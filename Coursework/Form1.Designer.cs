﻿namespace Coursework
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
            this.Type_of_planeTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.Number_of_passengersTextBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.Length_of_flightTextBox = new System.Windows.Forms.TextBox();
            this.Fuel_consumptionTextBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.Price_of_ticketTextBox = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Type_of_planeTextBox
            // 
            this.Type_of_planeTextBox.Location = new System.Drawing.Point(183, 52);
            this.Type_of_planeTextBox.Name = "Type_of_planeTextBox";
            this.Type_of_planeTextBox.Size = new System.Drawing.Size(100, 20);
            this.Type_of_planeTextBox.TabIndex = 0;
            this.Type_of_planeTextBox.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(117, 52);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Тип літака";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // Number_of_passengersTextBox
            // 
            this.Number_of_passengersTextBox.Location = new System.Drawing.Point(183, 89);
            this.Number_of_passengersTextBox.Name = "Number_of_passengersTextBox";
            this.Number_of_passengersTextBox.Size = new System.Drawing.Size(100, 20);
            this.Number_of_passengersTextBox.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(69, 92);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(108, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Кількість пасажирів";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(69, 119);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(114, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Дальність перельоту";
            // 
            // Length_of_flightTextBox
            // 
            this.Length_of_flightTextBox.Location = new System.Drawing.Point(183, 119);
            this.Length_of_flightTextBox.Name = "Length_of_flightTextBox";
            this.Length_of_flightTextBox.Size = new System.Drawing.Size(100, 20);
            this.Length_of_flightTextBox.TabIndex = 5;
            // 
            // Fuel_consumptionTextBox
            // 
            this.Fuel_consumptionTextBox.Location = new System.Drawing.Point(183, 151);
            this.Fuel_consumptionTextBox.Name = "Fuel_consumptionTextBox";
            this.Fuel_consumptionTextBox.Size = new System.Drawing.Size(100, 20);
            this.Fuel_consumptionTextBox.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(69, 151);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(98, 13);
            this.label4.TabIndex = 6;
            this.label4.Text = "Витрата пального";
            // 
            // Price_of_ticketTextBox
            // 
            this.Price_of_ticketTextBox.Location = new System.Drawing.Point(183, 189);
            this.Price_of_ticketTextBox.Name = "Price_of_ticketTextBox";
            this.Price_of_ticketTextBox.Size = new System.Drawing.Size(100, 20);
            this.Price_of_ticketTextBox.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(69, 189);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(88, 13);
            this.label5.TabIndex = 8;
            this.label5.Text = "Вартість квитка";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1520, 691);
            this.Controls.Add(this.Price_of_ticketTextBox);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.Fuel_consumptionTextBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.Length_of_flightTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Number_of_passengersTextBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Type_of_planeTextBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox Type_of_planeTextBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox Number_of_passengersTextBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox Length_of_flightTextBox;
        private System.Windows.Forms.TextBox Fuel_consumptionTextBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox Price_of_ticketTextBox;
        private System.Windows.Forms.Label label5;
    }
}
