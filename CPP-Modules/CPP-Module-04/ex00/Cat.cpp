#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
    if(this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}