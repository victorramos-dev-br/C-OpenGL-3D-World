# 🏘️ Mini Projeto de Computação Gráfica - Cenário 3D em OpenGL

## 📌 Sobre o Projeto
Este repositório contém os códigos desenvolvidos para o Mini Projeto de Computação Gráfica, do curso da Faculdade de Petrolina - FACAPE, ministrado pelo docente Luirys Silva. 

O objetivo central da atividade era a construção de uma casa 3D em OpenGL. Como desafio extra, o projeto foi expandido para um pequeno bairro/cenário 3D completo. O projeto obteve nota máxima (10) na avaliação final.

## 🛠️ Versões do Projeto e Funcionalidades

O repositório está dividido em duas versões para demonstrar a evolução das mecânicas implementadas na linguagem C com a biblioteca OpenGL/GLUT.

### 1. Versão Base (Requisitos Acadêmicos)
Esta versão foca em cumprir e expandir os requisitos obrigatórios solicitados no projeto. O cenário possui:
* Estrutura principal com uma Casa em 3D.
* Telhado, porta e pelo menos 2 janelas.
* Interação básica: rotação da cena pelo teclado.
* Boas práticas de organização: funções separadas para os objetos, indentação adequada e comentários.

### 2. Versão Interativa (Mecânicas Avançadas)
Nesta versão, o mesmo bairro foi aprimorado com mecânicas de movimentação complexas e controle de câmera, adicionando elementos de *gameplay*:
* **Movimentação WASD:** Controle fluido pelo cenário.
* **Modo Criativo:** Permite que o personagem voe livremente pelo bairro, desativando a gravidade.
* **Modo Sobrevivência:** Ativa a gravidade, impedindo o voo contínuo e habilitando a mecânica de pulo.

## 💻 Tecnologias Utilizadas
* Linguagem C
* OpenGL
* GLUT (OpenGL Utility Toolkit)

## 🚀 Como Executar
Para compilar e executar o projeto (exemplo via terminal no Linux usando GCC):

```bash
gcc -o projeto arquivo.c -lGL -lGLU -lglut
./projeto