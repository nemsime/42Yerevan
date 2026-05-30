#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    std::cout << "A new zombie has been created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::setName(const std::string& name)
{
    std::cout << "A new zombie named " << name << " has been created." << std::endl;
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}