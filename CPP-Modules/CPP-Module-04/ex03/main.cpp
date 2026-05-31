#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#include <iostream>

int main()
{
    // ---- Subject example (output must match exactly) ----
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    // ---- Extra tests ----
    std::cout << "\n----- extra tests -----" << std::endl;

    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());

    // Unknown type returns 0.
    AMateria* unknown = src2->createMateria("fire");
    std::cout << "createMateria(\"fire\") -> " << (unknown ? "not null" : "0 (unknown)") << std::endl;

    Character hero("hero");

    // Fill all 4 slots, then try a 5th: it should be ignored.
    hero.equip(src2->createMateria("ice"));
    hero.equip(src2->createMateria("ice"));
    hero.equip(src2->createMateria("cure"));
    hero.equip(src2->createMateria("cure"));

    AMateria* extra = src2->createMateria("ice"); // inventory full
    hero.equip(extra);                            // nothing happens

    Character villain("villain");
    for (int i = 0; i < 4; i++)
        hero.use(i, villain);

    // The 5th materia was never stored: delete it ourselves (no leak).
    delete extra;

    // use/unequip on invalid slots: nothing happens, no crash.
    hero.use(10, villain);
    hero.unequip(-1);
    hero.unequip(99);

    // unequip does NOT delete: save the address first to free it ourselves.
    AMateria* dropped = src2->createMateria("ice");
    hero.equip(dropped);   // goes into a now-free slot? inventory still full -> ignored
    // (inventory is full, so 'dropped' was not stored: free it.)
    delete dropped;

    // ---- Deep copy of a Character ----
    std::cout << "\n----- deep copy -----" << std::endl;
    Character original("original");
    original.equip(src2->createMateria("ice"));
    original.equip(src2->createMateria("cure"));

    Character copy(original); // deep copy: clones the materias
    copy.use(0, villain);
    copy.use(1, villain);

    Character assigned("assigned");
    assigned = original;      // deep copy via assignment
    assigned.use(0, villain);

    delete src2;

    return 0;
}
