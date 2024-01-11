#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &newTarget) :
    AForm("ShrubberyCreationForm", 145, 137),
    target(newTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
    AForm(other),
    target(other.target) 
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string const &ShrubberyCreationForm::getTarget(void) const
{
    return (this->target);
}

const char *ShrubberyCreationForm::CouldNotOpenFileException::what() const throw()
{
    return ("Could not open file");
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    this->canExecute(executor);
    std::string name = target;
    name += "_shrubbery";
    std::ofstream outfile(name.c_str());
    if (outfile.fail())
        throw ShrubberyCreationForm::CouldNotOpenFileException();
    outfile << "      /\\\\" << std::endl;
    outfile << "     //\\\\" << "\\" << std::endl;
    outfile << "    //  \\\\" << "\\" << std::endl;
    outfile << "   //    \\\\" << "\\" << std::endl;
    outfile << "  //______\\\\" << "\\" << std::endl;
    outfile << "     [\"\"]" << std::endl;
    outfile << "     [\"\"]" << std::endl;
    outfile << "     [\"\"]" << std::endl;

    outfile.close();
}
