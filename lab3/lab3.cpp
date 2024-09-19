#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip> // Для setw
#include <windows.h>

using namespace std;

// Максимальна кількість студентів
const int MAX_STUDENTS = 100;

// Клас для зберігання даних про студентів
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

    // Перевірка, чи є у студента п'ятірка
    bool has_no_five() const {
        return math_grade != 5 && physics_grade != 5 && informatics_grade != 5;
    }
};

// Функція для зчитування студентів з файлу
int read_students_from_file(const string& filename, Student students[]) {
    ifstream file(filename);//взяття інформації з файлу(лише взяття)
    int count = 0;

    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 0;
    }

    string line;
    while (getline(file, line) && count < MAX_STUDENTS) {
        stringstream ss(line);
        /*
        ініціалізація об'єкта класу stringstream з бібліотеки <sstream>, який дозволяє обробляти рядок 
        тексту (line) як потік, схожий на потоки для файлів чи консолі
        */
        string surname, name;
        int math_grade, physics_grade, informatics_grade;

        ss >> surname >> name >> math_grade >> physics_grade >> informatics_grade;
        students[count++] = Student(surname, name, math_grade, physics_grade, informatics_grade);
    }

    file.close();
    return count;
}

// Функція для виведення студентів, що не мають п'ятірок, за алфавітом
void print_students_without_fives(Student students[], int count) {
    // Масив для відфільтрованих студентів
    Student filtered_students[MAX_STUDENTS];
    int filtered_count = 0;

    // Відфільтрувати студентів, що не мають жодної п'ятірки
    for (int i = 0; i < count; ++i) {
        if (students[i].has_no_five()) {
            filtered_students[filtered_count++] = students[i];
        }
    }

    // Сортувати студентів за іменем
    sort(filtered_students, filtered_students + filtered_count, [](const Student& a, const Student& b) {
        return a.name < b.name;
        });

    // Вивести імена студентів та їхні оцінки з вирівнюванням
    cout << left << setw(15) << "Ім'я" << setw(20) << "Прізвище"
    << setw(12) << "Математика" << setw(12) << "Фізика" << "Інформатика" << endl;
    cout << string(65, '-') << endl;  // Розділова лінія

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

    // Масив студентів
    Student students[MAX_STUDENTS];// створення масиву екземплярів класу

    // Зчитуємо студентів з файлу
    int student_count = read_students_from_file(filename, students);

    // Виводимо студентів, що не мають жодної п'ятірки
    print_students_without_fives(students, student_count);

    return 0;
}
