#include <iostream>
#include <string>

namespace
{

const std::string correct_letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

const std::string special_letters = "!#$%&'*+-/=?^_`{|}~.";

}

// Функция для получения первой части email-адреса (до @)
std::string get_local_part(const std::string& email)
{
    std::string local_part = "";
    for (char c : email)
    {
        if (c == '@')
        {
            break;
        }
        local_part += c;
    }

    return local_part;
}

// Функция для получения второй части email-адреса (после @)
std::string get_domain_part(const std::string& email)
{
    std::string domain_part = "";
    bool found_at = false;
    
    for (char c : email)
    {
        if (found_at)
        {
            domain_part += c;
        }

        if (c == '@')
        {
            found_at = true;
        }
    }

    return domain_part;
}

// Проверка допустимых символов для локальной части
bool is_correct_local_char(char c)
{
    // Проверка букв и цифр
    for (char correct : correct_letters)
    {
        if (c == correct)
        {
            return true;
        }
    }
    
    // Проверка специальных символов
    for (char special : special_letters)
    {
        if (c == special)
        {
            return true;
        }
    }
    
    // Проверка дефиса
    if (c == '-')
    {
        return true;
    }

    return false;
}

// Проверка допустимых символов для доменной части
bool is_correct_domain_char(char c)
{
    // Проверка букв и цифр
    for (char correct : correct_letters)
    {
        if (c == correct)
        {
            return true;
        }
    }
    
    // Проверка дефиса и точки
    if ((c == '-') || (c == '.'))
    {
        return true;
    }

    return false;
}

// Проверка локальной части email-адреса
bool correctate_local_part(const std::string& local_part)
{
    // Проверка длины
    if (local_part.length() < 1 || local_part.length() > 64) {
        return false;
    }
    
    // Проверка первого и последнего символа
    if (local_part[0] == '.' || local_part[local_part.length() - 1] == '.')
    {
        return false;
    }
    
    // Проверка на две точки подряд
    for (size_t i = 0; i < local_part.length() - 1; i++)
    {
        if (local_part[i] == '.' && local_part[i + 1] == '.')
        {
            return false;
        }
    }
    
    // Проверка допустимости символов
    for (char c : local_part)
    {
        if (!is_correct_local_char(c))
        {
            return false;
        }
    }
    
    return true;
}

// Проверка доменной части email-адреса
bool correctate_domain_part(const std::string& domain_part)
{
    // Проверка длины
    if ((domain_part.length() < 1) || (domain_part.length() > 63))
    {
        return false;
    }
    
    // Проверка первого и последнего символа
    if ((domain_part[0] == '.') || (domain_part[domain_part.length() - 1] == '.'))
    {
        return false;
    }
    
    // Проверка на две точки подряд
    for (size_t i = 0; i < domain_part.length() - 1; i++)
    {
        if (domain_part[i] == '.' && domain_part[i + 1] == '.')
        {
            return false;
        }
    }
    
    // Проверка допустимости символов
    for (char c : domain_part)
    {
        if (!is_correct_domain_char(c))
        {
            return false;
        }
    }
    
    return true;
}

// Основная функция проверки email-адреса
bool correctate_email(const std::string& email)
{
    // Проверка наличия символа @
    int at_count = 0;
    for (char c : email) 
    {
        if (c == '@')
        {
            at_count++;
        }
    }
    
    if (at_count != 1)
    {
        return false;
    }
    
    // Получение частей адреса
    std::string local_part = get_local_part(email);
    std::string domain_part = get_domain_part(email);
    
    // Проверка, что обе части не пустые
    if ((local_part.empty()) || (domain_part.empty()))
    {
        return false;
    }
    
    // Валидация частей
    return correctate_local_part(local_part) && correctate_domain_part(domain_part);
}

int main()
{
    std::string email;
    
    std::cout << "Введите почтовый адресс: ";
    std::getline(std::cin, email);
    
    if (correctate_email(email))
    {
        std::cout << "Всё правильно!" << std::endl;
    } else {
        std::cout << "Что-то неправильно!" << std::endl;
    }
    
    return 0;
}