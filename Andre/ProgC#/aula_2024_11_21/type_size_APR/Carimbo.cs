using System;

public class Carimbo
{
    public static void ExibirInformacoes()
    {
        // Exibe a data atual
        DateTime date = DateTime.Now;
        Console.WriteLine($"Data atual: {date}");

        // Exibe o nome do autor
        Console.WriteLine("--------------------------------");
        string nome = "André Proença";
        Console.WriteLine($"Autor: {nome}");
        Console.WriteLine("--------------------------------");
    }
}
