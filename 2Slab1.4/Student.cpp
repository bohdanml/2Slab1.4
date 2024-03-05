#include "Student.h"
#include <iostream>

Student::Student() {}

void Student::Init(std::string lastName, std::string dateOfBirth, std::string phoneNumber) {
    this->lastName = lastName;
    this->dateOfBirth = dateOfBirth;
    this->phoneNumber = phoneNumber;
}

void Student::Read() {
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter date of birth: ";
    std::cin >> dateOfBirth;
    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;
}

void Student::Display() const {
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Date of Birth: " << dateOfBirth << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}

std::string Student::toString() const {
    return "Last Name: " + lastName + "\nDate of Birth: " + dateOfBirth + "\nPhone Number: " + phoneNumber;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getDateOfBirth() const {
    return dateOfBirth;
}

std::string Student::getPhoneNumber() const {
    return phoneNumber;
}