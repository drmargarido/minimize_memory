#!/bin/bash
rm -f src/main.lit
cat src/base_main.lit > src/main.lit
cat src/benchmark_imports.lit >> src/main.lit