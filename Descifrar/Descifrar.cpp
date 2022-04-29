#include "Descifrar.h"

char A[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int b[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};

int as[18]={1,2,4,5,7,8,10,11,13,14,16,17,19,20,22,23,25,26};

const int n=27;

int a1,b1;

void p_datos()
{
    string f_cifrada;
    cout<<"----CIFRAR FRASE----"<<endl;
    
    cout<<"Dijite frase: ";getline(cin,f_cifrada);
    
    int s=f_cifrada.length();
    
    int tamr=0;
    for(int i=0;i<s;i++)
    {
        if(f_cifrada[i]==126)
        {
            tamr++;
            i++;
        }
    }
    char f_c[s-tamr];
    
    int n_c[s-tamr];
    
    int tamo=s-tamr;
    
    cout<<tamo<<endl;
    strcpy(f_c,f_cifrada.c_str());
    
    ConvertirNum(f_c,n_c);
    
    
    
    /*
    for(char *p=f_cifrada;p<f_cifrada+11;p++)
    {
        //cout<<*p<<endl;
        
    }
    
    for(int *p=n_cifrada;p<n_cifrada+8;p++)
    {
        //cout<<*p<<endl;
        
    }
    */
    
    char Tam_peq[27][18][56]; // probemos solo con A y B
    
    Llenar3D(Tam_peq, n_c, as, b);
    
    Imprimir3D(Tam_peq);
    
}
int BusquedaNum(char x)
{
    int i=0;
    
    if ((int)x==126)
    {
        return 14;
    }
    for (char *p=A;*p;p++)
    {
        if (*p=='O')
        {
            i++;
        }
        if (*p==x)
        {
            return i;
        }
        else
        {
            i++;
        }
        
    }
        
    return 0;
    
}

void ConvertirNum(char a[56], int a2[56])
{
    int *i=a2;
    for(char *p=a;*p;p++)
    {
        if(*p==126)
        {
            *i=14;
            //cout<<"a2["<<i<<"]: "<<a2[i]<<endl;
            //cout<<*p<<": "<<*i<<endl;
            i++;
            p++;
        }
        else
        {
            *i=BusquedaNum(*p);
        
            //cout<<"a2["<<i<<"]: "<<a2[i]<<endl;
            //cout<<*p<<": "<<*i<<endl;
            i++;
        }
        
    }
}

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

int VerInverso(int a, int n)
{
    if(Euclides(a, n)==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void PosiblesA(int a3[], int s)
{
    int a=0;
    for(int *p=a3;a<=26;)
    {
        if(VerInverso(a, n)==1)
        {
            *p=a;
            //cout<<*p<<" ";
            a++;
            p++;
        }
        else
        {
            a++;
        }
    }
    cout<<endl;
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
        a1=a;
        b1=b;
        
}
int  EuclidesEX(int a, int b, int*mcd, int* x, int* y)
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

int ModJusto(int a1)
{
    int a2;
    if(a1<0)
    {
        a2=a1+n;
        return ModJusto(a2);
    }
    else if(a1>26)
    {
        a2=a1-n;
        return ModJusto(a2);
    }
    else
    {
        return a1;
    }
}
int NumInverso(int a)
{
    int mcd=Euclides(a, n),x,y,a1;
    
    //cout<<"mcd ( "<<a<<" , "<<n<<"): "<<mcd<<endl;
    a1=EuclidesEX(a, n, &mcd, &x, &y);
    
    //cout<<"Inverso de "<<a<<": "<<a1<<endl;
    a1=ModJusto(a1);
    
    //cout<<"Inverso de "<<a<<"(mod 27): "<<a1<<endl;
    return a1;
    
}

char BusquedaLet(int x)
{
    for(int i=0;i<sizeof(A);i++)
    
        if(x==i)
        {
           if (i==14)
           {
               return '~';
           }
           else
           {
               if(i>=15)
               {
                   i--;
                   return A[i];
               }
               
               return A[i];
           }
        }
        
    
    
    
    return '\330';
    
}
char DescifrarNum(int a, int b, int y)
{
    int x,a1;
    
    char x1;
    
    a1=NumInverso(a);
    //cout<<"Inverso de "<<a<<": "<<a1<<endl;
    x=a1*(y-b);
    //cout<<a1<<" * "<<" ( "<<y<<" (-) "<<b<<" ): ";
    x=ModJusto(x);
    //cout<<"x: "<<x<<endl;
    
    x1=BusquedaLet(x);
    
    //cout<<"Letra de x: "<<x1<<endl;
    
    return BusquedaLet(x);
    
}



void Llenar3D(char m[27][18][56],int nc[], int a1[], int b[]) // Llenar3D(Tam_peq, n_cifrada, a1, b)
{
    int *p1=a1;// a1[18]
    int *q1=b; // b[27]
    int *r1=nc; // nc[11]
    
    //cout<<*p1<<endl;// 1
    //cout<<*q1<<endl;// 0
    //cout<<*r1<<endl; // 16
    
    for(char (*p)[18][56]=m;p<m+27;p++,q1++)
    {
        //cout<<"Matriz "<<*q1<<endl;
        for(char (*q)[56]=*p;q<*(p+1);)
        {
            for(char *r=*q;r<*(q+1);)
            {
                *r=DescifrarNum(*p1, *q1, *r1);
                //cout<<DescifrarNum(*p1, *q1, *r1)<<" ";
                //cout<<*r<<" ";
                r++;
                r1++;
                if(r==*(q+1))
                {
                    r1=nc;
                }
            }
            q++;
            p1++;
            if(q==*(p+1))
            {
                p1=a1;
            }
        }

        
    }
}

void Imprimir3D(char m[27][18][56])
{
    int i=0;
    for(char (*p)[18][56]=m;p<m+27;p++)
    {
        cout<<"Matriz "<<i<<endl;
        for(char (*q)[56]=*p;q<*(p+1);q++)
        {
            for(char *r=*q;r<*(q+1);r++)
            {
                cout<<*r;
            }
            cout<<endl;
            cout<<endl;
            
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        i++;
    }
}