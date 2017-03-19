#lang planet neil/sicp
(define (triple-weight weighted-pairs)
  (define (triple x) (* x x x))
  (let ((p1 (car weighted-pairs))
        (p2 (cadr weighted-pairs)))
    (+ (triple p1)
       (triple p2))))

(define (ramanujan s)
  (let ((s1 (stream-car s))
        (s2 (Stream-car (stream-cdr s))))
    (if (= (triple s1) (triple s2));相同权重的相邻的两个序对
        (cons-stream s1 (ramanujan (stream-cdr s)))
        (ramujan (stream-cdr s)))))
