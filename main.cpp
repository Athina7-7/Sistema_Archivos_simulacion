#include <iostream>              // Sirve para usar las funciones de cout (mostrar txt) y
                                 // cin (leer texto del usuario)
#include <fstream>               // Para leer y escribir archivos txt
#include <filesystem>           // Permite crear, borrar, buscar y listar carpetas y archivos del sistema
#include <string>               // Para manejar texto en el código

// En vez de escribir std::filesystem::exists(), lo renombramos con fs::exists()
namespace fs = std::filesystem; 

// Para NO escribir std::cout, std::cin sino cout o cin. 
using namespace std;

// Creación de la función main

int main(){
    int opcion;
    
    do {
        cout << "Menu del sistema de archivos" << endl;
        cout << "1. Crear archivo" << endl;
        cout << "2. Eliminar archivo" << endl;
        cout << "3. Crear directorio" << endl;
        cout << "4. Eliminar directorio" << endl;
        cout << "5. Escribir en archivo" << endl;
        cout << "6. Leer archivo" << endl;
        cout << "7. Listar contenido del directorio" << endl;
        cout << "8. Mostrar información de archivo" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        //Limpia el salto de línea que quedó
        cin.ignore(); 

        
        
        switch (opcion){
        case 1:
            // crearArchivo();
        break;
        case 2:
            // eliminarArchivo();
        break;
        case 3: 
            // crearDirectorio();
        break;
        case 4: 
            // eliminarDirectorio();
        break;
        case 5: 
            // escribirArchivo();
        break;
        case 6: 
            // leerArchivo();
        break;
        case 7: 
            // listarDirectorio();
        break;
        case 8:
            // mostrarTxtArchivo();
        break;
        case 9: 
            cout << "Finaliza el programa" << endl;
        break;
        default:
            cout << "Opción incorrecta, elige otra" << endl;
        }
    }while (opcion != 9);
    
    
    return 0;
}