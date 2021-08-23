#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include"listaEstudiantes.hpp"
#include"colaErrores.hpp"
#include "nodoMatriz.hpp"
#include "listaTareas.hpp"

using namespace std;

int opcion;
int idErrores = 0;
bool repetir = true;
bool validadorRegistro = false;
listaEstudiantes *lista = new listaEstudiantes();
colaErrores *coladeErrores = new colaErrores();
nodoMatriz *matrix[5][30][9];
int contadorId=0;
int dia=0;
int hora=0;
int mes=0;
int indexLinearizado=0;

//lista doble para calendario
listaTareas *tareas = new listaTareas();

string rutaEstudiantes;
string rutaTareas;
void insertLinearizado(){
    for(int x=0; x<5; x++){
        for (int y=0; y<30; y++){
            for (int z=0; z<9; z++){
                if(matrix[x][y][z]!=NULL){
                    mes=x;
                    dia=y;
                    hora=z;
                    indexLinearizado=(dia+30*(hora+9*mes));
                    string indexID = std::to_string(indexLinearizado);
                    
                    tareas->insertarTarea(indexID, matrix[x][y][z]->getMes(), matrix[x][y][z]->getDia(), matrix[x][y][z]->getHora(), matrix[x][y][z]->getCarnet(), matrix[x][y][z]->getNombre(), matrix[x][y][z]->getDescripcion(), matrix[x][y][z]->getMateria(), matrix[x][y][z]->getFecha(), matrix[x][y][z]->getEstado());
                }else{
                    mes=x;
                    dia=y;
                    hora=z;
                    indexLinearizado=(dia+30*(hora+9*mes));
                    string indexID = std::to_string(indexLinearizado);
                    tareas->insertarTarea(indexID, "", "", "", "", "", "", "", "", "");
                }
            }
        }
    }
}

void recorridoPruebaMatrix(){
    for(int x=0; x<5; x++){
        for (int y=0; y<30; y++){
            for (int z=0; z<9; z++){
                if(matrix[x][y][z]!=NULL){
                    cout<<"-------------- Tarea No. "<<matrix[x][y][z]->getId()<<"----------------"<<endl;
                    cout<<matrix[x][y][z]->getId()<<endl;
                    cout<<matrix[x][y][z]->getMes()<<endl;
                    cout<<matrix[x][y][z]->getDia()<<endl;
                    cout<<matrix[x][y][z]->getHora()<<endl;
                    cout<<matrix[x][y][z]->getCarnet()<<endl;
                    cout<<matrix[x][y][z]->getNombre()<<endl;
                    cout<<matrix[x][y][z]->getDescripcion()<<endl;
                    cout<<matrix[x][y][z]->getMateria()<<endl;
                    cout<<matrix[x][y][z]->getFecha()<<endl;
                    cout<<matrix[x][y][z]->getEstado()<<endl;
                    cout<<"-------------------------------------\n"<<endl;
                }
            }
        }
    }
}

int indexHoras(string hora){
    switch(stoi(hora)){
        case 8:
            return 0;
        break;
        case 9:
            return 1;
        break;
        case 10:
            return 2;
        break;
        case 11:
            return 3;
        break;
        case 12:
            return 4;
        break;
        case 13:
            return 5;
        break;
        case 14:
            return 6;
        break;
        case 15:
            return 7;
        break;
        case 16:
            return 8;
        break;
        default:
            return -1;
        
    }
}

int indexMes(string mes){
    switch(stoi(mes)){
        case 7:
            return 0;
        break;
        case 8:
            return 1;
        break;
        case 9:
            return 2;
        break;
        case 10:
            return 3;
        break;
        case 11:
            return 4;
        break;
        default:
            return -1;
        
    }
}


void pruebaMatriz(){
    for(int x=0; x<5; x++){
        for (int y=0; y<30; y++){
            for (int z=0; z<9; z++){
                matrix[x][y][z]=NULL;
            }
        }
    }
    
    
    
    
    
}

void lecturaArchivoTareas(){
    pruebaMatriz();
    cout << "Ingrese la ruta del archivo .csv a cargar: " << endl;
    cin >> rutaTareas;
    ifstream archivo(rutaTareas);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string mes,dia,hora,carnet,nombre,descripcion, materia, fecha,estado;
        
        getline(stream,mes,delimitador);
        getline(stream,dia,delimitador);
        getline(stream,hora,delimitador);
        getline(stream,carnet,delimitador);
        getline(stream,nombre,delimitador);
        getline(stream,descripcion,delimitador);
        getline(stream,materia,delimitador);
        getline(stream,fecha,delimitador);
        getline(stream,estado,delimitador);
        string idStr = std::to_string(contadorId);
        
        matrix[indexMes(mes)][(stoi(dia)-1)][indexHoras(hora)]= new nodoMatriz(idStr,mes,dia,hora,carnet,nombre,descripcion,materia,fecha,estado);
        contadorId=contadorId+1;
    }

    archivo.close();
    recorridoPruebaMatrix();
    insertLinearizado();
    tareas->imprimirLista();
}

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
        
        regex regexCarnet("'\'d{9}");
        regex regexDpi("'\'d{13}");
        regex regexNombre("[a-z A-Z\n]");
        regex regexCarrera("[a-z A-Z\n]");
        regex regexCreditos("'\'d{3}");
        regex regexEdad("'\'d{3}");
        regex regexCorreo("/'\'S+@'\'S+'\'.'\'S+/");
        // Validador de datos correctos en carga masiva de usuarios.
         if(regex_match(carnet,regexCarnet)){
                    cout<<"Carnet de Estudiante No es Valido"<<endl;
                    validadorRegistro = true;
                    coladeErrores->encolar(idErrores, "Estudiante", "Error en Carnet de Estudiante: "+carnet);
                    idErrores=idErrores+1;
                }else{
                    cout<<"Carnet de Estudiante es Valido"<<endl;
                }
                if(regex_match(dpi,regexDpi)){
                    cout<<"DPI de Estudiante No es Valido"<<endl;
                    validadorRegistro = true;
                    coladeErrores->encolar(idErrores, "Estudiante", "Error en DPI de Estudiante: "+dpi);
                    idErrores=idErrores+1;
                }else{
                    cout<<"DPI de Estudiante es Valido"<<endl;
                }
                if(regex_match(nombre,regexNombre)){
                    cout<<"Nombre de Estudiante No es Valido"<<endl;
                    validadorRegistro = true;
                    coladeErrores->encolar(idErrores, "Estudiante", "Error en Nombre de Estudiante: "+nombre);
                    idErrores=idErrores+1;
                }else{
                    cout<<"Nombre de Estudiante es Valido"<<endl;
                }
                if(regex_match(carrera,regexCarrera)){
                    cout<<"Carrera de Estudiante No es Valido"<<endl;
                    validadorRegistro = true;
                    coladeErrores->encolar(idErrores, "Estudiante", "Error en Carrera de Estudiante: "+carrera);
                    idErrores=idErrores+1;
                }else{
                    cout<<"Carrera de Estudiante es Valido"<<endl;
                }
                if(regex_match(creditos,regexCreditos)){
                    cout<<"Creditos de Estudiante No es Valido"<<endl;
                    validadorRegistro = true;
                    coladeErrores->encolar(idErrores, "Estudiante", "Error en Creditos de Estudiante: "+creditos);
                    idErrores=idErrores+1;
                }else{
                    cout<<"Creditos de Estudiante es Valido"<<endl;
                }
                if(regex_match(edad,regexEdad)){
                    
                    cout<<"Edad de Estudiante No es Valido"<<endl;
                    validadorRegistro = true;
                    coladeErrores->encolar(idErrores, "Estudiante", "Error en Edad de Estudiante: "+edad);
                    idErrores=idErrores+1;
                }else{
                    cout<<"Edad de Estudiante es Valido"<<endl;
                }
                if(regex_match(correo,regexCorreo)){
                    
                    cout<<"Correo de Estudiante No es Valido"<<endl;
                    validadorRegistro = true;
                    coladeErrores->encolar(idErrores, "Estudiante", "Error en Correo de Estudiante: "+correo);
                    idErrores=idErrores+1;
                }else{
                    cout<<"Correo de Estudiante es Valido"<<endl;
                }
                
                if(validadorRegistro!=true){
                    lista->insertarValorFinal(carnet, dpi, nombre, carrera, contrasena, creditos, edad, correo);
                }
                validadorRegistro=false;
    }

    archivo.close();
    lista->imprimirListaEstudiantes();
    cout<<"\n"<<endl;
    cout<<"----------------- Cola de Errores -----------------"<<endl;
    coladeErrores->imprimirCola();
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
            lecturaArchivoTareas();
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
    Menu();
    return 0;
}
