#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

bool substr(const char* str, const char* subStr)
{
    if (!str || !subStr)
    {
        return false;
    }

    size_t lenStr = std::strlen(str);
    size_t lenSubStr = std::strlen(subStr);

    if (lenSubStr == 0)
    {
        return true;
    }

    if (lenSubStr > lenStr)
    {
        return false;
    }

    bool match { false };
    for (size_t i = 0; i <= lenStr - lenSubStr; i++)
    {
        match = true;
        for (size_t j = 0; j < lenSubStr; j++)
        {
            if (str[i + j] != subStr[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            return true;
        }
    }
    return match;
}

int main()
{
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";
    cout << std::boolalpha;
    cout << substr(a,b) << " " << substr(a,c);
    return 0;
}
