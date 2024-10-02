#include <iostream>
#include <cmath>  // Для математичних операцій
#include <windows.h>
using namespace std;

class Rhombus {
private:
    double a;  // Перша діагональ
    double b;  // Друга діагональ

public:
    // Конструктор без параметрів
    Rhombus() : a(0), b(0) {}

    // Конструктор з параметрами
    Rhombus(double a, double b) : a(a), b(b) {}

    // Геттери для отримання значень a і b
    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    // Сеттери для присвоєння значень a і b
    void setA(double a) {
        this->a = a;
    }

    void setB(double b) {
        this->b = b;
    }

    // Метод для обчислення площі ромба
    double area() const {
        return (a * b) / 2;
    }

    // Перевантаження оператора <<
    friend ostream& operator<<(ostream& out, const Rhombus& r) {
        out << "Діагональ a: " << r.a << ", Діагональ b: " << r.b
            << ", Площа: " << r.area() << endl;
        return out;
    }

    // Перевантаження оператора +
    Rhombus operator+(const Rhombus& other) {
        return Rhombus(a + other.a, b + other.b);
    }

    // Перевантаження оператора ++ (префіксний варіант)
    Rhombus& operator++() {
        ++a;
        ++b;
        return *this;
    }

    // Перевантаження оператора ++ (постфіксний варіант)
    Rhombus operator++(int) {
        Rhombus temp = *this;  // Створюємо тимчасовий об'єкт
        ++(*this);  // Викликаємо префіксний оператор
        return temp;
    }
};

int main() {

    // Налаштування кодування для консолі
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);



    // Створення екземпляра ромба за замовчуванням
    Rhombus r1;
    cout << r1;

    // Створення екземпляра ромба з заданими діагоналями
    Rhombus r2(6, 8);
    cout << r2;

    // Використання перевантаженого оператора <<
    cout << "Ромб 2: " << r2;

    // Використання перевантаженого оператора +
    Rhombus r3 = r1 + r2;
    cout << "Ромб 3 (результат додавання): " << r3;

    // Використання перевантаженого оператора ++
    ++r3;
    cout << "Ромб 3 після ++: " << r3;

    // Використання постфіксного ++
    r3++;
    cout << "Ромб 3 після постфіксного ++: " << r3;

    return 0;
}
