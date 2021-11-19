int desceTudo(pPECA peca, TABULEIRO tabuleiro)
{
    switch (peca->tipo)
    {
    case 1:
        return descida(peca, tabuleiro, Y - 1);
        break;
    case 2:
        switch (peca->rot)
        {
        case 0:
            return descida(peca, tabuleiro, Y - 3);
            break;
        case 1:
            return descida(peca, tabuleiro, Y);
            break;
        }
        break;
    case 3 ... 4:
        switch (peca->rot)
        {
        case 0:
            return descida(peca, tabuleiro, Y - 1);
            break;
        case 1:
            return descida(peca, tabuleiro, Y - 2);
            break;
        }
        break;
    case 5 ... 6:
        if (peca->rot == 0 || peca->rot == 2)
            return descida(peca, tabuleiro, Y - 2);
        if (peca->rot == 1 || peca->rot == 3)
            return descida(peca, tabuleiro, Y - 1);
        break;
    case 7:
        if (peca->rot == 0 || peca->rot == 2)
            return descida(peca, tabuleiro, Y - 1);
        if (peca->rot == 1 || peca->rot == 3)
            return descida(peca, tabuleiro, Y - 2);
        break;
    }
}

int descida(pPECA peca, TABULEIRO tabuleiro, int fundo)
{
    if (colisaoFinal(peca->pos.y - 1, fundo - 1) || colisaoPecaPecaY(tabuleiro, *peca, peca->pos.y + 1, peca->pos.x))
    {
        return 0;
    }
    else
    {
        peca->pos.y++;
        return 1 + descida(peca, tabuleiro, fundo);
    }
}
