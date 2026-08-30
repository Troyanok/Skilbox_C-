#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

const int TOTAL_QUEST { 13 };
const int WINNER_COUNT { 6 };

// Удаление пробелов по краям строки
string WithoutExtraSpace(const string &s)
{
    size_t start = 0;
    while (start < s.size() && isspace(static_cast<unsigned char>(s[start])))
    {
        start++;
    }

    size_t end = s.size();
    while (end > start && isspace(static_cast<unsigned char>(s[end - 1])))
    {
        end--;
    }

    return s.substr(start, end - start);
}

// Приведение строки к нижнему регистру (для нечувствительного сравнения)
string ToLower(const string &s)
{
    string result = s;
    for (char &c : result)
    {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }
    return result;
}

int main()
{
    int playersCount { 0 };
    int viewersCount { 0 };
    int currentSector { 1 };
    int offset { 0 };

    vector<bool> activeQuest(TOTAL_QUEST + 1, true);
    cout << "Добро пожаловать в игру Что? Где? Когда?" << endl;
    cout << "Для каждого хода введите смещение (офсет) волчка." << endl;
    cout << "Игра идёт до " << WINNER_COUNT << " очков у одной из сторон." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;

    while (playersCount < WINNER_COUNT && viewersCount < WINNER_COUNT)
    {
        cout << "Текущий сектор: " << currentSector << ". Введите смещение: ";
        
        // Безопасный ввод смещения с проверкой корректности
        while (!(cin >> offset))
        {
            cout << "Ошибка ввода. Введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // Очищаем остаток строки до конца, чтобы не мешать следующему вводу
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int rawTarget = (currentSector - 1 + offset) % TOTAL_QUEST;
        if (rawTarget < 0)
        {
            rawTarget += TOTAL_QUEST;
        }
        rawTarget += 1;

        // Поиск активного сектора (вопрос не был задан)
        int activeSector = rawTarget;
        while (!activeQuest[activeSector])
        {
            activeSector = (activeSector % TOTAL_QUEST) + 1;
            if (activeSector == rawTarget)
            {
                cout << "Все сектора уже сыграны!" << endl;
                return -1;
            }
        }

        activeQuest[activeSector] = false;
        cout << "Играет сектор №" << activeSector << endl;
        cout << endl;

        // Чтение вопроса
        string questionFileName = "question_" + to_string(activeSector) + ".txt";
        ifstream questionFile(questionFileName);
        if (!questionFile.is_open())
        {
            cout << "Ошибка: не удалось открыть файл вопроса " << questionFileName << endl;
            return 1;
        }

        string question;
        getline(questionFile, question, '\0');
        questionFile.close();
        if (question.empty())
        {
            cout << "Файл вопроса пуст!" << endl;
            return -1;
        }

        // Удаляем возможные символы '\r' (для файлов, созданных в Windows)
        question.erase(remove(question.begin(), question.end(), '\r'), question.end());
        
        cout << "Вопрос: " << question << endl;

        // Ответ игрока
        cout << "Ваш ответ: ";
        string userAnswer;
        getline(cin, userAnswer);
        userAnswer = WithoutExtraSpace(userAnswer);

        // Получение корректного ответа
        string answerFileName = "answer_question_" + to_string(activeSector) + ".txt";
        ifstream answerFile(answerFileName);
        if (!answerFile.is_open())
        {
            cout << "Ошибка: не удалось открыть файл ответа " << answerFileName << endl;
            return -1;
        }
        string correctAnswer;
        getline(answerFile, correctAnswer);
        answerFile.close();
        correctAnswer = WithoutExtraSpace(correctAnswer);

        // Проверка на пустой файл с ответом (например, если в нём только переводы строк)
        if (correctAnswer.empty())
        {
            cout << "Ошибка: файл ответа не содержит данных." << endl;
            return -1;
        }

        // Сравнение без учёта регистра
        if (ToLower(userAnswer) == ToLower(correctAnswer))
        {
            cout << "Правильно! Очко достаётся знатокам." << endl;
            playersCount++;
        }
        else
        {
            cout << "Неверно. Правильный ответ: " << correctAnswer << ". Очко уходит телезрителям." << endl;
            viewersCount++;
        }

        // Обновляем текущий сектор для следующего хода
        currentSector = activeSector;

        cout << "Счёт: Знатоки " << playersCount << " - Зрители " << viewersCount << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << endl;
    }

    if (playersCount == WINNER_COUNT)
    {
        cout << "Поздравляем! Победили знатоки!" << endl;
    }
    else
    {
        cout << "Увы, победа досталась телезрителям." << endl;
    }
    return 0;
}
