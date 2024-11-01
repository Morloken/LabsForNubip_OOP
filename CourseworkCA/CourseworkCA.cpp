#define NOMINMAX
#include <windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <limits>
#include <map>

using namespace std;

// Прототип функції для вибору типу літака
string selectAirplaneType();

class Airplane {
private:
    string type;
    int passengerCount;
    double range;
    double fuelConsumption;
    double ticketPrice;

public:
    Airplane(const string& type, int passengerCount, double range, double fuelConsumption, double ticketPrice)
        : type(type), passengerCount(passengerCount), range(range), fuelConsumption(fuelConsumption), ticketPrice(ticketPrice) {}

    double calculateFuelPerPassengerPerDistance() const {
        return (fuelConsumption / range) / passengerCount;
    }

    string getType() const { return type; }
    int getPassengerCount() const { return passengerCount; }
    double getRange() const { return range; }
    double getTicketPrice() const { return ticketPrice; }
    double getCostPerPassenger(double fuelPrice) const {
        return calculateFuelPerPassengerPerDistance() * fuelPrice;
    }

    void displayBasicInfo() const {
        cout << "Тип літака: " << type << endl;
        cout << "Кількість пасажирів: " << passengerCount << endl;
        cout << "Дальність: " << range << " км" << endl;
    }

    void displayInfo(double fuelPrice) const {
        cout << "Тип літака: " << type << endl;
        cout << "Кількість пасажирів: " << passengerCount << endl;
        cout << "Дальність: " << range << " км" << endl;
        cout << "Розхід пального: " << fuelConsumption << " л" << endl;
        cout << "Вартість квитка: " << ticketPrice << " грн" << endl;
        cout << "Собівартість перевезення одного пасажира: " << getCostPerPassenger(fuelPrice) << " грн" << endl;
    }

    void saveToFile(ofstream& outFile, double fuelPrice) const {
        outFile << type << "," << passengerCount << "," << range << "," << fuelConsumption << "," << ticketPrice << ","
            << getCostPerPassenger(fuelPrice) << endl;
    }
};

map<string, pair<int, double>> airplaneData = {
    {"Boeing 737", {160, 2600}},
    {"Airbus A320", {180, 2700}},
    {"Embraer E190", {100, 1800}},
    {"Boeing 777", {396, 9700}},
    {"Airbus A380", {853, 15000}},
    {"Bombardier CRJ", {90, 1500}},
    {"Boeing 787", {296, 14100}},
    {"Airbus A350", {440, 15000}},
    {"ATR 72", {70, 1500}},
    {"Cessna 208", {12, 1200}}
};

// Функція для вибору типу літака
string selectAirplaneType() {
    int choice;
    while (true) {
        cout << "Оберіть тип літака:" << endl;
        int i = 1;
        for (const auto& entry : airplaneData) {
            cout << i++ << ". " << entry.first << endl;
        }

        cout << "Введіть номер типу літака (1-" << airplaneData.size() << "): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > static_cast<int>(airplaneData.size())) {
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            auto it = airplaneData.begin();
            advance(it, choice - 1);
            return it->first;
        }
    }
}

vector<Airplane> loadDataFromFile(const string& filename) {
    vector<Airplane> airplanes;
    ifstream inFile(filename);

    if (inFile.is_open()) {
        string type;
        int passengerCount;
        double range, fuelConsumption, ticketPrice;
        while (getline(inFile, type, ',')) {
            inFile >> passengerCount;
            inFile.ignore(); // ігноруємо коми
            inFile >> range;
            inFile.ignore();
            inFile >> fuelConsumption;
            inFile.ignore();
            inFile >> ticketPrice;
            airplanes.emplace_back(type, passengerCount, range, fuelConsumption, ticketPrice);
        }
        inFile.close();
    }
    return airplanes;
}

void saveDataToFile(const vector<Airplane>& airplanes, const string& filename, double fuelPrice) {
    ofstream outFile(filename);
    for (const auto& airplane : airplanes) {
        airplane.saveToFile(outFile, fuelPrice);
    }
    outFile.close();
}

void displayMenu() {
    cout << "\nМеню:\n";
    cout << "1. ІнформаціЯ про літаки у файлі\n";
    cout << "2. Список інформації про всі можливі літаки\n";
    cout << "3. Розрахувати паливо на одного пасажира на одиницю дальності\n";
    cout << "4. Почати обчислення з введенням вартості пального\n";
    cout << "5. Вийти\n";
    cout << "Виберіть опцію: ";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<Airplane> airplanes;
    string filename = "airplanes_data.txt";
    double fuelPrice = 0.0;

    airplanes = loadDataFromFile(filename);

    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Літаки з файлу:\n";
            for (const auto& airplane : airplanes) {
                airplane.displayInfo(fuelPrice);
            }
            break;

        case 2:
            cout << "Всі літаки в пам'яті:\n";
            for (const auto& entry : airplaneData) {
                const string& type = entry.first;
                int passengerCount = entry.second.first;
                double range = entry.second.second;
                Airplane airplane(type, passengerCount, range, 0, 0); // Використовуємо 0 для паливної витрати та вартості квитка
                airplane.displayBasicInfo();
                cout << endl; 
            }
            break;

        case 3: {
            string type = selectAirplaneType();
            int passengerCount = airplaneData[type].first;
            double range = airplaneData[type].second;
            double fuelConsumption;
            cout << "Введіть розхід пального (л): ";
            cin >> fuelConsumption;
            Airplane airplane(type, passengerCount, range, fuelConsumption, 0);
            cout << "Розхід пального на одного пасажира на одиницю дальності: "
                << airplane.calculateFuelPerPassengerPerDistance() << " л\n";
            break;
        }

        case 4: {
            cout << "Введіть вартість одного літра пального: ";
            cin >> fuelPrice;

            string type = selectAirplaneType();
            int passengerCount = airplaneData[type].first;
            double range = airplaneData[type].second;
            double fuelConsumption, ticketPrice;

            cout << "Введіть розхід пального (л): ";
            cin >> fuelConsumption;
            cout << "Введіть вартість квитка (грн): ";
            cin >> ticketPrice;

            airplanes.emplace_back(type, passengerCount, range, fuelConsumption, ticketPrice);
            sort(airplanes.begin(), airplanes.end(), [fuelPrice](const Airplane& a, const Airplane& b) {
                return a.getCostPerPassenger(fuelPrice) < b.getCostPerPassenger(fuelPrice);
                });
            for (const auto& airplane : airplanes) {
                airplane.displayInfo(fuelPrice);
            }
            saveDataToFile(airplanes, filename, fuelPrice);
            break;
        }

        case 5:
            cout << "Вихід з програми.\n";
            break;

        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 5);

    return 0;
}
