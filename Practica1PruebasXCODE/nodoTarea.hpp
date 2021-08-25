#include <iostream>
#include <string>
using namespace std;

class nodoTarea
{
private:
    string id;
    string mes;
    string hora;
    string dia;
    string carnet;
    string nombre;
    string descripcion;
    string materia;
    string fecha;
    string estado;
    nodoTarea *siguiente;
    nodoTarea *anterior;

public:
    // aqui se declaran los constructures
    nodoTarea();
    nodoTarea(string id_,string mes_,string dia_,string hora_, string carnet_, string nombre_, string descripcion_, string materia_, string fecha_, string estado_);
    nodoTarea(string id_,string mes_,string dia_,string hora_, string carnet_, string nombre_, string descripcion_, string materia_, string fecha_, string estado_, nodoTarea *siguiente_, nodoTarea *anterior_);
    
    // aqui estan los metodos GET
    string getId();
    string getMes();
    string getDia();
    string getHora();
    string getCarnet();
    string getNombre();
    string getDescripcion();
    string getMateria();
    string getFecha();
    string getEstado();
    nodoTarea *getAnterior();
    nodoTarea *getSiguiente();
    
    // Aqui se generan los SET
    void setId(string id_);
    void setMes(string mes_);
    void setDia(string dia_);
    void setHora(string hora_);
    void setCarnet(string carnet_);
    void setNombre(string nombre_);
    void setDescripcion(string descripcion_);
    void setMateria(string materia_);
    void setFecha(string fecha_);
    void setEstado(string estado_);
    void setAnterior(nodoTarea * nodo_);
    void setSiguiente(nodoTarea *nodo_);
};
