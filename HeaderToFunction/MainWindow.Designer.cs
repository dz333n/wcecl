namespace HeaderToFunction
{
    partial class MainWindow
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainWindow));
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnClearSource = new System.Windows.Forms.Button();
            this.btnPasteSource = new System.Windows.Forms.Button();
            this.tbSource = new System.Windows.Forms.TextBox();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.cbNewLinesForArgs = new System.Windows.Forms.CheckBox();
            this.cbWrapFunction = new System.Windows.Forms.CheckBox();
            this.tbSuffix = new System.Windows.Forms.TextBox();
            this.cbAddSuffix = new System.Windows.Forms.CheckBox();
            this.tbResult = new System.Windows.Forms.TextBox();
            this.btnCopyResult = new System.Windows.Forms.Button();
            this.btnConvert = new System.Windows.Forms.Button();
            this.btnSearch = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.btnClearSource);
            this.groupBox1.Controls.Add(this.btnPasteSource);
            this.groupBox1.Controls.Add(this.tbSource);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(525, 337);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Header source";
            // 
            // btnClearSource
            // 
            this.btnClearSource.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnClearSource.Location = new System.Drawing.Point(87, 308);
            this.btnClearSource.Name = "btnClearSource";
            this.btnClearSource.Size = new System.Drawing.Size(75, 23);
            this.btnClearSource.TabIndex = 5;
            this.btnClearSource.Text = "Clear";
            this.btnClearSource.UseVisualStyleBackColor = true;
            this.btnClearSource.Click += new System.EventHandler(this.btnClearSource_Click);
            // 
            // btnPasteSource
            // 
            this.btnPasteSource.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnPasteSource.Location = new System.Drawing.Point(6, 308);
            this.btnPasteSource.Name = "btnPasteSource";
            this.btnPasteSource.Size = new System.Drawing.Size(75, 23);
            this.btnPasteSource.TabIndex = 4;
            this.btnPasteSource.Text = "Paste";
            this.btnPasteSource.UseVisualStyleBackColor = true;
            this.btnPasteSource.Click += new System.EventHandler(this.btnPasteSource_Click);
            // 
            // tbSource
            // 
            this.tbSource.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbSource.Font = new System.Drawing.Font("Courier New", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.tbSource.Location = new System.Drawing.Point(6, 19);
            this.tbSource.Multiline = true;
            this.tbSource.Name = "tbSource";
            this.tbSource.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.tbSource.Size = new System.Drawing.Size(513, 283);
            this.tbSource.TabIndex = 0;
            this.tbSource.Text = resources.GetString("tbSource.Text");
            this.tbSource.WordWrap = false;
            // 
            // splitContainer1
            // 
            this.splitContainer1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.splitContainer1.Location = new System.Drawing.Point(0, 41);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.groupBox1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.groupBox2);
            this.splitContainer1.Size = new System.Drawing.Size(1080, 361);
            this.splitContainer1.SplitterDistance = 540;
            this.splitContainer1.TabIndex = 1;
            // 
            // groupBox2
            // 
            this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox2.Controls.Add(this.cbNewLinesForArgs);
            this.groupBox2.Controls.Add(this.cbWrapFunction);
            this.groupBox2.Controls.Add(this.tbSuffix);
            this.groupBox2.Controls.Add(this.cbAddSuffix);
            this.groupBox2.Controls.Add(this.tbResult);
            this.groupBox2.Controls.Add(this.btnCopyResult);
            this.groupBox2.Controls.Add(this.btnConvert);
            this.groupBox2.Location = new System.Drawing.Point(3, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(521, 337);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Result";
            // 
            // cbNewLinesForArgs
            // 
            this.cbNewLinesForArgs.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.cbNewLinesForArgs.AutoSize = true;
            this.cbNewLinesForArgs.Checked = true;
            this.cbNewLinesForArgs.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbNewLinesForArgs.Location = new System.Drawing.Point(76, 311);
            this.cbNewLinesForArgs.Name = "cbNewLinesForArgs";
            this.cbNewLinesForArgs.Size = new System.Drawing.Size(110, 17);
            this.cbNewLinesForArgs.TabIndex = 6;
            this.cbNewLinesForArgs.Text = "New lines for args";
            this.cbNewLinesForArgs.UseVisualStyleBackColor = true;
            // 
            // cbWrapFunction
            // 
            this.cbWrapFunction.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.cbWrapFunction.AutoSize = true;
            this.cbWrapFunction.Checked = true;
            this.cbWrapFunction.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbWrapFunction.Location = new System.Drawing.Point(341, 311);
            this.cbWrapFunction.Name = "cbWrapFunction";
            this.cbWrapFunction.Size = new System.Drawing.Size(93, 17);
            this.cbWrapFunction.TabIndex = 5;
            this.cbWrapFunction.Text = "Wrap function";
            this.cbWrapFunction.UseVisualStyleBackColor = true;
            // 
            // tbSuffix
            // 
            this.tbSuffix.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.tbSuffix.Location = new System.Drawing.Point(273, 309);
            this.tbSuffix.Name = "tbSuffix";
            this.tbSuffix.Size = new System.Drawing.Size(62, 20);
            this.tbSuffix.TabIndex = 4;
            this.tbSuffix.Text = "_WCECL";
            // 
            // cbAddSuffix
            // 
            this.cbAddSuffix.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.cbAddSuffix.AutoSize = true;
            this.cbAddSuffix.Checked = true;
            this.cbAddSuffix.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbAddSuffix.Location = new System.Drawing.Point(192, 311);
            this.cbAddSuffix.Name = "cbAddSuffix";
            this.cbAddSuffix.Size = new System.Drawing.Size(75, 17);
            this.cbAddSuffix.TabIndex = 3;
            this.cbAddSuffix.Text = "Add suffix:";
            this.cbAddSuffix.UseVisualStyleBackColor = true;
            this.cbAddSuffix.CheckedChanged += new System.EventHandler(this.cbAddSuffix_CheckedChanged);
            // 
            // tbResult
            // 
            this.tbResult.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbResult.Font = new System.Drawing.Font("Courier New", 9.75F);
            this.tbResult.Location = new System.Drawing.Point(6, 19);
            this.tbResult.Multiline = true;
            this.tbResult.Name = "tbResult";
            this.tbResult.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.tbResult.Size = new System.Drawing.Size(509, 283);
            this.tbResult.TabIndex = 2;
            this.tbResult.WordWrap = false;
            // 
            // btnCopyResult
            // 
            this.btnCopyResult.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnCopyResult.Location = new System.Drawing.Point(6, 308);
            this.btnCopyResult.Name = "btnCopyResult";
            this.btnCopyResult.Size = new System.Drawing.Size(49, 23);
            this.btnCopyResult.TabIndex = 1;
            this.btnCopyResult.Text = "Copy";
            this.btnCopyResult.UseVisualStyleBackColor = true;
            this.btnCopyResult.Click += new System.EventHandler(this.btnCopyResult_Click);
            // 
            // btnConvert
            // 
            this.btnConvert.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnConvert.Location = new System.Drawing.Point(440, 308);
            this.btnConvert.Name = "btnConvert";
            this.btnConvert.Size = new System.Drawing.Size(75, 23);
            this.btnConvert.TabIndex = 0;
            this.btnConvert.Text = "Convert";
            this.btnConvert.UseVisualStyleBackColor = true;
            this.btnConvert.Click += new System.EventHandler(this.btnConvert_Click);
            // 
            // btnSearch
            // 
            this.btnSearch.Location = new System.Drawing.Point(12, 12);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(143, 23);
            this.btnSearch.TabIndex = 2;
            this.btnSearch.Text = "Search in headers";
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.btnSearch_Click);
            // 
            // MainWindow
            // 
            this.AcceptButton = this.btnConvert;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1080, 402);
            this.Controls.Add(this.btnSearch);
            this.Controls.Add(this.splitContainer1);
            this.Name = "MainWindow";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "WCECL Header To Function Converter";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnPasteSource;
        private System.Windows.Forms.TextBox tbSource;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.CheckBox cbWrapFunction;
        private System.Windows.Forms.TextBox tbSuffix;
        private System.Windows.Forms.CheckBox cbAddSuffix;
        private System.Windows.Forms.TextBox tbResult;
        private System.Windows.Forms.Button btnCopyResult;
        private System.Windows.Forms.Button btnConvert;
        private System.Windows.Forms.Button btnClearSource;
        private System.Windows.Forms.CheckBox cbNewLinesForArgs;
        private System.Windows.Forms.Button btnSearch;
    }
}

