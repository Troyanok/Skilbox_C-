#include <iostream>
#include <string>

std::string EncryptCaesar(const std::string& text, int shift)
{
   std::string result = "";
   
   // Корректируем сдвиг, чтобы он был в диапазоне 0-25
   shift = shift % 26;

   if (shift < 0)
   {
      shift += 26;  // Обрабатываем отрицательные сдвиги
   }
   
   for (char c : text)
   {
      if (c >= 'A' && c <= 'Z')
      {
         // Шифруем заглавные буквы
         char encrypted = ((c - 'A' + shift) % 26) + 'A';
         result += encrypted;
      }
      else if (c >= 'a' && c <= 'z')
      {
         // Шифруем строчные буквы
         char encrypted = ((c - 'a' + shift) % 26) + 'a';
         result += encrypted;
      }
      else
      {
         // Оставляем другие символы без изменений
         result += c;
      }
   }
   
   return result;
}

int main()
{
   std::string text;
   int shift;
   
   std::cout << "Введите текст: ";
   std::getline(std::cin, text);
   
   std::cout << "Введите значение циклического сдвига: ";
   std::cin >> shift;
   
   std::string encrypted = EncryptCaesar(text, shift);
   std::cout << "Зашифрованный текст: " << encrypted << std::endl;
   
   // Декодирование для проверки
   std::string decrypted = EncryptCaesar(encrypted, -shift);
   std::cout << "Расшифрованный текст: " << decrypted << std::endl;
   
   return 0;
}