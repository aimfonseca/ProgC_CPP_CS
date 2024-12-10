using Microsoft.Win32.SafeHandles;
using MySql.Data.MySqlClient;

namespace WinFormsApp_cardapio
{
    public partial class Form1 : Form
    {
        private MySqlConnection conn;
        private string nomeImagem = string.Empty; // Vari�vel para armazenar o nome da imagem
        private int? id_produto_selecionado = 0;

        public Form1()
        {
            InitializeComponent();
            LoadCategorias(); // Chama o m�todo para carregar as categorias ao iniciar o formul�rio
            LoadProdutos(); // Chama o m�todo para carregar os produtos ao iniciar o formul�rio
        }
        private void LoadCategorias()
        {
            try
            {
                string data_source = "datasource=localhost;username=root;password=;database=restaurante_bd";
                conn = new MySqlConnection(data_source);

                string sql = "SELECT id, nome FROM categorias"; // Seleciona tanto o ID quanto o nome das categorias

                MySqlCommand comando = new MySqlCommand(sql, conn);

                conn.Open();

                MySqlDataReader reader = comando.ExecuteReader();

                // Limpa itens antigos
                comboBoxCategorias.Items.Clear();

                while (reader.Read())
                {
                    // Adiciona cada categoria � ComboBox, mas o valor da categoria � o ID
                    comboBoxCategorias.Items.Add(new KeyValuePair<int, string>((int)reader["id"], (string)reader["nome"]));
                }

                reader.Close();

                // Define o que ser� exibido na ComboBox e o que ser� armazenado como valor
                comboBoxCategorias.DisplayMember = "Value"; // Exibe o nome
                comboBoxCategorias.ValueMember = "Key"; // Armazena o ID

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                conn.Close();
            }
        }
        // Evento ao clicar no bot�o para inserir o produto
        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string data_source = "datasource=localhost;username=root;password=;database=restaurante_bd";
                conn = new MySqlConnection(data_source);
                conn.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = conn;

                // L�gica corrigida: se id_produto_selecionado for null, deve inserir um novo produto
                if (id_produto_selecionado == 0 || id_produto_selecionado == null)
                {
                    // Inserir produto
                    int categoriaId = ((KeyValuePair<int, string>)comboBoxCategorias.SelectedItem).Key;

                    cmd.CommandText = "INSERT INTO produtos (nome, descricao, preco, imagem, id_categoria) " +
                                      "VALUES (@nome, @descricao, @preco, @imagem, @id_categoria)";


                    cmd.Parameters.AddWithValue("@nome", txtNome.Text);
                    cmd.Parameters.AddWithValue("@descricao", txtDescricao.Text);
                    cmd.Parameters.AddWithValue("@preco", txtPreco.Text);
                    cmd.Parameters.AddWithValue("@imagem", nomeImagem); // Passa o nome da imagem
                    cmd.Parameters.AddWithValue("@id_categoria", categoriaId); // Passa o ID da categoria

                    cmd.ExecuteNonQuery();

                    MessageBox.Show("Produto inserido com sucesso!", "Sucesso!", MessageBoxButtons.OK, MessageBoxIcon.Information);

                    // Limpa os campos de entrada
                    txtNome.Text = string.Empty;
                    txtPreco.Text = string.Empty;
                    txtDescricao.Text = string.Empty;
                    comboBoxCategorias.SelectedIndex = -1; // Reseta a sele��o do ComboBox
                    pictureBox1.Image = null;
                }
                else
                {
                    // Alterar produto
                    int categoriaId = ((KeyValuePair<int, string>)comboBoxCategorias.SelectedItem).Key;

                    // Verifica se uma nova imagem foi selecionada
                    if (string.IsNullOrEmpty(nomeImagem))
                    {
                        // Se n�o foi selecionada, busca o nome da imagem atual no banco de dados
                        string sqlImagem = "SELECT imagem FROM produtos WHERE id = @id";
                        MySqlCommand cmdImagem = new MySqlCommand(sqlImagem, conn);
                        cmdImagem.Parameters.AddWithValue("@id", id_produto_selecionado);
                        nomeImagem = cmdImagem.ExecuteScalar()?.ToString(); // Obt�m o nome da imagem atual
                    }


                    cmd.CommandText = "UPDATE produtos SET " +
                                      "nome=@nome, descricao=@descricao, preco=@preco, imagem=@imagem, id_categoria=@id_categoria " +
                                      "WHERE id=@id";

                    cmd.Parameters.AddWithValue("@nome", txtNome.Text);
                    cmd.Parameters.AddWithValue("@descricao", txtDescricao.Text);
                    cmd.Parameters.AddWithValue("@preco", txtPreco.Text);
                    cmd.Parameters.AddWithValue("@imagem", nomeImagem); // Passa o nome da imagem, seja o novo ou o existente
                    cmd.Parameters.AddWithValue("@id_categoria", categoriaId); // Passa o ID da categoria
                    cmd.Parameters.AddWithValue("@id", id_produto_selecionado); // Passa o ID do produto para atualizar

                    cmd.ExecuteNonQuery();

                    MessageBox.Show("Produto atualizado com sucesso!", "Sucesso!", MessageBoxButtons.OK, MessageBoxIcon.Information);

                    // Limpa os campos de entrada
                    txtNome.Text = string.Empty;
                    txtPreco.Text = string.Empty;
                    txtDescricao.Text = string.Empty;
                    comboBoxCategorias.SelectedIndex = -1; // Reseta a sele��o do ComboBox
                    pictureBox1.Image = null;
                    button2.Text = "Inserir Produto";
                }


                LoadProdutos(); // Atualiza a ListView com os produtos ap�s a inser��o/atualiza��o

            }
            catch (Exception ex)
            {
                MessageBox.Show("Erro: " + ex.Message);
            }
            finally
            {
                conn.Close();
            }
        }

        // Evento ao clicar no bot�o para selecionar a imagem
        private void selectImagem_Click(object sender, EventArgs e)
        {
            // Cria��o do OpenFileDialog para permitir ao usu�rio selecionar uma imagem
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.gif;*.bmp";
            openFileDialog.Title = "Selecionar Imagem";

            // Verifica se o usu�rio selecionou um arquivo
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    // Obt�m o caminho completo da imagem selecionada
                    string caminhoImagemSelecionada = openFileDialog.FileName;

                    // Gera um nome �nico para a imagem, por exemplo, um GUID ou o nome do arquivo original
                    nomeImagem = Path.GetFileName(caminhoImagemSelecionada); // Obt�m apenas o nome da imagem

                    // Caminho completo para salvar a imagem no diret�rio
                    string caminhoDestino = Path.Combine("C:\\Users\\filip\\Documents\\GitHub\\restaurante2\\static\\imgs", nomeImagem);

                    // Copia a imagem selecionada para o diret�rio de destino
                    File.Copy(caminhoImagemSelecionada, caminhoDestino);

                    // Exibe a imagem no PictureBox
                    pictureBox1.Image = Image.FromFile(caminhoDestino);
                    pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage; // Ajusta o tamanho da imagem no PictureBox
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Erro ao carregar a imagem: " + ex.Message);
                }
            }
        }
        // Evento ao clicar na imagem para exibir em maior tamanho ou fazer outras a��es (se necess�rio)
        private void pictureBox1_Click(object sender, EventArgs e)
        {
            // Adicione a��es que deseja realizar quando o usu�rio clicar na imagem, se necess�rio.
        }
        private void listViewProdutos_SelectedIndexChanged(object sender, EventArgs e)
        {
            // A��es ao selecionar um item na ListView (se necess�rio)
        }
        private void LoadProdutos()
        {
            try
            {
                // Caminho base para as imagens
                string caminhoImagens = "C:\\Users\\filip\\Documents\\GitHub\\restaurante2\\static\\imgs\\";

                // Define a conex�o com o banco de dados
                string data_source = "datasource=localhost;username=root;password=;database=restaurante_bd";
                conn = new MySqlConnection(data_source);

                string sql = "SELECT id, nome, descricao, preco, imagem, id_categoria FROM produtos ORDER BY id_categoria";
                MySqlCommand comando = new MySqlCommand(sql, conn);

                conn.Open();
                MySqlDataReader reader = comando.ExecuteReader();

                listViewProdutos.Items.Clear();

                ImageList imageList = new ImageList
                {
                    ImageSize = new Size(80, 80)
                };
                listViewProdutos.SmallImageList = imageList;

                listViewProdutos.View = View.Details;
                listViewProdutos.Columns.Clear();
                listViewProdutos.Columns.Add("Imagem", 80);
                listViewProdutos.Columns.Add("Id", 0);
                listViewProdutos.Columns.Add("Nome", 150);
                listViewProdutos.Columns.Add("Descri��o", 230);
                listViewProdutos.Columns.Add("Pre�o", 100);
                listViewProdutos.Columns.Add("Categoria", 100);

                while (reader.Read())
                {
                    ListViewItem item = new ListViewItem();
                    item.SubItems.Add(reader["id"].ToString());

                    string nomeImagemProduto = reader["imagem"].ToString();
                    string caminhoImagemProduto = Path.Combine(caminhoImagens, nomeImagemProduto);

                    if (File.Exists(caminhoImagemProduto))
                    {
                        // Carrega a imagem para mem�ria usando MemoryStream
                        using (var stream = new MemoryStream(File.ReadAllBytes(caminhoImagemProduto)))
                        {
                            Image imagemProduto = Image.FromStream(stream);
                            imageList.Images.Add(imagemProduto);
                        }

                        item.ImageIndex = imageList.Images.Count - 1;
                    }
                    else
                    {
                        item.ImageIndex = -1;
                    }

                    item.SubItems.Add(reader["nome"].ToString());
                    item.SubItems.Add(reader["descricao"].ToString());
                    item.SubItems.Add(reader["preco"].ToString());
                    item.SubItems.Add(reader["id_categoria"].ToString());

                    item.Tag = nomeImagemProduto;
                    listViewProdutos.Items.Add(item);
                }

                reader.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                conn.Close();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                if (listViewProdutos.SelectedItems.Count == 0)
                {
                    MessageBox.Show("Selecione um produto para excluir.");
                    return;
                }

                ListViewItem itemSelecionado = listViewProdutos.SelectedItems[0];
                int produtoId = int.Parse(itemSelecionado.SubItems[1].Text);
                string nomeImagemProduto = itemSelecionado.Tag as string;

                const string dataSource = "datasource=localhost;username=root;password=;database=restaurante_bd";
                conn = new MySqlConnection(dataSource);

                string sql = "DELETE FROM produtos WHERE id = @id";
                MySqlCommand comando = new MySqlCommand(sql, conn);
                comando.Parameters.AddWithValue("@id", produtoId);

                conn.Open();
                int resultado = comando.ExecuteNonQuery();

                if (resultado > 0)
                {
                    string caminhoImagem = Path.Combine("C:\\Users\\filip\\Documents\\GitHub\\restaurante2\\static\\imgs", nomeImagemProduto);

                    if (pictureBox1.Image != null)
                    {
                        pictureBox1.Image.Dispose();
                        pictureBox1.Image = null;
                    }

                    if (File.Exists(caminhoImagem))
                    {
                        File.Delete(caminhoImagem);
                    }
                    // Limpa os campos de entrada
                    txtNome.Text = string.Empty;
                    txtPreco.Text = string.Empty;
                    txtDescricao.Text = string.Empty;
                    comboBoxCategorias.SelectedIndex = -1; // Reseta a sele��o do ComboBox
                    pictureBox1.Image = null;
                    button2.Text = "Inserir Produto";

                    MessageBox.Show("Produto exclu�do com sucesso.");

                    LoadProdutos();
                }
                else
                {
                    MessageBox.Show("Nenhum produto foi exclu�do. Verifique o ID.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Erro ao excluir produto: {ex.Message}");
            }
            finally
            {
                conn?.Close();
            }
        }


        private void listViewProdutos_ItemSelectionChanged(object sender, ListViewItemSelectionChangedEventArgs e)
        {
            ListView.SelectedListViewItemCollection itens_selecionados = listViewProdutos.SelectedItems;

            if (listViewProdutos.SelectedItems.Count > 0)
            {
                // Altera o texto do bot�o
                button2.Text = "Alterar Produto";

                foreach (ListViewItem item in itens_selecionados)
                {
                    id_produto_selecionado = Convert.ToInt32(item.SubItems[1].Text);
                    txtNome.Text = item.SubItems[2].Text;
                    txtDescricao.Text = item.SubItems[3].Text;
                    txtPreco.Text = item.SubItems[4].Text;

                    // Seleciona a categoria na ComboBox
                    int categoriaId = int.Parse(item.SubItems[5].Text);
                    foreach (KeyValuePair<int, string> categoria in comboBoxCategorias.Items)
                    {
                        if (categoria.Key == categoriaId)
                        {
                            comboBoxCategorias.SelectedItem = categoria;
                            break;
                        }
                    }

                    // Atualiza a imagem no PictureBox com base no nome salvo no Tag
                    string nomeImagemProduto = item.Tag as string; // Recupera o nome da imagem
                    if (!string.IsNullOrEmpty(nomeImagemProduto))
                    {
                        string caminhoImagem = Path.Combine("C:\\Users\\filip\\Documents\\GitHub\\restaurante2\\static\\imgs", nomeImagemProduto);
                        if (File.Exists(caminhoImagem))
                        {
                            pictureBox1.Image = Image.FromFile(caminhoImagem);
                            pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
                        }
                        else
                        {
                            pictureBox1.Image = null;
                        }
                    }
                    else
                    {
                        pictureBox1.Image = null;
                    }
                }
            }
            else
            {
                // Restaura o texto do bot�o ao estado padr�o
                button2.Text = "Inserir Produto";

                // Limpa os campos e a imagem caso nenhum item esteja selecionado
                txtNome.Text = string.Empty;
                txtDescricao.Text = string.Empty;
                txtPreco.Text = string.Empty;
                comboBoxCategorias.SelectedIndex = -1;
                pictureBox1.Image = null;
            }
        }

        private void Atualizar_Click(object sender, EventArgs e)
        {
            LoadProdutos();
        }

    }
}