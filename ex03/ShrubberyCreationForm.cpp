#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//constructors and destructor
ShrubberyCreationForm::ShrubberyCreationForm():AForm(), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other), _target(other._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    //std::cout << this->getName() << " is destroyed" << std::endl;
}

//operators
ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

//other public member funcs
void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (this->getSignedInfo() == false)
    {
        std::cout << "Shrubbery creation failed because: ";
        throw (UnsignedFormException());
    }
    if (this->getGradeToExec() < executor.getGrade())
        throw (Bureaucrat::GradeTooLowException());
    std::cout << "^^^^^EXECUTING^^^^^" << std::endl;
    std::ofstream   file(this->_target + "_Shrubbery");

    file << "                      ___" << std::endl;
    file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    file << "             ,-'          __,,-- \\" << std::endl;
    file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    file << "     (     ,-'                  `." << std::endl;
    file << "      `._,'     _   _             ;" << std::endl;
    file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    file << "                \"Hb HH dF" << std::endl;
    file << "                 \"HbHHdF" << std::endl;
    file << "                  |HHHF" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  dHHHb" << std::endl;
    file << "                .dFd|bHb.               o" << std::endl;
    file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    file << "##########################################" << std::endl;

    file.close();
    std::cout << "Form status notification: " << this->getName() << " is executed by " << executor.getName() << std::endl;
}