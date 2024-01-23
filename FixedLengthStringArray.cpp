#include "FixedLengthStringArray.h"
// Включение заголовочного файла для ввода/вывода на консоль
#include <iostream>

using namespace std;

//конструктор инициализирует переменные `length` и `array` класса `FixedLengthStringArray`, используя значения аргумента `len` и пустые строки.
FixedLengthStringArray::FixedLengthStringArray(int len) : length(len), array(len, "") {}

// Проверка корректности индекса перед доступом к элементу массива
void FixedLengthStringArray::checkIndex(int index) const {
    if (index < 0 || index >= length) {
        throw out_of_range("Index out of bounds");
    }
}

// Установка значения элемента массива по указанному индексу
void FixedLengthStringArray::setElement(int index, const string& value) {
    checkIndex(index);
    array[index] = value;
}

// Получение значения элемента массива по указанному индексу
string FixedLengthStringArray::getElement(int index) const {
    checkIndex(index);
    return array[index];
}

// Сцепление массивов строк
FixedLengthStringArray FixedLengthStringArray::concatenateArrays(const FixedLengthStringArray& otherArray) const {
    // Проверка, что массивы имеют одинаковую длину
    if (otherArray.length != length) {
        throw invalid_argument("Arrays must have the same length for concatenation");
    }

    // Создание нового массива для результата сцепления
    FixedLengthStringArray result(length);

    // Выполнение сцепления элементов двух массивов
    for (int i = 0; i < length; ++i) {
        result.setElement(i, array[i] + otherArray.getElement(i));
    }
    return result;
}

// Объединение (слияние) массивов строк с уникальными элементами
FixedLengthStringArray FixedLengthStringArray::mergeArrays(const FixedLengthStringArray& otherArray) const {
    // Проверка, что массивы имеют одинаковую длину
    if (otherArray.length != length) {
        throw invalid_argument("Arrays must have the same length for merging");
    }

    // Создание нового массива для результата объединения
    FixedLengthStringArray result(length);

    // Копирование элементов текущего массива в результат
    for (int i = 0; i < length; ++i) {
        result.setElement(i, array[i]);
    }

    // Добавление уникальных элементов из другого массива
    for (int i = 0; i < length; ++i) {
        // Проверка, что элемент отсутствует в результате
        if (find(result.array.begin(), result.array.end(), otherArray.getElement(i)) == result.array.end()) {
            result.setElement(i, otherArray.getElement(i));
        }
    }
    return result;
}

// Вывод элемента массива по указанному индексу на консоль
void FixedLengthStringArray::displayElement(int index) const {
    cout << getElement(index) << endl;
}

// Вывод всех элементов массива на консоль
void FixedLengthStringArray::displayArray() const {
    for (const auto& element : array) {
        cout << element << " ";
    }
    cout << endl;
}
