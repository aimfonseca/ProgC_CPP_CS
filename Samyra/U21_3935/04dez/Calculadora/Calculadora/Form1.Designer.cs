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
            btnSete = new Button();
            txtResultado = new TextBox();
            btnOito = new Button();
            btnNove = new Button();
            btnDivisao = new Button();
            btnQuatro = new Button();
            btnCinco = new Button();
            btnSeis = new Button();
            btnMultiplicacao = new Button();
            btnUm = new Button();
            btnDois = new Button();
            btnTres = new Button();
            btnAdicao = new Button();
            btnVirgula = new Button();
            btnZero = new Button();
            btnIgual = new Button();
            btnSubtracao = new Button();
            btnLimpar = new Button();
            lblOperacao = new Label();
            SuspendLayout();
            // 
            // btnSete
            // 
            btnSete.BackColor = Color.Gray;
            btnSete.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnSete.ForeColor = Color.White;
            btnSete.Location = new Point(29, 183);
            btnSete.Name = "btnSete";
            btnSete.Size = new Size(77, 67);
            btnSete.TabIndex = 0;
            btnSete.Text = "7";
            btnSete.UseVisualStyleBackColor = false;
            btnSete.Click += btnSete_Click;
            // 
            // txtResultado
            // 
            txtResultado.BackColor = SystemColors.ControlText;
            txtResultado.Font = new Font("Arial Black", 28.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            txtResultado.ForeColor = Color.Transparent;
            txtResultado.Location = new Point(29, 28);
            txtResultado.Multiline = true;
            txtResultado.Name = "txtResultado";
            txtResultado.ReadOnly = true;
            txtResultado.Size = new Size(326, 71);
            txtResultado.TabIndex = 1;
            txtResultado.TextAlign = HorizontalAlignment.Right;
            // 
            // btnOito
            // 
            btnOito.BackColor = Color.Gray;
            btnOito.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnOito.ForeColor = Color.White;
            btnOito.Location = new Point(112, 183);
            btnOito.Name = "btnOito";
            btnOito.Size = new Size(77, 67);
            btnOito.TabIndex = 2;
            btnOito.Text = "8";
            btnOito.UseVisualStyleBackColor = false;
            btnOito.Click += btnOito_Click;
            // 
            // btnNove
            // 
            btnNove.BackColor = Color.Gray;
            btnNove.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnNove.ForeColor = Color.White;
            btnNove.Location = new Point(195, 183);
            btnNove.Name = "btnNove";
            btnNove.Size = new Size(77, 67);
            btnNove.TabIndex = 3;
            btnNove.Text = "9";
            btnNove.UseVisualStyleBackColor = false;
            btnNove.Click += btnNove_Click;
            // 
            // btnDivisao
            // 
            btnDivisao.BackColor = Color.FromArgb(64, 64, 64);
            btnDivisao.Font = new Font("Arial", 16.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            btnDivisao.ForeColor = Color.FromArgb(0, 192, 0);
            btnDivisao.Location = new Point(278, 110);
            btnDivisao.Name = "btnDivisao";
            btnDivisao.Size = new Size(77, 67);
            btnDivisao.TabIndex = 4;
            btnDivisao.Text = "/";
            btnDivisao.UseVisualStyleBackColor = false;
            btnDivisao.Click += btnDivisao_Click;
            // 
            // btnQuatro
            // 
            btnQuatro.BackColor = Color.Gray;
            btnQuatro.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnQuatro.ForeColor = Color.White;
            btnQuatro.Location = new Point(29, 256);
            btnQuatro.Name = "btnQuatro";
            btnQuatro.Size = new Size(77, 67);
            btnQuatro.TabIndex = 5;
            btnQuatro.Text = "4";
            btnQuatro.UseVisualStyleBackColor = false;
            btnQuatro.Click += btnQuatro_Click;
            // 
            // btnCinco
            // 
            btnCinco.BackColor = Color.Gray;
            btnCinco.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnCinco.ForeColor = Color.White;
            btnCinco.Location = new Point(112, 256);
            btnCinco.Name = "btnCinco";
            btnCinco.Size = new Size(77, 67);
            btnCinco.TabIndex = 6;
            btnCinco.Text = "5";
            btnCinco.UseVisualStyleBackColor = false;
            btnCinco.Click += btnCinco_Click;
            // 
            // btnSeis
            // 
            btnSeis.BackColor = Color.Gray;
            btnSeis.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnSeis.ForeColor = Color.White;
            btnSeis.Location = new Point(195, 256);
            btnSeis.Name = "btnSeis";
            btnSeis.Size = new Size(77, 67);
            btnSeis.TabIndex = 7;
            btnSeis.Text = "6";
            btnSeis.UseVisualStyleBackColor = false;
            btnSeis.Click += btnSeis_Click;
            // 
            // btnMultiplicacao
            // 
            btnMultiplicacao.BackColor = Color.FromArgb(64, 64, 64);
            btnMultiplicacao.Font = new Font("Arial", 13.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            btnMultiplicacao.ForeColor = Color.FromArgb(0, 192, 0);
            btnMultiplicacao.Location = new Point(278, 183);
            btnMultiplicacao.Name = "btnMultiplicacao";
            btnMultiplicacao.Size = new Size(77, 67);
            btnMultiplicacao.TabIndex = 8;
            btnMultiplicacao.Text = "x";
            btnMultiplicacao.UseVisualStyleBackColor = false;
            btnMultiplicacao.Click += btnMultiplicacao_Click;
            // 
            // btnUm
            // 
            btnUm.BackColor = Color.Gray;
            btnUm.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnUm.ForeColor = Color.White;
            btnUm.Location = new Point(29, 329);
            btnUm.Name = "btnUm";
            btnUm.Size = new Size(77, 67);
            btnUm.TabIndex = 9;
            btnUm.Text = "1";
            btnUm.UseVisualStyleBackColor = false;
            btnUm.Click += btnUm_Click;
            // 
            // btnDois
            // 
            btnDois.BackColor = Color.Gray;
            btnDois.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnDois.ForeColor = Color.White;
            btnDois.Location = new Point(112, 329);
            btnDois.Name = "btnDois";
            btnDois.Size = new Size(77, 67);
            btnDois.TabIndex = 10;
            btnDois.Text = "2";
            btnDois.UseVisualStyleBackColor = false;
            btnDois.Click += btnDois_Click;
            // 
            // btnTres
            // 
            btnTres.BackColor = Color.Gray;
            btnTres.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnTres.ForeColor = Color.White;
            btnTres.Location = new Point(195, 329);
            btnTres.Name = "btnTres";
            btnTres.Size = new Size(77, 67);
            btnTres.TabIndex = 11;
            btnTres.Text = "3";
            btnTres.UseVisualStyleBackColor = false;
            btnTres.Click += btnTres_Click;
            // 
            // btnAdicao
            // 
            btnAdicao.BackColor = Color.FromArgb(64, 64, 64);
            btnAdicao.Font = new Font("Arial", 16.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            btnAdicao.ForeColor = Color.FromArgb(0, 192, 0);
            btnAdicao.Location = new Point(278, 329);
            btnAdicao.Name = "btnAdicao";
            btnAdicao.Size = new Size(77, 67);
            btnAdicao.TabIndex = 12;
            btnAdicao.Text = "+";
            btnAdicao.UseVisualStyleBackColor = false;
            btnAdicao.Click += btnAdicao_Click;
            // 
            // btnVirgula
            // 
            btnVirgula.BackColor = Color.Gray;
            btnVirgula.Font = new Font("Arial", 16.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            btnVirgula.ForeColor = Color.White;
            btnVirgula.Location = new Point(195, 402);
            btnVirgula.Name = "btnVirgula";
            btnVirgula.Size = new Size(77, 67);
            btnVirgula.TabIndex = 13;
            btnVirgula.Text = ",";
            btnVirgula.UseVisualStyleBackColor = false;
            btnVirgula.Click += btnVirgula_Click;
            // 
            // btnZero
            // 
            btnZero.BackColor = Color.Gray;
            btnZero.Font = new Font("Arial", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnZero.ForeColor = Color.White;
            btnZero.Location = new Point(29, 402);
            btnZero.Name = "btnZero";
            btnZero.Size = new Size(160, 67);
            btnZero.TabIndex = 14;
            btnZero.Text = "0";
            btnZero.UseVisualStyleBackColor = false;
            btnZero.Click += btnZero_Click;
            // 
            // btnIgual
            // 
            btnIgual.BackColor = Color.FromArgb(0, 192, 0);
            btnIgual.Font = new Font("Arial", 16.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            btnIgual.ForeColor = Color.White;
            btnIgual.Location = new Point(278, 402);
            btnIgual.Name = "btnIgual";
            btnIgual.Size = new Size(77, 67);
            btnIgual.TabIndex = 15;
            btnIgual.Text = "=";
            btnIgual.UseVisualStyleBackColor = false;
            btnIgual.Click += btnIgual_Click;
            // 
            // btnSubtracao
            // 
            btnSubtracao.BackColor = Color.FromArgb(64, 64, 64);
            btnSubtracao.Font = new Font("Arial", 16.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            btnSubtracao.ForeColor = Color.FromArgb(0, 192, 0);
            btnSubtracao.Location = new Point(278, 256);
            btnSubtracao.Name = "btnSubtracao";
            btnSubtracao.Size = new Size(77, 67);
            btnSubtracao.TabIndex = 16;
            btnSubtracao.Text = "-";
            btnSubtracao.UseVisualStyleBackColor = false;
            btnSubtracao.Click += btnSubtracao_Click;
            // 
            // btnLimpar
            // 
            btnLimpar.BackColor = Color.FromArgb(64, 64, 64);
            btnLimpar.Font = new Font("Arial", 16.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            btnLimpar.ForeColor = Color.FromArgb(255, 128, 0);
            btnLimpar.Location = new Point(29, 110);
            btnLimpar.Name = "btnLimpar";
            btnLimpar.Size = new Size(77, 67);
            btnLimpar.TabIndex = 17;
            btnLimpar.Text = "C";
            btnLimpar.UseVisualStyleBackColor = false;
            btnLimpar.Click += btnLimpar_Click;
            // 
            // lblOperacao
            // 
            lblOperacao.AutoSize = true;
            lblOperacao.BackColor = Color.Black;
            lblOperacao.Font = new Font("Arial", 22.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            lblOperacao.ForeColor = SystemColors.ControlLightLight;
            lblOperacao.Location = new Point(43, 40);
            lblOperacao.Name = "lblOperacao";
            lblOperacao.Size = new Size(0, 42);
            lblOperacao.TabIndex = 18;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.WindowText;
            ClientSize = new Size(391, 487);
            Controls.Add(lblOperacao);
            Controls.Add(btnLimpar);
            Controls.Add(btnSubtracao);
            Controls.Add(btnIgual);
            Controls.Add(btnZero);
            Controls.Add(btnVirgula);
            Controls.Add(btnAdicao);
            Controls.Add(btnTres);
            Controls.Add(btnDois);
            Controls.Add(btnUm);
            Controls.Add(btnMultiplicacao);
            Controls.Add(btnSeis);
            Controls.Add(btnCinco);
            Controls.Add(btnQuatro);
            Controls.Add(btnDivisao);
            Controls.Add(btnNove);
            Controls.Add(btnOito);
            Controls.Add(txtResultado);
            Controls.Add(btnSete);
            ForeColor = SystemColors.InactiveCaptionText;
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Calculadora";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button btnSete;
        private TextBox txtResultado;
        private Button btnOito;
        private Button btnNove;
        private Button btnDivisao;
        private Button btnQuatro;
        private Button btnCinco;
        private Button btnSeis;
        private Button btnMultiplicacao;
        private Button btnUm;
        private Button btnDois;
        private Button btnTres;
        private Button btnAdicao;
        private Button btnVirgula;
        private Button btnZero;
        private Button btnIgual;
        private Button btnSubtracao;
        private Button btnLimpar;
        private Label lblOperacao;
    }
}
