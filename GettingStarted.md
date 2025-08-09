# Configuração do Ambiente de Programação em C/C++ com o Visual Studio Code

Este tutorial irá guiá-lo pela instalação e configuração do ambiente para rodar projetos em linguagem C/C++ utilizando a IDE (Integrated Development Environment) **VS Code** e o **MinGW-UCRT64** como compilador (portanto, no **Windows** <img src="https://github.com/user-attachments/assets/ad835449-5f61-4907-a116-b9ced2c8e30d" alt="MS Windows Logo" height="16" style="vertical-align: middle;" />).

## ⚠️ Importante: Diferenças entre Windows, Linux e macOS

Este tutorial foi desenvolvido para Windows utilizando MSYS2 UCRT64 como ambiente de compilação. Caso esteja utilizando Linux ou macOS, algumas configurações podem ser diferentes, especialmente na escolha do compilador C/C++.

Para configurar corretamente o compilador no VS Code no Linux ou no MacOS, siga os guias oficiais:

🔗 [Linux: Configuração do VS Code para C++ no Linux](https://code.visualstudio.com/docs/cpp/config-linux)  
🔗 [macOS: Configuração do VS Code para C++ no macOS](https://code.visualstudio.com/docs/cpp/config-clang-mac)  

---

## 📌 1. Instalando as Ferramentas Necessárias

Antes de começar, certifique-se de ter os seguintes programas instalados:

### 1️⃣ Instalar o Compilador MinGW-UCRT64 através do <img src="https://github.com/user-attachments/assets/a473c44b-1fe1-4399-911a-d921225f53a6" alt="MSYS2 Logo" width="32" style="vertical-align: middle;" />


Baixe o **MSYS2** através do link:
🔗 [MSYS2 Download](https://www.msys2.org/)

Provavelmente ao terminar de instalar, abrirá um terminal. Caso isso não aconteça, digite "msys" na barra de pesquisa do Windows e entre neste aplicativo:

 <img src="https://github.com/user-attachments/assets/8d5603b3-6338-4235-9775-6aeaa900da7d" alt="" width="256" align="middle"/>

Execute o seguinte comando para instalar os pacotes necessários:

```sh
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```
Na primeira questão que aparecer, apenas digite `ENTER`. Na segunda [Y/N], digite `Y`.

Caso queira ou necessite de mais suporte nesta etapa, consulte o manual oficial:

🔗 [Configuração do VS Code para C++ no Windows](https://code.visualstudio.com/docs/cpp/config-mingw)

### Configurando a variável de ambiente no Sistema Operacional (Windows)

Esse passo garante que o sistema operacional encontre o compilador automaticamente ao rodar comandos no terminal, sem precisar especificar o caminho completo. A forma mais simples de fazer isso (se você tiver permissão de administrador do sistema) é a seguinte:

 - Edite a variável de caminhos do sistema operacional (`PATH`), acrescentando o caminho onde ficaram os executáveis do compilador (provavelmente ficaram em `C:\msys64\ucrt64\bin` - ou onde você escolheu instalar)

<img src="https://github.com/user-attachments/assets/645846a5-38e2-4a26-a307-a961afb80116" alt="" style="width:30%; height:auto;" align="middle"/>
<img src="https://github.com/user-attachments/assets/89bc66d1-c269-45ac-9f5f-e528325a9e95" alt="" style="width:30%; height:auto;" align="middle"/>
<img src="https://github.com/user-attachments/assets/25c305fa-239c-4119-afd3-20d8dbf318e6" alt="" style="width:30%; height:auto;" align="middle"/>

 - Se estiver em um computador que não tenha acesso de adm, adicionar temporariamente ao path com este comando (via terminal CMD): 
```sh
   set PATH=%PATH%;C:\msys64\ucrt64\bin
```
---

### 2️⃣ Instalar o VS Code <img src="https://github.com/user-attachments/assets/0b0e314b-8910-4311-b862-8f4c2e012d33" alt="Visual Studio Code Logo" width="32" style="vertical-align: middle;" />

Baixe e instale o **VS Code** pelo link:
🔗 [VS Code Download](https://code.visualstudio.com/)

Após a instalação, abra o **VS Code** e instale a seguinte extensão:

- **C/C++** ➝ Para suporte à IntelliSense e depuração.
  
Para isso, você pode ir no menu View -> Extensions ou clicar no ícone <img src="https://github.com/user-attachments/assets/ce6873db-1dbb-4a74-887f-4ea90f90dfc4" alt="" width="32" style="vertical-align: middle;" /> da interface do Visual Studio Code.

---
