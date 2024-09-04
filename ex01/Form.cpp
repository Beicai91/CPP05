#include "Form.hpp"
#include "Bureaucrat.hpp"

//constructors and destructor
Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
    std::cout << "A default, unsigned form is created. Bureaucrats of any valide grade can sign and execute it" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw (Form::GradeTooHighException());
    if (gradeToSign > 150 || gradeToExec > 150)
        throw (Form::GradeTooLowException());
    std::cout << "A " << name << " unsigned form is created(Grade to sign it " << gradeToSign << "; Grade to execute it " << gradeToExec << ")"<< std::endl;
}

Form::Form(const Form &other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    std::cout << "A form is created by copying another one" << std::endl;
}

Form::~Form()
{
    std::cout << "The form is destroyed" << std::endl;
}

//operators
Form    &Form::operator=(const Form &other)
{
    if (this == &other)
        return (*this);
    this->_signed = other._signed;
    std::cout << "This form's signature status is copied form another one" << std::endl;
    return (*this);
}

std::ostream    &operator<<(std::ostream &os, const Form &target)
{
    os << "Form info:\nname " << target.getName() << "\nsignature status: " << target.getSignedInfo() << "\nGrade to sign: " << target.getGradeToSign() << "\nGrade to execute: " << target.getGradeToExec() << std::endl;
    return (os);
}

//nested classes
const char  *Form::GradeTooLowException::what() const throw()
{
    return ("Form grade to sign or to execute is too low (Grade range: 1-150)");
}

const char  *Form::GradeTooHighException::what() const throw()
{
    return ("Form grade to sign or to execute is too high (Grade range: 1-150)");
}

//getters
const std::string   Form::getName() const
{
    return (this->_name);
}

bool    Form::getSignedInfo() const
{
    return (this->_signed);
}

const int   Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

const int   Form::getGradeToExec() const
{
    return (this->_gradeToExec);
}

//public member funcs
void    Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (this->_signed == true)
    {
        std::cout << "Form status notification: Form is already signed" << std::endl;
        return ;
    }
    if (bureaucrat.getGrade() <= this->_gradeToSign)
    {
        this->_signed = true;
        std::cout << "Form status notification: Form is signed by " << bureaucrat.getName() << std::endl;
    }
    else
        throw (Bureaucrat::GradeTooLowException());
}
