all:
	pandoc --slide-level 2 -s presentation.md -t beamer -o presentation.pdf

clean:
	rm presentation.pdf
