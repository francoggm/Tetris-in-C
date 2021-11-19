#include <raylib.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int colisaoFinal(int py, int fundo)
{
    if (py == fundo)
    {
        return 1;
    }
    else
        return 0;
}

int colisaoPecaPecaY(TABULEIRO tabuleiro, PECA peca, int py, int px)
{
    if (px - peca.pos.x != 0)
        return 0;

    switch (peca.tipo)
    {
    case 1:
        if (tabuleiro.g[py + 1][peca.pos.x] || tabuleiro.g[py + 1][peca.pos.x + 1])
        {
            apagaPeca(peca, &tabuleiro);
            apagaQuadradosAdj(peca, &tabuleiro);
            temPeca = !temPeca;
            return 1;
        }
        else
            return 0;
        break;
    case 2:
        switch (peca.rot)
        {
        case 0:
            if (tabuleiro.g[py + 3][peca.pos.x])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 1:
            if (tabuleiro.g[py][peca.pos.x] || tabuleiro.g[py][peca.pos.x + 1] || tabuleiro.g[py][peca.pos.x + 2] || tabuleiro.g[py][peca.pos.x + 3])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        }
        break;
    case 3:
        switch (peca.rot)
        {
        case 0:
            if (tabuleiro.g[py + 1][peca.pos.x] || tabuleiro.g[py + 1][peca.pos.x + 1] || tabuleiro.g[py][peca.pos.x + 2])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 1:
            if (tabuleiro.g[py + 1][peca.pos.x] || tabuleiro.g[py + 2][peca.pos.x + 1])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        }
        break;
    case 4:
        switch (peca.rot)
        {
        case 0:
            if (tabuleiro.g[py][peca.pos.x] || tabuleiro.g[py + 1][peca.pos.x + 1] || tabuleiro.g[py + 1][peca.pos.x + 2])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 1:
            if (tabuleiro.g[py + 2][peca.pos.x] || tabuleiro.g[py + 1][peca.pos.x + 1])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        }
        break;
    case 5:
        switch (peca.rot)
        {
        case 0:
            if (tabuleiro.g[py + 2][peca.pos.x] || tabuleiro.g[py + 2][peca.pos.x + 1])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 1:
            if (tabuleiro.g[py + 1][peca.pos.x] || tabuleiro.g[py][peca.pos.x + 1] || tabuleiro.g[py][peca.pos.x + 2])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 2:
            if (tabuleiro.g[py][peca.pos.x] || tabuleiro.g[py + 2][peca.pos.x + 1])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 3:
            if (tabuleiro.g[py + 1][peca.pos.x] || tabuleiro.g[py + 1][peca.pos.x + 1] || tabuleiro.g[py + 1][peca.pos.x + 2])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        }
        break;
    case 6:
        switch (peca.rot)
        {
        case 0:
            if (tabuleiro.g[py + 2][peca.pos.x] || tabuleiro.g[py + 2][peca.pos.x + 1])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 1:
            if (tabuleiro.g[py + 1][peca.pos.x] || tabuleiro.g[py + 1][peca.pos.x + 1] || tabuleiro.g[py + 1][peca.pos.x + 2])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 2:
            if (tabuleiro.g[py + 2][peca.pos.x] || tabuleiro.g[py][peca.pos.x + 1])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 3:
            if (tabuleiro.g[py][peca.pos.x] || tabuleiro.g[py][peca.pos.x + 1] || tabuleiro.g[py + 1][peca.pos.x + 2])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        }
        break;
    case 7:
        switch (peca.rot)
        {
        case 0:
            if (tabuleiro.g[py][peca.pos.x] || tabuleiro.g[py + 1][peca.pos.x + 1] || tabuleiro.g[py][peca.pos.x + 2])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 1:
            if (tabuleiro.g[py + 1][peca.pos.x] || tabuleiro.g[py + 2][peca.pos.x + 1])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 2:
            if (tabuleiro.g[py + 1][peca.pos.x] || tabuleiro.g[py + 1][peca.pos.x + 1] || tabuleiro.g[py + 1][peca.pos.x + 2])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        case 3:
            if (tabuleiro.g[py + 2][peca.pos.x] || tabuleiro.g[py + 1][peca.pos.x + 1])
            {
                apagaPeca(peca, &tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
                temPeca = !temPeca;
                return 1;
            }
            else
                return 0;
            break;
        }
        break;
    }
}

int colisaoPecaPecaX(TABULEIRO tabuleiro, PECA peca, int px)
{
    int py = peca.pos.y, valx = px - peca.pos.x;
    if (valx == 0)
        return 0;
    switch (peca.tipo)
    {
    case 1:
        if (valx > 0)
        {
            if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px + 1])
                return 1;
            else
                return 0;
        }
        else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px])
            return 1;
        else
            return 0;
        break;
    case 2:
        switch (peca.rot)
        {
        case 0:
            if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px] || tabuleiro.g[py + 2][px] || tabuleiro.g[py + 3][px])
                return 1;
            else
                return 0;
            break;
        case 1:
            if (valx > 0)
                if (tabuleiro.g[py][px + 3])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px])
                return 1;
            else
                return 0;
            break;
        }
        break;
    case 3:
        switch (peca.rot)
        {
        case 0:
            if (valx > 0)
                if (tabuleiro.g[py][px + 2] || tabuleiro.g[py + 1][px + 1])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px])
                return 1;
            else
                return 0;
            break;
        case 1:
            if (valx > 0)
                if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px + 1] || tabuleiro.g[py + 2][px + 1])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px] || tabuleiro.g[py + 2][px + 1])
                return 1;
            else
                return 0;
            break;
        }
        break;
    case 4:
        switch (peca.rot)
        {
        case 0:
            if (valx > 0)
                if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px + 2])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px + 1])
                return 1;
            else
                return 0;
            break;
        case 1:
            if (valx > 0)
                if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px + 1] || tabuleiro.g[py + 2][px])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px] || tabuleiro.g[py + 2][px])
                return 1;
            else
                return 0;
            break;
        }
        break;
    case 5:
        switch (peca.rot)
        {
        case 0:
            if (valx > 0)
                if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px] || tabuleiro.g[py + 2][px + 1])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px] || tabuleiro.g[py + 2][px])
                return 1;
            else
                return 0;
            break;
        case 1:
            if (valx > 0)
                if (tabuleiro.g[py][px + 2] || tabuleiro.g[py + 1][px])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px])
                return 1;
            else
                return 0;
            break;
        case 2:
            if (valx > 0)
                if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px + 1] || tabuleiro.g[py + 2][px + 1])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px + 1] || tabuleiro.g[py + 2][px + 1])
                return 1;
            else
                return 0;
            break;
        case 3:
            if (valx > 0)
                if (tabuleiro.g[py][px + 2] || tabuleiro.g[py + 1][px + 2])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px + 2] || tabuleiro.g[py + 1][px])
                return 1;
            else
                return 0;
            break;
        }
        break;
    case 6:
        switch (peca.rot)
        {
        case 0:
            if (valx > 0)
                if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px + 1] || tabuleiro.g[py + 2][px + 1])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px + 1] || tabuleiro.g[py + 2][px])
                return 1;
            else
                return 0;
            break;
        case 1:
            if (valx > 0)
                if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px + 2])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px])
                return 1;
            else
                return 0;
            break;
        case 2:
            if (valx > 0)
                if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px] || tabuleiro.g[py + 2][px])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px] || tabuleiro.g[py + 2][px])
                return 1;
            else
                return 0;
            break;
        case 3:
            if (valx > 0)
                if (tabuleiro.g[py][px + 2] || tabuleiro.g[py + 1][px + 2])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px + 2])
                return 1;
            else
                return 0;
            break;
        }
        break;
    case 7:
        switch (peca.rot)
        {
        case 0:
            if (valx > 0)
                if (tabuleiro.g[py][px + 2] || tabuleiro.g[py + 1][px + 1])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px + 1])
                return 1;
            else
                return 0;
            break;
        case 1:
            if (valx > 0)
                if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px + 1] || tabuleiro.g[py + 2][px + 1])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px] || tabuleiro.g[py + 2][px + 1])
                return 1;
            else
                return 0;
            break;
        case 2:
            if (valx > 0)
                if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px + 2])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px + 1] || tabuleiro.g[py + 1][px])
                return 1;
            else
                return 0;
            break;
        case 3:
            if (valx > 0)
                if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px + 1] || tabuleiro.g[py + 2][px])
                    return 1;
                else
                    return 0;
            else if (tabuleiro.g[py][px] || tabuleiro.g[py + 1][px] || tabuleiro.g[py + 2][px])
                return 1;
            else
                return 0;
            break;
        }
        break;
    }
}

//colisões das peças
int verificaColisao(PECA peca, int py, int px, pTABULEIRO tabuleiro)
{ //py é a posição em y que a peça pretende ser deslocada e px é a posição que a peça pretende ser deslocada

    //a colisão será verificada de acordo com o tipo da forma
    switch (peca.tipo)
    {
    case 1: //quadrado
        if (colisaoFinal(py, Y - 1))
        {
            if (peca.dif == 3)
            {
                apagaPeca(peca, tabuleiro);
                apagaQuadradosAdj(peca, &tabuleiro);
            }
            temPeca = !temPeca;
        }
        if (py < Y - 1 && (px < X - 1 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
            return 1;
        else
            return 0;
        break;
    case 2: //I
        switch (peca.rot)
        {
        case 0:
            if (colisaoFinal(py, Y - 3))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }
                temPeca = !temPeca;
            }
            if (py < Y - 3 && (px < X && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;

            break;
        case 1:
            if (colisaoFinal(py, Y - 1))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y && (px < X - 3 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;

            break;
        }
        break;
    case 3: //S
        switch (peca.rot)
        {
        case 0:
            if (colisaoFinal(py, Y - 1))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 1 && (px < X - 2 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 1:
            if (colisaoFinal(py, Y - 2))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 2 && (px < X - 1 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;

            break;
        }
        break;
    case 4:
        switch (peca.rot)
        {
        case 0:
            if (colisaoFinal(py, Y - 1))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 1 && (px < X - 2 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 1:
            if (colisaoFinal(py, Y - 2))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 2 && (px < X - 1 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;

            break;
        }
        break;
    case 5: //L
        switch (peca.rot)
        {
        case 0:
            if (colisaoFinal(py, Y - 2))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 2 && (px < X - 1 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 1:
            if (colisaoFinal(py, Y - 2))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 1 && (px < X - 2 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 2:
            if (colisaoFinal(py, Y - 2))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 2 && (px < X - 1 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 3:
            if (colisaoFinal(py, Y - 1))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 1 && (px < X - 2 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        }
        break;
    case 6:
        switch (peca.rot)
        {
        case 0:
            if (colisaoFinal(py, Y - 2))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 2 && (px < X - 1 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 1:
            if (colisaoFinal(py, Y - 2))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 1 && (px < X - 2 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 2:
            if (colisaoFinal(py, Y - 2))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 2 && (px < X - 1 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 3:
            if (colisaoFinal(py, Y - 1))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 1 && (px < X - 2 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        }
        break;
    case 7: //T
        switch (peca.rot)
        {
        case 0:
            if (colisaoFinal(py, Y - 1))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 1 && (px < X - 2 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 1:
            if (colisaoFinal(py, Y - 2))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 2 && (px < X - 1 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 2:
            if (colisaoFinal(py, Y - 1))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 1 && (px < X - 2 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        case 3:
            if (colisaoFinal(py, Y - 2))
            {
                if (peca.dif == 3)
                {
                    apagaPeca(peca, tabuleiro);
                    apagaQuadradosAdj(peca, &tabuleiro);
                }

                temPeca = !temPeca;
            }
            if (py < Y - 2 && (px < X - 1 && px >= 0) && !colisaoPecaPecaY(*tabuleiro, peca, py, px) && !colisaoPecaPecaX(*tabuleiro, peca, px))
                return 1;
            else
                return 0;
            break;
        }
        break;
    }
}

int verificaColisaoRotacao(PECA peca, TABULEIRO tabuleiro, int tipo)
{
    int py = peca.pos.y, px = peca.pos.x;
    switch (peca.tipo)
    {
    case 2: //I
        switch (peca.rot)
        {
        case 0:
            if ((py < Y - 1 && px < X - 3) && (!tabuleiro.g[py][px + 3] && !tabuleiro.g[py][px + 2] && !tabuleiro.g[py][px + 1]))
                return 1;
            else
                return 0;
            break;
        case 1:
            if ((py < Y - 3 && px < X - 1) && (!tabuleiro.g[py + 3][px] && !tabuleiro.g[py + 2][px] && !tabuleiro.g[py + 1][px]))
                return 1;
            else
                return 0;
            break;
        }
        break;
    case 3: //S
        switch (peca.rot)
        {
        case 0:
            if ((py < Y - 2 && px < X - 1) && !tabuleiro.g[py + 2][px])
                return 1;
            else
                return 0;
            break;
        case 1:
            if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py][px + 1] && !tabuleiro.g[py][px + 2]))
                return 1;
            else
                return 0;
            break;
        }
        break;
    case 4: //S inverso
        switch (peca.rot)
        {
        case 0:
            if ((py < Y - 2 && px < X - 1) && !tabuleiro.g[py + 2][px])
                return 1;
            else
                return 0;
            break;
        case 1:
            if ((py < Y - 1 && px < X - 2) && !tabuleiro.g[py + 1][px + 2])
                return 1;
            else
                return 0;
            break;
        }
        break;
    case 5: //L
        if (tipo == -1)
        {
            switch (peca.rot)
            {
            case 0:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py][px + 2] && !tabuleiro.g[py + 1][px + 2]) && !tabuleiro.g[py + 1][px + 1])
                    return 1;
                else
                    return 0;
                break;
            case 1:
                if ((py < Y - 2 && px < X - 2) && (!tabuleiro.g[py + 2][px + 1] && !tabuleiro.g[py + 2][px]))
                    return 1;
                else
                    return 0;
                break;
            case 2:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py + 1][px] && !tabuleiro.g[py][px + 2]))
                    return 1;
                else
                    return 0;
                break;
            case 3:
                if ((py < Y - 2 && px < X - 1) && (!tabuleiro.g[py][px + 1] && !tabuleiro.g[py + 2][px + 1] && !tabuleiro.g[py][px]))
                    return 1;
                else
                    return 0;
                break;
            }
        }
        if (tipo == 1)
        {
            switch (peca.rot)
            {
            case 0:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py][px + 1] && !tabuleiro.g[py][px + 2]))
                    return 1;
                else
                    return 0;
                break;
            case 1:
                if ((py < Y - 2 && px < X - 1) && (!tabuleiro.g[py + 1][px + 1] && !tabuleiro.g[py + 2][px + 1]))
                    return 1;
                else
                    return 0;
                break;
            case 2:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py][px + 2] && !tabuleiro.g[py + 1][px + 2]))
                    return 1;
                else
                    return 0;
                break;
            case 3:
                if ((py < Y - 2 && px < X - 2) && (!tabuleiro.g[py][px] && !tabuleiro.g[py + 2][px + 1] && !tabuleiro.g[py + 2][px]))
                    return 1;
                else
                    return 0;
                break;
            }
        }
        break;
    case 6: //L inverso
        if (tipo == -1)
        {
            switch (peca.rot)
            {
            case 0:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py][px] && !tabuleiro.g[py][px + 2] && !tabuleiro.g[py + 1][px + 2]))
                    return 1;
                else
                    return 0;
                break;
            case 1:
                if ((py < Y - 2 && px < X - 1) && !tabuleiro.g[py + 2][px] && !tabuleiro.g[py + 2][px + 1] && !tabuleiro.g[py][px + 1])
                    return 1;
                else
                    return 0;
                break;
            case 2:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py + 1][px + 2] && !tabuleiro.g[py + 1][px + 1]))
                    return 1;
                else
                    return 0;
                break;
            case 3:
                if ((py < Y - 2 && px < X - 1) && (!tabuleiro.g[py + 1][px] && !tabuleiro.g[py + 1][px]))
                    return 1;
                else
                    return 0;
                break;
            }
        }
        if (tipo == 1)
        {
            switch (peca.rot)
            {
            case 0:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py + 1][px + 2] && !tabuleiro.g[py + 1][px]))
                    return 1;
                else
                    return 0;
                break;
            case 1:
                if ((py < Y - 2 && px < X - 1) && (!tabuleiro.g[py][px + 1] && !tabuleiro.g[py + 2][px]))
                    return 1;
                else
                    return 0;
                break;
            case 2:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py][px + 2] && !tabuleiro.g[py + 1][px + 2]))
                    return 1;
                else
                    return 0;
                break;
            case 3:
                if ((py < Y - 2 && px < X - 1) && !tabuleiro.g[py + 2][px] && !tabuleiro.g[py + 2][px + 1] && !tabuleiro.g[py + 1][px + 1])
                    return 1;
                else
                    return 0;
                break;
            }
        }
        break;
    case 7: //T
        if (tipo == -1)
        {
            switch (peca.rot)
            {
            case 0:
                if ((py < Y - 2 && px < X - 1) && (!tabuleiro.g[py + 1][px] && !tabuleiro.g[py + 2][px]))
                    return 1;
                else
                    return 0;
                break;
            case 1:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py][px] && !tabuleiro.g[py][px + 2]))
                    return 1;
                else
                    return 0;
                break;
            case 2:
                if (py < Y - 2 && px < X - 1 && (!tabuleiro.g[py][px] && !tabuleiro.g[py + 2][px]))
                    return 1;
                else
                    return 0;
                break;
            case 3:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py][px + 1] && !tabuleiro.g[py + 1][px + 2]))
                    return 1;
                else
                    return 0;
                break;
            }
        }
        if (tipo == 1)
        {
            switch (peca.rot)
            {
            case 0:
                if ((py < Y - 2 && px < X - 1) && (!tabuleiro.g[py + 1][px] && !tabuleiro.g[py + 2][px + 1]))
                    return 1;
                else
                    return 0;
                break;
            case 1:
                if ((py < Y - 1 && px < X - 2) && !tabuleiro.g[py + 1][px + 2])
                    return 1;
                else
                    return 0;
                break;
            case 2:
                if (py < Y - 2 && px < X - 1 && (!tabuleiro.g[py][px] && !tabuleiro.g[py + 2][px]))
                    return 1;
                else
                    return 0;
                break;
            case 3:
                if ((py < Y - 1 && px < X - 2) && (!tabuleiro.g[py][px + 1] && !tabuleiro.g[py][px + 2]))
                    return 1;
                else
                    return 0;
                break;
            }
        }
        break;
    }
    return 0;
}