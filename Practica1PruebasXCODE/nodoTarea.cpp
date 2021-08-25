//
//  nodoTarea.cpp
//  Practica1PruebasXCODE
//
//  Created by NegroCorado on 18/08/21.
//

#include "nodoTarea.hpp"

nodoTarea::nodoTarea()
{
    this->id = "";
    this->mes = "";
    this->dia = "";
    this->hora= "";
    this->carnet = "";
    this->nombre = "";
    this->descripcion = "";
    this->materia = "";
    this->fecha = "";
    this->estado = "";
    this->siguiente = NULL;
    this->anterior = NULL;
}

nodoTarea::nodoTarea(string id_,string mes_,string dia_,string hora_, string carnet_, string nombre_, string descripcion_, string materia_, string fecha_, string estado_)
{
    this->id = id_;
    this->mes = mes_;
    this->dia = dia_;
    this->hora = hora_;
    this->carnet = carnet_;
    this->nombre = nombre_;
    this->descripcion = descripcion_;
    this->materia = materia_;
    this->fecha = fecha_;
    this->estado = estado_;
    this->siguiente = 0;
    this->anterior = 0;
}

nodoTarea::nodoTarea(string id_,string mes_,string dia_,string hora_, string carnet_, string nombre_, string descripcion_, string materia_, string fecha_, string estado_, nodoTarea *anterior_, nodoTarea *siguiente_)
{
    this->id = id_;
    this->mes = mes_;
    this->dia = dia_;
    this->hora = hora_;
    this->carnet = carnet_;
    this->nombre = nombre_;
    this->descripcion = descripcion_;
    this->materia = materia_;
    this->fecha = fecha_;
    this->estado = estado_;
    this->siguiente = siguiente_;
    this->anterior = anterior_;
}

// Getters

string nodoTarea::getId()
{
    return this->id;
}

string nodoTarea::getMes(){
    return this->mes;
}

string nodoTarea::getDia(){
    return this->dia;
}

string nodoTarea::getHora(){
    return this->hora;
}

string nodoTarea::getCarnet()
{
    return this->carnet;
}

string nodoTarea::getNombre(){
    return this->nombre;
}

string nodoTarea::getDescripcion(){
    return this->descripcion;
}

string nodoTarea::getMateria(){
    return this->materia;
}

string nodoTarea::getFecha(){
    return this->fecha;
}

string nodoTarea::getEstado(){
    return this->estado;
}

nodoTarea *nodoTarea::getSiguiente()
{
    return this->siguiente;
}

nodoTarea *nodoTarea::getAnterior(){
    return this->anterior;
}

// Setters

void nodoTarea::setId(string id_)
{
    this->id = id_;
}

void nodoTarea::setMes(string mes_){
    this->mes=mes_;
}

void nodoTarea::setDia(string dia_){
    this->dia=dia_;
}

void nodoTarea::setHora(string hora_){
    this->hora=hora_;
}

void nodoTarea::setCarnet(string carnet_){
    this->carnet = carnet_;
}

void nodoTarea::setNombre(string nombre_){
    this->nombre=nombre_;
}

void nodoTarea::setDescripcion(string descripcion_){
    this->descripcion=descripcion_;
}

void nodoTarea::setMateria(string materia_){
    this->materia=materia_;
}

void nodoTarea::setFecha(string fecha_){
    this->fecha=fecha_;
}


void nodoTarea::setEstado(string estado_){
    this->estado=estado_;
}


void nodoTarea::setSiguiente(nodoTarea *siguiente_){
    this->siguiente = siguiente_;
}

void nodoTarea::setAnterior(nodoTarea *anterior_){
    this->anterior=anterior_;
}
