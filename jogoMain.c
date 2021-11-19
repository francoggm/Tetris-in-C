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

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    int dist, i, j, coluna, metade = ((X * TAM) / 2), IniGrid = (screenWidth / 2) - metade, ydesce = 0, val, opcao = 0, jogoCarregado;
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

    InitAudioDevice();
    Music musicMenu = LoadMusicStream(NOMEMUSICA);
    Music musicJogo = LoadMusicStream(NOMEMUSICA1);

    PlayMusicStream(musicMenu);

    SetMusicVolume(musicMenu, 0.1);

    while (!WindowShouldClose())
    {
        SetTargetFPS(60);
        UpdateMusicStream(musicMenu);
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
            PlayMusicStream(musicJogo);
            SetMusicVolume(musicJogo, 0.05);
            //laço para zerar a matriz tabuleiro
            for (i = 0; i < Y; i++)
                for (j = 0; j < X; j++)
                    tabuleiro.g[i][j] = 0;

            while (!WindowShouldClose())
            {
                SetTargetFPS(60);
                UpdateMusicStream(musicJogo);
                BeginDrawing();

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
                        acabaJogo(screenWidth, screenHeight, &tabuleiro);
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
                                        PauseMusicStream(musicJogo);
                                        SetTargetFPS(12);
                                        if (verificaColisao(peca[0], peca[0].pos.y + 1, peca[0].pos.x, &tabuleiro))
                                        { //para que o movimento realmente aconteça ele verifica se não há colisão no movimento esperado, portanto passa peca.pos.y+1 nesse caso
                                            peca[0].pos.y++;
                                            preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y - 1, peca[0].pos.x); //passa por parametro a struct peca o endereco do tabuleiro e as novas posições para y e x
                                        }
                                        ResumeMusicStream(musicJogo);
                                    }
                                }

                                if (IsKeyDown(KEY_LEFT))
                                {
                                    PauseMusicStream(musicJogo);
                                    SetTargetFPS(12);
                                    if (verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x - 1, &tabuleiro))
                                    { //similar com o caso anterior porem passando x-1 para o movimento da esquerda
                                        peca[0].pos.x--;
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x + 1); //similar com o caso anterior
                                    }
                                    ResumeMusicStream(musicJogo);
                                }

                                if (IsKeyDown(KEY_RIGHT))
                                {
                                    PauseMusicStream(musicJogo);
                                    SetTargetFPS(12);
                                    if (verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x + 1, &tabuleiro))
                                    { //similar com os casos anteriores porem passando x+1 para o movimento a direita
                                        peca[0].pos.x++;
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x - 1); //similar com os casos anteriores
                                    }
                                    ResumeMusicStream(musicJogo);
                                }
                                if (IsKeyPressed(KEY_UP))
                                {
                                    ydesce = desceTudo(&peca, tabuleiro);
                                    preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y - ydesce, peca[0].pos.x);
                                }

                                //Sentido Horario
                                if (IsKeyPressed(KEY_X))
                                {
                                    if (peca[0].dif == 2)
                                    {
                                        apagaPeca(peca[0], &tabuleiro);
                                        do
                                        {
                                            peca[0].tipo = GetRandomValue(1, 7);
                                        } while (!verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x, &tabuleiro));
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                                    }
                                    else if (verificaColisaoRotacao(peca[0], tabuleiro, 1))
                                    {
                                        peca[0].rot++;
                                        setaRotacao(&peca, 1);
                                        rotacionaPeca(peca[0], &tabuleiro, 1);
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                                    }
                                }

                                //Sentido Anti-horario
                                if (IsKeyPressed(KEY_Z))
                                {
                                    if (peca[0].dif == 2)
                                    {
                                        apagaPeca(peca[0], &tabuleiro);
                                        do
                                        {
                                            peca[0].tipo = GetRandomValue(1, 7);
                                        } while (!verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x, &tabuleiro));
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                                    }
                                    else if (verificaColisaoRotacao(peca[0], tabuleiro, -1))
                                    {
                                        peca[0].rot--;
                                        setaRotacao(&peca, -1);
                                        rotacionaPeca(peca[0], &tabuleiro, -1);
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                                    }
                                }

                                if (IsKeyPressed(KEY_R))
                                {
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

            PlayMusicStream(musicJogo);
            SetMusicVolume(musicJogo, 0.05);

            //laço para zerar a matriz tabuleiro
            for (i = 0; i < Y; i++)
                for (j = 0; j < X; j++)
                    tabuleiro.g[i][j] = 0;

            while (!WindowShouldClose())
            {
                SetTargetFPS(60);
                UpdateMusicStream(musicJogo);
                BeginDrawing();

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
                        acabaJogo(screenWidth, screenHeight, &tabuleiro);
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
                                        PauseMusicStream(musicJogo);
                                        SetTargetFPS(12);
                                        if (verificaColisao(peca[0], peca[0].pos.y + 1, peca[0].pos.x, &tabuleiro))
                                        { //para que o movimento realmente aconteça ele verifica se não há colisão no movimento esperado, portanto passa peca.pos.y+1 nesse caso
                                            peca[0].pos.y++;
                                            preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y - 1, peca[0].pos.x); //passa por parametro a struct peca o endereco do tabuleiro e as novas posições para y e x
                                        }
                                        ResumeMusicStream(musicJogo);
                                    }
                                }

                                if (IsKeyDown(KEY_LEFT))
                                {
                                    PauseMusicStream(musicJogo);
                                    SetTargetFPS(12);
                                    if (verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x - 1, &tabuleiro))
                                    { //similar com o caso anterior porem passando x-1 para o movimento da esquerda
                                        peca[0].pos.x--;
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x + 1); //similar com o caso anterior
                                    }
                                    ResumeMusicStream(musicJogo);
                                }

                                if (IsKeyDown(KEY_RIGHT))
                                {
                                    PauseMusicStream(musicJogo);
                                    SetTargetFPS(12);
                                    if (verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x + 1, &tabuleiro))
                                    { //similar com os casos anteriores porem passando x+1 para o movimento a direita
                                        peca[0].pos.x++;
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x - 1); //similar com os casos anteriores
                                    }
                                    ResumeMusicStream(musicJogo);
                                }
                                if (IsKeyPressed(KEY_UP))
                                {
                                    ydesce = desceTudo(&peca, tabuleiro);
                                    preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y - ydesce, peca[0].pos.x);
                                }

                                //Sentido Horario
                                if (IsKeyPressed(KEY_X))
                                {

                                    if (peca[0].dif == 2)
                                    {
                                        apagaPeca(peca[0], &tabuleiro);
                                        do
                                        {
                                            peca[0].tipo = GetRandomValue(1, 7);
                                        } while (!verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x, &tabuleiro));
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                                    }
                                    else if (verificaColisaoRotacao(peca[0], tabuleiro, 1))
                                    {
                                        peca[0].rot++;
                                        setaRotacao(&peca, 1);
                                        rotacionaPeca(peca[0], &tabuleiro, 1);
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                                    }
                                }

                                //Sentido Anti-horario
                                if (IsKeyPressed(KEY_Z))
                                {
                                    if (peca[0].dif == 2)
                                    {
                                        apagaPeca(peca[0], &tabuleiro);
                                        do
                                        {
                                            peca[0].tipo = GetRandomValue(1, 7);
                                        } while (!verificaColisao(peca[0], peca[0].pos.y, peca[0].pos.x, &tabuleiro));
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                                    }
                                    else if (verificaColisaoRotacao(peca[0], tabuleiro, -1))
                                    {
                                        peca[0].rot--;
                                        setaRotacao(&peca, -1);
                                        rotacionaPeca(peca[0], &tabuleiro, -1);
                                        preencheMatriz(peca[0], &tabuleiro, peca[0].pos.y, peca[0].pos.x);
                                    }
                                }

                                if (IsKeyPressed(KEY_R))
                                {
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
                if (jogoCarregado)
                {
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
    UnloadMusicStream(musicMenu);
    UnloadMusicStream(musicJogo);

    CloseAudioDevice();

    return 0;
}
