#!/bin/bash
for c_file in $(find . -name '*.c')
do
  echo [testing] "$c_file"
  riscv64-unknown-elf-gcc -o tmp "$c_file"
  qemu-riscv64 tmp
  expected="$?"

  ../build/easycc "$c_file" -o tmp.s || exit
  riscv64-unknown-elf-gcc -o tmp tmp.s
  qemu-riscv64 tmp
  actual="$?"
  rm tmp.s
  rm tmp

  if [ "$actual" = "$expected" ]; then
    echo "$c_file => $actual"
  else
    echo "$c_file => $expected expected, but got $actual"
    exit 1
  fi

done 
echo OK
