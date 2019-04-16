#include <iostream>
#include <cmath>
using namespace std;
class monom
{
public :
    int g;//grad
    float c;//coef



    friend istream& operator>>(istream&intrare,monom&m)
    {
        int c,g;
        cout<<"Coeficientul monumului este"<<" ";
        intrare>>m.c;
        cout<<"Gradul monumului este"<<" ";

        intrare>>m.g;



        return intrare;
    }
    friend ostream& operator<<(ostream&iesire,monom m)
    {
        int c,g;
        iesire<<"Monomul este de forma :";


        iesire<<m.c<<"x^"<<m.g;

        return iesire;
    }
    void operator=(const monom &m)
    {
        c=m.c;
        g=m.g;
    }
public :
    monom(int grad,float coef)
    {
        g=grad;
        c=coef;
    }

    monom( const monom&m)
    {
        this->c=m.c;
        this->g=m.g;
    }
public :
    ~monom()
    {

        c=0;
        g=0;
        cout<<" se apeleaza distructorul monomului"<<endl;

    }


};

class polinom
{
    friend class monom;
public:

    float v[100];
    int w[100],n,m;

    virtual void afisare()
    {
        int i;
        cout<<"Numarul de monomi din polinom este: "<<n<<endl;

        for(i=1; i<n; i++)
        {
            cout<<v[i]<<"x^"<<w[i]<<"+";
        }
        if(i==n)
            cout<<v[i]<<"x^"<<w[i]<<endl;



    }


    polinom(int nr,monom m)
    {
        int p=m.g;
        int i,j,d=0;
        int k=1;
        for(i=1; i<=nr; i++)
        {
            v[i]=0;
            w[i]=0;
        }
        n=nr;
        i=0;

        while(k<=nr)
        {
            cin>>m;

            while(d==0)
            {

                {

                    v[i+k]=m.c;
                    w[i+k]=m.g;
                    d++;
                }
            }




            k++;

            d=0;
        }


    }
public:
    ~polinom()
    {
        int i;
        for(i=1; i<=n; i++)
        {
            v[i]=0;
            w[i]=0;
        }

        cout<<" se apeleaza distructorul polinomului"<<endl;

    }






};
class polinom_ireductibil:public polinom
{
public:

    float v[100];
    int w[100],n,m;
    polinom_ireductibil(int nr,monom m):polinom(nr,m) {};
    void afisare(polinom s)
    {
        s.afisare();
    }


    void verificare(polinom s)
    {
        int i;
        int cmmdc =s.v[1];

        for (i = 2; i <= s.n; i++)
        {

            int aux = s.v[i];
            while (aux!= cmmdc)
            {

                if (aux> cmmdc)
                    aux = aux - cmmdc;
                else if (aux < cmmdc)
                    cmmdc = cmmdc - aux;
            }

        }


        float auc[100],p,x=0,max1,min1;
        if(cmmdc==1)
        {
            int ok;
            double d;
            ok=1;
            d=2;
            for (i = 1; i <= s.n; i++)
            {
                while (d<=s.v[i]/2)
                {
                    if (fmod(s.v[i],d)==0)
                        ok=0;

                    d=d+1;
                }
                x=s.v[i];
                if(x!=0)
                    i=s.n;
            }

            if (ok==1)
            {
                p=x;
                for (i = 1; i <= s.n; i++)
                    auc[i]=s.v[i];

                max1=s.v[1];
                min1=s.v[1];
                for (i=2; i<=s.n; i++)
                {
                    if(s.v[i]>max1)

                        max1=s.v[i];
                    if(s.v[i]<min1)
                        min1=s.v[i];

                }



                int num=0;
                for (i = 1; i <= s.n; i++)
                {
                    if(fmod(auc[i],p)==0&&auc[i])
                        num++;
                }


                if(p/auc[s.n]!=0&&p*p/auc[1]!=0)
                    num++;
                if(num==s.n )
                    cout<<"polinomul este ireductibil"<<endl;
                else
                    cout<<"polinomul este reductibil"<<endl;



            }
            else
                cout<<"polinomul este reductibil"<<endl;

        }
    }
/*public:
    ~polinom_ireductibil()
    {
        int i;
        for(i=1; i<=n; i++)
        {
            v[i]=0;
            w[i]=0;

        }

        cout<<" se apeleaza distructorul "<<endl;

    }*/

};




int main()
{
    int i;
    int x,j,n,g;
    float y;
    cout<<"Gradul monomului este :";
    cin>>x;
    cout<<"Coeficientul monomului este :";
    cin>>y;
    monom m(x,y);
    cout<<m<<endl;
    monom m1=m;
    cout<<m1<<endl;


    polinom p(3,m);
    p.afisare();
    cout<<endl;
    polinom_ireductibil s(4,m);
    s.afisare(s);
    s.verificare(s);




    return 0;
}
