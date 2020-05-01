#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <Windows.h>
//Struct cards-start
typedef struct
{
    char nome[200];
    int status;
    int posicao;
} Cartas;
Cartas carta[12];
//Struct cards-end

void gamePlace() //Function for the Game place
{
    //Game place-start
    printf("\t\t\t\t    1 \t    2 \t    3 \t    4 \n");
    printf("\t\t\t\t");
    printf(".................................\n");

    printf("\t\t\t    A   ");
    printf("|  A1\t|  A2\t|  A3\t|  A4\t|\n");
    printf("\t\t\t\t");
    printf("|.......|.......|.......|.......|\n");

    printf("\t\t\t    B   ");
    printf("|  B1\t|  B2\t|  B3\t|  B4\t|\n");
    printf("\t\t\t\t");
    printf("|.......|.......|.......|.......|\n");

    printf("\t\t\t    C   ");
    printf("|  C1\t|  C2\t|  C3\t|  C4\t|\n");
    printf("\t\t\t\t");
    printf("|.......|.......|.......|.......|\n");
    // Game place-end
}

int main()
{

    //Declaration-start
    int respostaMenu;

    char imagem[12][30] = {" PEIXE ", " PEIXE ",
                           "  GATO ", "  GATO ",
                           "  VACA ", "  VACA ",
                           "PASSARO", "PASSARO",
                           " COBRA ", " COBRA ",
                           "  TATU ", "  TATU "};
    int i;
    int j;
    int error = 0;
    int randon[12];
    int temporaria;
    int posicaoTemp[2];
    char escolha[30][30];
    int sec = 5;
    int min = 00;
    int pontoJogador = 0;
    int pontoCPU = 0;

    //Declaration-end

    printf("\n\n\t\t\t\t");
    printf("  Bem-Vindo ao Jogo da memoria!\n\n");

    gamePlace();

    //Game menu-start
    printf("\n\t\t\t\t   __________________________\n\t\t\t\t  |\t\t\t     |");
    printf("\n\t\t\t\t  |\t");
    printf("Jogar - 0");

    printf("\t     |\n\t\t\t\t  |\t\t\t     |\n\t\t\t\t  |\t");
    printf("Instrucoes - 1");

    printf("\t     |\n\t\t\t\t  |\t\t\t     |\n\t\t\t\t  |\t");
    printf("Sair - 2");
    printf("\t     |\n\t\t\t\t  |__________________________|\n\t\t\t\t\t");

    do //Detect ERROR-start
    {

        printf("\n\t\t\t\t\tResposta:\t");

        scanf("%i", &respostaMenu);

        if (respostaMenu != 0 && respostaMenu != 1 && respostaMenu != 2)
        {
            printf("\n\t\t\t\t   __________________________\n\t\t\t\t  |\t\t\t     |");
            printf("\n\t\t\t\t  |");
            printf("  Use um comando valido!");
            printf("  |\n\t\t\t\t  |__________________________|\n\t\t\t\t\t");
        }

    } while (respostaMenu != 0 && respostaMenu != 1 && respostaMenu != 2); //Detect ERROR-end

    //Game menu-end

    //Options-start
    switch (respostaMenu)
    {
    case 0: //Game option
        system("cls");
        srand(time(NULL));

        //Randon cards-start
        for (i = 0; i < 12; i++)
        {

            do
            {
                error = 0;
                randon[i] = (rand() % 12);

                for (j = 0; j <= i; j++)
                {

                    if (randon[i] == randon[j])
                    {

                        error++;
                    }
                }

            } while (error > 1);

            error = 0;

            temporaria = randon[i];

            strcpy(carta[i].nome, imagem[temporaria]);

            carta[i].status = 0;

            carta[i].posicao = i;
        }
        //Randon cards-end
        do
        {
            printf("\n\n\n\n\n\n");
            //Game place-start
            printf("\t\t\t\t    1 \t    2 \t    3 \t    4 \n");
            printf("\t\t\t\t");
            printf(".................................\n");

            printf("\t\t\t    A   ");

            for (i = 0; i < 4; i++)
            {
                switch (carta[i].status)
                {
                case 0:
                    printf("| VIRADA");
                    break;
                case 1:
                    printf("|%s", carta[i].nome);
                    break;

                default:
                    printf("Erro desconhecido-Tente reiniciar o programa");
                    return 1;
                    break;
                }
            }

            printf("|\n\t\t\t\t");
            printf("|.......|.......|.......|.......|\n");

            printf("\t\t\t    B   ");
            for (i = 4; i < 8; i++)
            {
                switch (carta[i].status)
                {
                case 0:
                    printf("| VIRADA");
                    break;
                case 1:
                    printf("|%s", carta[i].nome);
                    break;

                default:
                    printf("Erro desconhecido-Tente reiniciar o programa");
                    return 1;
                    break;
                }
            }
            printf("|\n\t\t\t\t");
            printf("|.......|.......|.......|.......|\n");

            printf("\t\t\t    C   ");
            for (i = 8; i < 12; i++)
            {
                switch (carta[i].status)
                {
                case 0:
                    printf("| VIRADA");
                    break;
                case 1:
                    printf("|%s", carta[i].nome);
                    break;

                default:
                    printf("Erro desconhecido-Tente reiniciar o programa");
                    return 1;
                    break;
                }
            }
            printf("|\n\t\t\t\t");
            printf("|.......|.......|.......|.......|\n");
            // Game place-end

            do
            {
                do
                {
                    error = 0;
                    printf("\n  \t\t\t");
                    printf("Escolha a primeira posicao da carta a ser escolhida:\n   \t\t\t");
                    scanf("%s", &escolha[0]);
                    escolha[0] == strupr(escolha[0]);

                    printf("\n  \t\t\t");
                    printf("Escolha a segunda posicao da carta a ser escolhida:\n   \t\t\t");
                    scanf("%s", &escolha[1]);
                    escolha[1] == strupr(escolha[1]);
                    if (strcmp(escolha[0], escolha[1]) == 0)
                    {
                        printf("\n  \t\t\t");
                        printf("As duas posicoes nao podem ser iguais!\n");
                    }
                } while (strcmp(escolha[0], escolha[1]) == 0);

                for (i = 0; i < 2; i++)
                {

                    if (strcmp(escolha[i], "A1") == 0)
                    {
                        strcpy(escolha[i], carta[0].nome);
                        posicaoTemp[i] = carta[0].posicao;
                    }
                    else if (strcmp(escolha[i], "A2") == 0)
                    {
                        strcpy(escolha[i], carta[1].nome);
                        posicaoTemp[i] = carta[1].posicao;
                    }
                    else if (strcmp(escolha[i], "A3") == 0)
                    {
                        strcpy(escolha[i], carta[2].nome);
                        posicaoTemp[i] = carta[2].posicao;
                    }
                    else if (strcmp(escolha[i], "A4") == 0)
                    {
                        strcpy(escolha[i], carta[3].nome);
                        posicaoTemp[i] = carta[3].posicao;
                    }
                    else if (strcmp(escolha[i], "B1") == 0)
                    {
                        strcpy(escolha[i], carta[4].nome);
                        posicaoTemp[i] = carta[4].posicao;
                    }
                    else if (strcmp(escolha[i], "B2") == 0)
                    {
                        strcpy(escolha[i], carta[5].nome);
                        posicaoTemp[i] = carta[5].posicao;
                    }
                    else if (strcmp(escolha[i], "B3") == 0)
                    {
                        strcpy(escolha[i], carta[6].nome);
                        posicaoTemp[i] = carta[6].posicao;
                    }
                    else if (strcmp(escolha[i], "B4") == 0)
                    {
                        strcpy(escolha[i], carta[7].nome);
                        posicaoTemp[i] = carta[7].posicao;
                    }
                    else if (strcmp(escolha[i], "C1") == 0)
                    {
                        strcpy(escolha[i], carta[8].nome);
                        posicaoTemp[i] = carta[8].posicao;
                    }
                    else if (strcmp(escolha[i], "C2") == 0)
                    {
                        strcpy(escolha[i], carta[9].nome);
                        posicaoTemp[i] = carta[9].posicao;
                    }
                    else if (strcmp(escolha[i], "C3") == 0)
                    {
                        strcpy(escolha[i], carta[10].nome);
                        posicaoTemp[i] = carta[10].posicao;
                    }
                    else if (strcmp(escolha[i], "C4") == 0)
                    {
                        strcpy(escolha[i], carta[11].nome);
                        posicaoTemp[i] = carta[11].posicao;
                    }
                    else
                    {
                        printf("\n  \t\t\t");
                        printf("Posicao %i invalida , tente novamente!\n", i + 1);
                        error++;
                    }
                }
            } while (error != 0);

            if (strcmp(escolha[0], escolha[1]) == 0)
            {
                printf("\n  \t\t\t");
                printf("Voce fez um ponto, parabens!!\n");

                pontoJogador++;
                carta[posicaoTemp[0]].status = 1;
                carta[posicaoTemp[1]].status = 1;
            }
            else
            {
                system("cls");
                printf("\n  \t\t\t");
                printf("Que pena!As imagens nao sao iguais :(\n");
                carta[posicaoTemp[0]].status = 1;
                carta[posicaoTemp[1]].status = 1;
                sec = 5;
                min = 00;

                //Game place-start
                printf("\t\t\t\t    1 \t    2 \t    3 \t    4 \n");
                printf("\t\t\t\t");
                printf(".................................\n");

                printf("\t\t\t    A   ");

                for (i = 0; i < 4; i++)
                {
                    switch (carta[i].status)
                    {
                    case 0:
                        printf("| VIRADA");
                        break;
                    case 1:
                        printf("|%s", carta[i].nome);
                        break;

                    default:
                        printf("Erro desconhecido-Tente reiniciar o programa");
                        return 1;
                        break;
                    }
                }

                printf("|\n\t\t\t\t");
                printf("|.......|.......|.......|.......|\n");

                printf("\t\t\t    B   ");
                for (i = 4; i < 8; i++)
                {
                    switch (carta[i].status)
                    {
                    case 0:
                        printf("| VIRADA");
                        break;
                    case 1:
                        printf("|%s", carta[i].nome);
                        break;

                    default:
                        printf("Erro desconhecido-Tente reiniciar o programa");
                        return 1;
                        break;
                    }
                }
                printf("|\n\t\t\t\t");
                printf("|.......|.......|.......|.......|\n");

                printf("\t\t\t    C   ");
                for (i = 8; i < 12; i++)
                {
                    switch (carta[i].status)
                    {
                    case 0:
                        printf("| VIRADA");
                        break;
                    case 1:
                        printf("|%s", carta[i].nome);
                        break;

                    default:
                        printf("Erro desconhecido-Tente reiniciar o programa");
                        return 1;
                        break;
                    }
                }
                printf("|\n\t\t\t\t");
                printf("|.......|.......|.......|.......|\n");
                // Game place-end

                while (sec > 0)
                {
                    printf("\n  \t\t\t");
                    printf("%ds", sec);
                    Sleep(1000);
                    sec--;

                    if (sec == 20)
                    {
                        sec = 0;
                        min--;
                    }
                }
                printf("\n  \t\t\t");
                printf("0s\n");
                system("cls");

                carta[posicaoTemp[0]].status = 0;
                carta[posicaoTemp[1]].status = 0;
            }
        } while (pontoJogador + pontoCPU < 6);
        break;
    case 1: //Instructions option
        system("cls");
        printf("Voce escolheu instrucoes!");
        break;

    case 2: //Exit option
        system("cls");
        gamePlace();
        printf("\n  \t\t\t\t      ");
        printf("Voce escolheu sair!");
        return 0;
        break;

    default: //Catch error

        printf("Erro desconhecido - Reinicie o programa.");
        return 1;
        break;
    }

    return 0;
}