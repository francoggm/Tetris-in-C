void dificuldade(pTABULEIRO tabuleiro)
{
    if ((tabuleiro->pontuacao % 2) == 0)
    {
        if (!(tabuleiro->dificuldade == 1))
            tabuleiro->dificuldade--;
    }
}

void salvaJogo(pPECA peca, pTABULEIRO tabuleiro)
{
    FILE *arquivo;

    if (!(arquivo = fopen(SALVO, "w+b")))
    {
        //exibir mensagem de erro
    }
    else
    {
        fwrite(peca, sizeof(PECA), 1, arquivo);
        fwrite(peca + 1, sizeof(PECA), 1, arquivo);
        fwrite(tabuleiro, sizeof(TABULEIRO), 1, arquivo);
        fclose(arquivo);
        //exibir mensagem de salvamento
    }
}

void carregaJogo(pPECA peca, pTABULEIRO tabuleiro)
{
    FILE *arquivo;

    if (!(arquivo = fopen(SALVO, "rb")))
    {
        //exibir mensagem de erro
    }
    else
    {
        fread(peca, sizeof(PECA), 1, arquivo);
        fread(peca + 1, sizeof(PECA), 1, arquivo);
        fread(tabuleiro, sizeof(TABULEIRO), 1, arquivo);
        fclose(arquivo);
        //exibir mensagem de sucesso
    }
}

void acabaJogo(int larguraTela, int alturaTela, pTABULEIRO tabuleiro, pRANK ranking)
{
    int qtd;
    gameOver = true;
    DrawText("Fim de jogo!", 500, 300, 40, RED);
    DrawText(TextFormat("Sua pontuação foi: %d", tabuleiro->pontuacao), 465, 350, 30, RED);
    DrawText("Pressione SPACE para iniciar um novo jogo", 500, 400, 10, WHITE);

    /*
    qtd = puxaPontuacao(ranking);
    if(qtd == 0)
        adicionaPontuacaoPrimeiraVez(ranking, tabuleiro);
    else
        adicionaPontuacao(ranking, tabuleiro);
    
    desenhaPontuacao(ranking);
    */

    if (IsKeyPressed(KEY_SPACE))
        resetaJogo(tabuleiro);
}

void resetaJogo(pTABULEIRO tabuleiro)
{
    int i, j;
    for (i = 0; i < Y; i++)
        for (j = 0; j < X; j++)
            tabuleiro->g[i][j] = 0;
    tabuleiro->pontuacao = 0;
    tabuleiro->dificuldade = 21;
    gameOver = false;
    first = true;
    temPeca = false;
}