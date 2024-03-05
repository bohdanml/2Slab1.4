#include <iostream>
#include "Student.h"
#include <vector>
#include <algorithm>

class StudentGroup {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student);
    void removeStudent(const std::string& lastName);
    Student* findStudent(const std::string& lastName);
    void sortStudentsByLastName();
    void sortStudentsByDateOfBirth();
    void sortStudentsByPhoneNumber();
    void displayAllStudents() const;
};

void StudentGroup::addStudent(const Student& student) {
    students.push_back(student);
}

void StudentGroup::removeStudent(const std::string& lastName) {
    students.erase(std::remove_if(students.begin(), students.end(), [&lastName](const Student& s) {
        return s.getLastName() == lastName;
        }), students.end());
}

Student* StudentGroup::findStudent(const std::string& lastName) {
    auto it = std::find_if(students.begin(), students.end(), [&lastName](const Student& s) {
        return s.getLastName() == lastName;
        });
    if (it != students.end())
        return &(*it);
    return nullptr;
}

void StudentGroup::sortStudentsByLastName() {
    std::sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.getLastName() < s2.getLastName();
        });
}

void StudentGroup::sortStudentsByDateOfBirth() {
    std::sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.getDateOfBirth() < s2.getDateOfBirth();
        });
}

void StudentGroup::sortStudentsByPhoneNumber() {
    std::sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.getPhoneNumber() < s2.getPhoneNumber();
        });
}

void StudentGroup::displayAllStudents() const {
    for (const auto& student : students) {
        student.Display();
        std::cout << std::endl;
    }
}

int main() {
    StudentGroup group;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Remove Student" << std::endl;
        std::cout << "3. Find Student" << std::endl;
        std::cout << "4. Sort Students by Last Name" << std::endl;
        std::cout << "5. Sort Students by Date of Birth" << std::endl;
        std::cout << "6. Sort Students by Phone Number" << std::endl;
        std::cout << "7. Display All Students" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Student student;
            student.Read();
            group.addStudent(student);
            break;
        }
        case 2: {
            std::string lastName;
            std::cout << "Enter last name of student to remove: ";
            std::cin >> lastName;
            group.removeStudent(lastName);
            break;
        }
        case 3: {
            std::string searchLastName;
            std::cout << "Enter last name to search: ";
            std::cin >> searchLastName;
            Student* foundStudent = group.findStudent(searchLastName);
            if (foundStudent != nullptr) {
                std::cout << "Found student:" << std::endl;
                foundStudent->Display();
            }
            else {
                std::cout << "Student not found." << std::endl;
            }
            break;
        }
        case 4:
            group.sortStudentsByLastName();
            std::cout << "Students sorted by last name:" << std::endl;
            group.displayAllStudents();
            break;
        case 5:
            group.sortStudentsByDateOfBirth();
            std::cout << "Students sorted by date of birth:" << std::endl;
            group.displayAllStudents();
            break;
        case 6:
            group.sortStudentsByPhoneNumber();
            std::cout << "Students sorted by phone number:" << std::endl;
            group.displayAllStudents();
            break;
        case 7:
            std::cout << "All students:" << std::endl;
            group.displayAllStudents();
            break;
        case 8:
            std::cout << "Exiting program." << std::endl;
            return 0;
        default:
            std::cout << "Eror. Please try again." << std::endl;
        }
    }

    return 0;
}
