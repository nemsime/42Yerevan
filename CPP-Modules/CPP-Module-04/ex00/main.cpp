#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
    std::cout << "===== Correct polymorphism (Animal) =====" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n===== Wrong polymorphism (WrongAnimal) =====" << std::endl;
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wcat = new WrongCat();

    std::cout << wcat->getType() << " " << std::endl;
    // makeSound() is NOT virtual in WrongAnimal:
    // calling it through a WrongAnimal* runs WrongAnimal::makeSound()
    wcat->makeSound(); // outputs the WrongAnimal sound, NOT the WrongCat one!
    wmeta->makeSound();

    delete wmeta;
    delete wcat;

    std::cout << "\n===== Concrete WrongCat (static type) =====" << std::endl;
    WrongCat realCat;
    realCat.makeSound(); // here the WrongCat sound shows: static type is WrongCat

    return 0;
}
