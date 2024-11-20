using System;

class Carimbo{
    public static void ExibirInfo(){
        DateTime dataAtual = DateTime.Now;
        string nome = "André Proença";        
        Console.WriteLine("-----------------------------------");
        Console.WriteLine($"Data e hora atual: {dataAtual}" );
        Console.WriteLine($"Autor: {nome}");
        Console.WriteLine("-----------------------------------");
    }
}