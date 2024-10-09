/*
* 1. Визначити ієрархію класів (відповідно до варіанта). 
        Для визначення ієрархії класів зв'язати ставленням спадкування класи, наведені  для заданого варіанта, 
        з цих  класів обрати один, який буде стояти на чолі ієрархії. 
2. Реалізувати класи. Визначити в класах всі необхідні конструктори і деструктор.
3. Написати демонстраційну програму, в якій створюються об'єкти різних класів. 
4. Побудувати діаграму класів. 

Варіант:
    10. квитанція, накладна, документ, чек;
*/


#include <iostream>
#include <string>
#include <iomanip>  // Для використання функції setw для форматування виводу
using namespace std;

// Базовий клас для документів
class Document {
protected:
    string documentNumber;  // Номер документа
    string date;            // Дата документа
public:
    // Конструктор базового класу, який ініціалізує номер документа та дату
    Document(string num, string d) : documentNumber(num), date(d) {
        cout << "Document created: " << documentNumber << endl;
    }

    // Віртуальний деструктор, що забезпечує правильне видалення об'єктів похідних класів
    virtual ~Document() {
        cout << "Document destroyed: " << documentNumber << endl;
    }

    // Віртуальна функція для виведення інформації про документ (її можна перевизначати в похідних класах)
    virtual void printInfo() const {
        // Форматування виводу за допомогою setw для вирівнювання виведених даних
        cout << setw(15) << left << "Document number:" << setw(10) << documentNumber
            << setw(10) << "Date:" << setw(15) << date << endl;
    }
};

// Похідний клас для Квитанції (Receipt), який успадковує базовий клас Document
class Receipt : public Document {
    double amount;  // Сума квитанції
public:
    // Конструктор класу Receipt, який викликає конструктор базового класу і додає поле 'amount'
    Receipt(string num, string d, double amt) : Document(num, d), amount(amt) {
        cout << "Receipt created with amount: " << amount << endl;
    }

    // Деструктор класу Receipt
    ~Receipt() {
        cout << "Receipt destroyed" << endl;
    }

    // Перевизначена функція для виведення інформації про квитанцію
    void printInfo() const override {
        cout << setw(15) << left << "Receipt:" << setw(10) << documentNumber
            << setw(10) << "Date:" << setw(15) << date
            << setw(10) << "Amount:" << setw(10) << amount << endl;
    }
};

// Похідний клас для Накладної (Invoice), який успадковує базовий клас Document
class Invoice : public Document {
    string goodsDescription;  // Опис товарів
public:
    // Конструктор класу Invoice, який викликає конструктор базового класу і додає поле 'goodsDescription'
    /*інформація, яка містить деталі про те, які товари або послуги були продані, придбані або переміщені.*/
    Invoice(string num, string d, string goods) : Document(num, d), goodsDescription(goods) {
        cout << "Invoice created with goods: " << goodsDescription << endl;
    }

    // Деструктор класу Invoice
    ~Invoice() {
        cout << "Invoice destroyed" << endl;
    }

    // Перевизначена функція для виведення інформації про накладну
    void printInfo() const override {
        cout << setw(15) << left << "Invoice:" << setw(10) << documentNumber
            << setw(10) << "Date:" << setw(15) << date
            << setw(10) << "Goods:" << setw(10) << goodsDescription << endl;
    }
};

// Похідний клас для Чека (Check), який успадковує базовий клас Document
class Check : public Document {
    string bankName;  // Назва банку
public:
    // Конструктор класу Check, який викликає конструктор базового класу і додає поле 'bankName'
    Check(string num, string d, string bank) : Document(num, d), bankName(bank) {
        cout << "Check created for bank: " << bankName << endl;
    }

    // Деструктор класу Check
    ~Check() {
        cout << "Check destroyed" << endl;
    }

    // Перевизначена функція для виведення інформації про чек
    void printInfo() const override {
        cout << setw(15) << left << "Check:" << setw(10) << documentNumber
            << setw(10) << "Date:" << setw(15) << date
            << setw(10) << "Bank:" << setw(10) << bankName << endl;
    }
};



// Функція для малювання діаграми класів з бейджами в консолі
void drawClassDiagram() {
    cout << "\n--- Class Diagram ---\n";
    cout << "      +-----------------------------------------------------------------+\n";
    cout << "      |                           Document                              |\n";
    cout << "      |-----------------------------------------------------------------|\n";
    cout << "      |                    - documentNumber: string                     |\n";
    cout << "      |                    - date: string                               |\n";
    cout << "      +-----------------------------------------------------------------+\n";
    cout << "           /                             |                           \\\n";
    cout << "          /                              |                            \\\n";
    cout << "         /                               |                             \\\n";
    cout << "        /                                |                              \\\n";
    cout << " +-----------------+       +----------------------------+             +--------------------+\n";
    cout << " |   Receipt       |       |    Invoice                 |             |     Check          |\n";
    cout << " |-----------------|       |----------------------------|             |--------------------|\n";
    cout << " | - amount: double|       | - goodsDescription: string |             | - bankName: string |\n";
    cout << " +-----------------+       +----------------------------+             +--------------------+\n";
}




// Головна функція для демонстрації роботи програми
int main() {
    // Створення об'єктів класів Receipt, Invoice та Check, використовуючи динамічне виділення пам'яті
    Document* doc1 = new Receipt("R001", "2024-10-09", 150.75);  // Квитанція
    Document* doc2 = new Invoice("I001", "2024-10-08", "Electronics");  // Накладна
    Document* doc3 = new Check("C001", "2024-10-07", "Bank of America");  // Чек

    // Виведення інформації про кожен документ
    cout << "\n--- Document Information ---\n";
    doc1->printInfo();  // Виклик перевизначеної функції для квитанції
    doc2->printInfo();  // Виклик перевизначеної функції для накладної
    doc3->printInfo();  // Виклик перевизначеної функції для чека

    // Функція для малювання діаграми класів
    drawClassDiagram();
    cout << endl << endl;

    // Видалення об'єктів та звільнення пам'яті (викликається деструктор)
    delete doc1;
    delete doc2;
    delete doc3;

    return 0;
}
/*
Використання поліморфізму дозволяє працювати з об'єктами похідних класів через вказівники на базовий клас Document.
Це означає, що навіть якщо ми створюємо об'єкт квитанції або накладної, можемо викликати їхні методи через вказівник типу Document*.




У Main створюються три об'єкти: квитанція, накладна та чек. 
Для цього використовується динамічне виділення пам'яті (оператор new), 
і всі об'єкти зберігаються як вказівники на базовий клас Document.
Це дозволяє використовувати єдиний тип даних для різних об'єктів і демонструє принцип поліморфізму.



  delete, викликає відповідні деструктори для кожного типу документів. 
  Це забезпечує коректне звільнення пам'яті та дотримання принципів об'єктно-орієнтованого програмування.
*/