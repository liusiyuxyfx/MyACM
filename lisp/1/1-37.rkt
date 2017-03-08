#lang sicp
;a
(define (con-frac n d k)
  (define (loop result i)
    (if (= i 0)
        result
        (loop (/ (n i)
                 (+ (d i) result))
              (- i 1))))
  (loop 0 k))

;b
(define (con-frac2 n d k)
  (cond ((= k 0) 0)
        (else (/ (n k) (+ (d k) (con-frac2 n d (- k 1)))))))