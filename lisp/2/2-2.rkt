#lang sicp
(define (make-segment x y) (cons x y))
(define (start-segment segment) (car segment))
(define (end-segment segment) (cdr segment))
(define (make-point x y) (cons x y))
(define (x-point point) (car point))
(define (y-point point) (cdr point))
(define (mid-point segment)
  (let ((a (start-segment segment))
        (b (end-segment segment)))
    (make-point (/ (+ (x-point a) (x-point b)) 2.0)
                (/ (+ (y-point a) (y-point b)) 2.0))))

