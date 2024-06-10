#include <iostream>
#include <string>

using namespace std;

void mostrarEstante1() {
  cout << "Estante 1: Leches de 1 tr.\n";
  cout << "  - Entera\n";
  cout << "  - Deslactosada\n";
  cout << "  - Descremada\n";
}

void mostrarEstante2() {
  cout << "Estante 2: Leches de 1.5 trs.\n";
  cout << "  - Entera\n";
  cout << "  - Deslactosada\n";
  cout << "  - Descremada\n";
}

void mostrarEstante3() {
  cout << "Estante 3: Leches de 2 trs.\n";
  cout << "  - Entera\n";
  cout << "  - Deslactosada\n";
  cout << "  - Descremada\n";
}

void mostrarEstante4() {
  cout << "Estante 4: Leches en botella de 250 ml\n";
  cout << "  - Entera\n";
  cout << "  - Fresa\n";
  cout << "  - Vainilla\n";
  cout << "  - Chocolate\n";
  cout << "  - Chocomenta\n";
  cout << "  - Cookies and Cream\n";
}

void mostrarEstante5() {
  cout << "Estante 5: Leche en caja pequeña de 180 ml\n";
  cout << "  - Entera\n";
  cout << "  - Fresa\n";
  cout << "  - Vainilla\n";
  cout << "  - Chocolate\n";
  cout << "  - Chocomenta\n";
  cout << "  - Cookies and Cream\n";
}

int main() {
  cout << "Bienvenido a DELI LECHE!\n";
  cout << "Seleccione una opción para ver los productos:\n";
  cout << "1. Estante 1: Leches de 1 tr.\n";
  cout << "2. Estante 2: Leches de 1.5 trs.\n";
  cout << "3. Estante 3: Leches de 2 trs.\n";
  cout << "4. Estante 4: Leches en botella de 250 ml\n";
  cout << "5. Estante 5: Leche en caja pequeña de 180 ml\n";
  cout << "6. Regresar al menú principal\n";

  int opcion;
  cin >> opcion;

  while (opcion!= 6) {
    switch (opcion) {
      case 1:
        mostrarEstante1();
        break;
      case 2:
        mostrarEstante2();
        break;
      case 3:
        mostrarEstante3();
        break;
      case 4:
        mostrarEstante4();
        break;
      case 5:
        mostrarEstante5();
        break;
      default:
        cout << "Opción inválida. Intente de nuevo.\n";
    }

    cout << "\nPresione 6 para regresar al menú principal o seleccione otra opción:\n";
    cin >> opcion;
  }

  cout << "Gracias por visitar DELI LECHE!\n";
  return 0;
}