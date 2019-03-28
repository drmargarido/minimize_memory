all:
	mkdir build
	literate/./lit benchmarks.lit --out-dir build/

presentation:
	mkdir presentation
	pandoc --slide-level 2 -s presentation.md -t beamer -o presentation/presentation.pdf

clean:
	rm -R presentation
	rm -R build
