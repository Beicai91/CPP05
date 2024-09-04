#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

//constructors and destructor
RobotomyRequestForm::RobotomyRequestForm(): AForm(), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{
    //std::cout << this->getName() << " is destroyed" << std::endl;
}

//operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

//other public member funcs
void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (this->getSignedInfo() == false)
    {
        std::cout << "Robotomy failed because ";
        throw (UnsignedFormException());
    }
    if (executor.getGrade() > this->getGradeToExec())
    {
        std::cout << "Robotomy failed" << std::endl;
        throw (Bureaucrat::GradeTooLowException());
    }
    std::cout << "#####EXECUTING#####" << std::endl;
    std::cout << this->_target << " has been robotomized successfully 50\% of the time" << std::endl;
    std::cout << "Form status notification: " << this->getName() << " is executed by " << executor.getName() << std::endl;
}
