# Exemplo de Herança: Animais Barulhentos!

Este projeto é um exercício prático da disciplina de Algoritmos e Programação: Orientação a Objetos. O objetivo é demonstrar conceitos-chave de C++, incluindo:

* **Herança:** Com a classe base `Animal` e as classes derivadas `Cachorro` e `Gato`.
* **Polimorfismo:** Através do método virtual `fazerSom()`.
* **Associação entre Classes:** Mostrando como um `Animal` pode *usar* um `GerenciadorSom` sem possuí-lo, através do uso de referências (`&`).
* **Separação de Arquivos:** Organização do código em arquivos `.h` e `.cpp`.

---
## Dependência

Este projeto utiliza a biblioteca `miniaudio` para manipulação de áudio.

* **miniaudio:** Uma biblioteca de áudio de arquivo único (single-header) para C/C++.
    * **Link:** [https://github.com/mackron/miniaudio](https://github.com/mackron/miniaudio)
    * **Inclusão:** O arquivo `miniaudio.h` já está incluído neste repositório para conveniência.

---

## Como Compilar e Executar

Este projeto foi configurado para ser compilado no Windows utilizando o **MinGW** e o **`mingw32-make`**.

### 1. Ambiente Recomendado

* **Terminal:** PowerShell
* **Compilador:** MinGW (com `g++`)
* **Build System:** `mingw32-make`

### 2. Compilando o Projeto

Para compilar o código-fonte, abra o **PowerShell** na raiz do projeto (onde o `Makefile` está localizado) e execute o comando:

```powershell
mingw32-make
```

Isso irá invocar o `Makefile`, compilar todos os arquivos necessários e, se tudo estiver correto, gerar o executável principal (ex: `main.exe`).

### 3. Executando o Programa

Após a compilação, você pode executar o programa diretamente no PowerShell:

```powershell
.\main.exe
```

Se preferir, pode chamar via `mingw32-make` também:

```powershell
mingw32-make run
```

### 4. Limpando os Arquivos Gerados

O `Makefile` inclui comandos para limpar os arquivos gerados durante a compilação.

* **`mingw32-make clean`**
    * Limpa **apenas** os arquivos objeto (`.o`) que são criados durante o processo.

* **`mingw32-make cleanall`**
    * Limpa **tudo**: remove os arquivos objeto (`.o`) E também o executável principal (`.exe`).

---

## Estrutura das Classes

* **`GerenciadorSom`**
    * Classe utilitária (baseada na `miniaudio.h`) responsável por inicializar um dispositivo de áudio e tocar arquivos de som. É uma classe concreta e independente.

* **`Animal`** (Classe Base Abstrata)
    * Define a interface comum para todos os animais.
    * Possui um `nome` e uma **referência** para um `GerenciadorSom`, que é recebida no construtor.
    * Declara o método `virtual void fazerSom() = 0;`, tornando-a uma classe abstrata.

* **`Cachorro`** (Classe Derivada)
    * Herda de `Animal`.
    * Seu construtor recebe o `nome` e o `GerenciadorSom&` e os repassa para o construtor da classe `Animal`.
    * Implementa `fazerSom()` tocando um som de latido.

* **`Gato`** (Classe Derivada)
    * Herda de `Animal`.
    * Também repassa `nome` e `GerenciadorSom&` para a classe `Animal`.
    * Implementa `fazerSom()` tocando um som de miado.

## Entendendo o Makefile

O **Makefile** é um script que automatiza o processo de compilação do nosso projeto. Ele é lido pelo comando **mingw32-make** e entende quais arquivos precisam ser compilados ou "linkados" para gerar o executável final.

Este é o Makefile que usamos:
```makefile
# --- Variáveis de Configuração ---
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
TARGET = main
SOURCES = main.cpp Animal.cpp Cachorro.cpp GerenciadorSom.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# --- Regras (Targets) ---

# Regra padrão: compila o executável
all: $(TARGET)

# Regra para "linkar" o executável final
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regra "padrão" para compilar .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# NOVO: Regra para executar
# O 'run' depende do 'all', então o 'make' vai primeiro
# garantir que tudo esteja compilado antes de executar.
run: all
	.\$(TARGET).exe

# Alvo padrão para limpar apenas os arquivos objeto (.o)
clean:
	del /F /Q *.o

# Alvo para limpar TUDO (objetos e executável)
cleanall: clean
	del /F /Q $(TARGET).exe
```

### O que eu preciso alterar em um novo projeto?

Na maioria das vezes, você **só precisará editar a seção "Variáveis de Configuração"** no topo do arquivo.

As duas variáveis mais importantes são:

1.  **`TARGET`**:
    * **O que é:** O nome que você quer dar ao seu programa executável final.
    * **Exemplo:** Se você mudar `TARGET = main` para `TARGET = AlbumApp`, o `make` irá gerar o arquivo `AlbumApp.exe`.

2.  **`SOURCES`**:
    * **O que é:** Esta é a variável **mais importante**. É a lista de **todos** os arquivos de código-fonte (`.cpp`) do seu projeto.
    * **Exemplo:** Se você adicionar a classe `Gato` ao projeto, você **precisa** adicionar `Gato.cpp` a esta lista.
    * *Antes:* `SOURCES = main.cpp Animal.cpp Cachorro.cpp GerenciadorSom.cpp`
    * *Depois:* `SOURCES = main.cpp Animal.cpp Cachorro.cpp GerenciadorSom.cpp Gato.cpp`

### O que eu NÃO preciso alterar?

O resto do `Makefile` é genérico e funciona automaticamente baseado nas variáveis que você definiu acima:

* **`OBJECTS`**: Gera a lista de arquivos `.o` (arquivos objeto) automaticamente a partir da sua lista `SOURCES`.
* **Regra `$(TARGET): $(OBJECTS)`**: Regra que "linka" (junta) todos os arquivos `.o` para criar o `.exe` final.
* **Regra `%.o: %.cpp`**: A "regra mágica" que ensina o `make` a transformar qualquer arquivo `.cpp` em um arquivo `.o` correspondente.
* **`run`, `clean`, `cleanall`**: Regras de conveniência que usam a variável `$(TARGET)` e funcionarão automaticamente.