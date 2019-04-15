# minimize_memory

Memory Reduction Presentation and Benchmark

## Compile Code

The code of the benchmark programs is in the src folder. I used a technique called literate programming using the (Literate)[https://github.com/zyedidia/Literate] code generator.

Just by using make the executables will be generated.

```
make
```

## Generate Presentation

Presentation is generated with beamer. So pandoc will be necessary to generate the presentation. Since pandoc translates de presentation mardown to latex a latex compiler must be available also.

```sh
make presentation
```

## Add New Benchmark

1. Create a file for you benchmark implementation in the src folder
2. Add a new entry to the src/imports.txt file
3. Implement
4. Change the base Makefile accordingly


**Note** - It's a good ideia to use fltk or gtk as a base.


## Contributors

* Daniel Margarido