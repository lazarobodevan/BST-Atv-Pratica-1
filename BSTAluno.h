//
// Created by lazarus on 12/09/20.
//
#include <stdio.h>
typedef struct {
    char nome[20];
    int matricula;
    int grupo;
    double nota;
}TAluno;

typedef struct tipoNo *tipoapontador;
typedef struct tipoNo{
    TAluno aluno;
    tipoapontador esq, dir;
}tipoNo;

void inicializaAluno(TAluno *aluno);

void readFile(FILE *file, tipoapontador *no);

void inicializa(tipoapontador *no);
void insere(tipoapontador *no, TAluno aluno);
void notasDecre(tipoapontador no); //ordem comecando da direita
int qtdAlunos(tipoapontador no, int *qtd);
void maiorNota(tipoapontador no);
void menorNota(tipoapontador no);
void somaNotasGp(tipoapontador no, double *gp1, double *gp2, double *gp3);
void gpMaiorNota(double gp1, double gp2, double gp3);
int qtdAlunosMediaFT(tipoapontador no, int *cont); //qtd de alunos com media 6/10 no forum tematico
