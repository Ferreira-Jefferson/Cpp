## Fase
1 — Glossário

## Exercício
1/3

## Objetivo
Conhecer os termos e comandos que compõem um Makefile padrão 42.

## Tarefa
Use a opção [3] para explorar os comandos do Makefile abaixo. Quando estiver pronto, vá para o quiz e escreva o nome do comando que corresponde a cada descrição.

```makefile
NAME = hello

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

## Glossário
### NAME
A variável que guarda o nome do binário final gerado pelo Makefile. É o arquivo executável criado ao rodar `make`. Ex: `NAME = hello` gera um executável chamado `hello`.
### SRC
A lista de arquivos fonte .cpp do projeto. Você define aqui quais arquivos serão compilados. Ex: `SRC = main.cpp utils.cpp`.
### OBJ
A lista de arquivos objeto (.o), gerada automaticamente a partir de SRC usando substituição de sufixo. `$(SRC:.cpp=.o)` troca cada `.cpp` por `.o` — você não precisa escrever na mão.
### CXX
O compilador C++ a ser usado. Na 42, usamos `c++` (alias para g++). Esta variável é passada para cada chamada de compilação.
### CXXFLAGS
As flags (opções) passadas ao compilador. Na 42, o padrão é `-Wall -Wextra -Werror -std=c++98`. Elas ativam avisos extras e exigem código sem erros de compilação.
### all
O target padrão do Makefile. Quando você digita apenas `make`, este target é executado. Geralmente depende de `$(NAME)` para disparar a compilação.
### clean
O target que remove apenas os arquivos objeto (.o) gerados durante a compilação. Não apaga o binário final — só a "sujeira" intermediária.
### fclean
O target que faz limpeza total: chama `clean` para remover os .o e depois apaga também o binário final `$(NAME)`.
### re
O target que recompila tudo do zero. Chama `fclean` para apagar todos os arquivos gerados e depois `all` para recompilar do início.
### .PHONY
Uma declaração especial que diz ao Make que os targets listados não são arquivos reais no disco. Sem isso, se existir um arquivo chamado `clean` na pasta, o `make clean` seria ignorado.
### $<
Variável automática do Make. Dentro de uma receita, representa o primeiro pré-requisito. Na regra `%.o: %.cpp`, o `$<` é o arquivo `.cpp` sendo compilado.
### $@
Variável automática do Make. Dentro de uma receita, representa o nome do alvo atual. Na regra `%.o: %.cpp`, o `$@` é o arquivo `.o` que está sendo gerado.

## QuizComandos
### C1
Guarda o nome do binário final que o Makefile irá gerar.
### C2
Lista os arquivos fonte .cpp que serão compilados.
### C3
Lista os arquivos objeto .o, derivada automaticamente dos arquivos fonte.
### C4
Especifica qual compilador C++ será usado.
### C5
Define as flags e opções passadas ao compilador (-Wall, -Wextra, etc.).
### C6
Target padrão — executado quando você digita apenas `make`.
### C7
Remove apenas os arquivos .o; não apaga o binário.
### C8
Remove os .o e também o binário final.
### C9
Apaga tudo e recompila do zero.
### C10
Declara que os targets não são arquivos reais no disco.

## Conceitos
variáveis NAME/SRC/OBJ/CXX/CXXFLAGS, targets all/clean/fclean/re, .PHONY, variáveis automáticas $< e $@

## Dicas
### Dica 1
Comece explorando os comandos no modo Explorar antes de tentar o quiz. Digite o nome exato como aparece no Makefile.
### Dica 2
No quiz, o nome deve ser escrito exatamente como no Makefile — maiúsculas importam. Ex: `NAME`, `CXX`, `.PHONY`.
### Dica 3
Variáveis automáticas como `$<` e `$@` têm nomes especiais com o cifrão. Explore-os no glossário para não esquecer.
