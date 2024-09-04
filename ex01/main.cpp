#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat  b1("John", 20);
        Form f1("HR", 0, 8);
        b1.signForm(f1);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat  b1("Mark", 1);
        Form f1("IT", 1, 1);
        f1.beSigned(b1);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b1("Bob", 20);
        Form f1("CEO", 1, 1);
        b1.signForm(f1);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Form f1("PR", 10, 10);
        Form f2(f1);
        std::cout << f2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception " << e.what() << std::endl;
    }
    return (0);
}