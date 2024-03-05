#pragma once

#include <string>

class Student {
private:
    std::string lastName;
    std::string dateOfBirth;
    std::string phoneNumber;

public:
    Student();
    void Init(std::string lastName, std::string dateOfBirth, std::string phoneNumber);
    void Read();
    void Display() const;
    std::string toString() const;
    std::string getLastName() const;
    std::string getDateOfBirth() const;
    std::string getPhoneNumber() const;
};