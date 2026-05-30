#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== ScavTrap creation ===" << std::endl;
    ScavTrap scav("Serena");

    std::cout << "\n=== FragTrap creation (watch construction chaining) ===" << std::endl;
    FragTrap frag("Fraggy");

    std::cout << "\n=== ScavTrap actions ===" << std::endl;
    scav.attack("intruder");
    scav.guardGate();
    scav.takeDamage(20);
    scav.beRepaired(10);

    std::cout << "\n=== FragTrap actions ===" << std::endl;
    frag.attack("enemy");
    frag.highFivesGuys();
    frag.takeDamage(40);
    frag.beRepaired(15);

    std::cout << "\n=== FragTrap copy and assignment ===" << std::endl;
    FragTrap fragCopy(frag);
    FragTrap fragAssign("Temp");
    fragAssign = frag;

    std::cout << "\n=== End of main (watch destruction chaining) ===" << std::endl;
    return 0;
}
