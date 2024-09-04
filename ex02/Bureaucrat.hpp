#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;
        int _grade; //[0-150]
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name,  int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat  &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        const std::string   getName() const;
        int getGrade() const;
        void    incrementGrade(Bureaucrat &target);
        void    decrementGrade(Bureaucrat &target);
        void    signForm(AForm &target) const;
        void    executeForm(const AForm &form);

        class GradeTooHighException : public std::exception
        {
            public:
                const char  *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char  *what() const throw();
        };

};

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &target);

#endif