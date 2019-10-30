class vect//clasa pentru citirea si afisarea a n numere complexe
{
    int n;//numarul de numere complexe
    Complex *obj;//vectorul de numere complexe

public:

    vect ();//constructor de declarare
    vect (int);//constructor de initializare
    vect (const vect &);//constructor de copierre
    ~vect ();//destructor
    void cit_n(int n, Complex *obj);//metoda de citire si scriere a n numere complexe
    Complex* get_obj();//furnizarea unui numar complex
};
