#lang planet neil/sicp
;a
(define (integrate-series s)
  (stream-map /
              ones
              integers))
;b
(define cosine-series (cons-stream 1 (itegrate-serie
                                      (scale-stream sine-series -1))))
(define sine-series (cons-stream 0 (integrate-series cosine-sries)))