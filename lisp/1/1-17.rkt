#lang sicp
(define (double a) (+ a a)) 
(define (halve a) (/ a 2)) 
  
(define (* a b) 
  (cond ((= b 0) 0) 
        ((even? b) (double (* a (halve b)))) 
        (else (+ a (* a (- b 1)))))) 