all:
	mkdir -p build
	mkdir -p build/gtk
	literate/./lit src/main.lit --out-dir build/
	cp -R images build/_book/
	cd build/gtk/ && make

presentation:
	mkdir -p presentation
	pandoc --slide-level 2 -s presentation.md -t beamer -o presentation/presentation.pdf

clean:
	rm -f -R presentation
	rm -f -R build
