#ifndef STRINGIFY_H
#define STRINGIFY_H

#include <string>
#include <sstream>

template<class T>
static inline
std::string stringify(const T& obj)
{
    std::ostringstream iss;
    iss << obj;
    return iss.str();
}

template<class T>
static inline
std::string stringifyPtr(const T* obj)
{
    std::ostringstream iss;
    iss << *obj;
    return iss.str();
}


template<class Container>
static inline
std::string stringifyArr(const Container& container)
{
    std::ostringstream iss;
    iss << "[";
    for (auto& item : container)
    {
        iss << item << ", ";
    }
    iss << "]";
    return iss.str();
}


template<class Container>
static inline
std::string stringifyPtrArr(const Container& container)
{
    std::stringstream iss;
    iss << "[";
    for (auto& pItem : container)
    {
        iss << *pItem << ", ";
    }
    iss << "]";
    return iss.str();
}

#endif // !STRINGIFY_H