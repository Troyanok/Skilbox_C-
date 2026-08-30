#include <include/phone.h>

PhoneSim::PhoneSim()
    : currentElem_(Contact())
{}

void PhoneSim::AddPhone(const std::string& phone, const std::string& name)
{
    std::cout << "Add phone!" << std::endl;
    phoneList_.push_back(Contact(name, phone));
}

void PhoneSim::CallPhone(const std::string& str)
{
    std::cout << "Call phone!" << std::endl;
    if (!FindPhoneFromList(str))
    {
        std::cout << "Не найден контакт или номер телефона, попробуйте снова!" << std::endl;
        return;
    }

    std::cout << "CALL " << currentElem_.GetPhoneName() << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;
}

void PhoneSim::WriteSms(const std::string& str)
{
    std::cout << "Write sms phone!" << std::endl;
    if (!FindPhoneFromList(str))
    {
        std::cout << "Не найден контакт или номер телефона, попробуйте снова!" << std::endl;
        return;
    }

    std::cout << "Введите сообщение для отправления sms" << std::endl;
    std::string message;
    getline(std::cin, message);

    std::cout << "Получатель " << currentElem_.GetContactName() << " : " << currentElem_.GetPhoneName() << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Сообщение: " << message << std::endl;
    std::cout << std::endl;
}

bool PhoneSim::FindPhoneFromList(const std::string& str)
{
    for (auto elem: phoneList_)
    {
        if ((elem.GetContactName() == str) || (elem.GetPhoneName() == str))
        {
            currentElem_ = elem;
            return true;
        }
    }

    return false;
}
