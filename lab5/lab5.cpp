#include <iostream>
#include <windows.h>
using namespace std;

#define COUT std::cout
#define ENDL std::endl

class Romb {
private:
    double a, b;

public:
    Romb() { a = b = 0; }
    Romb(double a, double b) { this->a = a; this->b = b; }

    double area();
    Romb& operator++();
    Romb operator++(int);
    Romb& operator--();
    Romb operator--(int);

    Romb operator+(Romb r);
    Romb operator=(Romb r);
    friend ostream& operator<<(ostream& os, const Romb& r);

    double getA() { return a; }
    double getB() { return b; }
    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }

    ~Romb() {}
};

double Romb::area() {
    return a * b / 2.0;
}

Romb& Romb::operator ++ () {
    a++;
    b++;
    return *this;
}

Romb Romb::operator ++ (int) {
    Romb temp = *this;
    a++;
    b++;
    return temp;
}

Romb& Romb::operator -- () {
    if (a > 1 || b > 1) {
        a--;
        b--;
    }
    return *this;
}

Romb Romb::operator -- (int) {
    Romb temp = *this;
    if (a > 1 || b > 1) {
        a--;
        b--;
    }
    return temp;
}

Romb Romb::operator + (Romb r) {
    Romb temp;
    temp.setA(a + r.a);
    temp.setB(b + r.b);
    return temp;
}

Romb Romb::operator=(Romb r) {
    if (this != &r) {
        a = r.a;
        b = r.b;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Romb& r) {
    os << "Romb{a=" << r.a << ",b=" << r.b << "}";
    return os;
}

int main() {

    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Romb romb1(1.0, 2.0);
    Romb romb2(3.0, 3.0);
    Romb romb3(4.0, 5.0);

    // int a = 1, b = 3, c = 2;
    // a += b += c;

    //COUT << a << b << c << ENDL;

    romb1 = romb2 = romb3;
    COUT << &romb1 << "\t" << romb1 << ENDL;
    COUT << &romb2 << "\t" << romb2 << ENDL;
    COUT << &romb3 << "\t" << romb3 << ENDL << ENDL;

    COUT << romb1 + romb2 << ENDL;

    COUT << &romb1 << "\t" << romb1 << ENDL;
    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;

    romb1++;
    romb2++;
    COUT << &romb1 << "\t" << romb1 << ENDL;
    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;

    romb1--;
    romb2--;
    COUT << &romb1 << "\t" << romb1 << ENDL;
    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;

    romb1 = romb2;
    COUT << &romb1 << "\t" << romb1 << ENDL;
    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;
    return 0;
}
//-------------------------------------------------------------------------------with comments
//#include <iostream>    // Підключення бібліотеки для введення-виведення
//#include <windows.h>   // Підключення специфічної для Windows бібліотеки для налаштування кодових сторінок консолі
//using namespace std;    // Використання стандартного простору імен для уникнення постійного використання std::
//
//#define COUT std::cout  // Макрос для спрощення команд виводу
//#define ENDL std::endl  // Макрос для спрощення команди нового рядка
//
//// Оголошення класу 'Romb' (ромб — геометрична фігура)
//class Romb {
//private:
//    double a, b;    // Приватні атрибути 'a' та 'b', що представляють діагоналі ромба
//
//public:
//    // Конструктор за замовчуванням, який ініціалізує 'a' та 'b' значенням 0
//    Romb() { a = b = 0; }
//
//    // Параметризований конструктор для ініціалізації 'a' та 'b' заданими значеннями
//    Romb(double a, double b) { this->a = a; this->b = b; }
//
//    // Метод для обчислення площі ромба (формула: (a*b)/2)
//    double area();
//
//    // Оператор префіксного інкремента (++ перед змінною, збільшує діагоналі 'a' і 'b' на 1)
//    Romb& operator++();
//
//    // Оператор постфіксного інкремента (++ після змінної, збільшує діагоналі 'a' і 'b' на 1 і повертає попереднє значення)
//    Romb operator++(int);
//
//    // Оператор префіксного декремента (-- перед змінною, зменшує діагоналі 'a' і 'b' на 1, але не дозволяє їм стати меншими за 1)
//    Romb& operator--();
//
//    // Оператор постфіксного декремента (-- після змінної, зменшує діагоналі 'a' і 'b' на 1 і повертає попереднє значення)
//    Romb operator--(int);
//
//    // Оператор додавання ромбів (повертає новий ромб з діагоналями, що є сумою відповідних діагоналей двох ромбів)
//    Romb operator+(Romb r);
//
//    // Оператор присвоєння (присвоює значення одного ромба іншому)
//    Romb operator=(Romb r);
//
//    // Дружня функція для перевантаження оператора виведення (<<)
//    friend ostream& operator<<(ostream& os, const Romb& r);
//
//    // Геттери для отримання значень діагоналей
//    double getA() { return a; }
//    double getB() { return b; }
//
//    // Сеттери для встановлення значень діагоналей
//    void setA(double a) { this->a = a; }
//    void setB(double b) { this->b = b; }
//
//    // Деструктор (порожній, оскільки немає спеціальних ресурсів для звільнення)
//    ~Romb() {}
//};
//
//// Метод для обчислення площі ромба
//double Romb::area() {
//    return a * b / 2.0;
//}
//
//// Оператор префіксного інкремента (++ перед змінною)
//Romb& Romb::operator++() {
//    a++;
//    b++;
//    return *this;
//}
//
//// Оператор постфіксного інкремента (++ після змінної)
//Romb Romb::operator++(int) {
//    Romb temp = *this;
//    a++;
//    b++;
//    return temp;
//}
//
//// Оператор префіксного декремента (-- перед змінною)
//Romb& Romb::operator--() {
//    if (a > 1 || b > 1) {
//        a--;
//        b--;
//    }
//    return *this;
//}
//
//// Оператор постфіксного декремента (-- після змінної)
//Romb Romb::operator--(int) {
//    Romb temp = *this;
//    if (a > 1 || b > 1) {
//        a--;
//        b--;
//    }
//    return temp;
//}
//
//// Оператор додавання двох ромбів
//Romb Romb::operator+(Romb r) {
//    Romb temp;
//    temp.setA(a + r.a);
//    temp.setB(b + r.b);
//    return temp;
//}
//
//// Оператор присвоєння одного ромба іншому
//Romb Romb::operator=(Romb r) {
//    if (this != &r) {
//        a = r.a;
//        b = r.b;
//    }
//    return *this;
//}
//
//// Оператор виведення ромба
//ostream& operator<<(ostream& os, const Romb& r) {
//    os << "Romb{a=" << r.a << ",b=" << r.b << "}";
//    return os;
//}
//
//// Головна функція
//int main() {
//    // Налаштування кодової сторінки для коректного відображення тексту в консолі (Windows специфіка)
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//
//    // Створення кількох об'єктів класу Romb
//    Romb romb1(1.0, 2.0);
//    Romb romb2(3.0, 3.0);
//    Romb romb3(4.0, 5.0);
//
//    // Присвоєння об'єктів один одному
//    romb1 = romb2 = romb3;
//
//    // Виведення адрес та значень об'єктів
//    COUT << &romb1 << "\t" << romb1 << ENDL;
//    COUT << &romb2 << "\t" << romb2 << ENDL;
//    COUT << &romb3 << "\t" << romb3 << ENDL << ENDL;
//
//    // Додавання ромбів та виведення результату
//    COUT << romb1 + romb2 << ENDL;
//
//    // Виведення об'єктів після додавання
//    COUT << &romb1 << "\t" << romb1 << ENDL;
//    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;
//
//    // Інкрементування об'єктів
//    romb1++;
//    romb2++;
//    COUT << &romb1 << "\t" << romb1 << ENDL;
//    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;
//
//    // Декрементування об'єктів
//    romb1--;
//    romb2--;
//    COUT << &romb1 << "\t" << romb1 << ENDL;
//    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;
//
//    // Присвоєння об'єктів після декременту
//    romb1 = romb2;
//    COUT << &romb1 << "\t" << romb1 << ENDL;
//    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;
//
//    return 0;
//}
