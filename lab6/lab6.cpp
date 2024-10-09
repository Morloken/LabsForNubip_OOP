/*
* 1. ��������� �������� ����� (�������� �� �������). 
        ��� ���������� �������� ����� ��'����� ���������� ����������� �����, �������  ��� �������� �������, 
        � ���  ����� ������ ����, ���� ���� ������ �� ��� ��������. 
2. ���������� �����. ��������� � ������ �� �������� ������������ � ����������.
3. �������� �������������� ��������, � ��� ����������� ��'���� ����� �����. 
4. ���������� ������� �����. 

������:
    10. ���������, ��������, ��������, ���;
*/


#include <iostream>
#include <string>
#include <iomanip>  // ��� ������������ ������� setw ��� ������������ ������
using namespace std;

// ������� ���� ��� ���������
class Document {
protected:
    string documentNumber;  // ����� ���������
    string date;            // ���� ���������
public:
    // ����������� �������� �����, ���� �������� ����� ��������� �� ����
    Document(string num, string d) : documentNumber(num), date(d) {
        cout << "Document created: " << documentNumber << endl;
    }

    // ³��������� ����������, �� ��������� ��������� ��������� ��'���� �������� �����
    virtual ~Document() {
        cout << "Document destroyed: " << documentNumber << endl;
    }

    // ³�������� ������� ��� ��������� ���������� ��� �������� (�� ����� ������������� � �������� ������)
    virtual void printInfo() const {
        // ������������ ������ �� ��������� setw ��� ����������� ��������� �����
        cout << setw(15) << left << "Document number:" << setw(10) << documentNumber
            << setw(10) << "Date:" << setw(15) << date << endl;
    }
};

// �������� ���� ��� ��������� (Receipt), ���� ��������� ������� ���� Document
class Receipt : public Document {
    double amount;  // ���� ���������
public:
    // ����������� ����� Receipt, ���� ������� ����������� �������� ����� � ���� ���� 'amount'
    Receipt(string num, string d, double amt) : Document(num, d), amount(amt) {
        cout << "Receipt created with amount: " << amount << endl;
    }

    // ���������� ����� Receipt
    ~Receipt() {
        cout << "Receipt destroyed" << endl;
    }

    // ������������� ������� ��� ��������� ���������� ��� ���������
    void printInfo() const override {
        cout << setw(15) << left << "Receipt:" << setw(10) << documentNumber
            << setw(10) << "Date:" << setw(15) << date
            << setw(10) << "Amount:" << setw(10) << amount << endl;
    }
};

// �������� ���� ��� �������� (Invoice), ���� ��������� ������� ���� Document
class Invoice : public Document {
    string goodsDescription;  // ���� ������
public:
    // ����������� ����� Invoice, ���� ������� ����������� �������� ����� � ���� ���� 'goodsDescription'
    /*����������, ��� ������ ����� ��� ��, �� ������ ��� ������� ���� ������, ������� ��� ��������.*/
    Invoice(string num, string d, string goods) : Document(num, d), goodsDescription(goods) {
        cout << "Invoice created with goods: " << goodsDescription << endl;
    }

    // ���������� ����� Invoice
    ~Invoice() {
        cout << "Invoice destroyed" << endl;
    }

    // ������������� ������� ��� ��������� ���������� ��� ��������
    void printInfo() const override {
        cout << setw(15) << left << "Invoice:" << setw(10) << documentNumber
            << setw(10) << "Date:" << setw(15) << date
            << setw(10) << "Goods:" << setw(10) << goodsDescription << endl;
    }
};

// �������� ���� ��� ���� (Check), ���� ��������� ������� ���� Document
class Check : public Document {
    string bankName;  // ����� �����
public:
    // ����������� ����� Check, ���� ������� ����������� �������� ����� � ���� ���� 'bankName'
    Check(string num, string d, string bank) : Document(num, d), bankName(bank) {
        cout << "Check created for bank: " << bankName << endl;
    }

    // ���������� ����� Check
    ~Check() {
        cout << "Check destroyed" << endl;
    }

    // ������������� ������� ��� ��������� ���������� ��� ���
    void printInfo() const override {
        cout << setw(15) << left << "Check:" << setw(10) << documentNumber
            << setw(10) << "Date:" << setw(15) << date
            << setw(10) << "Bank:" << setw(10) << bankName << endl;
    }
};



// ������� ��� ��������� ������� ����� � �������� � ������
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




// ������� ������� ��� ������������ ������ ��������
int main() {
    // ��������� ��'���� ����� Receipt, Invoice �� Check, �������������� �������� �������� ���'��
    Document* doc1 = new Receipt("R001", "2024-10-09", 150.75);  // ���������
    Document* doc2 = new Invoice("I001", "2024-10-08", "Electronics");  // ��������
    Document* doc3 = new Check("C001", "2024-10-07", "Bank of America");  // ���

    // ��������� ���������� ��� ����� ��������
    cout << "\n--- Document Information ---\n";
    doc1->printInfo();  // ������ ������������� ������� ��� ���������
    doc2->printInfo();  // ������ ������������� ������� ��� ��������
    doc3->printInfo();  // ������ ������������� ������� ��� ����

    // ������� ��� ��������� ������� �����
    drawClassDiagram();
    cout << endl << endl;

    // ��������� ��'���� �� ��������� ���'�� (����������� ����������)
    delete doc1;
    delete doc2;
    delete doc3;

    return 0;
}
/*
������������ ����������� �������� ��������� � ��'������ �������� ����� ����� ��������� �� ������� ���� Document.
�� ������, �� ����� ���� �� ��������� ��'��� ��������� ��� ��������, ������ ��������� ��� ������ ����� �������� ���� Document*.




� Main ����������� ��� ��'����: ���������, �������� �� ���. 
��� ����� ��������������� �������� �������� ���'�� (�������� new), 
� �� ��'���� ����������� �� ��������� �� ������� ���� Document.
�� �������� ��������������� ������ ��� ����� ��� ����� ��'���� � ��������� ������� �����������.



  delete, ������� ������� ����������� ��� ������� ���� ���������. 
  �� ��������� �������� ��������� ���'�� �� ���������� �������� ��'�����-����������� �������������.
*/