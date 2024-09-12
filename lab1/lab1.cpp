//������ 10. �������� ���� �����:
// a) ���� ��������� ������ ������ ���� ��������� a � b.
// b) ���� ����������� ��� ��������� ������� ��������� � ��������� 0, �
// ����������� � ����������� ������� ��������� � ��������� ��������� a � b. c)
// ���� ������ ���������� ���������� � ����������� �������� a, b � �����������
// �������� �����. d) ������� print_sqrt () �������� �� ����� �������� a, b �
// ����� ���� ������.
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
        cout << "���� ��������� � ���������� �� �������������." << endl;
        cout << "--------------" << endl;
    }

    Rhombus(double a_val, double b_val) : a(a_val), b(b_val) {
        cout << "���� ��������� � ���������� a: " << a << ", b: " << b << "." << endl;
    }

    ~Rhombus() { // destructor
        cout << "���� � ���������� a: " << a << " � b: " << b << " �������." << endl;
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
        cout << "������� print_sqrt() �������� �� ����� ��������: " << endl;
        cout << "ĳ������� a: " << a << ", ĳ������� b: " << b << endl;
        cout << "����� �����: " << calculateArea() << endl;
    }
}; //---------------- end of class Rhombus

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double a_input, b_input;
    cout << "������ �������� ��� ������� a: ";
    cin >> a_input;
    cout << "������ �������� ��� ������� b: ";
    cin >> b_input;

    // �������� �� ��������� �����
    Rhombus* rhombus_ptr = new Rhombus(a_input, b_input);

    Rhombus rhombus1;
    Rhombus rhombus2(a_input, b_input);

    cout << "===================" << endl;
    cout << "������ ���� �������� ��� ������� a: ";
    cin >> a_input;
    rhombus1.setA(a_input);

    cout << "������ ���� �������� ��� ������� b: ";
    cin >> b_input;
    rhombus1.setB(b_input);

    cout << "===================" << endl;

    // �������� �� �������-���� �����
    void (Rhombus:: * print_ptr)() const = &Rhombus::print_sqrt;

    // ������ ������� ����� �������� �� �������-���� �����
    (rhombus1.*print_ptr)();
    (rhombus2.*print_ptr)();

    // ������ ������� ����� �������� �� ��������� �����
    (rhombus_ptr->*print_ptr)();

    // ��������� ���'��
    delete rhombus_ptr;

    return 0;
}

