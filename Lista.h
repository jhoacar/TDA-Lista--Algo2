#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

const int SMALLER = -1;
const int BIGGER = 1;
const int EQUALS = 0;
const int DONT_FOUND = -1;

//Pre: Dos datos a comparar, con sobrecargas de los operadores "<,>,=="
//Post: Compara y devuelve SMALLER si A es menor que B, BIGGER si A es mayor que B y EQUALS caso contrario
template<class Dato>
int comparacion(Dato A, Dato B){
    if(A<B)
        return SMALLER;
    else if(A>B)
        return BIGGER;
    else
        return EQUALS;
}

template <class Dato>
void swap_data(Dato &a, Dato &b){
  Dato tmp = a;
  a = b;
  b = tmp;
}


template <class Dato>
class Lista
{
	  Nodo<Dato> *start;
		Nodo<Dato> *end;
    Nodo<Dato> *actual;
		unsigned long size;
    
    //Pre: Esta lista actual previamente vacia y una lista por parametro con la informacion a copiar 
    //Post: Carga toda la informacion de la lista del parametro a esta lista actual 
    void copy_all(const Lista &lista);
    
    //Pre: Lista con datos previamente, para ser eliminados.
    //Post: Elimina toda la informacion de la lista, liberando toda la memoria reservada
    void erase_all();

    //Pre: Un indice a buscar en la lista
    //Post: Devuelve el nodo que se encuentra en ese indice de la lista
		Nodo<Dato>* search_node(const int index) const;
    
    
	public:
		
    //Pre: Constructor por defecto
    //Post: Crea desde cero a una lista vacia
    Lista();
    
    //Pre: Una lista previamente cargada con informacion
    //Post: Constructor de copia que crea una lista con toda la informacion de la lista del parametro
    Lista(const Lista &lista);
    
    //Pre: 
    //Post: Elimina toda la lista
    ~Lista();
		
    //Pre: Una funcion que permita imprimir el tipo de dato de la lista
    //Post: Recorre cada dato de la lista y la imprime con la funcion que fue ofrecida
    void print(void (*print_data)(const Dato dato));
    
    //Pre: Un dato a cargar a la lista
    //Post: Agrega al final de la lista el dato por parametro
    void add(Dato dato);
    
    //Pre: Un dato a cargar a la lista
    //Post: Devuelve un puntero con la referencia de la lista con dicho dato agregado al final
    Lista<Dato>* push(Dato dato);
    
    //Pre: Un indice a eliminar de la lista
    //Post: Devuelve verdadero si fue eliminado de la lista, falso caso contrario
    bool erase(const int index);
    
    //Pre: 
    //Post: Devuelve el tamano de la lista
		int get_size() const;
		
    //Pre: Un indice a evaluar si esta en el rango valido
    //Post: Devuelve verdadero si puede estar en la lista, falso caso contrario
    bool is_valid(const int index) const;
    
    //Pre: Un dato a evaluar su existencia
    //Post: Devuelve verdadero si se encontro en la lista dicho dato
    bool exists(Dato dato, int (*compare)(Dato A , Dato B)) const;
    
    //Pre: El comienzo de la busqueda (puede ser desde el origen: 0), el dato a buscar y una funcion donde me compara dos Datos A y B si son iguales
    //Post: Devuelve la posicion donde encontro dicho dato buscandolo desde el indice de comienzo
    int search_data(int start_search,const Dato dato, int (*compare)(Dato A, Dato B)) const;
    
    //Pre: Un indice a buscar en la lista
    //Post: Devuelve una referencia del dato que se encuentra en dicha posicion
		Dato& operator[](const int index) const;
    
    //Pre: Una lista con la informacion a cargar
    //Post: Elimina la informacion que se encontraba antes y copia la informacion de ahora de la lista
		void operator=(const Lista &lista);
    
    //Pre: Una lista a unir
    //Post: Devuelve un puntero con la lista de la union, eliminando la informacion de la lista del parametro
    Lista<Dato>* operator+(Lista &lista);
    
    //Pre: Una funcion que permita comparar dos datos
    //Post: Ordena de menor a mayor de acuerdo a la funcion del parametro
    void sort(int (*compare)(const Dato a, const Dato b));
    
    //Pre: Esta lista, previamente ordenada
    //Post: Elimina todas aquellas ocurrencias repetidas de la lista    
    void clean();

    //Pre: Dos posiciones de la lista
    //Post: Intercambia sus datos en la lista
    void swap(const int index_a, const int index_b);

    //Pre: Una lista para unir
    //Post: Une esta lista con la del parametro, modificandose
    void operator+=(const Lista &lista);

    //Pre: Una lista para unir
    //Post: Devuelve la union de esta lista con la del parametro, sin modificar esta
    Lista* get_union(const Lista &lista);
		
    //Pre:
    //Post: Revierte el orden de esta lista, donde el ultimo se encontrara en el primero
    void reverse();

    //Pre:
    //Post: Devuelve un puntero con esta lista revertida, sin modificar esta
    Lista *get_reverse();

    //Pre: Recibe una lista con la informacion y una funcion de comparacion entre dos datos (Este método devolvera -1 si A es menor que B; 1, si A es mayor que B; y 0 si son iguales.)
    //Post:se hace un merge entre las dos, modificando la original, que tiene que quedar ordenada  y  sin  elementos  repetidos.
    void merge(const Lista &lista, int (*comparar)(const Dato A, const Dato B));

    //Pre: Un dato a eliminar de la lista y una funcion de comparacion entre dos datos A y B
    //Post: Elimina el dato si lo encontro en la lista basandose en el criterio de la funcion de comparacion
    void erase_data(const Dato dato, int (*compare)(Dato A, Dato B));

    //Pre: Un dato a eliminar de la lista y una funcion con el criterio de comparacion entre dos Datos A y B
    //Post: Elimina todos las ocurrencias que encuentra del dato en la lista
    void erase_all_occurrences(const Dato dato, int (*compare)(Dato A, Dato B));

    //Pre: Una lista cargada y una funcion que me permita comparar dos Datos, A y B
    //Post: Retorna una nueva lista con los datos de esta lista que no esta con la del parametro
    Lista* get_difference(const Lista lista , int (*compare)(Dato A, Dato B) );

    //Pre:
    //Post: Pone el puntero a la primera posición o apuntando a NULL
    void reset (void);
    
    //Pre:
    //Post: devuelve true si el actual no apunta a NULL, false de lo contrario
    bool exists_next (void) const;
    
    //Pre: hay_siguiente tiene que haber devuelto true previamente
    //Post: devuelve el elemento actual y avanza
    Dato next_data(void);

    //Pre: Una lista a analizar y una funcion con el criterio de comparacion
    //Post: Devuelve verdadero si encuentra alguna coincidencia de un dato con la lista del parametro, falso caso contrario
    bool exist_any(const Lista &lista, int(*compare)(Dato A, Dato B));
};

template <class Dato>
Lista<Dato>::Lista(){
      this->start = new Nodo<Dato>();
      this->end=this->start;
      this->actual=this->start;
	    this->size=0;
}

template <class Dato>
Lista<Dato>::Lista(const Lista &lista){
  copy_all(lista);
}

template <class Dato>
Lista<Dato>::~Lista(){
  erase_all();
}

template <class Dato>
void Lista<Dato>::print(void (*print_data)(const Dato dato)){
  for(int i=0 ; i < (int)size ; i++)
    print_data((*this)[i]);
}

template <class Dato>
void Lista<Dato>::copy_all(const Lista &lista){
  this->start = new Nodo<Dato>();
  this->end=this->start;
  this->actual=this->start;
  this->size=0;
  for(int i=0; i< lista.get_size(); i++)
    add(lista[i]);
}

template <class Dato>
void Lista<Dato>::add(Dato dato){
  *(end->dato)=dato;
  end->next = new Nodo<Dato>();
  end=end->next;
  size+=1;
}
template <class Dato>
Lista<Dato>* Lista<Dato>::push(Dato dato){
  add(dato);
  return this;
}

template <class Dato>
void Lista<Dato>::erase_all(){
  Nodo<Dato> *tmp;
  while( start!=nullptr ){
    tmp = start;
    start = start->next;
    delete tmp;
  }
}

template <class Dato>
bool Lista<Dato>::erase(const int index){

  Nodo<Dato> *erase_node = search_node(index);
  
  if(erase_node == nullptr) //Si no se encuentra en la lista no se elimina
    return false;
  
  Nodo<Dato> *before = search_node(index-1);

  if(before==nullptr) // Si no tiene antecesor entonces se encuentra en el inicio
    start = erase_node->next; //Se referencia al que sigue
  else if(erase_node->next == nullptr){// Si en el que sigue no hay nada, se encuentra al final
    end = before;
    end->next=nullptr;
  }
  else //Se deja de referenciar 
    before->next = erase_node->next;

  delete erase_node;
  
  size--;
  return true;
}

template <class Dato>
int Lista<Dato>::get_size() const{
  return (int)size;
}

template <class Dato>
bool Lista<Dato>::is_valid(const int index) const{
  return index>=0 && index<= (int) size;
}

template <class Dato>
bool Lista<Dato>::exists(Dato dato,int (*compare)(Dato A , Dato B)) const{
  return search_data(0,dato,compare) != DONT_FOUND;
}


template <class Dato>
Nodo<Dato>* Lista<Dato>::search_node(const int index) const{
  
  if(!is_valid(index))
    return nullptr;

  Nodo<Dato> *nodo = start;
  for(int i=0 ; i < index  ; i++)
    nodo = nodo->next; 	
  
  return nodo;
}

template <class Dato>
int Lista<Dato>::search_data(int start_search,const Dato dato, int (*compare)(Dato A,Dato B)) const{

  Nodo<Dato> *nodo = search_node(start_search);
  
  if(nodo==nullptr)
    return DONT_FOUND;

  bool found = compare(*(nodo->dato) , dato) == EQUALS;

  while(start_search< (int) size && !found){
    nodo = nodo->next;
    if(nodo!=nullptr)
      found = compare(*(nodo->dato) , dato) == EQUALS;
    start_search++;
  } 	
  return found ? start_search : DONT_FOUND;
}

template <class Dato>
Dato& Lista<Dato>::operator[](const int index) const{
  Nodo<Dato> *nodo = search_node(index);
  return *(nodo->dato);
}

template <class Dato>
void Lista<Dato>::operator=(const Lista &lista){
  erase_all();
  copy_all(lista);
}
 
template <class Dato>
Lista<Dato>* Lista<Dato>::operator+(Lista &lista){
  (*this)+=lista;
  lista.erase_all();
  return this;
}

template <class Dato>
void Lista<Dato>::sort(int (*compare)(const Dato a, const Dato b)){
    *this=*quick_sort(*this,compare);
}

template <class Dato>
void Lista<Dato>::clean(){
  Lista nueva;
  for( int i=0 ; i< (int) size; i++){
    Dato dato = (*this)[i];
    if( i< (int) size && dato != (*this)[i+1]) 
      nueva.add(dato);
  }
  (*this) = nueva;

}

template <class Dato>
void Lista<Dato>::swap(const int index_a, const int index_b){
  
  if(index_a == index_b) //Mejora el rendimiento de hacer busquedas innecesarias
    return;

  Nodo<Dato> *node_a = search_node(index_a);
  Nodo<Dato> *node_b = search_node(index_b); 

  if(node_a == nullptr || node_b == nullptr)
    return;

  swap_data( (*this)[index_a] , (*this)[index_b] );

}

template <class Dato>
void Lista<Dato>::operator+=(const Lista &lista){
  for( int i=0; i<lista.get_size(); i++)
    add(lista[i]);
}

template <class Dato>
Lista<Dato>* Lista<Dato>::get_union(const Lista &lista){
  Lista *nueva = new Lista(*this);
  (*nueva)+=lista;
  return nueva;
}

template <class Dato>
void Lista<Dato>::reverse(){
  Lista nueva;
  for(int i = (int)size - 1 ; i>=0 ; i-- )
    nueva.add((*this)[i]);
  (*this) = nueva;
}

template <class Dato>
Lista<Dato>* Lista<Dato>::get_reverse(){
  Lista *nueva = new Lista(*this);
  nueva->reverse();
  return nueva;
}

template <class Dato>
void Lista<Dato>::merge(const Lista &lista, int (*comparar)(const Dato a, const Dato b)){
  (*this)+=lista;
  sort(comparar);
  clean();
}

template <class Dato>
void Lista<Dato>::erase_data(const Dato dato, int (*compare)(Dato A, Dato B)){
  erase(search_data(0,dato,compare));
}

template <class Dato>
void Lista<Dato>::erase_all_occurrences(const Dato dato, int (*compare)(Dato A, Dato B)){
  int start = -1;
  do{
    start = search_data(start+1,dato,compare);
    erase(start);
  }while(start!= DONT_FOUND);
}

template <class Dato>
Lista<Dato>* Lista<Dato>::get_difference(const Lista<Dato> lista, int (*compare)(Dato A, Dato B)){
  Lista *nueva = new Lista();
  for(int i = 0 ; i < (int)size ; i++){
    if(!lista.exists( (*this)[i], compare ) )
      nueva->add((*this)[i]);
  }
  return nueva;
}

template <class Dato>
void Lista<Dato>::reset (void){
  actual=start;
}

template <class Dato>
bool Lista<Dato>::exists_next (void) const {
    return actual->next!=nullptr;
}

template <class Dato>
Dato Lista<Dato>::next_data(void){
  Dato dato = *(actual->next->dato);
  actual=actual->next;
  return dato;
}

template <class Dato>
bool Lista<Dato>::exist_any(const Lista<Dato> &lista , int(*compare)(Dato A, Dato B)){
  bool found = false;
  int i = 0;
  while(i< lista.get_size()){
    found = exists(lista[i],compare);
    i++;
  }
  return found;
}


template <class Dato>
Lista<Dato>* selection_sort(Lista<Dato> &list,int (*compare)(const Dato a, const Dato b)){
      Lista<Dato> *nueva = new Lista<Dato>(list);
      for(int i = 0; i < nueva->get_size(); i++){
        Dato min = (*nueva)[i];
        int min_index = i;
        for(int j = i+1 ; j < nueva->get_size() ; j++ ){
          if( compare( (*nueva)[j] , min ) == SMALLER ){
            min = (*nueva)[j];
            min_index = j;
          }
        }
        nueva->swap(i,min_index);
      }
      return nueva;
}

template <class Dato>
Lista<Dato>* quick_sort(Lista<Dato> &list,int (*compare)(const Dato a, const Dato b)){
    if(list.get_size()==0)
      return new Lista<Dato>();
    Lista<Dato> left;
    Lista<Dato> right;
    Dato pivot = list[0];

    for(int i=1;i<list.get_size();i++){
        if(compare(list[i],pivot)==SMALLER)
          left.add(list[i]);
        else
          right.add(list[i]);
    }
  return *(quick_sort(left,compare)->push(pivot))+*quick_sort(right,compare);
}


#endif