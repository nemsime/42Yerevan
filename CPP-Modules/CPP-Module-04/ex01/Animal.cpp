#include "Animal.hpp"
#include <iostream>

Animal::Animal(){
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other){
    type = other.type;
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
    if(this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Animal Copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const{
    std::cout << "Animal makes sound" << std::endl;
}

std::string Animal::getType() const{
    return type;
}