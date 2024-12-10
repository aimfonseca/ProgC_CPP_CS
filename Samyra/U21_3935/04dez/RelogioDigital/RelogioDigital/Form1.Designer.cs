namespace RelogioDigital
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
            components = new System.ComponentModel.Container();
            lblHoras = new Label();
            lblMinutos = new Label();
            label3 = new Label();
            lblSegundos = new Label();
            label5 = new Label();
            btnConfigurar = new Button();
            btnOk = new Button();
            btnHorasMenos = new Button();
            btnHorasMais = new Button();
            btnMinutosMenos = new Button();
            btnMinutosMais = new Button();
            btnSegundosMais = new Button();
            btnSegundosMenos = new Button();
            timerRelogioDigital = new System.Windows.Forms.Timer(components);
            SuspendLayout();
            // 
            // lblHoras
            // 
            lblHoras.AutoSize = true;
            lblHoras.Font = new Font("Arial", 48F, FontStyle.Regular, GraphicsUnit.Point, 0);
            lblHoras.Location = new Point(56, 70);
            lblHoras.Name = "lblHoras";
            lblHoras.Size = new Size(126, 89);
            lblHoras.TabIndex = 0;
            lblHoras.Text = "00";
            // 
            // lblMinutos
            // 
            lblMinutos.AutoSize = true;
            lblMinutos.Font = new Font("Arial", 48F, FontStyle.Regular, GraphicsUnit.Point, 0);
            lblMinutos.Location = new Point(203, 70);
            lblMinutos.Name = "lblMinutos";
            lblMinutos.Size = new Size(126, 89);
            lblMinutos.TabIndex = 1;
            lblMinutos.Text = "00";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Arial", 48F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label3.Location = new Point(314, 70);
            label3.Name = "label3";
            label3.Size = new Size(60, 89);
            label3.TabIndex = 2;
            label3.Text = ":";
            // 
            // lblSegundos
            // 
            lblSegundos.AutoSize = true;
            lblSegundos.Font = new Font("Arial", 48F, FontStyle.Regular, GraphicsUnit.Point, 0);
            lblSegundos.Location = new Point(352, 70);
            lblSegundos.Name = "lblSegundos";
            lblSegundos.Size = new Size(126, 89);
            lblSegundos.TabIndex = 3;
            lblSegundos.Text = "00";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Arial", 48F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label5.Location = new Point(162, 70);
            label5.Name = "label5";
            label5.Size = new Size(60, 89);
            label5.TabIndex = 4;
            label5.Text = ":";
            // 
            // btnConfigurar
            // 
            btnConfigurar.BackColor = Color.White;
            btnConfigurar.Location = new Point(151, 237);
            btnConfigurar.Name = "btnConfigurar";
            btnConfigurar.Size = new Size(94, 29);
            btnConfigurar.TabIndex = 5;
            btnConfigurar.Text = "Configurar";
            btnConfigurar.UseVisualStyleBackColor = false;
            btnConfigurar.Click += btnConfigurar_Click;
            // 
            // btnOk
            // 
            btnOk.Location = new Point(294, 237);
            btnOk.Name = "btnOk";
            btnOk.Size = new Size(94, 29);
            btnOk.TabIndex = 6;
            btnOk.Text = "ok";
            btnOk.UseVisualStyleBackColor = true;
            btnOk.Visible = false;
            btnOk.Click += btnOk_Click;
            // 
            // btnHorasMenos
            // 
            btnHorasMenos.Location = new Point(74, 162);
            btnHorasMenos.Name = "btnHorasMenos";
            btnHorasMenos.Size = new Size(43, 29);
            btnHorasMenos.TabIndex = 7;
            btnHorasMenos.Text = "-";
            btnHorasMenos.UseVisualStyleBackColor = true;
            btnHorasMenos.Visible = false;
            btnHorasMenos.Click += btnHorasMenos_Click;
            // 
            // btnHorasMais
            // 
            btnHorasMais.Location = new Point(123, 162);
            btnHorasMais.Name = "btnHorasMais";
            btnHorasMais.Size = new Size(43, 29);
            btnHorasMais.TabIndex = 8;
            btnHorasMais.Text = "+";
            btnHorasMais.UseVisualStyleBackColor = true;
            btnHorasMais.Visible = false;
            btnHorasMais.Click += btnHorasMais_Click_1;
            // 
            // btnMinutosMenos
            // 
            btnMinutosMenos.Location = new Point(222, 162);
            btnMinutosMenos.Name = "btnMinutosMenos";
            btnMinutosMenos.Size = new Size(43, 29);
            btnMinutosMenos.TabIndex = 9;
            btnMinutosMenos.Text = "-";
            btnMinutosMenos.UseVisualStyleBackColor = true;
            btnMinutosMenos.Visible = false;
            btnMinutosMenos.Click += btnMinutosMenos_Click;
            // 
            // btnMinutosMais
            // 
            btnMinutosMais.Location = new Point(271, 162);
            btnMinutosMais.Name = "btnMinutosMais";
            btnMinutosMais.Size = new Size(43, 29);
            btnMinutosMais.TabIndex = 10;
            btnMinutosMais.Text = "+";
            btnMinutosMais.UseVisualStyleBackColor = true;
            btnMinutosMais.Visible = false;
            btnMinutosMais.Click += btnMinutosMais_Click;
            // 
            // btnSegundosMais
            // 
            btnSegundosMais.Location = new Point(414, 162);
            btnSegundosMais.Name = "btnSegundosMais";
            btnSegundosMais.Size = new Size(43, 29);
            btnSegundosMais.TabIndex = 12;
            btnSegundosMais.Text = "+";
            btnSegundosMais.UseVisualStyleBackColor = true;
            btnSegundosMais.Visible = false;
            btnSegundosMais.Click += btnSegundosMais_Click;
            // 
            // btnSegundosMenos
            // 
            btnSegundosMenos.Location = new Point(365, 162);
            btnSegundosMenos.Name = "btnSegundosMenos";
            btnSegundosMenos.Size = new Size(43, 29);
            btnSegundosMenos.TabIndex = 11;
            btnSegundosMenos.Text = "-";
            btnSegundosMenos.UseVisualStyleBackColor = true;
            btnSegundosMenos.Visible = false;
            btnSegundosMenos.Click += btnSegundosMenos_Click;
            // 
            // timerRelogioDigital
            // 
            timerRelogioDigital.Enabled = true;
            timerRelogioDigital.Interval = 1000;
            timerRelogioDigital.Tick += timerRelogioDigital_Tick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(192, 192, 255);
            ClientSize = new Size(529, 298);
            Controls.Add(btnSegundosMais);
            Controls.Add(btnSegundosMenos);
            Controls.Add(btnMinutosMais);
            Controls.Add(btnMinutosMenos);
            Controls.Add(btnHorasMais);
            Controls.Add(btnHorasMenos);
            Controls.Add(btnOk);
            Controls.Add(btnConfigurar);
            Controls.Add(label5);
            Controls.Add(lblSegundos);
            Controls.Add(label3);
            Controls.Add(lblMinutos);
            Controls.Add(lblHoras);
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Relógio Digital";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label lblHoras;
        private Label lblMinutos;
        private Label label3;
        private Label lblSegundos;
        private Label label5;
        private Button btnConfigurar;
        private Button btnOk;
        private Button btnHorasMenos;
        private Button btnHorasMais;
        private Button btnMinutosMenos;
        private Button btnMinutosMais;
        private Button btnSegundosMais;
        private Button btnSegundosMenos;
        private System.Windows.Forms.Timer timerRelogioDigital;
    }
}
