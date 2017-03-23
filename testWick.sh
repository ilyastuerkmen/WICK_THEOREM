#!/bin/bash

make
cd src/testWickTheorem
../../bin/main
g++ *.C
./a.out > hanrathtest
cmp --silent hanrathtest mytest && echo '### SUCCESS: Files Are Identical! ###' || echo '### WARNING: Files Are Different! ###'
