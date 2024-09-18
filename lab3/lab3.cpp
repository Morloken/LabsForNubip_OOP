#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <windows.h>

using namespace std;

// Клас для зберігання даних про студентів
class Student {
public:
    string surname;
    string name;
    int math_grade;
    int physics_grade;
    int informatics_grade;

    Student(string s, string n, int mg, int pg, int ig)
        : surname(s), name(n), math_grade(mg), physics_grade(pg), informatics_grade(ig) {}

    // Перевірка, чи є у студента п'ятірка
    bool has_no_five() const {
        return math_grade != 5 && physics_grade != 5 && informatics_grade != 5;
    }
};

// Функція для зчитування студентів з файлу
vector<Student> read_students_from_file(const string& filename) {
    ifstream file(filename);
    vector<Student> students;

    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return students;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string surname, name;
        int math_grade, physics_grade, informatics_grade;

        ss >> surname >> name >> math_grade >> physics_grade >> informatics_grade;
        students.push_back(Student(surname, name, math_grade, physics_grade, informatics_grade));
    }

    file.close();
    return students;
}

// Функція для виведення студентів, що не мають п'ятірок, за алфавітом
void print_students_without_fives(vector<Student>& students) {
    // Відфільтрувати студентів, що не мають жодної п'ятірки
    vector<Student> filtered_students;
    for (const auto& student : students) {
        if (student.has_no_five()) {
            filtered_students.push_back(student);
        }
    }

    // Сортувати студентів за іменем
    sort(filtered_students.begin(), filtered_students.end(), [](const Student& a, const Student& b) {
        return a.name < b.name;
        });

    // Вивести імена студентів
    cout << "Студенти, що не мають жодної п'ятірки:" << endl;
    for (const auto& student : filtered_students) {
        cout << student.name << " " << student.surname << endl;
    }
}

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    string filename = "C:\\User\\user1\Documents\GitHub\LabsForNubip_OOP\lab3\x64\Debug";

    // Зчитуємо студентів з файлу
    vector<Student> students = read_students_from_file(filename);

    // Виводимо студентів, що не мають жодної п'ятірки
    print_students_without_fives(students);

    return 0;
}
