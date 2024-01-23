// Включение заголовочного файла с объявлением функций тестирования
#include "test.h"

// Включение заголовочного файла с объявлением класса FixedLengthStringArray
#include "FixedLengthStringArray.h"

// Включение заголовочного файла для использования макроса assert
#include <cassert>

void testSetElement() {

    FixedLengthStringArray array(3);

    // Установка элемента в массив
    array.setElement(0, "hello");

    // Проверка, что установка прошла успешно
    assert(array.getElement(0) == "hello");
}

// Функция для тестирования сцепления массивов
void testConcatenateArrays() {
    // Создание двух объектов FixedLengthStringArray с размером 3
    FixedLengthStringArray array1(3);
    FixedLengthStringArray array2(3);

    // Установка значений в первом массиве
    array1.setElement(0, "Hello");
    array1.setElement(1, " ");
    array1.setElement(2, "world");

    // Установка значений во втором массиве
    array2.setElement(0, "C++");
    array2.setElement(1, " is");
    array2.setElement(2, " beautiful!");

    // Сцепление массивов
    FixedLengthStringArray concatenatedArray = array1.concatenateArrays(array2);

    // Проверка, что сцепление прошло успешно
    assert(concatenatedArray.getElement(0) == "HelloC++");
    assert(concatenatedArray.getElement(1) == "  is");
    assert(concatenatedArray.getElement(2) == "world beautiful!");
}

// Функция для запуска всех тестов
bool runTests() {
    // Вызов функций тестирования
    testSetElement();
    testConcatenateArrays();

    // Возвращение значения true, если все тесты успешно пройдены
    return true;
}
