#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n========== DEFAULT CONSTRUCTOR ==========\n";

    Bureaucrat def;
    std::cout << def << std::endl;

    std::cout << "\n========== COPY CONSTRUCTOR ==========\n";

    Bureaucrat copy(def);
    std::cout << copy << std::endl;

    std::cout << "\n========== COPY ASSIGNMENT OPERATOR ==========\n";

    Bureaucrat copy_ass;
    copy_ass = copy;
    std::cout << copy_ass << std::endl;

    std::cout << "\n========== VALID INCREMENT ==========\n";

    Bureaucrat a("POPOK", 2);
    std::cout << a << std::endl;

    a.incrementGrade();
    std::cout << a << std::endl;

    std::cout << "\n========== VALID DECREMENT ==========\n";

    Bureaucrat b("PNDUK", 149);
    std::cout << b << std::endl;

    b.decrementGrade();
    std::cout << b << std::endl;

    std::cout << "\n========== TOO HIGH GRADE INCREMENT ==========\n";

    try
    {
        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TOO LOW GRADE DECREMENT ==========\n";

    try
    {
        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== INVALID CONSTRUCTORS ==========\n";

    try
    {
        Bureaucrat c("tooHigh", 0);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat d("tooLow", 151);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}