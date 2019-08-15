namespace HeaderToFunction
{
    partial class SearchDlg
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnChooseFolder = new System.Windows.Forms.Button();
            this.btnSelectFiles = new System.Windows.Forms.Button();
            this.btnCacheSearch = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnClearCache = new System.Windows.Forms.Button();
            this.tbSearchWhat = new System.Windows.Forms.TextBox();
            this.btnPaste = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnChooseFolder
            // 
            this.btnChooseFolder.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnChooseFolder.Location = new System.Drawing.Point(55, 22);
            this.btnChooseFolder.Name = "btnChooseFolder";
            this.btnChooseFolder.Size = new System.Drawing.Size(220, 59);
            this.btnChooseFolder.TabIndex = 0;
            this.btnChooseFolder.Text = "...folder\r\n(through all *.h files)";
            this.btnChooseFolder.UseVisualStyleBackColor = true;
            this.btnChooseFolder.Click += new System.EventHandler(this.btnChooseFolder_Click);
            // 
            // btnSelectFiles
            // 
            this.btnSelectFiles.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnSelectFiles.Location = new System.Drawing.Point(55, 101);
            this.btnSelectFiles.Name = "btnSelectFiles";
            this.btnSelectFiles.Size = new System.Drawing.Size(220, 59);
            this.btnSelectFiles.TabIndex = 1;
            this.btnSelectFiles.Text = "...files\r\n(through selected files)";
            this.btnSelectFiles.UseVisualStyleBackColor = true;
            this.btnSelectFiles.Click += new System.EventHandler(this.btnSelectFiles_Click);
            // 
            // btnCacheSearch
            // 
            this.btnCacheSearch.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnCacheSearch.Location = new System.Drawing.Point(55, 185);
            this.btnCacheSearch.Name = "btnCacheSearch";
            this.btnCacheSearch.Size = new System.Drawing.Size(220, 59);
            this.btnCacheSearch.TabIndex = 2;
            this.btnCacheSearch.Text = "...cache";
            this.btnCacheSearch.UseVisualStyleBackColor = true;
            this.btnCacheSearch.Click += new System.EventHandler(this.btnCacheSearch_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.groupBox1.Controls.Add(this.btnClearCache);
            this.groupBox1.Controls.Add(this.btnChooseFolder);
            this.groupBox1.Controls.Add(this.btnCacheSearch);
            this.groupBox1.Controls.Add(this.btnSelectFiles);
            this.groupBox1.Location = new System.Drawing.Point(79, 83);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(324, 281);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Search in...";
            // 
            // btnClearCache
            // 
            this.btnClearCache.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnClearCache.Location = new System.Drawing.Point(55, 250);
            this.btnClearCache.Name = "btnClearCache";
            this.btnClearCache.Size = new System.Drawing.Size(220, 23);
            this.btnClearCache.TabIndex = 3;
            this.btnClearCache.Text = "Clear cache";
            this.btnClearCache.UseVisualStyleBackColor = true;
            this.btnClearCache.Click += new System.EventHandler(this.btnClearCache_Click);
            // 
            // tbSearchWhat
            // 
            this.tbSearchWhat.Location = new System.Drawing.Point(6, 22);
            this.tbSearchWhat.Name = "tbSearchWhat";
            this.tbSearchWhat.Size = new System.Drawing.Size(256, 20);
            this.tbSearchWhat.TabIndex = 4;
            this.tbSearchWhat.Text = "CreateWindowExW;InvalidateRect";
            // 
            // btnPaste
            // 
            this.btnPaste.Location = new System.Drawing.Point(263, 21);
            this.btnPaste.Name = "btnPaste";
            this.btnPaste.Size = new System.Drawing.Size(56, 22);
            this.btnPaste.TabIndex = 5;
            this.btnPaste.Text = "Paste";
            this.btnPaste.UseVisualStyleBackColor = true;
            this.btnPaste.Click += new System.EventHandler(this.btnPaste_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.groupBox2.Controls.Add(this.btnPaste);
            this.groupBox2.Controls.Add(this.tbSearchWhat);
            this.groupBox2.Location = new System.Drawing.Point(79, 23);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(324, 51);
            this.groupBox2.TabIndex = 6;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Search what";
            // 
            // SearchDlg
            // 
            this.AcceptButton = this.btnChooseFolder;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(456, 398);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SearchDlg";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Search";
            this.Load += new System.EventHandler(this.SearchDlg_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnChooseFolder;
        private System.Windows.Forms.Button btnSelectFiles;
        private System.Windows.Forms.Button btnCacheSearch;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnClearCache;
        private System.Windows.Forms.TextBox tbSearchWhat;
        private System.Windows.Forms.Button btnPaste;
        private System.Windows.Forms.GroupBox groupBox2;
    }
}