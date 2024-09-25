
/*
�������� ����, ����������� ����� ������ ��������� �����  ����� (���. �������)
����� ������ �������� ���������� ������������. ���������� ������� ������, �� ������� �� �����.
�������� �������, ���������� ��� � ��������� ����. 
������� ������ 䳿 ��� ������� ������� ���� �������� ������� (������� 4.1).


������ 10:
��� ������: ֳ���.   
ʳ������ ��������: 10. 
����� ��� ���������� �������� ������ �������: i. 
���������: i-1.    
������� �� �������:������ ������� ������� �������� ��������
*/

#include <iostream>
#include <windows.h>

using namespace std;

class DynamicArray {
private:
    int* arr; //     * -  ��������� �������� �� ������� ���'�� ��� ������
    int size;

public:
    // ����������� ��� ����������� ���������� ������
    DynamicArray(int n) : size(n) {//������ ���� �������� n, �� ������� ����� ���������� ������, ���� ���� ���������.
        /*
        : size(n) � �� ������ �����������, �� ��������������� ��� ����������� ����� ����� ����� ���������� ��� ������������.
        size(n) ������, �� ���� size ����� DynamicArray ���� ������������� ���������, ��� ���������� � �������� n.
        */
        arr = new int[size]; // �������� ���'��� ��� ������
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                arr[i] = i;        // ������ �������
            }
            else {
                arr[i] = i - 1;    // �������� �������
            }
        }
    }

    // ���������� ��� ��������� ���'��
    ~DynamicArray() {
        delete[] arr; // ��������� ���'���
    }

    // ������� ��� ������ ������ � ������� �� ������� �������� �������
    void printArrayWithBrackets() const {
        /*
        const, ������, �� �� ������� �� ����� ���� ��'����, ��� ����� ���� �����������. �� �������, 
        �� ����� ����� (�������, ����� �� ���� ���� �����) 
        �� ������ ����� �� ��� ��������� ���� �������.
        */ 
        for (int i = 0; i < size; i++) {
            if ((i + 1) % 3 == 0) {
                cout << "[" << arr[i] << "] "; // ����� ������� �������� � ������(��� �����)
            }
            else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    // ������� ��� ������� �� �������� ������
    int getElement(int index) const {
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};

// �������, ��� ��������� ������� ������� �������� ��������
int productOfEveryThird(const DynamicArray& array) {
    int product = 1;//1 �� �� ������ �� 0.
    for (int i = 2; i < array.getSize(); i += 3) { // �������� � ������� 2 (����� �������)
        product *= array.getElement(i);
    }
    return product;
}

int main() {//====================================================  MAIN
    // ������������ ��������� ��� ������
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 10; // ʳ������ �������� ������ ��������� ��� 10 �������
    DynamicArray arr(n);

    // �������� ����� � ������� �� ������� �������� �������
    cout << "�����: ";
    arr.printArrayWithBrackets();

    // ��������� ������� ������� �������� ��������
    int result = productOfEveryThird(arr);
    cout << "������� ������� �������� ��������: " << result << endl;
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

   
    cout << "�����: ";
    arr.printArrayWithBrackets();

    
    int result = productOfEveryThird(arr);
    cout << "������� ������� �������� ��������: " << result << endl;
    cout << "\n- - - - - - - - - - - - - - -\n\n\n\n\n";
    return 0;
}

*/