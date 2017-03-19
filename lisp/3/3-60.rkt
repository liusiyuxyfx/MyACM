#lang planet neil/sicp
(define (mul-series s1 s2)
  (cons-stream
   (* (stream-car s1)
      (stream-car s2))
   (add-streams (mul-streams (stream-cdr s1)
                             (stream-cdr s2))
                (mul-series s1 s2))))