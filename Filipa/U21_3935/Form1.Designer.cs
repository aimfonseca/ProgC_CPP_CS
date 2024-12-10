namespace WinFormsApp_cardapio
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
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            comboBoxCategorias = new ComboBox();
            label5 = new Label();
            txtNome = new TextBox();
            txtPreco = new TextBox();
            txtDescricao = new TextBox();
            selectImagem = new Button();
            pictureBox1 = new PictureBox();
            button2 = new Button();
            listViewProdutos = new ListView();
            label6 = new Label();
            button1 = new Button();
            Atualizar = new Button();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(33, 118);
            label1.Name = "label1";
            label1.Size = new Size(40, 15);
            label1.TabIndex = 0;
            label1.Text = "Nome";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(33, 162);
            label2.Name = "label2";
            label2.Size = new Size(37, 15);
            label2.TabIndex = 1;
            label2.Text = "Preço";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(33, 206);
            label3.Name = "label3";
            label3.Size = new Size(58, 15);
            label3.TabIndex = 2;
            label3.Text = "Descrição";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(33, 365);
            label4.Name = "label4";
            label4.Size = new Size(31, 15);
            label4.TabIndex = 3;
            label4.Text = "Foto";
            // 
            // comboBoxCategorias
            // 
            comboBoxCategorias.BackColor = SystemColors.Info;
            comboBoxCategorias.FormattingEnabled = true;
            comboBoxCategorias.Location = new Point(33, 323);
            comboBoxCategorias.Name = "comboBoxCategorias";
            comboBoxCategorias.Size = new Size(217, 23);
            comboBoxCategorias.TabIndex = 4;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(33, 305);
            label5.Name = "label5";
            label5.Size = new Size(58, 15);
            label5.TabIndex = 5;
            label5.Text = "Categoria";
            // 
            // txtNome
            // 
            txtNome.BackColor = SystemColors.Info;
            txtNome.Location = new Point(33, 136);
            txtNome.Name = "txtNome";
            txtNome.Size = new Size(217, 23);
            txtNome.TabIndex = 6;
            // 
            // txtPreco
            // 
            txtPreco.BackColor = SystemColors.Info;
            txtPreco.Location = new Point(33, 180);
            txtPreco.Name = "txtPreco";
            txtPreco.Size = new Size(217, 23);
            txtPreco.TabIndex = 7;
            // 
            // txtDescricao
            // 
            txtDescricao.BackColor = SystemColors.Info;
            txtDescricao.Location = new Point(33, 224);
            txtDescricao.Multiline = true;
            txtDescricao.Name = "txtDescricao";
            txtDescricao.Size = new Size(217, 80);
            txtDescricao.TabIndex = 8;
            // 
            // selectImagem
            // 
            selectImagem.BackColor = SystemColors.Info;
            selectImagem.Location = new Point(70, 360);
            selectImagem.Name = "selectImagem";
            selectImagem.Size = new Size(180, 25);
            selectImagem.TabIndex = 10;
            selectImagem.Text = "Selecionar imagem";
            selectImagem.UseVisualStyleBackColor = false;
            selectImagem.Click += selectImagem_Click;
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = SystemColors.Info;
            pictureBox1.Location = new Point(33, 391);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(217, 197);
            pictureBox1.TabIndex = 11;
            pictureBox1.TabStop = false;
            pictureBox1.Click += pictureBox1_Click;
            // 
            // button2
            // 
            button2.BackColor = SystemColors.ButtonFace;
            button2.Location = new Point(33, 604);
            button2.Name = "button2";
            button2.Size = new Size(109, 39);
            button2.TabIndex = 12;
            button2.Text = "Inserir Produto";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // listViewProdutos
            // 
            listViewProdutos.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left;
            listViewProdutos.BackColor = SystemColors.Info;
            listViewProdutos.FullRowSelect = true;
            listViewProdutos.GridLines = true;
            listViewProdutos.LabelEdit = true;
            listViewProdutos.Location = new Point(292, 114);
            listViewProdutos.MultiSelect = false;
            listViewProdutos.Name = "listViewProdutos";
            listViewProdutos.Size = new Size(669, 585);
            listViewProdutos.TabIndex = 0;
            listViewProdutos.UseCompatibleStateImageBehavior = false;
            listViewProdutos.View = View.Details;
            listViewProdutos.ItemSelectionChanged += listViewProdutos_ItemSelectionChanged;
            listViewProdutos.SelectedIndexChanged += listViewProdutos_SelectedIndexChanged;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Microsoft YaHei UI Light", 24F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label6.Location = new Point(31, 37);
            label6.Name = "label6";
            label6.Size = new Size(300, 41);
            label6.TabIndex = 13;
            label6.Text = "Gestão de produtos";
            // 
            // button1
            // 
            button1.Location = new Point(150, 604);
            button1.Name = "button1";
            button1.Size = new Size(100, 39);
            button1.TabIndex = 14;
            button1.Text = "Eliminar";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // Atualizar
            // 
            Atualizar.Location = new Point(31, 647);
            Atualizar.Name = "Atualizar";
            Atualizar.Size = new Size(219, 45);
            Atualizar.TabIndex = 15;
            Atualizar.Text = "Atualizar";
            Atualizar.UseVisualStyleBackColor = true;
            Atualizar.Click += Atualizar_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ActiveCaption;
            ClientSize = new Size(977, 716);
            Controls.Add(Atualizar);
            Controls.Add(button1);
            Controls.Add(label6);
            Controls.Add(listViewProdutos);
            Controls.Add(button2);
            Controls.Add(pictureBox1);
            Controls.Add(selectImagem);
            Controls.Add(txtDescricao);
            Controls.Add(txtPreco);
            Controls.Add(txtNome);
            Controls.Add(label5);
            Controls.Add(comboBoxCategorias);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Painel de administrador";
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private ComboBox comboBoxCategorias;
        private Label label5;
        private TextBox txtNome;
        private TextBox txtPreco;
        private TextBox txtDescricao;
        private Button selectImagem;
        private PictureBox pictureBox1;
        private Button button2;
        private ListView listViewProdutos;
        private Label label6;
        private Button button1;
        private Button Atualizar;
    }
}
