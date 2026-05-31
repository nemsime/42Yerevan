#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
    if(this != &other)
    {
        Animal::operator=(other);

        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat(){
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}