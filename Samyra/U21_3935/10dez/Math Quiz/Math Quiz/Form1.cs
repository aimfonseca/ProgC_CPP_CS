namespace Math_Quiz
{
    public partial class Form1 : Form
    {
        // Crie um objeto Random chamado randomizer
        // para gerar números aleatórios.
        Random randomizer = new Random();

        // Estas variáveis inteiras armazenam os números
        // para o problema de adição.
        int addend1;
        int addend2;

        // Estas variáveis inteiras armazenam os números
        // para o problema de subtração.
        int minuend;
        int subtrahend;

        // Estas variáveis inteiras armazenam os números
        // para o problema de multiplicação.
        int multiplicand;
        int multiplier;

        // Estas variáveis inteiras armazenam os números
        // para o problema de divisão.
        int dividend;
        int divisor;

        // Esta variável inteira rastreia o tempo restante.
        int timeLeft;

        public Form1()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Inicia o quiz preenchendo todos os valores
        /// dos problemas e iniciando o cronômetro.
        /// </summary>
        public void StartTheQuiz()
        {
            // Preenche o problema de adição.
            // Gera dois números aleatórios para somar.
            // Armazena os valores nas variáveis 'addend1' e 'addend2'.
            addend1 = randomizer.Next(51);
            addend2 = randomizer.Next(51);

            // Converte os dois números gerados aleatoriamente
            // em strings para que possam ser exibidos
            // nos controles do tipo Label.
            plusLeftLabel.Text = addend1.ToString();
            plusRightLabel.Text = addend2.ToString();

            // 'sum' é o nome do controle NumericUpDown.
            // Esta etapa garante que seu valor seja zero antes
            // de adicionar quaisquer valores a ele.
            sum.Value = 0;

            // Preenche o problema de subtração.
            minuend = randomizer.Next(1, 101);
            subtrahend = randomizer.Next(1, minuend);
            minusLeftLabel.Text = minuend.ToString();
            minusRightLabel.Text = subtrahend.ToString();
            difference.Value = 0;

            // Preenche o problema de multiplicação.
            multiplicand = randomizer.Next(2, 11);
            multiplier = randomizer.Next(2, 11);
            timesLeftLabel.Text = multiplicand.ToString();
            timesRightLabel.Text = multiplier.ToString();
            product.Value = 0;

            // Preenche o problema de divisão.
            divisor = randomizer.Next(2, 11);
            int temporaryQuotient = randomizer.Next(2, 11);
            dividend = divisor * temporaryQuotient;
            dividedLeftLabel.Text = dividend.ToString();
            dividedRightLabel.Text = divisor.ToString();
            quotient.Value = 0;

            // Inicia o cronômetro.
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
        /// Verifica as respostas para ver se o usuário acertou tudo.
        /// </summary>
        /// <returns>True se a resposta estiver correta, false caso contrário.</returns>
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
                // Se CheckTheAnswer() retornar true, significa que o usuário
                // acertou a resposta. Pare o cronômetro
                // e exiba uma MessageBox.
                timer1.Stop();
                MessageBox.Show("Você acertou todas as respostas!",
                                "Parabéns!");
                startButton.Enabled = true;
            }
            else if (timeLeft > 0)
            {
                // Se CheckTheAnswer() retornar false, continue contando
                // o tempo. Reduza o tempo restante em um segundo e 
                // exiba o novo tempo atualizando o rótulo de tempo restante.
                timeLeft = timeLeft - 1;
                timeLabel.Text = timeLeft + " segundos";
            }
            else
            {
                // Se o tempo acabar, pare o cronômetro, exiba uma
                // MessageBox e preencha as respostas.
                timer1.Stop();
                timeLabel.Text = "O tempo acabou!";
                MessageBox.Show("Você não terminou a tempo.", "Que pena!");
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
