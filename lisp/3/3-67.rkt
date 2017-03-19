#lang planet neil/sicp
(define (pairs s t)
  (cons-stream
   (list (stream-car s) (stream-car t))
   (interleave
    (stream-map (lambda (x) (list (stream-car s) x))
                (stream-cdr t))
    (interleave
     (stream-map (lambda (x) (list (stream-car t)x))
                 (stream-cdr s))
     (pairs (stream-cdr s) (stream-cdr t))))))
(pairs integers integers)

;这里实际上就是讲矩阵的下三角加入了进来，那么参考之前的pairs，中间的方块不变
;第一列的计算与第一行的计算形式差不多。