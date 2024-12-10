namespace Math_Quiz
{
    public partial class Form1 : Form
    {
        // Crie um objeto Random chamado randomizer
        // para gerar n�meros aleat�rios.
        Random randomizer = new Random();

        // Estas vari�veis inteiras armazenam os n�meros
        // para o problema de adi��o.
        int addend1;
        int addend2;

        // Estas vari�veis inteiras armazenam os n�meros
        // para o problema de subtra��o.
        int minuend;
        int subtrahend;

        // Estas vari�veis inteiras armazenam os n�meros
        // para o problema de multiplica��o.
        int multiplicand;
        int multiplier;

        // Estas vari�veis inteiras armazenam os n�meros
        // para o problema de divis�o.
        int dividend;
        int divisor;

        // Esta vari�vel inteira rastreia o tempo restante.
        int timeLeft;

        public Form1()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Inicia o quiz preenchendo todos os valores
        /// dos problemas e iniciando o cron�metro.
        /// </summary>
        public void StartTheQuiz()
        {
            // Preenche o problema de adi��o.
            // Gera dois n�meros aleat�rios para somar.
            // Armazena os valores nas vari�veis 'addend1' e 'addend2'.
            addend1 = randomizer.Next(51);
            addend2 = randomizer.Next(51);

            // Converte os dois n�meros gerados aleatoriamente
            // em strings para que possam ser exibidos
            // nos controles do tipo Label.
            plusLeftLabel.Text = addend1.ToString();
            plusRightLabel.Text = addend2.ToString();

            // 'sum' � o nome do controle NumericUpDown.
            // Esta etapa garante que seu valor seja zero antes
            // de adicionar quaisquer valores a ele.
            sum.Value = 0;

            // Preenche o problema de subtra��o.
            minuend = randomizer.Next(1, 101);
            subtrahend = randomizer.Next(1, minuend);
            minusLeftLabel.Text = minuend.ToString();
            minusRightLabel.Text = subtrahend.ToString();
            difference.Value = 0;

            // Preenche o problema de multiplica��o.
            multiplicand = randomizer.Next(2, 11);
            multiplier = randomizer.Next(2, 11);
            timesLeftLabel.Text = multiplicand.ToString();
            timesRightLabel.Text = multiplier.ToString();
            product.Value = 0;

            // Preenche o problema de divis�o.
            divisor = randomizer.Next(2, 11);
            int temporaryQuotient = randomizer.Next(2, 11);
            dividend = divisor * temporaryQuotient;
            dividedLeftLabel.Text = dividend.ToString();
            dividedRightLabel.Text = divisor.ToString();
            quotient.Value = 0;

            // Inicia o cron�metro.
            timeLeft = 30;
            timeLabel.Text = "30 segundos";
            timer1.Start();
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            StartTheQuiz();
            startButton.Enabled = false;
        }

        /// <summary>
        /// Verifica as respostas para ver se o usu�rio acertou tudo.
        /// </summary>
        /// <returns>True se a resposta estiver correta, false caso contr�rio.</returns>
        private bool CheckTheAnswer()
        {
            if ((addend1 + addend2 == sum.Value)
                && (minuend - subtrahend == difference.Value)
                && (multiplicand * multiplier == product.Value)
                && (dividend / divisor == quotient.Value))
                return true;
            else
                return false;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (CheckTheAnswer())
            {
                // Se CheckTheAnswer() retornar true, significa que o usu�rio
                // acertou a resposta. Pare o cron�metro
                // e exiba uma MessageBox.
                timer1.Stop();
                MessageBox.Show("Voc� acertou todas as respostas!",
                                "Parab�ns!");
                startButton.Enabled = true;
            }
            else if (timeLeft > 0)
            {
                // Se CheckTheAnswer() retornar false, continue contando
                // o tempo. Reduza o tempo restante em um segundo e 
                // exiba o novo tempo atualizando o r�tulo de tempo restante.
                timeLeft = timeLeft - 1;
                timeLabel.Text = timeLeft + " segundos";
            }
            else
            {
                // Se o tempo acabar, pare o cron�metro, exiba uma
                // MessageBox e preencha as respostas.
                timer1.Stop();
                timeLabel.Text = "O tempo acabou!";
                MessageBox.Show("Voc� n�o terminou a tempo.", "Que pena!");
                sum.Value = addend1 + addend2;
                difference.Value = minuend - subtrahend;
                product.Value = multiplicand * multiplier;
                quotient.Value = dividend / divisor;
                startButton.Enabled = true;
            }
        }

        private void answer_Enter(object sender, EventArgs e)
        {
            // Seleciona toda a resposta no controle NumericUpDown.
            NumericUpDown answerBox = sender as NumericUpDown;

            if (answerBox != null)
            {
                int lengthOfAnswer = answerBox.Value.ToString().Length;
                answerBox.Select(0, lengthOfAnswer);
            }
        }
    }
}
