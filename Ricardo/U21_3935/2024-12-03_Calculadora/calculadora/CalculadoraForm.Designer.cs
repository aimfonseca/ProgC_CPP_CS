namespace calculadora
{
    partial class CalculadoraForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CalculadoraForm));
            textBox_Result = new TextBox();
            tableLayoutPanel1 = new TableLayoutPanel();
            button7 = new Button();
            button5 = new Button();
            button6 = new Button();
            button3 = new Button();
            button0 = new Button();
            button2 = new Button();
            buttonEqual = new Button();
            button1 = new Button();
            button00 = new Button();
            button4 = new Button();
            buttonDecimal = new Button();
            buttonClear = new Button();
            buttonMultiply = new Button();
            button8 = new Button();
            buttonSubtract = new Button();
            button9 = new Button();
            buttonAdd = new Button();
            buttonDivide = new Button();
            tableLayoutPanel1.SuspendLayout();
            SuspendLayout();
            // 
            // textBox_Result
            // 
            textBox_Result.Dock = DockStyle.Top;
            textBox_Result.Font = new Font("Segoe UI", 16F);
            textBox_Result.Location = new Point(0, 0);
            textBox_Result.Name = "textBox_Result";
            textBox_Result.ReadOnly = true;
            textBox_Result.Size = new Size(284, 36);
            textBox_Result.TabIndex = 0;
            textBox_Result.TextAlign = HorizontalAlignment.Right;
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.BackColor = Color.Transparent;
            tableLayoutPanel1.ColumnCount = 5;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 20F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 20F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 20F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 20F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 20F));
            tableLayoutPanel1.Controls.Add(button7, 0, 0);
            tableLayoutPanel1.Controls.Add(button5, 1, 1);
            tableLayoutPanel1.Controls.Add(button6, 2, 1);
            tableLayoutPanel1.Controls.Add(button3, 2, 2);
            tableLayoutPanel1.Controls.Add(button0, 0, 3);
            tableLayoutPanel1.Controls.Add(button2, 1, 2);
            tableLayoutPanel1.Controls.Add(buttonEqual, 4, 3);
            tableLayoutPanel1.Controls.Add(button1, 0, 2);
            tableLayoutPanel1.Controls.Add(button00, 1, 3);
            tableLayoutPanel1.Controls.Add(button4, 0, 1);
            tableLayoutPanel1.Controls.Add(buttonDecimal, 2, 3);
            tableLayoutPanel1.Controls.Add(buttonClear, 4, 0);
            tableLayoutPanel1.Controls.Add(buttonMultiply, 3, 1);
            tableLayoutPanel1.Controls.Add(button8, 1, 0);
            tableLayoutPanel1.Controls.Add(buttonSubtract, 3, 2);
            tableLayoutPanel1.Controls.Add(button9, 2, 0);
            tableLayoutPanel1.Controls.Add(buttonAdd, 3, 3);
            tableLayoutPanel1.Controls.Add(buttonDivide, 3, 0);
            tableLayoutPanel1.Location = new Point(0, 42);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 4;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.Size = new Size(284, 277);
            tableLayoutPanel1.TabIndex = 20;
            // 
            // button7
            // 
            button7.Dock = DockStyle.Fill;
            button7.Location = new Point(3, 3);
            button7.Name = "button7";
            button7.Size = new Size(50, 63);
            button7.TabIndex = 1;
            button7.Text = "7";
            button7.UseVisualStyleBackColor = true;
            button7.Click += button_Click;
            // 
            // button5
            // 
            button5.Dock = DockStyle.Fill;
            button5.Location = new Point(59, 72);
            button5.Name = "button5";
            button5.Size = new Size(50, 63);
            button5.TabIndex = 5;
            button5.Text = "5";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button_Click;
            // 
            // button6
            // 
            button6.Dock = DockStyle.Fill;
            button6.Location = new Point(115, 72);
            button6.Name = "button6";
            button6.Size = new Size(50, 63);
            button6.TabIndex = 6;
            button6.Text = "6";
            button6.UseVisualStyleBackColor = true;
            button6.Click += button_Click;
            // 
            // button3
            // 
            button3.Dock = DockStyle.Fill;
            button3.Location = new Point(115, 141);
            button3.Name = "button3";
            button3.Size = new Size(50, 63);
            button3.TabIndex = 9;
            button3.Text = "3";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button_Click;
            // 
            // button0
            // 
            button0.Dock = DockStyle.Fill;
            button0.Location = new Point(3, 210);
            button0.Name = "button0";
            button0.Size = new Size(50, 64);
            button0.TabIndex = 17;
            button0.Text = "0";
            button0.UseVisualStyleBackColor = true;
            button0.Click += button_Click;
            // 
            // button2
            // 
            button2.Dock = DockStyle.Fill;
            button2.Location = new Point(59, 141);
            button2.Name = "button2";
            button2.Size = new Size(50, 63);
            button2.TabIndex = 8;
            button2.Text = "2";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button_Click;
            // 
            // buttonEqual
            // 
            buttonEqual.Dock = DockStyle.Fill;
            buttonEqual.Location = new Point(227, 210);
            buttonEqual.Name = "buttonEqual";
            buttonEqual.Size = new Size(54, 64);
            buttonEqual.TabIndex = 18;
            buttonEqual.Text = "=";
            buttonEqual.UseVisualStyleBackColor = true;
            buttonEqual.Click += buttonEqual_Click;
            // 
            // button1
            // 
            button1.Dock = DockStyle.Fill;
            button1.Location = new Point(3, 141);
            button1.Name = "button1";
            button1.Size = new Size(50, 63);
            button1.TabIndex = 7;
            button1.Text = "1";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button_Click;
            // 
            // button00
            // 
            button00.Dock = DockStyle.Fill;
            button00.Location = new Point(59, 210);
            button00.Name = "button00";
            button00.Size = new Size(50, 64);
            button00.TabIndex = 11;
            button00.Text = "00";
            button00.UseVisualStyleBackColor = true;
            button00.Click += button_Click;
            // 
            // button4
            // 
            button4.Dock = DockStyle.Fill;
            button4.Location = new Point(3, 72);
            button4.Name = "button4";
            button4.Size = new Size(50, 63);
            button4.TabIndex = 4;
            button4.Text = "4";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button_Click;
            // 
            // buttonDecimal
            // 
            buttonDecimal.Dock = DockStyle.Fill;
            buttonDecimal.Location = new Point(115, 210);
            buttonDecimal.Name = "buttonDecimal";
            buttonDecimal.Size = new Size(50, 64);
            buttonDecimal.TabIndex = 16;
            buttonDecimal.Text = ".";
            buttonDecimal.UseVisualStyleBackColor = true;
            buttonDecimal.Click += buttonDecimal_Click;
            // 
            // buttonClear
            // 
            buttonClear.Dock = DockStyle.Fill;
            buttonClear.Location = new Point(227, 3);
            buttonClear.Name = "buttonClear";
            buttonClear.Size = new Size(54, 63);
            buttonClear.TabIndex = 19;
            buttonClear.Text = "C";
            buttonClear.UseVisualStyleBackColor = true;
            buttonClear.Click += buttonClear_Click;
            // 
            // buttonMultiply
            // 
            buttonMultiply.Dock = DockStyle.Fill;
            buttonMultiply.Location = new Point(171, 72);
            buttonMultiply.Name = "buttonMultiply";
            buttonMultiply.Size = new Size(50, 63);
            buttonMultiply.TabIndex = 14;
            buttonMultiply.Text = "×";
            buttonMultiply.UseVisualStyleBackColor = true;
            buttonMultiply.Click += operator_Click;
            // 
            // button8
            // 
            button8.Dock = DockStyle.Fill;
            button8.Location = new Point(59, 3);
            button8.Name = "button8";
            button8.Size = new Size(50, 63);
            button8.TabIndex = 2;
            button8.Text = "8";
            button8.UseVisualStyleBackColor = true;
            button8.Click += button_Click;
            // 
            // buttonSubtract
            // 
            buttonSubtract.Dock = DockStyle.Fill;
            buttonSubtract.Location = new Point(171, 141);
            buttonSubtract.Name = "buttonSubtract";
            buttonSubtract.Size = new Size(50, 63);
            buttonSubtract.TabIndex = 13;
            buttonSubtract.Text = "-";
            buttonSubtract.UseVisualStyleBackColor = true;
            buttonSubtract.Click += operator_Click;
            // 
            // button9
            // 
            button9.Dock = DockStyle.Fill;
            button9.Location = new Point(115, 3);
            button9.Name = "button9";
            button9.Size = new Size(50, 63);
            button9.TabIndex = 3;
            button9.Text = "9";
            button9.UseVisualStyleBackColor = true;
            button9.Click += button_Click;
            // 
            // buttonAdd
            // 
            buttonAdd.Dock = DockStyle.Fill;
            buttonAdd.Location = new Point(171, 210);
            buttonAdd.Name = "buttonAdd";
            buttonAdd.Size = new Size(50, 64);
            buttonAdd.TabIndex = 12;
            buttonAdd.Text = "+";
            buttonAdd.UseVisualStyleBackColor = true;
            buttonAdd.Click += operator_Click;
            // 
            // buttonDivide
            // 
            buttonDivide.Dock = DockStyle.Fill;
            buttonDivide.Location = new Point(171, 3);
            buttonDivide.Name = "buttonDivide";
            buttonDivide.Size = new Size(50, 63);
            buttonDivide.TabIndex = 15;
            buttonDivide.Text = "÷";
            buttonDivide.UseVisualStyleBackColor = true;
            buttonDivide.Click += operator_Click;
            // 
            // CalculadoraForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            ClientSize = new Size(284, 361);
            Controls.Add(tableLayoutPanel1);
            Controls.Add(textBox_Result);
            Name = "CalculadoraForm";
            Text = "A Minha 1ª Calculadora";
            tableLayoutPanel1.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox textBox_Result;
        private TableLayoutPanel tableLayoutPanel1;
        private Button button7;
        private Button button5;
        private Button button6;
        private Button button3;
        private Button button0;
        private Button button2;
        private Button buttonEqual;
        private Button button1;
        private Button button00;
        private Button button4;
        private Button buttonDecimal;
        private Button buttonClear;
        private Button buttonMultiply;
        private Button button8;
        private Button buttonSubtract;
        private Button button9;
        private Button buttonAdd;
        private Button buttonDivide;
    }
}
