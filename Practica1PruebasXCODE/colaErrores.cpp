//
//  colaErrores.cpp
//  Practica1PruebasXCODE
//
//  Created by NegroCorado on 16/08/21.
//

#include "colaErrores.hpp"
#include <sstream>
#include <fstream>
int contadorCola=0;

colaErrores::colaErrores(){
    this->primero = NULL;
    this->ultimo = NULL;
}

bool colaErrores::vacia(){
    if (primero == NULL)
           return true;
       else
           return false;
}

void colaErrores::encolar(int id_, string tipo_, string descripcion_)
{
    nodoError *nuevo;
    nuevo = new nodoError(id_, tipo_, descripcion_);
    nuevo->setId(id_);
    nuevo->setTipo(tipo_);
    nuevo->setDescripcion(descripcion_);
    nuevo->setSiguiente(NULL);
    if(primero==NULL){
            primero = nuevo;
            primero->setSiguiente(NULL);
            ultimo = primero;
    }else{
            ultimo->setSiguiente(nuevo);
            nuevo->setSiguiente(NULL);
            ultimo = nuevo;
    }
        cout << endl << " Nodo Ingresado " << endl << endl;
}

void colaErrores::imprimirCola(){
    nodoError *actual = new nodoError();
    actual = primero;
    if(primero!=NULL){
        while (actual!=NULL) {
            cout<<"Id de Error: "<<actual->getId()<<endl;
            cout<<"Tipo del Error: "<<actual->getTipo()<<endl;
            cout<<"Descripcion de Error: "<<actual->getDescripcion()<<endl;
            actual = actual->getSiguiente();
        }
    }else{
        cout<<"La Cola Esta Vacia"<<endl;
    }
    
}

void colaErrores::graficarCola(){
    string iniciador="digraph List {\nrankdir=LR;\nnode [shape = record, color=blue , style=filled, fillcolor=skyblue];\n";
    string nodos="";
    string unirNodos="";
    string grafico="";
    string dataNodo="";
    nodoError *actual = new nodoError();
    nodoError *aux = new nodoError();
    actual = primero;
    if(primero!=NULL){
        while (actual!=NULL) {
            aux=actual;
            cout<<"Id de Error: "<<actual->getId()<<endl;
            cout<<"Tipo del Error: "<<actual->getTipo()<<endl;
            cout<<"Descripcion de Error: "<<actual->getDescripcion()<<endl;
            aux=aux->getSiguiente();
            string identificador = std::to_string(actual->getId());
            dataNodo="Id: "+std::to_string(actual->getId())+"\n Tipo: "+actual->getTipo()+"\n Descripcion: "+actual->getDescripcion();
            nodos = nodos+ identificador + "[label=\""+dataNodo+ "\",shape="+ "record" + "]\n";
            if(aux!=NULL){
                unirNodos=unirNodos+""+std::to_string(actual->getId())+"->"+std::to_string(aux->getId())+"\n";
            }
            actual = actual->getSiguiente();
        }
    }else{
        cout<<"La Cola Esta Vacia"<<endl;
    }
    
    cout<<iniciador + nodos+ unirNodos <<endl;
    grafico=iniciador+nodos+unirNodos+"\n}";
    try{
            //Esta variable debe ser modificada para agregar su path de creacion de la Grafica
            string path = "/Users/negrocorado/Desktop/Walther Corado/EDD/Lab/ProbadorC++/Practica1PruebasXCODE/Practica1PruebasXCODE/Graficas/";

            ofstream file;
            file.open(path + "GraphCola"+std::to_string(contadorCola)+".dot",std::ios::out);

            if(file.fail()){
                exit(1);
            }
            file<<grafico;
            file.close();

            //system("dot -Tpng"+path+nombre_de_fichero.dot+" -o nombre_de_imagen_generada.png");
            //string command = "dot -Tpng " + path + "Graph.dot -o  " + path + "Graph.png";
            //system(command.c_str());
        string comando="dot -Tpng "+path+"GraphCola"+std::to_string(contadorCola)+".dot -o "+"GraphCola"+std::to_string(contadorCola)+".png";
            string command = "dot -Tpng " +path + "GraphTareas"+std::to_string(contadorCola)+".dot -o GraphCola"+std::to_string(contadorCola)+".png";
        system(comando.c_str());
    }catch(exception e){
        cout<<"Fallo detectado"<<endl;
    }
    contadorCola=contadorCola+1;
}

int colaErrores::desencolar()
{
    if (!vacia())
    {
        int edad_ = primero->getId();
        //string nombre_ = primero->Nombre;
        nodoError *bor = primero;
        if (primero == ultimo)
        {
            primero = NULL;
            ultimo = NULL;
        }
        else
        {
            primero= primero->getSiguiente();
        }
        cout<<"--------- Error Desencolado --------------"<<endl;
        cout<<"Id de Error: "<<bor->getId()<<endl;
        cout<<"Tipo del Error: "<<bor->getTipo()<<endl;
        cout<<"Descripcion de Error: "<<bor->getDescripcion()<<endl;
        delete bor;
        return edad_;
    }
    else
        return -1;
}

bool colaErrores::esEstudiante(){
    nodoError *actual = new nodoError();
    actual = primero;
    bool encontrado = false;
    string nodoBuscado="";
    nodoBuscado="Estudiante";
    if(primero != NULL){
        while(actual!=NULL && encontrado != true){
            
            if(actual->getTipo() == nodoBuscado){
                cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado";
                encontrado = true;
            }
            
            actual = actual->getSiguiente();
        }
        if(!encontrado){
            cout << "\n Nodo No Encontrado";
        }
    }else{
        cout << endl << " La cola se encuentra Vacia " << endl << endl;
    }
    return encontrado;
}
