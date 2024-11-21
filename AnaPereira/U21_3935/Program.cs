using System;

class Program
{
    static void Main()
    {
        // Obter o número do utilizador
        Console.WriteLine("Digite um número:");
        int numero = int.Parse(Console.ReadLine());

        // Guardar o número numa variável temporária
        int numeroOriginal = numero;
        int invertido = 0;

        // Reverter o número
        while (numero > 0)
        {
            int digito = numero % 10;
            invertido = invertido * 10 + digito;
            numero /= 10;
        }

        // Comparar o número temporário com o número invertido
        if (numeroOriginal == invertido)
        {
            Console.WriteLine($"O número {numeroOriginal} é um palíndromo.");
        }
        else
        {
            Console.WriteLine($"O número {numeroOriginal} não é um palíndromo.");
        }
    }
}