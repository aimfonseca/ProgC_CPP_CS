using static System.Windows.Forms.VisualStyles.VisualStyleElement.Header;

namespace Quizz
{
    public partial class Form1 : Form
    {
        // Objeto para gerar números aleatórios
        Random rand = new Random();

        // Variáveis para guardar os números gerados pelo objeto "rand"
        int adendo1;
        int adendo2;

        int minuendo;
        int subtrator;

        int multiplicando;
        int multiplicador;

        int dividendo;
        int divisor;

        int tempo;

        private void StartQuizz()
        {
            adendo1 = rand.Next(51);
            adendo2 = rand.Next(51);
            plusLeftLabel.Text = adendo1.ToString();
            plusRightLabel.Text = adendo2.ToString();
            soma.Value = 0;

            minuendo = rand.Next(1, 101);
            subtrator = rand.Next(1, minuendo);
            minusLeftLabel.Text = minuendo.ToString();
            minusRightLabel.Text = subtrator.ToString();
            diferenca.Value = 0;

            multiplicando = rand.Next(2, 11);
            multiplicador = rand.Next(2, 11);
            timesLeftLabel.Text = multiplicando.ToString();
            timesRightLabel.Text = multiplicador.ToString();
            produto.Value = 0;

            dividendo = rand.Next(2, 11);
            int temp = rand.Next(2, 11);
            divisor = dividendo * temp;
            dividedLeftLabel.Text = dividendo.ToString();
            dividedRightLabel.Text = divisor.ToString();
            quociente.Value = 0;

            tempo = 30;
            time_label.Text = tempo.ToString() + " segundos";
            timer1.Start();

        }

        private void startBtn_Click(object sender, EventArgs e)
        {
            StartQuizz();
            StartBtn.Enabled = false;
        }

        private bool verificacao()
        {
            if ((adendo1 + adendo2 == soma.Value)
                && (minuendo - subtrator == diferenca.Value)
                && (multiplicando * multiplicador == produto.Value)
                && (dividendo / divisor == quociente.Value))
                return true;
            else
                return false;
        }
        public Form1()
        {
            InitializeComponent();

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (verificacao())
            {
                // If CheckTheAnswer() returns true, then the user 
                // got the answer right. Stop the timer  
                // and show a MessageBox.
                timer1.Stop();
                MessageBox.Show("Acertaste!", "Parabéns!");
                StartBtn.Enabled = true;
            }
            else if (tempo > 0)
            {
                // If CheckTheAnswer() returns false, keep counting
                // down. Decrease the time left by one second and 
                // display the new time left by updating the 
                // Time Left label.
                tempo = tempo - 1;
                time_label.Text = tempo + " segundos";
            }
            else
            {
                // If the user ran out of time, stop the timer, show
                // a MessageBox, and fill in the answers.
                timer1.Stop();
                time_label.Text = "Acabou o tempo!";
                MessageBox.Show("Tenta para a próxima :)", "Não terminaste a tempo.");
                soma.Value = adendo1 + adendo2;
                diferenca.Value = minuendo - subtrator;
                produto.Value = multiplicando * multiplicador;
                quociente.Value = dividendo / divisor;
                StartBtn.Enabled = true;
            }

        }
    }
}
