#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <windows.h>

using namespace std;

// ���� ��� ��������� ����� ��� ��������
class Student {
public:
    string surname;
    string name;
    int math_grade;
    int physics_grade;
    int informatics_grade;

    Student(string s, string n, int mg, int pg, int ig)
        : surname(s), name(n), math_grade(mg), physics_grade(pg), informatics_grade(ig) {}

    // ��������, �� � � �������� �'�����
    bool has_no_five() const {
        return math_grade != 5 && physics_grade != 5 && informatics_grade != 5;
    }
};

// ������� ��� ���������� �������� � �����
vector<Student> read_students_from_file(const string& filename) {
    ifstream file(filename);
    vector<Student> students;

    if (!file.is_open()) {
        cerr << "�� ������� ������� ����!" << endl;
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

// ������� ��� ��������� ��������, �� �� ����� �'�����, �� ��������
void print_students_without_fives(vector<Student>& students) {
    // ³������������ ��������, �� �� ����� ����� �'�����
    vector<Student> filtered_students;
    for (const auto& student : students) {
        if (student.has_no_five()) {
            filtered_students.push_back(student);
        }
    }

    // ��������� �������� �� ������
    sort(filtered_students.begin(), filtered_students.end(), [](const Student& a, const Student& b) {
        return a.name < b.name;
        });

    // ������� ����� ��������
    cout << "��������, �� �� ����� ����� �'�����:" << endl;
    for (const auto& student : filtered_students) {
        cout << student.name << " " << student.surname << endl;
    }
}

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    string filename = "C:\\User\\user1\Documents\GitHub\LabsForNubip_OOP\lab3\x64\Debug";

    // ������� �������� � �����
    vector<Student> students = read_students_from_file(filename);

    // �������� ��������, �� �� ����� ����� �'�����
    print_students_without_fives(students);

    return 0;
}
