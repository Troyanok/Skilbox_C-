#include <iostream>
#include <memory>
#include <include/dog.h>
#include <include/swimming.h>
#include <include/dancing.h>
#include <include/counting.h>

int main()
{
    // Создаём собаку
    Dog dog1("Steve");

    // Добавляем таланты
    dog1.AddTalent(std::make_unique<Dancing>());
    dog1.AddTalent(std::make_unique<Swimming>());

    // Показываем таланты
    dog1.ShowTalents();

    // Добавляем ещё один талант и показываем снова
    dog1.AddTalent(std::make_unique<Counting>());
    dog1.ShowTalents();

    return 0;
}
