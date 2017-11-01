class Program
{
  static void Main(string[] args)
  {
    Drummer first = new Drummer();
    first.name = "John Bonham";
    first.band = "Led Zeppelin";

    Drummer second = new Drummer("Mitch Mitchell", "Jimi Hendrix Experience");
    Drummer third = new Drummer("Keith Moon", "The Who");
    Drummer fourth = new Drummer("Jimmy Chamberlin", "The Smashing Pumpkins");
    Drummer fifth = new Drummer("Dave Grohl", "Nirvana");

    Console.WriteLine("-----------------------");
    Console.WriteLine("Top 5 Favorite Drummers");
    Console.WriteLine("-----------------------");
    Console.WriteLine("1.) Name: " + first.name + " | Band: " + first.band);
    Console.WriteLine("2.) Name: " + second.name + " | Band: " + second.band);
    Console.WriteLine("3.) Name: " + third.name + " | Band: " + third.band);
    Console.WriteLine("4.) Name: " + fourth.name + " | Band: " + fourth.band);
    Console.WriteLine("5.) Name: " + fifth.name + " | Band: " + fifth.band);
  }
}

public class Drummer
{
  public string name;
  public string band;
  
  public string Name
  {
    get
    {
      return this.name;
    }
    set
    {
      this.name = value;
    }
  }

  public string Band
  {
    get
    {
      return this.band;
    }
    set
    {
      this.band = value;
    }
  }

  public Drummer()
  {
    this.name = "";
    this.band = "";
  }

  public Drummer(string name, string band)
  {
    this.name = name;
    this.band = band;
  }
}

//  -----------------------
//  Top 5 Favorite Drummers
//  -----------------------
//  1.) Name: John Bonham | Band: Led Zeppelin
//  2.) Name: Mitch Mitchell | Band: Jimi Hendrix Experience
//  3.) Name: Keith Moon | Band: The Who
//  4.) Name: Jimmy Chamberlin | Band: The Smashing Pumpkins
//  5.) Name: Dave Grohl | Band: Nirvana
