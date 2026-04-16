#include <iostream>
#include <vector>
#include "clases.h" // Asegúrate de incluir el archivo de clases

int main() {
    SistemaEntrenamiento sistema;
    sistema.cargarDatosIniciales(); // Asegúrate de haber implementado esta función correctamente

    int opcion = -1;

    while (opcion != 0) {
        cout << endl;
        cout << "========= SISTEMA DE GESTION DE RUTINAS =========" << endl;
        cout << "1. Crear ejercicio" << endl;
        cout << "2. Actualizar ejercicio" << endl;
        cout << "3. Eliminar ejercicio" << endl;
        cout << "4. Consultar ejercicio" << endl;
        cout << "5. Buscar ejercicios por intensidad" << endl;
        cout << "6. Generar rutina" << endl;
        cout << "7. Mostrar todos los ejercicios" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                sistema.crearEjercicio();
                break;
            case 2:
                sistema.actualizarEjercicio();
                break;
            case 3:
                sistema.eliminarEjercicio();
                break;
            case 4:
                sistema.consultarEjercicio();
                break;
            case 5:
                sistema.buscarPorIntensidad();
                break;
            case 6:
                sistema.generarRutina();
                break;
            case 7:
                sistema.mostrarTodosLosEjercicios();
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    }

    return 0;
}