#include <iostream>
#include <string>

using namespace std;

int main()
{
    int day;
    cout << "Введите день недели (от 1 до 7): ";
    cin >> day;

    std::string dayName;
    std::string menu;

    if (day == 1)
    {
        dayName = "понедельник";
        menu = "Борщ\nСалат «Греческий»\nГовядина по-бургундски\nКомпот";
    }
    else if (day == 2)
    {
        dayName = "вторник";
        menu = "Харчо\nСалат «Оливье»\nБаварские колбаски с капустой\nМорс";
    }
    else if (day == 3)
    {
        dayName = "среда";
        menu = "Щи\nСалат «Капрезе»\nРыбное филе с овощами\nЧай";
    }
    else if (day == 4)
    {
        dayName = "четверг";
        menu = "Гороховый суп\nСалат «Цезарь» с креветками\nКуриная ножка с пюре\nМорс";
    }
    else if (day == 5)
    {
        dayName = "пятница";
        menu = "Суп-лапша куриный\nСалат «Мимоза»\nПлов\nСок";
    }
    else if (day == 6)
    {
        dayName = "суббота";
        menu = "Томатный суп\nСалат «Кобб»\nСтейк\nМорс";
    }
    else if (day == 7)
    {
        dayName = "воскресенье";
        menu = "Солянка\nСалат «Цезарь» с курицей\nУтка с яблоками\nКомпот";
    }
    else
    {
        cout << "Ошибка: введите число от 1 до 7!\n";
        return 1;
    }

    cout << "Меню сегодня (" << dayName << "):\n" << menu << "\n";

    return 0;
}