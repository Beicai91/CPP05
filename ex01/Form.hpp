#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool    _signed; //initialise to false
        const int   _gradeToSign;
        const int   _gradeToExec;
    
    public:
        Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExec);
        Form(const Form &other);
        Form    &operator=(const Form &other);
        ~Form();

        //nest exception class
        class GradeTooHighException: public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                const char  *what() const throw();
        };

        //getters
        const std::string   getName() const;
        bool    getSignedInfo() const;
        const int   getGradeToSign() const;
        const int   getGradeToExec() const;

        //other funcs
        void    beSigned(const Bureaucrat &bureaucrat);
};

std::ostream    &operator<<(std::ostream &os, const Form &target);

#endif