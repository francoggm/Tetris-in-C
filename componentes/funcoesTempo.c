#include <time.h>


void inicia(pTEMPO temp)
{
    temp->inicio = clock();
}

void para(pTEMPO temp)
{
    temp->fim = clock();
}

int tempo(TEMPO temp)
{
    return (clock() - temp.inicio) / CLOCKS_PER_SEC;
}