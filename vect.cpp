#include <iostream>
#include "Complex.h"
#include "vect.h"

using namespace std;

vect::vect()//constructor de declarare
{
    obj=NULL;
    n=0;
}

vect::vect(int a)//constructor de initializare
{
    n=a;
    obj=new Complex [n];
}

vect::vect(const vect &a)//constructor de copiere
{
    n = a.n;
    obj = a.obj;
}

vect::~vect()//deconstructor
{
    delete [] obj;
    n=0;
}

void vect::cit_n(int n, Complex *obj)//metoda de citire si scriere a n numere complexe
{
    int i;
    for (i=0; i<n; i++)
    {
        cout <<"nr"<<i<<"=";
        cin>>obj[i];
    }
    for (i=0; i<n; i++)
        cout<<"nr"<<i<<"="<<obj[i]<<endl;
}

Complex* vect::get_obj()
{
    return this->obj;
}
