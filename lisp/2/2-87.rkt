#lang sicp
(define (=zero-poly? pol)
  (let ((tl (term-list pol))
        (ft (first-term pol))
        (rt (rest-terms pol)))
    (if (empty-termlist? tl)
        true
        (and (=zero? (coeff ft))
             (=zero-poly? rt)))))
(put '=zero? '(polynomial) (lambda (pol) (=zero-poly? pol)))