#include <iostream>
#include <string>

using namespace std;

struct Empleado {
    int edad;
    string nombre;
    string apellido;
    string puesto;
    double sueldo;
    char genero; 
};

int main() {
    Empleado empleado;

    cout << "Ingrese edad plis: ";
    cin >> empleado.edad;

    cout << "Ingrese nombre plis: ";
    cin.ignore(); 
    getline(cin, empleado.nombre);
    
    cout << "Ingrese su apellido plis:";
    cin.ignore();
    getline(cin,empleado.apellido);

    cout << "Ingrese puesto plis: ";
    getline(cin, empleado.puesto);

    cout << "Ingrese sueldo plis: ";
    cin >> empleado.sueldo;

    cout << "Ingrese género plis (M/F): ";
    cin >> empleado.genero;

    cout << "Empleado registrado con trienfo mi amor!" << endl;

    cout << "Datos del empleado:" << endl;
    cout << "Edad: " << empleado.edad << endl;
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Apellido:" << empleado.apellido << endl;
    cout << "Puesto: " << empleado.puesto << endl;
    cout << "Salario: " << empleado.sueldo << endl;
    cout << "Género: " << empleado.genero << endl;

    return 0;
}