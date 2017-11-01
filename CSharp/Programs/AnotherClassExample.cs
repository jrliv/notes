// Example program of how to use classes, objects, and methods.
using System;

class Program
{
    static void Main()
    {
        Dog firstDog = new Dog();
        firstDog.Name = "Cole";
        firstDog.Bark();

        Dog secondDog = new Dog("Trixie", "brown", "cocker spaniel");
        Console.WriteLine("Dog {0} is a {1} {2}.", secondDog.Name, secondDog.Color, secondDog.Breed);
        secondDog.Bark();
    }
}

public class Dog
{
    // Fields
    private string name;
    private string color;
    private string breed;

    public string Name
    {
        // Get and set name property
        get
        {
            return this.name;
        }
        
        set
        {
            this.name = value;
        }
    }

    public string Color
    {
        // Get and set color property
        get
        {
            return this.color;
        }
        
        set
        {
            this.color = value;
        }
    }

    public string Breed
    {
        // Get and set breed property
        get
        {
            return this.breed;
        }
        
        set
        {
            this.breed = value;
        }
    }

    // Default constructor
    public Dog()
    {
        this.name = "Unnamed";
        this.color = "black";
        this.breed = "lab";
    }

    // Constructor with parameters
    public Dog(string name, string color, string breed)
    {
        this.name = name;
        this.color = color;
        this.breed = breed;
    }

    public void Bark()
    {
        Console.WriteLine("Dog {0} said: Woof woof!", name);
    }
}