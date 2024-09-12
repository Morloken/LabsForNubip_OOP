//Варіант 10. Створити клас «ромб»:
// a) його екземпляр містить розміри його діагоналей a і b.
// b) його конструктор без параметра створює екземпляр зі значенням 0, а
// конструктор з параметрами створює екземпляр з відповідним значенням a і b. c)
// його методи дозволяють отримувати і присвоювати значення a, b і обчислювати
// значення площі. d) функція print_sqrt () виводить на екран значення a, b і
// площі цієї фігури.
#include <cmath>
#include <iostream>
#include <windows.h>

using namespace std;

class Rhombus {
private:
    double a;
    double b;

public:
    // Конструктор за замовчуванням
    Rhombus() : a(0), b(0) {
        cout << "Ромб створений з діагоналями за замовчуванням." << endl;
        cout << "--------------" << endl;
    }

    // Конструктор з параметрами
    Rhombus(double a_val, double b_val) {
        this->a = a_val;
        this->b = b_val;
        cout << "Ромб створений з діагоналями a: " << this->a << ", b: " << this->b << "." << endl;
    }

    // Деструктор
    ~Rhombus() {
        cout << "Ромб з діагоналями a: " << this->a << " і b: " << this->b << " знищено." << endl;
    }

    // Сеттер для діагоналі a
    void setA(double a_val) {
        this->a = a_val;  // Використання this для явного доступу до змінної-члена a
    }

    // Сеттер для діагоналі b
    void setB(double b_val) {
        this->b = b_val;  // Використання this для явного доступу до змінної-члена b
    }

    // Геттер для діагоналі a
    double getA() const {
        return this->a;  // Використання this для явного доступу до змінної-члена a
    }

    // Геттер для діагоналі b
    double getB() const {
        return this->b;  // Використання this для явного доступу до змінної-члена b
    }

    // Метод для обчислення площі ромба
    double calculateArea() const {
        return (this->a * this->b) / 2;
    }

    // Метод для виведення інформації на екран
    void print_sqrt() const {
        cout << "--------------" << endl;
        cout << "Функція print_sqrt() виводить на екран значення: " << endl;
        cout << "Діагональ a: " << this->a << ", Діагональ b: " << this->b << endl;
        cout << "Площа ромба: " << this->calculateArea() << endl;
    }
}; //---------------- end of class Rhombus

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double a_input, b_input;

    // Введення користувачем діагоналей a і b
    cout << "Введіть значення для діагоналі a: ";
    cin >> a_input;
    cout << "Введіть значення для діагоналі b: ";
    cin >> b_input;

    // Покажчик на екземпляр класу
    Rhombus* rhombus_ptr = new Rhombus(a_input, b_input);

    // Створення двох об'єктів класу Rhombus
    Rhombus rhombus1;
    Rhombus rhombus2(a_input, b_input);

    // Введення нових значень для rhombus1
    cout << "===================" << endl;
    cout << "Введіть нове значення для діагоналі a: ";
    cin >> a_input;
    rhombus1.setA(a_input);

    cout << "Введіть нове значення для діагоналі b: ";
    cin >> b_input;
    rhombus1.setB(b_input);

    cout << "===================" << endl;

    // Покажчик на функцію-член класу
    void (Rhombus:: * print_ptr)() const = &Rhombus::print_sqrt;

    // Виклик функції через покажчик на функцію-член класу для об'єктів
    (rhombus1.*print_ptr)();
    (rhombus2.*print_ptr)();

    // Виклик функції через покажчик на екземпляр класу
    (rhombus_ptr->*print_ptr)();

    // Звільнення пам'яті для динамічного об'єкта
    delete rhombus_ptr;

    return 0;
}

