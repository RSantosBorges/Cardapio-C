
<h1 align="center">🍽️ Cardápio Digital em C</h1>
<p align="center">Um projeto simples e didático de gerenciamento de cardápio usando linguagem C.</p>

---

## 📌 Sobre o Projeto | About the Project

🔧 Este projeto implementa um **sistema de cardápio digital** no terminal, utilizando **C puro**, com foco em fins educacionais.  
It allows you to **create**, **add**, **remove**, **search**, **list**, and **free** items from a digital menu, all through the terminal interface.

---

## 📂 Estrutura do Projeto | Project Structure

```bash
📁 cardapio-digital/
├── main.c         # Arquivo principal com a lógica do menu principal
├── cardapio.c     # Implementação das funções do cardápio
├── cardapio.h     # Cabeçalho contendo declarações e struct
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

> 📝 *É necessário ter o compilador GCC instalado. No Windows, você pode usar o [MinGW](http://www.mingw.org/).*

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

---

## 🎯 Objetivos Educacionais | Educational Goals

📘 Com este projeto você aprende sobre:
- Ponteiros e listas encadeadas
- Alocação dinâmica de memória (`malloc`, `free`)
- Organização modular com arquivos `.h` e `.c`
- Manipulação de strings e entrada de dados em C
- Boas práticas em terminal com `system("cls")`, `sleep()`, etc.

---

## 🧑‍💻 Autor | Author

Feito com 💙 por **Seu Nome Aqui**  
Sinta-se à vontade para usar, estudar ou modificar o projeto.

---

## 📜 Licença | License

Este projeto está disponível sob a licença MIT.  
This project is licensed under the MIT License.
