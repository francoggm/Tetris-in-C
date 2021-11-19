#include <raylib.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "componentes/setup.c"

#include "componentes/menuSelecao.c"
#include "componentes/funcoesTempo.c"
#include "componentes/funcoesColisoes.c"
#include "componentes/funcoesDesenhos.c"
#include "componentes/funcoesTabuleiro.c"
#include "componentes/funcoesRotacoes.c"
#include "componentes/funcoesJogo.c"
#include "componentes/funcoesFuncionalidade.c"

//void desenhaPontuacao(pRANK);

//int puxaPontuacao(pRANK);

//void adicionaPontuacaoPrimeiraVez(pRANK, pTABULEIRO);

//void adicionaPontuacao(pRANK, pTABULEIRO);

//void salvaPontuacao(pRANK);

//bool puxaPontuacao(pRANK);

//void adicionaPontuacao(pRANK, pTABULEIRO);

//void quicksort(pRANK, int);

//int particiona(pRANK, int);

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;
    int dist, i, j, linha, coluna, metade = ((X * TAM) / 2), tamLinha = X * TAM, IniGrid = (screenWidth / 2) - metade, ydesce = 0, val, opcao = 0, jogoCarregado;
    PECA peca[2];
    TABULEIRO tabuleiro;
    TEMPO time;
    IMAGEM imagens;
    RANK ranking[MAXPONTUACAO];

    //inicialização padrão do raylib
    InitWindow(screenWidth, screenHeight, "Tetris");
    Image paleatorio = LoadImage(NOMEALEATORIO);
    Image pbomba = LoadImage(NOMEBOMBA);
    ImageResize(&paleatorio, TAM, TAM);
    ImageResize(&pbomba, TAM, TAM);
    imagens.pecaAleatoria = LoadTextureFromImage(paleatorio);
    imagens.pecaBomba = LoadTextureFromImage(pbomba);
    UnloadImage(paleatorio);
    UnloadImage(pbomba);
    
    while (!WindowShouldClose())
    {
        SetTargetFPS(15);
        BeginDrawing();

        ClearBackground(BLACK);
        desenhaMenu(screenWidth);
        jogoCarregado = 1;
        opcao = menuSelecao();
        if (opcao == 1)
        {
            EndDrawing();
            pausado = false;
            first = true;
            temPeca = false;
            gameOver = false;
            tabuleiro.dificuldade = 30;

            //laço para zerar a matriz tabuleiro
            for (i = 0; i < Y; i++)
                for (j = 0; j < X; j++)
                    tabuleiro.g[i][j] = 0;

            while (!WindowShouldClose())
            {
                BeginDrawing();
                DrawTexture(imagens.pecaAleatoria, 10, 10, WHITE);
                SetTargetFPS(15);
                ClearBackground(BLACK);

                //Inicializações

                funcionalidadeTeclas();
                quadradoProxPeca(screenWidth, screenHeight, metade);
                verificaLinhaCompleta(&tabuleiro);
                val = 0;

                if (!temPeca)
                {
                    for (j = 0; j < X; j++)
                    {
                        if (tabuleiro.g[0][j])
                            val++;
                    }
                    if (val != 0)
                        acabaJogo(screenWidth, screenHeight, &tabuleiro, ranking);
                    else
                    {
                        time.inicio = clock();
                        initPeca(&tabuleiro, peca, &time); //função passando por parametro o endereço da struct tabuleiro e da peca
                    }
                }
                else
                    desenhaProximaPeca(peca[1], screenWidth, screenHeight, metade, imagens);

                if (!gameOver)
                {

                    if (IsKeyPressed(KEY_ENTER))
                    {
                        if (pausado == false)
                            pausado = true;
                        else
                            pausado = false;
                    }

                    if (!pausado)
                    {

                        for (i = 0; i < Y; i++)
                            for (j = 0; j < X; j++)
                                if (tabuleiro.g[i][j] == 1)
                                    desenhaPeca(peca[0], pX(j, IniGrid), pY(i), imagens); //passa por parametro a struct peca e a posição calculada de x e y
                        if (!first)
                        {
                            if (temPeca)
                            {
                                if ((float)(clock() - time.inicio) / CLOCKS_PER_SEC >= (0.15 * tabuleiro.dificuldade))
                                {

                                    if (verificaColisao(peca[0], peca[0].pos.y + 1, peca[0].pos.x, &tabuleiro))
                                    { //para que o movimento realmente aconteça ele verifica se não há colisão no movimento esperado, portanto passa peca.pos.y+1 nesse caso
                                        peca[0].pos.y++;
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y - 1, peca[0].pos.x); //passa por parametro a struct peca o endereco do tabuleiro e as novas posições para y e x
                                        time.inicio = clock();
                                    }
                                }
                                else
                                {
                                    if (IsKeyDown(KEY_DOWN))
                                    {
                                        if (verificaColisao(peca[0], peca[0].pos.y + 1, peca[0].pos.x, &tabuleiro))
                                        { //para que o movimento realmente aconteça ele verifica se não há colisão no movimento esperado, portanto passa peca.pos.y+1 nesse caso
                                            peca[0].pos.y++;
                                            preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y - 1, peca[0].pos.x); //passa por parametro a struct peca o endereco do tabuleiro e as novas posições para y e x
                                        }
                                        //}
                                    }
                                }

                                if (IsKeyDown(KEY_LEFT))
                                {
                                    if (verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x - 1, &tabuleiro))
                                    { //similar com o caso anterior porem passando x-1 para o movimento da esquerda
                                        peca[0].pos.x--;
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x + 1); //similar com o caso anterior
                                    }
                                }

                                if (IsKeyDown(KEY_RIGHT))
                                    if (verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x + 1, &tabuleiro))
                                    { //similar com os casos anteriores porem passando x+1 para o movimento a direita
                                        peca[0].pos.x++;
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x - 1); //similar com os casos anteriores
                                    }

                                if (IsKeyPressed(KEY_UP))
                                {
                                    ydesce = desceTudo(&peca, tabuleiro);
                                    preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y - ydesce, peca[0].pos.x);
                                }

                                //Sentido Horario
                                if (IsKeyDown(KEY_X))
                                {
                                    SetTargetFPS(12);
                                    if (peca[0].dif == 2){
                                apagaPeca(peca[0], &tabuleiro);
                                do
                                {
                                    peca[0].tipo = GetRandomValue(1, 7);
                                } while (!verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x, &tabuleiro));
                                preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                            }else
                            if (verificaColisaoRotacao(peca[0], tabuleiro, 1))
                            {
                                peca[0].rot++;
                                setaRotacao(&peca, 1);
                                rotacionaPeca(peca[0], &tabuleiro, 1);
                                preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                            }
                                }

                                //Sentido Anti-horario
                                if (IsKeyDown(KEY_Z))
                                {
                                    SetTargetFPS(12);
                                    if (peca[0].dif == 2){
                                apagaPeca(peca[0], &tabuleiro);
                                do
                                {
                                    peca[0].tipo = GetRandomValue(1, 7);
                                } while (!verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x, &tabuleiro));
                                preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                            }else
                            if (verificaColisaoRotacao(peca[0], tabuleiro, -1))
                            {
                                peca[0].rot--;
                                setaRotacao(&peca, -1);
                                rotacionaPeca(peca[0], &tabuleiro, -1);
                                preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                            }
                                }

                                if(IsKeyPressed(KEY_R))
                                {
                                    //acabaJogo(screenWidth, screenHeight, &tabuleiro, ranking);
                                    resetaJogo(&tabuleiro);
                                }

                                if (IsKeyDown(KEY_S))
                                {
                                    salvaJogo(&peca, &tabuleiro);
                                }

                                if (IsKeyDown(KEY_L))
                                {
                                    carregaJogo(&peca, &tabuleiro);
                                }
                            }
                        }
                        else
                            first = false;

                        /*------------------------------------------------------------------------------------*/
                        //desenho do grid
                        //linha
                        for (i = 0; i <= Y; i++)
                        {
                            dist = (TAM * i) + MARGEM;                                                              //calcula a distancia entre as linhas
                            DrawLine((screenWidth / 2) - metade, dist, (screenWidth / 2) + metade, dist, RAYWHITE); //desenha a linha
                        }
                        //coluna
                        for (i = 0; i <= X; i++)
                        {
                            dist = (TAM * i);                                               //calcula a distancia entre as colunas
                            coluna = (int)(((screenWidth / 2)) - metade) + dist;            //soma a distancia a partir de 1/4 da tela
                            DrawLine(coluna, MARGEM, coluna, (TAM * Y) + MARGEM, RAYWHITE); //desenha coluna
                        }
                    }
                    else
                    {
                        DrawText("Jogo Pausado!", 420, 300, 40, YELLOW);
                        DrawText("Pressione ENTER para voltar", 490, 350, 10, WHITE);
                    }
                }
                EndDrawing();
            }
        }
        else if (opcao == 2)
        {
            EndDrawing();
            pausado = false;
            first = true;
            temPeca = false;
            gameOver = false;
            tabuleiro.dificuldade = 30;

            //laço para zerar a matriz tabuleiro
            for (i = 0; i < Y; i++)
                for (j = 0; j < X; j++)
                    tabuleiro.g[i][j] = 0;

            

            while (!WindowShouldClose())
            {
                BeginDrawing();
                SetTargetFPS(15);
                ClearBackground(BLACK);
                
                //Inicializações

                funcionalidadeTeclas();
                quadradoProxPeca(screenWidth, screenHeight, metade);
                verificaLinhaCompleta(&tabuleiro);
                val = 0;

                if (!temPeca)
                {
                    for (j = 0; j < X; j++)
                    {
                        if (tabuleiro.g[0][j])
                            val++;
                    }
                    if (val != 0)
                        acabaJogo(screenWidth, screenHeight, &tabuleiro, ranking);
                    else
                    {
                        time.inicio = clock();
                        initPeca(&tabuleiro, peca, &time); //função passando por parametro o endereço da struct tabuleiro e da peca
                    }
                }
                else
                    desenhaProximaPeca(peca[1], screenWidth, screenHeight, metade, imagens);

                if (!gameOver)
                {

                    if (IsKeyPressed(KEY_ENTER))
                    {
                        if (pausado == false)
                            pausado = true;
                        else
                            pausado = false;
                    }

                    if (!pausado)
                    {

                        for (i = 0; i < Y; i++)
                            for (j = 0; j < X; j++)
                                if (tabuleiro.g[i][j] == 1)
                                    desenhaPeca(peca[0], pX(j, IniGrid), pY(i), imagens); //passa por parametro a struct peca e a posição calculada de x e y
                        if (!first)
                        {
                            if (temPeca)
                            {
                                if ((float)(clock() - time.inicio) / CLOCKS_PER_SEC >= (0.15 * tabuleiro.dificuldade))
                                {

                                    if (verificaColisao(peca[0], peca[0].pos.y + 1, peca[0].pos.x, &tabuleiro))
                                    { //para que o movimento realmente aconteça ele verifica se não há colisão no movimento esperado, portanto passa peca.pos.y+1 nesse caso
                                        peca[0].pos.y++;
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y - 1, peca[0].pos.x); //passa por parametro a struct peca o endereco do tabuleiro e as novas posições para y e x
                                        time.inicio = clock();
                                    }
                                }
                                else
                                {
                                    if (IsKeyDown(KEY_DOWN))
                                    {
                                        if (verificaColisao(peca[0], peca[0].pos.y + 1, peca[0].pos.x, &tabuleiro))
                                        { //para que o movimento realmente aconteça ele verifica se não há colisão no movimento esperado, portanto passa peca.pos.y+1 nesse caso
                                            peca[0].pos.y++;
                                            preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y - 1, peca[0].pos.x); //passa por parametro a struct peca o endereco do tabuleiro e as novas posições para y e x
                                        }
                                        //}
                                    }
                                }

                                if (IsKeyDown(KEY_LEFT))
                                {
                                    if (verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x - 1, &tabuleiro))
                                    { //similar com o caso anterior porem passando x-1 para o movimento da esquerda
                                        peca[0].pos.x--;
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x + 1); //similar com o caso anterior
                                    }
                                }

                                if (IsKeyDown(KEY_RIGHT))
                                    if (verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x + 1, &tabuleiro))
                                    { //similar com os casos anteriores porem passando x+1 para o movimento a direita
                                        peca[0].pos.x++;
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x - 1); //similar com os casos anteriores
                                    }

                                if (IsKeyPressed(KEY_UP))
                                {
                                    ydesce = desceTudo(&peca, tabuleiro);
                                    preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y - ydesce, peca[0].pos.x);
                                }

                                //Sentido Horario
                                if (IsKeyDown(KEY_X))
                                {
                                    SetTargetFPS(12);
                                    if (peca[0].dif == 2){
                                apagaPeca(peca[0], &tabuleiro);
                                do
                                {
                                    peca[0].tipo = GetRandomValue(1, 7);
                                } while (!verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x, &tabuleiro));
                                preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                            }else
                            if (verificaColisaoRotacao(peca[0], tabuleiro, 1))
                            {
                                peca[0].rot++;
                                setaRotacao(&peca, 1);
                                rotacionaPeca(peca[0], &tabuleiro, 1);
                                preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                            }
                                }

                                //Sentido Anti-horario
                                if (IsKeyDown(KEY_Z))
                                {
                                    SetTargetFPS(12);
                                    if (peca[0].dif == 2){
                                apagaPeca(peca[0], &tabuleiro);
                                do
                                {
                                    peca[0].tipo = GetRandomValue(1, 7);
                                } while (!verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x, &tabuleiro));
                                preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                            }else
                            if (verificaColisaoRotacao(peca[0], tabuleiro, -1))
                            {
                                peca[0].rot--;
                                setaRotacao(&peca, -1);
                                rotacionaPeca(peca[0], &tabuleiro, -1);
                                preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                            }
                                }

                                if(IsKeyPressed(KEY_R))
                                {
                                    //acabaJogo(screenWidth, screenHeight, &tabuleiro, ranking);
                                    resetaJogo(&tabuleiro);
                                }

                                if (IsKeyDown(KEY_S))
                                {
                                    salvaJogo(&peca, &tabuleiro);
                                }

                                if (IsKeyDown(KEY_L))
                                {
                                    carregaJogo(&peca, &tabuleiro);
                                }
                            }
                        }
                        else
                        {
                            
                            first = false;
                        }

                        /*------------------------------------------------------------------------------------*/
                        //desenho do grid
                        //linha
                        for (i = 0; i <= Y; i++)
                        {
                            dist = (TAM * i) + MARGEM;                                                              //calcula a distancia entre as linhas
                            DrawLine((screenWidth / 2) - metade, dist, (screenWidth / 2) + metade, dist, RAYWHITE); //desenha a linha
                        }
                        //coluna
                        for (i = 0; i <= X; i++)
                        {
                            dist = (TAM * i);                                               //calcula a distancia entre as colunas
                            coluna = (int)(((screenWidth / 2)) - metade) + dist;            //soma a distancia a partir de 1/4 da tela
                            DrawLine(coluna, MARGEM, coluna, (TAM * Y) + MARGEM, RAYWHITE); //desenha coluna
                        }
                    }
                    else
                    {
                        DrawText("Jogo Pausado!", 420, 300, 40, YELLOW);
                        DrawText("Pressione ENTER para voltar", 490, 350, 10, WHITE);
                    }
                }

                EndDrawing();
                if(jogoCarregado){
                    carregaJogo(&peca, &tabuleiro);
                    jogoCarregado = 0;
                }
                    
            }
        }
        else if (opcao == 4)
        {
            return 0;
        }
        EndDrawing();
    }

    return 0;
}

/*
int puxaPontuacao(pRANK rank){
    FILE *arquivo = NULL;
    if(arquivo = fopen(TABELA, "rb")){
        fclose(arquivo);
        return 1;
    } else {
        return 0;
    }
}


void adicionaPontuacaoPrimeiraVez(pRANK rank, pTABULEIRO tabuleiro){
    int quant = 1;
    FILE *arquivo = NULL;
    //rank[0].nome = pegaNome();
    rank[0].pontuacao = tabuleiro->pontuacao;

    if(arquivo = fopen(TABELA, "w+b")){
        fwrite(&quant, sizeof(int), 1, arquivo);
        fwrite(rank + 0, sizeof(RANK), 1, arquivo);
        fclose(arquivo);

    } else
        DrawText("Erro em ler arquivo!", 0, 50, 10, WHITE);
}

void adicionaPontuacao(pRANK rank, pTABULEIRO tabuleiro){
    int quant, i;
    FILE *arquivo = NULL;
    if(arquivo = fopen(TABELA, "w+b")){
        fread(&quant, sizeof(int), 1, arquivo);
        quant++;
        fwrite(&quant, sizeof(int), 1, arquivo);
        for(i = 0; i < quant - 1; i++){
            fread(rank + i, sizeof(RANK), 1, arquivo);
        }
        rank[quant].pontuacao = tabuleiro->pontuacao;
        //rank[qtd].nome = pegaNome();
        //ordenaVetor(rank, qtd);
        for(i = 0; i < quant; i ++){
            fwrite(rank + i, sizeof(RANK), 1, arquivo);
        }
        fclose(arquivo);
    } else
        DrawText("Falha ao abrir arquivo de pontuacoes!", 0, 20, 10, WHITE);
}



void adicionaPontuacao(pRANK ranking, pTABULEIRO tabuleiro){
    int qtd = 0, i, val = 1;
    //char nome[MAXNOME] = "";
    RANK aux;
    //aux.nome = "";
    if (!puxaPontuacao(ranking)){
        val=0;
    }
    if (val){
        
        qtd=ranking[0].qtd;
        if ((qtd < MAXPONTUACAO) || (tabuleiro->pontuacao > ranking[qtd-1].pontuacao)){
            //scanf("%s", &nome);//pegar o nome, nao sei como vamos fazer isso
        }else{
            //mensagem de tristeza pq nao entrou no rank
        }
        quicksort(ranking, qtd);
        if (qtd < MAXPONTUACAO){
            //strcpy(ranking[qtd].nome, nome);
            ranking[qtd].pontuacao=tabuleiro->pontuacao;
            for (i = 0; i < qtd; i++){
                ranking[i].qtd++;
            }
            salvaPontuacao(ranking);
        }else{
            if (qtd == MAXPONTUACAO && (tabuleiro->pontuacao > ranking[qtd-1].pontuacao)){
                //strcpy(aux.nome, nome);
                aux.pontuacao=tabuleiro->pontuacao;
                aux.qtd=MAXPONTUACAO;
                ranking[qtd-1]=aux;
                quicksort(ranking, qtd);
                salvaPontuacao(ranking);
            } 
        }
    }else{
        //scanf("%s", &nome);//pegar o nome, nao sei como vamos fazer isso
        //strcpy(ranking[0].nome, nome);

        ranking[0].pontuacao = tabuleiro->pontuacao;
        ranking[0].qtd=1;
        salvaPontuacao(ranking);
    }
}

void salvaPontuacao(pRANK ranking){
    FILE *arquivo;
    int qtd, i;

    if (!(arquivo = fopen(TABELA, "w+b"))){
        //mensagem de erro
    } else {
        fread(ranking, sizeof(RANK), 1, arquivo);
        qtd = ranking[0].qtd;
        for (i = 0; i < qtd; i++)
            fwrite(ranking + i, sizeof(RANK),1, arquivo);
        fclose(arquivo);
    }
}

bool puxaPontuacao(pRANK ranking){
    FILE *arquivo;
    int qtd, i;

    if (!(arquivo = fopen(TABELA, "rb"))){
        //mensagem de erro
        DrawText("Erro", 0, 10, 40, WHITE);
        return false;
    } else {
        DrawText("Passou", 0, 10, 40, WHITE);
        if (fread (ranking, sizeof(RANK), 1, arquivo)){
            qtd = ranking[0].qtd;
            rewind(arquivo);
            for (i = 0; i < qtd; i++) {
                fread(ranking + i, sizeof(RANK),1, arquivo);
            }
            return true;
        }else
            return false;
    }
    fclose(arquivo);
}


void quicksort (pRANK p, int n){
    int i, j;
    RANK aux;
    for(i = 0; i <= n - 1; i++){
        for(j = i; j <= n - 1; j++){
            if(p[i].pontuacao > p[j].pontuacao){
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
}

int particiona(pRANK ranking, int n){
    int i = -1, j, intervalo = n-1;
    RANK aux, pivo;
    pivo = ranking[intervalo];
    
    for(j = 0; j < n; j++){
        if (ranking[j].pontuacao <= pivo.pontuacao){
            i++;
            aux = ranking[i];
            ranking[i] = ranking[j];
            ranking[j] = aux;
            
        }
    }
    return i;
}
*/
