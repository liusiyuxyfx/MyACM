#lang sicp
(define (cons x y)
  (lambda (m) (m x y)))
(define (car1 z)
  (z (lambda (p q) p)))