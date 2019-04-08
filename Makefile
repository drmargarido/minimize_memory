all:
	mkdir -p build
	mkdir -p build/gtk
	mkdir -p build/fltk

	# Compile each benchmark code one at a time so their implementation of the global macros will not override the other ones
	while read in; do echo $$in > src/benchmark_imports.lit && ./generate_main.sh && literate/lit --tangle src/main.lit --out-dir build/; done < src/imports.txt

	# Generate full documentation
	cat src/imports.txt > src/benchmark_imports.lit
	./generate_main.sh
	literate/lit --weave src/main.lit --out-dir build/
	cp -R images build/_book/

	# Compile each app
	cd build/gtk/ && make
	cd build/fltk/ && make

presentation:
	mkdir -p presentation
	pandoc --slide-level 2 -s presentation.md -t beamer -o presentation/presentation.pdf

clean:
	rm -f -R presentation
	rm -f -R build
