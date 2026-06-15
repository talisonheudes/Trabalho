# 🐝 BeeVision – Sistema de Identificação e Monitoramento de Abelhas

## 📋 Informações do Projeto

**Disciplina:** Algoritmos e Programação I

**Professora:** Dra. Alcilene Dalília de Sousa

**Integrantes:**

* Talison Heuddes
* Kauan Sousa
* Samuel Leal

---

## 📖 Sobre o Projeto

O **BeeVision** é um sistema desenvolvido em linguagem C para auxiliar no cadastro, monitoramento e identificação de abelhas sem ferrão.

O projeto permite gerenciar informações sobre diferentes espécies de abelhas, sensores ambientais associados às colmeias e realizar classificações baseadas nos dados cadastrados.

---

## 🎯 Objetivos

* Cadastrar espécies de abelhas sem ferrão;
* Registrar sensores ambientais;
* Consultar informações cadastradas;
* Monitorar dados relacionados às colmeias;
* Auxiliar na identificação de espécies através de regras de classificação.

---

## ⚙️ Funcionalidades

### 🐝 Gerenciamento de Abelhas

* Cadastro de abelhas;
* Listagem de registros;
* Busca por identificação;
* Armazenamento de informações biológicas.

### 🌡️ Gerenciamento de Sensores

* Cadastro de sensores ambientais;
* Monitoramento de dados coletados;
* Associação de sensores às colmeias.

### 🔎 Sistema de Identificação

* Classificação textual de espécies;
* Aplicação de regras para reconhecimento de abelhas;
* Auxílio à tomada de decisão.

---

## 🛠 Tecnologias Utilizadas

* Linguagem C
* GCC (GNU Compiler Collection)
* Estruturas de dados com vetores e structs
* Modularização com arquivos `.h` e `.c`

---

## 📁 Estrutura do Projeto

```text
BeeVision/
│
├── include/
│   ├── abelha.h
│   ├── sensor.h
│   └── utils.h
│
├── src/
│   ├── abelha.c
│   ├── sensor.c
│   └── utils.c
│
├── main.c
└── README.md
```

---

## 🔨 Compilação

No terminal, navegue até a pasta do projeto e execute:

```bash
cd C:\Local_do_arquivo\QueenBeen

gcc -I include src/*.c main.c -o QueenBeen.exe
```

---

## ▶️ Execução

Após a compilação:

```bash
.\QueenBeen.exe
```

---

## ⚠️ Bugs Conhecidos

Atualmente o sistema **não possui persistência de dados em arquivo**.

Isso significa que:

* Todos os cadastros permanecem apenas na memória durante a execução;
* Ao fechar o programa, os dados são perdidos;
* A implementação de salvamento em arquivos será adicionada em versões futuras.

---

## 🚀 Melhorias Futuras

* Persistência de dados em arquivos;
* Exportação de relatórios;
* Interface gráfica;
* Integração com sensores reais;
* Aprimoramento do algoritmo de identificação;
* Estatísticas e análises ambientais.

---

## 📄 Licença

Projeto desenvolvido exclusivamente para fins acadêmicos na disciplina de **Algoritmos e Programação I**.
