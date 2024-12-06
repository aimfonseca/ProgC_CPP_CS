namespace Calculadora
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            PainelSuperior = new Panel();
            icon = new Button();
            label1 = new Label();
            button2 = new Button();
            button1 = new Button();
            CloseBtn = new Button();
            PainelInferior = new Panel();
            richTextBox1 = new RichTextBox();
            BtnLimparHistorico = new Button();
            PainelHistorico = new Panel();
            historico = new Button();
            menu = new Button();
            Display2 = new TextBox();
            Display1 = new TextBox();
            PainelSuperior.SuspendLayout();
            PainelInferior.SuspendLayout();
            PainelHistorico.SuspendLayout();
            SuspendLayout();
            // 
            // PainelSuperior
            // 
            PainelSuperior.Controls.Add(icon);
            PainelSuperior.Controls.Add(label1);
            PainelSuperior.Controls.Add(button2);
            PainelSuperior.Controls.Add(button1);
            PainelSuperior.Controls.Add(CloseBtn);
            PainelSuperior.Dock = DockStyle.Top;
            PainelSuperior.Location = new Point(0, 0);
            PainelSuperior.Margin = new Padding(0);
            PainelSuperior.Name = "PainelSuperior";
            PainelSuperior.Size = new Size(370, 40);
            PainelSuperior.TabIndex = 0;
            // 
            // icon
            // 
            icon.BackColor = Color.Transparent;
            icon.Dock = DockStyle.Left;
            icon.FlatAppearance.BorderSize = 0;
            icon.FlatAppearance.MouseOverBackColor = Color.FromArgb(32, 32, 32);
            icon.FlatStyle = FlatStyle.Flat;
            icon.ForeColor = Color.FromArgb(32, 32, 32);
            icon.Image = (Image)resources.GetObject("icon.Image");
            icon.Location = new Point(0, 0);
            icon.Margin = new Padding(0);
            icon.Name = "icon";
            icon.Size = new Size(25, 40);
            icon.TabIndex = 4;
            icon.UseVisualStyleBackColor = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Gadugi", 9F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(28, 12);
            label1.Name = "label1";
            label1.Size = new Size(140, 16);
            label1.TabIndex = 3;
            label1.Text = "Calculadora Cordyceps®";
            // 
            // button2
            // 
            button2.Dock = DockStyle.Right;
            button2.FlatAppearance.BorderSize = 0;
            button2.FlatAppearance.MouseOverBackColor = Color.FromArgb(62, 62, 62);
            button2.FlatStyle = FlatStyle.Flat;
            button2.Image = (Image)resources.GetObject("button2.Image");
            button2.Location = new Point(220, 0);
            button2.Margin = new Padding(0);
            button2.Name = "button2";
            button2.Size = new Size(50, 40);
            button2.TabIndex = 2;
            button2.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            button1.Dock = DockStyle.Right;
            button1.FlatAppearance.BorderSize = 0;
            button1.FlatAppearance.MouseOverBackColor = Color.FromArgb(62, 62, 62);
            button1.FlatStyle = FlatStyle.Flat;
            button1.Image = (Image)resources.GetObject("button1.Image");
            button1.Location = new Point(270, 0);
            button1.Margin = new Padding(0);
            button1.Name = "button1";
            button1.Size = new Size(50, 40);
            button1.TabIndex = 1;
            button1.UseVisualStyleBackColor = true;
            // 
            // CloseBtn
            // 
            CloseBtn.Dock = DockStyle.Right;
            CloseBtn.FlatAppearance.BorderSize = 0;
            CloseBtn.FlatAppearance.MouseOverBackColor = Color.FromArgb(190, 9, 9);
            CloseBtn.FlatStyle = FlatStyle.Flat;
            CloseBtn.Image = (Image)resources.GetObject("CloseBtn.Image");
            CloseBtn.Location = new Point(320, 0);
            CloseBtn.Margin = new Padding(0);
            CloseBtn.Name = "CloseBtn";
            CloseBtn.Size = new Size(50, 40);
            CloseBtn.TabIndex = 0;
            CloseBtn.UseVisualStyleBackColor = true;
            // 
            // PainelInferior
            // 
            PainelInferior.Controls.Add(richTextBox1);
            PainelInferior.Controls.Add(BtnLimparHistorico);
            PainelInferior.Dock = DockStyle.Bottom;
            PainelInferior.Location = new Point(0, 549);
            PainelInferior.Margin = new Padding(0);
            PainelInferior.Name = "PainelInferior";
            PainelInferior.Size = new Size(370, 1);
            PainelInferior.TabIndex = 1;
            // 
            // richTextBox1
            // 
            richTextBox1.BackColor = Color.FromArgb(32, 32, 32);
            richTextBox1.BorderStyle = BorderStyle.None;
            richTextBox1.Dock = DockStyle.Fill;
            richTextBox1.ForeColor = Color.Silver;
            richTextBox1.Location = new Point(0, 0);
            richTextBox1.Margin = new Padding(0);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.ScrollBars = RichTextBoxScrollBars.Horizontal;
            richTextBox1.Size = new Size(370, 0);
            richTextBox1.TabIndex = 4;
            richTextBox1.Text = "";
            // 
            // BtnLimparHistorico
            // 
            BtnLimparHistorico.Dock = DockStyle.Bottom;
            BtnLimparHistorico.FlatAppearance.BorderSize = 0;
            BtnLimparHistorico.FlatAppearance.MouseOverBackColor = Color.FromArgb(62, 62, 62);
            BtnLimparHistorico.FlatStyle = FlatStyle.Flat;
            BtnLimparHistorico.Image = (Image)resources.GetObject("BtnLimparHistorico.Image");
            BtnLimparHistorico.Location = new Point(0, -39);
            BtnLimparHistorico.Margin = new Padding(0);
            BtnLimparHistorico.Name = "BtnLimparHistorico";
            BtnLimparHistorico.Size = new Size(370, 40);
            BtnLimparHistorico.TabIndex = 3;
            BtnLimparHistorico.UseVisualStyleBackColor = true;
            // 
            // PainelHistorico
            // 
            PainelHistorico.Controls.Add(historico);
            PainelHistorico.Controls.Add(menu);
            PainelHistorico.Dock = DockStyle.Top;
            PainelHistorico.Location = new Point(0, 40);
            PainelHistorico.Margin = new Padding(0);
            PainelHistorico.Name = "PainelHistorico";
            PainelHistorico.Size = new Size(370, 40);
            PainelHistorico.TabIndex = 2;
            // 
            // historico
            // 
            historico.Dock = DockStyle.Right;
            historico.FlatAppearance.BorderSize = 0;
            historico.FlatAppearance.MouseOverBackColor = Color.FromArgb(62, 62, 62);
            historico.FlatStyle = FlatStyle.Flat;
            historico.Image = (Image)resources.GetObject("historico.Image");
            historico.Location = new Point(320, 0);
            historico.Margin = new Padding(0);
            historico.Name = "historico";
            historico.Size = new Size(50, 40);
            historico.TabIndex = 2;
            historico.UseVisualStyleBackColor = true;
            // 
            // menu
            // 
            menu.Dock = DockStyle.Left;
            menu.FlatAppearance.BorderSize = 0;
            menu.FlatAppearance.MouseOverBackColor = Color.FromArgb(62, 62, 62);
            menu.FlatStyle = FlatStyle.Flat;
            menu.Image = (Image)resources.GetObject("menu.Image");
            menu.Location = new Point(0, 0);
            menu.Margin = new Padding(0);
            menu.Name = "menu";
            menu.Size = new Size(50, 40);
            menu.TabIndex = 1;
            menu.UseVisualStyleBackColor = true;
            // 
            // Display2
            // 
            Display2.BackColor = Color.FromArgb(32, 32, 32);
            Display2.BorderStyle = BorderStyle.None;
            Display2.ForeColor = Color.Silver;
            Display2.Location = new Point(0, 89);
            Display2.Margin = new Padding(0);
            Display2.Multiline = true;
            Display2.Name = "Display2";
            Display2.Size = new Size(370, 23);
            Display2.TabIndex = 3;
            Display2.Text = "666";
            Display2.TextAlign = HorizontalAlignment.Right;
            // 
            // Display1
            // 
            Display1.BackColor = Color.FromArgb(32, 32, 32);
            Display1.BorderStyle = BorderStyle.None;
            Display1.Font = new Font("Gadugi", 24F, FontStyle.Bold, GraphicsUnit.Point);
            Display1.ForeColor = Color.Silver;
            Display1.Location = new Point(0, 121);
            Display1.Margin = new Padding(0);
            Display1.Multiline = true;
            Display1.Name = "Display1";
            Display1.Size = new Size(370, 40);
            Display1.TabIndex = 4;
            Display1.Text = "666";
            Display1.TextAlign = HorizontalAlignment.Right;
            // 
            // Form1
            // 
            AutoScaleMode = AutoScaleMode.None;
            BackColor = Color.FromArgb(32, 32, 32);
            ClientSize = new Size(370, 550);
            Controls.Add(Display1);
            Controls.Add(Display2);
            Controls.Add(PainelHistorico);
            Controls.Add(PainelInferior);
            Controls.Add(PainelSuperior);
            Font = new Font("Gadugi", 12F, FontStyle.Regular, GraphicsUnit.Point);
            ForeColor = Color.White;
            FormBorderStyle = FormBorderStyle.None;
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            PainelSuperior.ResumeLayout(false);
            PainelSuperior.PerformLayout();
            PainelInferior.ResumeLayout(false);
            PainelHistorico.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Panel PainelSuperior;
        private Panel PainelInferior;
        private Button CloseBtn;
        private Button button2;
        private Button button1;
        private Button icon;
        private Label label1;
        private Panel PainelHistorico;
        private Button menu;
        private TextBox Display2;
        private TextBox Display1;
        private Button historico;
        private Button BtnLimparHistorico;
        private RichTextBox richTextBox1;
    }
}
