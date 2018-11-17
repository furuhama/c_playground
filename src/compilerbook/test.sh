#!/bin/bash

try() {
  input="$1"
  expected="$2"

  ./0cc "$input" > tmp.s
  gcc tmp.s -o tmp
  ./tmp
  actual="$?"

  if [ "$actual" != "$expected" ]; then
    echo "$expected expected with input $input, but got $actual"
    exit 1
  fi
}

try 0 0
try 42 42

try '5-5+10-10' 0
try '20+31-9' 42

echo OK
