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
    //bool buscarCarnet(int carnet);
    bool validaEspacio(string id);
    bool validaModificar(string id, string carnet);
    int getTamano();
    void ingresarbyId(string id, string mes, string dia, string hora, string carnet, string nombre, string descripcion, string materia, string fecha, string estado);
    void imprimirLista();
    void obtenerTareaColum(string id, string mes, string dia, string hora, string carnet, string nombre, string descripcion, string materia, string fecha, string estado);
    void insertarTarea(string id, string mes, string dia, string hora, string carnet, string nombre, string descripcion, string materia, string fecha, string estado);
    void eliminarTarea (string id);
    void graficarTareas();
    void busquedaLinearizada(string id);
    string contarCarnets();
    string dataArchivo(string carnet);
};
