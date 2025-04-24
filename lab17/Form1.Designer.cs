namespace lab17
{
    partial class Form1
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
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonDraw = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.buttonSaveBinary = new System.Windows.Forms.Button();
            this.buttonSaveXml = new System.Windows.Forms.Button();
            this.buttonLoadBinary = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.buttonLoadXml = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(174, 12);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(120, 20);
            this.numericUpDown1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(43, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(125, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Для введення радіуса r";
            // 
            // buttonDraw
            // 
            this.buttonDraw.Location = new System.Drawing.Point(174, 63);
            this.buttonDraw.Name = "buttonDraw";
            this.buttonDraw.Size = new System.Drawing.Size(208, 23);
            this.buttonDraw.TabIndex = 2;
            this.buttonDraw.Text = "Намалювати";
            this.buttonDraw.UseVisualStyleBackColor = true;
            this.buttonDraw.Click += new System.EventHandler(this.buttonDraw_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(43, 68);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(111, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Виклик методу Draw";
            // 
            // buttonSaveBinary
            // 
            this.buttonSaveBinary.Location = new System.Drawing.Point(174, 114);
            this.buttonSaveBinary.Name = "buttonSaveBinary";
            this.buttonSaveBinary.Size = new System.Drawing.Size(208, 23);
            this.buttonSaveBinary.TabIndex = 4;
            this.buttonSaveBinary.Text = "Зберегти Binary";
            this.buttonSaveBinary.UseVisualStyleBackColor = true;
            this.buttonSaveBinary.Click += new System.EventHandler(this.buttonSaveBinary_Click);
            // 
            // buttonSaveXml
            // 
            this.buttonSaveXml.Location = new System.Drawing.Point(174, 158);
            this.buttonSaveXml.Name = "buttonSaveXml";
            this.buttonSaveXml.Size = new System.Drawing.Size(208, 23);
            this.buttonSaveXml.TabIndex = 5;
            this.buttonSaveXml.Text = "Зберегти XML";
            this.buttonSaveXml.UseVisualStyleBackColor = true;
            this.buttonSaveXml.Click += new System.EventHandler(this.buttonSaveXml_Click);
            // 
            // buttonLoadBinary
            // 
            this.buttonLoadBinary.Location = new System.Drawing.Point(174, 203);
            this.buttonLoadBinary.Name = "buttonLoadBinary";
            this.buttonLoadBinary.Size = new System.Drawing.Size(208, 23);
            this.buttonLoadBinary.TabIndex = 6;
            this.buttonLoadBinary.Text = "Завантажити Binary";
            this.buttonLoadBinary.UseVisualStyleBackColor = true;
            this.buttonLoadBinary.Click += new System.EventHandler(this.buttonLoadBinary_Click);
            // 
            // panel1
            // 
            this.panel1.Location = new System.Drawing.Point(400, 14);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(545, 546);
            this.panel1.TabIndex = 7;
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // buttonLoadXml
            // 
            this.buttonLoadXml.Location = new System.Drawing.Point(174, 243);
            this.buttonLoadXml.Name = "buttonLoadXml";
            this.buttonLoadXml.Size = new System.Drawing.Size(208, 23);
            this.buttonLoadXml.TabIndex = 8;
            this.buttonLoadXml.Text = "Завантажити XML";
            this.buttonLoadXml.UseVisualStyleBackColor = true;
            this.buttonLoadXml.Click += new System.EventHandler(this.buttonLoadXml_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(957, 590);
            this.Controls.Add(this.buttonLoadXml);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.buttonLoadBinary);
            this.Controls.Add(this.buttonSaveXml);
            this.Controls.Add(this.buttonSaveBinary);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.buttonDraw);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.numericUpDown1);
            this.Name = "Form1";
            this.Text = "Lab 17 Illarionov";
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonDraw;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonSaveBinary;
        private System.Windows.Forms.Button buttonSaveXml;
        private System.Windows.Forms.Button buttonLoadBinary;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button buttonLoadXml;
    }
}

