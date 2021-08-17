#include "listaEstudiantes.hpp"

listaEstudiantes::listaEstudiantes(){
    this->primero = NULL;
    this->ultimo = NULL;
}

bool listaEstudiantes::vacia(){
    return this->primero == NULL;
}

void listaEstudiantes::insertarValorFinal(string carnet_, string dpi_, string nombre_, string carrera_, string correo_, string contrasena_, string creditos_, string edad_)
{
    nodoEstudiante *nuevo;
    nuevo = new nodoEstudiante(edad_, dpi_, nombre_,carrera_,correo_,contrasena_,creditos_,edad_);
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
            cout << "Correo Estudiante: " <<actual->getNombre()<< endl;
            cout << "Contraseña Estudiante: " <<actual->getContrasena()<< endl;
            cout << "No. de Creditos: " <<actual->getCreditos()<< endl;
            cout << "Edad del Estudiante: "<<actual->getEdad()<< endl;
            actual = actual->getSiguiente();
        }while(actual != primero);
    }else{
        cout<< "\n La lista se Encuentra Vacia\n\n";
    }
}
