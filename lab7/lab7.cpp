#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>

#define M_PI 3.14159265358979323846

using namespace std;

// Абстрактний клас опору
class Resistance {
public:
    virtual double calculateResistance() const = 0; // Чисто віртуальна функція
    virtual void showType() const = 0;              // Додаємо функцію для виведення типу опору
    virtual ~Resistance() {}
};

// Клас активного опору
class ActiveResistance : public Resistance {
    double resistivity; // питомий опір
    double length;      // довжина провідника
    double area;        // площа поперечного перерізу

public:
    ActiveResistance(double r, double l, double s) : resistivity(r), length(l), area(s) {}

    double calculateResistance() const override {
        return (resistivity * length) / area;
    }

    void showType() const override {
        cout << "Тип опору: Активний" << endl;
    }
};

// Клас ємнісного опору
class CapacitiveResistance : public Resistance {
    double frequency;   // частота
    double capacitance; // ємність

public:
    CapacitiveResistance(double f, double c) : frequency(f), capacitance(c) {}

    double calculateResistance() const override {
        return 1 / (2 * M_PI * frequency * capacitance);
    }

    void showType() const override {
        cout << "Тип опору: Ємнісний" << endl;
    }
};

// Клас індуктивного опору
class InductiveResistance : public Resistance {
    double frequency;  // частота
    double inductance; // індуктивність

public:
    InductiveResistance(double f, double l) : frequency(f), inductance(l) {}

    double calculateResistance() const override {
        return 2 * M_PI * frequency * inductance;
    }

    void showType() const override {
        cout << "Тип опору: Індуктивний" << endl;
    }
};

// Демонстраційна програма
int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<Resistance*> resistances;

    // Створення об'єктів кожного типу опору для абстрактного класу
    resistances.push_back(new ActiveResistance(1.68, 2.0, 0.001)); // Активний опір
    resistances.push_back(new CapacitiveResistance(50, 0.000001)); // Ємнісний опір
    resistances.push_back(new InductiveResistance(50, 0.01));      // Індуктивний опір

    // Виклик поліморфної функції для абстрактного класу
    cout << "Абстрактний клас:" << endl;
    for (const Resistance* res : resistances) {
        res->showType(); // Виведення типу опору
        cout << "Resistance: " << res->calculateResistance() << " ohms" << endl;
    }

    // Очищення пам'яті для абстрактного класу
    for (Resistance* res : resistances) {
        delete res;
    }

    return 0;
}
