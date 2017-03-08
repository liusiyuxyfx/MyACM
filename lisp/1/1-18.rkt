#lang sicp
(define (double x) (+ x x))
(define (halve x) (/ x 2))
(define (* a b)
  (define (iter result x y)
    (cond ((= y 0) result)
          ((even? y) (iter result (double x) (halve y)))
          (else (iter (+ result x) x (- y 1)))))
  (iter 0 a b))
                           