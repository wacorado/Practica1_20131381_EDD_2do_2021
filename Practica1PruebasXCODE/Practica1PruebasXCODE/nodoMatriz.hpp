#include <string>
#include <iostream>

using namespace std;

class nodoMatriz{
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
public:
    //constructores
    nodoMatriz();
    nodoMatriz(string id_,string mes_,string dia_,string hora_, string carnet_, string nombre_, string descripcion_, string materia_, string fecha_, string estado_);
    
    //Getters
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
    
    //setters
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
    
};
