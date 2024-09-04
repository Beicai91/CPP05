#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "TEST1: John (grade 1) tries to execute sf directly" << std::endl;
    Bureaucrat  b1("John", 1);
    ShrubberyCreationForm sf("home");
    AForm   &sf_ref = sf;
    b1.executeForm(sf_ref);

    std::cout << "\nTEST2: John signs sf form before execute again" << std::endl;
    b1.signForm(sf);
    b1.executeForm(sf_ref);

    std::cout << "\nTEST3: Mark (grade 120) tries to sign rf form before execute" << std::endl;
    Bureaucrat  b2("Mark", 120);
    RobotomyRequestForm rf("home");
    b2.signForm(rf);
    AForm   &rf_ref = rf;
    b2.executeForm(rf_ref);

    std::cout << "\nTEST4: Bob (grade 10) signs rf again. Then Mark (grade 120) still tries to execute it" << std::endl;
    Bureaucrat b3("Bob", 10);
    b3.signForm(rf);
    b2.executeForm(rf_ref);

    std::cout << "\nTEST5: Mr. President signs and executes pf" << std::endl;
    Bureaucrat  b4("Mr.President", 1);
    const Bureaucrat    &b4_ref = b4;
    PresidentialPardonForm  pf("home");
    pf.beSigned(b4_ref);
    pf.execute(b4_ref);

    return (0);
}