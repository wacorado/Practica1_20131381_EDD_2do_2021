//
//  nodoMatriz.cpp
//  Practica1PruebasXCODE
//
//  Created by NegroCorado on 19/08/21.
//

#include "nodoMatriz.hpp"

nodoMatriz::nodoMatriz(){
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
}

nodoMatriz::nodoMatriz(string id_,string mes_,string dia_,string hora_, string carnet_, string nombre_, string descripcion_, string materia_, string fecha_, string estado_)
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
}

string nodoMatriz::getId()
{
    return this->id;
}

string nodoMatriz::getMes(){
    return this->mes;
}

string nodoMatriz::getDia(){
    return this->dia;
}

string nodoMatriz::getHora(){
    return this->hora;
}

string nodoMatriz::getCarnet()
{
    return this->carnet;
}

string nodoMatriz::getNombre(){
    return this->nombre;
}

string nodoMatriz::getDescripcion(){
    return this->descripcion;
}

string nodoMatriz::getMateria(){
    return this->materia;
}

string nodoMatriz::getFecha(){
    return this->fecha;
}

string nodoMatriz::getEstado(){
    return this->estado;
}


void nodoMatriz::setId(string id_)
{
    this->id = id_;
}

void nodoMatriz::setMes(string mes_){
    this->id = mes_;
}

void nodoMatriz::setDia(string dia_){
    this->dia = dia_;
}

void nodoMatriz::setHora(string hora_){
    this->hora = hora_;
}

void nodoMatriz::setCarnet(string carnet_){
    this->carnet = carnet_;
}

void nodoMatriz::setNombre(string nombre_){
    this->nombre=nombre_;
}

void nodoMatriz::setDescripcion(string descripcion_){
    this->descripcion=descripcion_;
}

void nodoMatriz::setMateria(string materia_){
    this->materia=materia_;
}

void nodoMatriz::setFecha(string fecha_){
    this->fecha=fecha_;
}

void nodoMatriz::setEstado(string estado_){
    this->estado=estado_;
}
