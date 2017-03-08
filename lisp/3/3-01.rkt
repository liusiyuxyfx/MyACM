#lang sicp
(define (make-accumulator amount)
  (lambda (x)
    (begin (set! amount (+ x amount)) amount)))
(define a (make-accumulator 100))
(a 10)
(a 20)
