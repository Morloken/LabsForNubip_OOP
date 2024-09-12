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
    Rhombus() : a(0), b(0) {
        cout << "Ромб створений з діагоналями за замовчуванням." << endl;
        cout << "--------------" << endl;
    }

    Rhombus(double a_val, double b_val) : a(a_val), b(b_val) {
        cout << "Ромб створений з діагоналями a: " << a << ", b: " << b << "." << endl;
    }

    ~Rhombus() { // destructor
        cout << "Ромб з діагоналями a: " << a << " і b: " << b << " знищено." << endl;
    }

    void setA(double a_val) { a = a_val; }

    void setB(double b_val) { b = b_val; }

    double getA() const { return a; } // method that doesn't change the value

    double getB() const { return b; } // method that doesn't change the value

    double calculateArea() const {
        return (a * b) / 2;
    }

    void print_sqrt() const {
        cout << "--------------" << endl;
        cout << "Функція print_sqrt() виводить на екран значення: " << endl;
        cout << "Діагональ a: " << a << ", Діагональ b: " << b << endl;
        cout << "Площа ромба: " << calculateArea() << endl;
    }
}; //---------------- end of class Rhombus

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double a_input, b_input;
    cout << "Введіть значення для діагоналі a: ";
    cin >> a_input;
    cout << "Введіть значення для діагоналі b: ";
    cin >> b_input;

    // Покажчик на екземпляр класу
    Rhombus* rhombus_ptr = new Rhombus(a_input, b_input);

    Rhombus rhombus1;
    Rhombus rhombus2(a_input, b_input);

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

    // Виклик функції через покажчик на функцію-член класу
    (rhombus1.*print_ptr)();
    (rhombus2.*print_ptr)();

    // Виклик функції через покажчик на екземпляр класу
    (rhombus_ptr->*print_ptr)();

    // Звільнення пам'яті
    delete rhombus_ptr;

    return 0;
}

