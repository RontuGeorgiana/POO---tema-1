#include <iostream>
#include "Complex.h"
#include "vect.h"

using namespace std;

void ec (Complex *x)//rezolvarea ecuatiei de gradul 2
{
    Complex a,b,c,del;//coeficienti si delta
    Complex *del_rad;//radical din delta
    del_rad=new Complex[2];
    cout<<"a=";
    cin>>a;
    cout<<endl<<"b=";
    cin>>b;
    cout<<endl<<"c=";
    cin>>c;
    del = (b ^ 2) - 4*(a*c);//calcul pt delta
    sqrt(del, del_rad);//calcul pt radical din delta
    //calculul radacinilor
    x[0]=(( -b ) + del_rad[0])/(2 * a);
    x[1]=(( -b ) - del_rad[0])/(2 * a);
    x[2]=(( -b ) + del_rad[1])/(2 * a);
    x[3]=(( -b ) - del_rad[1])/(2 * a);
    delete [] del_rad;
}

int main()
{
   int opt,n;//optiunea de rulare a programului si nr de elem al vectorului de nr complexe
   Complex* x;//vectorul de radacini
   x=new Complex [4];
   /*cout<<"Alegeti optiunea dorita:"<<endl<<"1-rezolvarea ecuatiei de grad 2";
   cout<<endl<<"2-citirea si afisarea a n elemente"<<endl;*/
   do{
        cout<<"Alegeti optiunea dorita:"<<endl<<"1-rezolvarea ecuatiei de grad 2";
        cout<<endl<<"2-citirea si afisarea a n elemente"<<endl<<"3-iesire program"<<endl;
        cin>>opt;
        switch (opt)
        {
            case 1://optiunea pt rezolvarea ecuatiei de gradul 2
                cout<<"a*x^2 + b*x + c"<<endl;
                ec(x);
                cout<<"x1="<<x[0]<<endl;
                cout<<"x2="<<x[1]<<endl;
                cout<<"x3="<<x[2]<<endl;
                cout<<"x4="<<x[3]<<endl;
                cout<<endl;
                break;
            case 2://optiunea pt citirea si afisarea a n nr complexe
                cout<<"n=";
                cin>>n;
                vect v(n);
                v.cit_n(n,v.get_obj());
                cout<<endl;
                break;
        }
   }while (opt != 3);//while pt efectuarea mai multor operatii fara a inchide programul
    delete [] x;
    return 0;
}
