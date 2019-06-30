/*
	Arquivo: mat2_prova1_Vetores.cpp
	Aluno: Luan Gabriel Mantuani
	Materia: Matematica_II
	Professor: Fernando Brito

	--> TEMA, fazer a implementacao dos algoritmos de:
		Soma, subtracao , modulo, produto escalar, angulo, produto vetorial, produto misto(duas formas)
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
#define PI 3.14159265359

using namespace std;

//  Estruturas
struct vetor{
	float x;
	float y;
	float z;
};

//  Variaveis Globais
vetor a, b, c, aux1, aux2, aux3;
char menuOpcao, vetAux1, vetAux2, vetAux3;


//ARQUIVO SEQUENCIAL - Funcoes
void soma();
void subtracao();
float modulo(bool, vetor);
float produtoEscalar(bool);
void angulo();
vetor produtoVetorial(bool);
float produtoMisto(bool);
void todasOperacoes();
void escolherVetor();
void inserirValor();
void vetores();
void vetoresEscolhidos();
void valoresProva();

int main(){
    setlocale(LC_ALL, "Portuguese");
    valoresProva();

    do{

        system("cls");
        cout << "\tOPERAÇÕES                        //"<<endl;
        cout << "\t1 - Soma                         //"<<endl;
        cout << "\t2 - Subtração                    //"<<endl;
        cout << "\t3 - Módulo                       //"<<endl;
        cout << "\t4 - Produto Escalar              //"<<endl;
        cout << "\t5 - Ângulo                       //"<<endl;
        cout << "\t6 - Produto Vetorial             //"<<endl;
        cout << "\t7 - Produto Misto                //"<<endl;
        cout << "\t8 - Todas as Operações           //"<<endl;
        cout << "\t-----------------------------------"<<endl;
        cout << "\tQ - Escolher vetores             //"<<endl;
        cout << "\tW - Inserir valores              //"<<endl;
        cout << "\tE - Sair do programa             //"<<endl;
        vetoresEscolhidos();
        cout << "\tOpção: ";
        cin >> menuOpcao;

        switch (tolower(menuOpcao)){

        case '1':
            soma();
            break;

        case '2':
            subtracao();
            break;

        case '3':
            modulo(true, a);
            break;

        case '4':
            produtoEscalar(true);
            break;

        case '5':
            angulo();
            break;

        case '6':
            produtoVetorial(true);
            break;

        case '7':
            produtoMisto(true);
            break;

        case '8':
            todasOperacoes();
            break;

        case 'q':
            escolherVetor();
            break;

        case 'w':
            inserirValor();
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
void soma(){
    vetor soma;
    soma.x = aux1.x + aux2.x;
    soma.y = aux1.y + aux2.y;
    soma.z = aux1.z + aux2.z;

    cout<<"\n\tSoma: "<<endl;
    cout<<"\t"<<vetAux1<<" + "<<vetAux2<<" = ( "<<soma.x<<" , "<<soma.y<<" , "<<soma.z<<" )"<<endl;
    cout<<endl;
}

void subtracao(){
    vetor sub;
    sub.x = aux1.x - aux2.x;
    sub.y = aux1.y - aux2.y;
    sub.z = aux1.z - aux2.z;

    cout<<"\n\tSubtração: "<<endl;
    cout<<"\t"<<vetAux1<<" - "<<vetAux2<<" = ( "<<sub.x<<" , "<<sub.y<<" , "<<sub.z<<" )"<<endl;
    cout<<endl;
}

float modulo(bool exibir, vetor vet){
    float modA, modB, modC, mod;
    modA = sqrt(pow(a.x, 2)+pow(a.y, 2)+pow(a.z, 2));
    modB = sqrt(pow(b.x, 2)+pow(b.y, 2)+pow(b.z, 2));
    modC = sqrt(pow(c.x, 2)+pow(c.y, 2)+pow(c.z, 2));

    if(exibir){
        cout<<"\n\tMódulos:"<<endl;
        cout<<"\t|A|( "<<a.x<<" , "<<a.y<<" , "<<a.z<<" ) = "<<modA<<endl;
        cout<<"\t|B|( "<<b.x<<" , "<<b.y<<" , "<<b.z<<" ) = "<<modB<<endl;
        cout<<"\t|C|( "<<c.x<<" , "<<c.y<<" , "<<c.z<<" ) = "<<modC<<endl;
        cout<<endl;
    }else{return mod = sqrt(pow(vet.x, 2)+pow(vet.y, 2)+pow(vet.z, 2));}
}

float produtoEscalar(bool exibir){
    float produto;
    produto = (aux1.x * aux2.x)+(aux1.y * aux2.y)+(aux1.z * aux2.z);

    if(exibir){
        cout<<"\n\tProduto Escalar: "<<endl;
        cout<<"\t"<<vetAux1<<" * "<<vetAux2<<" = "<<produto<<endl;
        cout<<endl;
    }else{return produto;}
}

void angulo(){
    float alfa;
    alfa = produtoEscalar(false)/(modulo(false, aux1) * modulo(false, aux2));
    alfa = acos(alfa)*180/PI;

    cout<<"\n\tÂngulo: "<<endl;
    cout<<"\t"<<vetAux1<<" ^ "<<vetAux2<<" = "<<alfa<<endl;
    if(produtoEscalar(false)==0){
        cout<<"\t*Os vetores "<<vetAux1<<" e "<<vetAux2<<" são ortogonais"<<endl;
    }
    cout<<endl;
}

vetor produtoVetorial(bool exibir){
    vetor produto;
    produto.x = (aux1.y * aux2.z) - (aux1.z * aux2.y);
    produto.y = (aux1.z * aux2.x) - (aux1.x * aux2.z);
    produto.z = (aux1.x * aux2.y) - (aux1.y * aux2.x);

    if(exibir){
        cout<<"\n\tProduto Vetorial: "<<endl;
        cout<<"\t\t| i\tj\tk |"<<endl;
        cout<<"\t"<<vetAux1<<" X "<<vetAux2<<" ="
        <<"\t| "<<aux1.x<<"\t"<<aux1.y<<"\t"<<aux1.z<<" | ="
        <<" ( "<<produto.x<<", "<<produto.y<<", "<<produto.z<<" )"<<endl;
        cout<<"\t\t| "<<aux2.x<<"\t"<<aux2.y<<"\t"<<aux2.z<<" |"<<endl;
        cout<<endl;
    }else{return produto;}
}

float produtoMisto(bool exibir){
    //Definição dos produtos
    vetor vetorial = produtoVetorial(false);
    float produto = (vetorial.x * aux3.x)  + (vetorial.y * aux3.y) + (vetorial.z * aux3.z);

    //Determinante
    float determinante = (aux1.x*aux2.y*aux3.z)+(aux1.y*aux2.z*aux3.x)+(aux1.z*aux2.x*aux3.y)-(aux1.z*aux2.y*aux3.x)-(aux1.y*aux2.x*aux3.z)-(aux1.x*aux2.z*aux3.y);

    if(exibir){
        cout<<"\n\tProduto Misto, pela definição de produtos: "<<endl;
        cout<<"\t\t\t| i\tj\tk |"<<endl;
        cout<<"\t( "<<vetAux1<<" X "<<vetAux2<<" ) * "<<vetAux3<<" ="
            <<"\t| "<<aux1.x<<"\t"<<aux1.y<<"\t"<<aux1.z<<" | * "<<vetAux3<<" ="
            <<" ( "<<vetorial.x<<", "<<vetorial.y<<", "<<vetorial.z<<" ) * ( "<<aux3.x<<", "<<aux3.y<<", "<<aux3.z<<" ) ="
            <<" "<<produto<<endl;
        cout<<"\t\t\t| "<<aux2.x<<"\t"<<aux2.y<<"\t"<<aux2.z<<" |"<<endl;

        cout<<"\n\n\tProduto Misto, pelo determinante: "<<endl;
        cout<<"\t\t\t| "<<aux1.x<<"\t"<<aux1.y<<"\t"<<aux1.z<<" |"<<endl;
        cout<<"\t[ "<<vetAux1<<", "<<vetAux2<<", "<<vetAux3<<" ] ="
            <<"\t| "<<aux2.x<<"\t"<<aux2.y<<"\t"<<aux2.z<<" | ="
            <<" "<<determinante<<endl;
        cout<<"\t\t\t| "<<aux3.x<<"\t"<<aux3.y<<"\t"<<aux3.z<<" |"<<endl;
        cout<<endl;
    }else{return determinante;}
}

void todasOperacoes(){
    system("cls");
    vetores();
    vetoresEscolhidos();
    soma();
    subtracao();
    modulo(true, a);
    produtoEscalar(true);
    angulo();
    produtoVetorial(true);
    produtoMisto(true);
}

void escolherVetor(){
    char opcao;

    system("cls");
    cout<<"\nEscolha dois vetores para efetuar as operações";
    vetores();
    cout<<"\tOpções: "<<endl;
    cout<<"\tA - Vetor A"<<endl;
    cout<<"\tB - Vetor B"<<endl;
    cout<<"\tC - Vetor C"<<endl;

    for(int i=1; i<4; i++){
        do{
            cout<<"\n\tVetor "<<i<<": ";
            cin>> opcao;

            switch(tolower(opcao)){
                case 'a':
                    if(i==1){aux1 = a;}
                    else if(i==2){aux2 = a;}
                    else {aux3 = a;}
                    break;

                case 'b':
                    if(i==1){aux1 = b;}
                    else if(i==2){aux2 = b;}
                    else {aux3 = b;}
                    break;

                case 'c':
                    if(i==1){aux1 = b;}
                    else if(i==2){aux2 = b;}
                    else {aux3 = b;}
                    break;
                default:
                    cout<<"\tOpção inválida!!!";
                    opcao = 'x';
            }
        }while(opcao == 'x');

        if(i==1){vetAux1 = opcao;}
        else if(i==2){vetAux2 = opcao;}
        else{vetAux3 = opcao;}
    }
}

void inserirValor(){
    system("cls");

    cout<<"Vetor A"<<endl;
    cout<<"\tx =  ";
    cin>> a.x;
    cout<<"\ty =  ";
    cin>> a.y;
    cout<<"\tz =  ";
    cin>> a.z;

    cout<<"\nVetor B"<<endl;
    cout<<"\tx =  ";
    cin>> b.x;
    cout<<"\ty =  ";
    cin>> b.y;
    cout<<"\tz =  ";
    cin>> b.z;

    cout<<"\nVetor C"<<endl;
    cout<<"\tx =  ";
    cin>> b.x;
    cout<<"\ty =  ";
    cin>> b.y;
    cout<<"\tz =  ";
    cin>> b.z;
}

void vetores(){
    cout<<endl;
    cout<<"\tVETORES: "<<endl;
    cout<<"\tA ( "<<a.x<<" , "<<a.y<<" , "<<a.z<<" )"<<endl;
    cout<<"\tB ( "<<b.x<<" , "<<b.y<<" , "<<b.z<<" )"<<endl;
    cout<<"\tC ( "<<c.x<<" , "<<c.y<<" , "<<c.z<<" )"<<endl;
    cout<<endl;
}

void vetoresEscolhidos(){
    cout<<endl;
    cout<<"\tVETORES ESCOLHIDOS"<<endl;
    cout<<"\t"<<vetAux1<<" ( "<<aux1.x<<" , "<<aux1.y<<" , "<<aux1.z<<" )"<<endl;
    cout<<"\t"<<vetAux2<<" ( "<<aux2.x<<" , "<<aux2.y<<" , "<<aux2.z<<" )"<<endl;
    cout<<"\t"<<vetAux3<<" ( "<<aux3.x<<" , "<<aux3.y<<" , "<<aux3.z<<" )"<<endl;
    cout<<endl;
}

void valoresProva(){
    a.x = 1;
    a.y = 0;
    a.z = 1;

    b.x = -2;
    b.y = 10;
    b.z = 2;

    c.x = 3;
    c.y = 3;
    c.z = 0;

    aux1 = a;
    aux2 = b;
    aux3 = c;

    vetAux1 = 'a';
    vetAux2 = 'b';
    vetAux3 = 'c';
}
