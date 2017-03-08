#lang sicp
(define (filtered-accumulate combiner null-value filter a next b term)
  (if (> a b)
      null-value
      (if (filter a)
          (combiner (term a) (filtered-accumulate combiner null-value filter (next a) next b term))
          (combiner null-value (filtered-accumulate combiner null-value filter (next a) next b term))
          )
      )
  )
 