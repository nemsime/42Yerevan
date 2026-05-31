#include "Character.hpp"

Character::Character() : name("")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(const Character& other) : ICharacter(), name(other.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;
        // During copy, the existing Materias must be deleted before the
        // new ones are added.
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            inventory[i] = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return ;
    // Avoid equipping the same materia twice (would lead to a double free).
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == m)
            return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == 0)
        {
            inventory[i] = m;
            return ;
        }
    }
    // Inventory is full: nothing happens.
}

// The materia is removed from the inventory but NOT deleted: the caller
// keeps ownership of the address it saved before calling unequip().
void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return ;
    inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return ;
    if (inventory[idx])
        inventory[idx]->use(target);
}
