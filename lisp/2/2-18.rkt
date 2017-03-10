#lang sicp
(define (reverse item)
  (define (reverse-iter item pos)
    (if (null? item)
        pos
        (reverse-iter (cdr item) (cons (car item) pos))))
  (reverse-iter item nil))