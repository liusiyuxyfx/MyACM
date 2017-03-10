#lang planet neil/sicp 
;append: (1 2 3 4 5 6)
;cons: ((1 2 3) 4 5 6))
;list: ((1 2 3) (4 5 6))

(define x (list 1 2 3))
(define y (list 4 5 6))
(define (append list1 list2)
  (if (null? list1)
      list2
      (cons (car list1) (append (cdr list1) list2))))
(define a (append x y))
(display a)
(define b (cons x y))
(newline)
(display b)
(define c (list x y))
(newline)
(display c)