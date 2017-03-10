#lang planet neil/sicp
(define (make-vect x y) (cons x y))
(define (xcor-vect vect) (car vect))
(define (ycor-vect vect) (cdr vect))

(define (make-segment star-vect end-vect)
  (cons star-vect end-vect))
(define (star-segment segment)
  (car segment))
(define (end-segment segment)
  (cdr segment))
