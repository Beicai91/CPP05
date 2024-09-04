#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//constructors and destructor
PresidentialPardonForm::PresidentialPardonForm():AForm(), _target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other), _target(other._target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{
    //std::cout << this->getName() << " is destroyed" << std::endl;
}

//operators
PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

//other public member funcs
void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (this->getSignedInfo() == false)
    {
        std::cout << "Presidential pardon action failed because ";
        throw (UnsignedFormException());
    }
    if (this->getGradeToExec() < executor.getGrade())
        throw (Bureaucrat::GradeTooLowException());
    std::cout << "*****EXECUTING*****\n" << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    std::cout << "Form status notification: " << this->getName() << " is executed by " << executor.getName() << std::endl;
}