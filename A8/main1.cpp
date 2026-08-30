#include <iostream>
#include <string>

using namespace std;

bool CheckTime(string time)
{
   if (time.length() != 5)
   {
      return false;
   }
   
   if (time[2] != ':')
   {
      return false;
   }
   
   for (int i = 0; i < 5; i++)
   {
      if (!((time[i] >= '0') && (time[i] <= '9')) && (i != 2))
      {
         return false;
      }
   }
   
   int hours = std::stoi(time.substr(0, 2));
   int minutes = std::stoi(time.substr(3, 2));
      
   return (hours >= 0 && hours <= 23) && (minutes >= 0 && minutes <= 59);
}

int main()
{
   string timeBefore;
   string timeAfter;

   std::cout << "Введите время отправления (HH:MM): ";
   std::getline(std::cin, timeBefore);
   if (!CheckTime(timeBefore))
   {
      cout << "Введённое время некорректно!" << endl;
      return -1;
   }

   std::cout << "Введите время прибытия (HH:MM): ";
   std::getline(std::cin, timeAfter);

   if (!CheckTime(timeAfter))
   {
      cout << "Введённое время некорректно!" << endl;
      return -1;
   }

   int depHours = std::stoi(timeBefore.substr(0, 2));
   int depMinutes = std::stoi(timeBefore.substr(3, 2));
   int arrHours = std::stoi(timeAfter.substr(0, 2));
   int arrMinutes = std::stoi(timeAfter.substr(3, 2));
   int depTotalMinutes = depHours * 60 + depMinutes;
   int arrTotalMinutes = arrHours * 60 + arrMinutes;
   
   int totalMinutes;
   if (arrTotalMinutes >= depTotalMinutes)
   {
      totalMinutes = arrTotalMinutes - depTotalMinutes;
   }
   else
   {
      totalMinutes = (24 * 60 - depTotalMinutes) + arrTotalMinutes;
   }
   
   int hours = totalMinutes / 60;
   int minutes = totalMinutes % 60;
   
   std::cout << "Поездка составила " << hours << " ч. " << minutes << " мин.\n";
 
   return 0;
}