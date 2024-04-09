//Roberto Carlos de León Gramajo
//5090-23-1762
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definición de la clase Persona
class Persona {
protected:
    struct DatosPersona {
        string nombre;
        string apellido;
        int edad;
        int diaCumple;
        int mesCumple;
        bool tieneTrabajo;
    } datos;

public:
    void obtenerDatosPersona() {
        cout << "Ingrese el nombre: ";
        cin >> datos.nombre;
        cout << "Ingrese el apellido: ";
        cin >> datos.apellido;
        cout << "Ingrese la edad: ";
        cin >> datos.edad;
        cout << "Ingrese el día de cumpleaños: ";
        cin >> datos.diaCumple;
        cout << "Ingrese el mes de cumpleaños: ";
        cin >> datos.mesCumple;
        cout << "¿Tiene trabajo? (1: Sí / 0: No): ";
        cin >> datos.tieneTrabajo;
    }

    void guardarDatosEnArchivo(ofstream &archivo) {
        archivo << "Nombre: " << datos.nombre << endl;
        archivo << "Apellido: " << datos.apellido << endl;
        archivo << "Edad: " << datos.edad << endl;
        archivo << "Cumpleaños: " << datos.diaCumple << "/" << datos.mesCumple << endl;
        archivo << "Tiene trabajo: " << (datos.tieneTrabajo ? "Sí" : "No") << endl;
    }

    // Método para obtener el nombre de la persona
    string obtenerNombre() {
        return datos.nombre;
    }
};

// Definición de la clase Estudiante que hereda de Persona
class Estudiante : public Persona {
private:
    string numeroCarnet;
    int semestre;
    string carreraUniversitaria;
    string horarioClases;

public:
    void obtenerDatosEstudiante() {
        obtenerDatosPersona();
        cout << "Ingrese el número de carnet de estudiante: 5090-23-";
        cin >> numeroCarnet;
        cout << "Ingrese el semestre: ";
        cin >> semestre;
        cout << "Ingrese el nombre de la carrera universitaria: Ingenieria en ";
        cin >> carreraUniversitaria;
        cout << "1ra. Lunes, Miércoles y Viernes de 07:00 a 12:00, Martes y Jueves de 08:30 a 12:00\n";
        cout << "2da. Lunes, Miércoles y Viernes de 07:00 a 12:00, Martes y Jueves de 07:00 a 10:00\n";
        cout << "Elija un horario de clases (1 o 2): ";
        int opcion;
        cin >> opcion;
        horarioClases = (opcion == 1) ? "Lunes, Miércoles y Viernes de 07:00 a 12:00, Martes y Jueves de 08:30 a 12:00"
                                      : "Lunes, Miércoles y Viernes de 07:00 a 12:00, Martes y Jueves de 07:00 a 10:00";
    }

    void guardarDatosEnArchivo(ofstream &archivo) {
        Persona::guardarDatosEnArchivo(archivo);
        archivo << "Número de carnet: 5090-23-" << numeroCarnet << endl;
        archivo << "Semestre: " << semestre << endl;
        archivo << "Carrera universitaria: " << carreraUniversitaria << endl;
        archivo << "Horario de clases: " << horarioClases << endl;
    }
};

// Función para el algoritmo de ordenamiento de burbuja
void ordenarNombres(string nombres[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (nombres[j] > nombres[j + 1]) {
                swap(nombres[j], nombres[j + 1]);
            }
        }
    }
}

int main() {
    ofstream archivo("Hojadetrabajo.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    const int cantidadEstudiantes = 5;
    Estudiante estudiantes[cantidadEstudiantes];

    // Obtener datos de los estudiantes
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        cout << "Ingrese los datos del estudiante " << i + 1 << ":" << endl;
        estudiantes[i].obtenerDatosEstudiante();
        cout << endl;
    }

    // Guardar los datos de los estudiantes en el archivo
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        archivo << "Datos del estudiante " << i + 1 << ":" << endl;
        estudiantes[i].guardarDatosEnArchivo(archivo);
        archivo << endl;
    }

    // Lista de nombres de estudiantes para ordenar
    string nombres[cantidadEstudiantes];
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        nombres[i] = estudiantes[i].obtenerNombre();
    }

    // Ordenar los nombres de los estudiantes
    ordenarNombres(nombres, cantidadEstudiantes);

    // Mostrar los nombres ordenados
    cout << "Nombres de estudiantes ordenados:" << endl;
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        cout << nombres[i] << endl;
    }

    archivo.close();
    return 0;
}

