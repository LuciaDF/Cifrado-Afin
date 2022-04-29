#include "Inverso.h"

int a1,b1,x,y,mcd;

int Euclides (int a, int b)
{
    int r;
    if (b==0)
    {
        return a;
    }
    else
    {
        r=a%b;
        return Euclides(b, r);
    }
}

// Plantilla

//template <class TIPP> // Plantillas de Funcion

int Verificar(float a, int n) // Verifica que a ∈ Z y ∈ € Z+.
{
    int g;
    g=a-((int)a*(a/(int)a));
   if (g==0 and n>0)
   {
       return 1;
   }
   else
   {
       return 0;
   }
}

void EuclidesExt(int a, int b, int*mcd, int* x, int* y)
{
    int x1,y1;
        if (b==0)
        {
            *mcd=a;
            *x=1;
            *y=0;
        }
        else
        {
            EuclidesExt(b, a%b, mcd, x, y);
            // Paso recursivo
            x1=*x;
            y1=*y;
            *x=y1;
            *y=x1-(a/b)*y1;
        }
        
        
}

int  EuclidesEX(int a, int b, int*mcd, int* x, int* y) // Retorna x'
{
    int x1,y1;
     if (b==0)
        {
            *mcd=a;
            *x=1;
            *y=0;
        }
        else
        {
            EuclidesExt(b, a%b, mcd, x, y);
            // Paso recursivo
            x1=*x;
            y1=*y;
            *x=y1;
            *y=x1-(a/b)*y1;
        }
        a1=a;
        b1=b;
    
    return *x;
    
}

int ModJusto(int a,int n)
{
    if (a>=0 and a<=n)
    {
        return a;
    }
    else if (a>n)
    {
        return ModJusto(a-n,n);
    }
    else
    {
        return ModJusto(a+n, n);
    }
}

int VerMod(int a,int n)
{
    if (a>=0 and a<=n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void NumInverso(int a, int n)
{
    int nm;
    if (Verificar(a, n)==1)
    {
        if(Euclides(a, n)==1)
        {
            nm=EuclidesEX(a, n, &mcd, &x, &y);
            if(VerMod(nm, n)==1)
            {
                cout<<"El inverso de "<<a<<" y "<<n<<" mod ("<<n<<"): "<<nm<<endl;
            }
            else
            {
                nm=ModJusto(nm, n);
                cout<<"El inverso de "<<a<<" y "<<n<<" mod ("<<n<<"): "<<nm<<endl;
            }
        }
        else
        {
            cout<<a<<" no tiene inversa mod ("<<n<<"). "<<endl;
            // retorne al menu
        }
 
    }
    else
    {
        cout<<"a debe ser entero y n debe ser entero positivo porfavor."<<endl;
        // retorne al menu
        
    }
    
}

int NumInverso2(int a)
{
    int n=27;
    int mcd=Euclides(a, n),x,y,a1;
    
    //cout<<"mcd ( "<<a<<" , "<<n<<"): "<<mcd<<endl;
    a1=EuclidesEX(a, n, &mcd, &x, &y);
    
    //cout<<"Inverso de "<<a<<": "<<a1<<endl;
    a1=ModJusto(a1,n);
    
    //cout<<"Inverso de "<<a<<"(mod 27): "<<a1<<endl;
    return a1;
    
}
void p_datos(Inverso *i6)
{
    cout<<"---INVERSO DE UN NUMERO - VERIFICACIÓN---"<<endl;
    
    cout<<"Digite a: ";cin>>i6->a;
    fflush(stdin);
    cout<<"Digite n: ";cin>>i6->n;
    fflush(stdin);
    
    NumInverso(i6->a, i6->n);
}
