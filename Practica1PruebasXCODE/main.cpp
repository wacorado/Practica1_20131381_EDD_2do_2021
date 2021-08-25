#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <string>
#include"listaEstudiantes.hpp"
#include"colaErrores.hpp"
#include "nodoMatriz.hpp"
#include "listaTareas.hpp"

using namespace std;

void Menu();
int opcion, opcion2, opcion3, opcion4;
int idErrores = 0;
bool repetir = true;
bool validadorRegistro = false;
bool validarRegistroTarea=true;
bool cargaMasivaTarea=false;
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
    string mes,dia,hora,carnet,nombre,descripcion, materia, fecha,estado;
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
        
        
        getline(stream,mes,delimitador);
        getline(stream,dia,delimitador);
        getline(stream,hora,delimitador);
        getline(stream,carnet,delimitador);
        getline(stream,nombre,delimitador);
        getline(stream,descripcion,delimitador);
        getline(stream,materia,delimitador);
        getline(stream,fecha,delimitador);
        getline(stream,estado,delimitador);
        
        const regex regexMes("^[7-9]{1}$|^1[0-1]$");
        const regex regexDia("^[1-9]$|^[1-2][0-9]$|^3[0]$");
        const regex regexHora("^[8-9]$|^1[0-6]$");
        const regex regexCarnet("\\d{9}");
        const regex regexNombre("^[a-z A-Z 0-9 \\á\\Á\\é\\É\\í\\Í\\ó\\Ó\\Ú\\ú\\+]+$");
        //const regex regexDescripcion("[a-z A-Z]\\n á é í ó ú");
        const regex regexMateria("^[a-z A-Z 0-9 \\á\\Á\\é\\É\\í\\Í\\ó\\Ó\\Ú\\ú\\+]+$");
        const regex regexFecha("^2021\\/(0[7-9]|1[0-1])\\/(0[1-9]|[1-2][0-9]|3[0])");
        const regex regexEstado("^[a-z A-Z \\n]+$");
        
        
            
        if ((regex_match(mes,regexMes))){
                    if((regex_match(dia,regexDia))){
                        if((regex_match(hora,regexHora))){
                            if((regex_match(carnet,regexCarnet))){
                                if(lista->encontrarCarnet(stoi(carnet))){
                                    cout<<"Carnet Encontrado Correctamente dentro de Estudiantes"<<endl;
                                }else{
                                    cout<<"Error en carnet  No Registrado en Alumnos no se registrara Tarea"<<endl;
                                    validarRegistroTarea=false;
                                    coladeErrores->encolar(idErrores, "Tarea", "Error en carnet de Tarea: "+carnet);
                                    idErrores=idErrores+1;
                                }
                                if((regex_match(nombre,regexNombre))){
                                    if((regex_match(materia,regexMateria))){
                                        if((regex_match(fecha,regexFecha))){
                                            if((regex_match(estado,regexEstado))){
                                                
                                                cout<<"Error en Estado de tarea es un estado no Valido aun asi se registrara la tarea"<<endl;
                                                coladeErrores->encolar(idErrores, "Tarea", "Error en Estado de Tarea: "+estado);
                                                idErrores=idErrores+1;
                                             }else{
                                                 cout<<"Se Registrara la Tarea"<<endl;
                                             }
                                          }else{
                                              cout<<"Error en fecha No se registrara Tarea"<<endl;
                                              validarRegistroTarea=false;
                                              coladeErrores->encolar(idErrores, "Tarea", "Error en fecha de Tarea: "+fecha);
                                              idErrores=idErrores+1;
                                          }
                                    }else{
                                        cout<<"Error en Materia de tarea  no Valido aun asi se registrara la tarea"<<endl;
                                        coladeErrores->encolar(idErrores, "Tarea", "Error en Materia de Tarea: "+materia);
                                        idErrores=idErrores+1;
                                    }
                                }else{
                                    cout<<"Error en Nombre de tarea  no Valido aun asi se registrara la tarea"<<endl;
                                    coladeErrores->encolar(idErrores, "Tarea", "Error en nombre de Tarea: "+nombre);
                                    idErrores=idErrores+1;
                                }
                            }else{
                                cout<<"Error en carnet  No valido no se registrara Tarea"<<endl;
                                validarRegistroTarea=false;
                                coladeErrores->encolar(idErrores, "Tarea", "Error en carnet de Tarea: "+carnet);
                                idErrores=idErrores+1;
                            }
                        }else{
                            cout<<"Error en hora no esta dentro del rango permitido"<<endl;
                            validarRegistroTarea=false;
                            coladeErrores->encolar(idErrores, "Tarea", "Error en hora de Tarea: "+hora);
                            idErrores=idErrores+1;
                        }
                    }else{
                        cout<<"Error el dia no esta dentro del rango permitido"<<endl;
                        validarRegistroTarea=false;
                        coladeErrores->encolar(idErrores, "Tarea", "Error en dia de Tarea: "+dia);
                        idErrores=idErrores+1;
                    }
                }else{
                    cout<<"Error el mes no esta dentro del rango permitido"<<endl;
                    validarRegistroTarea=false;
                    coladeErrores->encolar(idErrores, "Tarea", "Error en mes de Tarea: "+mes);
                    idErrores=idErrores+1;
                }
        
        if(validarRegistroTarea!=false){
            string idStr = std::to_string(contadorId);
            matrix[indexMes(mes)][(stoi(dia)-1)][indexHoras(hora)]= new nodoMatriz(idStr,mes,dia,hora,carnet,nombre,descripcion,materia,fecha,estado);
            contadorId=contadorId+1;
        }else{
            validarRegistroTarea=true;
        }
        
        
        
    }

    archivo.close();
    cargaMasivaTarea=true;
    recorridoPruebaMatrix();
    insertLinearizado();
    tareas->imprimirLista();
    coladeErrores->imprimirCola();
    
}

void lecturaArchivoEstudiantes()
{
    string carnet, dpi, nombre, carrera, correo, contrasena, creditos, edad;
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
        
        getline(stream,carnet,delimitador);
        getline(stream,dpi,delimitador);
        getline(stream,nombre,delimitador);
        getline(stream,carrera,delimitador);
        getline(stream,contrasena,delimitador);
        getline(stream,creditos,delimitador);
        getline(stream,edad,delimitador);
        getline(stream,correo,delimitador);
        
        const regex regexCarnet("\\d{9}");
        const regex regexDpi("\\d{13}");
        const regex regexNombre("^[a-z A-Z \\á\\Á\\é\\É\\í\\Í\\ó\\Ó\\Ú\\ú\\+]+$");
        const regex regexCarrera("^[a-z A-Z \\á\\Á\\é\\É\\í\\Í\\ó\\Ó\\Ú\\ú\\+]+$");
        const regex regexCreditos("\\d{1,3}");
        const regex regexEdad("\\d{2}");
        const regex regexCorreo("([a-z 0-9 \\.]+\\@+[a-z]+\\.+(com|es|org))");
        // Validador de datos correctos en carga masiva de usuarios.
        if(regex_match(carnet,regexCarnet)){
            cout<<"Carnet Valido"<<endl;
        }else{
            cout<<"Error en Carnet no Valido"<<endl;
            coladeErrores->encolar(idErrores, "Estudiante", "Error Carnet de Estudainte: "+carnet);
            idErrores=idErrores+1;
        }
        
        if(regex_match(dpi,regexDpi)){
            cout<<"Dpi Valido"<<endl;
        }else{
            cout<<"Error en Dpi no Valido"<<endl;
            coladeErrores->encolar(idErrores, "Estudiante", "Error DPI de Estudainte: "+dpi);
            idErrores=idErrores+1;
        }
        
        if(regex_match(nombre,regexNombre)){
            cout<<"Nombre Valido"<<endl;
        }else{
            cout<<"Error en Nombre no Valido"<<endl;
            coladeErrores->encolar(idErrores, "Estudiante", "Error Nombre de Estudainte: "+nombre);
            idErrores=idErrores+1;
        }
        
        if(regex_match(carrera,regexCarrera)){
            cout<<"Carrera Valido"<<endl;
        }else{
            cout<<"Error en Carnet no Valido"<<endl;
            coladeErrores->encolar(idErrores, "Estudiante", "Error carrera de Estudainte: "+carrera);
            idErrores=idErrores+1;
        }
        
        if(regex_match(creditos,regexCreditos)){
            cout<<"Creditos Valido"<<endl;
        }else{
            cout<<"Error en Creditos no Valido"<<endl;
            coladeErrores->encolar(idErrores, "Estudiante", "Error Creditos de Estudainte: "+creditos);
            idErrores=idErrores+1;
        }
        
        if(regex_match(edad,regexEdad)){
            cout<<"Edad Valido"<<endl;
        }else{
            cout<<"Error en Edad no Valido"<<endl;
            coladeErrores->encolar(idErrores, "Estudiante", "Error Edad de Estudainte: "+edad);
            idErrores=idErrores+1;
        }
        
        if(regex_match(correo,regexCorreo)){
            cout<<"Error en Correo no Valido"<<endl;
            coladeErrores->encolar(idErrores, "Estudiante", "Error Correo de Estudainte: "+correo);
            idErrores=idErrores+1;
        }else{
            cout<<"Correo Valido"<<endl;
            
        }
        
        lista->insertarValorFinal(carnet, dpi, nombre, carrera, contrasena, creditos, edad, correo);
//            validadorRegistro=false;
    }

    archivo.close();
    lista->imprimirListaEstudiantes();
    cout<<"\n"<<endl;
    cout<<"----------------- Cola de Errores -----------------"<<endl;
    coladeErrores->imprimirCola();
}


void menuManualUsuarios(){
    string carnet="", dpi="", nombre="", carrera="", correo="", contrasena="", creditos="", edad="";
    string dpiIngresado;
    const regex regexCarnet("\\d{9}");
    const regex regexDpi("\\d{13}");
    const regex regexNombre("^[a-z A-Z \\á\\Á\\é\\É\\í\\Í\\ó\\Ó\\Ú\\ú\\+]+$");
    const regex regexCarrera("^[a-z A-Z \\á\\Á\\é\\É\\í\\Í\\ó\\Ó\\Ú\\ú\\+]+$");
    const regex regexCreditos("\\d{1,3}");
    const regex regexEdad("\\d{2}");
    const regex regexCorreo("([a-z 0-9 \\.]+\\@+[a-z]+\\.+(com|es|org))");
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMenu Ingreso Manual" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Ingresar" << endl;
        cout << "\t2. Modificar" << endl;
        cout << "\t3. Eliminar" << endl;
        cout << "\t4. Salir" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion2;

        switch (opcion2)
        {
        case 1:
                cout << "\n\tIngrese No. Carnet: "<<endl;
                //cin >> carnet;
                cin.ignore();
                std::getline(cin, carnet);
                if(regex_match(carnet,regexCarnet)){
                    cout << "\n\t No.Carnet Valido"<<endl;
                }else{
                    cout << "\n\t No.Carnet no Valido no se permite Registrar Estudiante"<<endl;
                    menuManualUsuarios();
                }
                
                cout << "\n\tIngrese No.DPI: "<<endl;
                cin >> dpi;
                //cin.ignore();
                //std::getline(cin, dpi);
                if(regex_match(dpi,regexDpi)){
                    cout << "\n\t No.DPI Valido"<<endl;
                }else{
                    cout << "\n\t No.DPI no Valido no se permite Registrar Estudiante"<<endl;
                    menuManualUsuarios();
                }
                
                cout << "\n\tIngrese Nombre: "<<endl;
                //cin.getline(nombre, 100);
                cin.ignore();
                std::getline(cin, nombre);
                //cin.get(nombre);
                //cin >> nombre;
                if(regex_match(nombre,regexNombre)){
                    cout << "\n\t Nombre Valido"<<endl;
                }else{
                    cout << "\n\t Nombre no Valido no se permite Registrar Estudiante"<<endl;
                    menuManualUsuarios();
                }
                
                cout << "\n\tIngrese Carrera: "<<endl;
                //cin.getline(carrera, 100);
                cin.ignore();
                std::getline(cin, carrera);
                //cin.get(carrera);
                //cin >> carrera;
                if(regex_match(carrera,regexCarrera)){
                    cout << "\n\t Nombre de Carrera Valido"<<endl;
                }else{
                    cout << "\n\t Nombre de Carrera no Valido no se permite Registrar Estudiante"<<endl;
                    menuManualUsuarios();
                }
                
                cout << "\n\tIngrese Correo: "<<endl;
                cin.ignore();
                //std::getline(cin, correo);
                cin >> correo;
                if(regex_match(correo,regexCorreo)){
                    cout << "\n\t Correo Valido"<<endl;
                }else{
                    cout << "\n\t Correo no Valido no se permite Registrar Estudiante"<<endl;
                    menuManualUsuarios();
                }
                
                cout << "\n\tIngrese Contraseña: "<<endl;
                //cin >> contrasena;
                cin.ignore();
                std::getline(cin, contrasena);
                
                cout << "\n\tIngrese No.Creditos: "<<endl;
                cin.ignore();
                std::getline(cin, creditos);
                //cin >> creditos;
                if(regex_match(creditos,regexCreditos)){
                    cout << "\n\t Creditos Valido"<<endl;
                }else{
                    cout << "\n\t Creditos no Valido no se permite Registrar Estudiante"<<endl;
                    menuManualUsuarios();
                }
                
                cout << "\n\tIngrese Edad: "<<endl;
                //cin >> edad;
                cin.ignore();
                std::getline(cin, edad);
                if(regex_match(edad,regexEdad)){
                    cout << "\n\t Edad Valido"<<endl;
                }else{
                    cout << "\n\t Edad no Valido  se permite Registrar Estudiante"<<endl;
                    coladeErrores->encolar(idErrores, "Estudiante", "Error en Edad de Estudiante: "+edad);
                    idErrores=idErrores+1;
                }

                lista->insertarValorFinal(carnet, dpi, nombre, carrera, contrasena, creditos, edad, correo);
                
            break;
                
        case 2:
                cout<<"Ingresar el DPI del usuario a Modificar "<<endl;
                cin>>dpiIngresado;
                lista->modificarNodo(dpiIngresado);
            break;
                

        case 3:
                cout<<"Ingresar el DPI del usuario a Eliminar "<<endl;
                cin>>dpiIngresado;
                lista->eliminarValor(dpiIngresado);
            break;

        case 4:
                Menu();
        
            break;

        }
    } while (repetir);
}

void menuManualTareas(){
    string mes,dia,hora,carnet,nombre,descripcion, materia, fecha,estado;
    int mes2,dia2,hora2;
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMenu Ingreso Manual" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Ingresar" << endl;
        cout << "\t2. Modificar" << endl;
        cout << "\t3. Eliminar" << endl;
        cout << "\t4. Salir" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion3;
        
        const regex regexMes("^[7-9]{1}$|^1[0-1]$");
        const regex regexDia("^[1-9]$|^[1-2][0-9]$|^3[0]$");
        const regex regexHora("^[8-9]$|^1[0-6]$");
        const regex regexCarnet("\\d{9}");
        const regex regexNombre("^[a-z A-Z 0-9 \\á\\Á\\é\\É\\í\\Í\\ó\\Ó\\Ú\\ú\\+]+$");
        //const regex regexDescripcion("[a-z A-Z]\\n á é í ó ú");
        const regex regexMateria("^[a-z A-Z 0-9 \\á\\Á\\é\\É\\í\\Í\\ó\\Ó\\Ú\\ú\\+]+$");
        const regex regexFecha("^2021\\/(0[7-9]|1[0-1])\\/(0[1-9]|[1-2][0-9]|3[0])");
        const regex regexEstado("^[a-z A-Z ]+$");
        
        switch (opcion3){
            case 1:
                if(cargaMasivaTarea!=false){
                    cout<<"AHORA SI SE PUEDE REGISTRAR MANUALMENTE UNA TAREA"<<endl;
                    cout<<"Ingresar Mes de Tarea"<<endl;
                                        cin>>mes;
                                        if(regex_match(mes,regexMes)){
                                            cout<<"Mes Valido para Tarea"<<endl;
                                        }else{
                                            cout<<"Mes No valido para Tarea, no se podra Registrar"<<endl;
                                            menuManualTareas();
                                        }
                                                            
                                        cout<<"Ingresar Dia de Tarea"<<endl;
                                        cin>>dia;
                                        if(regex_match(dia,regexDia)){
                                            cout<<"Dia Valido para Tarea"<<endl;
                                        }else{
                                            cout<<"Dia No valido para Tarea, no se podra Registrar"<<endl;
                                            menuManualTareas();
                                        }
                                                           
                                        cout<<"Ingresar Hora de Tarea"<<endl;
                                        cin>>hora;
                                        if(regex_match(hora,regexHora)){
                                            cout<<"Hora Valido para Tarea"<<endl;
                                        }else{
                                            cout<<"Hora No valido para Tarea, no se podra Registrar"<<endl;
                                            menuManualTareas();
                                        }
                                                            
                                        mes2=indexMes(mes);
                                        dia2=(stoi(dia)-1);
                                        hora2=indexHoras(hora);
                                        indexLinearizado=(dia2+30*(hora2+9*mes2));
                                        string indexID = std::to_string(indexLinearizado);
                                                            
                                        if(tareas->validaEspacio(indexID)){
                                            cout<<"Ingresar Carnet de Tarea"<<endl;
                                            cin>>carnet;
                                            if(regex_match(carnet,regexCarnet)){
                                                if(lista->encontrarCarnet(stoi(carnet))){
                                                    cout<<"Carnet Encontrado Correctamente dentro de Estudiantes"<<endl;
                                                }else{
                                                    cout<<"Error en carnet  No Registrado en Alumnos no se registrara Tarea"<<endl;
                                                    menuManualTareas();
                                                }
                                            cout<<"Carnet Valido para Tarea"<<endl;
                                            }else{
                                                cout<<"Carnet No valido para Tarea, no se podra Registrar"<<endl;
                                                menuManualTareas();
                                            }
                                                                
                                            cout<<"Ingresar Nombre de Tarea"<<endl;
                                            cin.ignore();
                                            getline(cin,nombre);
                                            if(regex_match(nombre,regexNombre)){
                                                cout<<"Nombre Valido para Tarea"<<endl;
                                            }else{
                                                cout<<"Nombre No valido para Tarea, no se podra Registrar"<<endl;
                                                menuManualTareas();
                                            }
                                                                
                                            cout<<"Ingresar Descripcio de Tarea"<<endl;
                                            cin.ignore();
                                            getline(cin,descripcion);
                                                                
                                            cout<<"Ingresar Materia de Tarea"<<endl;
                                            cin.ignore();
                                            getline(cin,materia);
                                            if(regex_match(materia,regexMateria)){
                                                cout<<"Nombre de Materia Valido para Tarea"<<endl;
                                            }else{
                                                cout<<"Nombre de Materia No valido para Tarea, no se podra Registrar"<<endl;
                                                menuManualTareas();
                                            }
                                                                
                                            cout<<"Ingresar Estado de Tarea"<<endl;
                                            cin.ignore();
                                            cin>>estado;
                                            if(regex_match(estado,regexEstado)){
                                                cout<<"Estado Valido para Tarea"<<endl;
                                                tareas->ingresarbyId(indexID, mes, dia, hora, carnet, nombre, descripcion, materia, fecha, estado);
                                            }else{
                                                cout<<"Estado No valido para Tarea, no se podra Registrar"<<endl;
                                                menuManualTareas();
                                            }
                                                                
                                        }else{
                                            cout<<"Espacio de Tarea no Valido"<<endl;
                                            menuManualTareas();
                                            }

                }else{
                    cout<<"No se puede Registrar una tarea debido a que no se han cargado Tareas Masivas";
                }
                break;
            case 2:
                cout<<"Ingrese Mes para Modificar Tarea "<<endl;
                cin>>mes;
                if(regex_match(mes,regexMes)){
                    cout<<"Mes Valido para Tarea"<<endl;
                }else{
                    cout<<"Mes No valido para Tarea, no se podra Registrar"<<endl;
                    menuManualTareas();
                }
                cout<<"Ingrese Dia para Modificar Tarea "<<endl;
                cin>>dia;
                if(regex_match(dia,regexDia)){
                    cout<<"Dia Valido para Tarea"<<endl;
                }else{
                    cout<<"Dia No valido para Tarea, no se podra Registrar"<<endl;
                    menuManualTareas();
                }
                cout<<"Ingrese Hora para Modificar Tarea "<<endl;
                cin>>hora;
                if(regex_match(hora,regexHora)){
                    cout<<"Hora Valido para Tarea"<<endl;
                }else{
                    cout<<"Hora No valido para Tarea, no se podra Registrar"<<endl;
                    menuManualTareas();
                }
                mes2=indexMes(mes);
                dia2=(stoi(dia)-1);
                hora2=indexHoras(hora);
                indexLinearizado=(dia2+30*(hora2+9*mes2));
                //string indexID2 = std::to_string(indexLinearizado);
                cout<<"Ingrese Carnet para Modificar Tarea "<<endl;
                cin>>carnet;
                if(regex_match(carnet,regexCarnet)){
                    if(lista->encontrarCarnet(stoi(carnet))){
                        cout<<"Carnet Encontrado Correctamente dentro de Estudiantes"<<endl;
                    }else{
                        cout<<"Error en carnet  No Registrado en Alumnos no se registrara Tarea"<<endl;
                        menuManualTareas();
                    }
                    cout<<"Carnet Valido para Tarea"<<endl;
                    if(tareas->validaModificar(std::to_string(indexLinearizado), carnet)){
                                        //cout<<"Ha ingresado a modificador de Tareas"<<endl;
                                    }else{
                                        cout<<"No se puede Modificar ya que esta Vacio"<<endl;
                                    }

                }else{
                    cout<<"carnet No valido para Tarea, no se podra Registrar"<<endl;
                    menuManualTareas();
                }
                break;
            case 3:
                cout<<"Ingrese Mes para Modificar Tarea "<<endl;
                cin>>mes;
                if(regex_match(mes,regexMes)){
                    cout<<"Mes Valido para Tarea"<<endl;
                }else{
                    cout<<"Mes No valido para Tarea, no se podra Registrar"<<endl;
                    menuManualTareas();
                }
                cout<<"Ingrese Dia para Modificar Tarea "<<endl;
                cin>>dia;
                if(regex_match(dia,regexDia)){
                    cout<<"Dia Valido para Tarea"<<endl;
                }else{
                    cout<<"Dia No valido para Tarea, no se podra Registrar"<<endl;
                    menuManualTareas();
                }
                cout<<"Ingrese Hora para Modificar Tarea "<<endl;
                cin>>hora;
                if(regex_match(hora,regexHora)){
                    cout<<"Hora Valido para Tarea"<<endl;
                }else{
                    cout<<"Hora No valido para Tarea, no se podra Registrar"<<endl;
                    menuManualTareas();
                }
                mes2=indexMes(mes);
                dia2=(stoi(dia)-1);
                hora2=indexHoras(hora);
                indexLinearizado=(dia2+30*(hora2+9*mes2));
                tareas->eliminarTarea(std::to_string(indexLinearizado));
                break;
            case 4:
                Menu();
                break;
        }
    } while (repetir);
}


void reportes(){
    string dataDoc="";
    string dataUsr="";
    string dataTask="";
    string mes,dia,hora;
    int mes2,dia2,hora2;
    string indexID;
    const regex regexMes("^[7-9]{1}$|^1[0-1]$");
    const regex regexDia("^[1-9]$|^[1-2][0-9]$|^3[0]$");
    const regex regexHora("^[8-9]$|^1[0-6]$");
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMenu Reportes " << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Grafica Estudiantes" << endl;
        cout << "\t2. Grafica Tareas" << endl;
        cout << "\t3. Busqueda Linearizada" << endl;
        cout << "\t4. Busqueda en Estructura Linearizada" << endl;
        cout << "\t5. Cola De Errores" << endl;
        cout << "\t6. Genera Codigo de Salida" << endl;
        cout << "\t7. Salir" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion2;

        switch (opcion2)
        {
        case 1:
                lista->graficarLista();
            break;

        case 2:
                tareas->graficarTareas();
            break;
        case 3:
                cout<<"Ingresar Mes de Tarea"<<endl;
                cin>>mes;
                if(regex_match(mes,regexMes)){
                    cout<<"Mes Valido para Tarea"<<endl;
                }else{
                    cout<<"Mes No valido para Tarea, no se podra Registrar"<<endl;
                    reportes();
                }
                                                        
                cout<<"Ingresar Dia de Tarea"<<endl;
                cin>>dia;
                if(regex_match(dia,regexDia)){
                    cout<<"Dia Valido para Tarea"<<endl;
                }else{
                    cout<<"Dia No valido para Tarea, no se podra Registrar"<<endl;
                    reportes();
                }
                                                       
                cout<<"Ingresar Hora de Tarea"<<endl;
                cin>>hora;
                if(regex_match(hora,regexHora)){
                    cout<<"Hora Valido para Tarea"<<endl;
                }else{
                    cout<<"Hora No valido para Tarea, no se podra Registrar"<<endl;
                    reportes();
                }
                                                        
                mes2=indexMes(mes);
                dia2=(stoi(dia)-1);
                hora2=indexHoras(hora);
                indexLinearizado=(dia2+30*(hora2+9*mes2));
                indexID = std::to_string(indexLinearizado);
                tareas->busquedaLinearizada(indexID);
            break;
        case 4:
                cout<<"Ingresar Mes de Tarea"<<endl;
                cin>>mes;
                if(regex_match(mes,regexMes)){
                    cout<<"Mes Valido para Tarea"<<endl;
                }else{
                    cout<<"Mes No valido para Tarea, no se podra Registrar"<<endl;
                    reportes();
                }
                                                        
                cout<<"Ingresar Dia de Tarea"<<endl;
                cin>>dia;
                if(regex_match(dia,regexDia)){
                    cout<<"Dia Valido para Tarea"<<endl;
                }else{
                    cout<<"Dia No valido para Tarea, no se podra Registrar"<<endl;
                    reportes();
                }
                                                       
                cout<<"Ingresar Hora de Tarea"<<endl;
                cin>>hora;
                if(regex_match(hora,regexHora)){
                    cout<<"Hora Valido para Tarea"<<endl;
                }else{
                    cout<<"Hora No valido para Tarea, no se podra Registrar"<<endl;
                    reportes();
                }
                                                        
                mes2=indexMes(mes);
                dia2=(stoi(dia)-1);
                hora2=indexHoras(hora);
                cout<<"---- Reporte desde la Matriz ------------"<<endl;
                cout<<"Index: "<<matrix[mes2][dia2][hora2]->getId()<<endl;
                cout<<"Mes: "<<matrix[mes2][dia2][hora2]->getMes()<<endl;
                cout<<"Dia: "<<matrix[mes2][dia2][hora2]->getDia()<<endl;
                cout<<"Hora: "<<matrix[mes2][dia2][hora2]->getHora()<<endl;
                cout<<"Carnet: "<<matrix[mes2][dia2][hora2]->getCarnet()<<endl;
                cout<<"Nombre: "<<matrix[mes2][dia2][hora2]->getNombre()<<endl;
                cout<<"Descripcion: "<<matrix[mes2][dia2][hora2]->getDescripcion()<<endl;
                cout<<"Materia: "<<matrix[mes2][dia2][hora2]->getMateria()<<endl;
                cout<<"Fecha: "<<matrix[mes2][dia2][hora2]->getFecha()<<endl;
                cout<<"Estado: "<<matrix[mes2][dia2][hora2]->getEstado()<<endl;
                    
            break;
        case 5:
                coladeErrores->graficarCola();
            break;
                
        case 6:
                if(coladeErrores->vacia()){
                    cout<<"SE GENERAN LOS ARCHIVOS CORRECTAMENTE"<<endl;
                    for(int x=0; x<5; x++){
                        for (int y=0; y<30; y++){
                            for (int z=0; z<9; z++){
                                if(matrix[x][y][z]!=NULL){
                                    if(matrix[x][y][z]->getCarnet()!=""){
                                        cout<<"Carnet: "+matrix[x][y][z]->getCarnet()<<endl;
                                        dataUsr=lista->dataArchivo(matrix[x][y][z]->getCarnet());
                                        dataTask=tareas->dataArchivo(matrix[x][y][z]->getCarnet());
                                        dataDoc=dataDoc+dataUsr+dataTask;
                                    }
                                }
                            }
                        }
                    }
                    
                    try{
                            //Esta variable debe ser modificada para agregar su path de creacion de la Grafica
                            string path = "/Users/negrocorado/Desktop/Walther Corado/EDD/Lab/ProbadorC++/Practica1PruebasXCODE/Practica1PruebasXCODE/Graficas/";

                            ofstream file;
                            file.open(path + "Data.txt",std::ios::out);

                            if(file.fail()){
                                exit(1);
                            }
                            file<<"¿Elements?\n"+dataDoc+"¿$Elements?";
                            file.close();
                            
                        }catch(exception e){
                            cout<<"Fallo detectado"<<endl;
                        }
                }else{
                    cout<<"Aun hay errores favor verificar para poder generar archivos"<<endl;
                }
                    
            break;

        case 7:
                Menu();
            break;
        }
    } while (repetir);
    
}




void ingresoManualMenu(){
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMenu Ingreso Manual" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Usuarios" << endl;
        cout << "\t2. Tareas" << endl;
        cout << "\t3. Salir" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion2;

        switch (opcion2)
        {
        case 1:
                menuManualUsuarios();
            break;

        case 2:
                menuManualTareas();
            break;
        case 3:
                Menu();
            break;
        }
    } while (repetir);
}

void arreglaErrores(){
    coladeErrores->graficarCola();
    if(coladeErrores->esEstudiante()){
        cout<<"Error de Estudiante a Corregir"<<endl;
        coladeErrores->desencolar();
    }else{
        cout<<"Error de Tarea a Corregir"<<endl;
        coladeErrores->desencolar();
    }
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
        cout << "\t4. Solventar Error"<<endl;
        cout << "\t5. Reportes" << endl;
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
                ingresoManualMenu();
            break;
        case 4:
                // Aqui ira todo lo referente a Reportes
                cout << "AQUI LLAMAREMOS EL METODO DE Arreglar ERRORES" << endl;
                arreglaErrores();
            break;
        case 5:
            // Aqui ira todo lo referente a Reportes
            cout << "AQUI LLAMAREMOS EL METODO DE Reportes" << endl;
                reportes();
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}



int main()
{
    Menu();
    return 0;
}
