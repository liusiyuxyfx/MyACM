#lang sicp
(define (compose f g)
  (lambda (x) (f (g x))))
(define (repeated f cnt)
  (cond ((= cnt 0) (lambda (x) x))
         (else (compose f (repeated f (- cnt 1))))))