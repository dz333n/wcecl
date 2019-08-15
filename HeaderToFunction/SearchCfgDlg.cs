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
    public partial class SearchCfgDlg : Form
    {
        public SearchCfgDlg()
        {
            InitializeComponent();
            cbUseCache.Checked = HeaderSearch.UseCache;
        }

        private void SearchCfgDlg_Load(object sender, EventArgs e)
        {
        }

        private void cbUseCache_CheckedChanged(object sender, EventArgs e)
        {
            HeaderSearch.UseCache = cbUseCache.Checked;
        }
    }
}
