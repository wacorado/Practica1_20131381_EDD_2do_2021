//
//  colaErrores.cpp
//  Practica1PruebasXCODE
//
//  Created by NegroCorado on 16/08/21.
//

#include "colaErrores.hpp"

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

