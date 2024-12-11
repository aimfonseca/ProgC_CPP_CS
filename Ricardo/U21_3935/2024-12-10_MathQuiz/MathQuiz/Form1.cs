using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media; // SOUNDSS!!!
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MathQuiz
{
    public partial class Form1 : Form
    {
        // Create a Random object called randomizer 
        // to generate random numbers.
        Random randomizer = new Random();

        // These integer variables store the numbers 
        // for the addition problem. 
        int addend1;
        int addend2;

        // These integer variables store the numbers 
        // for the subtraction problem. 
        int minuend;
        int subtrahend;

        // These integer variables store the numbers 
        // for the multiplication problem. 
        int multiplicand;
        int multiplier;

        // These integer variables store the numbers 
        // for the division problem. 
        int dividend;
        int divisor;

        // This integer variable keeps track of the 
        // remaining time.
        int timeLeft;

        private SoundPlayer correctSound = new SoundPlayer(@"C:\Csharp\MathQuiz\Sounds\correct.wav");
        private SoundPlayer wrongSound = new SoundPlayer(@"C:\Csharp\MathQuiz\Sounds\wrong.wav");
        private SoundPlayer redAlertSound = new SoundPlayer(@"C:\Csharp\MathQuiz\Sounds\nuke_redAlert.wav"); 
        private bool isBlinking = false;

        private bool isMuted = false; // Variável para controlar o som

        public Form1()
        {
        InitializeComponent();
        }

        /// <summary>
        /// Start the quiz by filling in all of the problems
        /// and starting the timer.
        /// </summary>
        public void StartTheQuiz()
        {
            // Fill in the addition problem.
            // Generate two random numbers to add.
            // Store the values in the variables 'addend1' and 'addend2'.
            addend1 = randomizer.Next(51);
            addend2 = randomizer.Next(51);

            // Convert the two randomly generated numbers
            // into strings so that they can be displayed
            // in the label controls.
            plusLeftLabel.Text = addend1.ToString();
            plusRightLabel.Text = addend2.ToString();

            // 'sum' is the name of the NumericUpDown control.
            // This step makes sure its value is zero before
            // adding any values to it.
            sum.Value = 0;

            // Fill in the subtraction problem.
            minuend = randomizer.Next(1, 101);
            subtrahend = randomizer.Next(1, minuend);
            minusLeftLabel.Text = minuend.ToString();
            minusRightLabel.Text = subtrahend.ToString();
            difference.Value = 0;

            // Fill in the multiplication problem.
            multiplicand = randomizer.Next(2, 11);
            multiplier = randomizer.Next(2, 11);
            timesLeftLabel.Text = multiplicand.ToString();
            timesRightLabel.Text = multiplier.ToString();
            product.Value = 0;

            // Fill in the division problem.
            divisor = randomizer.Next(2, 11);
            int temporaryQuotient = randomizer.Next(2, 11);
            dividend = divisor * temporaryQuotient;
            dividedLeftLabel.Text = dividend.ToString();
            dividedRightLabel.Text = divisor.ToString();
            quotient.Value = 0;

            // Start the timer.
            timeLeft = 30;
            timeLabel.Text = "30 segundos";
            timer1.Start();

            // Fazer um reset ao estado inicial da cor da Label
            timeLabel.BackColor = DefaultBackColor;
        }

        /// <summary>
        /// Check the answers to see if the user got everything right.
        /// </summary>
        /// <returns>True if the answer's correct, false otherwise.</returns>
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

        private void startButton_Click(object sender, EventArgs e)
        {
            StartTheQuiz();
            startButton.Enabled = false;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (CheckTheAnswer())
            {
                timer1.Stop();
                MessageBox.Show("Todas as tuas respostas estão corretas!\nParabéns!");
                startButton.Enabled = true;
                timeLabel.BackColor = DefaultBackColor; // Fazer um reset à cor do fundo
            }
            else if (timeLeft > 0)
            {
                timeLeft = timeLeft - 1;
                timeLabel.Text = timeLeft + " segundos";

                // Tocar alarme nos últimos 5 segundos se não estiver "Mute"
                if (timeLeft == 5 && !isMuted)
                {
                    redAlertSound.Stop();
                    redAlertSound.Play();
                }

                // Piscar a vermelho nos últimos 5 segundos
                if (timeLeft <= 5)
                {
                    isBlinking = !isBlinking;
                    timeLabel.BackColor = isBlinking ? Color.Red : DefaultBackColor;
                }
            }
            else
            {
                timer1.Stop();
                timeLabel.Text = "Acabou o tempo!";
                MessageBox.Show("Não acabaste atempadamente.\nDesculpa... esta redundância!");
                sum.Value = addend1 + addend2;
                difference.Value = minuend - subtrahend;
                product.Value = multiplicand * multiplier;
                quotient.Value = dividend / divisor;
                startButton.Enabled = true;
                timeLabel.BackColor = DefaultBackColor; // Resetar cor do fundo
            }
        }

        // Método para verificar respostas e tocar SONS!!!
        private void NumericUpDown_Validated(object sender, EventArgs e)
        {
            NumericUpDown numericUpDown = sender as NumericUpDown;

            if (numericUpDown != null && numericUpDown.Value != 0)
            {
                if ((numericUpDown == sum && addend1 + addend2 == numericUpDown.Value) ||
                    (numericUpDown == difference && minuend - subtrahend == numericUpDown.Value) ||
                    (numericUpDown == product && multiplicand * multiplier == numericUpDown.Value) ||
                    (numericUpDown == quotient && dividend / divisor == numericUpDown.Value))
                {
                    if (!isMuted)
                    {
                        correctSound.Stop();
                        correctSound.Play(); // Som correto
                    }
                }
                else
                {
                    if (!isMuted)
                    {
                        wrongSound.Stop();
                        wrongSound.Play(); // Som de erro
                    }
                }
            }
        }


        private void answer_Enter(object sender, EventArgs e)
        {
            // Select the whole answer in the NumericUpDown control.
            NumericUpDown answerBox = sender as NumericUpDown;

            if (answerBox != null)
            {
                int lengthOfAnswer = answerBox.Value.ToString().Length;
                answerBox.Select(0, lengthOfAnswer);
            }
        }

        private void muteButton_Click(object sender, EventArgs e)
        {
            isMuted = !isMuted; // Alterna entre som ativado e desativado

            // Caminhos relativos para as imagens na pasta "Images"
            string soundOnPath = @"Images\soundOn.png";
            string soundOffPath = @"Images\soundOff.png";

            // Atualiza a imagem do botão
            muteButton.BackgroundImage = isMuted
                ? Image.FromFile(soundOffPath) // Ícone "Sem Som"
                : Image.FromFile(soundOnPath); // Ícone "Com Som"
            muteButton.BackgroundImageLayout = ImageLayout.Stretch; // Ajusta a imagem ao botão
        }
    }
}
