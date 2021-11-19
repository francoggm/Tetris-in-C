#include <raylib.h>

//funções para o calculo da posição no grid
int pX(int x, int posiInit)
{
    return posiInit + (x * TAM); //a partir da posição inicial soma com o valor de x deslocamentos
}

int pY(int y)
{
    return 1 + MARGEM + (y * TAM); //a partir da margem soma com o valor de y deslocamentos
}

void preencheMatriz(PECA peca, pTABULEIRO matriz, int vy, int vx)
{ //vy= velho y, vx=velho x
    int i, j;
    switch (peca.tipo)
    {       //de acordo com o tipo da forma passada por parametro
    case 1: // Quadrado
        //laco de repetição para apagar o tabuleiro nas posições antigas do quadrado
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                matriz->g[vy + i][vx + j] = 0; //por isso que apaga usando vy e vx

        //laco de repeticao para escrever a nova posição do quadrado no tabuleiro
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
        break;
    //para os outros casos segue a mesma logica alterando apenas o preenchimento na matriz de acordo com a forma das peças
    case 2: // I
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 4; i++)
                matriz->g[vy + i][vx] = 0;
            for (i = 0; i < 4; i++)
                matriz->g[peca.pos.y + i][peca.pos.x] = 1;
            break;
        case 1:
            for (i = 0; i < 4; i++)
                matriz->g[vy][vx + i] = 0;
            for (i = 0; i < 4; i++)
                matriz->g[peca.pos.y][peca.pos.x + i] = 1;
            break;
        }
        break;
    case 3: // S
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 0) && !(i == 1 && j == 2))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 0) && !(i == 1 && j == 2))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 1:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 1) && !(i == 2 && j == 0))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 1) && !(i == 2 && j == 0))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        }
        break;
    case 4: // S invertido
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 2) && !(i == 1 && j == 0))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 2) && !(i == 1 && j == 0))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 1:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 0) && !(i == 2 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;

            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 0) && !(i == 2 && j == 1))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        }

        break;
    case 5: // L
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 1) && !(i == 1 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 1) && !(i == 1 && j == 1))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 1:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 1 && j == 1) && !(i == 1 && j == 2))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 1 && j == 1) && !(i == 1 && j == 2))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 2:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 1 && j == 0) && !(i == 2 && j == 0))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 1 && j == 0) && !(i == 2 && j == 0))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 3:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 0) && !(i == 0 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 0) && !(i == 0 && j == 1))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        }

        break;
    case 6: // L invertido

        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 0) && !(i == 1 && j == 0))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 0) && !(i == 1 && j == 0))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 1:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 1) && !(i == 0 && j == 2))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 1) && !(i == 0 && j == 2))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 2:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 1 && j == 1) && !(i == 2 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 1 && j == 1) && !(i == 2 && j == 1))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 3:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 1 && j == 0) && !(i == 1 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 1 && j == 0) && !(i == 1 && j == 1))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        }
        break;
    case 7: // T
        /*if (peca.rot==0 || peca.rot==2){
                for (i = 0; i < 2; i++)
                        for(j = 0; j < 3; j++)
                            matriz->g[vy+i][vx+j]=0;
            }
            if (peca.rot==1 || peca.rot==3){
                for (i = 0; i < 3; i++)
                        for(j = 0; j < 2; j++)
                            matriz->g[vy+i][vx+j]=0;
            }*/
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 1 && j == 0) && !(i == 1 && j == 2))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 1 && j == 0) && !(i == 1 && j == 2))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 1:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 0) && !(i == 2 && j == 0))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 0) && !(i == 2 && j == 0))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 2:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 0) && !(i == 0 && j == 2))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 0) && !(i == 0 && j == 2))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        case 3:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 1) && !(i == 2 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 1) && !(i == 2 && j == 1))
                        matriz->g[peca.pos.y + i][peca.pos.x + j] = 1;
            break;
        }

        break;
    }
}

void apagaPeca(PECA peca, pTABULEIRO matriz)
{
    int i, j, vy = peca.pos.y, vx = peca.pos.x;

    switch (peca.tipo)
    {       //de acordo com o tipo da forma passada por parametro
    case 1: // Quadrado
        //laco de repetição para apagar o tabuleiro nas posições antigas do quadrado
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                matriz->g[vy + i][vx + j] = 0; //por isso que apaga usando vy e vx
        break;
    //para os outros casos segue a mesma logica alterando apenas o preenchimento na matriz de acordo com a forma das peças
    case 2: // I
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 4; i++)
                matriz->g[vy + i][vx] = 0;
            break;
        case 1:
            for (i = 0; i < 4; i++)
                matriz->g[vy][vx + i] = 0;
            break;
        }
        break;
    case 3: // S
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 0) && !(i == 1 && j == 2))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 1:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 1) && !(i == 2 && j == 0))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        }
        break;
    case 4: // S invertido
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 2) && !(i == 1 && j == 0))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 1:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 0) && !(i == 2 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        }

        break;
    case 5: // L
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 1) && !(i == 1 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 1:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 1 && j == 1) && !(i == 1 && j == 2))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 2:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 1 && j == 0) && !(i == 2 && j == 0))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 3:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 0) && !(i == 0 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        }

        break;
    case 6: // L invertido

        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 0) && !(i == 1 && j == 0))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 1:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 1) && !(i == 0 && j == 2))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 2:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 1 && j == 1) && !(i == 2 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 3:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 1 && j == 0) && !(i == 1 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        }
        break;
    case 7: // T
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 1 && j == 0) && !(i == 1 && j == 2))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 1:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 0) && !(i == 2 && j == 0))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 2:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 0) && !(i == 0 && j == 2))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        case 3:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 1) && !(i == 2 && j == 1))
                        matriz->g[vy + i][vx + j] = 0;
            break;
        }

        break;
    }
}

void initPeca(pTABULEIRO tabuleiro, pPECA peca, pTEMPO time)
{ //paça o endereço de tabuleiro e peca no parametro para ser usado ponteiros
    //setando x e y da peça
    if (first)
    {
        tabuleiro->pontuacao = 0;
        peca[0].tipo = GetRandomValue(1, 7);
        peca[0].dif = GetRandomValue(1, 2);
        peca[1].tipo = GetRandomValue(1, 7);
        peca[1].dif = GetRandomValue(1, 2);
        first = !first;
    }
    else
    {
        peca[0].tipo = peca[1].tipo;
        peca[0].dif = peca[1].dif;
        peca[1].tipo = GetRandomValue(1, 7);
        peca[1].dif = GetRandomValue(1, 2);
    }

    int i, j;
    peca[0].pos.y = 0;
    peca[0].pos.x = 5;
    peca[0].rot = 0;
    switch (peca[0].tipo)
    {       //de acordo com o tipo da peça será feito o desenho da forma
    case 1: //Quadrado
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                if (tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j])
                {
                    acabaJogo(screenWidth, screenHeight, &tabuleiro);
                    return;
                }
                else
                    tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j] = 1; //preenche matriz do tabuleiro de acordo com a forma para ser desenhada
            }                                                               //seleciona a cor da peca
        peca[0].cor = BLUE;
        temPeca = !temPeca; //muda a variavel que informa se tem peça para true
        break;
    //segue a mesma logica para as outras formas
    case 2: //I
        for (i = 0; i < 4; i++)
        {
            if (tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x])
            {
                acabaJogo(screenWidth, screenHeight, &tabuleiro);
                return;
            }

            else
                tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x] = 1;
        }
        peca[0].cor = RED;
        temPeca = !temPeca;
        break;

    case 3: //S
        peca[0].pos.x--;
        for (i = 0; i < 2; i++)
            for (j = 0; j < 3; j++)
                if (!(i == 0 && j == 0) && !(i == 1 && j == 2))
                {
                    if (tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j])
                    {
                        acabaJogo(screenWidth, screenHeight, &tabuleiro);
                        return;
                    }

                    else
                        tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j] = 1;
                }
        peca[0].cor = YELLOW;
        temPeca = !temPeca;
        break;

    case 4: //S invertido
        peca[0].pos.x--;
        for (i = 0; i < 2; i++)
            for (j = 0; j < 3; j++)
            {
                if (!(i == 0 && j == 2) && !(i == 1 && j == 0))
                {
                    if (tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j])
                    {
                        acabaJogo(screenWidth, screenHeight, &tabuleiro);
                        return;
                    }

                    else
                        tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j] = 1;
                }
            }
        peca[0].cor = PINK;
        temPeca = !temPeca;
        break;

    case 5: //L
        for (i = 0; i < 3; i++)
            for (j = 0; j < 2; j++)
                if (!(i == 0 && j == 1) && !(i == 1 && j == 1))
                {
                    if (tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j])
                    {
                        acabaJogo(screenWidth, screenHeight, &tabuleiro);
                        return;
                    }

                    else
                        tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j] = 1;
                }

        peca[0].cor = PURPLE;
        temPeca = !temPeca;
        break;

    case 6: //L invertido
        for (i = 0; i < 3; i++)
            for (j = 0; j < 2; j++)
                if (!(i == 0 && j == 0) && !(i == 1 && j == 0))
                {
                    if (tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j])
                    {
                        acabaJogo(screenWidth, screenHeight, &tabuleiro);
                        return;
                    }
                    else
                        tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j] = 1;
                }

        peca[0].cor = GREEN;
        temPeca = !temPeca;
        break;

    case 7: //T
        peca[0].pos.x--;
        for (i = 0; i < 2; i++)
            for (j = 0; j < 3; j++)
                if (!(i == 1 && j == 0) && !(i == 1 && j == 2))
                {
                    if (tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j])
                    {
                        acabaJogo(screenWidth, screenHeight, &tabuleiro);
                        return;
                    }
                    else
                        tabuleiro->g[peca[0].pos.y + i][peca[0].pos.x + j] = 1;
                }

        peca[0].cor = MAROON;
        temPeca = !temPeca;
        break;
    }
}

void verificaLinhaCompleta(pTABULEIRO tabuleiro)
{
    int cont = 0, i, j;
    DrawText(TextFormat("Pontuacao: %d", tabuleiro->pontuacao), 50, 200, 40, WHITE);
    for (i = 0; i < Y; i++)
    {
        for (j = 0; j < X; j++)
        {
            if (tabuleiro->g[i][j] == 1)
            {
                cont++;
            }
        }
        if (cont == X)
        {
            apagaLinha(i, tabuleiro);
            redesenhaTabuleiro(i, tabuleiro);
            tabuleiro->pontuacao++;
            dificuldade(tabuleiro);
            i--;
        }
        cont = 0;
    }
}

void apagaLinha(int y, pTABULEIRO tabuleiro)
{
    int j;
    for (j = 0; j < X; j++)
        tabuleiro->g[y][j] = 0;
}

void redesenhaTabuleiro(int y, pTABULEIRO tabuleiro)
{
    int j, i;
    for (i = y; i > 0; i--)
        for (j = 0; j < X; j++)
            if (tabuleiro->g[i][j])
            {
                tabuleiro->g[i + 1][j] = 1;
                tabuleiro->g[i][j] = 0;
            }
}

void apagaQuadradosAdj(PECA peca, pTABULEIRO tabuleiro)
{
    int py = peca.pos.y, px = peca.pos.x;
    switch (peca.tipo)
    {
    case 1:
        if (px == 0)
        {
            tabuleiro->g[py + 2][px] = 0;
            tabuleiro->g[py + 2][px + 1] = 0;
            tabuleiro->g[py][px + 2] = 0;
            tabuleiro->g[py + 1][px + 2] = 0;
            tabuleiro->g[py - 1][px] = 0;
            tabuleiro->g[py - 1][px + 1] = 0;
        }
        if (px == X - 2)
        {
            tabuleiro->g[py + 2][px] = 0;
            tabuleiro->g[py + 2][px + 1] = 0;
            tabuleiro->g[py][px - 1] = 0;
            tabuleiro->g[py + 1][px - 1] = 0;
            tabuleiro->g[py - 1][px] = 0;
            tabuleiro->g[py - 1][px + 1] = 0;
        }
        if (!py == Y - 2)
        {
            tabuleiro->g[py][px + 2] = 0;
            tabuleiro->g[py + 1][px + 2] = 0;
            tabuleiro->g[py][px - 1] = 0;
            tabuleiro->g[py + 1][px - 1] = 0;
            tabuleiro->g[py - 1][px] = 0;
            tabuleiro->g[py - 1][px + 1] = 0;
        }

        /*for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                    if(px==0 && j == 0){
                    tabuleiro->g[i][j+1];*/

        break;
    case 2:
        switch (peca.rot)
        {
        case 0:
            tabuleiro->g[py][px + 1] = 0;
            break;
        case 1:
            break;
        }

        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    }
}