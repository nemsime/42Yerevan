#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
    if(this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Bark" << std::endl;
}