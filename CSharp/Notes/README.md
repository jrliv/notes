# CSharp Notes

## Contents

* [Objects](#objects)
* [Classes](#classes)
* [Namespaces](#namespaces)
* [References and resources](#references-and-resources)

## Objects

### What is an object?

In terms of software, an object is a combination of code and data that can be treated as a unit. An object can be a piece of an application, like a control or a form. An entire application can also be an object. Software objects generally model real world objects or abstract concepts (which are also regarded as objects).

Examples of real-world objects are people, cars, goods, purchases, etc. abstract objects are concepts in an object area, which we have to model and use in a computer program. Examples of abstract objects are the data structures stack, queue, list and tree.

### Object characteristics

Objects usually consist of two main characteristics:

**States** – these are the characteristics of the object which define it in a way and describe it in general or in a specific moment (usually nouns)

**Behavior** – these are the specific distinctive actions, which can be done by the object. (usually verbs)

For example a real-world object such as a person can have descriptive states such as "name", "age", "gender", etc. and their behaviors could consist of "talking", "walking", "sitting", etc.

These can be thought of as data members, embedded in object variables which describe their states, and methods, which build and use objects.

### Creating objects

Objects are created from pre-defined classes using the **new** operator/keyword. They are usually assigned to a variable name of the class type. Here is an example of creating an object called dogObject from the Dog class.

    Dog dogObject = new Dog();

It's important to remember that **dogObject** is an instance of the **Dog** class. **dogObject** is a *reference* variable to the newly created object on the heap. The variable **dogObject** contains or "points to" the address in memory (or on the heap) that holds the object value.

Depending on if you have a **constructor** that takes them, parameters can also be used when creating an object:

    Dog dogObject = new Dog("Scruffy", "brown", "st. bernard");

This would create an object with three data members that could describe the name, color, and breed of the dog object.

The constructor is a special method of the class, which is called automatically when creating an object of this class, and performs initialization of its data (this is its purpose). The constructor has no type of returned value and its name is not random, and mandatorily coincides with the class name. The constructor can be with or without parameters.

Each class can have different count of constructors with one only restriction – the count and type of their parameters have to be different (different signature). When creating an object of this class, one of the constructors is called.

A class that has only **private** constructors cannot be instantiated. Such class usually has only static members and is called "utility class".

### Releasing objects

The .NET framework contains a **garbage collector** that is built into the CLR and cleans any unused objects from memory. This means we don't have to worry about unused objects and clean them ourselves. We can let the garbage collector handle it. However, if we need to manually ensure that an object gets released we can set it's value to **null** to make sure that the garbage collector will release or "clean" it:

    dogObject = null;

### Accessing objects

To access the fields and properties of an object you use the **.** operator. You can access the fields and the properties either to read data from them or assign new data. 

In the case of a property, the access is implemented in exactly the same way as in the case of a field. This is achieved by the keywords **get** and **set** in the definition of the property which "get" and "set" the value of the property.

For example if you defined a new parameterless Dog object like previously, you could assign the value of it's name property by using the syntax:

    dogObject.Name = "Scruffy";

You can also call methods on objects that have been defined in the class it's instantiated from:

    dogObject.Bark();

This would execute the **Bark()** method defined in the **Dog** class on the **dogObject**.

### Static fields and methods

As mentioned, the data members of a class represent the states of the objects. They are directly related to the instances (objects) of the class. **Static members** are fields and methods that are associated with a class but not an instance of a class. They can be used in another class without the need of creating an instance from the class they are implemented in. Obviously you will use the **static** keyword to define something that is static. It's important to remember that static fields are initialized when the data type (the class) is used for the first time, during the execution of the program.

## Classes

A class is a structure used to define the nature of grouped abstract objects. Objects are usually instances of specific classes.

The class represents a pattern, which describes the different states and behavior of the certain objects (the copies), which are created from this class (pattern).

For example you could have a class named **Cat** defined, which describes the characteristics of cats and you could also have an object named **Max** defined, which would be an instance of the class **Cat** and contain the characteristics that the class defines likes it's data members and methods.

### Declaring a class

A class in C# is defined by the keyword **class**, followed by an identifier (name) of the class and a set of data members and methods in a separate code block. Classes in C# can contain fields, properties, and methods. Here is the definition of a class based on syntax rules:

    [<access_modifier>] class <class_name>

### Naming a class

Nouns are usually used to name classes. The names of the classes begin with capital letter, and the rest of the letters are lower case. If the name of the class consists of several words, every word begins with capital letter, without separator to be used. This is the well-known PascalCase convention.

### Elements of a class

#### Declaration

To *declare* a class, you define it's access modifier with the necessary keyword followed by the keyword **public** and the classes name.

    public class Dog

#### Body

The *body* of a class is similar to the body of a condition, loop, or method in which it is in closed between to curly braces and contains the logic it's used for.

#### Constructor

The *constructor* is usually defined within the body of a class. It's used for creating new objects of the class. Constructors use the same name as the class and they're declared with an access modifier.

    public Dog()
    {

    }

A constructor can contain parameters or it can be parameterless like above. The default constructor is paramaterless.

#### Fields

*Fields* are variables that are declared inside of a class.  They represent the data of the object. The values contained in the fields reflect the state of an object from the class. A field is defined with an access modifier keyword followed by it's type and name.

    private string name;
    private int age;
    private int dob;

The scope of a class field starts from the line where is declared and ends at the closing bracket of the body of the class. Fields can also be defined as **static**, which means it can be shared among all objects.

Unlike local variables, object fields can be declared without being initialized because they have default values. When an object is created, all of the fields are initialized with their respective default values in .NET, unless they are initialized with some other value. The default values are usually 0, false, or null depending on the type of the field.

Fields declared as **const** or **readonly** are called constants. They are used when a certain value is used several times. 

The fields declared with **const** must be initialized during declaration. Afterwards their value cannot be changed. They can be accessed without having to create an instance (an object) of the class. They are common for all created objects in our program. When the code is compiled, the places where const fields are referred to are replaced with their actual values directly without the use of the constant variable at all. For this reason the const fields are called *compile-time constants* because they are replaced with the value during the compilation process.

The **readonly** modifier also creates fields with values that cannot be changed once they are assigned. Fields declared as readonly allow one-time initialization, either in the moment of the declaration or in the class constructors. Afterwords the values cannot be changed. For this reason, the readonly fields are called *run-time constants* because their values cannot be
changed after assignment and run-time, and because the process happens during the execution of the program (in runtime).

C# allows the  defining of local variables that have names that match with the field names of the class. When this occurs we say that the scope of the local variable overlays the field variable. This is known as *scope overlapping*.

For example if you have a class with an integer field named **myValue** that is equal to 5 and a method within the class that contains an local integer variable named **myValue** that is equal to 10, the local variable inside of the method will be used instead of the field if the method is called. 

Here is the example using code:

    public class ScopeOverlapping
    {
        int myValue = 5;

        void PrintMyValue()
        {
            int myValue = 10;
            Console.WriteLine("My value is: " + myValue);
        }

        static void Main()
        {
            ScopeOverlapping scopeInstance = new ScopeOverlapping();
            scopeInstance.PrintMyValue();
        }
    }

After executing this code the result will be:

    My value is: 10

If you wanted to use and print the value of the field instead, you could use the **this** keyword like:

    void PrintMyValue()
    {
        int myValue = 10;
        Console.WriteLine("My value is: " + this.myValue);
    }

The value of the result would then be 5.

#### Properties

*Properties* are used as a way to describe the characteristics of a class. They may be held by certain objects or they can be shared to all objects.

    private string Name
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

The keyword **this** is used in C# to reference the *current object* being used in the same class. This access option is only possible from non-static code (i.e. the method or block doesn't contain the **static** modifier).

Just to note, when it's not explicitly required, the reserved keyword **this** can be skipped when we access the elements of the same class. However, for better code readability, it's recommended to use the **this** keyword even when not required.

#### Methods 

The last and sometimes most important element of a class are *methods*.

    public void Bark()
    {
        Console.WriteLine("{0} said: Wow-wow!",
        name ?? "[unnamed dog]");
    }

### Access levels and modifiers

An *access modifier* is a reserved keyword in C# that is used to control the access to elements of the class and the class itself. In C# there are four access modifiers; **public**, **private**, **protected**, and **internal**.

The **public** modifier is the <u>least</u> restricted access level in C#. It let's the compiler and the programmer know that the element it's used on is public and can be accessed from every class and namespace. Every other class can create objects from this type and has access to the methods and the fields of the public class.

The **private** modifier is the <u>most</u> restricted access level in C#. It's used to indicate that the element that it's used on cannot be accessed from any other class (except the class in which it is defined) even if this class exists in the same namespace. Private classes like other private members are accessible only inside the class which defined them.

The **protected** modifier  can be accessed only by code in the same class or struct, or in a class that is derived from that class.

The **internal** modifier is used to limit the access to the elements of the class only to files from the same assembly, i.e. within the same project in Visual Studio. If you declare one class with access modifier internal it will be accessible only from the same namespace. As mentioned, it means that only the classes from the same assembly can create objects from this type class and to have access to the methods and fields. **Internal** is the default access modifier if no modifier is specified when a class is defined.

It's important to remember that the default access for everything in C# is "the most restricted access you could declare for that member". So while outer classes can be defaulted to internal access, inner classes and elements inside of the outer class will default to private. https://stackoverflow.com/questions/2521459/what-are-the-default-access-modifiers-in-c

If two classes are not visible one to other, then their members (fields and methods) are not visible also, regardless of what kind of access levels their elements have.

### Utility classes

A class that has only private constructors cannot be instantiated. Such class usually has only static members and is called "utility class". Many of the System classes in C# are examples of utility classes that don't need to be instantiated. **System.Environment**, **System.Console**, **System.String**, **System.Math**, and **System.Random** are a few of the most commonly used System classes in C#.

## Namespaces

A namespace is a named container or package for groups of classes which are usually grouped by a particular feature or characteristic. They help keep classes and source code more logical and organized. 

### Define a namespace

Declaring your own namespaces can help you control the scope of class and method names in larger programming projects. You can declare a namespace by using the **namespace** keyword in C#.

    namespace SampleNamespace
    {
        class SampleClass { }

        interface SampleInterface { }

        struct SampleStruct { }

        enum SampleEnum { a, b }
    }

### Nested namespaces

Namespaces can contain other namespaces within themselves. This allows you to create a sort of hierarchy of namespaces and classes that are more easily distributed based on what their purposes. For example, the namespace **System** contains a nested namespace **Collections** so the full name of the namespace would obviously be **System.Collections**.

It's important to remember that classes are required to have unique names only within the namespaces, in which they are defined. This is because classes in the namespace are uniquely defined in its context. In .NET Framework sometimes there are classes from different namespaces with matching names, for example:

    System.Windows.Forms.Control
    System.Web.UI.Control
    System.Windows.Controls.Control

### Include a namespace

It's often necessary to use the classes of a namespace multiple times. For convenience can include a namespace in the program so all classes defined in it can be used without the need to use their full names. To include a namespace you use the **using** keyword in C#.

    using System.Windows.Forms

It's important to remember that when including a namespace, the classes from the nested namespaces are not included. For example, the inclusion of namespaces **System.Collections** doesn't include the classes from its nested namespace **System.Collections.Generic**. When used you have to apply their full names or to include the higher level namespace that contains them.

## References and resources

* [Fundamentals of Computer Programming with C#](https://tinyurl.com/csharpprogramming)
* [C# Reference](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/)
* [C# Guide](https://docs.microsoft.com/en-us/dotnet/csharp/)
* [C# Tutorial](https://www.tutorialspoint.com/csharp/)

---------------------------------------------------------------------------
[Back to top](#csharp-notes)

