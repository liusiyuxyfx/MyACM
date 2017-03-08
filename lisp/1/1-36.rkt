#lang sicp

(define tolerence 0.0001)
(define (fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerence))
  (define (try guess)
    (display guess)
    (newline)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try first-guess))
(define (average x y) (/ (+ x y) 2))
(define (ans1 x y) (fixed-point (lambda (x) (/ (log y) (log x))) 10.0))
(define (ans2 x y) (fixed-point (lambda (x) (average x (/ (log y) (log x))) 10.0)))