#lang planet neil/sicp
(define S (cons-stream
           1
           (merge (scale-stream S 2)
                  (merge (scale-stream s 3)
                         (scale-stream s 5)))))