namespace lab15_NET
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
            this.textBoxH = new System.Windows.Forms.TextBox();
            this.textBoxL = new System.Windows.Forms.TextBox();
            this.textBoxR = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.labelResult = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.buttonClose_Click = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBoxH
            // 
            this.textBoxH.Location = new System.Drawing.Point(159, 16);
            this.textBoxH.Name = "textBoxH";
            this.textBoxH.Size = new System.Drawing.Size(217, 22);
            this.textBoxH.TabIndex = 0;
            // 
            // textBoxL
            // 
            this.textBoxL.Location = new System.Drawing.Point(159, 64);
            this.textBoxL.Name = "textBoxL";
            this.textBoxL.Size = new System.Drawing.Size(217, 22);
            this.textBoxL.TabIndex = 1;
            // 
            // textBoxR
            // 
            this.textBoxR.Location = new System.Drawing.Point(159, 107);
            this.textBoxR.Name = "textBoxR";
            this.textBoxR.Size = new System.Drawing.Size(217, 22);
            this.textBoxR.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(82, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(71, 16);
            this.label1.TabIndex = 3;
            this.label1.Text = "h (висота)";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(82, 67);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(63, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "l (твірна)";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(39, 110);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(114, 16);
            this.label3.TabIndex = 5;
            this.label3.Text = "r (радіус основи)";
            // 
            // labelResult
            // 
            this.labelResult.AutoSize = true;
            this.labelResult.Location = new System.Drawing.Point(172, 159);
            this.labelResult.Name = "labelResult";
            this.labelResult.Size = new System.Drawing.Size(188, 16);
            this.labelResult.TabIndex = 6;
            this.labelResult.Text = "Відображення результатів: ";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(187, 199);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(141, 32);
            this.button1.TabIndex = 8;
            this.button1.Text = "Обчислити";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // buttonClose_Click
            // 
            this.buttonClose_Click.BackColor = System.Drawing.Color.LightCoral;
            this.buttonClose_Click.Location = new System.Drawing.Point(397, 3);
            this.buttonClose_Click.Name = "buttonClose_Click";
            this.buttonClose_Click.Size = new System.Drawing.Size(85, 32);
            this.buttonClose_Click.TabIndex = 9;
            this.buttonClose_Click.Text = "Закрити";
            this.buttonClose_Click.UseVisualStyleBackColor = false;
            this.buttonClose_Click.Click += new System.EventHandler(this.button2_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(169, 247);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(175, 32);
            this.label4.TabIndex = 10;
            this.label4.Text = "Завдання 1";
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.SpringGreen;
            this.button2.Location = new System.Drawing.Point(397, 41);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(127, 28);
            this.button2.TabIndex = 11;
            this.button2.Text = "До завдання 2";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click_1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(551, 535);
            this.ControlBox = false;
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.buttonClose_Click);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.labelResult);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxR);
            this.Controls.Add(this.textBoxL);
            this.Controls.Add(this.textBoxH);
            this.Name = "Form1";
            this.Text = " Завдання 1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxH;
        private System.Windows.Forms.TextBox textBoxL;
        private System.Windows.Forms.TextBox textBoxR;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label labelResult;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button buttonClose_Click;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button button2;
    }
}

