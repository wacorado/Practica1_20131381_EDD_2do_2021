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
    bool encontrarCarnet(int carnet);
    int getTamano();
    void modificarNodo(string Dpi);
    void imprimirListaEstudiantes();
    void insertarValorIncio(string carnet, string dpi, string nombre, string carrera, string contrasena, string creditos, string edad, string correo);
    void insertarValorFinal(string carnet, string dpi, string nombre, string carrera, string contrasena, string creditos, string edad, string correo);
    void eliminarValor(string Dpi);
    void graficarLista();
    string dataArchivo(string carnet);
    
};
