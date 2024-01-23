#include <iostream>
#include <cmath>

using namespace std;

class Vector3D {
    private:
        double x, y, z;

        public:
            Vector3D(double x_val = 0, double y_val = 0, double z_val = 0)
                : x(x_val), y(y_val), z(z_val) {}

            Vector3D operator+(const Vector3D& other) const {
                return Vector3D(x + other.x, y + other.y, z + other.z);
            }

            Vector3D operator-(const Vector3D& other) const {
                return Vector3D(x - other.x, y - other.y, z - other.z);
            }

            double dotProduct(const Vector3D& other) const {
                return x * other.x + y * other.y + z * other.z;
            }

            double length() const {
                return sqrt(x * x + y * y + z * z);
            }

            double cosineAngle(const Vector3D& other) const {
                double dot = dotProduct(other);
                double lengthProduct = length() * other.length();
                return dot / lengthProduct;
            }

            void print() const {
                cout << "(" << x << ", " << y << ", " << z << ")";
            }
 };

int main() {
    double x, y, z;
    setlocale(LC_ALL, "Russian");
    char operation;
    char back;

    Vector3D a, b;

    do {
        cout << "1. Ввести векторы\n2. Сложить векторы\n3. Вычесть векторы\n4. Вычислить скалярное произведение\n5. Вычислить длину векторов\n6. Вычислить косинус угла между векторами\n7. Выйти\nВыберите операцию: ";
        cin >> operation;

        switch (operation) {
        case '1':
            cout << "Введите координаты вектора a: ";
            cin >> x >> y >> z;
            a = Vector3D(x, y, z);

            cout << "Введите координаты вектора b: ";
            cin >> x >> y >> z;
            b = Vector3D(x, y, z);
            break;

        case '2':
            cout << "Сумма векторов a и b равна ", (a + b).print();
            cout << "\n\nНажмите 1 для возврата к основному меню или любую другую клавишу для выхода: ";
            cin >> back;
            if (back != '1') operation = '7';
            break;

        case '3':
            cout << "Разность векторов a и b равна ", (a - b).print();
            cout << "\n\nНажмите 1 для возврата к основному меню или любую другую клавишу для выхода: ";
            cin >> back;
            if (back != '1') operation = '7';
            break;

        case '4':
            cout << "Скалярное произведение векторов a и b равно " << a.dotProduct(b);
            cout << "\n\nНажмите 1 для возврата к основному меню или любую другую клавишу для выхода: ";
            cin >> back;
            if (back != '1') operation = '7';
            break;

        case '5':
            cout << "Длина вектора a: " << a.length() << "\nДлина вектора b: " << b.length();
            cout << "\n\nНажмите 1 для возврата к основному меню или любую другую клавишу для выхода: ";
            cin >> back;
            if (back != '1') operation = '7';
            break;

        case '6':
            cout << "Косинус угла между векторами a и b: " << a.cosineAngle(b);
            cout << "\n\nНажмите 1 для возврата к основному меню или любую другую клавишу для выхода: ";
            cin >> back;
            if (back != '1') operation = '7';
            break;

        case '7':
            cout << "Выход из программы.";
            break;

        default:
            cout << "Неверный ввод, попробуйте снова.";
        }

        cout << std::endl;
    } while (operation != '7');

    return 0;
}

