#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include "Lista.h"
#include <string>
#include <iostream>
using namespace std;

class Universidad
{
    string nombre;
    int ranking;
    Lista<string> *carreras;
    public:
        // Crea una universidad con su nombre, el ranking y una lista de carreras
        Universidad(string nombre, int ranking, Lista<string>* carreras):nombre(nombre),ranking(ranking){
            this->carreras = new Lista<string>(*carreras);
        }
        ~Universidad(){
            delete carreras;
        }
        string obtener_nombre() const// devuelve el nombre de la universidad
        {
            return nombre;
        }
        unsigned int obtener_ranking () const // devuelve el ranking
        {
            return (unsigned int)ranking;
        }
        Lista<string>* obtener_carreras () const// devuelve ptr a lista de carreras
        {
            return carreras;
        }
        bool exist_any(Lista<string> carreras)
        { 
           return this->carreras->exist_any(carreras,comparacion);;
        }
};
//Implementar el método recomendar_universidades de la clase Buscador_universidades:
class Buscador_universidades
{
    public:
        Buscador_universidades(){};
        ~Buscador_universidades(){};
        // Post: busca en “universidades” aquellas que tienen alguna carrera de la
        // lista “vocaciones” y un ranking mayor o igual a ranking_minimo.
        // Devuelve una lista con las universidades que cumplen con estas características.
        Lista<Universidad *>* recomendar_universidades (Lista<Universidad *>*universidades, Lista<string>* vocaciones, int ranking_minimo)
        {
            Lista<Universidad *>* recomendaciones = new Lista<Universidad *>;
            for(int i = 0 ; i < universidades->get_size(); i++){
                
                if( (*universidades)[i]->obtener_ranking() >=(unsigned int) ranking_minimo && (*universidades)[i]->exist_any(*vocaciones) )
                {
                    recomendaciones->add((*universidades)[i]);
                }
            }
            return recomendaciones;
        }
};

#endif