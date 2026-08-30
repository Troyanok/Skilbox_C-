#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Функция для получения отдельных октетов IP-адреса
std::vector<std::string> GetOctets(const std::string& ip_address)
{
    std::vector<std::string> octets;
    std::string current_octet = "";
    
    for (char c : ip_address)
    {
        if (c == '.')
        {
            if (!current_octet.empty())
            {
                octets.push_back(current_octet);
                current_octet = "";
            }
        }
        else
        {
            current_octet += c;
        }
    }
    
    // Добавляем последний октет
    if (!current_octet.empty())
    {
        octets.push_back(current_octet);
    }
    
    return octets;
}

// Проверка, является ли строка числом
bool IsNumber(const std::string& str)
{
    if (str.empty())
    {
        return false;
    }
        
    for (char c : str)
    {
        if ((c < '0') || (c > '9'))
        {
            return false;
        }
    }
    return true;
}

// Проверка октета
bool ValidateOctet(const std::string& octet)
{
    // Проверка, что строка состоит только из цифр
    if (!IsNumber(octet))
    {
        return false;
    }
    
    // Проверка на ведущие нули
    if ((octet.length() > 1) && (octet[0] == '0'))
    {
        return false;
    }
    
    // Преобразование в число
    int num = std::stoi(octet);
    
    // Проверка диапазона
    if ((num < 0) || (num > 255))
    {
        return false;
    }
    
    return true;
}

// Основная функция проверки IP-адреса
bool ValidateIpAddress(const std::string& ip_address)
{
    // Проверка на наличие посторонних символов
    for (char c : ip_address)
    {
        if (!((c >= '0' && c <= '9') || c == '.'))
        {
            return false;
        }
    }
    
    // Получение октетов
    std::vector<std::string> octets = GetOctets(ip_address);
    
    // Проверка количества октетов
    if (octets.size() != 4)
    {
        return false;
    }
    
    // Проверка на двойные точки
    for (size_t i = 0; i < ip_address.length() - 1; i++)
    {
        if ((ip_address[i] == '.') && (ip_address[i + 1] == '.'))
        {
            return false;
        }
    }
    
    // Проверка первой и последней точки
    if ((ip_address[0] == '.') || (ip_address[ip_address.length() - 1] == '.'))
    {
        return false;
    }
    
    // Проверка каждого октета
    for (const std::string& octet : octets)
    {
        if (!ValidateOctet(octet))
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    std::string ip_address;
    
    std::cout << "Введите IP-адресс: ";
    std::getline(std::cin, ip_address);
    
    if (ValidateIpAddress(ip_address))
    {
        std::cout << "Всё корректно!" << std::endl;
    }
    else
    {
        std::cout << "Не всё корректно!" << std::endl;
    }
    
    return 0;
}