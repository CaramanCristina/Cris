#include <iostream>
#include <cstring>

using namespace std;

class Film
{
public:
    char * nume_film;
    char * tip;
    int durata;

    Film (char * n,char *t,int d):durata(d)
    {
        nume_film=new char(strlen(n)+1);
        tip=new char(strlen(t)+1);
        strcpy(this ->nume_film,n);
        strcpy(this ->tip,t);
    }
    ~Film()
    {
        delete this->nume_film;
        delete this ->tip;

    }
    double operator +(Film &f)
    {
        return this->durata+f.durata;
    }

   friend istream &operator>>(istream &intrare,Film& f)
    {
        cout<<"Numele filmului este:";
        intrare >>f.nume_film;
        cout<<"Genul filmului este :";
        intrare>>f.tip;
        cout<<"Durata filmului este ;";
        intrare >>f.durata;
        return intrare;


    }
  /* friend ofstream &operator<<(ofstream &iesire,Film f)
   {
    iesire<<f.nume_film<<f.tip<<f.durata;
    return iesire;
   }*/

};
class Angajati:public Film
{
char *cnp;

char *nume;

void persoane(char*a,char*b,char*n)
{
    cnp=new char(strlen(a)+1);
    nume=new char(strlen(b)+1);
    strcpy(cnp,a);
    strcpy(nume,b);
    strcpy(nume_film,n);
}




~Angajati()
    {
        delete this->nume_film;
        delete this ->nume;
         delete this ->cnp;;


    }



};
template<class FirmaDistributie,unsigned nr_pers=30000,unsigned nr_act=10000,char*pers=new char[3000] >class Incasari:public Film,public Angajati
{int suma;
int bunus;
Angajati v[3000];
const Incasari&operator=(const Angajati &a)
{
a.nume=suma;
}


};

/*template<class FirmaDistributie,unsigned nr_pers=30000,unsigned nr_act=10000,char*pers=new char[3000] >*/
int main()
{ Film f1(" Harry Potter","family",190) ;
 Film f2("Fast and Furios ","aventure",200);




    return 0;
}
