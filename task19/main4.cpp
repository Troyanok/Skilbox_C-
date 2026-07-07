#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAP_SIZE = 20;
const int ENEMY_COUNT = 5;

struct Character
{
    string name;
    int health;
    int armor;
    int damage;
    int x, y;
};

// Генерация случайного числа в диапазоне [min, max]
int RandInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Проверка, свободна ли клетка
bool IsCellFree(int x, int y, const vector<Character>& chars, int skipIndex = -1)
{
    for (size_t i = 0; i < chars.size(); ++i)
    {
        if (static_cast<int>(i) == skipIndex) continue;
        if ((chars[i].health > 0) && (chars[i].x == x) && (chars[i].y == y))
        {
            return false;
        }
    }
    return true;
}

// Отображение карты
void DrawMap(const vector<Character>& chars)
{
    char grid[MAP_SIZE][MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; ++i)
        for (int j = 0; j < MAP_SIZE; ++j)
            grid[i][j] = '.';

    if (chars[0].health > 0)
    {
        grid[chars[0].y][chars[0].x] = 'P';
    }

    for (size_t i = 1; i < chars.size(); ++i)
    {
        if (chars[i].health > 0)
        {
            grid[chars[i].y][chars[i].x] = 'E';
        }
    }

    for (int i = 0; i < MAP_SIZE; ++i)
    {
        for (int j = 0; j < MAP_SIZE; ++j)
        {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

// Атака
void Attack(Character& attacker, Character& target)
{
    int dmg = attacker.damage;
    int absorbed = min(target.armor, dmg);
    target.armor -= absorbed;
    int healthLoss = dmg - absorbed;
    target.health -= healthLoss;
    if (target.health < 0)
    {
        target.health = 0;
    }
}

// Сохранение игры
void SaveGame(const vector<Character>& chars)
{
    ofstream file("save.bin", ios::binary);
    if (!file)
    {
        cout << "Ошибка сохранения!" << endl;
        return;
    }
    size_t count = chars.size();
    file.write((char*)(&count), sizeof(count));
    for (const auto& c : chars)
    {
        int len = c.name.length();
        file.write((char*)(&len), sizeof(len));
        file.write(c.name.c_str(), len);
        file.write((char*)(&c.health), sizeof(c.health));
        file.write((char*)(&c.armor), sizeof(c.armor));
        file.write((char*)(&c.damage), sizeof(c.damage));
        file.write((char*)(&c.x), sizeof(c.x));
        file.write((char*)(&c.y), sizeof(c.y));
    }
    cout << "Игра сохранена." << endl;
}

// Загрузка игры
bool LoadGame(vector<Character>& chars)
{
    ifstream file("save.bin", ios::binary);
    if (!file)
    {
        cout << "Файл сохранения не найден." << endl;
        return false;
    }
    size_t count;
    file.read((char*)(&count), sizeof(count));
    if (!file)
    {
        return false;
    }
    chars.clear();
    for (size_t i = 0; i < count; ++i)
    {
        Character c;
        int len;
        file.read((char*)(&len), sizeof(len));
        c.name.resize(len);
        file.read(&c.name[0], len);
        file.read((char*)(&c.health), sizeof(c.health));
        file.read((char*)(&c.armor), sizeof(c.armor));
        file.read((char*)(&c.damage), sizeof(c.damage));
        file.read((char*)(&c.x), sizeof(c.x));
        file.read((char*)(&c.y), sizeof(c.y));
        if (!file)
        {
            return false;
        }
        chars.push_back(c);
    }
    cout << "Игра загружена." << endl;
    return true;
}

// Инициализация: создание игрока и врагов
void InitializeGame(vector<Character>& characters)
{
    characters.clear();
    characters.push_back(Character{}); // слот для игрока

    // Ввод параметров игрока
    cout << "Введите имя игрока: ";
    cin >> characters[0].name;
    cout << "Здоровье: ";
    cin >> characters[0].health;
    cout << "Броня: ";
    cin >> characters[0].armor;
    cout << "Урон: ";
    cin >> characters[0].damage;

    // Случайная позиция игрока
    do
    {
        characters[0].x = RandInt(0, MAP_SIZE - 1);
        characters[0].y = RandInt(0, MAP_SIZE - 1);
    } while (!IsCellFree(characters[0].x, characters[0].y, characters, 0));

    // Создание врагов
    for (int i = 0; i < ENEMY_COUNT; ++i)
    {
        Character enemy;
        enemy.name = "Enemy #" + to_string(i + 1);
        enemy.health = RandInt(50, 150);
        enemy.armor = RandInt(0, 50);
        enemy.damage = RandInt(15, 30);
        do
        {
            enemy.x = RandInt(0, MAP_SIZE - 1);
            enemy.y = RandInt(0, MAP_SIZE - 1);
        } while (!IsCellFree(enemy.x, enemy.y, characters));
        characters.push_back(enemy);
    }
}

// Проверка, завершена ли игра
bool IsGameOver(const vector<Character>& chars)
{
    if (chars[0].health <= 0)
    {
        cout << "Вы погибли. Поражение." << endl;
        return true;
    }
    for (size_t i = 1; i < chars.size(); ++i)
    {
        if (chars[i].health > 0) return false;
    }
    cout << "Все враги повержены! Победа!" << endl;
    return true;
}

// Ход игрока
void PlayerTurn(vector<Character>& chars)
{
    cout << "Ваш ход (L/R/U/D, save, load): ";
    string cmd;
    cin >> cmd;

    if (cmd == "save")
    {
        SaveGame(chars);
        return;
    }
    if (cmd == "load")
    {
        LoadGame(chars);
        return;
    }

    int dx = 0, dy = 0;
    if (cmd == "L")
    {
        dx = -1;
    }
    else if (cmd == "R")
    {
        dx = 1;
    }
    else if (cmd == "U")
    {
        dy = -1;
    }
    else if (cmd == "D")
    {
        dy = 1;
    }
    else
    {
        cout << "Неверная команда. Пропуск хода." << endl;
        return;
    }

    int newX = chars[0].x + dx;
    int newY = chars[0].y + dy;
    if ((newX < 0) || (newX >= MAP_SIZE) || (newY < 0) || (newY >= MAP_SIZE))
    {
        cout << "Выход за границы. Ход пропущен." << endl;
        return;
    }

    // Поиск врага в новой клетке
    for (size_t i = 1; i < chars.size(); ++i)
    {
        if ((chars[i].health > 0) && (chars[i].x == newX) && (chars[i].y == newY))
        {
            Attack(chars[0], chars[i]);
            cout << "Вы атаковали " << chars[i].name << "!" << endl;
            if (chars[i].health <= 0)
            {
                cout << chars[i].name << " уничтожен." << endl;
            }
            return;
        }
    }
    // Если никого нет — перемещение
    chars[0].x = newX;
    chars[0].y = newY;
}

// Ход всех врагов
void EnemiesTurn(vector<Character>& chars)
{
    for (size_t i = 1; i < chars.size(); ++i)
    {
        if (chars[i].health <= 0) continue;
        int dir = rand() % 4;
        int dx = 0, dy = 0;
        switch (dir)
        {
            case 0: dx = -1; break;
            case 1: dx = 1; break;
            case 2: dy = -1; break;
            case 3: dy = 1; break;
        }
        int newX = chars[i].x + dx;
        int newY = chars[i].y + dy;
        if ((newX >= 0) && (newX < MAP_SIZE) && (newY >= 0) && (newY < MAP_SIZE))
        {
            if (IsCellFree(newX, newY, chars, i))
            {
                chars[i].x = newX;
                chars[i].y = newY;
            }
        }
    }
}

// Главный игровой цикл
void GameLoop(vector<Character>& chars)
{
    bool playerTurnFlag = true;
    while (!IsGameOver(chars))
    {
        DrawMap(chars);
        if (playerTurnFlag)
        {
            PlayerTurn(chars);
        }
        else
        {
            EnemiesTurn(chars);
        }
        playerTurnFlag = !playerTurnFlag;
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    vector<Character> characters;

    InitializeGame(characters);
    GameLoop(characters);

    return 0;
}
