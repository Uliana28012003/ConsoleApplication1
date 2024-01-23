#include "FixedLengthStringArray.h"
#include <iostream>
#include "test.h"
#include <chrono>

using namespace std;
using namespace chrono;


class LogDuration {
public:
    LogDuration()
        //: � ������ ������������ ������������ ��� ������������� ������ ������ ����� ����������� ���� ������������
        : start(steady_clock::now())
    {
    }

    ~LogDuration() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << duration_cast<milliseconds>(dur).count()
            << " ms" << endl;
    }

private:
    steady_clock::time_point start;
};

// ������� ��� ����������� ���� ��������
void displayMenu() {
    cout << "1. ���������� ������� � �������\n";
    cout << "2. �������� ������� �� �������\n";
    cout << "3. ������� �������\n";
    cout << "4. ���������� �������\n";
    cout << "5. ������� �������\n";
    cout << "6. ������� ������\n";
    cout << "0. �����\n";
    cout << "������� ��� �����: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    int length = 5;
    FixedLengthStringArray array1(length);
    FixedLengthStringArray array2(length);

    if (runTests()) {
        cout << "����-����� �������� �������!" << endl;
    }
    else {
        cerr << "����-����� �� ��������!" << endl;
    }

    int choice;
    do {
        // ����� ���� ��������
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            // ��������� �������� � �������
            // ����� ������� ���������� �������� � �������������� LogDuration
            { LogDuration input;
            int index;
            string value;
            cout << "������� ������: ";
            cin >> index;
            cout << "������� ��������: ";
            cin >> value;
            array1.setElement(index, value);
            break;
            }
        }
        case 2: {
            // ��������� �������� �� �������
            // ����� ������� ���������� �������� � �������������� LogDuration
            int index;
            { LogDuration input;
            cout << "������� ������: ";
            cin >> index;
            cout << "������� � �������� " << index << ": " << array1.getElement(index) << endl;
            break;
            }
        }
        case 3: {
            // ��������� ��������
            // ����� ������� ���������� �������� � �������������� LogDuration
            { LogDuration input;
            FixedLengthStringArray concatenatedArray = array1.concatenateArrays(array2);
            cout << "���������� ������: ";
            concatenatedArray.displayArray();
            break;
            }
        }
        case 4: {
            // ����������� ��������
            // ����� ������� ���������� �������� � �������������� LogDuration
            { LogDuration input;
            FixedLengthStringArray mergedArray = array1.mergeArrays(array2);
            cout << "������������ ������: ";
            mergedArray.displayArray();
            break;
            }
        }
        case 5: {
            // ����� �������� �������
            // ����� ������� ���������� �������� � �������������� LogDuration
            { LogDuration input;
            int index;
            cout << "������� ������: ";
            cin >> index;
            cout << "������� � �������� " << index << ": ";
            array1.displayElement(index);
            break;
            }
        }
        case 6: {
            // ����� �������
            // ����� ������� ���������� �������� � �������������� LogDuration
            { LogDuration input;
            cout << "������: ";
            array1.displayArray();
            break;
            }
        }
        case 0:
            // ����� �� ���������
            // ����� ������� ���������� �������� � �������������� LogDuration
        { LogDuration input;
        cout << "����� �� ���������.\n";
        break;
        }
        default:
            cout << "�������� �����. ����������, ���������� �����.\n";
        }
    } while (choice != 0);

    return 0;
}
