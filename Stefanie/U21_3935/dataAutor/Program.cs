using System;

class Programa
{
    private static int Main()
    {
        DateTime agora = DateTime.Now;
        Console.WriteLine($"Data e hora atual: {agora}");
        Console.WriteLine("Stéfanie Abreu");
        
        
        int num1, num2;
        Console.Write("Escreve o primeiro número: ");
        num1 = int.Parse(Console.ReadLine()); // Converte  para inteiro
        Console.Write("Escreve o segundo número: ");
        num2 = int.Parse(Console.ReadLine()); 

        // fazer a soma
        Console.WriteLine("Soma = " + (num1 + num2));
        

        // fazer divisão
        Console.WriteLine("Divisão = " + (num1 / num2));

        return 0;
    }
}