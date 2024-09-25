
/*
Створити клас, конструктор якого генерує динамічний масив  чисел (див. варіанти)
Розмір масиву задається параметром конструктора. Деструктор звільняє пам’ять, що виділена під масив.
Створити функцію, параметром якої є створений клас. 
Функція виконує дії над масивом певного типу відповідно варіанту (таблиця 4.1).


Варіант 10:
Тип данних: Цілий.   
Кількість елементів: 10. 
Вираз для обчислення елемента масиву Парного: i. 
Непарного: i-1.    
Вказівки до обробки:Знайти добуток кожного третього елемента
*/

#include <iostream>
#include <windows.h>

using namespace std;

class DynamicArray {
private:
    int* arr; //     * -  Динамічний показник на область пам'яті для масиву
    int size;

public:
    // Конструктор для ініціалізації динамічного масиву
    DynamicArray(int n) : size(n) {//приймає один параметр n, що визначає розмір динамічного масиву, який буде створений.
        /*
        : size(n) — це список ініціалізації, що використовується для ініціалізації членів класу перед виконанням тіла конструктора.
        size(n) означає, що член size класу DynamicArray буде ініціалізований значенням, яке передається в параметрі n.
        */
        arr = new int[size]; // Виділяємо пам'ять для масиву
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                arr[i] = i;        // Парний елемент
            }
            else {
                arr[i] = i - 1;    // Непарний елемент
            }
        }
    }

    // Деструктор для звільнення пам'яті
    ~DynamicArray() {
        delete[] arr; // Звільняємо пам'ять
    }

    // Функція для виводу масиву з дужками на кожному третьому елементі
    void printArrayWithBrackets() const {
        /*
        const, означає, що ця функція не змінює стан об'єкта, для якого вона викликається. Це гарантія, 
        що члени класу (зокрема, масив та інші поля класу) 
        не будуть змінені під час виконання цієї функції.
        */ 
        for (int i = 0; i < size; i++) {
            if ((i + 1) % 3 == 0) {
                cout << "[" << arr[i] << "] "; // Третій елемент виводимо в дужках(Для краси)
            }
            else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    // Функція для доступу до елементів масиву
    int getElement(int index) const {
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};

// Функція, яка знаходить добуток кожного третього елемента
int productOfEveryThird(const DynamicArray& array) {
    int product = 1;//1 бо не множим на 0.
    for (int i = 2; i < array.getSize(); i += 3) { // Починаємо з індексу 2 (третій елемент)
        product *= array.getElement(i);
    }
    return product;
}

int main() {//====================================================  MAIN
    // Налаштування кодування для консолі
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 10; // Кількість елементів масиву фіксована для 10 варіанту
    DynamicArray arr(n);

    // Виводимо масив з дужками на кожному третьому елементі
    cout << "Масив: ";
    arr.printArrayWithBrackets();

    // Знаходимо добуток кожного третього елемента
    int result = productOfEveryThird(arr);
    cout << "Добуток кожного третього елемента: " << result << endl;
    cout << "\n- - - - - - - - - - - - - - -\n\n\n\n\n";
    return 0;
}

//==============================================================================CODE WITHOUT COMMENTS
/*
#include <iostream>
#include <windows.h>

using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    
    DynamicArray(int n) : size(n) {
       
        arr = new int[size]; 
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                arr[i] = i;        
            }
            else {
                arr[i] = i - 1;    
            }
        }
    }

    
    ~DynamicArray() {
        delete[] arr; 
    }

    
    void printArrayWithBrackets() const {
       
        for (int i = 0; i < size; i++) {
            if ((i + 1) % 3 == 0) {
                cout << "[" << arr[i] << "] "; 
            }
            else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    
    int getElement(int index) const {
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};


int productOfEveryThird(const DynamicArray& array) {
    int product = 1;
    for (int i = 2; i < array.getSize(); i += 3) { 
        product *= array.getElement(i);
    }
    return product;
}

int main() {
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 10; 
    DynamicArray arr(n);

   
    cout << "Масив: ";
    arr.printArrayWithBrackets();

    
    int result = productOfEveryThird(arr);
    cout << "Добуток кожного третього елемента: " << result << endl;
    cout << "\n- - - - - - - - - - - - - - -\n\n\n\n\n";
    return 0;
}

*/