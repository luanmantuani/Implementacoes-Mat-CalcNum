/*
	Arquivo: calculoN_prova1_Gauss.cpp
	Aluno: Luan Gabriel Mantuani
	Materia: Calculo Numerico
	Professor: Fernando Brito

	--> TEMA, fazer a implementacao dos algoritmos de:
		resolução do sistema utilizando triangulação
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

//  Variaveis Globais
float aux[3][4];
char letras[3][3];

// Funcoes
void sistemaTriangular();
void inserirValor();
void valoresProva();
void desenharSistema(string);

int main(){
    char menuOpcao;
    setlocale(LC_ALL, "Portuguese");
    valoresProva();

    do{

        system("cls");
        cout << "\tOPERAÇÕES - Eliminação de Gauss          //"<<endl;
        cout << "\t1 - Sistema triangular                   //"<<endl;
        cout << "\t-------------------------------------------"<<endl;
        cout << "\tQ - Inserir valores                      //"<<endl;
        cout << "\tW - Inserir valores da Prova I - ex1     //"<<endl;
        cout << "\tE - Sair do programa                     //"<<endl;
        desenharSistema("Sistema");
        cout << "\tOpção: ";
        cin >> menuOpcao;

        switch (tolower(menuOpcao)){

        case '1':
            sistemaTriangular();
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
void sistemaTriangular(){
    system("cls");

    int lin, col, imaior, jmaior;
    float m, valor[3], resultado[3], maior = abs(aux[0][0]);
    float aux2[3][4];
    char laux[3][3];
    desenharSistema("Sistema base");

    //localiza o maior denominador
    for(lin=0; lin<3; lin++){
        for(col=0; col<3; col++){
            if(abs(aux[lin][col]) > maior){
                maior = abs(aux[lin][col]);
                imaior = lin;
                jmaior = col;
            }
        }
    }

    //modifica a matriz para o maior denominador ficar na linha 1
    for(col=0; col<4; col++){ aux2[0][col] = aux[imaior][col];}
    for(col=0; col<4; col++){ aux[imaior][col] = aux[0][col];}
    for(col=0; col<4; col++){ aux[0][col] = aux2[0][col];}
    for(col=0; col<3; col++){ laux[0][col] = letras[imaior][col];}
    for(col=0; col<3; col++){ letras[imaior][col] = letras[0][col];}
    for(col=0; col<3; col++){ letras[0][col] = laux[0][col];}
    desenharSistema("Alinhamento do denominador verticalmente");

    //modifica a matriz para o maior denominador ficar na posicao 1
    for(lin=0; lin<3; lin++){ aux2[lin][0] = aux[lin][jmaior];}
    for(lin=0; lin<3; lin++){ aux[lin][jmaior] = aux[lin][0];}
    for(lin=0; lin<3; lin++){ aux[lin][0] = aux2[lin][0];}
    for(lin=0; lin<3; lin++){ laux[lin][0] = letras[lin][jmaior];}
    for(lin=0; lin<3; lin++){ letras[lin][jmaior] = letras[lin][0];}
    for(lin=0; lin<3; lin++){ letras[lin][0] = laux[lin][0];}
    desenharSistema("Alinhamento do denominador horizontalmente");

    //Define linha 1, calcula o M1, M2 e zera as 2 primeiras variaveis das linhas 1 e 2
    for(lin=1; lin<3; lin++){
        m = -(aux[lin][0]/aux[0][0]);
        for(col=0; col<4; col++){
           aux[lin][col] = aux[lin][col] + (aux[0][col] * m);
        }
        aux[lin][0] = 0;
    }
    desenharSistema("Sistema Triangular: linha 1, m1 e m2");

    //Procura o maior denominador entre as linhas 2 e 3 e ja coloca a linha com o maior denominador na linha 2
    for(lin=1, maior=aux[1][1], imaior=1, jmaior=1; lin<3; lin++){
        for(col=1; col<3; col++){
            if(abs(aux[lin][col]) > maior){
                maior = abs(aux[lin][col]);
                imaior = lin;
                jmaior = col;
            }
        }
    }
    for(col=1; col<4; col++){ aux2[1][col] = aux[imaior][col];}
    for(col=1; col<4; col++){ aux[imaior][col] = aux[1][col];}
    for(col=1; col<4; col++){ aux[1][col] = aux2[1][col];}
    for(col=1; col<3; col++){ laux[1][col] = letras[imaior][col];}
    for(col=1; col<3; col++){ letras[imaior][col] = letras[1][col];}
    for(col=1; col<3; col++){ letras[1][col] = laux[1][col];}
    desenharSistema("Alinhamento do denominador verticalmente, linha 1 e 2");

    //Coloca a coluna com o maior denominador na posicao 2
    for(lin=0; lin<3; lin++){ aux2[lin][1] = aux[lin][jmaior];}
    for(lin=0; lin<3; lin++){ aux[lin][jmaior] = aux[lin][1];}
    for(lin=0; lin<3; lin++){ aux[lin][1] = aux2[lin][1];}
    for(lin=0; lin<3; lin++){ laux[lin][1] = letras[lin][jmaior];}
    for(lin=0; lin<3; lin++){ letras[lin][jmaior] = letras[lin][1];}
    for(lin=0; lin<3; lin++){ letras[lin][1] = laux[lin][1];}
    desenharSistema("Alinhamento do denominador horizontalmente, linha 1 e 2");

    //Calcula M3, zera e linha 2
    m = -(aux[2][1]/aux[1][1]);
    for(col=1; col<4; col++){
       aux[2][col] = aux[2][col] + (aux[1][col] * m);
    }
    aux[2][1] = 0;
    desenharSistema("Sistema triangular: linhas 1, 2 e 3");

    //Monta o vetor resultante
    valor[2] = (aux[2][3]/aux[2][2]);
    valor[1] = (aux[1][3] - (aux[1][2] * valor[2]))/aux[1][1];
    valor[0] = (aux[0][3] - (aux[0][2] * valor[2]) - (aux[0][1] * valor[1]))/aux[0][0];
    for(int i=0; i<3; i++){
        if(letras[i][i] == 'x'){resultado[0] = valor[i];}
        else if(letras[i][i] == 'y'){resultado[1] = valor[i];}
        else {resultado[2] = valor[i];}
    }
    cout<<"\tV = ( X, Y, Z ) = ( "<<resultado[0]<<" , "<<resultado[1]<<" , "<<resultado[2]<<" )"<<endl;

    valoresProva();
}

void inserirValor(){
    system("cls");
    cout<<"\nInforme o valor dos denominadores e do resultado de cada linha(0 à 2):"<<endl;
    for(int i=0; i<3; i++){
        cout<<"\nLinha "<<i<<endl;
        cout<<"\tx =  ";
        cin>> aux[i][0];
        letras[i][0] = 'x';
        cout<<"\ty =  ";
        cin>> aux[i][1];
        letras[i][1] = 'y';
        cout<<"\tz =  ";
        cin>> aux[i][2];
        letras[i][2] = 'z';
        cout<<"\tResultado =  ";
        cin>> aux[i][3];
    }
}

void valoresProva(){
    aux[0][0] = 2;
    aux[0][1] = 5;
    aux[0][2] = -7;
    aux[0][3] = -2;

    aux[1][0] = 3;
    aux[1][1] = 7;
    aux[1][2] = -9;
    aux[1][3] = 3;

    aux[2][0] = 1;
    aux[2][1] = 2;
    aux[2][2] = -4;
    aux[2][3] = 1;

    for(int i=0; i<3; i++){
        letras[i][0] = 'x';
        letras[i][1] = 'y';
        letras[i][2] = 'z';
    }
}

void desenharSistema(string texto){
    cout<<endl;
    cout<<"\t"<<texto<<endl;
    cout<<"\t("<<aux[0][0]<<letras[0][0]<<"\t"<<aux[0][1]<<letras[0][1]<<"\t"<<aux[0][2]<<letras[0][2]<<"\t= "<<aux[0][3]<<endl;
    cout<<"\t<"<<aux[1][0]<<letras[1][0]<<"\t"<<aux[1][1]<<letras[1][1]<<"\t"<<aux[1][2]<<letras[1][2]<<"\t= "<<aux[1][3]<<endl;
    cout<<"\t("<<aux[2][0]<<letras[2][0]<<"\t"<<aux[2][1]<<letras[2][1]<<"\t"<<aux[2][2]<<letras[2][2]<<"\t= "<<aux[2][3]<<endl;
    cout<<endl;
}
