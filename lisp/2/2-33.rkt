#lang planet neil/sicp
(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))
(define (map p sequence)
  (accumulate (lambda (x y)
                (cons (p x) y))
              nil
              sequence))
(define (append seq1 seq2)
  (accumulate cons seq1 seq2))
(define (length sequence)
  (accumulate (lambda (x y)
                (+ 1 y))
              0
              sequence))