---
title: Que Stack Gráfica Escolher?
author: Daniel Margarido
date: \today
theme: CambridgeUS
colortheme: beaver
fontfamily: merriweather
header-includes:
    - \let\olditem\item \renewcommand{\item}{\setlength{\itemsep}{\fill}\olditem}
    - \newcommand{\begincols}[1]{\begin{columns}{#1}}
    - \newcommand{\stopcols}{\end{columns}}
    - \hypersetup{colorlinks=true, linkcolor=, urlcolor=blue}
---

## Indice

1. Problema
2. Estado atual
3. Foco de Análise
4. Consumos atuais
5. Aplicação de Notas - GKT
6. Aplicação de Notas - Swing
7. Aplicação de Notas - FLTK
8. Aplicação de Notas - X11 + Nuklear
9. Comparação de resultados
10. Dados de outros casos
11. Outras Alternativas
12. Conclusões
13. Motivação
14. Questões


# Problema

## Geral
* Equipamentos ficam mais lentos ao longo do tempo.

* A verdade é que não ficam.

* O software que usamos diariamente gasta cada vez mais recursos.

* E usufruimos assim tanto de mais funcionalidades do que era usado à uns 5 ou 10 anos?

## Minha Workstation

\begincols{}

\column{0.49\textwidth}

* 2 Motores 92RPM
* 1GB de RAM
* 8GB de armazenamento
* 4× ARM Cortex-A53, 1.2GHz
* Robot Tank Chasis


\column{0.49\textwidth}
![Raspberry Tank](images/raspberry.jpg)

\stopcols


# Estado atual
## Windows 10 Acabado de Ligar

Consumo de RAM: 2.4GB
![Windows](images/Windows_10.png)

## Firefox com tab de texto

Consumo de RAM: 514MB
![Firefox](images/firefox_text.png)

## Intellij IDEA Acabado de Abrir

Consumo de RAM: 848MB
![IDEA](images/idea.png)

## Discord

Consumo de RAM: 503.1MB
![Discord](images/discord.png)


# Foco de Análise

## Recursos

* Windows ocupa para cima de 2GB e mesmo o Ubuntu atual ocupa quase 1GB de RAM.

* 20MB de RAM é quanto ocupa um servidor OpenBSD acabado de instalar.

## Comparação

* Servidor que tem interface de linha de comandos vs um sistema com ambiente gráfico completo.

* 40x mais RAM, temos de tentar reduzir o máximo que conseguirmos.


# Consumos Atuais

## Metodologia

* Pesquisa de toolkit gráficos.

* Implementação de aplicação de notas.

* Inserção de notas no em ficheiro e a sua pesquisa.

* Em cada teste vamos medir:
    - Utilização de memória RAM
    - Simplicidade de implementação
    - Plataformas Suportadas

## Regras

* Tamanho de janela 400x300.

* Implementar apenas a interface usando o toolkit gráfico.

## Mockup da Aparência Desejada

![Mockup Interface](images/notes_mockup.png)

# Aplicação de Notas - GKT
## Apresentação

\begincols{}
\column{0.60\textwidth}

* Criado em 1998.
* Implementado em C.
* Desenvolvido pelo GNOME Project.
* Maioria dos ambientes gráficos mais utilizados em linux utilizam gtk.

\column{0.38\textwidth}
![GTK logo](images/gtk_logo.png)

\stopcols

---

## Resultado

\begincols{}

\column{0.49\textwidth}
![GTK Notas](images/gtk_notes.png)

\column{0.49\textwidth}
![GTK Notas](images/gtk_notes2.png)

\stopcols

---

## Avaliação
* Utilização de memória RAM - 26.54MB
* Plataformas Suportadas - GNU/Linux, Unix, Windows e Mac OS X
* Simplicidade de implementação:
    - Widgets baseados em GtkWidget.
    - Manual de fácil pesquisa e com boa documentação.
    - Glade para construção de interface só com drag and drop.
    - Trabalhoso usar as caixas de layout que são para definir posição dos widgets.

# Aplicação de Notas - Swing
## Apresentação
\begincols{}
\column{0.60\textwidth}

* Criado em 1997
* Implementado em Java
* Alternativa lightweight ao java AWT
* Desenha os próprios widgets sem utilizar os do sistema

\column{0.38\textwidth}
![Java logo](images/java_logo.jpg)

\stopcols

---

## Resultado

\begincols{}

\column{0.49\textwidth}
![Swing Notas](images/swing_notes.png)

\column{0.49\textwidth}
![Swing Notas](images/swing_notes2.png)

\stopcols

---

## Avaliação
* Utilização de memória RAM - 55.60MB
* Plataformas Suportadas - Platform-Independent
* Simplicidade de implementação:
    - Documentação nos standards do java mas sem pesquisa rápida.
    - Escassos exemplos de utilização.
    - Utilização simples permite posicionamento usando layouts e posicionamento directo na frame.

# Aplicação de Notas - FLTK
## Apresentação

\begincols{}
\column{0.60\textwidth}

* Criado em 1998
* Implementado em C++
* Usa um design mais leve e restringe-se apenas à funcionalidade de GUI
* Normalmente linkado de forma estática

\column{0.38\textwidth}
![FLTK logo](images/fltk_logo.gif)

\stopcols

---

## Resultado

\begincols{}

\column{0.49\textwidth}
![FLTK Notas](images/fltk_notes.png)

\column{0.49\textwidth}
![FLTK Notas](images/fltk_notes2.png)

\stopcols

---

## Avaliação

* Utilização de memória RAM - 9.84MB
* Plataformas Suportadas - GNU/Linux, Unix, Windows, macOS, AmigaOS 4
* Simplicidade de implementação:
    - Desenho de elementos na interface simples
    - Gestão de linhas e margens precisou de calculos manuais
    - Documentação tem os widgets bem documentados e aborda a maioria dos casos de uso
    - FLUID permite construir a interface com drag and drop


# Aplicação de Notas - Nuklear
## Apresentação
* Criado em 2015
* Implementado em ANSI C
* Immediate mode graphical user interface toolkit
* Zero dependências, recebe o input do estado atual e gera comandos de desenho de primitivas como output
* Backends atuais para desenhar estas primitivas - x11, d3d9, d3d11, gdl, gdlp, glfw, sdl com opengl, sfml com opengl, allegro5


## Resultado

\begincols{}

\column{0.49\textwidth}
![Nuklear + X11 Notas](images/nuklear_x11_2.png)

\column{0.49\textwidth}
![Nuklear + X11 Notas](images/nuklear_x11.png)

\stopcols

## Avaliação
* Utilização de memória RAM - 3.9MB
* Plataformas Suportadas - Depende dos backends de render
* Simplicidade de implementação:
    - Utilização de contextos para desenhar demora um pouco a entender
    - Desenho por layout e posições absolutas
    - Documentação limitada
    - Utilização envolve ainda alguma leitura de código para escolher backends e perceber como é a integração

# Comparação de resultados
## Comparação

![Toolkits Comparison](images/toolkits_comparison.png)


# Dados de outros casos

## Electron

\begincols{}

\column{0.70\textwidth}

* Hello World utiliza 125MB de RAM
* Rapidamente flutua para valores mais altos
* Chromium com aplicação no topo

\column{0.20\textwidth}
![Electron Logo](images/electron_logo.png)

\stopcols

---

## Electron Example

![Slack](images/slack.jpg)

---

## Tekui

\begincols{}

\column{0.70\textwidth}

* Hello World utiliza 9.8MB de RAM
* Utiliza Lua para scripting
* Permite mudar estilos com CSS
* Cross-Platform

\column{0.20\textwidth}
![Tekui Logo](images/tekui_logo.png)

\stopcols

---

## Tekui Example

![Tekui Usage](images/tekui_example.png)

---


## Wayland Client


\begincols{}

\column{0.70\textwidth}

* Hello World utiliza - 868KB de RAM
* Disponibiliza um pixelbuffer
* É preciso implementar toda a stack
* Alternativa Wayland + ImGui

\column{0.20\textwidth}
![Wayland](images/wayland_logo.png)

\stopcols


# Outras Alternativas para Testar

## Com muitas funcionalidades

* QT
* .NET

## Lightweight

* tk
* motif
* IUP
* SDL

## Sistema

* Win32
* X.org


# Conclusões

## Conclusões

* Toolkits mais apelativos
* Maximizar a produtividade
* Cross-platform
* É possivel reduzir o consumo de memória


# Motivação

## Futuro

* Manter o raspberry como máquina de trabalho durante mais uns 5 anos
* Não ter de trocar de hardware de 2 em 2 anos


# Questões

## Contactos


\begincols{}

\column{0.64\textwidth}

* Email:
	- drmargarido@gmail.com
* Apresentação:
	- [https://github.com/drmargarido/minimize_memory](https://github.com/drmargarido/minimize_memory)

* Github:
	- [https://github.com/drmargarido](https://github.com/drmargarido)
* Bitbucket:
	- [https://bitbucket.org/Alface0/](https://bitbucket.org/Alface0/)
* Itch.io:
	- [https://drmargarido.itch.io/](https://drmargarido.itch.io/)

\column{0.35\textwidth}
![Duvidas](images/question_mark.gif)

\stopcols
