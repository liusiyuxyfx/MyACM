#lang planet neil/sicp 
(define x (list (list 1 2) (list 3 4)))

(define (deep-reverse items)
  (define (iter items ans)
    (if (null? items)
        ans
        (if (pair? (car items))
            (iter (cdr items) (cons (deep-reverse (car items)) ans))
            (iter (cdr items) (cons (car items) ans)))))
  (iter items nil))

(display (deep-reverse x))