#include "Form.hpp"

const std::string& Form::getName() const
{
    return _name;
}

int Form::get_Sgrade() const
{
    return s_grade;
}

int Form::get_Egrade() const
{
    return e_grade;
}

bool Form::getIsSigned() const
{
    return is_signed;
}

Form::Form(): _name("FORTYTWO_FORM"), s_grade(42), e_grade(21), is_signed(false){}

Form::Form(const Form &other) : _name(other._name),s_grade(other.s_grade),e_grade(other.e_grade),is_signed(other.is_signed){}

Form& Form::operator=(const Form& other)
{
    if(this != &other)
        is_signed = other.is_signed;
    return *this;
}

Form::~Form(){}

Form::Form(const std::string& name, int s_grade, int e_grade) : _name(name),s_grade(s_grade),e_grade(e_grade),is_signed(false)
{
    if (s_grade < 1 || e_grade < 1)
        throw GradeTooHighException();
    else if (s_grade > 150 || e_grade > 150)
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << form.getName() << ", form sign grade is " << form.get_Sgrade() << ", execute grade is " << form.get_Egrade() << " is it signed?: " << form.getIsSigned(); 
    return out;
}