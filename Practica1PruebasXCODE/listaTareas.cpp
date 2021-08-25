//
//  listaTareas.cpp
//  Practica1PruebasXCODE
//
//  Created by NegroCorado on 18/08/21.
//

#include "listaTareas.hpp"
#include <regex>
#include <sstream>
#include <fstream>
using namespace std;
bool repetir3=true;
int contadorGrafica = 0;
listaTareas::listaTareas(){
    this->primero = NULL;
    this->ultimo = NULL;
}

bool listaTareas::vacia(){
    if (primero == NULL)
           return true;
       else
           return false;
}

void listaTareas::insertarTarea(string id_, string mes_, string dia_, string hora_, string carnet_, string nombre_, string descripcion_, string materia_, string fecha_, string estado_){
    
    nodoTarea *nuevo;
    nuevo = new nodoTarea( id_, mes_, dia_, hora_, carnet_,  nombre_,  descripcion_,  materia_,  fecha_,  estado_);
    //nuevo->setId(id_);
    //nuevo->setCarnet(carnet_);
    //nuevo->setNombre(nombre_);
    //nuevo->setDescripcion(descripcion_);
    //nuevo->setMateria(materia_);
    //nuevo->setFecha(fecha_);
    //nuevo->setHora(hora_);
    //nuevo->setEstado(estado_);
    if(primero==NULL){
            primero = nuevo;
        primero->setSiguiente(NULL);
        primero->setAnterior(NULL);
            ultimo = primero;
        }else{
            ultimo->setSiguiente(nuevo);
            nuevo->setSiguiente(NULL);
            nuevo->setAnterior(ultimo);
            ultimo = nuevo;
        }
//    cout << "\n Nodo Ingresado\n\n"<<endl;
}

void listaTareas::imprimirLista(){
    nodoTarea *actual = new nodoTarea();
    actual = primero;
    if(primero!=NULL){
        
        while(actual!=NULL){
            cout<<"Index: "<<actual->getId()<<endl;
            cout<<"Mes: "<<actual->getMes()<<endl;
            cout<<"Dia: "<<actual->getDia()<<endl;
            cout<<"Hora: "<<actual->getHora()<<endl;
            cout<<"Carnet: "<<actual->getCarnet()<<endl;
            cout<<"Nombre: "<<actual->getNombre()<<endl;
            cout<<"Descripcion: "<<actual->getDescripcion()<<endl;
            cout<<"Materia: "<<actual->getMateria()<<endl;
            cout<<"Fecha: "<<actual->getFecha()<<endl;
            cout<<"Estado: "<<actual->getEstado()<<endl;
            //cout << "\n " << actual->dato;
            actual = actual->getSiguiente();
        }
        
    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}

bool listaTareas::validaEspacio(string id){
    nodoTarea *actual = new nodoTarea();
    actual = primero;
    bool encontrado = false;
    string nodoBuscado = "";
    nodoBuscado=id;
    if(primero!=NULL){
        
        while(actual!=NULL && encontrado!=true){
            
            if(actual->getId()== nodoBuscado){
                cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
                if(actual->getCarnet()==""){
                    encontrado = true;
                }else{
                    cout<<"El Espacio de tarea no esta Disponible";
                    encontrado =false;
                }
    
            }
            
            actual = actual->getSiguiente();
        }
        
        if(!encontrado){
            cout << "\n Nodo no Encontrado\n\n";
        }
        
    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
    return encontrado;
}

void listaTareas::ingresarbyId(string id_, string mes_, string dia_, string hora_, string carnet_, string nombre_, string descripcion_, string materia_, string fecha_, string estado_){
    nodoTarea *actual = new nodoTarea();
    actual = primero;
    bool encontrado = false;
    string nodoBuscado = "";
    nodoBuscado=id_;
    if(primero!=NULL){
        
        while(actual!=NULL && encontrado!=true){
            
            if(actual->getId()== nodoBuscado){
                actual->setMes(mes_);
                actual->setDia(dia_);
                actual->setHora(hora_);
                actual->setCarnet(carnet_);
                actual->setNombre(nombre_);
                actual->setDescripcion(descripcion_);
                actual->setMateria(materia_);
                actual->setFecha(fecha_);
                actual->setEstado(estado_);
                cout<<"Tarea Ingresada Correctamente"<<endl;
                encontrado=true;
            }
            
            actual = actual->getSiguiente();
        }
        
        if(!encontrado){
            cout << "\n TAREA NO REGISTRADA \n\n";
        }
        
    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}

bool listaTareas::validaModificar(string id, string carnet){
    string mes,dia,hora,nombre,descripcion, materia, fecha,estado;
    int opcion2;
    const regex regexCarnet("\\d{9}");
    const regex regexDpi("\\d{13}");
    const regex regexNombre("^[a-z A-Z \\á\\Á\\é\\É\\í\\Í\\ó\\Ó\\Ú\\ú\\+]+$");
    const regex regexCarrera("^[a-z A-Z \\á\\Á\\é\\É\\í\\Í\\ó\\Ó\\Ú\\ú\\+]+$");
    const regex regexCreditos("\\d{1,3}");
    const regex regexEdad("\\d{2}");
    const regex regexCorreo("([a-z 0-9 \\.]+\\@+[a-z]+\\.+(com|es|org))");
    
    nodoTarea *actual = new nodoTarea();
    actual = primero;
    bool encontrado = false;
    string nodoBuscado = "";
    nodoBuscado=id;
    if(primero!=NULL){
        
        while(actual!=NULL && encontrado!=true){
            
            if(actual->getId()== nodoBuscado){
                cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
                if(actual->getCarnet()== carnet){
                    do{
                                        system("cls");
                                        cout << "\n\n\t\t\tIndique que desea Modificar" << endl;
                                        cout << "\t\t\t-------------------------------" << endl;
                                        cout << "\n\t1. Carnet" << endl;
                                        cout << "\t2. Nombre" << endl;
                                        cout << "\t3. Descripcion" << endl;
                                        cout << "\t4. Materia" << endl;
                                        cout << "\t5. Fecha" << endl;
                                        cout << "\t6. Estado" << endl;
                                        cout << "\n\tIngrese una opcion: ";
                                        cin >> opcion2;

                                        switch (opcion2)
                                        {
                                            case 1:
                                                cout<<"Ingrese Nuevo Carnet "<<endl;
                                                cin.ignore();
                                                std::getline(cin, carnet);
                                                actual->setCarnet(carnet);
                                                repetir3=false;
                                            break;
                                            case 2:
                                                cout<<"Ingrese Nuevo Nombre "<<endl;
//                                                cin>>nombre;
                                                cin.ignore();
                                                std::getline(cin, nombre);
                                                actual->setNombre(nombre);
                                                repetir3=false;
                                            break;
                                            case 3:
                                                cout<<"Ingrese Nueva Descripcion "<<endl;
                                                cin.ignore();
                                                std::getline(cin, descripcion);
                                                actual->setDescripcion(descripcion);
                                                repetir3=false;
                                            break;
                                            case 4:
                                                cout<<"Ingrese Nueva Materia "<<endl;
                                                cin.ignore();
                                                std::getline(cin, materia);
                                                actual->setMateria(materia);
                                                repetir3=false;
                                            break;
                                            case 5:
                                                cout<<"Ingrese Nueva Fecha "<<endl;
                                                cin>>fecha;
                                                actual->setFecha(fecha);
                                                repetir3=false;
                                            break;
                                            case 6:
                                                cout<<"Ingrese Nuevo Estado "<<endl;
                                                cin.ignore();
                                                std::getline(cin, estado);
                                                actual->setEstado(estado);
                                                repetir3=false;
                                            break;
                                        }
                                    } while (repetir3);
                    encontrado = true;
                    cout<<"Tarea Modificada de Manera Correcta"<<endl;
                    
                }else{
                    cout<<"La tarea no es modificable ya que esta Vacia";
                    encontrado =false;
                }
    
            }
            
            actual = actual->getSiguiente();
        }
        
        if(!encontrado){
            cout << "\n Nodo no Encontrado\n\n";
        }
        
    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
    return encontrado;
}

void listaTareas::eliminarTarea(string id){
    string decision;
    nodoTarea *actual = new nodoTarea();
    actual = primero;
    nodoTarea *anterior = new nodoTarea();
    anterior = NULL;
    bool encontrado = false;
    string nodoBuscado = "";
    nodoBuscado=id;
    if(primero!=NULL){
        
        while(actual!=NULL && encontrado!=true){
            
            if(actual->getId() == nodoBuscado){
                cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado";
                cout <<"Esta seguro que desea Eliminar Tarea: S/N"<<endl;
                cin>>decision;
                if(decision=="s"||decision=="S"){
                    if(actual==primero){
                        primero = primero->getSiguiente();
                        primero->setAnterior(NULL);
                    }else if(actual==ultimo){
                        anterior->setSiguiente(NULL);
                        ultimo = anterior;
                    }else{
                        anterior->setSiguiente(actual->getSiguiente());
                        actual->setSiguiente(anterior);
                        actual->setAnterior(anterior);
//                        actual->siguiente->atras = anterior;
                    }
                    
                    cout << "\n Nodo Eliminado";
                    encontrado = true;
                }
                else{
                    cout<<"No se eliminara el Nodo"<<endl;
                    encontrado=false;
                }
            }
            anterior = actual;
            actual = actual->getSiguiente();
        }
        
        if(!encontrado){
            cout << "\n Nodo no Encontrado\n\n";
        }
        
    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}


void listaTareas::graficarTareas(){
    string iniciador="digraph List {\nrankdir=LR;\nnode [shape = record, color=blue , style=filled, fillcolor=skyblue];\n";
    string nodos="";
    string unirNodos="";
    string grafico="";
    string dataNodo="";
    nodoTarea *actual = new nodoTarea();
    nodoTarea *aux = new nodoTarea();
    actual = primero;
    
    if(primero!=NULL){
        
        while(actual!=NULL){
            aux = actual;
            cout<<"Index: "<<actual->getId()<<endl;
            cout<<"Mes: "<<actual->getMes()<<endl;
            cout<<"Dia: "<<actual->getDia()<<endl;
            cout<<"Hora: "<<actual->getHora()<<endl;
            cout<<"Carnet: "<<actual->getCarnet()<<endl;
            cout<<"Nombre: "<<actual->getNombre()<<endl;
            cout<<"Descripcion: "<<actual->getDescripcion()<<endl;
            cout<<"Materia: "<<actual->getMateria()<<endl;
            cout<<"Fecha: "<<actual->getFecha()<<endl;
            cout<<"Estado: "<<actual->getEstado()<<endl;
            //cout << "\n " << actual->dato;
            aux=aux->getSiguiente();
            string identificador = actual->getId();
            if(actual->getCarnet()==""){
                dataNodo= "Espacio Vacio";
            }else{
                dataNodo= "Carnet: "+actual->getCarnet()+"\nNombre: "+actual->getNombre()+"\nDescripcion: "+actual->getDescripcion()+"\nMateria: "+actual->getMateria()+"\nFecha: "+actual->getFecha()+"\nHora: "+actual->getHora()+"\nEstado: "+actual->getEstado();
            }
            nodos = nodos+ identificador + "[label=\""+dataNodo+ "\",shape="+ "record" + "]\n";
            if(aux!=NULL){
                unirNodos=unirNodos+""+actual->getId()+"->"+aux->getId()+"\n"+aux->getId()+"->"+actual->getId()+"\n";
            }
            actual = actual->getSiguiente();
        }
        
        
    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
    cout<<iniciador + nodos+ unirNodos <<endl;
    grafico=iniciador+nodos+unirNodos+"\n}";
    try{
            //Esta variable debe ser modificada para agregar su path de creacion de la Grafica
            string path = "/Users/negrocorado/Desktop/Walther Corado/EDD/Lab/ProbadorC++/Practica1PruebasXCODE/Practica1PruebasXCODE/Graficas/";

            ofstream file;
            file.open(path + "GraphTareas"+std::to_string(contadorGrafica)+".dot",std::ios::out);

            if(file.fail()){
                exit(1);
            }
            file<<grafico;
            file.close();

            //system("dot -Tpng"+path+nombre_de_fichero.dot+" -o nombre_de_imagen_generada.png");
            //string command = "dot -Tpng " + path + "Graph.dot -o  " + path + "Graph.png";
            //system(command.c_str());
        string comando="dot -Tpng "+path+"GraphTareas"+std::to_string(contadorGrafica)+".dot -o "+"Graph"+std::to_string(contadorGrafica)+".png";
            string command = "dot -Tpng " +path + "GraphTareas"+std::to_string(contadorGrafica)+".dot -o Graph"+std::to_string(contadorGrafica)+".png";
        system(comando.c_str());
            
        }catch(exception e){
            cout<<"Fallo detectado"<<endl;
        }
    contadorGrafica=contadorGrafica+1;
}


void listaTareas::busquedaLinearizada(string id){
    nodoTarea *actual = new nodoTarea();
    actual = primero;
    bool encontrado = false;
    string nodoBuscado = "";
    nodoBuscado=id;
    if(primero!=NULL){
        while(actual!=NULL && encontrado!=true){
            if(actual->getId()== nodoBuscado){
                cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
                cout<<"Index: "<<actual->getId()<<endl;
                cout<<"Mes: "<<actual->getMes()<<endl;
                cout<<"Dia: "<<actual->getDia()<<endl;
                cout<<"Hora: "<<actual->getHora()<<endl;
                cout<<"Carnet: "<<actual->getCarnet()<<endl;
                cout<<"Nombre: "<<actual->getNombre()<<endl;
                cout<<"Descripcion: "<<actual->getDescripcion()<<endl;
                cout<<"Materia: "<<actual->getMateria()<<endl;
                cout<<"Fecha: "<<actual->getFecha()<<endl;
                cout<<"Estado: "<<actual->getEstado()<<endl;
            }
            
            actual = actual->getSiguiente();
        }
        
        if(!encontrado){
            cout << "\n Nodo no Encontrado\n\n";
        }
        
    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}

string listaTareas::contarCarnets(){
    int contador =0;
    nodoTarea *actual = new nodoTarea();
    actual = primero;
    if(primero!=NULL){
        
        while(actual!=NULL){
            if(actual->getId()==""){
                
            }else{
                contador=contador+1;
            }
            actual = actual->getSiguiente();
        }
        
    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
    return std::to_string(contador);
}
string listaTareas::dataArchivo(string carnet_){
    string iniciador=" ¿element type=\"task\"?\n";
    string dataInterna="";
    string dataFinal="";
    string data2="";
    nodoTarea *actual = new nodoTarea();
    actual = primero;
    bool encontrado = false;
    string nodoBuscado = "";
    nodoBuscado=carnet_;
    if(primero!=NULL){
        while(actual!=NULL && encontrado!=true){
            if(actual->getCarnet()== nodoBuscado){
                dataInterna=dataInterna+"   ¿element type=\"task\"?\n"+"        ¿item Carnet = \""+actual->getCarnet()+"\" $?\n"+"      ¿item Nombre = \""+actual->getNombre()+"\" $?\n"+"      ¿item Descripcion = \""+actual->getDescripcion()+"\" $?\n"+"        ¿item Materia = \""+actual->getMateria()+"\" $?\n"+"        ¿item Fecha = \""+actual->getFecha()+"\" $?\n"+"        ¿item Hora = \""+actual->getHora()+":00\" $?\n"+"       ¿item Estado = \""+actual->getEstado()+"\" $?\n"+"  ¿$element?\n";
            }
            
            actual = actual->getSiguiente();
        }
        
        if(!encontrado){
            cout << "\n Nodo no Encontrado\n\n";
        }
        dataFinal=dataInterna;
    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
    return dataFinal;
}
