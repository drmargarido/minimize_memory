---
title: Reduzir RAM em Aplicações Gráficas
subtitle: ENEI 2019
author: Daniel Margarido
date: \today
theme: CambridgeUS
colortheme: beaver
fontfamily: merriweather
header-includes:
    - \let\olditem\item \renewcommand{\item}{\setlength{\itemsep}{\fill}\olditem}
---

## Indice

1. Estado atual/Problema
2. O que podemos fazer
3. Base de testes
4. Stacks Principais
5. Alternativas Mais Leves
6. Interação directa com sistema
7. Missão redução máxima
8. Comparação de resultados
9. Conclusões


# Estado atual/Problema

## Panorama atual 

* Os sistemas continuam a crescer como se toda a gente tivesse 64GB de RAM
* 20MB de ram chegam para ter um servidor
* O sistemas populares mais pequenos com parte gráfica ainda são grandes demais
* Troca regular de hardware desnecessária
* Aplicações a ficarem mais pesadas a cada dia que passa

## Exemplos - Windows

* Windows 10 - 2GB
 
## Exemplos - Ubuntu 18.04

* Ubuntu + Gnome - 700MB

## Exemplos - Kubuntu 18.04

* Ubuntu + KDE - 1GB


# Ações possiveis
## Como developers o que podemos fazer

* Podemos tentar reduzir o consumo de recursos da nossas aplicações
* Perceber realmente que funcionalidades vamos utilizar do toolkit gráfico, de modo a podermos selecionar algo mais leve que permita a mesma funcionalidade


# Comparação entre consumo de recursos

## Base de testes

* Aplicação para tirar notas e pesquisar mais tarde
* Backend implementado com shell scripts isolando a UI da lógica da inserção e pesquisa
* Tamanho da janela - 400x300
* Parametros de avaliação:
    + Utilização de memória RAM
    + Simplicidade de implementação
    + Multiplataforma

---

* Versão command line da aplicação

## Stacks Principais - .NET
## Stacks Principais - GTK
## Stacks Principais - QT

## Alternativas Mais Leves - Enlightment
## Alternativas Mais Leves - FLTK
## Alternativas Mais Leves - tk
## Alternativas Mais Leves - motif
## Alternativas Mais Leves - SDL?
## Alternativas Mais Leves - IUP
## Alternativas Mais Leves - Tekui

## Interação directa com sistema - Win32
## Interação directa com sistema - X.org
## Interação directa com sistema - Wayland


# Missão redução máxima

# Comparação de resultados

# Conclusões