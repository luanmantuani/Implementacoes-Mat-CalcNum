/*
	Arquivo: mat2_prova2_Bases_2x2.cpp
	Aluno: Luan Gabriel Mantuani
	Materia: Matematica_II
	Professor: Fernando Brito

	--> TEMA, fazer a implementacao dos algoritmos de:
		formação de base dos vetores e combinação linear com os 2 vetores da base
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
};

//  Variaveis Globais
vetor a, b, v;
char letra[4] = {'A', 'B', 'V'};
float aux[2][3];
char letras[2][2];



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
        cout << "\tOPERAÇÕES - VETORES 2 VARIÁVEIS          //"<<endl;
        cout << "\t1 - Verificar Base                       //"<<endl;
        cout << "\t2 - Combinação Linear                    //"<<endl;
        cout << "\t3 - Todas as operacoes                   //"<<endl;
        cout << "\t-------------------------------------------"<<endl;
        cout << "\tQ - Inserir valores                      //"<<endl;
        cout << "\tW - Inserir valores da Prova II - ex1    //"<<endl;
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
    float determinante = (a.x*b.y)-(a.y*b.x);

    if(exibir){
        cout<<"\n\tVerificar se os vetores formam uma base: "<<endl;
        cout<<"\t\t\t| "<<a.x<<"\t"<<a.y<<" |"<<endl;
        cout<<"\t[ A, B ] =\t| "<<b.x<<"\t"<<b.y<<" | = "<<determinante<<endl;
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
        float m, valor[2], maior = a.x;
        float aux2[2][3];
        char laux[2][2];
        vetor resultado;

        //valores iniciais da matriz/sistema
        aux[0][0] = a.x;    aux[0][1] = b.x;    aux[0][2] = v.x;
        aux[1][0] = a.y;    aux[1][1] = b.y;    aux[1][2] = v.y;
        letras[0][0] = 'x';    letras[0][1] = 'y';
        letras[1][0] = 'x';    letras[1][1] = 'y';
        desenharMatriz("Sistema base");

        //localiza o maior denominador
        for(lin=0; lin<2; lin++){
            for(col=0; col<2; col++){
                if(aux[lin][col] > maior){
                    maior = aux[lin][col];
                    imaior = lin;
                    jmaior = col;
                }
            }
        }

        //modifica a matriz para o maior denominador ficar na linha 1
        for(col=0; col<3; col++){ aux2[0][col] = aux[imaior][col];}
        for(col=0; col<3; col++){ aux[imaior][col] = aux[0][col];}
        for(col=0; col<3; col++){ aux[0][col] = aux2[0][col];}
        for(col=0; col<2; col++){ laux[0][col] = letras[imaior][col];}
        for(col=0; col<2; col++){ letras[imaior][col] = letras[0][col];}
        for(col=0; col<2; col++){ letras[0][col] = laux[0][col];}
        desenharMatriz("Alinhando maior denominador verticalmente");

        //modifica a matriz para o maior denominador ficar na posicao 1
        for(lin=0; lin<2; lin++){ aux2[lin][0] = aux[lin][jmaior];}
        for(lin=0; lin<2; lin++){ aux[lin][jmaior] = aux[lin][0];}
        for(lin=0; lin<2; lin++){ aux[lin][0] = aux2[lin][0];}
        for(lin=0; lin<2; lin++){ laux[lin][0] = letras[lin][jmaior];}
        for(lin=0; lin<2; lin++){ letras[lin][jmaior] = letras[lin][0];}
        for(lin=0; lin<2; lin++){ letras[lin][0] = laux[lin][0];}
        desenharMatriz("Alinhando maior denominador horizontalmente");

        //Calcula o valor de x e y
        valor[0] = ((aux[1][2]*aux[0][0])-(aux[0][2]*aux[1][0]))/((aux[0][0]*aux[1][1])-(aux[0][1]*aux[1][0]));
        if(aux[0][0] == 0){
            m = 1;
        }else{
            m = aux[0][0];
        }
        valor[1] = (aux[0][2]-aux[0][1]*valor[0])/m;
        if(letras[0][0] == 'x'){
            resultado.x = valor[1];
            resultado.y = valor[0];
        }else{
            resultado.x = valor[0];
            resultado.y = valor[1];
        }
        cout<<"\tV = ( X, Y ) = ( "<<resultado.x<<" , "<<resultado.y<<" )"<<endl;

        //Compara o vetor resultante com o vetor de base
        aux2[0][0] = a.x * resultado.x;    aux2[0][1] = b.x * resultado.y;
        aux2[1][0] = a.y * resultado.x;    aux2[1][1] = b.y * resultado.y;
        cout<<"\t( "<<v.x<<" , "<<v.y<<") = ( "<<aux2[0][0]<<" , "<<aux2[1][0]<<" ) +"
            <<" ( "<<aux2[0][1]<<" , "<<aux2[1][1]<<" )"<<endl;
        cout<<"\t( "<<v.x<<" , "<<v.y<<") ="
            <<" ( "<<aux2[0][0]<<" + "<<aux2[0][1]<<" ,"
            <<" "<<aux2[1][0]<<" + "<<aux2[1][1]<<" )"<<endl;

            resultado.x = aux2[0][0] + aux2[0][1];
            resultado.y = aux2[1][0] + aux2[1][1];

        cout<<"\t( "<<v.x<<" , "<<v.y<<") ="
            <<" ( "<<resultado.x<<" , "<<resultado.y<<" )"<<endl;

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

    for(int i=0; i<3; i++){
        cout<<"Vetor "<<letra[i]<<endl;
        cout<<"\tx =  ";
        cin>> k.x;
        cout<<"\ty =  ";
        cin>> k.y;

        if(i==0){a = k;}
        else if(i==1){b = k;}
        else {v = k;}
    }


}

void vetores(){
    cout<<endl;
    cout<<"\tVETORES de operação: "<<endl;
    cout<<"\tA ( "<<a.x<<", "<<a.y<<" )"<<endl;
    cout<<"\tB ( "<<b.x<<", "<<b.y<<" )"<<endl;
    cout<<"\tVETOR de combinação: "<<endl;
    cout<<"\tV ( "<<v.x<<", "<<v.y<<" )"<<endl;
    cout<<endl;
}

void valoresProva(){
    a.x = 0;
    a.y = 2;

    b.x = 3;
    b.y = 1;

    v.x = 3;
    v.y = 5;
}

void desenharMatriz(string texto){
    cout<<endl;
    cout<<"\t"<<texto<<endl;
    cout<<"\t"<<aux[0][0]<<letras[0][0]<<"\t"<<aux[0][1]<<letras[0][1]<<"\t=\t"<<aux[0][2]<<endl;
    cout<<"\t"<<aux[1][0]<<letras[1][0]<<"\t"<<aux[1][1]<<letras[1][1]<<"\t=\t"<<aux[1][2]<<endl;
    cout<<endl;
}
