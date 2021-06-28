#ifndef NODO_H
#define NODO_H


template <class Dato>
class Nodo{
    Dato *dato;
    Nodo<Dato> *next;
    public:
        //Usado para poder acceder a estos miembros desde la clase lista
        template <class> friend class Lista;
        Nodo(){
            dato = new Dato;
            next=nullptr;
        }
        ~Nodo(){
            delete dato;
            dato=nullptr;
        }
};

#endif