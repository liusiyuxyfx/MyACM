#lang planet neil/sicp
(define (monte-carlo experiment-stream passed failed)
  (define (next passed failed)
    (cons-stream
     (/ passed (+ passed failed))
     (monte-carlo
      (stream-cdr experiment-stream) passed failed)))
  (if (stream-car experiment-stream)
      (next (+ passed 1) failed)
      (next passed (+ failed 1))))

(define (random-in-range-stream low high) 
    (let ((random-number (+ low (random (- high low)))))
      (cons-stream random-number
                   (random-in-range-stream rand-number high))))
(define (estimate-integral p x1 x2 y1 y2)
  (let ((range1 (random-in-range-stream x1 y1))
        (range2 (random-in-range-stream x2 y2))
        (area (* (- x2 x1) (- y2 y1))))
    (scale-stream (monte-carlo (stream-map p range1 range2) 0 0) area)))
    