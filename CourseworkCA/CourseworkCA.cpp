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


    

// �������� ������� ��� ������ ���� �����
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
    }//�������, ��� ������� ������� ��������, 
    //�� ��������� ��������� ��� ���������� ������ �������� �� ������� ��������.

    string getType() const { return type; }
    int getPassengerCount() const { return passengerCount; }
    double getRange() const { return range; }
    double getTicketPrice() const { return ticketPrice; }
    double getCostPerPassenger(double fuelPrice) const {//���������� ��������
        return calculateFuelPerPassengerPerDistance() * fuelPrice;
    }

    void displayBasicInfo() const {
        cout << "��� �����: " << type << endl;
        cout << "ʳ������ ��������: " << passengerCount << endl;
        cout << "��������: " << range << " ��" << endl;
    }

    void displayInfo(double fuelPrice) const {
        cout << "\n\n----------------------------------"<<endl;
        cout << "��� �����: " << type << endl;
        cout << "ʳ������ ��������: " << passengerCount << endl;
        cout << "��������: " << range << " ��" << endl;
        cout << "������ ��������: " << fuelConsumption << " �" << endl;
        cout << "������� ������: " << ticketPrice << " ���" << endl;
        cout << "���������� ����������� ������ ��������: " << getCostPerPassenger(fuelPrice) << " ���" << endl;
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

// ������� ��� ������ ���� �����
string selectAirplaneType() {
    int choice;
    while (true) {
        cout << "������ ��� �����:" << endl;
        int i = 1;
        for (const auto& entry : airplaneData) {
            cout << i++ << ". " << entry.first << endl;
        }

        cout << "������ ����� ���� ����� (1-" << airplaneData.size() << "): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > static_cast<int>(airplaneData.size())) {
            cout << "������� ����. ��������� �� ���." << endl;
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
        airplanes.clear(); // ������� ������ ����� ����������� ����� �����
        string line;

        while (getline(inFile, line)) {
            // ������������� ��������� �� ��������� find � substr
            size_t pos = 0;
            vector<string> tokens;
            while ((pos = line.find(',')) != string::npos) {
                tokens.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            tokens.push_back(line); // ������ ������ ��������

            // �������� �� ������� ��������
            if (tokens.size() == 6) {
                string type = tokens[0];
                int passengerCount = stoi(tokens[1]);
                double range = stod(tokens[2]);
                double fuelConsumption = stod(tokens[3]);
                double ticketPrice = stod(tokens[4]);
                double costPerPassenger = stod(tokens[5]);

                // ����������, �� ��� �������
                if (passengerCount > -1 && range > -1 && fuelConsumption > -1 && ticketPrice >= 0) {
                    airplanes.emplace_back(type, passengerCount, range, fuelConsumption, ticketPrice);
                }
                else {
                    cout << "��������� ��� � �����.\n";
                }
            }
            else {
                cout << "����������� ������� ���� � �����.\n";
            }
        }

        inFile.close();
    }
    else {
        cout << "�� ������� ������� ���� ��� �������.\n";
    }
}




void saveDataToFile(vector<Airplane>& airplanes, const string& filename, double fuelPrice) {
    // ³�������� ���� � ����� ���������
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        // �������� ���� ����� ���� � ����� �����
        airplanes.back().saveToFile(outFile, fuelPrice);
        outFile.close();
    }
    else {
        cout << "�� ������� ������� ���� ��� ������.\n";
    }
}
void displayTicketPrice(const vector<Airplane>& airplanes) {
    if (airplanes.empty()) {
        cout << "���� ������� ��� ��� �� �����������.\n";
        return;
    }

    // Display only the types available in the file
    map<int, string> availableTypes;
    int index = 1;
    for (const auto& airplane : airplanes) {
        availableTypes[index++] = airplane.getType();
    }

    cout << "������ ��� ����� � ������� � ����:\n";
    for (const auto& entry : availableTypes) {
        cout << entry.first << ". " << entry.second << endl;
    }

    int choice;
    cout << "������ ����� ���� �����: ";
    cin >> choice;

    // Validate choice and display ticket price for selected airplane type
    if (availableTypes.find(choice) != availableTypes.end()) {
        string selectedType = availableTypes[choice];
        for (const auto& airplane : airplanes) {
            if (airplane.getType() == selectedType) {
                cout << "������� ������ �� ���� " << selectedType << ": " << airplane.getTicketPrice() << " ���\n";
                return;
            }
        }
    }
    else {
        cout << "������� ����. ��������� �� ���.\n";
    }
}





void displayMenu() {
    cout << "\n----------����----------\n";
    cout << "1. ������ \n(���������� ��� ������� ����� � ��������� ����)\n";
    cout << "\n2. ������ \n(���������� ��� �� ������ �����)\n";
    cout << "\n3. ������� \n(������� ������� ��������, �� ��������� ��������� ��� ���������� ������ �������� �� ������� ��������.)\n";
    cout << "\n4. ���������� \n(���������� ����������� ������ ��������)(������� ����� � ���� �����)\n";
    cout << "\n5. ֳ�� ������ \n(������ ������� ������ �� ���� � ����� ������)\n";
    cout << "\n6. �����\n";
    cout << "������� �����: ";
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
                cout << "���� ������� ��� ��� �� �����������.\n";
            }
            else {
                cout << "\n-------------------˳���� � �����-------------------\n";
                for (const auto& airplane : airplanes) {
                    airplane.displayInfo(fuelPrice);
                }
            }
            break;

        case 2:
            cout << "�� ����� � ���'��:\n";
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
            cout << "������ ������ �������� (�): ";
            cin >> fuelConsumption;
            Airplane airplane(type, passengerCount, range, fuelConsumption, 0);
            cout << "������ �������� �� ������ �������� �� ������� ��������: "
                << airplane.calculateFuelPerPassengerPerDistance() << " �\n";
            break;
        }

        case 4: {
            cout << "������ ������� ������ ���� ��������: ";
            cin >> fuelPrice;

            string type = selectAirplaneType();
            int passengerCount = airplaneData[type].first;
            double range = airplaneData[type].second;
            double fuelConsumption, ticketPrice;

            cout << "������ ������ �������� (�): ";
            cin >> fuelConsumption;
            cout << "������ ������� ������ (���): ";
            cin >> ticketPrice;

            airplanes.emplace_back(type, passengerCount, range, fuelConsumption, ticketPrice);

            saveDataToFile(airplanes, filename, fuelPrice);
            cout << "--------------------------���������� ��������� � ����--------------------------\n";
            break;
        }

        case 5:
            displayTicketPrice(airplanes);
            break;

        case 6:
            cout << "����� � ��������.\n";
            break;

        default:
            cout << "������� ����. ��������� �� ���.\n";
        }
    } while (choice != 6);

    return 0;
}