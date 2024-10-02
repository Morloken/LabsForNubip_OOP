#include <iostream>
#include <cmath>  // ��� ������������ ��������
#include <windows.h>
using namespace std;

class Rhombus {
private:
    double a;  // ����� ��������
    double b;  // ����� ��������

public:
    // ����������� ��� ���������
    Rhombus() : a(0), b(0) {}

    // ����������� � �����������
    Rhombus(double a, double b) : a(a), b(b) {}

    // ������� ��� ��������� ������� a � b
    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    // ������� ��� ��������� ������� a � b
    void setA(double a) {
        this->a = a;
    }

    void setB(double b) {
        this->b = b;
    }

    // ����� ��� ���������� ����� �����
    double area() const {
        return (a * b) / 2;
    }

    // �������������� ��������� <<
    friend ostream& operator<<(ostream& out, const Rhombus& r) {
        out << "ĳ������� a: " << r.a << ", ĳ������� b: " << r.b
            << ", �����: " << r.area() << endl;
        return out;
    }

    // �������������� ��������� +
    Rhombus operator+(const Rhombus& other) {
        return Rhombus(a + other.a, b + other.b);
    }

    // �������������� ��������� ++ (���������� ������)
    Rhombus& operator++() {
        ++a;
        ++b;
        return *this;
    }

    // �������������� ��������� ++ (����������� ������)
    Rhombus operator++(int) {
        Rhombus temp = *this;  // ��������� ���������� ��'���
        ++(*this);  // ��������� ���������� ��������
        return temp;
    }
};

int main() {

    // ������������ ��������� ��� ������
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);



    // ��������� ���������� ����� �� �������������
    Rhombus r1;
    cout << r1;

    // ��������� ���������� ����� � �������� ����������
    Rhombus r2(6, 8);
    cout << r2;

    // ������������ ��������������� ��������� <<
    cout << "���� 2: " << r2;

    // ������������ ��������������� ��������� +
    Rhombus r3 = r1 + r2;
    cout << "���� 3 (��������� ���������): " << r3;

    // ������������ ��������������� ��������� ++
    ++r3;
    cout << "���� 3 ���� ++: " << r3;

    // ������������ ������������ ++
    r3++;
    cout << "���� 3 ���� ������������ ++: " << r3;

    return 0;
}
