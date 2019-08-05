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
        public MainWindow()
        {
            InitializeComponent();
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
                result.AppendLine("Not implemented");
                throw new NotImplementedException();
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
    }
}
