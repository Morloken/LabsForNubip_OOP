#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>

#define M_PI 3.14159265358979323846

using namespace std;

// ����������� ���� �����
class Resistance {
public:
    virtual double calculateResistance() const = 0; // ����� ��������� �������
    virtual void showType() const = 0;              // ������ ������� ��� ��������� ���� �����
    virtual ~Resistance() {}
};

// ���� ��������� �����
class ActiveResistance : public Resistance {
    double resistivity; // ������� ���
    double length;      // ������� ���������
    double area;        // ����� ����������� �������

public:
    ActiveResistance(double r, double l, double s) : resistivity(r), length(l), area(s) {}

    double calculateResistance() const override {
        return (resistivity * length) / area;
    }

    void showType() const override {
        cout << "��� �����: ��������" << endl;
    }
};

// ���� �������� �����
class CapacitiveResistance : public Resistance {
    double frequency;   // �������
    double capacitance; // ������

public:
    CapacitiveResistance(double f, double c) : frequency(f), capacitance(c) {}

    double calculateResistance() const override {
        return 1 / (2 * M_PI * frequency * capacitance);
    }

    void showType() const override {
        cout << "��� �����: �������" << endl;
    }
};

// ���� ������������ �����
class InductiveResistance : public Resistance {
    double frequency;  // �������
    double inductance; // ������������

public:
    InductiveResistance(double f, double l) : frequency(f), inductance(l) {}

    double calculateResistance() const override {
        return 2 * M_PI * frequency * inductance;
    }

    void showType() const override {
        cout << "��� �����: �����������" << endl;
    }
};

// �������������� ��������
int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<Resistance*> resistances;

    // ��������� ��'���� ������� ���� ����� ��� ������������ �����
    resistances.push_back(new ActiveResistance(1.68, 2.0, 0.001)); // �������� ���
    resistances.push_back(new CapacitiveResistance(50, 0.000001)); // ������� ���
    resistances.push_back(new InductiveResistance(50, 0.01));      // ����������� ���

    // ������ ��������� ������� ��� ������������ �����
    cout << "����������� ����:" << endl;
    for (const Resistance* res : resistances) {
        res->showType(); // ��������� ���� �����
        cout << "Resistance: " << res->calculateResistance() << " ohms" << endl;
    }

    // �������� ���'�� ��� ������������ �����
    for (Resistance* res : resistances) {
        delete res;
    }

    return 0;
}
