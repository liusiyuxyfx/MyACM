#lang sicp
(define (f n)
  (cond ((< n 3) n)
        (else (+ (f (- n 1))
                 (* 2 (f (- n 2)))
                 (* 3 (f (- n 3)))))))
(define (f2 n)
  (g 2 1 0 n))
(define (g x y z max)
  (if (= max 0) z
      (g (+ x (* 2 y) (* 3 z)) x y (- max 1))))