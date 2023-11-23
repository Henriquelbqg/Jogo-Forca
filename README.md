# TrabalhoPIF 🎮

## Trabalho da matéria de Programação Imperativa e Funcional focado no desenvolvimento de um casual game.

### Integrantes 

Henrique Lobo -> hlqg@cesar.school

Lucas Souto -> lsmc2@cesar.school

Luiz Felipe -> lfsbs@cesar.school

### Descrição do projeto

> Estamos engajados no desenvolvimento de um jogo da forca clássico totalmente personalizável. Os usuários terão a liberdade de escolher o nível de dificuldade tornando cada partida única. Além disso, implementaremos um sistema de pontuação e recordes em um banco de dados, com um recorde que destacará a melhor pontuação entre todos os jogadores, proporcionando uma experiência competitiva e envolvente.


## Como Jogar

1. Insira seu nome para iniciar o jogo.
2. Escolha a dificuldade do jogo.
3. Chute letras para adivinhar a palavra.
4. Chutes errados serão exibidos junto com as partes do boneco e os chutes corretos.
5. Em caso de derrota, será mostrada uma animação do boneco e a palavra correta.
6. Em caso de vitória, uma animação de comemoração aparecerá junto com sua pontuação e recordes.

## Como Compilar

### Abra o terminal e navegue até o diretório do código fonte. Compile o código com o GCC usando o comando:

    gcc main.c -o forca

### Execute o programa com:

    ./forca


## Algumas Funções Implementadas

    chuteserrados(): Conta quantidade de erros.
    jachutou(): Confere se o chute é correto.
    abertura(): Exibe o menu inicial.
    desenharboneco(): Desenha a forca e o boneco.
    criarboneco(): Cria uma representação do boneco.
    enforcou(): Verifica se o jogador esgotou os chutes.
    alocanome(): Aloca dinamicamente o nome do jogador.
    nomevalido(): Verifica se o nome digitado é válido.

## Funções Principais

    escolhepalavra(): Seleciona uma palavra secreta com base na dificuldade.
    imprimepalavra(): Revela letras corretas e substitui as não reveladas por "_".
    chuta(): Permite ao usuário realizar um chute.
    acertou(): Verifica se todas as letras foram acertadas.

## Dificuldades Encontradas

1. Tratamento de erros.
2. Manipulação do arquivo .dat.
3. Uso de novas bibliotecas.
4. Criação de uma biblioteca própria.
