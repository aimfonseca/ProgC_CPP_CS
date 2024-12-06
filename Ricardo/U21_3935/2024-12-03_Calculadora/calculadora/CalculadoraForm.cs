using static System.Runtime.InteropServices.JavaScript.JSType;

namespace calculadora
{
    public partial class CalculadoraForm : Form
    {
        double resultValue = 0;
        string operatorPerformed = "";
        bool isOperatorPerformed = false;

        public CalculadoraForm()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, EventArgs e)
        {
            if ((textBox_Result.Text == "0") || (isOperatorPerformed))
                textBox_Result.Clear();

            isOperatorPerformed = false;
            Button button = (Button)sender;
            textBox_Result.Text += button.Text;
        }

        private void operator_Click(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            operatorPerformed = button.Text;
            resultValue = double.Parse(textBox_Result.Text);
            isOperatorPerformed = true;
        }

        private void buttonEqual_Click(object sender, EventArgs e)
        {
            switch (operatorPerformed)
            {
                case "+":
                    textBox_Result.Text = (resultValue + double.Parse(textBox_Result.Text)).ToString();
                    break;
                case "-":
                    textBox_Result.Text = (resultValue - double.Parse(textBox_Result.Text)).ToString();
                    break;
                case "×":
                    textBox_Result.Text = (resultValue * double.Parse(textBox_Result.Text)).ToString();
                    break;
                case "÷":
                    if (double.Parse(textBox_Result.Text) != 0)
                    {
                        textBox_Result.Text = (resultValue / double.Parse(textBox_Result.Text)).ToString();
                    }
                    else
                    {
                        MessageBox.Show("Cannot divide by zero");
                    }
                    break;
                default:
                    break;
            }
            resultValue = double.Parse(textBox_Result.Text);
            operatorPerformed = "";
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            textBox_Result.Text = "0";
            resultValue = 0;
            operatorPerformed = "";
        }

        private void buttonDecimal_Click(object sender, EventArgs e)
        {
            if (!textBox_Result.Text.Contains("."))
            {
                textBox_Result.Text += ".";
            }
        }
    }
}
