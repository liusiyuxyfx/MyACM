#lang planet neil/sicp
(define (stream-limit s tolerance)
  (let ((s1 (stream-car s))
        (s2 (stream-car (stream-cdr s))))
    (if (< (abs (- s1 s2)) tolerance)
        s2
        (stream-limit (stream-cdr s) tolerance))))
(define (sqrt x tolerance)
  (stream-limit (sqrt-stream x) tolerance))