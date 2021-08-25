#include <iostream>
#include <string>
using namespace std;

class nodoEstudiante
{
private:
    string carnet;
    string dpi;
    string nombre;
    string carrera;
    string contrasena;
    string creditos;
    string edad;
    string correo;
    nodoEstudiante *siguiente;
    nodoEstudiante *anterior;

public:
    // aqui se declaran los constructures
    nodoEstudiante();
    nodoEstudiante(string carnet_, string dpi_, string nombre_, string carrera_, string contrasena_, string creditos_, string edad_, string correo_);
    nodoEstudiante(string carnet_, string dpi_, string nombre_, string carrera_, string contrasena_, string creditos_, string edad_, string correo_, nodoEstudiante *siguiente_, nodoEstudiante *anterior_);
    
    // aqui estan los metodos GET
    string getCarnet();
    string getDpi();
    string getNombre();
    string getCarrera();
    string getCorreo();
    string getContrasena();
    string getCreditos();
    string getEdad();
    nodoEstudiante *getAnterior();
    nodoEstudiante *getSiguiente();
    
    // Aqui se generan los SET
    void setCarnet(string carnet_);
    void setDpi(string dpi_);
    void setNombre(string nombre_);
    void setCarrera(string carrera_);
    void setCorreo(string correo_);
    void setContrasena(string contrasena_);
    void setCreditos(string creditos_);
    void setEdad(string edad_);
    void setAnterior(nodoEstudiante * nodo_);
    void setSiguiente(nodoEstudiante *nodo_);
 
};
