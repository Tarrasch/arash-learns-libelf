#!/bin/zsh

gcc listing-sections.c -lelf -lbsd

./a.out a.out

./a.out /usr/lib/libdialog.a

./a.out ~/repos/ghc/inplace/bin/ghc-stage2

ghc Main.hs -o Main
./a.out Main
