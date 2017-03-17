#lang planet neil/sicp
(define (averager a b c)
  (let ((a-sum-b (make-connector))
        (x (make-connector)))
    (adder a b a-sum-b)
    (multiplier x c a-sum-b)
    (constant 2 x)
    'done))