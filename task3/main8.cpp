#include <iostream>

using namespace std;

int main()
{
    int salary1, salary2, salary3;
    int min_sal = 1000000, max_sal = 0;

    cout << "Введите зарплату первого сотрудника: ";
    cin >> salary1;
    
    cout << "Введите зарплату второго сотрудника: ";
    cin >> salary2;
    
    cout << "Введите зарплату третьего сотрудника: ";
    cin >> salary3;
    
    cout << "-----Считаем-----\n";
    
    
    // Первое сравнение: находим мин и макс для первых двух зарплат
    if (salary1 < salary2)
    {
        min_sal = salary1;
        max_sal = salary2;
    }
    else
    {
        min_sal = salary2;
        max_sal = salary1;
    }
    
    // Второе сравнение: сравниваем третью зарплату с текущим минимумом
    if (salary3 < min_sal)
    {
        min_sal = salary3;
    } 
    // Третье сравнение: сравниваем третью зарплату с текущим максимумом
    else if (salary3 > max_sal)
    {
        max_sal = salary3;
    }
    
    int diff = max_sal - min_sal;
    double average = (salary1 + salary2 + salary3) / 3.0;
    
    cout << "Самая высокая зарплата в отделе: " << max_sal << " рублей\n";
    cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << diff << " рублей\n";
    cout << "Средняя зарплата в отделе: " << average << " рублей\n";

    return 0;
}