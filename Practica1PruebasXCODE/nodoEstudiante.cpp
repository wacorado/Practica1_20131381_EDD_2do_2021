#include "nodoEstudiante.hpp"

// Constructores
nodoEstudiante::nodoEstudiante()
{
    this->edad = "";
    this->dpi = "";
    this->nombre = "";
    this->carrera = "";
    this->correo = "";
    this->contrasena = "";
    this->creditos = "";
    this->carnet = "";
    this->siguiente = NULL;
    this->anterior = NULL;
}

nodoEstudiante::nodoEstudiante(string carnet_, string dpi_, string nombre_, string carrera_, string contrasena_, string creditos_, string edad_, string correo_)
{
    this->carnet = carnet_;
    this->dpi = dpi_;
    this->nombre = nombre_;
    this->carrera = carrera_;
    this->contrasena = contrasena_;
    this->creditos = creditos_;
    this->edad = edad_;
    this->correo = correo_;
    this->siguiente = 0;
    this->anterior = 0;
}

nodoEstudiante::nodoEstudiante(string carnet_, string dpi_, string nombre_, string carrera_, string contrasena_, string creditos_, string edad_, string correo_, nodoEstudiante *anterior_, nodoEstudiante *siguiente_)
{
    this->carnet = carnet_;
    this->dpi = dpi_;
    this->nombre = nombre_;
    this->carrera = carrera_;
    this->contrasena = contrasena_;
    this->creditos = creditos_;
    this->edad = edad_;
    this->correo = correo_;
    this->siguiente = siguiente_;
    this->anterior = anterior_;
}

// Getters

string nodoEstudiante::getCarnet()
{
    return this->carnet;
}

string nodoEstudiante::getDpi()
{
    return this->dpi;
}

string nodoEstudiante::getNombre(){
    return this->nombre;
}

string nodoEstudiante::getCarrera(){
    return this->carrera;
}

string nodoEstudiante::getContrasena(){
    return this->contrasena;
}

string nodoEstudiante::getCreditos(){
    return this->creditos;
}

string nodoEstudiante::getEdad(){
    return this->edad;
}

string nodoEstudiante::getCorreo(){
    return this->correo;
}

nodoEstudiante *nodoEstudiante::getSiguiente()
{
    return this->siguiente;
}

nodoEstudiante *nodoEstudiante::getAnterior(){
    return this->anterior;
}

// Setters

void nodoEstudiante::setDpi(string dpi_)
{
    this->dpi = dpi_;
}

void nodoEstudiante::setCarnet(string carnet_){
    this->carnet = carnet_;
}

void nodoEstudiante::setNombre(string nombre_){
    this->nombre=nombre_;
}

void nodoEstudiante::setCarrera(string carrera_){
    this->carrera=carrera_;
}

void nodoEstudiante::setCorreo(string correo_){
    this->correo=correo_;
}

void nodoEstudiante::setContrasena(string contrasena_){
    this->contrasena=contrasena_;
}

void nodoEstudiante::setCreditos(string creditos_){
    this->creditos=creditos_;
}

void nodoEstudiante::setEdad(string edad_){
    this->edad=edad_;
}

void nodoEstudiante::setSiguiente(nodoEstudiante *siguiente_){
    this->siguiente = siguiente_;
}

void nodoEstudiante::setAnterior(nodoEstudiante *anterior_){
    this->anterior=anterior_;
}
