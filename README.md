<h2> 🎮Jogo da Forca em C </h2>
<p>Este é um jogo da forca simples e divertido, desenvolvido em C. O objetivo é adivinhar a palavra secreta, letra por letra, antes que seu bonequinho seja completamente "enforcado".</p>

<h2>🚀 Como Executar</h2>
<p>Para rodar este jogo, você vai precisar de um compilador C (como o GCC). Siga os passos abaixo:<br>
1. Salve o código: Salve o código-fonte do jogo em um arquivo com a extensão ".c" (ex: forca.c).<br>
2. Compile o código: Abra seu terminal ou prompt de comando, navegue até o diretório onde você salvou o arquivo e compile-o usando o seguinte comando:

```bash
gcc forca.c -o forca (se for windos será: -o forca.exe se for Linux ou IOS será: -o forca.out)
```

3. Execute o jogo: Depois de compilar, você pode executar o jogo com este comando:</p>

```bash
./forca (colocando a extensão ex: .exe ou .out)
```

<h2>🕹️ Como Jogar
O jogo é bem direto:</h2>

<p>1. Ao iniciar, uma palavra secreta será escolhida aleatoriamente e exibida com traços, um para cada letra.<br>
2. Você terá um número limitado de tentativas (geralmente 5 ou 6, dependendo da implementação).<br>
3. A cada rodada, você deve chutar uma letra.<br>
4. Se a letra que você chutou estiver na palavra secreta, ela será revelada nas posições corretas.<br>
5. Se a letra não estiver na palavra, você perde uma tentativa, e uma parte do "boneco da forca" será desenhada.<br>
6. O jogo termina quando você adivinha a palavra completa (vitória!) ou quando o boneco da forca é totalmente desenhado (derrota!).<br>
7. Ao final, o jogo mostrará se você venceu ou perdeu e qual era a palavra secreta.</p>

<h2>🛠️ Estrutura do Projeto
O projeto é composto por um único arquivo fonte em C (forca.c). Ele inclui as seguintes funcionalidades:</h2>

<p>1. Seleção de Palavra: Uma lista de palavras predefinidas é usada, e uma delas é escolhida aleatoriamente para cada partida.<br>
2. Gerenciamento de Tentativas: O jogo controla o número de tentativas restantes e as letras já chutadas.<br>
3. Renderização da Forca: A cada erro, uma representação textual da forca e do boneco é atualizada.<br>
4. Entrada de Usuário: Lida com a leitura das letras chutadas pelo jogador.<br>
5. Lógica de Acerto/Erro: Verifica se a letra chutada está na palavra e atualiza o estado do jogo.</p>

<h2>💡 Próximos Passos (Possíveis Melhorias)
Este é um projeto básico, mas pode ser expandido de várias formas:</h2>

<p>1. Adicionar Categorias de Palavras: Permitir que o jogador escolha uma categoria (animais, frutas, objetos, etc.).<br>
2. Carregar Palavras de um Arquivo: Em vez de ter as palavras embutidas no código, carregá-las de um arquivo de texto.<br>
3. Aumentar Dificuldade: Implementar diferentes níveis de dificuldade, talvez com palavras mais longas ou menos tentativas.<br>
4. Interface Gráfica: Para uma experiência mais rica, seria possível usar uma biblioteca gráfica (como SDL ou Raylib) para criar uma interface visual.</p><br>

<h1>Divirta-se jogando e, se quiser, sinta-se à vontade para contribuir! 😊</h1>
