#lang planet neil/sicp
;b
(define (corner-split painter n)
  (if (= n 0)
      painter
      (let ((up (up-split painter (- n 1)))
            (rigt (right-split painter (- n 1)))
            (corner (coner-split painter (- n 1))))
        (beside (below up painter)
                (below corner right)))))
(define (square-limit painter n)
  (let ((combine4 (square-of-four flip-vert rotate180
                                  identity flip-horiz)))
    (combine4 (corner-split painter n))))