/*
	Arquivo: calculoN_prova2_Seidel.cpp
	Aluno: Luan Gabriel Mantuani
	Materia: Calculo Numerico
	Professor: Fernando Brito

	--> TEMA, fazer a implementacao dos algoritmos de:
		resolução de sistemas atraves dos métodos Gauss-Siedel e Gauss-Jacob
*/
#include <stdio.h>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

//  Estruturas
struct vetor{
	float x;
	float y;
	float z;
	float r;
};

//  Variaveis Globais
vetor a, b, c;
float x, y, z, x2, y2, z2, precisao;

// Funcoes
void seidel();
void jacob();
void todasOperacoes();
void inserirValor();
void vetores();
void valoresProva();
bool erroRelativo();

int main(){
    char menuOpcao;
    setlocale(LC_ALL, "Portuguese");
    valoresProva();

    do{

        system("cls");
        cout << "\tOPERAÇÕES - Metodo de Seidel e Jacob     //"<<endl;
        cout << "\t1 - Seidel                               //"<<endl;
        cout << "\t2 - Jacob                                //"<<endl;
        cout << "\t3 - Todas as operacoes                   //"<<endl;
        cout << "\t-------------------------------------------"<<endl;
        cout << "\tQ - Inserir valores                      //"<<endl;
        cout << "\tW - Inserir valores da Prova II - ex2    //"<<endl;
        cout << "\tE - Sair do programa                     //"<<endl;
        vetores();
        cout << "\tOpção: ";
        cin >> menuOpcao;

        switch (tolower(menuOpcao)){

        case '1':
            system("cls");
            seidel();
            break;

        case '2':
            system("cls");
            jacob();
            break;

        case '3':
            system("cls");
            todasOperacoes();
            break;

        case 'q':
            inserirValor();
            break;

        case 'w':
            valoresProva();
            break;

        case 'e':
            return 0;
            break;

        default:
            cout << "\n\tOpção inválida\n\n";
        }

        system("pause");
    } while (menuOpcao != 'e');
}

//Funções
void seidel(){
    cout<<"\n\tMETODO GAUSS SIEDEL"<<endl;
    cout<<"\n\tInforme a precisão E: ";
    cin>>precisao;

    int k=0, k2=k+1;
    x2 = 0;  y2 = 0;  z2 = 0;
    x = (a.r - (a.y * y2) - (a.z * z2))/a.x;
    y = (b.r - (b.z * z2) - (b.x * x))/b.y;
    z = (c.r - (c.x * x) - (c.y * y))/c.z;
    cout<<"\tk = "<<k<<"\tx"<<k2<<" = "<<x<<"\ty"<<k2<<" ="<<y<<"\tz"<<k2<<" = "<<z<<endl;

    for(k=1, k2=k+1; erroRelativo(); k++, k2++){
        x2 = x;
        y2 = y;
        z2 = z;

        x = (a.r - (a.y * y2) - (a.z * z2))/a.x;
        y = (b.r - (b.z * z2) - (b.x * x))/b.y;
        z = (c.r - (c.x * x) - (c.y * y))/c.z;

        cout<<"\tk = "<<k<<"\tx"<<k2<<" = "<<x<<"\ty"<<k2<<" ="<<y<<"\tz"<<k2<<" = "<<z<<endl;
    }

    cout<<"\tk = "<<k<<"\t( "<<x<<" , "<<y<<" , "<<z<<" ) = ( "<<round(x)<<" , "<<round(y)<<" , "<<round(z)<<" )"<<endl;
    valoresProva();
}

void jacob(){
    cout<<"\n\tMETODO GAUSS JACOB"<<endl;
    cout<<"\n\tInforme a precisão E: ";
    cin>>precisao;

    int k=0, k2=k+1;
    x2 = 0;  y2 = 0;  z2 = 0;
    x = (a.r - (a.y * y2) - (a.z * z2))/a.x;
    y = (b.r - (b.z * z2) - (b.x * x2))/b.y;
    z = (c.r - (c.x * x2) - (c.y * y2))/c.z;
    cout<<"\tk = "<<k<<"\tx"<<k2<<" = "<<x<<"\ty"<<k2<<" ="<<y<<"\tz"<<k2<<" = "<<z<<endl;

    for(k=1, k2=k+1; erroRelativo(); k++, k2++){
        x2 = x;
        y2 = y;
        z2 = z;

        x = (a.r - (a.y * y2) - (a.z * z2))/a.x;
        y = (b.r - (b.z * z2) - (b.x * x2))/b.y;
        z = (c.r - (c.x * x2) - (c.y * y2))/c.z;

        cout<<"\tk = "<<k<<"\tx"<<k2<<" = "<<x<<"\ty"<<k2<<" ="<<y<<"\tz"<<k2<<" = "<<z<<endl;
    }

    cout<<"\tk = "<<k<<"\t( "<<x<<" , "<<y<<" , "<<z<<" ) = ( "<<round(x)<<" , "<<round(y)<<" , "<<round(z)<<" )"<<endl;
    valoresProva();
}

void todasOperacoes(){
    vetores();
    seidel();
    jacob();
}


void inserirValor(){
    system("cls");
    vetor k;
    float r[3];

    cout<<"\nInforme os denominadores e resultado dos vetores:"<<endl;
    for(int i=0; i<3; i++){
        cout<<"\n\tLinha - "<<i<<endl;
        cout<<"\tx =  ";
        cin>> k.x;
        cout<<"\ty =  ";
        cin>> k.y;
        cout<<"\tz =  ";
        cin>> k.z;
        cout<<"\tresultado =  ";
        cin>> k.r;

        if(i==0){a = k;}
        else if(i==1){b = k;}
        else {c = k;}
    }
    vetores();
}

void vetores(){
    cout<<endl;
    cout<<"\t("<<a.x<<"x\t"<<a.y<<"y\t"<<a.z<<"z\t= "<<a.r<<endl;
    cout<<"\t<"<<b.x<<"x\t"<<b.y<<"y\t"<<b.z<<"z\t= "<<b.r<<endl;
    cout<<"\t("<<c.x<<"x\t"<<c.y<<"y\t"<<c.z<<"z\t= "<<c.r<<endl;
    cout<<endl;
}

void valoresProva(){
    a.x = 5;    a.y = 1;    a.z = 1;    a.r = 5;
    b.x = 3;    b.y = 4;    b.z = 1;    b.r = 6;
    c.x = 1;    c.y = 1;    c.z = 2;    c.r = 0;
}

bool erroRelativo(){
    float ex, ey, ez;

    ex = fabs((x2-x)/x);
    ey = fabs((y2-y)/y);
    ez = fabs((z2-z)/z);

    if(ex <= precisao && ey <= precisao && ez <= precisao){
        return false;
    }else {return true;}
}

