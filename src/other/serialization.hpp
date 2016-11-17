#ifndef SERIALIZATION_HPP_
#define SERIALIZATION_HPP_

#include <iostream>
#include <string>
#include <map>
#include <memory>

class Serializable
{
public:
    Serializable() {}
    virtual ~Serializable() {}

    virtual std::string toString()
    {
        return std::string();
    }
};

template<typename T>
class SerializableTemplate : public Serializable
{
public:
    SerializableTemplate(T value) : m_value(value) {}
    virtual ~SerializableTemplate() {}

    virtual std::string toString()
    {
        return std::to_string(m_value);
    }

protected:
    T m_value;
};

struct ExampleStruct
{
    int intVal;
    std::string strVal;
};

template<>
class SerializableTemplate<ExampleStruct> : public Serializable
{
public:
    SerializableTemplate(ExampleStruct value) : m_value(value) {}
    virtual ~SerializableTemplate() {}

    virtual std::string toString()
    {
        return std::to_string(m_value.intVal) + ", " + m_value.strVal;
    }

protected:
    ExampleStruct m_value;
};

void Start()
{
    std::shared_ptr<Serializable> firstSer(new SerializableTemplate<int>(56));

    ExampleStruct exStruct;
    exStruct.intVal = 42;
    exStruct.strVal = std::string("this is the string");
    std::shared_ptr<Serializable> secondSer(new SerializableTemplate<ExampleStruct>(exStruct));

    std::map<std::string, std::shared_ptr<Serializable>> serMap;
    serMap["one"] = firstSer;
    serMap["two"] = secondSer;

    for (auto& item : serMap)
    {
        std::cout << item.first << ": " << item.second->toString() << std::endl;
    }
}

#endif /* SERIALIZATION_HPP_ */
