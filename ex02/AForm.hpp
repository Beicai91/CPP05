#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool    _signed; //initialise to false
        const int   _gradeToSign;
        const int   _gradeToExec;
    
    protected: //enforce that this abstract class cannot be instantiated
        AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExec);
        AForm(const AForm &other);
    
    public:
        AForm    &operator=(const AForm &other);
        virtual ~AForm();

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

        class UnsignedFormException: public std::exception
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
        virtual void    execute(const Bureaucrat &executor) const = 0;
};

std::ostream    &operator<<(std::ostream &os, const AForm &target);

#endif