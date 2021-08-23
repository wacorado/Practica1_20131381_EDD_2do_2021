#include "listaEstudiantes.hpp"

listaEstudiantes::listaEstudiantes(){
    this->primero = NULL;
    this->ultimo = NULL;
}

bool listaEstudiantes::vacia(){
    return this->primero == NULL;
}

void listaEstudiantes::insertarValorFinal(string carnet_, string dpi_, string nombre_, string carrera_, string contrasena_, string creditos_, string edad_, string correo_)
{
    nodoEstudiante *nuevo;
    nuevo = new nodoEstudiante(carnet_, dpi_, nombre_, carrera_, contrasena_, creditos_, edad_, correo_);
    if (vacia())
    {
        primero = nuevo;
        ultimo = nuevo;
        primero->setSiguiente(primero);
        primero->setAnterior(ultimo);
    }
    else
    {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        nuevo->setSiguiente(primero);
        ultimo = nuevo;
        primero->setAnterior(ultimo);
    }
    cout <<"Estudiante: "<<nombre_<<" Registrado Correctamente"<<endl;
}

void listaEstudiantes::imprimirListaEstudiantes(){
    nodoEstudiante *actual= new nodoEstudiante();
    actual = primero;
    if (primero != NULL){
        do{
            cout<< "----------- Estudiante Registrado -------- \n"<<endl;
            cout <<"Numero de Carnet: "<<actual->getCarnet()<<endl;
            cout <<"Numero de DPI: "<<actual->getDpi()<<endl;
            cout <<"Nombre Estudiante: " <<actual->getNombre()<<endl;
            cout <<"Carrera: " <<actual->getCarrera()<< endl;
            cout << "Contraseña Estudiante: " <<actual->getContrasena()<< endl;
            cout << "No. de Creditos: " <<actual->getCreditos()<< endl;
            cout << "Edad del Estudiante: "<<actual->getEdad()<< endl;
            cout << "Correo de Estudiante: "<<actual->getCorreo()<< endl;
            actual = actual->getSiguiente();
        }while(actual != primero);
    }else{
        cout<< "\n La lista se Encuentra Vacia\n\n";
    }
}
