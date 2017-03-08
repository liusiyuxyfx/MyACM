#lang sicp
;递归
(define (product1 term a next b)
  (if (> a b)
      1
      (* (product1 term (next a) next b) (term a))))

(define (inc x) (+ x 1))
(define (identity x) x)
(define (factorial a b)
  (product1 identity a inc b))

(define (pi-product n)
  (if (even? n)
      (/ (+ n 2) (+ n 1))
      (/ (+ n 1) (+ n 2))))

;迭代
(define (product2 term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (* next (term a)))))
  (iter a 1))
      
