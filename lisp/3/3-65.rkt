#lang planet neil/sicp
(define (find-ln2 n)
  (cons-stream (/ 1.0 n)
               (stream-map - (find-ln2 (+ n 1)))))
(define ln2-stream
  (partial-sums (ln2-stream 1)))