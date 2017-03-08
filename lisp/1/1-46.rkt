#lang sicp
(define tolerence 0.000001)
(define (iterative-improve closeenough? improve)
  (lambda (x) (if (closeenough? x (improve x))
                  (improve x)
                  ((iterative-improve closeenough? improve) (improve x)))))

(define (closeenough? a b)
  (< (/ (abs (- a b)) b) tolerence))

(define (sqrt x)
  ((iterative-improve
    closeenough?
    (lambda (y) (/ (+ y (/ x y)) 2))) 1.0))

(define (fixed-point f first-guess)
  ((iterative-improve closeenough? f) first-guess))
    