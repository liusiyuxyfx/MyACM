#lang planet neil/sicp
(define f
  (let ((a 0)
        (b 0))
    (lambda (x)
      (begin (set! a b)
             (set! b x)
             a))))