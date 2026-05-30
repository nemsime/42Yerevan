#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== ClapTrap creation ===" << std::endl;
    ClapTrap clap("Clappy");

    std::cout << "\n=== ScavTrap creation ===" << std::endl;
    ScavTrap scav("Serena");

    std::cout << "\n=== Actions ===" << std::endl;
    clap.attack("target");
    clap.takeDamage(4);
    clap.beRepaired(3);

    std::cout << "\n";
    scav.attack("intruder");
    scav.guardGate();
    scav.takeDamage(20);
    scav.beRepaired(10);

    std::cout << "\n=== Copy and assignment ===" << std::endl;
    ScavTrap scavCopy(scav);
    ScavTrap scavAssign("Temp");
    scavAssign = scav;

    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}
