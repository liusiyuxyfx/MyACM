;#lang planet neil/sicp
(define sum 0)
(define (accum x)
  (set! sum (+ x sum))
  sum)
(define seq (stream-map accum (stream-enumerate-interval 1 20)))
(define y (stream-filter even? seq))
(define z (stream-filter (lambda (x) (= (remainder x 5) 0))
                         seq))
;seq之后，sum为1
;y之后 sum 为 6
;z之后，sum为 10
;stream-ref 后 sum为136
;display后， sum 为210
;若不采用mem模式，则当stream-ref计算完后，由于sum是外部变量，并不会清零，
;则运行display-stream时，stream-ref所进行的计算将会再运行一次，导致进行了
;多余的累加，则结果错误