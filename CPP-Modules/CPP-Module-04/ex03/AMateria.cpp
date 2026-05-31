#include "AMateria.hpp"

AMateria::AMateria() : type("")
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
}

// While assigning a Materia to another, copying the type doesn't make sense,
// so the type is intentionally left untouched here.
AMateria& AMateria::operator=(const AMateria& other)
{
    (void)other;
    return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return type;
}

// Default implementation: concrete materias override this.
void AMateria::use(ICharacter& target)
{
    (void)target;
}
