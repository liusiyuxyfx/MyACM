#lang planet neil/sicp
(define (make-tree entry left right)
    (list entry left right))

(define (entry tree)
    (car tree))

(define (left-branch tree)
    (cadr tree))

(define (right-branch tree)
    (caddr tree))
(define (tree->list-1 tree)
    (if (null? tree)
        '()
        (append (tree->list-1 (left-branch tree))
                (cons (entry tree)
                      (tree->list-1 (right-branch tree))))))
(define (tree->list-2 tree)
    (define (copy-to-list tree result-list)
        (if (null? tree)
            result-list
            (copy-to-list (left-branch tree)
                          (cons (entry tree)
                                (copy-to-list (right-branch tree)
                                              result-list)))))
  (copy-to-list tree '()))

;a 相同
;b 1的复杂度高O（n^2),2的复杂度为O(N),差别在append和cons的使用上