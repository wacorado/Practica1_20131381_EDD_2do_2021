//
//  nodoError.cpp
//  Practica1PruebasXCODE
//
//  Created by NegroCorado on 16/08/21.
//

#include "nodoError.hpp"

// Constructores
nodoError::nodoError()
{
    this->id = 0;
    this->tipo = "";
    this->descripcion = "";
    this->siguiente = NULL;
    this->anterior = NULL;
}

nodoError::nodoError(int id_, string tipo_, string descripcion_)
{
    this->id = id_;
    this->tipo = tipo_;
    this->descripcion = descripcion_;
    this->siguiente = 0;
    this->anterior = 0;
}

nodoError::nodoError(int id_, string tipo_, string descripcion_, nodoError *anterior_, nodoError *siguiente_)
{
    this->id = id_;
    this->tipo = tipo_;
    this->descripcion = descripcion_;
    this->siguiente = siguiente_;
    this->anterior = anterior_;
}

// Getters
int nodoError::getId(){
    return  this->id;
}

string nodoError::getTipo(){
    return this->tipo;
}

string nodoError::getDescripcion(){
    return this->descripcion;
}


nodoError *nodoError::getSiguiente()
{
    return this->siguiente;
}

nodoError *nodoError::getAnterior(){
    return this->anterior;
}

// Setters

void nodoError::setId(int id_){
    this->id=id_;
}

void nodoError::setTipo(string tipo_){
    this->tipo=tipo_;
}

void nodoError::setDescripcion(string descripcion_){
    this->descripcion=descripcion_;
}

void nodoError::setSiguiente(nodoError *siguiente_){
    this->siguiente = siguiente_;
}

void nodoError::setAnterior(nodoError *anterior_){
    this->anterior=anterior_;
}

