#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        Form(const std::string& _name,int s_grade,int e_grade);
        
        const std::string &getName() const;
        int get_Sgrade() const;
        int get_Egrade() const;
        bool getIsSigned() const;

        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };

    private:
        const std::string _name;
        bool is_signed;
        const int s_grade;
        const int e_grade;
};

std::ostream &operator<<(std::ostream &out,
                         const Form &form);

#endif