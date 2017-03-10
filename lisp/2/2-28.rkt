#lang planet neil/sicp
(define (append list1 list2)
  (if (null? list1)
      list2
      (cons (car list1) (append (cdr list1) list2))))
(define (fringe items)
  (if (null? items)
      nil
      (if (pair? items)
          (append (fringe (car items)) (fringe (cdr items)))
          (list items))))
(define x (list (list 1 2) (list 3 4)))
(display (fringe x))
(newline)
(display (fringe (list x x)))