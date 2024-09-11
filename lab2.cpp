#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

class Hourglass {
private:
    double a; // Ширина
    double b; // Висота

public:
    // Конструктор без параметрів (ініціалізація значеннями 0)
    Hourglass() : a(0), b(0) {}

    // Конструктор з параметрами
    Hourglass(double width, double height) : a(width), b(height) {}

    // Метод для встановлення значень
    void setDimensions(double width, double height) {
        a = width;
        b = height;
    }

    // Метод для отримання ширини
    double getA() const {
        return a;
    }

    // Метод для отримання висоти
    double getB() const {
        return b;
    }

    // Метод для обчислення площі (основа годинника - це трикутники)
    double calculateArea() const {
        // Площа двох трикутників, кожен з основою a і висотою b/2
        return (a * (b / 2)) / 2 * 2; // Площа двох трикутників
    }

    // Метод для виводу значень
    void print_sqrt() const {
        cout << "Ширина (a): " << a << endl;
        cout << "Висота (b): " << b << endl;
        cout << "Площа пісочного годинника: " << calculateArea() << endl;
    }

    // Дружня функція для додавання розмірів двох екземплярів
    friend Hourglass frd(const Hourglass& h1, const Hourglass& h2);
};

// Дружня функція для додавання сторін двох екземплярів
Hourglass frd(const Hourglass& h1, const Hourglass& h2) {
    double newA = h1.a + h2.a; // Додавання ширин
    double newB = h1.b + h2.b; // Додавання висот
    return Hourglass(newA, newB); // Створюємо новий екземпляр з сумарними розмірами
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Створення двох об'єктів пісочного годинника
    Hourglass hg1(3.0, 4.0); // Перший екземпляр
    Hourglass hg2(2.0, 5.0); // Другий екземпляр

    // Виведення інформації про перший годинник
    cout << "Перший пісочний годинник:" << endl;
    hg1.print_sqrt();

    // Виведення інформації про другий годинник
    cout << "Другий пісочний годинник:" << endl;
    hg2.print_sqrt();

    // Додавання розмірів двох годинників
    Hourglass hg3 = frd(hg1, hg2);

    // Виведення результатів для нового годинника
    cout << "Пісочний годинник після додавання розмірів:" << endl;
    hg3.print_sqrt();

    return 0;
}
