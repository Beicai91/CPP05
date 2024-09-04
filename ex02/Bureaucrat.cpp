#include "Bureaucrat.hpp"
#include "AForm.hpp"

//constructors and destructor
Bureaucrat::Bureaucrat(): _name("default"), _grade(1)
{
    std::cout << "A default bureaucrat with grade 1 is created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    
        this->_grade = grade;
        std::cout << "A bureaucrat named " << name << " with grade " << grade << " is created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
    std::cout << "A bureaucrat named " << this->_name << " with grade " << this->_grade << " is created by copying another one" << std::endl; 
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "The bureaucrat named " << this->_name << " is destroyed" << std::endl;
}

//operators
Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return (*this);
    this->_grade = other._grade;
    std::cout << "copy assignment operator called. Grade of another one is copied" << std::endl;
    return (*this);
}

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &target)
{
    os << target.getName() << " , bureaucrat grade " << target.getGrade();
    return (os);
}

//public member funcs
const std::string   Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade(Bureaucrat &target)
{
    if (target._grade > 1)
        target._grade--;
    else
        std::cout << "Already maximum grade 1, impossible to increment" << std::endl;
}

void    Bureaucrat::decrementGrade(Bureaucrat &target)
{
    if (target._grade < 150)
        target._grade++;
    else
        std::cout << "Already minimun grade 150, impossible to decrement" << std::endl;
}

void    Bureaucrat::signForm(AForm &form) const
{
    if (form.getSignedInfo() == true)
    {
        std::cout << "Bureaucrat activity notification: The target form is already signed" << std::endl;
        return ;
    }
    try
    {
        form.beSigned(*this);
        std::cout << "Bureaucrat activity notification: " << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
        std::cout << this->_name << " couldn't sign " << form.getName() << " because he or she doesn't have a grade high enough to sign the form" << std::endl; 
    }
}

void    Bureaucrat::executeForm(const AForm &form)
{
    try
    {
        form.execute(*this);
        std::cout << "Bureaucrat activity notification: " << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
        std::cout << "Bureaucrat activity notification: " << this->_name << " couldn't execute " << form.getName() << " because the form is not signed yet or he or she doesn't have a grade high enough to execute the form" << std::endl; 
    }
}

//nest exception classes
const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high:\n If you are creating a bureaucrat, it should be no higher than 1");
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low:\n If you are creating a bureaucrat, it should be no lower than 150\n If you want a bureaucrat to sign a form or execute a form, it should be higher than form's grade");
}