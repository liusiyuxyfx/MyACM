;#lang planet neil/sicp
(define (mul-streams s1 s2)
  (stream-map * s1 s2))
;分析：
;pos:         0      1      2      3      4
;stream-cdr:  1      2      3      4      5
;fac:         1      1      2!     3!     4!
;-------------------------------------------------------
;fac:         1      2!     3!     4!     5!
(define factorials
  (cons-stream 1
               (mul-streams facorials
                            (stream-cdr integers))))