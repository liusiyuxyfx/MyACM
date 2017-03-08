#lang sicp
(define (pasca x y)
  (cond ((= x y) 1)
        ((= y 0) 1)
        (else (+ (pasca (- x 1) (- y 1))
                 (pasca (- x 1) y)))))
