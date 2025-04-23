
<h1 align="center">🍽️ Cardápio Digital em C</h1>
<p align="center">Um projeto simples em linguagem C para gerenciamento de um cardápio via terminal.</p>
<p align="center">A simple C project to manage a digital menu through the terminal.</p>

---

## 📌 Sobre o Projeto | About the Project

🔧 Este projeto é uma implementação de um **sistema de cardápio digital**, feito em **C**, com interação via terminal.  
🔧 This project is an implementation of a **digital menu system**, built in **C**, using terminal interaction.

Ele permite **criar**, **adicionar**, **remover**, **buscar**, **listar** e **liberar** itens de um cardápio digital.  
It allows you to **create**, **add**, **remove**, **search**, **list**, and **free** items from a digital menu.

---

## 📂 Estrutura do Projeto | Project Structure

```bash
📁 cardapio-digital/
├── main.c         # Execução principal do programa | Main program execution
├── cardapio.c     # Lógica das funcionalidades do cardápio | Core menu logic
├── cardapio.h     # Cabeçalho com declarações | Header with declarations
```

---

## ⚙️ Funcionalidades | Features

✅ Criar cardápio | Create menu  
✅ Inserir item | Add item  
✅ Remover item por ID | Remove item by ID  
✅ Buscar item por ID | Search item by ID  
✅ Listar todos os itens | List all items  
✅ Liberar memória utilizada | Free allocated memory  

---

## 💻 Como Compilar e Executar | How to Compile & Run

### 🐧 Linux/macOS:
```bash
gcc main.c -o cardapio
./cardapio
```

### 🪟 Windows:
```bash
gcc main.c -o cardapio.exe
cardapio.exe
```

> 📝 É necessário ter o GCC instalado.  
> 📝 GCC must be installed to compile.

---

## 🧪 Exemplo de Uso | Example Output

```
========= BEM VINDO =========
Por favor, selecione um.
1 ----- Criar cardápio
2 ----- Inserir item
3 ----- Remover item
4 ----- Buscar item
5 ----- Imprimir cardápio
0 ----- Sair
```

```
========= WELCOME =========
Please select an option.
1 ----- Create menu
2 ----- Add item
3 ----- Remove item
4 ----- Search item
5 ----- Print menu
0 ----- Exit
```

---

## 🎯 Objetivo | Purpose

🎯 O objetivo principal é servir como base para projetos simples de gerenciamento de informações via terminal, com manipulação de listas encadeadas.  
🎯 The main goal is to serve as a base for simple terminal-based management systems using linked lists.

---

## 🧑‍💻 Autor | Author

Feito com 💙 por **Renato S. Borges**  
Made with 💙 by **Renato S. Borges**
