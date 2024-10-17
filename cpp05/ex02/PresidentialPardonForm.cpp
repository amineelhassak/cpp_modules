#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5),target("_default")
{
    std::cout << "PresidentialPardonForm : " << this->target << " * constractor is callled" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):AForm("PresidentialPardonForm", 25, 5),target(target)
{
    std::cout << "PresidentialPardonForm : " << this->target << " ** parametrized constractor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Robo):AForm(Robo)
{
    std::cout << "PresidentialPardonForm : "<< this->target <<" *** parametrized constractor is called" << std::endl;
    *this = Robo;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &Robo)
{
    std::cout << "PresidentialPardonForm : " << this->target << " Assignment Operator "<< std::endl;
    if (this != &Robo)
    {
        *this = Robo;
        this->target = Robo.target;
    }
    return (*this);
}

void PresidentialPardonForm::excute( Bureaucrat const & bure) const
{
    if (bure.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    std::cout << this->target <<" has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm : " << this->target << " Destractor is callled" << std::endl;
}
