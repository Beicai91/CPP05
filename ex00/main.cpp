#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat  b1("John", 3);
        const std::string   name = b1.getName();
        std::cout << "b1's name is " << name << std::endl;
        for (int i = 0; i < 10; ++i)
            b1.incrementGrade(b1);
        std::cout << "b1's grade is incremented to " << b1.getGrade() << std::endl;
        
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat  b2("Mark", 151);
        b2.decrementGrade(b2); //this will not be executed, interrupted by catch
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat  b2("Mark", -1);
        const std::string   name = b2.getName();//this will not be executed, interrupted by catch
    }
    catch (const std::exception &e) //porlimorphism, derived-to-base, based on the dynamic type of `e` returned by throw() in constructor, the corresponding what() will be matched
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return (0);
}