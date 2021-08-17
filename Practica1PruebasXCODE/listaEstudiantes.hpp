#include "nodoEstudiante.hpp"

class listaEstudiantes
{
private:
    nodoEstudiante *primero;
    nodoEstudiante *ultimo;

public:
    //Constructor
    listaEstudiantes();

    //Metodos
    bool vacia();
    int getTamano();
    void imprimirListaEstudiantes();
    void insertarValorIncio(string carnet, string dpi, string nombre, string carrera, string contrasena, string creditos, string edad, string correo);
    void insertarValorFinal(string carnet, string dpi, string nombre, string carrera, string contrasena, string creditos, string edad, string correo);
    void eliminarValor(int value);
};
