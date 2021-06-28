#include "Lista.h"
#include <iostream>

using namespace std;

void print_data(string dato){
    cout<<dato<<" ";
}
void print_lista(Lista<string> lista){
    lista.print(print_data);
    cout<<endl;
}

void test_lista(){

    cout<<"TEST : "<<endl;

    Lista<string> A;
    Lista<string> B;
    Lista<Lista<string>> matriz;

    for(int i=0 ; i< 5; i++)
        A.add("("+to_string(i)+")");
    for(int i=5 ; i< 8; i++)
        B.add("("+to_string(i)+")");
        

    cout<<"Test (Swap): "<<endl;
    A.print(print_data);
    cout<<endl<<"Swap:"<<endl;
    A.swap(1,3);
    A.print(print_data);
    cout<<endl<<endl;
    
    cout<<"Test (Union): "<<endl;
    A.print(print_data);
    cout<<endl;
    B.print(print_data);
    cout<<endl<<"Union:"<<endl;
    A+=B;
    //Lista<string> *C = A.get_union(B);
    A.print(print_data);
    cout<<endl;
    //C->print(print_data);
    //cout<<endl<<endl;
    //delete C;
    
    cout<<"Test (Reverse): "<<endl;
    A.print(print_data);
    cout<<endl<<"Reverse:"<<endl;
    A.reverse();
    Lista<string> *D = A.get_reverse();
    A.print(print_data);
    cout<<endl;
    D->print(print_data);
    cout<<endl<<endl;
    delete D;

    cout<<"Test (Merge): "<<endl;
    A.print(print_data);
    cout<<endl;
    B.print(print_data);
    cout<<endl<<"Merge:"<<endl;
    A.merge(B,comparacion);
    A.print(print_data);

    cout<<endl<<endl;

    
    cout<<"Test (Erase): "<<endl;
    B.print(print_data);
    cout<<endl<<"Erase:"<<endl;
    B.erase_data("(5)",comparacion);
    B.print(print_data);
    
    cout<<endl<<endl;

    cout<<"Test (Erase All Occurrences): "<<endl;
    A.print(print_data);
    cout<<endl<<"Erase All Ocurrences:"<<endl;
    A.erase_all_occurrences("(5)",comparacion);
    A.print(print_data);
    
    cout<<endl<<endl;

    cout<<"Test (Difference): "<<endl;
    A.print(print_data);
    cout<<endl;
    B.print(print_data);
    cout<<endl<<"Difference:"<<endl;
    Lista<string> *E = A.get_difference(B,comparacion);
    E->print(print_data);

    cout<<endl<<endl;

    cout<<"Presione una tecla para continuar...";
    cin.get();
}

int main(){
    test_lista();
}