#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int main()
{
    std::cout << "===== Basic test (no leaks) =====" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
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

    // delete directly dogs and cats AS Animals: the virtual destructor
    // makes the right derived destructor run, so each Brain is freed.
    for (int k = 0; k < size; k++)
        delete animals[k];

    std::cout << "\n===== Deep copy test =====" << std::endl;
    // The "Brain copy constructor called" line proves a brand new Brain is
    // allocated for the copy, instead of sharing the same Brain pointer.
    {
        Dog original;
        Dog copyCtor(original);     // deep copy via copy constructor

        Cat catA;
        Cat catB;
        catB = catA;                // deep copy via copy assignment
    }

    return 0;
}
