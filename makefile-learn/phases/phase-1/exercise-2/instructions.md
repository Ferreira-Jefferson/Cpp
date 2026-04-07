## Fase
1 — Glossário

## Exercício
2/3

## Objetivo
Entender as variáveis automáticas e flags usadas dentro das receitas de um Makefile.

## Tarefa
Use a opção [3] para explorar os termos do Makefile abaixo. Quando estiver pronto, vá para o quiz e escreva o termo que corresponde a cada descrição.

```makefile
NAME    = programa

SRC     = main.cpp utils.cpp parser.cpp
OBJ     = $(SRC:.cpp=.o)

CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

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
### $@
Variável automática: representa o **nome do alvo** da regra atual. Na regra `$(NAME): $(OBJ)`, o `$@` é o valor de `$(NAME)` — o binário que está sendo gerado. Na regra `%.o: %.cpp`, o `$@` é o arquivo `.o` sendo criado.
### $<
Variável automática: representa o **primeiro pré-requisito** da regra. Na regra `%.o: %.cpp`, o `$<` é o arquivo `.cpp` que está sendo compilado. Útil quando você quer processar apenas o primeiro arquivo de dependência.
### $^
Variável automática: representa **todos os pré-requisitos** da regra, separados por espaço. Na regra `$(NAME): $(OBJ)`, o `$^` expande para a lista completa de `.o` que serão linkados no binário.
### %.o: %.cpp
Regra de padrão (pattern rule): define como compilar **qualquer** arquivo `.cpp` em `.o` automaticamente. O `%` é um curinga que captura o nome base do arquivo. Sem ela, você teria que escrever uma regra para cada `.cpp` manualmente.
### -c
Flag do compilador que instrui a **compilar sem linkar**. Gera apenas o arquivo objeto `.o` a partir do `.cpp`. A linkagem (junção dos `.o` no binário final) é feita numa etapa separada.
### -o
Flag do compilador que define o **nome do arquivo de saída**. Sem ela, o compilador usa um nome padrão como `a.out`. Ex: `-o $@` direciona a saída para o arquivo alvo da regra.
### -Wall
Flag que ativa os **avisos básicos** do compilador (Wall = "all warnings" — na prática, os mais comuns). Ajuda a detectar código potencialmente problemático antes que vire bug.
### -Wextra
Flag que ativa **avisos adicionais** além dos cobertos por `-Wall`. Inclui verificações mais pedantes, como parâmetros de função não usados e comparações entre tipos diferentes.
### -Werror
Flag que **transforma avisos em erros**. A compilação falha se qualquer aviso for gerado. Na 42, isso garante que o código não tenha nenhum warning — projeto que avisa não compila.
### -std=c++98
Flag que define o **padrão da linguagem** C++ a ser seguido — neste caso, o padrão de 1998. Na 42, todos os projetos devem compilar com `-std=c++98`, que proíbe features modernas como `auto` e lambdas.

## QuizComandos
### C1
Dentro de uma receita, representa o nome do alvo sendo construído.
### C2
Dentro de uma receita, representa o primeiro pré-requisito (dependência).
### C3
Dentro de uma receita, representa todos os pré-requisitos juntos, separados por espaço.
### C4
Regra que compila automaticamente qualquer .cpp em .o, usando um curinga de nome.
### C5
Flag que compila o arquivo fonte sem fazer linkagem, gerando apenas o .o.
### C6
Flag que define o nome do arquivo de saída gerado pelo compilador.
### C7
Flag que ativa os avisos de compilação mais comuns.
### C8
Flag que ativa avisos adicionais além dos básicos.
### C9
Flag que transforma avisos em erros, impedindo a compilação se houver qualquer warning.
### C10
Flag que especifica o padrão da linguagem C++ a ser usado (1998).

## Conceitos
variáveis automáticas $@ $< $^, pattern rule %.o: %.cpp, flags -c -o -Wall -Wextra -Werror -std=c++98

## Dicas
### Dica 1
`$@` = alvo (o que você quer gerar), `$<` = primeiro ingrediente, `$^` = todos os ingredientes. Pense numa receita de cozinha.
### Dica 2
`-c` compila, `-o` nomeia. Eles quase sempre aparecem juntos: `-c $< -o $@`.
### Dica 3
As flags `-Wall -Wextra -Werror` formam um trio padrão da 42. Cada uma adiciona uma camada extra de rigor ao compilador.
