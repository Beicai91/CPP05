#include "AForm.hpp"
#include "Bureaucrat.hpp"

//constructors and destructor
AForm::AForm(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
    std::cout << "A default, unsigned form is created. Bureaucrats of any valide grade can sign and execute it" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw (AForm::GradeTooHighException());
    if (gradeToSign > 150 || gradeToExec > 150)
        throw (AForm::GradeTooLowException());
    std::cout << "A " << name << " unsigned form is created(Grade to sign it " << gradeToSign << ";Grade to execute it " << gradeToExec << ")" << std::endl;
}

AForm::AForm(const AForm &other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    std::cout << "A form is created by copying another one" << std::endl;
}

AForm::~AForm()
{
    std::cout << "The form is destroyed" << std::endl;
}

//operators
AForm    &AForm::operator=(const AForm &other)
{
    if (this == &other)
        return (*this);
    this->_signed = other._signed;
    std::cout << "This BASE form's signature status is copied form another one" << std::endl;
    return (*this);
}

std::ostream    &operator<<(std::ostream &os, const AForm &target)
{
    os << "Form info:\nname " << target.getName() << "\nsignature status: " << target.getSignedInfo() << "\nGrade to sign: " << target.getGradeToSign() << "\nGrade to execute: " << target.getGradeToExec() << std::endl;
    return (os);
}

//nested classes
const char  *AForm::GradeTooLowException::what() const throw()
{
    return ("Form grade to sign or to execute is too low (Grade range: 1-150)");
}

const char  *AForm::GradeTooHighException::what() const throw()
{
    return ("Form grade to sign or to execute is too high (Grade range: 1-150)");
}

const char  *AForm::UnsignedFormException::what() const throw()
{
    return ("Form is not signed yet");
}

//getters
const std::string   AForm::getName() const
{
    return (this->_name);
}

bool    AForm::getSignedInfo() const
{
    return (this->_signed);
}

const int   AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}

const int   AForm::getGradeToExec() const
{
    return (this->_gradeToExec);
}

//other public member funcs
void    AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (this->_signed == true)
    {
        std::cout << "Form status notification: Form is already signed" << std::endl;
        return ;
    }
    if (bureaucrat.getGrade() <= this->_gradeToSign)
    {
        this->_signed = true;
        std::cout << "Form status notificiation: Form is signed by " << bureaucrat.getName() << std::endl;
    }
    else
        throw (Bureaucrat::GradeTooLowException());
}