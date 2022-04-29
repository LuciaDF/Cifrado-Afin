#include <iostream>
#include <string>


#include "Inverso.h"
using namespace std;

char abc[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int n=27;


struct Cifrar
{
    
    int a,b;
    long int tam;
    char *fac=NULL; // fc tambien
    int *nf=NULL; // nf para fc
    //struct Inverso i2; // estructura anidada
    char *fc=NULL;
    
    // Descifrar
    
   
};

void p_datos2(Cifrar *c1);//
void Mayuscula(char x[]);// bien
void TamañoArray(int tam, Cifrar *c2,string aux);// bien => Convertimos el string en array dinamico.
void CopiarChar(char *p, string fs,long int tam); // bien => Llenamos fac.
int BusquedaNum(char x);//bien
void CopiarInt(int *q, char *r,long tam);//bien => llenamos nf.
int EnelRango(Cifrar *c1, int x);// asegurarse que a,b,x estan en su rango.
int EnelRango2(char x);//bien => Por si la frase tiene una ñ.
int VerfInverso(int a);//bien => Verficar si tiene inverso
int ModJusto2(int y);//bien => Convertir el numero mod 27.
char BusquedaLet(int y);//bien => Busca la letra correspondiente del numero.
char Cifrarletra(Cifrar *c8, int x);//bien => si a y b estan deacuerdo a las restricciones cifrar la letra

void LLenarfCif(Cifrar *c4, long int tam);//bien => Definimos fc => frase cifrada

void CifrarFrase(Cifrar *c4, long int tam);//bien => Llenamos fc

int ReconoceEne(string aux); // bien => saber si tiene ñ o no.

int TamañoInit(Cifrar *c2, string aux); 

void menu(Inverso i1, Cifrar c1);
  

int main()
{
  int option;
  

  while (option!=3)
    {
      cout<<"------MENU------"<<endl;
      cout<<"1.- Inverso de un numero." <<endl;
      cout<<"2.- Cifrar. "<<endl;
      cout<<"3.- Salir "<<endl;
      cout<<"Eliges? ";cin>>option;

      switch(option)
        {
          case 3:
            exit(1);
          case 1:
            struct Inverso i2;
            p_datos(&i2);
            break;
          case 2:
            struct Cifrar c2;
            p_datos2(&c2);
            break;

        }
      
          
    }

   // struct Cifrar c1;
   //   p_datos2(&c1);
    return 0;
}

  void p_datos2(Cifrar *c1)
{
    int a;
    string aux;
    cout << endl;
    cout<<"--------CIFRAR--------"<<endl;
    fflush(stdin);
    cout<<"Digita frase: ";
    getline(cin,aux);//no lo lee
    getline(cin,aux);
     fflush(stdin);
    c1->tam=aux.length();// esta bien amenos que tenga una Ñ.
    

    TamañoArray(c1->tam, c1,aux); // Definir los punteros fac y nf.
    
    
    CopiarChar(c1->fac, aux, c1->tam-TamañoInit(c1, aux));

    // Convertimos el string en array dinamico.

    Mayuscula(c1->fac); // Lo convertimos a mayuscula.
    
   
    CopiarInt(c1->nf,c1->fac,c1->tam-TamañoInit(c1, aux)); //

    //2
    
    cout<<"Llave {a,b}: "<<endl;
    cout<<"Digite a: ";cin>>c1->a;
    cout<<"Digite b: ";cin>>c1->b;
    
    cout<<endl;
    
    LLenarfCif(c1,c1->tam-TamañoInit(c1, aux)); // Incializando frase cifrada.
    
    CifrarFrase(c1, c1->tam-TamañoInit(c1, aux));
   
    cout << endl;
    
}
int ReconoceEne(string aux)
{
    int t=aux.length();
    int i=0;
    for(long int j=0;j<t;j++)
    {
        if(EnelRango2(aux[j])==0)
        {
            i=1;
        }
    }
    return i;
}

int TamañoInit(Cifrar *c2, string aux)
{
    if(ReconoceEne(aux)==1)
    {
        
        return 1;
    }
    else
    {
        return 0;
    }
}
void Mayuscula(char x[]) // Si el usuario lo escriba en conbinacion de mayus y minus la funcion ayuda con ese problema.
{
    for(char *p=x;*p;p++)
    {
        if(*p>=97 and *p<=122)
        {
            *p-=32;
        }
        //cout<<*p<<" ";
    }
    //cout<<endl;
}
void TamañoArray(int tam, Cifrar *c2,string aux)
{
    if(ReconoceEne(aux)==1)
    {
        c2->fac=new char[tam-1];
        c2->nf=new int[tam-1];
      
    }
    else
    {
        c2->fac=new char[tam];
        c2->nf=new int[tam];
       
    }
    
    if(!c2->fac or !c2->nf)
    {
        cout<<"Reserva de memoria fallida"<<endl;
    }
    
}


void CopiarChar(char *p, string fs,long int tam)
{
    int i=0;
    char *q=p;
    
    for(;q<=p+tam,i<=tam;q++,i++)
    {
        
        *q=fs[i];
        if(*q==126)
        {
            i++;
        }
    }
    
    cout<<endl;
    if (i==0)
    {
        cout<<"Trate de nuevo. "<<endl;
        exit(1);
    }
    
}

int BusquedaNum(char x)
{
    int i=0;
    char *q=abc;
    *(q+28)='\0';
    
    if (x=='~')
    {
        return 14;
    }
    else
    {
        for (char *p=abc;*p;p++)
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
    }
    
    return 28;
    
}

void CopiarInt(int *q, char *r,long tam)
{
    char *s=r;
    for(int *p=q;s<r+tam,p<q+tam;p++,s++)
    {
        *p=BusquedaNum(*s);
    }
        
        
}
int EnelRango(Cifrar *c1, int x)
{
    if(c1->a,c1->b,x >=0 and c1->a,c1->b,x <=26)
    {
        return 1;
    }
    else
    {       
        return 0;
    }

}
int EnelRango2(char x)
{
    if(x >=65 and x <=90)
    {
        return 1;
    }
    else if(x>=97 and x<=122)
    {
        return 1;
    }
    else
    {
        
        return 0;
    }
}
int VerfInverso(int a)
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
int ModJusto2(int y)
{
    int y1;
    if (y>=0 and y<=26)
    {
        return y;
    }
    else
    {
        y1=y-n;
        return ModJusto2(y1);
    }
}
char BusquedaLet(int y)
{
    char *q=abc;
    *(q+28)='\0';
    for(int i=0;i<n;i++)
    {
        if(y==i)
        {
           if (i==14)
           {
               return (char)165;
           }
           else
           {
               if(i>=15)
               {
                   i--;
                   return abc[i];
               }
               return abc[i];
           }
        }
        
    
    }
    
    return '0';
}

char Cifrarletra(Cifrar *c8, int x)
{
    int y;
    if(EnelRango(c8, x)==1)
    {
        if(VerfInverso(c8->a)==1)
        {
            y=(c8->a*x)+c8->b;
            //cout<<c8->a<<" * "<<x<<" + "<<c8->b<<endl;
            y=ModJusto2(y);
            //cout<<y<<endl;
            return BusquedaLet(y);
            
        }
        else
        {
            cout<<c8->a<<" no tiene inversa."<<endl;
            exit(1);
        }
    }
    else
    {
        cout<<c8->a<<" y "<<c8->b<<"no estan el rango mod("<<n<<")."<<endl;
        exit(1);
    }
    
}

void LLenarfCif(Cifrar *c4, long int tam)
{
    
    c4->fc=new char[tam];
    
}
void CifrarFrase(Cifrar *c4, long int tam)
{
    int *q=c4->nf;// numeros de la frase
    
    cout<<"FRASE CIFRADA"<<endl;
    //cout<<tam<<endl;
    for(char *p=c4->fc;p<c4->fc+tam,q<c4->nf+tam;p++,q++)
    {
        *p=Cifrarletra(c4, *q);
        //cout<<*p<<" - "<<*q<<endl;
        cout<<*p;
        
        
    }
    cout<<endl;
    
}
