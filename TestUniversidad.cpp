#include "Universidad.h"
#include "Funciones.h"

#include <string>
using std::string;

void print_string(const string cadena){
    cout<<"\t"<<cadena<<endl;
}

void print_universidades(Universidad *universidad){
    cout<<"NOMBRE: "<<universidad->obtener_nombre()<<endl;
    cout<<"RANKING: "<<universidad->obtener_ranking()<<endl;
    cout<<"CARRERAS: "<<endl;
    universidad->obtener_carreras()->print(print_string);
}

Lista<Universidad*> universidades;

void cargar_universidades(){
    string texto = obtener_texto("universidades.txt");
    Lista<string> datos = dividir_texto(texto,'!');
    for( int i = 0; i< datos.get_size(); i++)
    {
        Lista<string> datos_universidades = dividir_texto(datos[i],';');
        Lista<string> *carreras = new Lista<string>(dividir_texto(datos_universidades[2],'\0'));
        universidades.add(new Universidad(datos_universidades[0],convertir_entero(datos_universidades[1]),carreras));        
    
    }
}


int main(){
    cargar_universidades();
    universidades.print(print_universidades);
}