//
//  main.cpp
//  Practica1PruebasXCODE
//
//  Created by NegroCorado on 16/08/21.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include"listaEstudiantes.hpp"
#include"colaErrores.hpp"
using namespace std;

int opcion;
bool repetir = true;
listaEstudiantes *lista = new listaEstudiantes();
colaErrores *coladeErrores = new colaErrores();

string rutaEstudiantes;

void lecturaArchivoEstudiantes()
{
    cout << "Ingrese la ruta del archivo .csv a cargar: " << endl;
    cin >> rutaEstudiantes;
    ifstream archivo(rutaEstudiantes);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string carnet, dpi, nombre, carrera, correo, contrasena, creditos, edad;
        
        getline(stream,carnet,delimitador);
        getline(stream,dpi,delimitador);
        getline(stream,nombre,delimitador);
        getline(stream,carrera,delimitador);
        getline(stream,contrasena,delimitador);
        getline(stream,creditos,delimitador);
        getline(stream,edad,delimitador);
        getline(stream,correo,delimitador);

        lista->insertarValorFinal(carnet, dpi, nombre, carrera, contrasena, creditos, edad, correo);
        //cout << linea << endl;
        // Magia aquí...
    }

    archivo.close();
    lista->imprimirListaEstudiantes();
}

void Menu()
{
    do
    {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\n\t\t\tMenu de Opciones" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Carga de Usuarios" << endl;
        cout << "\t2. Carga de Tareas" << endl;
        cout << "\t3. Ingreso Manual" << endl;
        cout << "\t4. Reportes" << endl;
        cout << "\t0. SALIR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Aqui ira todo lo referente a Cargar Usuarios
            cout << "AQUI LLAMAREMOS EL METODO DE CARGAR USUARIOS" << endl;
            lecturaArchivoEstudiantes();
            break;

        case 2:
            // Aqui ira todo lo referente a Cargar Tareas
            cout << "AQUI LLAMAREMOS EL METODO DE CARGAR TAREAS" << endl;
            break;

        case 3:
            // Aqui ira todo lo referente a Ingreso Manual
            cout << "AQUI LLAMAREMOS EL METODO DE INGRESO MANUAL" << endl;
            break;

        case 4:
            // Aqui ira todo lo referente a Reportes
            cout << "AQUI LLAMAREMOS EL METODO DE Reportes" << endl;
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}

int main()
{
    //listaEstudiantes *lista = new listaEstudiantes();
    //coladeErrores->encolar(0, "Alumno", "problema con Nombre: 234345534");
    //coladeErrores->encolar(1, "Tarea", "Error en Fecha no Valida: 30/02/2021");
    //coladeErrores->imprimirCola();
    

    //lista->insertarValorFinal("201313861","2290361550101","Walther Andree Corado Paiz","Ciencias y Sistemas","waltercoradpaiz@gmail.com","Computadora.62","99","28");
    //lista->insertarValorFinal("201313841","2290361540101","Mynor Estuardo Cordon Lopez","Industrial","mynorlx2@gmail.com","Sofia2021","10","27");
    //lista->imprimirListaEstudiantes();
    //cout << "Prueba de C++ on MacOs" << endl;
    //Menu();
    return 0;
}
