#include "Zombie.hpp"
#include <iostream>

int main()
{
    randomChump("StackZombie");

    std::cout << std::endl;

    Zombie* z = newZombie("Robert");
    z->announce();
    delete z;

    return 0;
}