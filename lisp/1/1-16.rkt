#lang sicp
(define (fast-expt b n)
  (iter b n 1))
(define (square x) (* x x))
(define (iter b counter a)
  (cond ((= counter 0) a)
        ((even? counter) (iter (square b) (/ counter 2) a))
        (else (iter b (- counter 1) (* a b)))))