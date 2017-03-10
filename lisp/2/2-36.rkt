#lang planet neil/sicp 
(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))

(define (accumulate-n op init seqs)
  (if (null? (car seqs))
      nil
      (cons (accumulate op init (map car seqs))
            (accumulate-n op init (map cdr seqs)))))

(define s (list (list 1 2 3)
                (list 4 5 6)
                (list 7 8 9)
                (list 11 12 13)))
(display (accumulate-n + (- 1) s))