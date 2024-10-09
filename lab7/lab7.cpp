#include <iostream>
#include <vector>
#include <cmath>


#define M_PI 3.14159265358979323846

using namespace std;

// Абстрактний клас опору
class Resistance {
public:
    virtual double calculateResistance() const = 0; // Чисто віртуальна функція
    virtual ~Resistance() {}
};

// Клас активного опору
class ActiveResistance : public Resistance {
    double resistivity; // питомий опір
    double length; // довжина провідника
    double area; // площа поперечного перерізу

public:
    ActiveResistance(double r, double l, double s) : resistivity(r), length(l), area(s) {}

    double calculateResistance() const override {
        return (resistivity * length) / area;
    }
};

// Клас ємнісного опору
class CapacitiveResistance : public Resistance {
    double frequency; // частота
    double capacitance; // ємність

public:
    CapacitiveResistance(double f, double c) : frequency(f), capacitance(c) {}

    double calculateResistance() const override {
        return 1 / (2 * M_PI * frequency * capacitance);
    }
};

// Клас індуктивного опору
class InductiveResistance : public Resistance {
    double frequency; // частота
    double inductance; // індуктивність

public:
    InductiveResistance(double f, double l) : frequency(f), inductance(l) {}

    double calculateResistance() const override {
        return 2 * M_PI * frequency * inductance;
    }
};

// Демонстраційна програма
int main() {
    vector<Resistance*> resistances;

    // Створення об'єктів кожного типу опору
    resistances.push_back(new ActiveResistance(1.68, 2.0, 0.001)); // Активний опір
    resistances.push_back(new CapacitiveResistance(50, 0.000001)); // Ємнісний опір
    resistances.push_back(new InductiveResistance(50, 0.01)); // Індуктивний опір

    // Виклик поліморфної функції
    for (const auto& res : resistances) {
        cout << "Resistance: " << res->calculateResistance() << " ohms" << endl;
    }

    // Очищення пам'яті
    for (auto& res : resistances) {
        delete res;
    }

    return 0;
}
