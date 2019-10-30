#include <iostream>
#include <math.h>
#include "Complex.h"

using namespace std;

Complex::Complex()//constructor de initializare
{

}

Complex::~Complex()//destructor
{

}

Complex::Complex(const Complex &a)//constructor de copiere
{
    real=a.real;
    imag=a.imag;
}

void Complex::setare(const double a, const double b)//metoda de setare pt partea reala si imaginara
{
    this->real=a;
    this->imag=b;
}

double Complex::get_r()//metoda de furnizare a partii reale
{
  return this->real;
}

double Complex::get_im()//metoda de furnizare a partii imaginare
{
    return this->imag;
}

istream & operator >> (istream & in, Complex &a)//supraincarcarea operatorului de citire
{
    in>>a.real;
    in>>a.imag;
    return in;
}

ostream & operator << (ostream & out, Complex &a)//supraincarcarea operatorului de afisare
{
    if (a.imag==0)
        out<<a.real;
    else if (a.real==0 && a.imag>0)
        out<<"i*"<<a.imag;
    else if (a.real==0 && a.imag<0)
        out<<a.imag<<"*i";
    else if (a.imag>0)
        out<<a.real<<"+ i*"<<a.imag;
    else out<<a.real<<a.imag<<"*i";
    return out;
}

Complex operator + (Complex a, Complex b)//operatoruul de adunare pt doua numere complexe
{
    a.real += b.real;
    a.imag += b.imag;
    return a;
}

Complex operator + (double a, Complex b)//operatorul de adunare pt un nr real si unul complex
{
    b.real += a;
    return b;
}

Complex operator + (Complex a, double b)//operatorul de adunare pt un nr complex si unul real
{
    a.real += b;
    return a;
}

Complex operator + (Complex a)
{
    a.real += a.real;
    a.imag += a.imag;
    return a;
}

Complex operator - (Complex a, Complex b)//operatorul de scadere pt doua numere complexe
{
    a.real -= b.real;
    a.imag -= b.imag;
    return a;
}

Complex operator - (double a, Complex b)//operatorul de scadere a unui nr complex dintr-un nr real
{
    Complex rez;
    rez.real = a - b.real;
    rez.imag = - b.imag;
    return rez;
}

Complex operator - (Complex a, double b)//operatorul de scadere a unui nr real dintr-un nr complex
{
    a.real -= b;
    return a;
}

Complex operator - (Complex a)//opusul numarului
{
    a.real = -a.real;
    a.imag = -a.imag;
    return a;
}

Complex operator * (Complex a, Complex b)//inmultirea a doua numere complexe
{
    Complex rez;
    rez.real= (a.real * b.real) - (a.imag * b.imag);
    rez.imag= (a.real * b.imag) + (a.imag * b.real);
    return rez;
}

Complex operator * (double a, Complex b)//inmultirea unui nr real cu un nr complex
{
    b.real *= a;
    b.imag *= a;
    return b;
}

Complex operator * (Complex a, double b)//inmultirea unui nr complex cu un nr real
{
    a.real *= b;
    a.imag *= b;
    return a;
}

Complex operator / (Complex a, Complex b)//impartirea  a doua numere complexe
{
    Complex rez;
    rez.real =((a.real * b.real)+(a.imag * b.imag))/(pow(b.real, 2)+ pow(b.imag, 2));
    rez.imag =((a.imag * b.real)-(a.real * b.imag))/(pow(b.real, 2)+ pow(b.imag, 2));
    return rez;
}

Complex operator / (double a, Complex b)//impartirea unui nr real la un nr complex
{
    Complex rez;
    rez.real = (a * b.real)/(pow(b.real, 2)+ pow(b.imag, 2));
    rez.imag = (a * b.imag)/(pow(b.real, 2)+ pow(b.imag, 2));
    return rez;
}

Complex operator / (Complex a, double b)//impartirea unui nr complex la un nr real
{
    a.real /= b;
    a.imag /= b;
    return a;
}

int operator == (Complex a, Complex b)//test de egalitate pt doua nr comlexe
{
    if (a.real==b.real && a.imag==b.imag)return 1;
    return 0;
}

int operator == (double a, Complex b)//test de egalitate pt un nr real si unul complex
{
    if (a==b.real && b.imag==0) return 1;
    return 0;
}

int operator == (Complex a, double b)//test de egalitate pt un nr complex si un nr real
{
    if (a.real==b && a.imag==0) return 1;
    return 0;
}

int operator != (Complex a, Complex b)//test de inegalitate pt doua nr complexe
{
   if (a.real!=b.real || a.imag!=b.imag)return 1;
   return 0;
}

int operator != (double a, Complex b)//test de inegalitate pt un nr real si un nr complex
{
    if (a!=b.real || b.imag!=0)return 1;
    return 0;
}

int operator != (Complex a, double b)//test de inegalitate pt un nr complex si un nr real
{
    if (a.real!=b || a.imag!=0)return 1;
    return 0;
}

//operatori de atribuire compusi pt adunare
Complex operator += (Complex a, Complex b)
{
    a.real += b.real;
    a.imag += b.imag;
    return a;
}

Complex operator += (Complex a, double b)
{
    a.real += b;
    return a;
}

//operatori de atribuire compusi pt scadere
Complex operator -= (Complex a, Complex b)
{
    a.real -= b.real;
    a.imag -= b.imag;
    return a;
}

Complex operator -= (Complex a, double b)
{
    a.real -= b;
    return a;
}

//operatori de atribuire compusi pt inmultire
Complex operator *= (Complex a, Complex b)
{
    Complex rez;
    rez.real= (a.real * b.real) - (a.imag * b.imag);
    rez.imag= (a.real * b.imag) + (a.imag * b.real);
    return rez;
}

Complex operator *= (Complex a, double b)
{
    a.real *=b;
    a.imag *=b;
    return a;
}

//operatori de atribuire compusi pt impartire
Complex operator /= (Complex a, Complex b)
{
    Complex rez;
    rez.real =((a.real * b.real)+(a.imag * b.imag))/(pow(b.real, 2)+ pow(b.imag, 2));
    rez.imag =((a.imag * b.real)-(a.real * b.imag))/(pow(b.real, 2)+ pow(b.imag, 2));
    return rez;
}

Complex operator /= (Complex a, double b)
{
    a.real /= b;
    a.imag /= b;
    return a;
}

Complex operator ^ (Complex a, unsigned int b)//ridicarea unui nr complex la putere naturala
{
    unsigned int i;
    Complex aux;
    aux=a;
    for(i=1; i<b; i++)
        a = a*aux;
    return a;
}

double abs (Complex a)//modulul unui numar complex
{
    double rez;
    rez = sqrt(pow(a.real,2)+pow(a.imag,2));
    return rez;
}

void sqrt (Complex a, Complex *rez)//radicalul unui numar complex
{
    rez[0].real = sqrt((a.real + sqrt(pow(a.real,2) + pow(a.imag,2))) /2);
    rez[0].imag = a.imag / sqrt(2* (a.real + sqrt(pow(a.real,2) + pow(a.imag,2))));
    rez[1].real = -sqrt((a.real + sqrt(pow(a.real,2) + pow(a.imag,2))) /2);
    rez[1].imag = -a.imag / sqrt(2* (a.real + sqrt(pow(a.real,2) + pow(a.imag,2))));
    //au acelasi rezultat ca formulele de mai sus
    //rez[2].real = a.imag / sqrt(2* (sqrt(pow(a.real,2) + pow(a.imag,2)) - a.real));
    //rez[2].imag = sqrt((sqrt(pow(a.real,2) + pow(a.imag,2)) - a.real) /2);
    //rez[3].real = -a.imag / sqrt(2* (sqrt(pow(a.real,2) + pow(a.imag,2)) - a.real));
    //rez[3].imag = -sqrt((sqrt(pow(a.real,2) + pow(a.imag,2)) - a.real) /2);
}

void Complex::citire(Complex &a)//metoda de citire pt un numar complex
{
    cin>>a;
}

void Complex::afisare()//metoda de afisare pt un numar complex
{
    cout<<*this;
}
