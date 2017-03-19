#lang planet neil/sicp
不行，因为这样会不断地调用(pairs (stream-cdr s) (stream-cdr t))