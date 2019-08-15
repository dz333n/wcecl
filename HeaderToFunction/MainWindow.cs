using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace HeaderToFunction
{
    public partial class MainWindow : Form
    {
        const char Tab = '	';

        public MainWindow()
        {
            InitializeComponent();

            HeaderSearch.StatusChanged += HeaderSearch_StatusChanged;
        }

        private void HeaderSearch_StatusChanged(HeaderSearch.SearchStatus status, object StringOrExceptionOrNull)
        {
            if (status == HeaderSearch.SearchStatus.Started)
                this.BeginInvoke(new Action(() => new SearchProcessDlg().ShowDialog()));
            else if(status == HeaderSearch.SearchStatus.FoundSomething)
            {
                this.Invoke(new Action(() =>
                {
                    tbSource.AppendText("\r\n");
                    tbSource.AppendText((string)StringOrExceptionOrNull);
                    tbSource.AppendText("\r\n");
                }));
            }
        }

        private void btnPasteSource_Click(object sender, EventArgs e)
        {
            tbSource.SelectAll();
            tbSource.Clear();
            tbSource.Paste();

            btnConvert.Focus();
        }

        private void btnCopyResult_Click(object sender, EventArgs e)
        {
            tbResult.Focus();
            tbResult.SelectAll();
            tbResult.Copy();
        }

        private void cbAddSuffix_CheckedChanged(object sender, EventArgs e)
        {
            var state = cbAddSuffix.Checked;

            tbSuffix.Enabled = state;
            cbWrapFunction.Enabled = state;

            if (!state) cbWrapFunction.Checked = false;
        }

        private void btnClearSource_Click(object sender, EventArgs e)
        {
            tbSource.Focus();
            tbSource.SelectAll();
            tbSource.Clear();
        }

        private void btnConvert_Click(object sender, EventArgs e)
        {
            this.Cursor = Cursors.WaitCursor;
            StringBuilder result = new StringBuilder();

            try
            {
                string source = tbSource.Text;

                // Remove new lines
                source = source.Replace("\r\n", " ").Replace("\n", " ");

                // Split code
                string[] codeLines = source.Split(new char[] { ';' }, StringSplitOptions.RemoveEmptyEntries);

                if (codeLines.Length <= 0) throw new Exception("No code");

                foreach (var codeLine in codeLines)
                {
                    // Get the text until the first bracket and bracket positions
                    //    IN: HWND  WINAPI  VOID  CreateWindowEx ( BRUG arg1 , BRUH arg2 )
                    //   OUT: HWND  WINAPI  VOID  CreateWindowEx 
                    string TextBeforeBraces = "", FunctionName = "";
                    bool AddText = true;
                    int BracketPositionStart = 0, BracketPositionEnd = 0;
                    for (int i = 0; i < codeLine.Length; i++)
                    {
                        var c = codeLine[i];

                        if (c == '(')
                        {
                            BracketPositionStart = i;
                            AddText = false;
                        }

                        if (AddText) TextBeforeBraces += c;

                        if (c == ')')
                        {
                            BracketPositionEnd = i;
                            break;
                        }
                    }

                    // Format the text before bracket and add suffix if needed
                    //   IN: HWND  WINAPI  VOID  CreateWindowEx
                    //  OUT: HWND WINAPI VOID CreateWindowEx_WCECL
                    var splitBr = TextBeforeBraces
                        .Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                    TextBeforeBraces = string.Join(" ", splitBr);

                    FunctionName = splitBr[splitBr.Length - 1];
                    if (cbAddSuffix.Checked) TextBeforeBraces += tbSuffix.Text;

                    // Add function declaration to the result
                    result.Append(TextBeforeBraces);
                    result.Append('(');

                    // Get text from the brackets, format it and generate variable name if needed
                    //   IN: ( IN BRUG arg1 , OUT BRUH arg2 ) or ( BRUH,  BRUH ) 
                    //  OUT: BRUG arg1,
                    //       BRUH arg2
                    string ArgumentsTextRaw = codeLine.Substring(BracketPositionStart + 1, BracketPositionEnd - BracketPositionStart - 1);
                    string[] ArgumentsTextSp = ArgumentsTextRaw.Split(new char[] { ',' }, StringSplitOptions.RemoveEmptyEntries);
                    bool ArgumentsNewLine = cbNewLinesForArgs.Checked ? (ArgumentsTextSp.Length > 1) : false;

                    for (int i = 0; i < ArgumentsTextSp.Length; i++)
                    {
                        var spArg = ArgumentsTextSp[i].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        ArgumentsTextSp[i] = string.Join(" ", spArg);

                        if (spArg.Length <= 1 && !IsOptionsArray(ArgumentsTextSp[i]))
                            ArgumentsTextSp[i] += $" arg{i}";

                        // Add to the result
                        if (ArgumentsNewLine)
                        {
                            result.AppendLine();
                            result.Append(Tab);
                        }
                        result.Append(ArgumentsTextSp[i]);
                        if (i < ArgumentsTextSp.Length - 1) result.Append(',');
                    }

                    result.Append(')');
                    result.AppendLine();
                    result.Append('{');
                    result.AppendLine();

                    if(cbWrapFunction.Checked)
                    {
                        result.Append($"{Tab}auto result = {FunctionName}(");

                        for (int i = 0; i < ArgumentsTextSp.Length; i++)
                        {
                            if (ArgumentsNewLine)
                            {
                                result.AppendLine();
                                result.Append($"{Tab}{Tab}");
                            }

                            var spTest = ArgumentsTextSp[i].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                            result.Append(spTest[spTest.Length - 1]);
                            if (IsOptionsArray(ArgumentsTextSp[i])) result.Append(" /* FIX HERE */ ");
                            if (i < ArgumentsTextSp.Length - 1) result.Append(',');
                        }

                        result.Append(");");
                        result.AppendLine();
                        result.AppendLine($"{Tab}return result;");
                    }

                    result.Append("}");
                    result.AppendLine();
                    result.AppendLine();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(
                    ex.ToString(),
                    "Header Converter",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error);
            }

            tbResult.Text = result.ToString();
            tbResult.Focus();
            tbResult.Select(0, 0);
            btnCopyResult.Focus();

            this.Cursor = Cursors.Default;
        }

        private bool IsOptionsArray(string arg)
            => arg == "...";

        private void btnSearch_Click(object sender, EventArgs e)
            => new SearchDlg().ShowDialog();
    }
}
