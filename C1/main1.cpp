#include <iostream>
#include <string>
#include <map>
#include <time.h>
#include <vector>

using namespace std;

struct Task
{
    string taskName;
    time_t beginTimeTask;
    time_t endTimeTask;

    Task() 
        : taskName("")
        , beginTimeTask(0)
        , endTimeTask(0)
    {};

    void ResetParams(const string& nameTask = "")
    {
        taskName = nameTask;
        beginTimeTask = time(nullptr);
        endTimeTask = 0;
    };
};

int main()
{
    vector<Task> completedTask;
    Task currentTask;

    string command;

    while (true)
    {
        cout << "Введите команду для текущей задачи: " << endl;
        cout << "\t begin - Начало отслеживания новой задачи;" << endl;
        cout << "\t end - Завершить отслеживание текущей задачи;" << endl;
        cout << "\t status - Вывести состояние текущей задачи;" << endl;
        cout << "\t exit - Завершить работу программы." << endl;
        cin >> command;
        cin.ignore();

        if (command == "exit")
        {
            if (currentTask.endTimeTask == 0 && !currentTask.taskName.empty())
            {
                currentTask.endTimeTask = time(nullptr);
                completedTask.push_back(currentTask);
            }
            break;
        }
        else if (command == "begin")
        {
            string taskName;
            cout << "Название задачи: ";
            getline(cin, taskName);

            if (taskName.empty())
            {
                cout << "Имя задачи не может быть пустым!" << endl;
                continue;
            }

            // Завершить предыдущую, если была активна
            if (currentTask.endTimeTask == 0 && !currentTask.taskName.empty())
            {
                currentTask.endTimeTask = time(nullptr);
                completedTask.push_back(currentTask);
            }

            currentTask.ResetParams(taskName);
            cout << "Started task \"" << taskName << "\"" << endl;
        }
        else if (command == "end")
        {
            if (currentTask.endTimeTask == 0 && !currentTask.taskName.empty())
            {
                currentTask.endTimeTask = time(nullptr);
                completedTask.push_back(currentTask);
                cout << "Задача \"" << currentTask.taskName << "\" завершена." << endl;
                currentTask = Task();
            }
            else
            {
                cout << "Нет активных задач сейчас" << endl;
            }
        }
        else if (command == "status")
        {
            cout << "Завершённые задачи: " << endl;
            for (const auto& t : completedTask)
            {
                double hours = difftime(t.endTimeTask, t.beginTimeTask) / 3600.0;
                cout << t.taskName << ": " << hours << " h" << endl;
            }

            if (currentTask.endTimeTask == 0 && !currentTask.taskName.empty())
            {
                double hours = difftime(time(nullptr), currentTask.beginTimeTask) / 3600.0;
                cout << "Активная: " << currentTask.taskName
                     << " (прошло " << hours << " h)" << endl;
            }
            else
            {
                cout << "Нет активных задач" << endl;
            }
            cout << "----------------------" << endl;
        }
        else
        {
            cout << "Неизвестная команда" << endl;
        }
        cout << endl;
    }
    return 0;
}
