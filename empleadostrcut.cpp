#include <iostream>
#include <string>

using namespace std;

struct Empleado {
    int edad;
    string nombre;
    string puesto;
    double salario;
    char genero; // 'M' para masculino, 'F' para femenino
};

int main() {
    Empleado empleado;

    cout << "Ingrese edad: ";
    cin >> empleado.edad;

    cout << "Ingrese nombre: ";
    cin.ignore(); // limpiar buffer de entrada
    getline(cin, empleado.nombre);

    cout << "Ingrese puesto: ";
    getline(cin, empleado.puesto);

    cout << "Ingrese salario: ";
    cin >> empleado.salario;

    cout << "Ingrese género (M/F): ";
    cin >> empleado.genero;

    cout << "Empleado creado con éxito!" << endl;

    cout << "Datos del empleado:" << endl;
    cout << "Edad: " << empleado.edad << endl;
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Puesto: " << empleado.puesto << endl;
    cout << "Salario: " << empleado.salario << endl;
    cout << "Género: " << empleado.genero << endl;

    return 0;
}