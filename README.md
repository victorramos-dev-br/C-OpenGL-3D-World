# 🏘️ Mini Projeto de Computação Gráfica - Cenário 3D em OpenGL

## 📌 Sobre o Projeto
Este repositório contém os códigos desenvolvidos para o Mini Projeto de Computação Gráfica, do curso da Faculdade de Petrolina - FACAPE, ministrado pelo docente Luirys Silva. 

O objetivo central da atividade era a construção de uma casa 3D em OpenGL. Como desafio extra, o projeto foi expandido para um pequeno bairro/cenário 3D completo. 
O projeto foi apresentado oficialmente no dia **08/06**, cumprindo o cronograma da disciplina, e obteve nota máxima (10) na 2º avaliação.

## 🛠️ Versões do Projeto e Funcionalidades

O repositório está dividido em duas versões para demonstrar a evolução das mecânicas implementadas na linguagem C com a biblioteca OpenGL/GLUT.

### 1. Versão Base (Requisitos Acadêmicos)
Esta versão foca em cumprir os requisitos obrigatórios solicitados no projeto, mas já expandidos para um formato de bairro. O cenário possui:
* **Bairro completo:** Rua, prédios, casas, sol/lua, cercas e árvores compondo o ambiente.
* **Estrutura principal:** Casas em 3D detalhadas.
* **Detalhes da casa:** Telhado, porta e janelas.
* **Interação básica:** Rotação da cena utilizando o teclado.
* **Boas práticas:** Funções separadas para os objetos, indentação adequada e comentários.

### 2. Versão Interativa (Mecânicas Avançadas)
Nesta versão, o mesmo bairro foi aprimorado com mecânicas complexas de física e controle, adicionando elementos de *gameplay*:
* **Movimentação WASD:** Controle fluido para andar pelo cenário.
* **Câmera Livre (Mouse):** Controle da visão em primeira pessoa movimentando o mouse pela tela.
* **Modo Criativo:** Permite que o personagem voe livremente pelo bairro, desativando a gravidade.
* **Modo Sobrevivência:** Ativa a gravidade, impedindo o voo contínuo e habilitando a mecânica de pulo com a barra de espaço.

## 💻 Tecnologias Utilizadas
* Linguagem C
* OpenGL
* GLUT (OpenGL Utility Toolkit)

## 🚀 Como Executar
Para compilar e executar o projeto (exemplo via terminal no Linux usando GCC):

```bash
g++ -o projeto cenario_interativo.cpp -lGL -lGLU -lglut
./projeto 
```
