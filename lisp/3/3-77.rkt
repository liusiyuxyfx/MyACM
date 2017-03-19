#lang planet neil/sicp
(define (integral delayed-integrand initial-value dt)
  (cons-stream initial-value
               (if (stream-null? (force delayed-integrand))
                   the-empty-stream
                   (integral (delay (stream-cdr integrand))
                             (+ (* dt (stream-car integrand))
                                initial-value)
                             dt))))