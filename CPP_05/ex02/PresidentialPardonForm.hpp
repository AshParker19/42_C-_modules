#ifndef PRESEDENTIALPARDONFORM_HPP
#define PRESEDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;
        PresidentialPardonForm();
    
    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        std::string const &getTarget(void) const;
        void execute(Bureaucrat const &executor) const;
};

#endif