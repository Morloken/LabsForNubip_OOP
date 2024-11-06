#define NOMINMAX
#include <windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
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
    }//функція, яка повертає кількість пального, 
    //що необхідно витратити при перевезенні одного пасажира на одиницю дальності.

    string getType() const { return type; }
    int getPassengerCount() const { return passengerCount; }
    double getRange() const { return range; }
    double getTicketPrice() const { return ticketPrice; }
    double getCostPerPassenger(double fuelPrice) const {//собівартість пасажира
        return calculateFuelPerPassengerPerDistance() * fuelPrice;
    }

    void displayBasicInfo() const {
        cout << "Тип літака: " << type << endl;
        cout << "Кількість пасажирів: " << passengerCount << endl;
        cout << "Дальність: " << range << " км" << endl;
    }

    void displayInfo(double fuelPrice) const {
        cout << "\n\n----------------------------------"<<endl;
        cout << "Тип літака: " << type << endl;
        cout << "Кількість пасажирів: " << passengerCount << endl;
        cout << "Дальність: " << range << " км" << endl;
        cout << "Розхід пального: " << fuelConsumption << " л" << endl;
        cout << "Вартість квитка: " << ticketPrice << " грн" << endl;
        cout << "Собівартість перевезення одного пасажира: " << getCostPerPassenger(fuelPrice) << " грн" << endl;
        cout << "----------------------------------";
    }

    void saveToFile(ofstream& outFile, double fuelPrice) const {
        outFile << type << "," << passengerCount << "," << range << "," << fuelConsumption << "," << ticketPrice << ","
            << getCostPerPassenger(fuelPrice) << endl;
    }
};//======================================= CLASS AIRPLANE END

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

void loadDataFromFile(vector<Airplane>& airplanes, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        airplanes.clear(); // Очищаємо вектор перед зчитуванням нових даних
        string line;

        while (getline(inFile, line)) {
            // Використовуємо розділення за допомогою find і substr
            size_t pos = 0;
            vector<string> tokens;
            while ((pos = line.find(',')) != string::npos) {
                tokens.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            tokens.push_back(line); // додаємо останнє значення

            // Перевірка на кількість елементів
            if (tokens.size() == 6) {
                string type = tokens[0];
                int passengerCount = stoi(tokens[1]);
                double range = stod(tokens[2]);
                double fuelConsumption = stod(tokens[3]);
                double ticketPrice = stod(tokens[4]);
                double costPerPassenger = stod(tokens[5]);

                // Перевіряємо, чи дані коректні
                if (passengerCount > -1 && range > -1 && fuelConsumption > -1 && ticketPrice >= 0) {
                    airplanes.emplace_back(type, passengerCount, range, fuelConsumption, ticketPrice);
                }
                else {
                    cout << "Некоректні дані в рядку.\n";
                }
            }
            else {
                cout << "Неправильна кількість полів у рядку.\n";
            }
        }

        inFile.close();
    }
    else {
        cout << "Не вдалося відкрити файл для читання.\n";
    }
}




void saveDataToFile(vector<Airplane>& airplanes, const string& filename, double fuelPrice) {
    // Відкриваємо файл у режимі додавання
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        // Записуємо лише новий літак у кінець файлу
        airplanes.back().saveToFile(outFile, fuelPrice);
        outFile.close();
    }
    else {
        cout << "Не вдалося відкрити файл для запису.\n";
    }
}
void displayTicketPrice(const vector<Airplane>& airplanes) {
    if (airplanes.empty()) {
        cout << "Файл порожній або дані не завантажено.\n";
        return;
    }

    // Display only the types available in the file
    map<int, string> availableTypes;
    int index = 1;
    for (const auto& airplane : airplanes) {
        availableTypes[index++] = airplane.getType();
    }

    cout << "Оберіть тип літака з наявних у файлі:\n";
    for (const auto& entry : availableTypes) {
        cout << entry.first << ". " << entry.second << endl;
    }

    int choice;
    cout << "Введіть номер типу літака: ";
    cin >> choice;

    // Validate choice and display ticket price for selected airplane type
    if (availableTypes.find(choice) != availableTypes.end()) {
        string selectedType = availableTypes[choice];
        for (const auto& airplane : airplanes) {
            if (airplane.getType() == selectedType) {
                cout << "Вартість квитка на літак " << selectedType << ": " << airplane.getTicketPrice() << " грн\n";
                return;
            }
        }
    }
    else {
        cout << "Невірний вибір. Спробуйте ще раз.\n";
    }
}





void displayMenu() {
    cout << "\n----------Меню----------\n";
    cout << "1. Записи \n(Інформація про записані літаки у фізичному файлі)\n";
    cout << "\n2. Буклет \n(Інформація про всі можливі літаки)\n";
    cout << "\n3. Витрати \n(Повертає кількість пального, що необхідно витратити при перевезенні одного пасажира на одиницю дальності.)\n";
    cout << "\n4. Собівартість \n(Собівартість перевезення одного пасажира)(Дозапис даних у файл літаків)\n";
    cout << "\n5. Ціна квитка \n(Показує вартість квитка на літак з файлу записів)\n";
    cout << "\n6. Вихід\n";
    cout << "Виберіть опцію: ";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<Airplane> airplanes;
    string filename = "airplanes_data.txt";
    double fuelPrice = 0.0;

    loadDataFromFile(airplanes, filename);

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            if (airplanes.empty()) {
                cout << "Файл порожній або дані не завантажено.\n";
            }
            else {
                cout << "\n-------------------Літаки з файлу-------------------\n";
                for (const auto& airplane : airplanes) {
                    airplane.displayInfo(fuelPrice);
                }
            }
            break;

        case 2:
            cout << "Всі літаки в пам'яті:\n";
            for (const auto& entry : airplaneData) {
                const string& type = entry.first;
                int passengerCount = entry.second.first;
                double range = entry.second.second;
                Airplane airplane(type, passengerCount, range, 0, 0);
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

            saveDataToFile(airplanes, filename, fuelPrice);
            cout << "--------------------------Інформацію збережено у файл--------------------------\n";
            break;
        }

        case 5:
            displayTicketPrice(airplanes);
            break;

        case 6:
            cout << "Вихід з програми.\n";
            break;

        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 6);

    return 0;
}