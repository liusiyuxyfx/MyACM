#lang sicp
(define (double f)
  (lambda (x) (f (sf x))))
(define (square x) (* x x))
(define (inc x) (+ x 1))