#include <iostream>
#include <string>
using namespace std;

class nodoError
{
private:
    int id;
    string tipo;
    string descripcion;
    nodoError *siguiente;
    nodoError *anterior;

public:
    // aqui se declaran los constructures
    nodoError();
    nodoError(int id_, string tipo_, string descripcion_);
    nodoError(int id_, string tipo_, string descripcion_, nodoError *siguiente_, nodoError *anterior_);
    
    // aqui estan los metodos GET
    int getId();
    string getTipo();
    string getDescripcion();
    nodoError *getAnterior();
    nodoError *getSiguiente();
    
    // Aqui se generan los SET
    void setId(int id_);
    void setTipo(string tipo_);
    void setDescripcion(string descripcion_);
    void setAnterior(nodoError * nodo_);
    void setSiguiente(nodoError *nodo_);
};
