#lang planet neil/sicp
(define (square x) (* x x))
(define (square-tree tree) (tree-map square tree))
(define (tree-map proc tree)
  (if (null? tree)
      nil
      (if (pair? tree)
          (cons (tree-map proc (car tree))
                (tree-map proc (cdr tree)))
          (proc tree))))
(define tree1 (list 1
                    (list 2 (list 3 4) 5)
                    (list 6 7)))
(display (square-tree tree1))