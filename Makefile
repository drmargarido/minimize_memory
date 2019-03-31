all:
	mkdir -p build
	mkdir -p build/gtk
	cp -R images build/
	literate/./lit benchmarks.lit --out-dir build/

presentation:
	mkdir -p presentation
	pandoc --slide-level 2 -s presentation.md -t beamer -o presentation/presentation.pdf

clean:
	rm -f -R presentation
	rm -f -R build
