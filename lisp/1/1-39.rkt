#lang sicp
(define (square x) (* x x))
(define (tan-cf x k)
  (define (iter result i)
    (cond ((= i 0) result
                   (iter (/ (if (= i 1)
                                x
                                (square x))
                            (- (- (* 2 i) 1) result))
                         (- i 1)))))
  (iter 0 k))