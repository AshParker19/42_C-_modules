#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;
        RobotomyRequestForm();
    
    public:
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        std::string const &getTarget(void) const;
        void execute(Bureaucrat const &executor) const;
};

#endif