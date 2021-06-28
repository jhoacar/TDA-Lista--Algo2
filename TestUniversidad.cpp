#include "Universidad.h"
#include "Funciones.h"

#include <string>
using std::string;

void print_string(const string cadena){
    cout<<"\t"<<cadena<<endl;
}

void print_universidades(Universidad *universidad){
    cout<<endl<<"NOMBRE: "<<universidad->obtener_nombre()<<endl;
    cout<<"RANKING: "<<universidad->obtener_ranking()<<endl;
    cout<<"CARRERAS: "<<endl;
    universidad->obtener_carreras()->print(print_string);
}

void print_nombre_universidades(Universidad *universidad){
    cout<<endl<<"-"<<universidad->obtener_nombre();
}

void cargar_universidades(Lista<Universidad*> &universidades){
    string texto = obtener_texto("universidades.txt");
    Lista<string> datos = dividir_texto(texto,'!');
    for( int i = 0; i< datos.get_size(); i++)
    {
        Lista<string> datos_universidades = dividir_texto(datos[i],';');
        Lista<string> *carreras = new Lista<string>(dividir_texto(datos_universidades[2],'\n'));
        universidades.add(new Universidad(datos_universidades[0],convertir_entero(datos_universidades[1]),carreras));        
    }
}

void cargar_recomendaciones(Lista<string> *&vocaciones){
    string texto = obtener_texto("vocaciones.txt");
    vocaciones =  new Lista<string>(dividir_texto(texto,'\n'));
}

int main(){
    Lista<Universidad*> universidades;
    int ranking_minimo=10;
    Lista<string> *vocaciones;

    cargar_universidades(universidades);
    cargar_recomendaciones(vocaciones);
    
    universidades.print(print_universidades);

    cout<<"VOCACIONES: "<<endl;
    vocaciones->print(print_string);
    
    Buscador_universidades buscador;
    Lista<Universidad*> *recomendaciones = buscador.recomendar_universidades(&universidades,vocaciones,ranking_minimo);
    
    cout<<"UNIVERSIDADES RECOMENDADAS ("<<recomendaciones->get_size()<<"): "<<endl;
    recomendaciones->print(print_nombre_universidades);
}