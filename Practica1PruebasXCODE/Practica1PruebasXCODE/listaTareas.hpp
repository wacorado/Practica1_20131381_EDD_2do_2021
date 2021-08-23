#include "nodoTarea.hpp"

class listaTareas
{
private:
    nodoTarea *primero;
    nodoTarea *ultimo;

public:
    //Constructor
    listaTareas();

    //Metodos
    bool vacia();
    int getTamano();
    void imprimirLista();
    void obtenerTareaColum(string id, string mes, string dia, string hora, string carnet, string nombre, string descripcion, string materia, string fecha, string estado);
    void insertarTarea(string id, string mes, string dia, string hora, string carnet, string nombre, string descripcion, string materia, string fecha, string estado);
    void eliminarTarea (string id);
};
