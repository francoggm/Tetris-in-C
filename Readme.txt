O projeto tem como ideia criar um programa que simule um jogo "Tetris", jogo arcade conhecido em decádas anteriores. A proposta é para o projeto final da cadeira de "Algoritmos e Programação" feita pelos alunos da UFRGS (Universidade Federal do Rio Grande do Sul).

O projeto visa apenas formas institucionais / educadionais e recreativas, sem fins lucrativos. Sendo aberto para todos e podendo ser modificado pelos usuários.



======== Composição ========

O projeto é composto dos seguintes arquivos:
    - Pasta "componentes", onde foi feito a modularização de todas as funções do projeto;
    - Pasta "resources", onde foi salvo os recursos gráficos utilizados no projeto;
    - Arquivo "jogoMain.c", onde está o código principal que faz a chamada de todos componentes necessários para funcionar o projeto.


======== Instalação ========

Para poder compilar e debugar no Windows, é necessário utilizar o compilador MINGW (https://sourceforge.net/projects/mingw/) e configurar as variáveis do sistema "Path" nas configurações do sistema operacional (Meu Computador > Propriedades > Configurações Avançadas do Sistema > Variáveis de Ambiete > Path > Definir diretório "C:/mingw/bin").

Para utilizar em sistemas Linux, é necessário utilizar os seguintes comandos no terminal:
    - sudo apt-get update
    - sudo apt-get install mingw-w64

Utilização de arquivos ".exe" apenas dar dois cliques com o botão esquerdo e utilizar o programa.

======== Utilização ========

• Menu Inicial

    Ao iniciar o código, irá rodar o Menu Inicial do jogo, onde terá as opções de "Novo Jogo", "Carregar Jogo", "Resultados" e "Sair".
        - Novo Jogo
        Inicializa um novo tabuleiro com peças aleatórias do jogo "Tetris", configurando todo o setup para padrão e reiniciando todas variáveis do sistema.

        - Carregar Jogo
        Inicializa o tabuleiro e peça desde o último salvamento feito dentro do jogo (Tecla "S"), trazendo todas variáveis e sistema com os mesmos valores de quando foi feito o salvamento.

        - Resultados
        Exibe uma lista das 100 maiores pontuações já feitas desde a primeira execução do código fonte (.exe)

        - Sair
        Retorna todos os valores e encerra o arquivo.

• Durante o Jogo

    O objetivo do Jogo é preencher linhas horizontais do tabuleiro para então pontuar 1 ponto na pontuação geral do usuário, o jogador que preencher mais linhas horizontais terá a maior pontuação do sistema.

    - A dificuldade do jogo consiste em aumentar a velocidade de descida das peças de acordo com a pontuação do jogador, então quanto maior a pontuação, maior o nível de dificuldade enfrentado pelo jogador.

    - As peças nascem de forma aleatória na primeira linha do tabuleiro, onde a gravidade (definida pela dificuldade) começa a incrementar o movimento Y das peças para o final do tabuleiro.

    - O movimento do jogador pode ser tanto no eixo horizontal (X) tecla "RIGHT" e "LEFT", quanto o eixo vertical (Y apenas para baixo) tecla "DOWN", as colisões são definidas de acordo com a posição da peça no tabuleiro, e é contabilizado como colisão apenas durante o encaixe entre peças ou quando ela atinge a última posição Y do tabuleiro.

    - É contabilizado a colisão apenas quando a peça é fixada no local de colisão e nasce outra peça para ser utilizada.

    - Durante o jogo é possível salvar o estado atual do jogo (posições do tabuleiro e local da peça) com a tecla "S", e caso queira carregar o mesmo jogo durante a utilização, usar a tecla "L".

    - Caso o jogador utiliza a opção Carregar Jogo, será retornado as configurações do último salvamento feito pelo mesmo, tecla "L".

    - É possível reiniciar o jogo e reinicilizar todas as configurações do jogo atual com a tecla "R".

    - Para rotacionar peças para o sentido horário, utilizar "X", e sentido anti-horário, utilizar "Z".

    - Rotações são apenas contabilizadas caso a peça tenha espaço para fazer a rotação sugerida, então caso o jogador tente rotacionar em um canto, ou onde já tenha uma peça fixada, ela não sera feita.

    - É possível pausar o jogo através da tecla ENTER e despausar a qualquer momento, voltando a mesma configuração de quando foi pausado.

    - O jogo é encerrado por apenas dois motivos, caso o jogador perca, ou caso ele retorne ao Menu Inicial.

    - O jogo é contabilizado como Fim de Jogo, apenas quando o jogador atinge a primeira linha do tabuleiro com alguma peça fixada, encerrando o jogo definitivo. É possível iniciar um novo jogo pressionando a tecla "SPACE".


======== O Jogo ========

• Composição

    - O jogo é composto de 7 peças normais, sendo (QUADRADO, I, S, S Invertido, L, L Invertido, T), e 1 especial (Peça interrogação), que a cada movimento "X" e "Z" ela troca o formato de si mesma.

    - Um tabuleiro feito de uma matriz 11x20, onde as peças serão apenas movimentadas entre as linhas e colunas do mesmo. Não é possível ter movimentação fora dele.

    - Um contador de pontuação no canto esquerdo da tela, onde informa a pontuação geral do usuário.

    - Um menu interativo, que através do clique do mouse nas opções, realiza a chamada do jogo.

    - Musica do menu inicial (https://www.youtube.com/watch?v=9k2EZHGKMtw&ab_channel=Crockett-Topic).

    - Musica durante o jogo (https://www.youtube.com/watch?v=NmCCQxVBfyM&ab_channel=SoundHub).

• Programação

    - O objetivo é criar todos "objetos" através de estruturas definidas no arquivo "setup.c", onde é feito a manipulação das mesmas, interagindo entre, e criando um ambiente jogável através das teclas.

    - O arquivo está modularizado a fim de organizar as funções que possuam cada configuração específica para o funcionamento do mesmo.

    - O arquivo "setup.c" está definindo todas constantes e variáveis booleanas que serão utilizadas durante o projeto, assim como a prototipação de todas funções usadas no código.

    - Cada função recebe parâmetros que são utilizados para a movimentação das variáveis com a struct durante o uso. Como posições das peças durante a movimentação e onde a matriz está preenchida com peças.

    - O jogo está definida com funções já definidas na biblioteca "Raylib", onde ela tem funcionalidades de teclas clicadas, configuração da janela do programa, desenhos na tela, carregamento de texturas, carregamentos de músicas.

    - Está sendo utilizado a biblioteca "time.h" para conseguir calcular o tempo de movimentação das peças, a fim de criar uma gravidade e dificuldade para cada peça.

    - O jogo é feito através de loops que são feitos enquanto a janela do programa está aberta, iniciando e finalizando o desenho para cada loop. Em resumo cada movimentação é feito com um novo desenho na tela através dessas funções do "Raylib"

    - As configurações de "frames per second (FPS)" são utilizadas durante o código para aumentar a suavidade de movimento das peças, para ser feito através das teclas principais.

    - Durante cada loop é feito as verificações de preenchimento de linhas, assim como as colisões e movimentações, sendo em quase tempo real cada verificação das peças.



/***********************************************************************************************************************************************/

Agradecimentos aos professores da cadeira de "Algoritmos e Programação" por proporcionar conhecimento avançado sobre algoritmos e uma boa lógica de programação para conseguir realizar esse longo projeto de final de curso.





