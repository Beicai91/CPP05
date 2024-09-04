#include "Bureaucrat.hpp"

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
    //if (target._grade > 1)
        //target._grade--;
    //else
        //std::cout << "Already maximum grade 1, impossible to increment" << std::endl;
    target._grade--;
    if (target._grade < 1)
    {
        std::cout << "Increment Error: ";
        throw GradeTooHighException();
    }
}

void    Bureaucrat::decrementGrade(Bureaucrat &target)
{
    //if (target._grade < 150)
        //target._grade++;
    //else
        //std::cout << "Already minimun grade 150, impossible to decrement" << std::endl;
    target._grade++;
    if (target._grade > 150)
    {
        std::cout << "Decrement Error: ";
        throw GradeTooLowException();
    }
}

//nest exception classes
const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high: it should be no higher than 1");
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low: it should be no lower than 150");
}