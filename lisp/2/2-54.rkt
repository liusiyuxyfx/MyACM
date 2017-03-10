#lang planet neil/sicp
(define (equal? list1 list2)
  (cond ((and (not (pair? list1))
             (not (pair? list2)))
        (eq? list1 list2))
        ((and (pair? list1) (pair? list2))
         (and (equal? (car list1) (car list2))
              (equal? (cdr list1) (cdr list2))))
        (else false)))

(display (equal? '(this is a list) '(this is a list)))
(newline)
(display (equal? '(this is a list) '(this (is a) list)))
      