#lang sicp
(define (same-parity a . z)
  (define x (if (even? a)
                  0
                  1))
  (define (iter item ans)
    (if (null? item)
        ans
        (iter (cdr item)
              (if (= (remainder (car item) 2) x)
                  (append ans (list (car item)))
                  ans))))
  (cons a (iter z nil)))
           