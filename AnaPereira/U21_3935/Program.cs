using System;

class Program
{
    static void Main()
    {
        // Insira um número
        Console.WriteLine("Digite um número:");
        int numero = int.Parse(Console.ReadLine());

        // Inicializar a soma dos dígitos
        int soma = 0;
        
        // Algoritmo para somar os dígitos
        while (numero > 0)
        {
            int digito = numero % 10; // Obter o dígito da extremidade direita
            soma += digito;            // Adicionar o dígito à soma
            numero /= 10;              // Remover o dígito da extremidade direita
        }

        // Exibir o resultado
        Console.WriteLine("A soma dos dígitos é: " + soma);
    }
}