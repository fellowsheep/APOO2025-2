# Além da Herança: Outros Relacionamentos Entre Classes 🪄

A herança ("*é um*") é um dos pilares da Orientação a Objetos, mas não é a única forma pela qual as classes podem se relacionar. Na verdade, a herança é um tipo de relação de **Generalização**. 

Além da generalização, ainda temos dois outros tipos fundamentais de relacionamentos: **Associação** e **Dependência**, que veremos neste material.

## Associação

A ideia principal de um relacionamento de  **Associação** é representar um objeto que "usa" ou "interage com" outro.

O Relacionamento de Associação ainda pode ser subdivido em:
* **Plana** : representa uma relação estrutural onde as classes possuem a
mesma importância. Uma linha ligando duas classes representa
graficamente essa relação. 

* **Agregação**: representa a estrutura todo-parte. Ela é representada por
uma linha ligando as duas classes da relação e a presença de um
*símbolo diamante* (losango). Esse losango é colocado na
conexão entre a linha e a classe que é considerada a mais importante
da relação.
Além disso, esse losango pode ser representado apenas como contorno ou preenchido, o que faz representar duas formas de relacionamento distintas:
   - Se estiver apenas contornado , tem-se Agregação Simples, ou simplesmente **Agregação**.
   - Se estiver preenchido, têm-se Agregação por Composição, ou
simplesmente **Composição**.


Neste capítulo vamos explorar os **tipos de relacionamento entre classes** em C++ — usando o universo de **RPG** como pano de fundo. 

---

## 1) Associação — “usa um”

Associação indica que um objeto **usa** outro, sem relação de propriedade. Os ciclos de vida são **independentes**.

### Diagrama simples (A usa B)

![UML Associação Simples](img/Associacao.svg)

```puml
@startuml associacao
class A
class B
A --> B : usa
@enduml
```

### Diagrama no contexto RPG (Mago usa Magia)

Um **Mago** pode **lançar** uma **Magia**, mas ele não “possui” essa magia.  
A `Magia` pode existir independentemente do `Mago`.

![AssociacaoSimplesMago](img/AssociacaoSimplesRPG.svg)

```puml
@startuml associacaoRPG
class Mago
class Magia
class BolaDeFogo
Magia <|-- BolaDeFogo
Mago --> Magia : usa
@enduml
```

### Código C++ (polimorfismo via ponteiros)

```cpp
#include <iostream>
#include <string>

class Magia {
public:
    virtual void executar() = 0; // Abstrato
};

class BolaDeFogo : public Magia {
public:
    void executar() override {
        std::cout << "Bola de Fogo explode!" << std::endl;
    }
};

class Mago {
public:
    // Exemplo 1: Recebendo a magia como parâmetro
    void lancar(Magia* magia) {
        std::cout << "Mago prepara o feitiço..." << std::endl;
        magia->executar();
    }
};
```

---

## 2) Agregação — “tem um”

Na agregação, o **todo** mantém uma **referência** (geralmente ponteiro) para a **parte**, mas o ciclo de vida da parte **não depende** do todo. Se o todo “morrer”, a parte pode continuar existindo.

### Diagrama simples (A o-- B)

![UML Agregação](img/agregacao.svg)

```puml
@startuml agregacao
class A
class B
A o-- B : tem (referencia)
@enduml
```

### **Exemplo de RPG:**

Um `Mago` "tem um" `Item` (como um cajado ou amuleto). O `Mago` usa o `Item` para melhorar suas magias. No entanto, se o `Mago` morrer, o `Item` pode "dropar no chão" — ele pode existir independentemente do `Mago`. O `Item` pode até ser compartilhado ou trocado.

**Diagrama UML:**
Uma linha sólida com um **diamante vazio** do lado do "todo" (o dono).

![UML Agregacao RPG](img/AgregacaoRPG.svg)

```plantuml
@startuml agregacaoRPG
class Mago
class Item
' O Mago "tem um" Item
Mago o-- Item: tem um 
@enduml
```

**Código C++:**
O `Mago` armazena um **ponteiro** para o `Item`. Ele não é responsável por criar ou destruir o `Item` — ele apenas o "equipa" (recebe o ponteiro de fora).

```cpp
#include <iostream>
#include <string>

class Item {
public:
    int bonusMagico;
    std::string nomeItem;
    
    Item(std::string nome, int bonus) : nomeItem(nome), bonusMagico(bonus) {}

    void brilhar() {
        std::cout << nomeItem << " brilha com poder!" << std::endl;
    }
};

class Mago {
private:
    Item* itemEquipado; // Armazena um ponteiro

public:
    Mago() : itemEquipado(nullptr) {}

    // O Mago recebe o item de uma fonte externa
    void equiparItem(Item* item) {
        this->itemEquipado = item;
        if(item != nullptr) {
            std::cout << "Mago equipou o " << item->nomeItem << "." << std::endl;
        } else {
            std::cout << "Mago desequipou o item." << std::endl;
        }
    }
    
    void lancarMagiaForte() {
        int poderBase = 10;
        if (itemEquipado != nullptr) {
            itemEquipado->brilhar();
            int poderTotal = poderBase + itemEquipado->bonusMagico;
            std::cout << "Mago lanca magia com poder " << poderTotal << "!" << std::endl;
        } else {
            std::cout << "Mago lanca magia com poder " << poderBase << "." << std::endl;
        }
    }
    
    // O destrutor do Mago NÃO deleta o item!
    ~Mago() {
        std::cout << "Mago morre, mas o item continua existindo..." << std::endl;
    }
};

int main() {
    // Os itens existem fora do Mago
    Item* cajado = new Item("Cajado de Fogo", 5);
    Item* amuleto = new Item("Amuleto de Agua", 3);
    
    Mago* m = new Mago();
    m->lancarMagiaForte(); // Lança sem item
    
    m->equiparItem(cajado); // Equipa o cajado
    m->lancarMagiaForte(); // Lança com o cajado
    
    m->equiparItem(amuleto); // Troca pelo amuleto
    m->lancarMagiaForte(); // Lança com o amuleto
    
    std::cout << "--- Mago e deletado ---" << std::endl;
    delete m; // O Mago morre...
    
    // ... mas os itens continuam existindo!
    std::cout << "O item " << cajado->nomeItem << " ainda esta no chao." << std::endl;
    
    // Precisamos liberar a memória dos itens separadamente
    delete cajado;
    delete amuleto;
    
    return 0;
}
```
---

## 3) Composição — "é parte de"

A **Composição** é a forma mais forte de posse. É um relacionamento "é parte de" ou "é composto por".

Ela também é um "tem um", mas com uma regra crucial: o ciclo de vida da "parte" é **totalmente controlado** pelo "todo". Se o "todo" é destruído, a "parte" é destruída junto. A "parte" não pode existir sem o "todo".

![alt text](img/Composicao.svg)
 
 ```puml
@startuml composicao
class A
class B
A *-- B : é composto por
@enduml
```

**Exemplo de RPG:**
Um `Mago` "é composto por" um `Inventario`. O `Inventario` de um Mago específico não faz sentido existir sem aquele `Mago`. Quando o `Mago` é criado, seu `Inventario` é criado junto. Quando o `Mago` morre (é destruído), seu `Inventario` deixa de existir.

**Diagrama UML:**
Uma linha sólida com um **diamante preenchido** do lado do "todo".

![UML Composicao RPG](img/ComposicaoRPG.svg)

```plantuml
@startuml composicaoRPG
class Mago
class Inventario

' O Mago "é composto por" um Inventario
Mago *-- Inventario: é composto por
@enduml
```

**Código C++:**
O `Inventario` é (geralmente) um **objeto membro** (não um ponteiro) da classe `Mago`. O construtor do `Mago` automaticamente chama o construtor do `Inventario`, e o destrutor do `Mago` automaticamente chama o destrutor do `Inventario`.

```cpp
#include <iostream>
#include <string>

class Inventario {
    public:
        Inventario() { // Construtor
        nSlots = 10; nItems = 0;
        itens = new Item[numSlots];
        std::cout << "(Inventario criado com " << numSlots << " slots)" << std::endl;
    }
    ~Inventario() { // Destrutor
        std::cout << "(Inventario destruido, itens perdidos)" << std::endl;
    }
    void guardarItem(std::string nomeItem) {
        if (nItems < nSlots) {
            Item item = Item(nomeItem);
            itens[nItems] = item;
            nItems++; 
            std::cout << nomeItem << " guardado no inventario." << std::endl;
        }
        else {
            std::cout << "Inventario cheio!" << std:: endl;
        }
    }
    private:
        Item *itens; //array dinâmico
        int nSlots;
        int nItems;

};

class Mago {
private:
    Inventario inventario; // Objeto membro (Composição)
    std::string nome;

public:
    // Quando o Mago é construído, o meuInventario é construído primeiro
    Mago(std::string nome) : nome(nome) {
        std::cout << "Mago " << nome << " foi criado." << std::endl;
        inventario.guardarItem("Pocao");
    }
    
    // Quando o Mago é destruído, o meuInventario é destruído logo em seguida
    ~Mago() {
        std::cout << "Mago " << nome << " foi destruido." << std::endl;
    }
    
    void verItens() {
        // ...
    }
};

int main() {
    std::cout << "--- Criando Mago ---" << std::endl;
    Mago* g = new Mago("Gandalf");
    std::cout << "--- Deletando Mago ---" << std::endl;
    delete g;
    std::cout << "--- Fim do Programa ---" << std::endl;
    
    /* Saída:
    --- Criando Mago ---
    (Inventario criado com 10 slots)
    Mago Gandalf foi criado.
    Pocao guardado no inventario.
    --- Deletando Mago ---
    Mago Gandalf foi destruido.
    (Inventario destruido, itens perdidos)
    --- Fim do Programa ---
    */
    return 0;
}
```
---

## 4) Estudo de Caso: Druida e Familiar (Associação vs. Composição)

O relacionamento entre **Druida** e **Familiar** pode ser modelado de formas diferentes, dependendo das regras do mundo:

* **Associação:** o Druida **invoca** um Familiar já existente (ciclos de vida independentes).
* **Composição:** o Druida **possui** um FamiliarVinculado que é criado e destruído junto com ele (ciclo de vida compartilhado).

### 4.1 Associação Simples

![alt text](img/AssociacaoDruida.svg)

```puml
@startuml associacaoDruida
class Druida
class Familiar
Druida --> Familiar : invoca
@enduml
```

### Código C++ (Associação Simples)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Familiar {
    string nome;
public:
    Familiar(string n) : nome(n) {}
    void responder() { cout << nome << " atende ao chamado.\n"; }
};

class Druida {
public:
    void invocar(Familiar* f) {
        if (f) {
            cout << "Druida entoa um canto antigo...\n";
            f->responder();
        }
    }
};

int main() {
    Familiar familiar("Lobo das Brumas");
    Druida druida;
    druida.invocar(&familiar);
}
```

### 4.2 Composição

![alt text](img/ComposicaoDruida.svg)

```puml
@startuml composicaoDruida
class Druida
class FamiliarVinculado
Druida *-- FamiliarVinculado : vinculo magico
@enduml
```

### Código C++ (Composição)

```cpp
#include <iostream>
using namespace std;

class FamiliarVinculado {
public:
    FamiliarVinculado() { cout << "Um vinculo magico e formado.\n"; }
    ~FamiliarVinculado() { cout << "O vinculo se desfaz...\n"; }
};

class Druida {
    FamiliarVinculado familiar; // composição
public:
    Druida()  { cout << "Druida desperta para a natureza.\n"; }
    ~Druida() { cout << "Druida retorna ao ciclo da vida.\n"; }
};

int main() {
    Druida druida;
}
```

---

## ⚖️ 5) Comparativo rápido

| Relação    |  Diagrama | Frase mental | Ciclo de vida | Exemplo                      |
| ---------- | --------: | ------------ | ------------- | ---------------------------- |
| Associação | `A --> B` | usa          | Independente  | Mago usa Magia               |
| Agregação  | `A o-- B` | tem (ref.)   | Separado      | Mago equipa Item             |
| Composição | `A *-- B` | é parte de   | Compartilhado | Mago contém Inventario       |
| Associação | `A --> B` | invoca       | Independente  | Druida invoca Familiar       |
| Composição | `A *-- B` | vínculo      | Compartilhado | Druida tem FamiliarVinculado |

> Em todos os casos acima, tratam-se de **tipos de Associação**. A diferença está no **nível de posse/vida** do objeto “parte”.

---

## 6) Dependência — “usa temporariamente”

A **dependência** é o relacionamento **mais fraco** entre classes.
Ela indica que uma classe **usa outra de forma transitória**, **sem armazená-la como atributo**.
É uma relação **temporária**, geralmente por meio de parâmetros de método, tipos de retorno ou variáveis locais.

Em UML, é representada por uma **seta tracejada (`..>`)**, indicando que uma mudança na classe fornecedora
pode afetar a classe cliente, mas **sem vínculo de ciclo de vida**.

---

### Diagrama simples (A ..> B)

![alt text](img/Dependencia.svg)

```puml
@startuml dependencia
class A
class B
A ..> B : usa temporariamente
@enduml
```

---

## Exemplo 1 — Mago e Feiticeiro

Um **Mago** pode pedir ajuda a um **Feiticeiro** para identificar um artefato mágico.
O Mago **não possui** um Feiticeiro como atributo; apenas **depende temporariamente** dele para realizar a tarefa.

### Diagrama UML (Dependência)

![alt text](img/DependenciaMago.svg)

```puml
@startuml dependenciaMago
class Mago
class Feiticeiro
Mago ..> Feiticeiro : consulta
@enduml
```

### Código C++

```cpp
#include <iostream>
#include <string>
using namespace std;

class Feiticeiro {
public:
    void identificarArtefato(string nome) {
        cout << "O Feiticeiro analisa o artefato '" << nome << "' com olhar sábio." << endl;
    }
};

class Mago {
public:
    void investigarArtefato(Feiticeiro f, string nome) {
        cout << "O Mago busca a ajuda de um Feiticeiro..." << endl;
        f.identificarArtefato(nome);
    }
};

int main() {
    Feiticeiro feiticeiro;
    Mago mago;
    mago.investigarArtefato(feiticeiro, "Amuleto do Caos");
}
```
**Análise:**
* `Mago` **usa** `Feiticeiro` apenas dentro do método `investigarArtefato`.
* Não há ponteiro, atributo ou ciclo de vida compartilhado.
* A relação é **pontual e efêmera**.
---

## Exemplo 2 — Alquimista e Ingrediente

O **Alquimista** utiliza um **Ingrediente** apenas durante o preparo de uma poção.
Após o método terminar, o ingrediente **não é armazenado** — o vínculo é temporário.

### Diagrama UML (Dependência)

![alt text](img/DependenciaAlquimista.svg)

```puml
@startuml dependenciaAlquimista
class Alquimista
class Ingrediente
Alquimista ..> Ingrediente : prepararPocao
@enduml
```

### Código C++

```cpp
#include <iostream>
#include <string>
using namespace std;

class Ingrediente {
public:
    string nome;
    Ingrediente(string n) : nome(n) {}
};

class Alquimista {
public:
    void prepararPocao(Ingrediente ing) {
        cout << "Misturando " << ing.nome << " na poção..." << endl;
    }
};

int main() {
    Ingrediente ingrediente("Raiz de Mandrágora");
    Alquimista alquimista;
    alquimista.prepararPocao(ingrediente);
}
```
**Análise:**
* O `Ingrediente` é passado como **parâmetro** e **não pertence** ao `Alquimista`.
* O método o usa apenas durante sua execução.
* Representa uma **dependência transitória**, típica de métodos utilitários.

---

### 📚 Referências



