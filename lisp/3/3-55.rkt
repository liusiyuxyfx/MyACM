;#lang planet neil/sicp
;分析
;stream-cdr  0         S1          S2              S3
;ps:         0         S0         S0+S1         S0+S1+S2
;---------------------------------------------------------------
;ps:         S0       S0+S1      S0+S1+S2      S0+S1+S2+S3
(define (partial-sums s)
  (cons-stream (stream-car s) (add-streams (stream-cdr s) (partial-sums s))))