#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

//Struct dados do usuário
typedef struct
{
    int ID;
    char nome[30];
    int respostasCorretas, respostasErradas;
} sUsuario;

//Struct operações aritméticas
typedef struct
{
    int codOperacao;
    double n1, n2;
} sOpAritmeticas;

//Struct formas geométricas
typedef struct
{
    int codForma;
    double base, altura, baseMaior, baseMenor, raio;
} sFGeometricas;

//Struct funções matemáticas
typedef struct
{
    int codFuncoes;
    double coefA, coefB, coefC, delta, x1, x2, x1C, x2C;
} sFMatematicas;

//Struct matrizes
typedef struct
{
    int codTipoMatriz;
    double matriz[5][3];
    double matrizInversa[5][3];
    double matrizTransposta[3][5];
} sMatriz;

//Struct para cadastro dos resultados
typedef struct
{
    int posicaoVetor;
    int IDusuario;
    int tipoTeste;
    int opcaoTeste;
    double respostaUsuario;
    double respostaCorreta;
} sResultados;


int main()
{
    setlocale(LC_ALL, "portuguese");

    printf("+-------------------------------------------------------------------------+\n");
    printf("|Pontifícia Universidade Católica de Minas Gerais - campus Poços de Caldas|\n");
    printf("|Ciência da Computação - Laboratório de AED I                             |\n");
    printf("|Projeto Final: Programa para realização de testes matemáticos            |\n");
    printf("|Alunos: João Marcelo e Tuanne                                            |\n");
    printf("+-------------------------------------------------------------------------+\n\n");
    system("pause");

    printf("\nO teste será composto de:\n\n");
    printf("a) 5 questões de Operações Aritméticas\n");
    printf("b) 5 questões de Formas Geométricas\n");
    printf("c) 5 questões de Funções Matemáticas\n");
    printf("d) 5 questões de Matrizes\n\n");
    system("pause");

//Declaração de variáveis
    int primeiraLetra;
    int i;
    int a;                                                      //variável somente para função toupper usuário
    int j;                                                     //variável que percorre os tipos de operações
    int w;                                                      //variavel que percorre o vetor de resultados para armazenamento dos dados e respostas
    int l, c;
    int maiorNota, novoRelatorio;
    char vencedor[30];                                                  //variavel utilizada na randomização da posição do teste da matriz

    double pi = 3.14;
    char tipoTeste[4][22] = {"Operações Aritméticas","Funções Geometricas","Funções Matemáticas","Matrizes"};
    char operacoesMat[4][14] = {"Soma","Subtração","Multiplicação", "Divisão"};
    char formasGeomet[4][10] = {"Circulo","Triângulo","Trapézio","Retângulo"};
    char funcoesMat [4][20] = {"Função de 1º grau","Função de 2º grau"};
    char tipoMatriz[2][18] = {"Matriz Inversa", "Matriz Transposta"};

    sUsuario vUsuario[5];
    sOpAritmeticas vOpAritmeticas[5];
    sFGeometricas vFGeometricas[5];
    sFMatematicas vFMatematicas[5];
    sMatriz vMatriz[5];
    sResultados vResultados[100];                               //vetor que armazena todas as structures dos resultados

//Cadastro de usuários_______________________________________________________________________________________
    system("cls");
    printf("+----------------------------+\n");
    printf("  ***CADASTRO DE USUÁRIOS***\n");
    printf("+----------------------------+\n");
    printf("Deverão ser cadastrados 5 usuários para realização dos testes\n\n");

    for(i=0; i<5; i++)
    {
        do
        {
            vUsuario[i].ID = i+1;
            printf("Digite o nome do Usuário %d: ", i+1);
            fflush(stdin);
            gets(vUsuario[i].nome);
            primeiraLetra = vUsuario[i].nome[0];

            if(primeiraLetra == 0 || primeiraLetra == 32)
                printf("Insira um nome de usuário válido\n\n");

            for(a=0; a<strlen(vUsuario[i].nome); a++)
            {
                vUsuario[i].nome[a] = toupper(vUsuario[i].nome[a]);
            }
        }
        while(primeiraLetra == 0 ||primeiraLetra == 32);
    }

//Cadastro de Operações Aritméticas____________________________________________________________________________
    system("cls");
    printf("+------------------------------------------+\n");
    printf("  ***CADASTRO DE OPERAÇÕES ARITMÉTICAS***\n");
    printf("+------------------------------------------+\n");
    printf("Cadastre, pelo menos 5 operações para o teste\n");
    printf("\n1 - Soma");
    printf("\n2 - Subtração");
    printf("\n3 - Multiplicação");
    printf("\n4 - Divisão\n");

    srand(clock());

    for(i=0; i<5; i++)                                      //Teste de operações aritméricas
    {
        //vOpAritmeticas[i].codTipoTeste = 1;
        vOpAritmeticas[i].n1 = (rand() %100)-50;
        vOpAritmeticas[i].n2 = (rand() %100)-50;
        do
        {
            printf("\nDigite o NÚMERO da operação desejada: ");
            fflush(stdin);
            scanf("%d", &vOpAritmeticas[i].codOperacao);

            if(vOpAritmeticas[i].codOperacao>4 || vOpAritmeticas[i].codOperacao<=0)
                printf("Opção inválida, digite novamente\n");
        }
        while(vOpAritmeticas[i].codOperacao>4 || vOpAritmeticas[i].codOperacao<=0);

//Gerando valores e inserindo na struct opAritmetica para a realização dos testes________________________________

        if(vOpAritmeticas[i].codOperacao==4)
            do
            {
                if(vOpAritmeticas[i].n2==0)
                    vOpAritmeticas[i].n2 = (rand() %50);
            }
            while(vOpAritmeticas[i].n2==0);
    }

//Cadastro de Formas Geométricas_______________________________________________________________________________________
    system("cls");
    printf("+----------------------------------------+\n");
    printf("   ***CADASTRO DE FORMAS GEOMÉTRICAS***\n");
    printf("+----------------------------------------+\n");
    printf("Cadastre, pelo menos 5 operações para o teste\n");
    printf("\n1 - Circulo");
    printf("\n2 - Triângulo");
    printf("\n3 - Trapézio");
    printf("\n4 - Retângulo\n");

    for(i=0; i<5; i++)
    {
        //vFGeometricas[i].codTipoTeste = 2;
        do
        {
            printf("\nDigite o NÚMERO da forma geométrica desejada: ");
            fflush(stdin);
            scanf("%d",&vFGeometricas[i].codForma);

            if(vFGeometricas[i].codForma>4 || vFGeometricas[i].codForma<=0)
                printf("Opção inválida, digite novamente\n");
        }
        while(vFGeometricas[i].codForma>4 || vFGeometricas[i].codForma<=0);

//Gerando valores e inserindo na struct opAritmetica para a realização dos testes_______________________________________
        srand(clock());
        vFGeometricas[i].base = rand() %50;
        vFGeometricas[i].altura = rand() %50;
        vFGeometricas[i].raio = rand() %50;
        vFGeometricas[i].baseMaior = rand() %50;
        do
        {
            vFGeometricas[i].base = rand() %50;
            vFGeometricas[i].altura = rand() %50;
            vFGeometricas[i].raio = rand() %50;
            vFGeometricas[i].baseMaior = rand() %50;
            vFGeometricas[i].baseMenor = rand() %50;
        }
        while(vFGeometricas[i].base==0 || vFGeometricas[i].altura==0 || vFGeometricas[i].raio==0 || vFGeometricas[i].baseMaior==0 || vFGeometricas[i].baseMenor>vFGeometricas[i].baseMaior);
    }

//Cadastro de Funções Matemáticas_______________________________________________________________________________________
    system("cls");
    printf("+---------------------------------------+\n");
    printf("  ***CADASTRO DE FUNÇÕES MATEMÁTICAS***\n");
    printf("+---------------------------------------+\n");
    printf("Cadastre, pelo menos 5 funções para o teste\n");
    printf("\n1 - Função de 1º grau");
    printf("\n2 - Função de 2º grau\n");

    for(i=0; i<5; i++)
    {
        //vFMatematicas[i].codTipoTeste = 3;
        do
        {
            printf("\nDigite o NÚMERO da função matemática desejada: ");
            fflush(stdin);
            scanf("%d",&vFMatematicas[i].codFuncoes);
            if(vFMatematicas[i].codFuncoes>2 || vFMatematicas[i].codFuncoes<=0)
                printf("Opção inválida, digite novamente\n");
        }
        while(vFMatematicas[i].codFuncoes>2 || vFMatematicas[i].codFuncoes<=0);

//Gerando valores e inserindo na struct opAritmetica para a realização dos testes__________________________
        srand(clock());

        vFMatematicas[i].coefA = (rand() %50)-25;
        vFMatematicas[i].coefB = (rand() %50)-25;
        vFMatematicas[i].coefC = (rand() %50)-25;
        vFMatematicas[i].delta=pow(vFMatematicas[i].coefB,2)-(4*vFMatematicas[i].coefA*vFMatematicas[i].coefC);

        do
        {
            if(vFMatematicas[i].coefA==0 || vFMatematicas[i].coefB==0 || vFMatematicas[i].coefC==0 || vFMatematicas[i].delta<0)
                vFMatematicas[i].coefA = (rand() %50)-25;
            vFMatematicas[i].coefB = (rand() %50)-25;
            vFMatematicas[i].coefC = (rand() %50)-25;
            vFMatematicas[i].delta=pow(vFMatematicas[i].coefB,2)-(4*vFMatematicas[i].coefA*vFMatematicas[i].coefC);
        }
        while(vFMatematicas[i].coefA==0 || vFMatematicas[i].coefB==0 || vFMatematicas[i].coefC==0 || vFMatematicas[i].delta<0);
    }

//Cadastro de Matrizes_______________________________________________________________________________________
    system("cls");
    printf("+-----------------------------+\n");
    printf("  ***CADASTRO DE MATRIZES***   \n");
    printf("+-----------------------------+\n");

    printf("Cadastre, pelo menos 5 opções para o teste de matrizes\n");
    printf("\n1 - matriz INVERSA");
    printf("\n2 - matriz TRANSPOSTA\n");

    for(i=0; i<5; i++)
    {
        do
        {
            printf("\nDigite o NÚMERO da opção desejada: ");
            fflush(stdin);
            scanf("%d",&vMatriz[i].codTipoMatriz);
            if(vMatriz[i].codTipoMatriz>2 || vMatriz[i].codTipoMatriz<=0)
                printf("Opção inválida, digite novamente\n");
        }
        while(vMatriz[i].codTipoMatriz>2 || vMatriz[i].codTipoMatriz<=0);
    }

//Geração das matrizes para teste_______________________________________________________________________________________

    srand(clock());
    for(i=0; i<5; i++)
    {

        for (l=0; l<5; l++)
        {
            for (c=0; c<3; c++)
            {
                vMatriz[i].matriz[l][c] = (rand() %100)-50;
            }
        }
    }

//INICIO DOS TESTES********************************************************************************************************

    w=0;                //percorre o vetor de resposta
    for(i=0; i<5; i++)  //percorre o vetor de usuarios para que cada um realize o teste abaixo
    {
        system("cls");
        printf("INSTRUÇÕES PARA INSERÇÃO DAS RESPOSTAS\n\n");
        printf("1 - Utilizar a vírgula como separador decimal\n");
        printf("2 - Utilizar 2 casas decimais\n");
        printf("3 - Não utilizar arredondamento\n\n");
        system("pause");


        system("cls");
        printf("+---------------------------------------------------------------------------------+\n");
        printf(" INÍCIO DO TESTE DO USUÁRIO %d: %s \n", vUsuario[i].ID, vUsuario[i].nome);
        printf("+---------------------------------------------------------------------------------+\n\n");

        vUsuario[i].respostasCorretas = 0;
        vUsuario[i].respostasErradas = 0;

        printf("------------------------------\n");
        printf("Teste de Operações Matemáticas\n");
        printf("------------------------------\n");

        for(j=0; j<5; j++)          //percorre o vetor das operações aritméticas
        {
            switch(vOpAritmeticas[j].codOperacao)
            {
            case 1:
                printf("\nResponda a pergunta: \n");
                printf("Qual o valor do resultado da expressão:\n%lf + %lf = ", vOpAritmeticas[j].n1, vOpAritmeticas[j].n2);
                scanf("%lf", &vResultados[w].respostaUsuario);
                fflush(stdin);
                vResultados[w].respostaCorreta = trunc((vOpAritmeticas[j].n1 + vOpAritmeticas[j].n2)*100)/100;
                break;

            case 2:
                printf("\nResponda a pergunta: \n");
                printf("Qual o valor do resultado da expressão:\n%lf - %lf = ", vOpAritmeticas[j].n1, vOpAritmeticas[j].n2);
                scanf("%lf", &vResultados[w].respostaUsuario);
                fflush(stdin);
                vResultados[w].respostaCorreta = trunc((vOpAritmeticas[j].n1 - vOpAritmeticas[j].n2)*100)/100;
                break;

            case 3:
                printf("\nResponda a pergunta: \n");
                printf("Qual o valor do resultado da expressão:\n%lf * %lf = ", vOpAritmeticas[j].n1, vOpAritmeticas[j].n2);
                scanf("%lf", &vResultados[w].respostaUsuario);
                fflush(stdin);
                vResultados[w].respostaCorreta = trunc((vOpAritmeticas[j].n1 * vOpAritmeticas[j].n2)*100)/100;
                break;

            case 4:
                printf("\nResponda a pergunta: \n");
                printf("Qual o valor do resultado da expressão:\n%lf / %lf = ", vOpAritmeticas[j].n1, vOpAritmeticas[j].n2);
                scanf("%lf", &vResultados[w].respostaUsuario);
                fflush(stdin);
                vResultados[w].respostaCorreta = trunc((vOpAritmeticas[j].n1 / vOpAritmeticas[j].n2)*100)/100;
                break;

            default:
                break;
            }

            vResultados[w].posicaoVetor = w;
            vResultados[w].IDusuario = vUsuario[i].ID;
            vResultados[w].tipoTeste = 1;
            vResultados[w].opcaoTeste = vOpAritmeticas[j].codOperacao;

            w++; //incrementa 1 posição no vetor de resultados, para receber o novo teste
        }
        printf("\n\n");
        system("pause");
        system("cls");
//___________________________________________________________________________________________
        printf("---------------------------\n");
        printf("Teste de Formas Geométricas\n");
        printf("---------------------------\n");

        for(j=0; j<5; j++)
        {
            switch(vFGeometricas[j].codForma)
            {
            case 1:
                printf("\nResponda a pergunta: \n");
                printf("Qual o valor da área de um círculo de raio = %lf?\n", vFGeometricas[j].raio);
                printf("Considerar o valor de PI = 3,14\n");
                printf("Sua resposta: ");
                scanf("%lf", &vResultados[w].respostaUsuario);
                fflush(stdin);
                vResultados[w].respostaCorreta = trunc((pi*pow(vFGeometricas[j].raio,2))*100)/100;
                break;

            case 2:
                printf("\nResponda a pergunta: \n");
                printf("Qual o valor da área de um triângulo com base = %lf e altura = %lf? \n", vFGeometricas[j].base, vFGeometricas[j].altura);
                printf("Sua resposta: ");
                scanf("%lf", &vResultados[w].respostaUsuario);
                fflush(stdin);
                vResultados[w].respostaCorreta = trunc((((vFGeometricas[j].base * vFGeometricas[j].altura)/2))*100)/100;
                break;

            case 3:
                printf("\nResponda a pergunta: \n");
                printf("Qual o valor da área de um trapézio com base maior = %lf, base menor = %lf e altura = %lf? \n", vFGeometricas[j].baseMaior, vFGeometricas[j].baseMenor,vFGeometricas[j].altura);
                printf("Sua resposta: ");
                scanf("%lf", &vResultados[w].respostaUsuario);
                fflush(stdin);
                vResultados[w].respostaCorreta = trunc((((vFGeometricas[j].baseMaior + vFGeometricas[j].baseMenor) * vFGeometricas[j].altura)/2)*100)/100;
                break;

            case 4:
                printf("\nResponda a pergunta: \n");
                printf("Qual o valor da área de um retângulo com base = %lf e altura = %lf? \n", vFGeometricas[j].base, vFGeometricas[j].altura);
                printf("Sua resposta: ");
                scanf("%lf", &vResultados[w].respostaUsuario);
                fflush(stdin);
                vResultados[w].respostaCorreta = vFGeometricas[j].base * vFGeometricas[j].altura;
                break;

            default:
                break;
            }

            vResultados[w].IDusuario = vUsuario[i].ID;
            vResultados[w].tipoTeste = 2;
            vResultados[w].opcaoTeste = vFGeometricas[j].codForma;

            w++;
        }
        printf("\n\n");
        system("pause");
        system("cls");

        printf("----------------------------\n");
        printf("Teste de Funções Matemáticas\n");
        printf("----------------------------\n");

        for(j=0; j<5; j++)
        {
            switch(vFMatematicas[j].codFuncoes)
            {
            case 1:
                printf("\nResponda a pergunta: \n");
                printf("Qual o valor da raíz da expressão:\n%lfx + %lf = 0?\n", vFMatematicas[j].coefB, vFMatematicas[j].coefC);
                printf("Sua resposta: ");
                scanf("%lf", &vResultados[w].respostaUsuario);
                fflush(stdin);
                vResultados[w].respostaCorreta = trunc((- vFMatematicas[j].coefC / vFMatematicas[j].coefB)*100)/100;
                break;

            case 2:
                printf("\nResponda a pergunta: \n");
                printf("Qual o valor das raízes x1 e x2 da equação = %lfx² + %lfx + %lf = 0?\n", vFMatematicas[j].coefA, vFMatematicas[j].coefB, vFMatematicas[j].coefC);
                vFMatematicas[j].delta=pow(vFMatematicas[j].coefB,2)-(4*vFMatematicas[j].coefA*vFMatematicas[j].coefC);

                if(vFMatematicas[j].delta>0)
                {
                    printf("Esta equação possui duas raizes reais\n");
                    printf("Sua resposta para x1: ");
                    scanf("%lf", &vFMatematicas[j].x1);
                    fflush(stdin);
                    printf("Sua resposta para x2: ");
                    scanf("%lf", &vFMatematicas[j].x2);
                    fflush(stdin);
                    vResultados[w].respostaUsuario = vFMatematicas[j].x1+vFMatematicas[j].x2;

                    vFMatematicas[j].x1C = trunc(((-vFMatematicas[j].coefB + sqrt(vFMatematicas[j].delta))/(2*vFMatematicas[j].coefA))*100)/100;
                    vFMatematicas[j].x2C = trunc(((-vFMatematicas[j].coefB - sqrt(vFMatematicas[j].delta))/(2*vFMatematicas[j].coefA))*100)/100;
                    vResultados[w].respostaCorreta = (vFMatematicas[j].x1C + vFMatematicas[j].x2C);
                }
                else
                {
                    printf("Esta equação só possui uma raiz real\n");
                    printf("Sua resposta para x1: ");
                    scanf("%lf", &vFMatematicas[j].x1);
                    fflush(stdin);
                    vFMatematicas[j].x2=0;
                    vResultados[w].respostaUsuario = vFMatematicas[j].x1+vFMatematicas[j].x2;

                    vFMatematicas[j].x1C = trunc(((-vFMatematicas[j].coefB + sqrt(vFMatematicas[j].delta))/(2*vFMatematicas[j].coefA))*100)/100;
                    vFMatematicas[j].x2C = 0;
                    vResultados[w].respostaCorreta = (vFMatematicas[j].x1C + vFMatematicas[j].x2C);
                }
                break;

            default:
                break;
            }

            vResultados[w].IDusuario = vUsuario[i].ID;
            vResultados[w].tipoTeste = 3;
            vResultados[w].opcaoTeste = vFMatematicas[j].codFuncoes;

            w++;
        }
        printf("\n\n");
        system("pause");
        system("cls");

        printf("-----------------\n");
        printf("Teste de Matrizes\n");
        printf("-----------------\n");

        for(j=0; j<5; j++)
        {
            switch(vMatriz[j].codTipoMatriz)
            {
            case 1:
//Apresentação das matrizes geradas_______________________________________________________________________________________

                printf("\nApresentando a matriz...\n");
                printf("=========================\n\n");

                for (l=0; l<5; l++)
                {
                    for (c=0; c<3; c++)
                    {
                        printf("%5.0lf", vMatriz[j].matriz[l][c]);   //o 5d serve para alinhar os números à direita e inserir um espaço entre eles, pois todos terão somente 2 dígitos
                    }
                    printf("\n\n");
                }

                printf("\n\nResponda a pergunta: \n");

                srand(clock());
                l = rand() % 5;
                c = rand() % 3;

                vMatriz[j].matrizInversa[l][c] = - vMatriz[j].matriz[l][c];

                vResultados[w].respostaCorreta = vMatriz[j].matrizInversa[l][c];
                printf("Qual o valor presente na linha %d, coluna %d da matriz INVERSA\n", l+1,c+1);
                printf("Digite sua resposta: ");
                scanf("%lf", &vResultados[w].respostaUsuario);
                break;

            case 2:

                printf("\nApresentando a matriz...\n");
                printf("=========================\n\n");

                for (l=0; l<5; l++)
                {
                    for (c=0; c<3; c++)
                    {
                        printf("%5.0lf", vMatriz[j].matriz[l][c]);   //o 5d serve para alinhar os números à direita e inserir um espaço entre eles, pois todos terão somente 2 dígitos
                    }
                    printf("\n\n");
                }

                for (c=0; c<3; c++)
                {
                    for (l=0; l<5; l++)
                    {
                        vMatriz[j].matrizTransposta[c][l] = vMatriz[j].matriz[l][c];
                    }
                }

                printf("\n\nResponda a pergunta: \n");

                srand(clock());
                l = rand() % 5;
                c = rand() % 3;

                vMatriz[j].matrizTransposta[c][l] = vMatriz[j].matriz[l][c];

                vResultados[w].respostaCorreta = vMatriz[j].matrizTransposta[c][l];
                printf("Qual o valor presente na linha %d, coluna %d da matriz TRANSPOSTA\n", c+1,l+1);
                printf("Digite sua resposta: ");
                scanf("%lf", &vResultados[w].respostaUsuario);
                break;

            default:
                break;
            }

            vResultados[w].IDusuario = vUsuario[i].ID;
            vResultados[w].tipoTeste = 4;
            vResultados[w].opcaoTeste = vMatriz[j].codTipoMatriz;

            w++;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    } //fechamento do for para troca de usuario

//*********RELATÓRIO DE RESULTADOS DOS TESTES REALIZADOS*********

    int tipoResultado;

    do
    {
        system("cls");
        printf("+--------------------------------------------------+\n");
        printf("|***RELATÓRIO DE RESULTADOS DOS TESTES APLICADOS***|\n");
        printf("+--------------------------------------------------+\n\n");
        printf("1 - Analítico\n");
        printf("2 - Sintético\n");
        printf("3 - Usuário com maior pontuação\n\n");

        printf("Como você gostaria de visualizar o relatório: ");
        scanf("%d", &tipoResultado);
        system("cls");

        switch(tipoResultado)
        {
        case 1:

            for(w=0; w<100; w++)
            {
                if(w<20)
                {
                    i=0;

                    if(w==0)
                    {
                        vUsuario[i].respostasCorretas=0;
                        vUsuario[i].respostasErradas=0;
                    }
                }

                if(w>=20 && w<40)
                {
                    i=1;

                    if(w==20)
                    {
                        vUsuario[i].respostasCorretas=0;
                        vUsuario[i].respostasErradas=0;
                    }
                }

                if(w>=40 && w<60)
                {
                    i=2;

                    if(w==40)
                    {
                        vUsuario[i].respostasCorretas=0;
                        vUsuario[i].respostasErradas=0;
                    }
                }

                if(w>=60 && w<80)
                {
                    i=3;

                    if(w==60)
                    {
                        vUsuario[i].respostasCorretas=0;
                        vUsuario[i].respostasErradas=0;
                    }
                }

                if(w>=80)
                {
                    i=4;

                    if(w==80)
                    {
                        vUsuario[i].respostasCorretas=0;
                        vUsuario[i].respostasErradas=0;
                    }
                }

                printf("Usuario: %s\n", vUsuario[i].nome);
                printf("Tipo de teste realizado: %s\n", tipoTeste[vResultados[w].tipoTeste-1]);

                if(vResultados[w].tipoTeste==1)
                    printf("Operacao escolhida: %s\n",operacoesMat[vResultados[w].opcaoTeste-1]);

                if(vResultados[w].tipoTeste==2)
                    printf("Operacao escolhida: %s\n",formasGeomet[vResultados[w].opcaoTeste-1]);

                if(vResultados[w].tipoTeste==3)
                    printf("Operacao escolhida: %s\n",funcoesMat[vResultados[w].opcaoTeste-1]);

                if(vResultados[w].tipoTeste==4)
                    printf("Operacao escolhida: %s\n",tipoMatriz[vResultados[w].opcaoTeste-1]);

                if(vResultados[w].respostaUsuario==vResultados[w].respostaCorreta)
                {
                    printf("RESPOSTA CORRETA\n\n");

                    vUsuario[i].respostasCorretas = vUsuario[i].respostasCorretas + 1;
                                    }
                else
                {
                    printf("RESPOSTA INCORRETA\n\n");

                    vUsuario[i].respostasErradas = vUsuario[i].respostasErradas +1;
                }
            } //fechamento do for do w

            system("pause");

            //*****************APRESENTAÇÃO DOS RESULTADOS***************************

            char rc, ri;
            int nq;

            for(w=0; w<100; w++)
            {
                switch(vResultados[w].IDusuario)
                {
                case 1:

                    i=0;
                    nq=1;

                    printf("\n\n+---------------------------------------------------------------------------------------------------------+\n");
                    printf(" Resultados do teste realizado pelo usuário: %s                                                          \n", vUsuario[i].nome);
                    printf("+-----------+------------------------+------------------------+--------------------+----------------------+\n");
                    printf("|  Questão  |     Tipo de teste      |        Operação        |  Resposta Correta  |  Resposta Incorreta  |\n");
                    printf("+-----------+------------------------+------------------------+--------------------+----------------------+\n");

                    for(w=0; w<20; w++)
                    {
                        if(vResultados[w].respostaUsuario==vResultados[w].respostaCorreta)
                        {
                            rc='X';
                            ri=' ';
                        }
                        else
                        {
                            rc=' ';
                            ri='X';
                        }

                        printf("|     %d     |           %d            |            %d           |          %c         |          %c           |\n", nq, vResultados[w].tipoTeste, vResultados[w].opcaoTeste, rc, ri);
                        printf("+----------------------------------------------------------------------------------------------------------\n");

                        nq++;
                    }
                    break;

                case 2:

                    i=1;
                    nq=1;

                    printf("\n\n+---------------------------------------------------------------------------------------------------------+\n");
                    printf("  Resultados do teste realizado pelo usuário: %s                                                           \n", vUsuario[i].nome);
                    printf("+-----------+------------------------+------------------------+--------------------+----------------------+\n");
                    printf("|  Questão  |     Tipo de teste      |        Operação        |  Resposta Correta  |  Resposta Incorreta  |\n");
                    printf("+-----------+------------------------+------------------------+--------------------+----------------------+\n");

                    for(w=20; w<40; w++)
                    {
                        if(vResultados[w].respostaUsuario==vResultados[w].respostaCorreta)
                        {
                            rc='X';
                            ri=' ';
                        }
                        else
                        {
                            rc=' ';
                            ri='X';
                        }

                        printf("|     %d     |           %d            |            %d           |          %c         |          %c           |\n", nq, vResultados[w].tipoTeste, vResultados[w].opcaoTeste, rc, ri);
                        printf("+---------------------------------------------------------------------------------------------------------\n");

                        nq++;
                    }
                    break;

                case 3:

                    i=2;
                    nq=1;

                    printf("\n\n+---------------------------------------------------------------------------------------------------------+\n");
                    printf("  Resultados do teste realizado pelo usuário: %s                                                           \n", vUsuario[i].nome);
                    printf("+-----------+------------------------+------------------------+--------------------+----------------------+\n");
                    printf("|  Questão  |     Tipo de teste      |        Operação        |  Resposta Correta  |  Resposta Incorreta  |\n");
                    printf("+-----------+------------------------+------------------------+--------------------+----------------------+\n");

                    for(w=40; w<60; w++)
                    {
                        if(vResultados[w].respostaUsuario==vResultados[w].respostaCorreta)
                        {
                            rc='X';
                            ri=' ';
                        }
                        else
                        {
                            rc=' ';
                            ri='X';
                        }

                        printf("|     %d     |           %d            |            %d           |          %c         |          %c           |\n", nq, vResultados[w].tipoTeste, vResultados[w].opcaoTeste, rc, ri);
                        printf("+---------------------------------------------------------------------------------------------------------\n");

                        nq++;
                    }
                    break;

                case 4:

                    i=3;
                    nq=1;

                    printf("\n\n+---------------------------------------------------------------------------------------------------------+\n");
                    printf("  Resultados do teste realizado pelo usuário: %s                                                           \n", vUsuario[i].nome);
                    printf("+-----------+------------------------+------------------------+--------------------+----------------------+\n");
                    printf("|  Questão  |     Tipo de teste      |        Operação        |  Resposta Correta  |  Resposta Incorreta  |\n");
                    printf("+-----------+------------------------+------------------------+--------------------+----------------------+\n");

                    for(w=60; w<80; w++)
                    {
                        if(vResultados[w].respostaUsuario==vResultados[w].respostaCorreta)
                        {
                            rc='X';
                            ri=' ';
                        }
                        else
                        {
                            rc=' ';
                            ri='X';
                        }

                        printf("|     %d     |           %d            |            %d           |          %c         |          %c           |\n", nq, vResultados[w].tipoTeste, vResultados[w].opcaoTeste, rc, ri);
                        printf("+---------------------------------------------------------------------------------------------------------\n");

                        nq++;
                    }
                    break;

                case 5:

                    i=4;
                    nq=1;

                    printf("\n\n+---------------------------------------------------------------------------------------------------------+\n");
                    printf("  Resultados do teste realizado pelo usuário: %s                                                           \n", vUsuario[i].nome);
                    printf("+-----------+------------------------+------------------------+--------------------+----------------------+\n");
                    printf("|  Questão  |     Tipo de teste      |        Operação        |  Resposta Correta  |  Resposta Incorreta  |\n");
                    printf("+-----------+------------------------+------------------------+--------------------+----------------------+\n");

                    for(w=80; w<100; w++)
                    {
                        if(vResultados[w].respostaUsuario==vResultados[w].respostaCorreta)
                        {
                            rc='X';
                            ri=' ';
                        }
                        else
                        {
                            rc=' ';
                            ri='X';
                        }

                        printf("|     %d     |           %d            |            %d           |          %c         |          %c           |\n", nq, vResultados[w].tipoTeste, vResultados[w].opcaoTeste, rc, ri);
                        printf("+---------------------------------------------------------------------------------------------------------\n");

                        nq++;
                    }
                    break;
                } //fechamendo do switch case dos resultados
            } //fechamento do for que percorre o vetor de resultados
            break;
            system("pause");

//*****************TOTALIZAÇÃO DOS RESULTADOS***************************

        case 2:

            printf("+---------------------------------------------+\n");
            printf("|      RESULTADOS SINTÉTICOS DOS TESTES       |\n");
            printf("+---------------------------------------------+\n\n");

            printf("| Respostas Corretas |  Respostas Incorretas  |\n");
            printf("+--------------------+------------------------+\n");

            for(i=0; i<5; i++)
            {
                printf("Usuario: %s\n", vUsuario[i].nome);
                printf("-----------------------------------------------\n");
                printf("|        %d           |           %d           |\n",vUsuario[i].respostasCorretas, vUsuario[i].respostasErradas);
                printf("-----------------------------------------------\n");
            }
            printf("\n\n");
            break;
            system("pause");

//**************MAIOR NOTA DOS TESTES************************************

        case 3:

            maiorNota = 0;

            for(i=0; i<5; i++)
            {
                if(vUsuario[i].respostasCorretas>maiorNota)
                    maiorNota = vUsuario[i].respostasCorretas;
                else
                    maiorNota = maiorNota;
            }

//**************USUÁRIO COM MAIOR NOTA DOS TESTES************************************

            strcpy (vencedor, vUsuario[0].nome);

            for(i=0; i<5; i++)
            {
                if(vUsuario[i].respostasCorretas==maiorNota)
                    strcpy (vencedor, vUsuario[i].nome);
            }
            printf("-------------------------------------------------------------------------------------\n");
            printf("O usuário com maior nota no teste foi: %s com %d acertos\n", vencedor, maiorNota);
            printf("-------------------------------------------------------------------------------------\n\n\n");
            break;

        } //Fechamento switch tipo Resultado
        system("pause");
        system("cls");

        printf("Gostaria de visualizar outro tipo de relatório?\n\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n\n");
        printf("Digite sua opção: ");
        scanf("%d", &novoRelatorio);
        system("cls");
    }
    while(novoRelatorio==1);

    printf("\n\n\n          **********OBRIGADO POR UTILIZAR O NOSSO PROGRAMA!**********\n\n\n");

} //chave de fechamento do intmain





