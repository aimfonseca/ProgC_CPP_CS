using System;
using System.Reflection.Metadata;

namespace MatchingGame
{
    public partial class Form1 : Form
    {

        // firstClicked aponta para o primeiro controle Label 
        // que o jogador clicou, mas será null 
        // se o jogador ainda não tiver clicado em um rótulo
        Label firstClicked = null;

        // secondClicked aponta para o segundo controle Label 
        // que o jogador clicou
        Label secondClicked = null;

        public Form1()
        {
            InitializeComponent();

            AssignIconsToSquares();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        // Use este objeto Random para escolher ícones aleatórios para os quadrados
        Random random = new Random();

        // Cada uma dessas letras é um ícone interessante
        // na fonte Webdings,
        // e cada ícone aparece duas vezes nesta lista
        List<string> icons = new List<string>()
            {
            "S", "S", "N", "N", ",", ",", ".", ".","Q","Q",
            "M", "M", "W", "W", "Y", "Y", "Z", "Z","9","9",
            "1", "1", "2", "2", "3", "3", "4", "4",
            "8", "8", "7", "7", "6", "6", "5", "5"
            };

        /// <summary>
        /// Atribui cada ícone da lista de ícones a um quadrado aleatório
        /// </summary>
        private void AssignIconsToSquares()
        {
            // O TableLayoutPanel possui 16 Labels,
            // e a lista de ícones contém 16 ícones,
            // então um ícone é selecionado aleatoriamente da lista
            // e adicionado a cada Label
            foreach (Control control in tableLayoutPanel1.Controls)
            {
                Label iconLabel = control as Label;
                if (iconLabel != null)
                {
                    int randomNumber = random.Next(icons.Count);
                    iconLabel.Text = icons[randomNumber];
                    iconLabel.ForeColor = iconLabel.BackColor; // Oculta o ícone
                    icons.RemoveAt(randomNumber); // Remove o ícone atribuído da lista
                }
            }
        }

        /// <summary>
        /// Todos os eventos de clique dos Labels são tratados por este manipulador de eventos
        /// </summary>
        /// <param name="sender">O Label que foi clicado</param>
        /// <param name="e"></param>

        private void label1_Click(object sender, EventArgs e)
        {
            
            Label clickedLabel = sender as Label;

            if (clickedLabel != null)
            {
                // O timer só está ativado após dois ícones diferentes 
                // terem sido mostrados ao jogador,
                // então ignore qualquer clique se o timer estiver ativo
                if (timer1.Enabled == true)
                    return;

                // Se o Label clicado for preto, o jogador clicou
                // em um ícone que já foi revelado -- ignore o clique
                if (clickedLabel.ForeColor == Color.Black)
                    return;

                // Se firstClicked for null, este é o primeiro ícone
                // do par que o jogador clicou,
                // então defina firstClicked para o Label clicado,
                // mude sua cor para preto e retorne
                if (firstClicked == null)
                {
                    firstClicked = clickedLabel;
                    firstClicked.ForeColor = Color.Black;
                    return;
                }

                // Se o jogador chegar aqui, o timer não está
                // ativo e firstClicked não é null,
                // então este deve ser o segundo ícone clicado
                // Defina sua cor para preto
                secondClicked = clickedLabel;
                secondClicked.ForeColor = Color.Black;

                // Verifique se o jogador ganhou
                CheckForWinner();

                // Se o jogador clicou em dois ícones iguais, mantenha-os 
                // pretos e redefina firstClicked e secondClicked 
                // para que o jogador possa clicar em outro ícone
                if (firstClicked.Text == secondClicked.Text)
                {
                    firstClicked = null;
                    secondClicked = null;
                    return;
                }

                // Se o jogador chegar aqui, ele clicou em dois ícones diferentes,
                // então inicie o timer (que aguardará três quartos de segundo
                // e depois ocultará os ícones)
                timer1.Start();
            }
        }

        

        /// <summary>
        /// Este timer é iniciado quando o jogador clica 
        /// em dois ícones que não combinam,
        /// conta três quartos de segundo 
        /// e depois se desliga e oculta ambos os ícones
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void timer1_Tick(object sender, EventArgs e)
        {
            // Pare o timer
            timer1.Stop();

            // Oculte ambos os ícones
            firstClicked.ForeColor = firstClicked.BackColor;
            secondClicked.ForeColor = secondClicked.BackColor;

            // Redefina firstClicked e secondClicked 
            // para que, na próxima vez que um Label for clicado,
            // o programa saiba que é o primeiro clique
            firstClicked = null;
            secondClicked = null;
        }

        /// <summary>
        /// Verifica todos os ícones para ver se estão combinados, 
        /// comparando sua cor de primeiro plano com sua cor de fundo. 
        /// Se todos os ícones estiverem combinados, o jogador vence
        /// </summary>
        private void CheckForWinner()
        {
            // Percorra todos os Labels no TableLayoutPanel, 
            // verificando cada um para ver se seu ícone está combinado
            foreach (Control control in tableLayoutPanel1.Controls)
            {
                Label iconLabel = control as Label;

                if (iconLabel != null)
                {
                    if (iconLabel.ForeColor == iconLabel.BackColor)
                        return;
                }
            }

            // Se o loop não retornar, significa que
            // não encontrou ícones não combinados
            // Isso significa que o jogador venceu. Mostre uma mensagem e feche o formulário
            MessageBox.Show("Você combinou todos os ícones!", "Parabéns");
            Close();
        }
    }
}
