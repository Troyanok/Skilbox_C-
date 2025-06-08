#include <iostream>
#include <string>

using namespace std;

int main() {
    int day;
    cout << "Введите день недели (от 1 до 7): ";
    cin >> day;

    std::string dayName;
    std::string menu;

    switch (day)
    {
        case 1:
        {
            dayName = "понедельник";
            menu = "Борщ\nСалат «Греческий»\nГовядина по-бургундски\nКомпот";
            break;
        }
        case 2:
        {
            dayName = "вторник";
            menu = "Харчо\nСалат «Оливье»\nБаварские колбаски с капустой\nМорс";
            break;
        }
        case 3:
        {
            dayName = "среда";
            menu = "Щи\nСалат «Капрезе»\nРыбное филе с овощами\nЧай";
            break;
        }
        case 4:
        {
            dayName = "четверг";
            menu = "Гороховый суп\nСалат «Цезарь» с креветками\nКуриная ножка с пюре\nМорс";
            break;
        }
        case 5:
        {
            dayName = "пятница";
            menu = "Суп-лапша куриный\nСалат «Мимоза»\nПлов\nСок";
            break;
        }
        case 6:
        {
            dayName = "суббота";
            menu = "Томатный суп\nСалат «Кобб»\nСтейк\nМорс";
            break;
        }
        case 7:
        {
            dayName = "воскресенье";
            menu = "Солянка\nСалат «Цезарь» с курицей\nУтка с яблоками\nКомпот";
            break;
        }
        default:
        {
            cout << "Ошибка: введите число от 1 до 7!\n";
            return 1;
        }
    }

    cout << "Меню сегодня (" << dayName << "):\n" << menu << "\n";

    return 0;
}