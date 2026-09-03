#include <include/dog.h>
#include <iostream>

void Dog::ShowTalents() const
{
    std::cout << "This is " << name_ << " and it has some talents:" << std::endl;
    if (talents_.empty())
    {
        std::cout << "\tIt has no talents." << std::endl;
    }
    else
    {
        for (const auto& talent : talents_)
        {
            std::cout << "\t\tIt can \"" << talent->GetTalentName() << std::endl;
        }
    }
}
