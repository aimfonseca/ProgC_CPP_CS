using System;
using System.Reflection.Metadata;

namespace MatchingGame
{
    public partial class Form1 : Form
    {

        // firstClicked aponta para o primeiro controle Label 
        // que o jogador clicou, mas ser� null 
        // se o jogador ainda n�o tiver clicado em um r�tulo
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

        // Use este objeto Random para escolher �cones aleat�rios para os quadrados
        Random random = new Random();

        // Cada uma dessas letras � um �cone interessante
        // na fonte Webdings,
        // e cada �cone aparece duas vezes nesta lista
        List<string> icons = new List<string>()
            {
            "S", "S", "N", "N", ",", ",", ".", ".","Q","Q",
            "M", "M", "W", "W", "Y", "Y", "Z", "Z","9","9",
            "1", "1", "2", "2", "3", "3", "4", "4",
            "8", "8", "7", "7", "6", "6", "5", "5"
            };

        /// <summary>
        /// Atribui cada �cone da lista de �cones a um quadrado aleat�rio
        /// </summary>
        private void AssignIconsToSquares()
        {
            // O TableLayoutPanel possui 16 Labels,
            // e a lista de �cones cont�m 16 �cones,
            // ent�o um �cone � selecionado aleatoriamente da lista
            // e adicionado a cada Label
            foreach (Control control in tableLayoutPanel1.Controls)
            {
                Label iconLabel = control as Label;
                if (iconLabel != null)
                {
                    int randomNumber = random.Next(icons.Count);
                    iconLabel.Text = icons[randomNumber];
                    iconLabel.ForeColor = iconLabel.BackColor; // Oculta o �cone
                    icons.RemoveAt(randomNumber); // Remove o �cone atribu�do da lista
                }
            }
        }

        /// <summary>
        /// Todos os eventos de clique dos Labels s�o tratados por este manipulador de eventos
        /// </summary>
        /// <param name="sender">O Label que foi clicado</param>
        /// <param name="e"></param>

        private void label1_Click(object sender, EventArgs e)
        {
            
            Label clickedLabel = sender as Label;

            if (clickedLabel != null)
            {
                // O timer s� est� ativado ap�s dois �cones diferentes 
                // terem sido mostrados ao jogador,
                // ent�o ignore qualquer clique se o timer estiver ativo
                if (timer1.Enabled == true)
                    return;

                // Se o Label clicado for preto, o jogador clicou
                // em um �cone que j� foi revelado -- ignore o clique
                if (clickedLabel.ForeColor == Color.Black)
                    return;

                // Se firstClicked for null, este � o primeiro �cone
                // do par que o jogador clicou,
                // ent�o defina firstClicked para o Label clicado,
                // mude sua cor para preto e retorne
                if (firstClicked == null)
                {
                    firstClicked = clickedLabel;
                    firstClicked.ForeColor = Color.Black;
                    return;
                }

                // Se o jogador chegar aqui, o timer n�o est�
                // ativo e firstClicked n�o � null,
                // ent�o este deve ser o segundo �cone clicado
                // Defina sua cor para preto
                secondClicked = clickedLabel;
                secondClicked.ForeColor = Color.Black;

                // Verifique se o jogador ganhou
                CheckForWinner();

                // Se o jogador clicou em dois �cones iguais, mantenha-os 
                // pretos e redefina firstClicked e secondClicked 
                // para que o jogador possa clicar em outro �cone
                if (firstClicked.Text == secondClicked.Text)
                {
                    firstClicked = null;
                    secondClicked = null;
                    return;
                }

                // Se o jogador chegar aqui, ele clicou em dois �cones diferentes,
                // ent�o inicie o timer (que aguardar� tr�s quartos de segundo
                // e depois ocultar� os �cones)
                timer1.Start();
            }
        }

        

        /// <summary>
        /// Este timer � iniciado quando o jogador clica 
        /// em dois �cones que n�o combinam,
        /// conta tr�s quartos de segundo 
        /// e depois se desliga e oculta ambos os �cones
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void timer1_Tick(object sender, EventArgs e)
        {
            // Pare o timer
            timer1.Stop();

            // Oculte ambos os �cones
            firstClicked.ForeColor = firstClicked.BackColor;
            secondClicked.ForeColor = secondClicked.BackColor;

            // Redefina firstClicked e secondClicked 
            // para que, na pr�xima vez que um Label for clicado,
            // o programa saiba que � o primeiro clique
            firstClicked = null;
            secondClicked = null;
        }

        /// <summary>
        /// Verifica todos os �cones para ver se est�o combinados, 
        /// comparando sua cor de primeiro plano com sua cor de fundo. 
        /// Se todos os �cones estiverem combinados, o jogador vence
        /// </summary>
        private void CheckForWinner()
        {
            // Percorra todos os Labels no TableLayoutPanel, 
            // verificando cada um para ver se seu �cone est� combinado
            foreach (Control control in tableLayoutPanel1.Controls)
            {
                Label iconLabel = control as Label;

                if (iconLabel != null)
                {
                    if (iconLabel.ForeColor == iconLabel.BackColor)
                        return;
                }
            }

            // Se o loop n�o retornar, significa que
            // n�o encontrou �cones n�o combinados
            // Isso significa que o jogador venceu. Mostre uma mensagem e feche o formul�rio
            MessageBox.Show("Voc� combinou todos os �cones!", "Parab�ns");
            Close();
        }
    }
}
