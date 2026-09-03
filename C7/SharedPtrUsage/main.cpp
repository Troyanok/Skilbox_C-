#include <iostream>
#include <memory>
#include <include/dog.h>
#include <include/toy.h>

int main()
{
    auto ball = std::make_shared<Toy>("Ball");
    auto bone = std::make_shared<Toy>("Bone");

    Dog dog1("Rex");
    Dog dog2("Buddy");

    dog1.GetToy(ball);
    dog2.GetToy(ball);
    dog2.GetToy(bone);
    dog1.GetToy(ball);
    dog1.DropToy();
    dog2.GetToy(ball);
    dog2.DropToy();

    return 0;
}
