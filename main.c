#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Autor: Alexandre Fernandes RA25080 - 2CTi 2019

int main()
{
    int sair = -1;
    int senha = 0, senhaChamada = 0, ctrl = 1;
    char confirma;
    Fila * bencaoMat = cria();
    Fila * bencaoEspir = cria();

    do {
        system("cls");
        printf("TENDA DOS MILAGRES\n\n");
        printf("1. Retirar Senha Para Obter Bencao Material\n");
        printf("2. Retirar Senha Para Obter Bencao Espiritual\n");
        printf("3. Conceder Bencao Material\n");
        printf("4. Conceder Bencao Espiritual\n");
        printf("5. Mostrar Lista Para Bencao Material\n");
        printf("6. Mostrar Lista Para Bencao Espiritual\n");
        printf("0. Fechar tenda dos milagres\n");
        printf("\nPessoas na fila para bencao material: %d", conta(bencaoMat));
        printf("\nPessoas na fila para bencao material: %d\n\n", conta(bencaoEspir));
        printf("Escolha:_ ");
        scanf("%d", &sair);
        system("cls");

        switch (sair) {
            case 1:
                senha = insere(bencaoMat);
                printf("Senha --M%d-- retirada com sucesso. Aguarde ser chamado!\n\n\n", senha);
                system("pause");
                break;
            case 2:
                senha = insere(bencaoEspir);
                printf("Senha --E%d-- retirada com sucesso. Aguarde ser chamado!\n\n\n", senha);
                system("pause");
                break;
            case 3:
                senhaChamada = retira(bencaoMat);
                imprimeSenha(senhaChamada,'M');
                break;
            case 4:
                senhaChamada = retira(bencaoEspir);
                imprimeSenha(senhaChamada,'E');
                break;
            case 5:
                imprime(bencaoMat);
                system("pause");
                break;
            case 6:
                imprime(bencaoEspir);
                system("pause");
                break;
            case 0:
                if (conta(bencaoMat) != 0 || conta(bencaoEspir) != 0) {
                    do {
                        printf("Ainda ha senha a ser atendida!\n");
                        printf("Deseja mesmo encerrar as atividades? [s/n]_ ");
                        fflush(stdin);
                        scanf("%c",&confirma);


                        switch (confirma) {
                            case 's':
                                printf("\n\n-- Ate a proxima! --\n\n");
                                libera(bencaoEspir);
                                libera(bencaoMat);
                                exit(0);
                                break;
                            case 'n':
                                sair = -1;
                                ctrl = 0;
                                break;
                            default:
                                printf("\n\nEntrada invalida! Digite 's' ou 'n'!\n\n");
                                break;
                        }
                    } while (ctrl != 0);
                } else {
                    libera(bencaoEspir);
                    libera(bencaoMat);
                }
                break;
        }
    } while (sair != 0);

    return 0;
}
