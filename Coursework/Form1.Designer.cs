namespace Coursework
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.Length_of_flightTextBox = new System.Windows.Forms.TextBox();
            this.Fuel_consumptionTextBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.Price_of_ticketTextBox = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.Fuel_costTextBox = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.Add_planeButton = new System.Windows.Forms.Button();
            this.Display_airplanesButton = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.Passengers_numericUpDown = new System.Windows.Forms.NumericUpDown();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.function_Button = new System.Windows.Forms.Button();
            this.listView1 = new System.Windows.Forms.ListView();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.textBox1 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.Passengers_numericUpDown)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(156, 64);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(76, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Тип літака";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(92, 113);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(134, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "Кількість пасажирів";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(56, 150);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(171, 16);
            this.label3.TabIndex = 4;
            this.label3.Text = "Дальність перельоту(км.)";
            // 
            // Length_of_flightTextBox
            // 
            this.Length_of_flightTextBox.Location = new System.Drawing.Point(244, 146);
            this.Length_of_flightTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.Length_of_flightTextBox.Name = "Length_of_flightTextBox";
            this.Length_of_flightTextBox.ReadOnly = true;
            this.Length_of_flightTextBox.Size = new System.Drawing.Size(132, 22);
            this.Length_of_flightTextBox.TabIndex = 5;
            // 
            // Fuel_consumptionTextBox
            // 
            this.Fuel_consumptionTextBox.Location = new System.Drawing.Point(244, 186);
            this.Fuel_consumptionTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.Fuel_consumptionTextBox.Name = "Fuel_consumptionTextBox";
            this.Fuel_consumptionTextBox.ReadOnly = true;
            this.Fuel_consumptionTextBox.Size = new System.Drawing.Size(132, 22);
            this.Fuel_consumptionTextBox.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(92, 186);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(145, 16);
            this.label4.TabIndex = 6;
            this.label4.Text = "Витрата пального(л.)";
            // 
            // Price_of_ticketTextBox
            // 
            this.Price_of_ticketTextBox.Location = new System.Drawing.Point(244, 233);
            this.Price_of_ticketTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.Price_of_ticketTextBox.Name = "Price_of_ticketTextBox";
            this.Price_of_ticketTextBox.ReadOnly = true;
            this.Price_of_ticketTextBox.Size = new System.Drawing.Size(132, 22);
            this.Price_of_ticketTextBox.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(92, 233);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(144, 16);
            this.label5.TabIndex = 8;
            this.label5.Text = "Вартість квитка(грн.)";
            // 
            // Fuel_costTextBox
            // 
            this.Fuel_costTextBox.Location = new System.Drawing.Point(564, 191);
            this.Fuel_costTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.Fuel_costTextBox.Name = "Fuel_costTextBox";
            this.Fuel_costTextBox.Size = new System.Drawing.Size(132, 22);
            this.Fuel_costTextBox.TabIndex = 11;
            this.Fuel_costTextBox.TextChanged += new System.EventHandler(this.textBox1_TextChanged_1);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(409, 194);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(154, 16);
            this.label6.TabIndex = 10;
            this.label6.Text = "Ціна пального(грн./1л.)";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // Add_planeButton
            // 
            this.Add_planeButton.Location = new System.Drawing.Point(189, 289);
            this.Add_planeButton.Margin = new System.Windows.Forms.Padding(4);
            this.Add_planeButton.Name = "Add_planeButton";
            this.Add_planeButton.Size = new System.Drawing.Size(188, 55);
            this.Add_planeButton.TabIndex = 12;
            this.Add_planeButton.Text = "Додати літак";
            this.Add_planeButton.UseVisualStyleBackColor = true;
            this.Add_planeButton.Click += new System.EventHandler(this.Add_planeButton_Click);
            // 
            // Display_airplanesButton
            // 
            this.Display_airplanesButton.Location = new System.Drawing.Point(453, 289);
            this.Display_airplanesButton.Margin = new System.Windows.Forms.Padding(4);
            this.Display_airplanesButton.Name = "Display_airplanesButton";
            this.Display_airplanesButton.Size = new System.Drawing.Size(188, 55);
            this.Display_airplanesButton.TabIndex = 13;
            this.Display_airplanesButton.Text = "Показати літаки";
            this.Display_airplanesButton.UseVisualStyleBackColor = true;
            this.Display_airplanesButton.Click += new System.EventHandler(this.Display_airplanesButton_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 26.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label7.Location = new System.Drawing.Point(403, 11);
            this.label7.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(1045, 52);
            this.label7.TabIndex = 14;
            this.label7.Text = "Програма розрахунку собівартості квитка на літак";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // Passengers_numericUpDown
            // 
            this.Passengers_numericUpDown.Location = new System.Drawing.Point(244, 111);
            this.Passengers_numericUpDown.Margin = new System.Windows.Forms.Padding(4);
            this.Passengers_numericUpDown.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.Passengers_numericUpDown.Name = "Passengers_numericUpDown";
            this.Passengers_numericUpDown.Size = new System.Drawing.Size(160, 22);
            this.Passengers_numericUpDown.TabIndex = 15;
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "Boeing 747",
            "Airbus A380",
            "Boeing 737",
            "Airbus A320",
            "Embraer E190",
            "Bombardier CRJ200",
            "ATR 42"});
            this.comboBox1.Location = new System.Drawing.Point(244, 61);
            this.comboBox1.Margin = new System.Windows.Forms.Padding(4);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(160, 24);
            this.comboBox1.TabIndex = 16;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // function_Button
            // 
            this.function_Button.Location = new System.Drawing.Point(244, 351);
            this.function_Button.Name = "function_Button";
            this.function_Button.Size = new System.Drawing.Size(270, 94);
            this.function_Button.TabIndex = 17;
            this.function_Button.Text = "Кількість пального, що необхідно витратити при перевезенні одного пасажира на оди" +
    "ницю дальності";
            this.function_Button.UseVisualStyleBackColor = true;
            this.function_Button.Click += new System.EventHandler(this.button1_Click);
            // 
            // listView1
            // 
            this.listView1.HideSelection = false;
            this.listView1.Location = new System.Drawing.Point(58, 451);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(638, 114);
            this.listView1.Sorting = System.Windows.Forms.SortOrder.Descending;
            this.listView1.TabIndex = 18;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.Visible = false;
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(261, 571);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(243, 23);
            this.progressBar1.TabIndex = 19;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(734, 572);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(273, 22);
            this.textBox1.TabIndex = 20;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged_2);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1924, 850);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.function_Button);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.Passengers_numericUpDown);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.Display_airplanesButton);
            this.Controls.Add(this.Add_planeButton);
            this.Controls.Add(this.Fuel_costTextBox);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.Price_of_ticketTextBox);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.Fuel_consumptionTextBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.Length_of_flightTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "SkylaraCalculator";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.Passengers_numericUpDown)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox Length_of_flightTextBox;
        private System.Windows.Forms.TextBox Fuel_consumptionTextBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox Price_of_ticketTextBox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox Fuel_costTextBox;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button Add_planeButton;
        private System.Windows.Forms.Button Display_airplanesButton;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.NumericUpDown Passengers_numericUpDown;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button function_Button;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.TextBox textBox1;
    }
}

