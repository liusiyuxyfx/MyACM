#lang planet neil/sicp 
(define (monte-carlo trials experiment) 
   (define (iter trials-remaining trials-passed) 
     (cond ((= trials-remaining 0) 
             (/ trials-passed trials)) 
           ((experiment) 
             (iter (- trials-remaining 1) (+ trials-passed 1))) 
           (else 
             (iter (- trials-remaining 1) trials-passed)))) 
   (iter trials 0))

(define (random-in-range low high)
  (let ((range (- high low)))
    (+ low (random range)))) 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (p x y)
  (< (+ (expt (- x 1.0) 2)
        (expt (- y 1.0) 2))
     1.0))
(define (estimate-integral p x1 x2 y1 y2 trials)
  (let ((range1 (random-in-range x1 x2))
        (range2 (random-in-range y1 y2)))
    (monte-carlo trials (p range1 range2))))
