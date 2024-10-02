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
//#include <iostream>    // ϳ��������� �������� ��� ��������-���������
//#include <windows.h>   // ϳ��������� ���������� ��� Windows �������� ��� ������������ ������� ������� ������
//using namespace std;    // ������������ ������������ �������� ���� ��� ��������� ��������� ������������ std::
//
//#define COUT std::cout  // ������ ��� ��������� ������ ������
//#define ENDL std::endl  // ������ ��� ��������� ������� ������ �����
//
//// ���������� ����� 'Romb' (���� � ����������� ������)
//class Romb {
//private:
//    double a, b;    // ������� �������� 'a' �� 'b', �� ������������� ������� �����
//
//public:
//    // ����������� �� �������������, ���� �������� 'a' �� 'b' ��������� 0
//    Romb() { a = b = 0; }
//
//    // ���������������� ����������� ��� ����������� 'a' �� 'b' �������� ����������
//    Romb(double a, double b) { this->a = a; this->b = b; }
//
//    // ����� ��� ���������� ����� ����� (�������: (a*b)/2)
//    double area();
//
//    // �������� ����������� ���������� (++ ����� ������, ������ ������� 'a' � 'b' �� 1)
//    Romb& operator++();
//
//    // �������� ������������ ���������� (++ ���� �����, ������ ������� 'a' � 'b' �� 1 � ������� �������� ��������)
//    Romb operator++(int);
//
//    // �������� ����������� ���������� (-- ����� ������, ������ ������� 'a' � 'b' �� 1, ��� �� �������� �� ����� ������� �� 1)
//    Romb& operator--();
//
//    // �������� ������������ ���������� (-- ���� �����, ������ ������� 'a' � 'b' �� 1 � ������� �������� ��������)
//    Romb operator--(int);
//
//    // �������� ��������� ����� (������� ����� ���� � ����������, �� � ����� ��������� ��������� ���� �����)
//    Romb operator+(Romb r);
//
//    // �������� ��������� (�������� �������� ������ ����� ������)
//    Romb operator=(Romb r);
//
//    // ������ ������� ��� �������������� ��������� ��������� (<<)
//    friend ostream& operator<<(ostream& os, const Romb& r);
//
//    // ������� ��� ��������� ������� ���������
//    double getA() { return a; }
//    double getB() { return b; }
//
//    // ������� ��� ������������ ������� ���������
//    void setA(double a) { this->a = a; }
//    void setB(double b) { this->b = b; }
//
//    // ���������� (�������, ������� ���� ����������� ������� ��� ���������)
//    ~Romb() {}
//};
//
//// ����� ��� ���������� ����� �����
//double Romb::area() {
//    return a * b / 2.0;
//}
//
//// �������� ����������� ���������� (++ ����� ������)
//Romb& Romb::operator++() {
//    a++;
//    b++;
//    return *this;
//}
//
//// �������� ������������ ���������� (++ ���� �����)
//Romb Romb::operator++(int) {
//    Romb temp = *this;
//    a++;
//    b++;
//    return temp;
//}
//
//// �������� ����������� ���������� (-- ����� ������)
//Romb& Romb::operator--() {
//    if (a > 1 || b > 1) {
//        a--;
//        b--;
//    }
//    return *this;
//}
//
//// �������� ������������ ���������� (-- ���� �����)
//Romb Romb::operator--(int) {
//    Romb temp = *this;
//    if (a > 1 || b > 1) {
//        a--;
//        b--;
//    }
//    return temp;
//}
//
//// �������� ��������� ���� �����
//Romb Romb::operator+(Romb r) {
//    Romb temp;
//    temp.setA(a + r.a);
//    temp.setB(b + r.b);
//    return temp;
//}
//
//// �������� ��������� ������ ����� ������
//Romb Romb::operator=(Romb r) {
//    if (this != &r) {
//        a = r.a;
//        b = r.b;
//    }
//    return *this;
//}
//
//// �������� ��������� �����
//ostream& operator<<(ostream& os, const Romb& r) {
//    os << "Romb{a=" << r.a << ",b=" << r.b << "}";
//    return os;
//}
//
//// ������� �������
//int main() {
//    // ������������ ������ ������� ��� ���������� ����������� ������ � ������ (Windows ���������)
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//
//    // ��������� ������ ��'���� ����� Romb
//    Romb romb1(1.0, 2.0);
//    Romb romb2(3.0, 3.0);
//    Romb romb3(4.0, 5.0);
//
//    // ��������� ��'���� ���� ������
//    romb1 = romb2 = romb3;
//
//    // ��������� ����� �� ������� ��'����
//    COUT << &romb1 << "\t" << romb1 << ENDL;
//    COUT << &romb2 << "\t" << romb2 << ENDL;
//    COUT << &romb3 << "\t" << romb3 << ENDL << ENDL;
//
//    // ��������� ����� �� ��������� ����������
//    COUT << romb1 + romb2 << ENDL;
//
//    // ��������� ��'���� ���� ���������
//    COUT << &romb1 << "\t" << romb1 << ENDL;
//    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;
//
//    // ��������������� ��'����
//    romb1++;
//    romb2++;
//    COUT << &romb1 << "\t" << romb1 << ENDL;
//    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;
//
//    // ��������������� ��'����
//    romb1--;
//    romb2--;
//    COUT << &romb1 << "\t" << romb1 << ENDL;
//    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;
//
//    // ��������� ��'���� ���� ����������
//    romb1 = romb2;
//    COUT << &romb1 << "\t" << romb1 << ENDL;
//    COUT << &romb2 << "\t" << romb2 << ENDL << ENDL;
//
//    return 0;
//}
