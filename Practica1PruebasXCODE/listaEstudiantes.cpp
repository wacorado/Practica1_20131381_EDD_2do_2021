#include <iostream>
#include <sstream>
#include <fstream>
#include "listaEstudiantes.hpp"
using namespace std;
bool repetir2 = true;
int contadorGraficas = 0;

listaEstudiantes::listaEstudiantes(){
    this->primero = NULL;
    this->ultimo = NULL;
}

bool listaEstudiantes::vacia(){
    return this->primero == NULL;
}

void listaEstudiantes::insertarValorFinal(string carnet_, string dpi_, string nombre_, string carrera_, string contrasena_, string creditos_, string edad_, string correo_)
{
    nodoEstudiante *nuevo;
    nuevo = new nodoEstudiante(carnet_, dpi_, nombre_, carrera_, contrasena_, creditos_, edad_, correo_);
    if (vacia())
    {
        primero = nuevo;
        ultimo = nuevo;
        primero->setSiguiente(primero);
        primero->setAnterior(ultimo);
    }
    else
    {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        nuevo->setSiguiente(primero);
        ultimo = nuevo;
        primero->setAnterior(ultimo);
    }
    cout <<"Estudiante: "<<nombre_<<" Registrado Correctamente"<<endl;
}

void listaEstudiantes::imprimirListaEstudiantes(){
    nodoEstudiante *actual= new nodoEstudiante();
    actual = primero;
    if (primero != NULL){
        do{
            cout<< "----------- Estudiante Registrado -------- \n"<<endl;
            cout <<"Numero de Carnet: "<<actual->getCarnet()<<endl;
            cout <<"Numero de DPI: "<<actual->getDpi()<<endl;
            cout <<"Nombre Estudiante: " <<actual->getNombre()<<endl;
            cout <<"Carrera: " <<actual->getCarrera()<< endl;
            cout << "Contraseña Estudiante: " <<actual->getContrasena()<< endl;
            cout << "No. de Creditos: " <<actual->getCreditos()<< endl;
            cout << "Edad del Estudiante: "<<actual->getEdad()<< endl;
            cout << "Correo de Estudiante: "<<actual->getCorreo()<< endl;
            actual = actual->getSiguiente();
        }while(actual != primero);
    }else{
        cout<< "\n La lista se Encuentra Vacia\n\n";
    }
}

bool listaEstudiantes::encontrarCarnet(int carnet_){
    nodoEstudiante *actual = new nodoEstudiante();
    actual = primero;
    bool encontrado = false;
    int nodoBuscado = 0;
    nodoBuscado=carnet_;
    if(primero!=NULL){
        do{
            
            if(stoi(actual->getCarnet())==nodoBuscado){
                cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
                encontrado = true;
            }
            
            actual = actual->getSiguiente();
        }while(actual!=primero && encontrado != true);
        
        if(!encontrado){
            cout << "\n Nodo no Encontrado\n\n";
        }
        
    }else{
        cout << "\n La lista se Encuentra Vacia\n\n";
    }
    return encontrado;
}

void listaEstudiantes::modificarNodo(string Dpi){
    int opcion2;
    string carnet, dpi, nombre, carrera, correo, contrasena, creditos, edad;
    nodoEstudiante *actual = new nodoEstudiante();
    actual = primero;
    bool encontrado = false;
    string nodoBuscado = "";
    nodoBuscado=Dpi;
    if(primero!=NULL){
            do{
                
                if(actual->getDpi()==nodoBuscado){
                    cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado";
                    
                    do{
                                        system("cls");
                                        cout << "\n\n\t\t\tIndique que desea Modificar" << endl;
                                        cout << "\t\t\t-------------------------------" << endl;
                                        cout << "\n\t1. Carnet" << endl;
                                        cout << "\t2. DPI" << endl;
                                        cout << "\t3. Nombre" << endl;
                                        cout << "\t4. Carrera" << endl;
                                        cout << "\t5. Password" << endl;
                                        cout << "\t6. Creditos" << endl;
                                        cout << "\t7. Edad" << endl;
                                        cout << "\t8. Correo" << endl;
                                        cout << "\n\tIngrese una opcion: ";
                                        cin >> opcion2;

                                        switch (opcion2)
                                        {
                                            case 1:
                                                cout<<"Ingrese Nuevo Carnet "<<endl;
                                                cin.ignore();
                                                std::getline(cin, carnet);
                                                actual->setCarnet(carnet);
                                                repetir2=false;
                                            break;
                                            case 2:
                                                cout<<"Ingrese Nuevo DPI "<<endl;
                                                cin>>dpi;
                                                actual->setDpi(dpi);
                                                repetir2=false;
                                            break;
                                            case 3:
                                                cout<<"Ingrese Nuevo Nombre "<<endl;
//                                                cin>>nombre;
                                                cin.ignore();
                                                std::getline(cin, nombre);
                                                actual->setNombre(nombre);
                                                repetir2=false;
                                            break;
                                            case 4:
                                                cout<<"Ingrese Nueva Carrera "<<endl;
                                                cin.ignore();
                                                std::getline(cin, carrera);
                                                actual->setCarrera(carrera);
                                                repetir2=false;
                                            break;
                                            case 5:
                                                cout<<"Ingrese Nuevo Password "<<endl;
                                                cin.ignore();
                                                std::getline(cin, contrasena);
                                                actual->setContrasena(contrasena);
                                                repetir2=false;
                                            break;
                                            case 6:
                                                cout<<"Ingrese Nuevo Creditos "<<endl;
                                                cin>>creditos;
                                                actual->setCreditos(creditos);
                                                repetir2=false;
                                            break;
                                            case 7:
                                                cout<<"Ingrese Nuevo Edad "<<endl;
                                                cin.ignore();
                                                std::getline(cin, creditos);
                                                actual->setEdad(edad);
                                                repetir2=false;
                                            break;
                                            case 8:
                                                cout<<"Ingrese Nuevo Correo "<<endl;
                                                cin.ignore();
                                                //std::getline(cin, correo);
                                                cin >> correo;
                                                actual->setCorreo(correo);
                                                repetir2=false;
                                            break;
                                                
                                        }
                                    } while (repetir2);
                    
                    encontrado = true;
                }
                
                actual = actual->getSiguiente();
            }while(actual!=primero && encontrado != true);
            
            if(!encontrado){
                cout << "\n Nodo no Encontrado\n\n";
            }
            
        }else{
            cout << "\n La lista se Encuentra Vacia\n\n";
        }
}

void listaEstudiantes::eliminarValor(string Dpi){
    nodoEstudiante *actual = new nodoEstudiante();
    actual = primero;
    nodoEstudiante *anterior = new nodoEstudiante();
    anterior = NULL;
    bool encontrado = false;
    string nodoBuscado="";
    nodoBuscado=Dpi;
    if(primero!=NULL){
        do{
            
            if(actual->getDpi()==nodoBuscado){
                cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado";
                
                if(actual==primero){
                    primero = primero->getSiguiente();
                    primero->setAnterior(ultimo);
                    ultimo->setSiguiente(primero);
                }else if(actual==ultimo){
                    ultimo = anterior;
                    ultimo->setSiguiente(primero);
                    primero->setAnterior(ultimo);
                }else{
                    anterior->setSiguiente(actual->getSiguiente());
                    actual->setSiguiente(anterior);
                    actual->setAnterior(anterior);
                    //actual->siguiente->atras = anterior;
                }
                
                cout << "\n Nodo Eliminado\n\n";
                encontrado = true;
            }
            
            anterior = actual;
            actual = actual->getSiguiente();
        }while(actual!=primero && encontrado != true);
        
        if(!encontrado){
            cout << "\n Nodo no Encontrado\n\n";
        }
        
    }else{
        cout << "\n La lista se Encuentra Vacia\n\n";
    }
}




void listaEstudiantes::graficarLista(){
    string iniciador="digraph List {\nrankdir=LR;\nnode [shape = record, color=blue , style=filled, fillcolor=skyblue];\n";
    string nodos="";
    string unirNodos="";
    string grafico="";
    
    
    nodoEstudiante *actual= new nodoEstudiante();
    actual = primero;
    if (primero != NULL){
        do{
         
            cout<< "----------- Estudiante Registrado -------- \n"<<endl;
            cout <<"Numero de Carnet: "<<actual->getCarnet()<<endl;
            cout <<"Numero de DPI: "<<actual->getDpi()<<endl;
            cout <<"Nombre Estudiante: " <<actual->getNombre()<<endl;
            cout <<"Carrera: " <<actual->getCarrera()<< endl;
            cout << "Contraseña Estudiante: " <<actual->getContrasena()<< endl;
            cout << "No. de Creditos: " <<actual->getCreditos()<< endl;
            cout << "Edad del Estudiante: "<<actual->getEdad()<< endl;
            cout << "Correo de Estudiante: "<<actual->getCorreo()<< endl;
          
            string identificador = actual->getCarnet();
            string dataNodo= "Carnet: "+actual->getCarnet()+" \n Dpi: "+actual->getDpi()+" \n Nombre: "+actual->getNombre()+" \n Carrera: "+actual->getCarrera()+" \n Contraseña: "+actual->getContrasena()+" \n Creditos: "+actual->getCreditos()+" \n Edad: "+actual->getEdad()+" \n Correo: "+actual->getCorreo();
            nodos = nodos+ identificador + "[label=\""+ dataNodo + "\",shape="+ "record" + "]\n";
            
            unirNodos=unirNodos+""+actual->getCarnet()+"->"+actual->getSiguiente()->getCarnet()+"\n"+actual->getSiguiente()->getCarnet()+"->"+actual->getCarnet()+"\n";
            
            
            
            actual = actual->getSiguiente();
        }while(actual != primero);
        unirNodos=unirNodos+""+primero->getCarnet()+"->"+ultimo->getCarnet()+"\n"+ultimo->getCarnet()+"->"+primero->getCarnet()+"\n";
        cout<<iniciador + nodos+ unirNodos <<endl;
        grafico=iniciador+nodos+unirNodos+"\n}";
        try{
                //Esta variable debe ser modificada para agregar su path de creacion de la Grafica
                string path = "/Users/negrocorado/Desktop/Walther Corado/EDD/Lab/ProbadorC++/Practica1PruebasXCODE/Practica1PruebasXCODE/Graficas/";

                ofstream file;
                file.open(path + "Graph"+std::to_string(contadorGraficas)+".dot",std::ios::out);

                if(file.fail()){
                    exit(1);
                }
                file<<grafico;
                file.close();
            
                
                

                //system("dot -Tpng"+path+nombre_de_fichero.dot+" -o nombre_de_imagen_generada.png");
                //string command = "dot -Tpng " + path + "Graph.dot -o  " + path + "Graph.png";
                //system(command.c_str());
            string comando="dot -Tpng "+path+"Graph"+std::to_string(contadorGraficas)+".dot -o "+"Graph"+std::to_string(contadorGraficas)+".png";
                string command = "dot -Tpng " +path + "Graph"+std::to_string(contadorGraficas)+".dot -o Graph"+std::to_string(contadorGraficas)+".png";
            system(comando.c_str());
                
            }catch(exception e){
                cout<<"Fallo detectado"<<endl;
            }
        contadorGraficas=contadorGraficas+1;
    }else{
        cout<< "\n La lista se Encuentra Vacia\n\n";
    }
}

string listaEstudiantes::dataArchivo(string carnet_){
    string iniciador="  ¿element type=\"user\"?\n";
    string dataInterna="";
    string dataFinal="";
    string data2="";
    nodoEstudiante *actual = new nodoEstudiante();
    actual = primero;
    bool encontrado = false;
    string nodoBuscado = "";
    nodoBuscado=carnet_;
    if(primero!=NULL){
        do{
            
            if(actual->getCarnet()==nodoBuscado){
                cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
                dataInterna="       ¿item Carnet = \""+actual->getCarnet()+"\" $?\n"+"      ¿item DIPI = \""+actual->getDpi()+"\" $?\n"+"       ¿item Nombre = \""+actual->getNombre()+"\" $?\n"+"      ¿item Carrera = \""+actual->getCarrera()+"\" $?\n"+"        ¿item Password = \""+actual->getContrasena()+"\" $?\n"+"        ¿item Creditos = \""+actual->getCreditos()+"\" $?\n"+"      ¿item Edad = \""+actual->getEdad()+"\" $?\n"+"      ¿item Correo = \""+actual->getCorreo()+"\" $?\n";
                encontrado = true;
            }
            actual = actual->getSiguiente();
        }while(actual!=primero && encontrado != true);
        
        if(!encontrado){
            cout << "\n Nodo no Encontrado\n\n";
        }
        dataFinal=iniciador+dataInterna+"¿  $element?\n";
        data2="Segundo String";
    }else{
        cout << "\n La lista se Encuentra Vacia\n\n";
    }
    return dataFinal;
}


