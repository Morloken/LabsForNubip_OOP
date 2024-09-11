#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

class Hourglass {
private:
    double a; // ������
    double b; // ������

public:
    //b) ����������� ��� ��������� (����������� ���������� 0)
    Hourglass() : a(0), b(0) {}

    // ����������� � �����������
    Hourglass(double width, double height) : a(width), b(height) {}

    // ����� ��� ������������ �������
    void setDimensions(double width, double height) {
        a = width;
        b = height;
    }

    //c) ��������� ������
    double getA() const {
        return a;
    }

    //c) ��������� ������
    double getB() const {
        return b;
    }

    //c) ���������� ����� (������ ��������� - ����������)
    double calculateArea() const {
        // ����� ���� ����������, ����� � ������� a � ������� b/2
        return (a * (b / 2)) / 2 * 2; // ����� ���� ����������
    }

    //d) ���� �������
    void print_sqrt() const {
        cout << "������ (a): " << a << endl;
        cout << "������ (b): " << b << endl;
        cout << "����� �������� ���������: " << calculateArea() << endl;
    }

    //e) ������ ������� ��� ��������� ������ ���� ����������
    friend Hourglass frd(const Hourglass& h1, const Hourglass& h2);
};

//e) ����������� ������ ������� ��� ��������� ����� ���� ����������
Hourglass frd(const Hourglass& h1, const Hourglass& h2) {
    double newA = h1.a + h2.a; // ��������� �����
    double newB = h1.b + h2.b; // ��������� �����
    return Hourglass(newA, newB); // ��������� ����� ��������� � ��������� ��������
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    // ��������� ���� ��'���� �������� ���������
    Hourglass hg1(3.0, 4.0); // ������ ���������
    Hourglass hg2(2.0, 5.0); // ������ ���

    //���� ��� ������ ��������
    cout << "\n------------------" << endl;
    cout << "������ ������� ��������:" << endl;
    hg1.print_sqrt();

    // ���� ��� 2��� ��������
    cout << "\n------------------" << endl;
    cout << "������ ������� ��������:" << endl;
    hg2.print_sqrt();

    // ��������� ������ ���� ���������
    Hourglass hg3 = frd(hg1, hg2);

    // ��������� ���������� ��� ������ ���������
    cout << "\n------------------" << endl;
    cout << "ϳ������ �������� ���� ��������� ������:" << endl;
    hg3.print_sqrt();

    return 0;
}
