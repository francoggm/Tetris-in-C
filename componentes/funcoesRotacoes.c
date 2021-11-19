void setaRotacao(pPECA peca, int tipo)
{
    switch (peca->tipo)
    {
    case 1: //quadrado
        peca->rot = 0;
        break;
    case 2 ... 4:       //I, S, S invertido
        if (tipo == -1) //sentido anti-horário
            if (peca->rot < 0)
                peca->rot = 1;
        if (tipo == 1)
            if (peca->rot >= 2)
                peca->rot = 0;
        break;
    case 5 ... 7: //L, L invertido, T
        if (tipo == -1)
            if (peca->rot < 0)
                peca->rot = 3;
        if (tipo == 1)
            if (peca->rot >= 4)
                peca->rot = 0;
    }
}

void rotacionaPeca(PECA peca, pTABULEIRO tabuleiro, int tipo)
{
    int i, j;
    switch (peca.tipo)
    {
    case 1:
        break;
    case 2: //I
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 4; i++)
                tabuleiro->g[peca.pos.y][peca.pos.x + i] = 0;
            break;
        case 1:
            for (i = 0; i < 4; i++)
                tabuleiro->g[peca.pos.y + i][peca.pos.x] = 0;
            break;
        }
        break;
    case 3: //S
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 1) && !(i == 2 && j == 0))
                        tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
            break;
        case 1:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 0) && !(i == 1 && j == 2))
                        tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
            break;
        }
        break;
    case 4: //S inverso
        switch (peca.rot)
        {
        case 0:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 2; j++)
                    if (!(i == 0 && j == 0) && !(i == 2 && j == 1))
                        tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
            break;
        case 1:
            for (i = 0; i < 2; i++)
                for (j = 0; j < 3; j++)
                    if (!(i == 0 && j == 2) && !(i == 1 && j == 0))
                        tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
            break;
        }
        break;
    case 5: //L
        if (tipo == -1)
        {
            switch (peca.rot)
            {
            case 0:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 1 && j == 1) && !(i == 1 && j == 2))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 1:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 1 && j == 0) && !(i == 2 && j == 0))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 2:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 0 && j == 0) && !(i == 0 && j == 1))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 3:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 0 && j == 1) && !(i == 1 && j == 1))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            }
        }
        if (tipo == 1)
        {
            switch (peca.rot)
            {
            case 0:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 0 && j == 0) && !(i == 0 && j == 1))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 1:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 0 && j == 1) && !(i == 1 && j == 1))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 2:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 1 && j == 1) && !(i == 1 && j == 2))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 3:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 1 && j == 0) && !(i == 2 && j == 0))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
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
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 0 && j == 1) && !(i == 0 && j == 2))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 1:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 1 && j == 1) && !(i == 2 && j == 1))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 2:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 1 && j == 0) && !(i == 1 && j == 1))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 3:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 0 && j == 0) && !(i == 1 && j == 0))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            }
        }
        if (tipo == 1)
        {
            switch (peca.rot)
            {
            case 0:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 1 && j == 0) && !(i == 1 && j == 1))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 1:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 0 && j == 0) && !(i == 1 && j == 0))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 2:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 0 && j == 1) && !(i == 0 && j == 2))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 3:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 1 && j == 1) && !(i == 2 && j == 1))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
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
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 0 && j == 0) && !(i == 2 && j == 0))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 1:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 0 && j == 0) && !(i == 0 && j == 2))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 2:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 0 && j == 1) && !(i == 2 && j == 1))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 3:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 1 && j == 0) && !(i == 1 && j == 2))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            }
        }
        if (tipo == 1)
        {
            switch (peca.rot)
            {
            case 0:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 0 && j == 1) && !(i == 2 && j == 1))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 1:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 1 && j == 0) && !(i == 1 && j == 2))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 2:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 2; j++)
                        if (!(i == 0 && j == 0) && !(i == 2 && j == 0))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            case 3:
                for (i = 0; i < 2; i++)
                    for (j = 0; j < 3; j++)
                        if (!(i == 0 && j == 0) && !(i == 0 && j == 2))
                            tabuleiro->g[peca.pos.y + i][peca.pos.x + j] = 0;
                break;
            }
        }
        break;
    }
}