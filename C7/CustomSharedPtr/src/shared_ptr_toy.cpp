#include <include/shared_ptr_toy.h>

shared_ptr_toy::shared_ptr_toy() 
    : toy_(nullptr)
    , refCount_(nullptr)
{}

shared_ptr_toy::shared_ptr_toy(const std::string& name)
{
    toy_ = new Toy(name);
    refCount_ = new int(1);
}

shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& other)
    : toy_(other.toy_), refCount_(other.refCount_)
{
    if (refCount_ != nullptr)
    {
        ++(*refCount_);
    }
}

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& other)
{
    if (this == &other)
    {
        return *this;
    }

    release();

    toy_ = other.toy_;
    refCount_ = other.refCount_;
    if (refCount_ != nullptr)
    {
        ++(*refCount_);
    }

    return *this;
}

shared_ptr_toy::~shared_ptr_toy()
{
    release();
}

void shared_ptr_toy::reset()
{
    release();
    toy_ = nullptr;
    refCount_ = nullptr;
}

Toy* shared_ptr_toy::get() const
{
    return toy_;
}

int shared_ptr_toy::use_count() const
{
    return refCount_ ? *refCount_ : 0;
}

std::string shared_ptr_toy::getToyName() const
{
    return toy_ ? toy_->GetName() : "Nothing";
}

void shared_ptr_toy::release()
{
    if (refCount_ != nullptr)
    {
        --(*refCount_);
        if (*refCount_ == 0)
        {
            delete toy_;
            delete refCount_;
        }
        toy_ = nullptr;
        refCount_ = nullptr;
    }
}

shared_ptr_toy make_shared_toy(const std::string& name)
{
    return shared_ptr_toy(name);
}
