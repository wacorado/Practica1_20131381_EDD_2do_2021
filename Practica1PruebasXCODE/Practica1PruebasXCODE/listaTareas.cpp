//
//  listaTareas.cpp
//  Practica1PruebasXCODE
//
//  Created by NegroCorado on 18/08/21.
//

#include "listaTareas.hpp"

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
