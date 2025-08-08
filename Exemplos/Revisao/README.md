# Projeto Exemplo — Funções e `struct` (C++)

Pequeno exemplo para compilar **`main.cpp`** e **`biblioteca.cpp`** (com **`biblioteca.h`** incluído nos `.cpp`).

```
.
├── main.cpp
├── biblioteca.h
└── biblioteca.cpp
```

---

## 1) Compilar via terminal (g++)

```bash
g++ main.cpp biblioteca.cpp -o programa
```

**O que acontece aqui?**
- `main.cpp` e `biblioteca.cpp`: os dois arquivos fonte a serem compilados e ligados.
- `-o programa`: define o nome do executável de saída (`programa` ou `programa.exe` no Windows).
- Você **não** passa o `.h` no comando — ele é incluído dentro dos `.cpp` com `#include "biblioteca.h"`.

Para executar:
```bash
./programa         # Linux/macOS
.\programa.exe     # Windows
```

---

## 2) Configurar um build simples no VS Code (`tasks.json`)

### Passo a passo
1. Abra o **Command Palette** (`Ctrl+Shift+P`).
2. Procure por **“Tasks: Configure Default Build Task”**.
3. Escolha **“C/C++: g++ build active file”** (qualquer uma para gerar a base).
4. O VS Code criará `.vscode/tasks.json`. Substitua o conteúdo por:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Compilar (g++)",
      "type": "shell",
      "command": "g++",
      "args": [
        "main.cpp",
        "biblioteca.cpp",
        "-o",
        "programa"
      ],
      "group": { "kind": "build", "isDefault": true },
      "problemMatcher": ["$gcc"]
    }
  ]
}
```

### Como usar
- `Ctrl+Shift+B` → selecione **Compilar (g++)** → gera o executável `programa`.

### Principais parâmetros (explicação rápida)
- **`label`**: nome que aparece na lista de tarefas do VS Code.
- **`type: "shell"`**: roda o comando no shell do sistema.
- **`command`**: executável a invocar (aqui, `g++`).
- **`args`**: argumentos passados ao `g++` (arquivos `.cpp` e `-o programa`).
- **`group.kind: "build"`**: classifica como tarefa de build.
- **`group.isDefault: true`**: vira a tarefa padrão de `Ctrl+Shift+B`.
- **`problemMatcher: ["$gcc"]`**: interpreta erros/avisos do compilador na aba **Problems** do VS Code.

> Dica: Se seus `.cpp` estiverem em subpastas, você pode adicionar `"options": { "cwd": "${workspaceFolder}" }` para garantir o diretório base correto.
