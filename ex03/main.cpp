#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    Intern  nobody;
    std::cout << std::endl;
    AForm   *f1 = nobody.makeForm("presidential pardon", "home");
    std::cout << std::endl;
    AForm   *f2 = nobody.makeForm("shrubbery creation", "home");
    std::cout << std::endl;
    AForm   *f3 = nobody.makeForm("robotomy request", "home");
    std::cout << std::endl;
    Bureaucrat  mr("Mark", 20);
    std::cout << std::endl;
    mr.signForm(*f1);
    mr.executeForm(*f1);
    std::cout << std::endl;
    mr.signForm(*f2);
    mr.executeForm(*f2);
    std::cout << std::endl;
    mr.signForm(*f3);
    mr.executeForm(*f3);

    std::cout << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return (0);
}