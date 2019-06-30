/*
	Arquivo: mat2_prova2_Bases_3x3.cpp
	Aluno: Luan Gabriel Mantuani
	Materia: Matematica_II
	Professor: Fernando Brito

	--> TEMA, fazer a implementacao dos algoritmos de:
		formação de base dos vetores e combinação linear com os 3 vetores da base
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
};

//  Variaveis Globais
vetor a, b, c, v;
char letra[4] = {'A', 'B', 'C', 'V'};
float aux[3][4];
char letras[3][3];



//ARQUIVO SEQUENCIAL - Funcoes
bool verificarBase(bool);
void CombinacaoLinear();
void todasOperacoes();
void inserirValor();
void vetores();
void valoresProva();
void desenharMatriz(string);

int main(){
    char menuOpcao;
    setlocale(LC_ALL, "Portuguese");
    valoresProva();

    do{

        system("cls");
        cout << "\tOPERAÇÕES - VETORES 3 VARIÁVEIS          //"<<endl;
        cout << "\t1 - Verificar Base                       //"<<endl;
        cout << "\t2 - Combinação Linear                    //"<<endl;
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
            verificarBase(true);
            break;

        case '2':
            CombinacaoLinear();
            break;

        case '3':
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
bool verificarBase(bool exibir){
    float determinante = (a.x*b.y*c.z)+(a.y*b.z*c.x)+(a.z*b.x*c.y);
    determinante += -(a.z*b.y*c.x)-(a.y*b.x*c.z)-(a.x*b.z*c.y);

    if(exibir){
        cout<<"\n\tVerificar se os vetores formam uma base: "<<endl;
        cout<<"\t\t\t| "<<a.x<<"\t"<<a.y<<"\t"<<a.z<<" |"<<endl;
        cout<<"\t[ A, B, C ] ="
            <<"\t| "<<b.x<<"\t"<<b.y<<"\t"<<b.z<<" | ="
            <<" "<<determinante<<endl;
        cout<<"\t\t\t| "<<c.x<<"\t"<<c.y<<"\t"<<c.z<<" |"<<endl;
        if(determinante == 0.0){
            cout<<"\t*Os vetores são Linearmente Dependentes(LD)!"<<endl;
        }else{
            cout<<"\t*Os vetores são Linearmente Independentes(LI)!"<<endl;
        }
        cout<<endl;
    }else{
        if(determinante != 0.0){return true;}
        else {return false;}
    }
}

void CombinacaoLinear(){
    if(verificarBase(false)){
        int lin, col, imaior, jmaior;
        float m, valor[3], maior = a.x;
        float aux2[3][4];
        char laux[3][3];
        vetor resultado;

        //valores iniciais da matriz/sistema
        aux[0][0] = a.x;    aux[0][1] = b.x;    aux[0][2] = c.x;    aux[0][3] = v.x;
        aux[1][0] = a.y;    aux[1][1] = b.y;    aux[1][2] = c.y;    aux[1][3] = v.y;
        aux[2][0] = a.z;    aux[2][1] = b.z;    aux[2][2] = c.z;    aux[2][3] = v.z;
        letras[0][0] = 'x';    letras[0][1] = 'y';    letras[0][2] = 'z';
        letras[1][0] = 'x';    letras[1][1] = 'y';    letras[1][2] = 'z';
        letras[2][0] = 'x';    letras[2][1] = 'y';    letras[2][2] = 'z';
        desenharMatriz("Sistema base");

        //localiza o maior denominador
        for(lin=0; lin<3; lin++){
            for(col=0; col<3; col++){
                if(aux[lin][col] > maior){
                    maior = aux[lin][col];
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
        desenharMatriz("Alinhamento do denominador verticalmente");

        //modifica a matriz para o maior denominador ficar na posicao 1
        for(lin=0; lin<3; lin++){ aux2[lin][0] = aux[lin][jmaior];}
        for(lin=0; lin<3; lin++){ aux[lin][jmaior] = aux[lin][0];}
        for(lin=0; lin<3; lin++){ aux[lin][0] = aux2[lin][0];}
        for(lin=0; lin<3; lin++){ laux[lin][0] = letras[lin][jmaior];}
        for(lin=0; lin<3; lin++){ letras[lin][jmaior] = letras[lin][0];}
        for(lin=0; lin<3; lin++){ letras[lin][0] = laux[lin][0];}
        desenharMatriz("Alinhamento do denominador horizontalmente");

        //Define linha 1, calcula o M1, M2 e zera as 2 primeiras variaveis das linhas 1 e 2
        for(lin=1; lin<3; lin++){
            m = -(aux[lin][0]/aux[0][0]);
            for(col=0; col<4; col++){
               aux[lin][col] = aux[lin][col] + (aux[0][col] * m);
            }
        }
        desenharMatriz("Sistema Triangular: linha 1, m1 e m2");

        //Procura o maior denominador entre as linhas 2 e 3 e ja coloca a linha com o maior denominador na linha 2
        for(lin=1, maior=aux[1][1], imaior=1, jmaior=1; lin<3; lin++){
            for(col=1; col<3; col++){
                if(aux[lin][col] > maior){
                    maior = aux[lin][col];
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
        desenharMatriz("Alinhamento do denominador verticalmente, linha 1 e 2");

        //Coloca a coluna com o maior denominador na posicao 2
        for(lin=0; lin<3; lin++){ aux2[lin][1] = aux[lin][jmaior];}
        for(lin=0; lin<3; lin++){ aux[lin][jmaior] = aux[lin][1];}
        for(lin=0; lin<3; lin++){ aux[lin][1] = aux2[lin][1];}
        for(lin=0; lin<3; lin++){ laux[lin][1] = letras[lin][jmaior];}
        for(lin=0; lin<3; lin++){ letras[lin][jmaior] = letras[lin][1];}
        for(lin=0; lin<3; lin++){ letras[lin][1] = laux[lin][1];}
        desenharMatriz("Alinhamento do denominador horizontalmente, linha 1 e 2");

        //Calcula M3, zera e linha 2
        m = -(aux[2][1]/aux[1][1]);
        for(col=1; col<4; col++){
           aux[2][col] = aux[2][col] + (aux[1][col] * m);
        }
        desenharMatriz("Sistema triangular: linhas 1, 2 e 3");

        //Monta o vetor resultante
        valor[2] = (aux[2][3]/aux[2][2]);
        valor[1] = (aux[1][3] - (aux[1][2] * valor[2]))/aux[1][1];
        valor[0] = (aux[0][3] - (aux[0][2] * valor[2]) - (aux[0][1] * valor[1]))/aux[0][0];
        for(int i=0; i<3; i++){
            if(letras[i][i] == 'x'){resultado.x = valor[i];}
            else if(letras[i][i] == 'y'){resultado.y = valor[i];}
            else {resultado.z = valor[i];}
        }
        cout<<"\tV = ( X, Y, Z ) = ( "<<resultado.x<<" , "<<resultado.y<<" , "<<resultado.z<<" )"<<endl;

        //Compara o vetor resultante com o vetor de base
        aux2[0][0] = a.x * resultado.x;    aux2[0][1] = b.x * resultado.y;    aux2[0][2] = c.x * resultado.z;
        aux2[1][0] = a.y * resultado.x;    aux2[1][1] = b.y * resultado.y;    aux2[1][2] = c.y * resultado.z;
        aux2[2][0] = a.z * resultado.x;    aux2[2][1] = b.z * resultado.y;    aux2[2][2] = c.z * resultado.z;
        cout<<"\t( "<<v.x<<" , "<<v.y<<" , "<<v.z<<") ="
            <<" ( "<<aux2[0][0]<<" , "<<aux2[1][0]<<" , "<<aux2[2][0]<<" ) +"
            <<" ( "<<aux2[0][1]<<" , "<<aux2[1][1]<<" , "<<aux2[2][1]<<" ) +"
            <<" ( "<<aux2[0][2]<<" , "<<aux2[1][2]<<" , "<<aux2[2][2]<<" )"<<endl;
        cout<<"\t( "<<v.x<<" , "<<v.y<<" , "<<v.z<<") ="
            <<" ( "<<aux2[0][0]<<" + "<<aux2[0][1]<<" + "<<aux2[0][2]<<" ,"
            <<" "<<aux2[1][0]<<" + "<<aux2[1][1]<<" + "<<aux2[1][2]<<" ,"
            <<" "<<aux2[2][0]<<" + "<<aux2[2][1]<<" + "<<aux2[2][2]<<" )"<<endl;

            resultado.x = aux2[0][0] + aux2[0][1] + aux2[0][2];
            resultado.y = aux2[1][0] + aux2[1][1] + aux2[1][2];
            resultado.z = aux2[2][0] + aux2[2][1] + aux2[2][2];

        cout<<"\t( "<<v.x<<" , "<<v.y<<" , "<<v.z<<") ="
            <<" ( "<<resultado.x<<" , "<<resultado.y<<" , "<<resultado.z<<" )"<<endl;

    }else{cout<<"\n\t*Os vetores são Linearmente Dependentes(LD)!"<<endl;}
}

void todasOperacoes(){
    system("cls");
    vetores();
    verificarBase(true);
    CombinacaoLinear();
    system("pause");
}


void inserirValor(){
    system("cls");
    vetor k;

    for(int i=0; i<4; i++){
        cout<<"Vetor "<<letra[i]<<endl;
        cout<<"\tx =  ";
        cin>> k.x;
        cout<<"\ty =  ";
        cin>> k.y;
        cout<<"\tz =  ";
        cin>> k.z;

        if(i==0){a = k;}
        else if(i==1){b = k;}
        else if(i==2){c = k;}
        else {v = k;}
    }


}

void vetores(){
    cout<<endl;
    cout<<"\tVETORES de operação: "<<endl;
    cout<<"\tA ( "<<a.x<<", "<<a.y<<", "<<a.z<<" )"<<endl;
    cout<<"\tB ( "<<b.x<<", "<<b.y<<", "<<b.z<<" )"<<endl;
    cout<<"\tC ( "<<c.x<<", "<<c.y<<", "<<c.z<<" )"<<endl;
    cout<<"\tVETOR de combinação: "<<endl;
    cout<<"\tV ( "<<v.x<<", "<<v.y<<", "<<v.z<<" )"<<endl;
    cout<<endl;
}

void valoresProva(){
    a.x = -1;
    a.y = 2;
    a.z = 1;

    b.x = 1;
    b.y = 0;
    b.z = 2;

    c.x = -2;
    c.y = -1;
    c.z = 0;

    v.x = -8;
    v.y = 4;
    v.z = 1;
}

void desenharMatriz(string texto){
    cout<<endl;
    cout<<"\t"<<texto<<endl;
    cout<<"\t"<<aux[0][0]<<letras[0][0]<<"\t"<<aux[0][1]<<letras[0][1]<<"\t"<<aux[0][2]<<letras[0][2]<<"\t= "<<aux[0][3]<<endl;
    cout<<"\t"<<aux[1][0]<<letras[1][0]<<"\t"<<aux[1][1]<<letras[1][1]<<"\t"<<aux[1][2]<<letras[1][2]<<"\t= "<<aux[1][3]<<endl;
    cout<<"\t"<<aux[2][0]<<letras[2][0]<<"\t"<<aux[2][1]<<letras[2][1]<<"\t"<<aux[2][2]<<letras[2][2]<<"\t= "<<aux[2][3]<<endl;
    cout<<endl;
}
