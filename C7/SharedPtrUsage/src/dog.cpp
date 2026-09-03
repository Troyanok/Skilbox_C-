#include <include/dog.h>
#include <iostream>

void Dog::GetToy(std::shared_ptr<Toy> toy)
{
    if (toy == nullptr)
    {
        std::cout << name_ << " cannot pick up a null toy." << std::endl;
        return;
    }

    if (currentToy_ == toy)
    {
        std::cout << "I already have this toy" << std::endl;
        return;
    }

    // Если у собаки есть другая игрушка, бросаем её
    if (currentToy_ != nullptr)
    {
        std::cout << name_ << " dropped the toy: " << currentToy_->GetName() << std::endl;
        currentToy_.reset();
    }

    // Проверяем, есть ли другие собаки, удерживающие эту игрушку
    if (toy.use_count() > 1)
    {
        std::cout << "Another dog is playing with this toy\n";
        return;
    }

    currentToy_ = toy;
    std::cout << name_ << " picked up the toy: " << toy->GetName() << std::endl;
}

void Dog::DropToy()
{
    if (currentToy_ == nullptr)
    {
        std::cout << "Nothing to drop" << std::endl;
        return;
    }

    std::cout << name_ << " dropped the toy: " << currentToy_->GetName() << std::endl;
    currentToy_.reset();
}
