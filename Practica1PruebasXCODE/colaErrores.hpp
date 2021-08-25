#include "nodoError.hpp"

class colaErrores
{
private:
    nodoError *primero;
    nodoError *ultimo;

public:
    //Constructor
    colaErrores();

    //Metodos
    bool vacia();
    int getTamano();
    void imprimirCola();
    void encolar(int id, string tipo, string descripcion);
    int desencolar ();
    void graficarCola();
    bool esEstudiante();
};
