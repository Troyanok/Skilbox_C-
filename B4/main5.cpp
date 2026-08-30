#include <iostream>
#include <sstream>
#include <string>

using namespace std;


// Перечисление устройств (битовые флаги)
enum Switches
{
     LIGHTS_INSIDE      = 1 << 0,  // 1
     LIGHTS_OUTSIDE     = 1 << 1,  // 2
     HEATERS            = 1 << 2,  // 4
     WATER_PIPE_HEATING = 1 << 3,  // 8
     CONDITIONER        = 1 << 4   // 16
};

int main()
{
     int switchState = 0;  // текущее состояние всех переключателей
     bool lightsInsideOn = false;
     double colorTemp = 5000.0;

     for (int hour = 0; hour < 48; hour++)
     {
          // Текущее время суток (0–23)
          int timeOfDay = hour % 24;

          // Ввод данных
          double tempIn, tempOut;
          string movement, lightsCommand;
          cout << "Temperature inside, temperature outside, movement, lights: ";
          cin >> tempIn >> tempOut >> movement >> lightsCommand;

          // Сохраняем предыдущие состояния для проверки изменений
          int old_state = switchState;

          // Управление обогревом водопровода 
          if (tempOut < 0.0)
          {
               switchState |= WATER_PIPE_HEATING;
          }
          else if (tempOut > 5.0)
          {
               switchState &= ~WATER_PIPE_HEATING;
          }

          // Управление садовым освещением 
          bool evening = (timeOfDay >= 17 || timeOfDay < 5); // с 17:00 до 4:59
          if (evening && movement == "yes")
          {
               switchState |= LIGHTS_OUTSIDE;
          }
          else
          {
               switchState &= ~LIGHTS_OUTSIDE;
          }

          // Управление отоплением 
          if (tempIn < 22.0)
          {
               switchState |= HEATERS;
          }
          else if (tempIn >= 25.0)
          {
               switchState &= ~HEATERS;
          }

          // Управление кондиционером 
          if (tempIn >= 30.0)
          {
               switchState |= CONDITIONER;
          }
          else if (tempIn <= 25.0)
          {
               switchState &= ~CONDITIONER;
          }

          // Управление внутренним светом (по команде пользователя) 
          if (lightsCommand == "on")
          {
               if (!(switchState & LIGHTS_INSIDE))
               {
                    switchState |= LIGHTS_INSIDE;
                    lightsInsideOn = true;
               }
          }
          else if (lightsCommand == "off")
          {
               if (switchState & LIGHTS_INSIDE)
               {
                    switchState &= ~LIGHTS_INSIDE;
                    lightsInsideOn = false;
               }
          }

          // Обновление цветовой температуры (только если свет включён) 
          if (lightsInsideOn)
          {
               // Логика изменения цвета в зависимости от времени
               if (timeOfDay >= 16 && timeOfDay < 20)
               {
                    // Плавное снижение с 5000K до 2700K за 4 часа
                    double progress = (timeOfDay - 16) / 4.0; // 0.0 в 16:00, 1.0 в 20:00
                    colorTemp = 5000.0 - (5000.0 - 2700.0) * progress;
               }
               else if (timeOfDay == 0)
               {
                    // Сброс в полночь
                    colorTemp = 5000.0;
               }
               // В остальное время цвет не меняется (остаётся последним установленным)
          }

          // Вывод событий только для изменившихся устройств 
          int changes = old_state ^ switchState; // биты, которые изменились

          if (changes & LIGHTS_INSIDE)
          {
               if (switchState & LIGHTS_INSIDE)
               {
                    cout << "Lights ON!" << endl;
               }
               else
               {
                    cout << "Lights OFF!" << endl;
               }
          }
          if (changes & LIGHTS_OUTSIDE)
          {
               if (switchState & LIGHTS_OUTSIDE)
               {
                    cout << "Outside lights ON!" << endl;
               }
               else
               {
                    cout << "Outside lights OFF!" << endl;
               }
          }
          if (changes & HEATERS)
          {
               if (switchState & HEATERS)
               {
                    cout << "Heaters ON!" << endl;
               }
               else
               {
                    cout << "Heaters OFF!" << endl;
               }
          }
          if (changes & WATER_PIPE_HEATING)
          {
               if (switchState & WATER_PIPE_HEATING)
               {
                    cout << "Water pipe heating ON!" << endl;
               }
               else
               {
                    cout << "Water pipe heating OFF!" << endl;
               }
          }
          if (changes & CONDITIONER)
          {
               if (switchState & CONDITIONER)
               {
                    cout << "Conditioner ON!" << endl;
               }
               else
               {
                    cout << "Conditioner OFF!" << endl;
               }
          }

          // Отображение цветовой температуры, если свет в доме включён
          if (switchState & LIGHTS_INSIDE)
          {
               cout << "Color temperature: " << colorTemp << "K" << endl;
          }
     }

     cout << "Симуляция завершена." << endl;
     return 0;
}