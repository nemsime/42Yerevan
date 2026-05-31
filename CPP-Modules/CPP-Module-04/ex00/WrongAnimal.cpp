#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
    type = other.type;
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if(this != &other)
    {
        this->type = other.type;
    }
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal makes sound" << std::endl;
}

std::string WrongAnimal::getType() const{
    return type;
}
