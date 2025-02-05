/**
 * @file StudentManager.cpp
 * @brief Implementation file for the StudentManager class.
 * 
 * This file contains the implementation of the StudentManager class,
 * which provides methods for managing student data.
 * 
 * @author Your Name
 * @date 2025-01-28
 * @version 1.0
 */

#include "StudentManager.h"
#include <iostream>
#include <algorithm>

// Adds a student to the system.
bool StudentManager::addStudent(const std::string& name, int id, double grade) {
    // Check if a student with the same ID already exists.
    auto it = std::find_if(students.begin(), students.end(), [id](const Student& student) {
        return student.id == id;
    });

    if (it != students.end()) {
        std::cerr << "Student with ID " << id << " already exists.\n";
        return false;
    }

    students.push_back({name, id, grade});
    return true;
}

// Removes a student from the system.
bool StudentManager::removeStudent(int id) {
    auto it = std::remove_if(students.begin(), students.end(), [id](const Student& student) {
        return student.id == id;
    });

    if (it != students.end()) {
        students.erase(it, students.end());
        return true;
    }

    std::cerr << "Student with ID " << id << " not found.\n";
    return false;
}

// Displays all student information.
void StudentManager::displayStudents() const {
    if (students.empty()) {
        std::cout << "No students available in the system.\n";
        return;
    }

    std::cout << "Student List:\n";
    for (const auto& student : students) {
        std::cout << "ID: " << student.id << ", Name: " << student.name 
                  << ", Grade: " << student.grade << '\n';
    }
}
