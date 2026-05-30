#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap("Claptrap");
    
    clap.attack("Bandit");
    clap.takeDamage(3);
    clap.beRepaired(5);
    clap.attack("Enemy");
    
    return 0;
}
