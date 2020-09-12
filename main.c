#include <stdio.h>
#include "BSTAluno.h"
int main() {
    FILE *arq = NULL;
    tipoapontador no;
    inicializa(&no);
    int cont = 0;
    double gp1 = 0, gp2 = 0, gp3 = 0;

    readFile(arq, &no);

    notasDecre(no);

    printf("\n%d alunos\n", qtdAlunos(no, &cont));
    cont = 0;

    maiorNota(no);
    menorNota(no);
    printf("\n\n");

    somaNotasGp(no, &gp1, &gp2, &gp3);
    gpMaiorNota(gp1, gp2, gp3);


    printf("\n---Qtd alunos com media: %d\n", qtdAlunosMediaFT(no, &cont));
}