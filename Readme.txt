======== Composição ========

O projeto é composto dos seguintes arquivos:
    • Pasta "componentes", onde foi feito a modularização de todas as funções do projeto;
    • Pasta "resources", onde foi salvo os recursos gráficos utilizados no projeto;
    • Arquivo "jogoMain.c", onde está o código principal que faz a chamada de todos componentes necessários para funcionar o projeto.


======== Instalação ========

Para poder compilar e debugar no Windows, é necessário utilizar o compilador MINGW (https://sourceforge.net/projects/mingw/) e configurar as variáveis do sistema "Path" nas configurações do sistema operacional (Meu Computador > Propriedades > Configurações Avançadas do Sistema > Variáveis de Ambiete > Path > Definir diretório "C:/mingw/bin").

Para utilizar em sistemas Linux, é necessário utilizar os seguintes comandos no terminal:
    • sudo apt-get update
    • sudo apt-get install mingw-w64

Utilização de arquivos ".exe" apenas dar dois cliques com o botão esquerdo e utilizar o programa.

======== Utilização ========

• Menu Inicial
    Ao iniciar o código, irá rodar o Menu Inicial do jogo, onde terá as opções de "Novo Jogo", "Carregar Jogo", "Resultados" e "Sair".
        • Novo Jogo
        Inicializa um novo tabuleiro com peças aleatórias do jogo "Tetris", configurando todo o setup para padrão e reiniciando todas variáveis do sistema.

        • Carregar Jogo
        Inicializa o tabuleiro e peça desde o último salvamento feito dentro do jogo (Tecla "S"), trazendo todas variáveis e sistema com os mesmos valores de quando foi feito o salvamento.

        • Resultados
        Exibe uma lista das 100 maiores pontuações já feitas desde a primeira execução do código fonte (.exe)

        • Sair
        Retorna todos os valores e encerra o arquivo.

• Durante o Jogo
    O objetivo do Jogo é preencher linhas horizontais do tabuleiro para então pontuar 1 ponto na pontuação geral do usuário, o jogador que preencher mais linhas horizontais terá a maior pontuação do sistema.

    • A dificuldade do jogo consiste em aumentar a velocidade de descida das peças de acordo com a pontuação do jogador, então quanto maior a pontuação, maior o nível de dificuldade enfrentado pelo jogador.

