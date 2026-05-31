#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int main()
{
    // Animal is now abstract (pure virtual makeSound), so the next line
    // would NOT compile: "cannot declare variable to be of abstract type".
    // const Animal* meta = new Animal();

    std::cout << "===== Basic test (no leaks) =====" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    j->makeSound();
    i->makeSound();
    delete j; // should not create a leak
    delete i;

    std::cout << "\n===== Array of Animals (half Dog, half Cat) =====" << std::endl;
    const int size = 6;
    Animal* animals[size];

    for (int k = 0; k < size; k++)
    {
        if (k < size / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    for (int k = 0; k < size; k++)
        animals[k]->makeSound();

    for (int k = 0; k < size; k++)
        delete animals[k];

    std::cout << "\n===== Deep copy test =====" << std::endl;
    {
        Dog original;
        Dog copyCtor(original);     // deep copy via copy constructor

        Cat catA;
        Cat catB;
        catB = catA;                // deep copy via copy assignment
    }

    return 0;
}
