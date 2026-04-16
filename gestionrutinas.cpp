#include "clases.h"

// ==========================
// CLASE EJERCICIO
// ==========================

Ejercicio::Ejercicio(
    int codigo,
    string nombre,
    string tipo,
    string nivelIntensidad,
    int tiempoMinutos,
    string descripcion,
    int semanaUltimoUso
) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->tipo = tipo;
    this->nivelIntensidad = nivelIntensidad;
    this->tiempoMinutos = tiempoMinutos;
    this->descripcion = descripcion;
    this->semanaUltimoUso = semanaUltimoUso;
}

Ejercicio::~Ejercicio() {
}

void Ejercicio::mostrarInfo() {
    cout << "Codigo: " << this->codigo << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Tipo: " << this->tipo << endl;
    cout << "Nivel de intensidad: " << this->nivelIntensidad << endl;
    cout << "Tiempo estimado: " << this->tiempoMinutos << " minutos" << endl;
    cout << "Descripcion: " << this->descripcion << endl;
    cout << "Semana ultimo uso: " << this->semanaUltimoUso << endl;
}

// ==========================
// CLASE ejercicioCardio
// ==========================

ejercicioCardio::ejercicioCardio(
    int codigo,
    string nombre,
    string nivelIntensidad,
    int tiempoMinutos,
    string descripcion,
    int semanaUltimoUso
) : Ejercicio(codigo, nombre, "Cardio", nivelIntensidad, tiempoMinutos, descripcion, semanaUltimoUso) {
}

ejercicioCardio::~ejercicioCardio() {
}

void ejercicioCardio::mostrarInfo() {
    cout << "----- EJERCICIO CARDIOVASCULAR -----" << endl;
    Ejercicio::mostrarInfo();
}

// ==========================
// CLASE ejercicioFuerza
// ==========================

ejercicioFuerza::ejercicioFuerza(
    int codigo,
    string nombre,
    string nivelIntensidad,
    int tiempoMinutos,
    string descripcion,
    int semanaUltimoUso
) : Ejercicio(codigo, nombre, "Fuerza", nivelIntensidad, tiempoMinutos, descripcion, semanaUltimoUso) {
}

ejercicioFuerza::~ejercicioFuerza() {
}

void ejercicioFuerza::mostrarInfo() {
    cout << "----- EJERCICIO DE FUERZA -----" << endl;
    Ejercicio::mostrarInfo();
}

// ==========================
// CLASE Rutina
// ==========================

Rutina::Rutina(string cliente, int semana) {
    this->cliente = cliente;
    this->semana = semana;
}

Rutina::~Rutina() {
}

void Rutina::agregarEejercicio(Ejercicio* ejercicio) {
    this->ejercicios.push_back(ejercicio);
}

bool Rutina::contieneEjercicio(int codigo) {
    for (int i = 0; i < this->ejercicios.size(); i++) {
        if (this->ejercicios[i]->codigo == codigo) {
            return true;
        }
    }
    return false;
}

void Rutina::eliminarEjercicio(int codigo) {
    for (int i = 0; i < this->ejercicios.size(); i++) {
        if (this->ejercicios[i]->codigo == codigo) {
            this->ejercicios.erase(this->ejercicios.begin() + i);
            i--;
        }
    }
}

int Rutina::calcularTiempoTotal() {
    int total = 0;

    for (int i = 0; i < this->ejercicios.size(); i++) {
        total += this->ejercicios[i]->tiempoMinutos;
    }

    return total;
}

void Rutina::mostrarRutina() {
    cout << "====================================" << endl;
    cout << "Cliente: " << this->cliente << endl;
    cout << "Semana: " << this->semana << endl;
    cout << "Cantidad de ejercicios: " << this->ejercicios.size() << endl;
    cout << "------------------------------------" << endl;

    for (int i = 0; i < this->ejercicios.size(); i++) {
        this->ejercicios[i]->mostrarInfo();
        cout << "------------------------------------" << endl;
    }

    cout << "Tiempo total estimado: " << this->calcularTiempoTotal() << " minutos" << endl;
    cout << "====================================" << endl;
}

// ==========================
// CLASE SistemaEntrenamiento
// ==========================

SistemaEntrenamiento::SistemaEntrenamiento() {
}

SistemaEntrenamiento::~SistemaEntrenamiento() {
    for (int i = 0; i < this->rutinas.size(); i++) {
        delete this->rutinas[i];
    }

    for (int i = 0; i < this->ejercicios.size(); i++) {
        delete this->ejercicios[i];
    }
}

string SistemaEntrenamiento::obtenerNivelIntensidad(int opcion) {
    if (opcion == 1) {
        return "Basico";
    }
    if (opcion == 2) {
        return "Intermedio";
    }
    if (opcion == 3) {
        return "Avanzado";
    }
    if (opcion == 4) {
        return "Alto rendimiento";
    }

    return "";
}

Ejercicio* SistemaEntrenamiento::buscarEjercicioPorCodigo(int codigo) {
    for (int i = 0; i < this->ejercicios.size(); i++) {
        if (this->ejercicios[i]->codigo == codigo) {
            return this->ejercicios[i];
        }
    }

    return NULL;
}

bool SistemaEntrenamiento::fueUsadoSemAnterior(string cliente, int semanaActual, int codigoEjercicio) {
    for (int i = 0; i < this->rutinas.size(); i++) {
        if (this->rutinas[i]->cliente == cliente && this->rutinas[i]->semana == semanaActual - 1) {
            if (this->rutinas[i]->contieneEjercicio(codigoEjercicio)) {
                return true;
            }
        }
    }

    return false;
}

void SistemaEntrenamiento::crearEjercicio() {
    int codigo;
    string nombre;
    int tipoOpcion;
    int intensidadOpcion;
    string nivelIntensidad;
    int tiempoMinutos;
    string descripcion;

    cout << "Ingrese codigo del ejercicio: ";
    cin >> codigo;

    if (this->buscarEjercicioPorCodigo(codigo) != NULL) {
        cout << "Ya existe un ejercicio con ese codigo." << endl;
        return;
    }

    cin.ignore(1000, '\n');

    cout << "Ingrese el nombre del ejercicio: ";
    getline(cin, nombre);

    cout << "Seleccione tipo de ejercicio:" << endl;
    cout << "1. Cardiovascular" << endl;
    cout << "2. Fuerza" << endl;
    cout << "Opcion: ";
    cin >> tipoOpcion;

    cout << "Seleccione el nivel de intensidad:" << endl;
    cout << "1. Basico" << endl;
    cout << "2. Intermedio" << endl;
    cout << "3. Avanzado" << endl;
    cout << "4. Alto rendimiento" << endl;
    cout << "Opcion: ";
    cin >> intensidadOpcion;

    nivelIntensidad = this->obtenerNivelIntensidad(intensidadOpcion);

    if (nivelIntensidad == "") {
        cout << "Nivel invalido." << endl;
        return;
    }

    cout << "Ingrese tiempo estimado en minutos: ";
    cin >> tiempoMinutos;

    cin.ignore(1000, '\n');

    cout << "Ingrese la descripcion del ejercicio: ";
    getline(cin, descripcion);

    Ejercicio* nuevoEjercicio = NULL;

    if (tipoOpcion == 1) {
        nuevoEjercicio = new ejercicioCardio(codigo, nombre, nivelIntensidad, tiempoMinutos, descripcion, 0);
    } else if (tipoOpcion == 2) {
        nuevoEjercicio = new ejercicioFuerza(codigo, nombre, nivelIntensidad, tiempoMinutos, descripcion, 0);
    } else {
        cout << "Tipo invalido." << endl;
        return;
    }

    this->ejercicios.push_back(nuevoEjercicio);
    cout << "Ejercicio creado correctamente." << endl;
}

void SistemaEntrenamiento::actualizarEjercicio() {
    int codigo;
    int intensidadOpcion;
    string nivelIntensidad;

    cout << "Ingrese codigo del ejercicio a actualizar: ";
    cin >> codigo;

    Ejercicio* ejercicio = this->buscarEjercicioPorCodigo(codigo);

    if (ejercicio == NULL) {
        cout << "No se encontro el ejercicio." << endl;
        return;
    }

    cin.ignore(1000, '\n');

    cout << "Ingrese nuevo nombre: ";
    getline(cin, ejercicio->nombre);

    cout << "Seleccione nuevo nivel de intensidad:" << endl;
    cout << "1. Basico" << endl;
    cout << "2. Intermedio" << endl;
    cout << "3. Avanzado" << endl;
    cout << "4. Alto rendimiento" << endl;
    cout << "Opcion: ";
    cin >> intensidadOpcion;

    nivelIntensidad = this->obtenerNivelIntensidad(intensidadOpcion);

    if (nivelIntensidad == "") {
        cout << "Nivel invalido." << endl;
        return;
    }

    ejercicio->nivelIntensidad = nivelIntensidad;

    cout << "Ingrese nuevo tiempo estimado en minutos: ";
    cin >> ejercicio->tiempoMinutos;

    cin.ignore(1000, '\n');

    cout << "Ingrese nueva descripcion: ";
    getline(cin, ejercicio->descripcion);

    cout << "Ejercicio actualizado correctamente." << endl;
}

void SistemaEntrenamiento::eliminarEjercicio() {
    int codigo;

    cout << "Ingrese codigo del ejercicio a eliminar: ";
    cin >> codigo;

    for (int i = 0; i < this->ejercicios.size(); i++) {
        if (this->ejercicios[i]->codigo == codigo) {
            for (int j = 0; j < this->rutinas.size(); j++) {
                this->rutinas[j]->eliminarEjercicio(codigo);
            }

            delete this->ejercicios[i];
            this->ejercicios.erase(this->ejercicios.begin() + i);

            cout << "Ejercicio eliminado correctamente." << endl;
            return;
        }
    }

    cout << "No se encontro el ejercicio." << endl;
}

void SistemaEntrenamiento::consultarEjercicio() {
    int codigo;

    cout << "Ingrese codigo del ejercicio a consultar: ";
    cin >> codigo;

    Ejercicio* ejercicio = this->buscarEjercicioPorCodigo(codigo);

    if (ejercicio == NULL) {
        cout << "No se encontro el ejercicio." << endl;
        return;
    }

    ejercicio->mostrarInfo();
}

void SistemaEntrenamiento::buscarPorIntensidad() {
    int intensidadOpcion;
    string nivelIntensidad;
    bool encontrado = false;

    cout << "Seleccione nivel de intensidad a buscar:" << endl;
    cout << "1. Basico" << endl;
    cout << "2. Intermedio" << endl;
    cout << "3. Avanzado" << endl;
    cout << "4. Alto rendimiento" << endl;
    cout << "Opcion: ";
    cin >> intensidadOpcion;

    nivelIntensidad = this->obtenerNivelIntensidad(intensidadOpcion);

    if (nivelIntensidad == "") {
        cout << "Nivel invalido." << endl;
        return;
    }

    for (int i = 0; i < this->ejercicios.size(); i++) {
        if (this->ejercicios[i]->nivelIntensidad == nivelIntensidad) {
            this->ejercicios[i]->mostrarInfo();
            cout << "------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron ejercicios con ese nivel." << endl;
    }
}

void SistemaEntrenamiento::generarRutina() {
    string cliente;
    int semana;
    int cantidadEjercicios;
    int intensidadOpcion;
    string nivelIntensidad;

    if (this->ejercicios.size() == 0) {
        cout << "No hay ejercicios registrados." << endl;
        return;
    }

    cin.ignore(1000, '\n');

    cout << "Ingrese nombre del cliente: ";
    getline(cin, cliente);

    cout << "Ingrese numero de semana: ";
    cin >> semana;

    cout << "Ingrese cantidad de ejercicios: ";
    cin >> cantidadEjercicios;

    cout << "Seleccione nivel de intensidad deseado:" << endl;
    cout << "1. Basico" << endl;
    cout << "2. Intermedio" << endl;
    cout << "3. Avanzado" << endl;
    cout << "4. Alto rendimiento" << endl;
    cout << "Opcion: ";
    cin >> intensidadOpcion;

    nivelIntensidad = this->obtenerNivelIntensidad(intensidadOpcion);

    if (nivelIntensidad == "") {
        cout << "Nivel invalido." << endl;
        return;
    }

    Rutina* nuevaRutina = new Rutina(cliente, semana);
    int contador = 0;

    for (int i = 0; i < this->ejercicios.size(); i++) {
        if (this->ejercicios[i]->nivelIntensidad == nivelIntensidad &&
            !this->fueUsadoSemAnterior(cliente, semana, this->ejercicios[i]->codigo) &&
            !nuevaRutina->contieneEjercicio(this->ejercicios[i]->codigo)) {

            nuevaRutina->agregarEejercicio(this->ejercicios[i]);
            contador++;

            if (contador == cantidadEjercicios) {
                break;
            }
        }
    }

    if (contador < cantidadEjercicios) {
        cout << "No hay suficientes ejercicios disponibles para generar la rutina." << endl;
        delete nuevaRutina;
        return;
    }

    for (int i = 0; i < nuevaRutina->ejercicios.size(); i++) {
        nuevaRutina->ejercicios[i]->semanaUltimoUso = semana;
    }

    this->rutinas.push_back(nuevaRutina);

    cout << "Rutina generada correctamente." << endl;
    nuevaRutina->mostrarRutina();
}

void SistemaEntrenamiento::mostrarTodosLosEjercicios() {
    if (this->ejercicios.size() == 0) {
        cout << "No hay ejercicios registrados." << endl;
        return;
    }

    for (int i = 0; i < this->ejercicios.size(); i++) {
        this->ejercicios[i]->mostrarInfo();
        cout << "------------------------------------" << endl;
    }
}

void SistemaEntrenamiento::cargarDatosIniciales() {
    this->ejercicios.push_back(new ejercicioCardio(1, "Trote suave", "Basico", 15, "Trotar a ritmo moderado durante 15 minutos.", 0));
    this->ejercicios.push_back(new ejercicioCardio(2, "Saltos en el lugar", "Intermedio", 10, "Realizar saltos continuos manteniendo postura estable.", 0));
    this->ejercicios.push_back(new ejercicioCardio(3, "Burpees", "Avanzado", 12, "Ejecutar burpees completos con tecnica controlada.", 0));
    this->ejercicios.push_back(new ejercicioCardio(4, "Sprint en pista", "Alto rendimiento", 8, "Realizar piques de alta intensidad con pausas cortas.", 0));

    this->ejercicios.push_back(new ejercicioFuerza(5, "Sentadillas", "Basico", 12, "Bajar y subir controlando la postura.", 0));
    this->ejercicios.push_back(new ejercicioFuerza(6, "Flexiones de brazos", "Intermedio", 10, "Ejecutar flexiones manteniendo alineacion corporal.", 0));
    this->ejercicios.push_back(new ejercicioFuerza(7, "Peso muerto", "Avanzado", 14, "Levantar carga con tecnica correcta.", 0));
    this->ejercicios.push_back(new ejercicioFuerza(8, "Dominadas", "Alto rendimiento", 10, "Realizar dominadas con control total.", 0));
}