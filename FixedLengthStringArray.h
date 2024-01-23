// Включение заголовочных файлов для использования std::vector, std::out_of_range для обработки ситуаций, когда индекс находится вне допустимого диапазона
#include <vector>
#include <stdexcept>
using namespace std;


class FixedLengthStringArray {
private:
    //члены класса: длина массива и вектор строк
    int length;
    vector<string> array;

public:
    FixedLengthStringArray(int len);

    // Проверка корректности индекса перед доступом к элементу массива
    void checkIndex(int index) const;

    // Установка значения элемента массива по указанному индексу
    void setElement(int index, const string& value);

    // Получение значения элемента массива по указанному индексу
    string getElement(int index) const;

    // Сцепление массивов строк !! Принимает другой массив строк в качестве параметра и возвращает новый массив, содержащий элементы обоих массивов
    FixedLengthStringArray concatenateArrays(const FixedLengthStringArray& otherArray) const;

    // Объединение (слияние) массивов строк с уникальными элементами
    FixedLengthStringArray mergeArrays(const FixedLengthStringArray& otherArray) const;

    // Вывод элемента массива по указанному индексу на консоль
    void displayElement(int index) const;

    // Вывод всех элементов массива на консоль
    void displayArray() const;
};


