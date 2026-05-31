#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (other.templates[i])
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete templates[i];
            templates[i] = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.templates[i])
                templates[i] = other.templates[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete templates[i];
}

// Takes ownership of the materia passed as a parameter and stores it as a
// template, so the example "learnMateria(new Ice())" does not leak.
void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == 0)
        {
            templates[i] = m;
            return ;
        }
    }
    // Already knows 4 materias: drop the extra one to avoid a leak.
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    return 0; // Unknown type.
}
