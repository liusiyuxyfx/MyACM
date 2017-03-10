#lang sicp
(define (last-pair item)
  (define (last-pair-iter item ans)
    (if (null? item)
        ans
        (last-pair-iter (cdr item) (car item))))
  (last-pair-iter (cdr item) (car item)))