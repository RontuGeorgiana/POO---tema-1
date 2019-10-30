class Complex
{   //partea reala si imaginara a numarului complex:
	double real;
	double imag;

	public:

	Complex();//constructor de initializare
	Complex(const Complex&);//constructor de copiere
	~Complex();//deconstructor
	void setare (const double a, const double b);//metoda de setare a partii reale si imaginare
	double get_r ();//metoda de furnizare a partii reale
	double get_im ();//metoda de furnizare a partii imaginare
    void citire (Complex &a);//metoda pentru citire
    void afisare ();//metoda pentru afisare
    friend std::istream & operator >> (std::istream &, Complex & );//operator de citire
    friend std::ostream & operator << (std::ostream &, Complex & );//operator de afisare
	//operatori de adunare:
	friend Complex operator + (Complex a, Complex b);
	friend Complex operator + (double a, Complex b);
	friend Complex operator + (Complex a, double b);
	friend Complex operator + (Complex a);
	//operatori de scadere:
	friend Complex operator - (Complex a, Complex b);
	friend Complex operator - (double a, Complex b);
	friend Complex operator - (Complex a, double b);
	friend Complex operator - (Complex a);//opusul numarului
	//operatori de inmultire:
	friend Complex operator * (Complex a, Complex b);
	friend Complex operator * (double a, Complex b);
	friend Complex operator * (Complex a, double b);
	//operatori de impartire:
	friend Complex operator / (Complex a, Complex b);
	friend Complex operator / (double a, Complex b);
	friend Complex operator / (Complex a, double b);
	//teste de egalitate:
	friend int operator == (Complex a, Complex b);
	friend int operator == (double a, Complex b);
	friend int operator == (Complex a, double b);
	//teste de inegalitate
	friend int operator != (Complex a, Complex b);
	friend int operator != (double a, Complex b);
	friend int operator != (Complex a, double b);
	//operatori de atribuire compusi pt adunare
	friend Complex operator += (Complex a, Complex b);
	friend Complex operator += (Complex a, double b);
	//operatori de atribuire compusi pt scadere
	friend Complex operator -= (Complex a, Complex b);
	friend Complex operator -= (Complex a, double b);
	//operatori de atribuire compusi pt inmultire
	friend Complex operator *= (Complex a, Complex b);
	friend Complex operator *= (Complex a, double b);
	//operatori de atribuire compusi pt impartire
	friend Complex operator /= (Complex a, Complex b);
	friend Complex operator /= (Complex a, double b);
	friend Complex operator ^ (Complex a, unsigned int b);//operator de ridicare la putere naturala
	friend double abs (Complex a);//operatorul pentru modul
	friend void sqrt (Complex a, Complex * rez);//operatorul pentru radical
	friend class vect;//functie prieten folosita pentru retinerea a n nr complexe
};

