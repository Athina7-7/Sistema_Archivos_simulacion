#include <iostream>
#include <fstream>
#include <filesystem>
#include "funciones.h"
#include <chrono>
#include <ctime>


namespace fs = std::filesystem;
using namespace std;

void crearArchivo(){
    string ruta;
    cout << "Ingresar ruta del archivo que desea crear: ";
    getline(cin, ruta);

    if(fs::exists(ruta)){
        cout << "Ya existe este archivo" << endl;
    } else{
        ofstream archivo(ruta);
        if (archivo) {
            cout << "Archivo creado exitosamente." << endl;
            archivo.close();
        } else{
            cout << "No se pudo crear el archivo" << endl;
        }
    }

}

void eliminarArchivo() {
    string ruta;
    cout << "Ingresar ruta del archivo que desea eliminar: ";
    getline(cin, ruta);

    if (!fs::exists(ruta)) {
        cout << "El archivo no existe" << endl;
    } else {
        if (fs::remove(ruta)) {
            cout << "Archivo eliminado " << endl;
        } else {
            cout << "No se pudo eliminar el archivo" << endl;
        }


    }

}

void crearDirectorio() {
    string ruta;
    cout << "Ingresar ruta del directorio que desea crear: ";
    getline(cin, ruta);

    if (fs::exists(ruta)) {
        cout << "El directorio ya existe" << endl;
    } else {
        if (fs::create_directory(ruta)) {
            cout << "Directorio creado correctamente" << endl;
        } else {
            cout << "No se pudo crear el directorio " << endl;
        }
    }
}

void eliminarDirectorio() {
    string ruta;
    cout << "Ingresar ruta del directorio que desea eliminar: ";
    getline(cin, ruta);

    if (!fs::exists(ruta) || !fs::is_directory(ruta)) {
        cout << "El directorio no existe o no es válido" << endl;
    } else {
        uintmax_t cantidad = fs::remove_all(ruta);
        cout << "Se eliminaron " << cantidad << endl;
    }


}


void escribirArchivo() {
    string ruta;
    cout << "Ingresar la ruta del archivo donde desea escribir: ";
    getline(cin, ruta);

    ofstream archivo(ruta, ios::app); // modo 'append' para agregar sin borrar lo anterior

    if (!archivo) {
        cout << "No se puede abrir o crear el archivo." << endl;
        return;
    }

    string contenido;
    cout << "Escribir el texto a guardar (finalice con una línea vacía):\n";

    while (true) {
        getline(cin, contenido);
        if (contenido.empty()) break;
        archivo << contenido << endl;
    }

    archivo.close();
    cout << "Contenido guardado" << endl;
}


void leerArchivo() {
    string ruta;
    cout << "Ingresar la ruta del archivo a leer: ";
    getline(cin, ruta);

    ifstream archivo(ruta);

    if (!archivo) {
        cout << "No se puede abrir el archivo." << endl;
        return;
    }

    string linea;
    cout << "Contenido del archivo:\n";
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}


void listarDirectorio() {
    string ruta;
    cout << "Ingresar la ruta del directorio: ";
    getline(cin, ruta);

    if (!fs::exists(ruta) || !fs::is_directory(ruta)) {
        cout << "Ruta inválida o no es un directorio." << endl;
        return;
    }

    cout << "Contenido del directorio:\n";
    for (const auto& entrada : fs::directory_iterator(ruta)) {
        cout << " - " << entrada.path().filename().string();
        if (fs::is_directory(entrada)) cout << " [Directorio]";
        else if (fs::is_regular_file(entrada)) cout << " [Archivo]";
        cout << endl;
    }
}



void mostrarTxtArchivo() {
    string ruta;
    cout << "Ingrese la ruta del archivo: ";
    getline(cin, ruta);

    if (!fs::exists(ruta)) {
        cout << "El archivo no existe." << endl;
        return;
    }

    cout << "Información del archivo:\n";
    cout << "Nombre: " << fs::path(ruta).filename().string() << endl;
    cout << "Ruta absoluta: " << fs::absolute(ruta) << endl;

    if (fs::is_regular_file(ruta)) {
        cout << "Tipo: Archivo\n";
        cout << "Tamaño: " << fs::file_size(ruta) << " bytes\n";
    } else if (fs::is_directory(ruta)) {
        cout << "Tipo: Directorio\n";
    }

    auto ftime = fs::last_write_time(ruta);
    auto sctp = chrono::time_point_cast<chrono::system_clock::duration>(
        ftime - fs::file_time_type::clock::now() + chrono::system_clock::now());
    time_t cftime = chrono::system_clock::to_time_t(sctp);
    cout << "Última modificación: " << std::asctime(std::localtime(&cftime));

}
