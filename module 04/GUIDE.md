# CPP Module 04 - Polimorfismo, Classes Abstratas e Interfaces

## Objetivo do Modulo

Este modulo ensina os pilares do **polimorfismo em C++**: como objetos de classes
diferentes podem ser tratados de forma uniforme atraves de ponteiros da classe base,
como classes abstratas impedem instanciacao direta e como interfaces definem contratos
que classes concretas devem cumprir.

---

## O que e Polimorfismo?

Polimorfismo significa "muitas formas". Em C++, isso permite que um ponteiro do tipo
`Animal*` aponte para um `Dog` ou um `Cat`, e ao chamar um metodo como `makeSound()`,
o programa execute a versao correta da classe derivada em tempo de execucao.

Isso so funciona quando o metodo na classe base e declarado com a keyword `virtual`.
Sem ela, o compilador decide qual funcao chamar em tempo de compilacao, baseando-se
no tipo do ponteiro (nao no tipo real do objeto).

```cpp
// COM virtual -> chama Dog::makeSound()
Animal* a = new Dog();
a->makeSound(); // "Auau"

// SEM virtual -> chama WrongAnimal::makeSound()
WrongAnimal* w = new WrongCat();
w->makeSound(); // "WrongAnimal default sound"
```

### Virtual Destructor

Quando fazemos `delete` em um ponteiro da classe base que aponta para um objeto
derivado, o destrutor da classe base e chamado. Se o destrutor **nao** for virtual,
o destrutor da classe derivada **nunca e chamado**, causando memory leak.

```cpp
class Animal {
    virtual ~Animal(); // sem isso, delete em Animal* nao chama ~Dog()
};
```

---

## Exercise 00 - Polymorphism

### Objetivo
Demonstrar polimorfismo com heranca e a keyword `virtual`, e demonstrar o que
acontece **sem** ela.

### Estrutura de classes

```
Animal (base)
├── Dog
└── Cat

WrongAnimal (base, makeSound NAO e virtual)
└── WrongCat
```

### Fluxo do programa

1. Cria um `Animal*` apontando para `Animal`, `Dog` e `Cat`
2. Chama `makeSound()` em cada um - gracas ao `virtual`, Dog e Cat emitem seus
   proprios sons, mesmo sendo chamados via ponteiro `Animal*`
3. Cria um `WrongAnimal*` apontando para `WrongCat`
4. Chama `makeSound()` - como **nao** tem `virtual`, o som emitido e o de
   `WrongAnimal`, nao o de `WrongCat`. Isso demonstra a necessidade do `virtual`

### Detalhes de implementacao

- `Animal` tem atributo protegido `std::string type`
- `Dog` e `Cat` herdam de `Animal` e setam `type` no construtor
- `makeSound()` e `virtual` em `Animal`, permitindo override nas filhas
- `WrongAnimal::makeSound()` **nao** e virtual, entao o override em `WrongCat` nao
  funciona via ponteiro da base
- Todas as classes seguem a **Orthodox Canonical Form** (construtor padrao,
  construtor de copia, operador de atribuicao, destrutor)

### Arquivos
| Arquivo | Descricao |
|---|---|
| `Animal.hpp/cpp` | Classe base com `virtual makeSound()` |
| `Dog.hpp/cpp` | Herda de Animal, type = "Dog" |
| `Cat.hpp/cpp` | Herda de Animal, type = "Cat" |
| `WrongAnimal.hpp/cpp` | Classe base **sem** virtual em makeSound |
| `WrongCat.hpp/cpp` | Herda de WrongAnimal |

---

## Exercise 01 - I don't want to set the world on fire

### Objetivo
Introduzir **composicao** (classe que possui outra classe via ponteiro) e garantir
**deep copy** (copia profunda) ao copiar objetos que contem memoria alocada
dinamicamente.

### Estrutura de classes

```
Animal (base)
├── Dog  ──possui──> Brain*
└── Cat  ──possui──> Brain*

Brain (classe independente, array de 100 strings)
```

### Fluxo do programa

1. Cria um array de `Animal*` com tamanho N
2. Preenche metade com `new Dog()` e metade com `new Cat()`
3. Cada Dog/Cat cria internamente um `Brain` com `new Brain()`
4. Deleta todos os Animals em loop - gracas ao `virtual ~Animal()`, o destrutor
   correto (Dog ou Cat) e chamado, que faz `delete _brain`
5. Testa deep copy: cria um Dog, copia ele em outro escopo. Quando a copia e
   destruida, o original continua intacto (cada um tem seu proprio Brain)

### Deep Copy vs Shallow Copy

```
SHALLOW COPY (errado):
Dog A: _brain --> [Brain no heap]
Dog B: _brain ----^  (aponta pro mesmo Brain!)
// delete A libera o Brain, B fica com ponteiro dangling

DEEP COPY (correto):
Dog A: _brain --> [Brain no heap]
Dog B: _brain --> [OUTRO Brain no heap]  (copia independente)
// delete A nao afeta B
```

### Detalhes de implementacao

- `Brain` contem `std::string ideas[100]`
- No construtor de `Dog`/`Cat`: `_brain = new Brain()`
- No destrutor de `Dog`/`Cat`: `delete _brain`
- No **copy constructor**: `_brain = new Brain(*other._brain)` (cria novo Brain
  copiando o conteudo)
- No **operator=**: deleta o Brain antigo, cria um novo copiando o do outro
- O `virtual ~Animal()` e essencial: sem ele, ao fazer `delete animals[i]` onde
  `animals[i]` e um `Animal*` apontando para `Dog`, o destrutor de `Dog` nao seria
  chamado e o Brain vazaria

### Arquivos
| Arquivo | Descricao |
|---|---|
| `Brain.hpp/cpp` | Classe com array de 100 ideas |
| `Dog.hpp/cpp` | Agora possui `Brain*`, deep copy implementado |
| `Cat.hpp/cpp` | Agora possui `Brain*`, deep copy implementado |

---

## Exercise 02 - Abstract class

### Objetivo
Tornar a classe `Animal` **abstrata**, impedindo que seja instanciada diretamente.
Faz sentido: um "Animal" generico nao emite nenhum som real.

### O que e uma classe abstrata?

Uma classe que possui pelo menos um metodo **pure virtual** (`= 0`). Ela nao pode
ser instanciada, servindo apenas como base para classes derivadas.

```cpp
class Animal {
    virtual void makeSound() const = 0; // pure virtual -> Animal e abstrata
};

// Animal a;           // ERRO de compilacao
// Animal* a = new Animal(); // ERRO de compilacao
Animal* a = new Dog();      // OK, Dog implementa makeSound()
```

### Diferenca do ex01

A unica mudanca em relacao ao ex01 e:

```cpp
// ex01:
virtual void makeSound() const;    // virtual normal, Animal pode ser instanciada

// ex02:
virtual void makeSound() const = 0; // pure virtual, Animal NAO pode ser instanciada
```

Todo o resto (Brain, deep copy, array de Animals) continua funcionando igual.

### Fluxo do programa

1. Cria array de `Animal*` com Dogs e Cats (nao pode mais criar `new Animal()`)
2. Testa polimorfismo e deleta tudo
3. Testa deep copy do Dog

### Arquivos
Mesmos do ex01, so muda a declaracao de `makeSound()` em `Animal.hpp`.

---

## Conceitos-chave resumidos

| Conceito | Onde aparece | Para que serve |
|---|---|---|
| `virtual` | ex00 | Permite polimorfismo em tempo de execucao |
| `virtual ~Destrutor()` | ex00, ex01, ex02 | Garante que o destrutor correto e chamado via ponteiro base |
| Deep copy | ex01, ex02 | Evita que dois objetos compartilhem a mesma memoria |
| `= 0` (pure virtual) | ex02 | Torna a classe abstrata, impede instanciacao |
| Orthodox Canonical Form | todos | Construtor padrao, copia, operator=, destrutor |

---

## Orthodox Canonical Form (OCF)

Todas as classes devem implementar estes 4 metodos:

```cpp
class Exemplo {
public:
    Exemplo();                              // Construtor padrao
    Exemplo(const Exemplo& other);          // Construtor de copia
    Exemplo& operator=(const Exemplo& other); // Operador de atribuicao
    ~Exemplo();                             // Destrutor
};
```

Quando a classe possui ponteiros para memoria alocada (como `Brain*`), o construtor
de copia e o operator= **devem** fazer deep copy, e o destrutor **deve** liberar a memoria.

---

## Compilacao

Todos os exercicios compilam com:
```
c++ -Wall -Wextra -Werror -std=c++98
```
