#lang sicp
;a
(define (accumulate combiner null-value term a next b)
  (if (> a b)
      null-value
      (combiner (term a) (accumulate combiner null-value term (next a) next b))))
;b
(define (accumulate2 combiner null-value term a next b)
  (define (iter result a)
    (if (> a b)
        result
        (iter (combiner result (term a)) (next a)))))