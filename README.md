# 🎲 Jogo Jokenpo em C (Pedra, Papel e Tesoura)

Este repositório contém o código-fonte de um jogo de Jokempo (Pedra, Papel e Tesoura) desenvolvido em Linguagem C. O projeto foi criado como um exercício prático para reforçar conceitos de programação estruturada, como o uso de funções, structs e ponteiros.

## 📜 Descrição do Projeto

O programa apresenta ao usuário um menu interativo com opções para iniciar uma nova partida, consultar as regras do jogo ou encerrar a aplicação. Ao iniciar o jogo, o usuário joga contra o computador, que escolhe sua jogada (Pedra, Papel ou Tesoura) de forma aleatória. O programa então compara as escolhas e declara o resultado da partida: vitória, derrota ou empate.

## ✨ Funcionalidades

* **Menu Principal:** Interface de texto simples para navegação.
* **Regras do Jogo:** Seção informativa que explica as regras de Jokenpo.
* **Oponente Aleatório:** O computador utiliza a hora atual do sistema como semente para gerar uma jogada verdadeiramente aleatória a cada partida.
* **Lógica de Jogo:** Implementação completa das regras de vitória, derrota e empate.
* **Código Modular:** O programa é bem organizado em funções distintas para o menu e a lógica do jogo, facilitando a leitura e a manutenção.

## 🚀 Como Compilar e Executar

Para compilar e executar este projeto, você precisará de um compilador C, como o GCC, que é padrão na maioria dos sistemas Linux e pode ser facilmente instalado no Windows (via MinGW/MSYS2) ou macOS.

**1. Clone ou baixe este repositório.**

**2. Abra um terminal na pasta do projeto.**

**3. Compile o código-fonte:**
```bash
gcc jokenpo.c -o jokempo
