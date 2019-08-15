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
    public partial class SearchProcessDlg : Form
    {
        public SearchProcessDlg()
        {
            InitializeComponent();
        }

        private void SearchProcessDlg_Load(object sender, EventArgs e)
        {
            HeaderSearch.StatusChanged += HeaderSearch_StatusChanged;
            HeaderSearch.SearchFileChanged += HeaderSearch_SearchFileChanged;
        }

        private void HeaderSearch_SearchFileChanged(string fileName, int count, int total)
        {
            tbCurrentFile.Invoke(new Action(() => tbCurrentFile.Text = $"{fileName} ({count}/{total})"));

            if (count == -1)
                progressBar1.Invoke(new Action(() => progressBar1.Style = ProgressBarStyle.Marquee));
            else
            {
                double c = count, t = total;
                double percentage = c / t * 100;

                progressBar1.Invoke(new Action(() =>
                {
                    if (progressBar1.Style == ProgressBarStyle.Marquee)
                        progressBar1.Style = ProgressBarStyle.Continuous;

                    progressBar1.Value = (int)percentage;
                }));
            }
        }

        private void HeaderSearch_StatusChanged(HeaderSearch.SearchStatus status, object StringOrExceptionOrNull)
        {

            if (status == HeaderSearch.SearchStatus.Error)
                this.Invoke(new Action(() => 
                    MessageBox.Show(StringOrExceptionOrNull.ToString())
                    ));

            if (status == HeaderSearch.SearchStatus.Finished)
                this.Invoke(new Action(() => this.Close()));
        }

        private void SearchProcessDlg_FormClosing(object sender, FormClosingEventArgs e)
        {
            HeaderSearch.StatusChanged -= HeaderSearch_StatusChanged;
            HeaderSearch.SearchFileChanged -= HeaderSearch_SearchFileChanged;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            HeaderSearch.Cancel = true;
            btnCancel.Enabled = false;
        }
    }
}
