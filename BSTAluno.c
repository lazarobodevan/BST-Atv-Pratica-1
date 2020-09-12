//
// Created by lazarus on 12/09/20.
//

#include "BSTAluno.h"
#include <string.h>
#include <stdlib.h>

void inicializaAluno(TAluno *aluno){
    aluno = (TAluno*) malloc(sizeof(TAluno));
}

void readFile(FILE *file, tipoapontador *no){
    file = fopen("alunos.txt", "r");
    if(file == NULL){
        printf("Ja to cancelada mesmo kkkkkkkkkkkkkkkkk\n");
        return;
    }

    char auxNome[20];
    int auxGp;
    double auxNota;
    int auxMat;
    TAluno aluno;

    int qtdLidos = 0;
    while (1) {
        inicializaAluno(&aluno);

        fscanf(file, "%s - %d - %d - %lf", auxNome, &auxMat, &auxGp, &auxNota); //leitura e atribuicao

        if(feof(file)){
            printf("---- Fim da linha -----\n");
            break;
        }

        strcpy(&auxNome[strlen(auxNome)], "\0"); //insercao de \0 na ultima posicao para indicar fim da string

        strcpy(aluno.nome, auxNome);
        aluno.matricula = auxMat;
        aluno.grupo = auxGp;
        aluno.nota = auxNota;

        insere(no, aluno);
        qtdLidos++;
    }
    printf("\n%d alunos lidos!\n", qtdLidos);


}

void inicializa(tipoapontador *no){
    *no = NULL;
}
void insere(tipoapontador *no, TAluno aluno){
    if(*no == NULL){
        *no = (tipoapontador) malloc(sizeof(tipoNo));
        strcpy((*no)->aluno.nome, aluno.nome);
        (*no)->aluno.matricula = aluno.matricula;
        (*no)->aluno.grupo = aluno.grupo;
        (*no)->aluno.nota = aluno.nota;
        (*no)->esq = NULL;
        (*no)->dir = NULL;
        printf("Aluno inserido!\n");
        return;
    }

    if(aluno.nota < (*no)->aluno.nota){
        printf("Esquerda\n");
        insere(&(*no)->esq, aluno);
    }
    if(aluno.nota > (*no)->aluno.nota){
        printf("Direita\n");
        insere(&(*no)->dir, aluno);
    }

}
void notasDecre(tipoapontador no){ //ordem comecando da direita
    if(no != NULL){
        notasDecre(no->dir);
        printf("-----\n");
        printf("Nome:      %s\n", no->aluno.nome);
        printf("Grupo:     %d\n", no->aluno.grupo);
        printf("Matricula: %d\n", no->aluno.matricula);
        printf("Nota:      %.2lf\n", no->aluno.nota);
        notasDecre(no->esq);
    }
}
int qtdAlunos(tipoapontador no, int *cont){

    if(no != NULL){
        qtdAlunos(no->dir, cont);
        (*cont)++;
        qtdAlunos(no->esq, cont);
    }
    return *cont;
}
void maiorNota(tipoapontador no){
    //maior nota
    /*if(no != NULL){
        maiorNota(no->dir);
        printf("--- Maior nota: %lf\n", no->aluno.nota);
        return;
    }
     */
    tipoapontador aux = no;
    while(no->dir != NULL){
        aux = no->dir;
        no = no->dir;
    }
    printf("\n--- Maior nota: %.2lf\n", aux->aluno.nota);

}

void menorNota(tipoapontador no){
    tipoapontador aux = no;
    while(no->esq != NULL){
        aux = no->esq;
        no = no->esq;
    }
    printf("\n--- Menor nota: %.2lf\n", aux->aluno.nota);
}

void somaNotasGp(tipoapontador no, double *gp1, double *gp2, double *gp3){
    if(no != NULL){
        if(no->aluno.grupo == 1)
            *gp1 += no->aluno.nota;
        else
            if(no->aluno.grupo == 2)
                *gp2 += no->aluno.nota;
            else
                *gp3 += no->aluno.nota;

        somaNotasGp(no->dir, gp1, gp2, gp3);
        somaNotasGp(no->esq, gp1, gp2, gp3);
    }
}

void gpMaiorNota(double gp1, double gp2, double gp3){
    if(gp1 > gp2 && gp1 > gp3)
        printf("Grupo 1 possui maiores notas: %.2lf\n", gp1);
    else if(gp2 > gp1 && gp2 > gp3)
        printf("Grupo 2 possui maiores notas: %.2lf\n", gp2);
    else
        printf("Grupo 3 possui maiores notas: %.2lf\n", gp3);
    printf("----Resumo de notas:\n");
    printf("GP1: %lf\n", gp1);
    printf("GP2: %lf\n", gp2);
    printf("GP3: %lf\n", gp3);

}

int qtdAlunosMediaFT(tipoapontador no, int *cont){ //qtd de alunos com media > 6 no forum tematico
    if(no != NULL){
        if(no->aluno.nota >= 6){
            (*cont)++;
        }
        qtdAlunosMediaFT(no->dir, cont);
        qtdAlunosMediaFT(no->esq, cont);
    }
    return *cont;
}
