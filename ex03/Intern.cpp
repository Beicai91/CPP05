#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//constructors and destructor
Intern::Intern()
{}

Intern::Intern(const Intern &other)
{}

Intern::~Intern()
{}

//operators
Intern  &Intern::operator=(const Intern &other)
{
    return (*this);
}

//public member funcs
AForm   *Intern::makeForm(const std::string name, const std::string target) const
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm   *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    for (int i = 0; i < 3; ++i)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << " form" << std::endl;
            for (int j = 0; j < 3; ++j)
            {
                if (j != i)
                    delete forms[j];
            }
            return (forms[i]);
        }
    }
    std::cout << "Intern cannot create " << name << "form (form name invalid)" << std::endl;
    for (int j = 0; j < 3; ++j)
        delete forms[j];
    return (NULL);
}