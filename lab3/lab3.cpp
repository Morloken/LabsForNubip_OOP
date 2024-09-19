#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip> // ��� setw
#include <windows.h>

using namespace std;

// ����������� ������� ��������
const int MAX_STUDENTS = 100;

// ���� ��� ��������� ����� ��� ��������
class Student {
public:
    string surname;
    string name;
    int math_grade;
    int physics_grade;
    int informatics_grade;

    Student() {}
    Student(string s, string n, int mg, int pg, int ig)
        : surname(s), name(n), math_grade(mg), physics_grade(pg), informatics_grade(ig) {}

    // ��������, �� � � �������� �'�����
    bool has_no_five() const {
        return math_grade != 5 && physics_grade != 5 && informatics_grade != 5;
    }
};

// ������� ��� ���������� �������� � �����
int read_students_from_file(const string& filename, Student students[]) {
    ifstream file(filename);//������ ���������� � �����(���� ������)
    int count = 0;

    if (!file.is_open()) {
        cerr << "�� ������� ������� ����!" << endl;
        return 0;
    }

    string line;
    while (getline(file, line) && count < MAX_STUDENTS) {
        stringstream ss(line);
        /*
        ����������� ��'���� ����� stringstream � �������� <sstream>, ���� �������� ��������� ����� 
        ������ (line) �� ����, ������ �� ������ ��� ����� �� ������
        */
        string surname, name;
        int math_grade, physics_grade, informatics_grade;

        ss >> surname >> name >> math_grade >> physics_grade >> informatics_grade;
        students[count++] = Student(surname, name, math_grade, physics_grade, informatics_grade);
    }

    file.close();
    return count;
}

// ������� ��� ��������� ��������, �� �� ����� �'�����, �� ��������
void print_students_without_fives(Student students[], int count) {
    // ����� ��� �������������� ��������
    Student filtered_students[MAX_STUDENTS];
    int filtered_count = 0;

    // ³������������ ��������, �� �� ����� ����� �'�����
    for (int i = 0; i < count; ++i) {
        if (students[i].has_no_five()) {
            filtered_students[filtered_count++] = students[i];
        }
    }

    // ��������� �������� �� ������
    sort(filtered_students, filtered_students + filtered_count, [](const Student& a, const Student& b) {
        return a.name < b.name;
        });

    // ������� ����� �������� �� ��� ������ � ������������
    cout << left << setw(15) << "��'�" << setw(20) << "�������"
    << setw(12) << "����������" << setw(12) << "Գ����" << "�����������" << endl;
    cout << string(65, '-') << endl;  // �������� ���

    for (int i = 0; i < filtered_count; ++i) {
        cout << left << setw(15) << filtered_students[i].name
            << setw(20) << filtered_students[i].surname
            << setw(12) << filtered_students[i].math_grade
            << setw(12) << filtered_students[i].physics_grade
            << filtered_students[i].informatics_grade << endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string filename = "data.txt";

    // ����� ��������
    Student students[MAX_STUDENTS];// ��������� ������ ���������� �����

    // ������� �������� � �����
    int student_count = read_students_from_file(filename, students);

    // �������� ��������, �� �� ����� ����� �'�����
    print_students_without_fives(students, student_count);

    return 0;
}
