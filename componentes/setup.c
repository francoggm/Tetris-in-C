#include <raylib.h>
#include <time.h>

#define TAM 20
#define BORDA 10
#define MARGEM 120
#define X 11
#define Y 20
#define MAXSTRING 31
#define MAXNOME 4
#define SALVO "jogoSalvo.bin"
#define TABELA "maioresPontuacoes.bin"
#define MAXPONTUACAO 101
#define NOMEALEATORIO "resources/interroga.png"
#define NOMEBOMBA "resources/Bomba.png"
#define NOMEMUSICA "resources/SheWas.mp3"
#define NOMEMUSICA1 "resources/MainTheme.mp3"

static bool temPeca = false; //variavel global para verificação se ja estiver uma peça em movimento
static bool gameOver = false;
static bool first = true;
static bool pausado = false;

const int screenWidth = 1280;
const int screenHeight = 720;

typedef struct _ranking
{
    char nome;
    int pontuacao, qtd;
} RANK, *pRANK;

typedef struct _time
{
    time_t inicio;
    time_t fim;
} TEMPO, *pTEMPO;

//struct posição
typedef struct _posicao
{
    int y, x;
} POSICAO, *pPOSICAO;

//struct da peça
typedef struct _peca
{
    POSICAO pos;
    Color cor;
    int tipo;
    int rot;
    int dif;
} PECA, *pPECA;

//struct para o tabuleiro
typedef struct _tabuleiro
{
    int g[Y][X];
    int pontuacao;
    int dificuldade;
} TABULEIRO, *pTABULEIRO;

//struct para as duas imagens usadas
typedef struct _imagens
{
    Texture2D pecaAleatoria;
    Texture2D pecaBomba;
} IMAGEM, *pIMAGEM;

Vector2 tamanhoB = {TAM, TAM};

//função para verificar colisão de acordo com a matriz
int verificaColisao(PECA, int, int, pTABULEIRO);

//funcao que verifica a rotação nos cantos
int verificaColisaoRotacao(PECA, TABULEIRO, int);

//funcao para verificar se  apeca chegou no fundo
int colisaoFinal(int, int);

int colisaoPecaPecaY(TABULEIRO, PECA, int, int);

int colisaoPecaPecaX(TABULEIRO, PECA, int);

//Iniciar contagem
void inicia(pTEMPO);

//Parar contagem
void para(pTEMPO);

//Calcular tempo decorrido
int tempo(TEMPO);

//função para desenhar peça
void desenhaPeca(PECA, int, int, IMAGEM);

//função para preencher matriz apos o movimento
void preencheMatriz(PECA, pTABULEIRO, int, int);

//função para inicializar a peça
void initPeca(pTABULEIRO, pPECA, pTEMPO);

//funcao para o preenchimento da matriz apos rotação
void setaRotacao(pPECA, int);

//funcao para a rotacao da peca
void rotacionaPeca(PECA, pTABULEIRO, int);

int desceTudo(pPECA, TABULEIRO);

int descida(pPECA, TABULEIRO, int);

void desenhaProximaPeca(PECA, int, int, int, IMAGEM);

void quadradoProxPeca(int, int, int);

void verificaLinhaCompleta(pTABULEIRO);

void salvaJogo(pPECA, pTABULEIRO);

void carregaJogo(pPECA, pTABULEIRO);

void acabaJogo(int, int, pTABULEIRO);

void resetaJogo(pTABULEIRO);

void dificuldade(pTABULEIRO);

void funcionalidadeTeclas();

void desenhaMenu(int);

void apagaPeca(PECA, pTABULEIRO);

void apagaQuadradosAdj(PECA, pTABULEIRO);