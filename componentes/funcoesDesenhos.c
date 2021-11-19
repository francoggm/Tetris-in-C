#include <raylib.h>

void desenhaPeca(PECA peca, int x, int y, IMAGEM imagens)
{
    Vector2 pos = {x, y};
    switch (peca.dif)
    {
    case 1:
        DrawRectangleV(pos, tamanhoB, peca.cor);
        break;
    case 2:
        DrawTextureV(imagens.pecaAleatoria, pos, WHITE);
        break;
    case 3:
        DrawRectangleV(pos, tamanhoB, RED);
        DrawTextureV(imagens.pecaBomba, pos, WHITE);
        break;
    }
}

void desenhaProximaPeca(PECA peca, int larguraTela, int alturaTela, int metade, IMAGEM imagens)
{
    switch (peca.dif)
    {
    case 1:
        switch (peca.tipo)
        {
        case 1:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 3.9)}, (Vector2){TAM, TAM}, BLUE);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 3.9)}, (Vector2){TAM, TAM}, BLUE);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 3.9) - TAM}, (Vector2){TAM, TAM}, BLUE);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 3.9) - TAM}, (Vector2){TAM, TAM}, BLUE);
            break;
        case 2:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) - TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) - TAM * 2}, (Vector2){TAM, TAM}, RED);
            break;
        case 3:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, YELLOW);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3) + TAM, alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, YELLOW);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1) + TAM}, (Vector2){TAM, TAM}, YELLOW);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3) - TAM, alturaTela - (metade * 4.1) + TAM}, (Vector2){TAM, TAM}, YELLOW);
            break;
        case 4:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, PINK);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3) - TAM, alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, PINK);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1) + TAM}, (Vector2){TAM, TAM}, PINK);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3) + TAM, alturaTela - (metade * 4.1) + TAM}, (Vector2){TAM, TAM}, PINK);
            break;
        case 5:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4)}, (Vector2){TAM, TAM}, PURPLE);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4) - TAM}, (Vector2){TAM, TAM}, PURPLE);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4) + TAM}, (Vector2){TAM, TAM}, PURPLE);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.35) + TAM, alturaTela - (metade * 4) + TAM}, (Vector2){TAM, TAM}, PURPLE);
            break;
        case 6:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4)}, (Vector2){TAM, TAM}, GREEN);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4) - TAM}, (Vector2){TAM, TAM}, GREEN);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4) + TAM}, (Vector2){TAM, TAM}, GREEN);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 4) + TAM}, (Vector2){TAM, TAM}, GREEN);
            break;
        case 7:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.29), alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, MAROON);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.29) + TAM, alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, MAROON);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.29) - TAM, alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, MAROON);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.29), alturaTela - (metade * 4.1) + TAM}, (Vector2){TAM, TAM}, MAROON);
            break;
        }
        break;
    case 2:
        switch (peca.tipo)
        {
        case 1:
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 3.9)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 3.9)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 3.9) - TAM}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 3.9) - TAM}, WHITE);
            break;
        case 2:
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) + TAM}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) - TAM}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) - TAM * 2}, WHITE);
            break;
        case 3:
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3) + TAM, alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1) + TAM}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3) - TAM, alturaTela - (metade * 4.1) + TAM}, WHITE);
            break;
        case 4:
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3) - TAM, alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1) + TAM}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.3) + TAM, alturaTela - (metade * 4.1) + TAM}, WHITE);
            break;
        case 5:
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4) - TAM}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4) + TAM}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.35) + TAM, alturaTela - (metade * 4) + TAM}, WHITE);
            break;
        case 6:
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4) - TAM}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4) + TAM}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 4) + TAM}, WHITE);
            break;
        case 7:
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.29), alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.29) + TAM, alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.29) - TAM, alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaAleatoria, (Vector2){larguraTela - (metade * 3.29), alturaTela - (metade * 4.1) + TAM}, WHITE);
            break;
        }
        break;
    case 3:
        switch (peca.tipo)
        {
        case 1:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 3.9)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 3.9)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 3.9) - TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 3.9) - TAM}, (Vector2){TAM, TAM}, RED);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 3.9)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 3.9)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 3.9) - TAM}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 3.9) - TAM}, WHITE);
            break;
        case 2:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) - TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) - TAM * 2}, (Vector2){TAM, TAM}, RED);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) + TAM}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) - TAM}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 3.9) - TAM * 2}, WHITE);
            break;
        case 3:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3) + TAM, alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3) - TAM, alturaTela - (metade * 4.1) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3) + TAM, alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1) + TAM}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3) - TAM, alturaTela - (metade * 4.1) + TAM}, WHITE);
            break;
        case 4:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3) - TAM, alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.3) + TAM, alturaTela - (metade * 4.1) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3) - TAM, alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3), alturaTela - (metade * 4.1) + TAM}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.3) + TAM, alturaTela - (metade * 4.1) + TAM}, WHITE);
            break;
        case 5:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4) - TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.35) + TAM, alturaTela - (metade * 4) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4) - TAM}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.35), alturaTela - (metade * 4) + TAM}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.35) + TAM, alturaTela - (metade * 4) + TAM}, WHITE);
            break;
        case 6:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4) - TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 4) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4) - TAM}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.2), alturaTela - (metade * 4) + TAM}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.2) - TAM, alturaTela - (metade * 4) + TAM}, WHITE);
            break;
        case 7:
            DrawRectangleV((Vector2){larguraTela - (metade * 3.29), alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.29) + TAM, alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.29) - TAM, alturaTela - (metade * 4.1)}, (Vector2){TAM, TAM}, RED);
            DrawRectangleV((Vector2){larguraTela - (metade * 3.29), alturaTela - (metade * 4.1) + TAM}, (Vector2){TAM, TAM}, RED);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.29), alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.29) + TAM, alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.29) - TAM, alturaTela - (metade * 4.1)}, WHITE);
            DrawTextureV(imagens.pecaBomba, (Vector2){larguraTela - (metade * 3.29), alturaTela - (metade * 4.1) + TAM}, WHITE);
            break;
        }
        break;
    }
}

void quadradoProxPeca(int larguraTela, int alturaTela, int metade)
{
    DrawLine((larguraTela / 2 + metade * 2), alturaTela / 2, (larguraTela / 2 + metade * 3.2), alturaTela / 2, RAYWHITE);
    DrawLine((larguraTela / 2 + metade * 2), alturaTela / 3.2, (larguraTela / 2 + metade * 3.2), alturaTela / 3.2, RAYWHITE);
    DrawLine((larguraTela / 2 + metade * 2), alturaTela / 2, (larguraTela / 2 + metade * 2), alturaTela / 3.2, RAYWHITE);
    DrawLine((larguraTela / 2 + metade * 3.2), alturaTela / 2, (larguraTela / 2 + metade * 3.2), alturaTela / 3.2, RAYWHITE);
}

void funcionalidadeTeclas()
{
    DrawText("S: Salvar Jogo", 860, 400, 15, WHITE);
    DrawText("L: Carrega Jogo", 860, 420, 15, WHITE);
    DrawText("R: Reinicia o Jogo", 860, 440, 15, WHITE);
    DrawText("X: Rota Horario", 860, 460, 15, WHITE);
    DrawText("Z: Rota Anti-Horario", 860, 480, 15, WHITE);
    DrawText("LEFT: Movimenta Esquerda", 860, 500, 15, WHITE);
    DrawText("RIGHT: Movimenta Direita", 860, 520, 15, WHITE);
    DrawText("DOWN: Movimento Baixo", 860, 540, 15, WHITE);
    DrawText("UP: Desce tudo para Baixo", 860, 560, 15, WHITE);
    DrawText("ESC: Voltar para o Menu", 860, 580, 15, WHITE);
    DrawText("ENTER: Pausa Jogo", 860, 600, 15, WHITE);
}

void desenhaMenu(int screenWidth){
        DrawText("T", (screenWidth/2) - 100, 50, 50, BLUE);
        DrawText("E", (screenWidth/2) - 50, 50, 50, RED);
        DrawText("T", (screenWidth/2) - 10, 50, 50, YELLOW);
        DrawText("R", (screenWidth/2) + 40, 50, 50, PINK);
        DrawText("I", (screenWidth/2) + 90, 50, 50, PURPLE);
        DrawText("S", (screenWidth/2) + 120, 50, 50, GREEN);

        DrawText("Novo Jogo", 580, 350, 30, WHITE);
        DrawText("Carregar Jogo", 545, 400, 30, WHITE);
        DrawText("Resultados", 570, 450, 30, WHITE);
        DrawText("Sair", 625, 500, 30, WHITE);       
}