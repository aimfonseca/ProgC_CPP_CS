using System;

namespace SimpleCalc
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Bem-vindo à Calculadora Simples!");

            Console.Write("Digite o primeiro número: ");
            double num1 = Convert.ToDouble(Console.ReadLine());

            Console.Write("Digite o operador (+, -, *, /): ");
            char operador = Console.ReadLine()[0];

            Console.Write("Digite o segundo número: ");
            double num2 = Convert.ToDouble(Console.ReadLine());

            double resultado = 0;
            bool operacaoValida = true;

            switch (operador)
            {
                case '+':
                    resultado = num1 + num2;
                    break;
                case '-':
                    resultado = num1 - num2;
                    break;
                case '*':
                    resultado = num1 * num2;
                    break;
                case '/':
                    if (num2 != 0)
                    {
                        resultado = num1 / num2;
                    }
                    else
                    {
                        Console.WriteLine("Erro: Divisão por zero não é permitida.");
                        operacaoValida = false;
                    }
                    break;
                default:
                    Console.WriteLine("Erro: Operador inválido.");
                    operacaoValida = false;
                    break;
            }

            if (operacaoValida)
            {
                Console.WriteLine($"Resultado: {resultado}");
            }

            Console.WriteLine("Pressione qualquer tecla para sair.");
            Console.ReadKey();
        }
    }
}