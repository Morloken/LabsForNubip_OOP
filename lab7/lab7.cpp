#include <iostream>
#include <vector>
#include <cmath>


#define M_PI 3.14159265358979323846

using namespace std;

// ����������� ���� �����
class Resistance {
public:
    virtual double calculateResistance() const = 0; // ����� ��������� �������
    virtual ~Resistance() {}
};

// ���� ��������� �����
class ActiveResistance : public Resistance {
    double resistivity; // ������� ���
    double length; // ������� ���������
    double area; // ����� ����������� �������

public:
    ActiveResistance(double r, double l, double s) : resistivity(r), length(l), area(s) {}

    double calculateResistance() const override {
        return (resistivity * length) / area;
    }
};

// ���� �������� �����
class CapacitiveResistance : public Resistance {
    double frequency; // �������
    double capacitance; // ������

public:
    CapacitiveResistance(double f, double c) : frequency(f), capacitance(c) {}

    double calculateResistance() const override {
        return 1 / (2 * M_PI * frequency * capacitance);
    }
};

// ���� ������������ �����
class InductiveResistance : public Resistance {
    double frequency; // �������
    double inductance; // ������������

public:
    InductiveResistance(double f, double l) : frequency(f), inductance(l) {}

    double calculateResistance() const override {
        return 2 * M_PI * frequency * inductance;
    }
};

// �������������� ��������
int main() {
    vector<Resistance*> resistances;

    // ��������� ��'���� ������� ���� �����
    resistances.push_back(new ActiveResistance(1.68, 2.0, 0.001)); // �������� ���
    resistances.push_back(new CapacitiveResistance(50, 0.000001)); // ������� ���
    resistances.push_back(new InductiveResistance(50, 0.01)); // ����������� ���

    // ������ ��������� �������
    for (const auto& res : resistances) {
        cout << "Resistance: " << res->calculateResistance() << " ohms" << endl;
    }

    // �������� ���'��
    for (auto& res : resistances) {
        delete res;
    }

    return 0;
}
