#include <include/contact.h>

Contact::Contact()
    : name_("")
    , phone_("")
{};

Contact::Contact(const std::string& name, const std::string& phone)
    : name_(name)
    , phone_(phone)
{};

std::string Contact::GetContactName() const
{
    return name_;
}

std::string Contact::GetPhoneName() const
{
    return phone_;
}
