#lang sicp
(define (postive? x) (>= x 0))
(define (negative? x) (< x 0))
(define (make-rat x y)
  (cond ((and (postive? x) (negative? y)) (cons (- x) y))
        ((and (negative? x) (postive? y)) (cons x y))
        (else (cons (abs x) (abs y)))))