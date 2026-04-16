#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <vector>
using namespace std;

class Ejercicio {
public:
    int codigo;
    string nombre;
    string tipo;
    string nivelIntensidad;
    int tiempoMinutos;
    string descripcion;
    int semanaUltimoUso;

    Ejercicio(int codigo, string nombre, string tipo, string nivelIntensidad, int tiempoMinutos, string descripcion, int semanaUltimoUso);
    ~Ejercicio();

    virtual void mostrarInfo();
};

class ejercicioCardio : public Ejercicio {
public:
    ejercicioCardio(int codigo, string nombre, string nivelIntensidad, int tiempoMinutos, string descripcion, int semanaUltimoUso);
    ~ejercicioCardio();
    void mostrarInfo();
};

class ejercicioFuerza : public Ejercicio {
public:
    ejercicioFuerza(int codigo, string nombre, string nivelIntensidad, int tiempoMinutos, string descripcion, int semanaUltimoUso);
    ~ejercicioFuerza();
    void mostrarInfo();
};

class Rutina {
public:
    string cliente;
    int semana;
    vector<Ejercicio*> ejercicios;

    Rutina(string cliente, int semana);
    ~Rutina();

    void agregarEejercicio(Ejercicio* ejercicio);
    bool contieneEjercicio(int codigo);
    void eliminarEjercicio(int codigo);
    int calcularTiempoTotal();
    void mostrarRutina();
};

class SistemaEntrenamiento {
public:
    vector<Ejercicio*> ejercicios;
    vector<Rutina*> rutinas;

    SistemaEntrenamiento();
    ~SistemaEntrenamiento();

    string obtenerNivelIntensidad(int opcion);
    Ejercicio* buscarEjercicioPorCodigo(int codigo);
    bool fueUsadoSemAnterior(string cliente, int semanaActual, int codigoEjercicio);

    void crearEjercicio();
    void actualizarEjercicio();
    void eliminarEjercicio();
    void consultarEjercicio();
    void buscarPorIntensidad();
    void generarRutina();
    
    // Aquí está la declaración del método mostrarTodosLosEjercicios
    void mostrarTodosLosEjercicios(); // Función declarada correctamente

    void cargarDatosIniciales();
};

#endif
