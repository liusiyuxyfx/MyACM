#lang planet neil/sicp
(define (=zero? x)
  (apply-generic '=zero? x))
;scheme
(put '=zero? '(scheme-number)
     (lambda (x) (= x 0)))
;rational
(put '=zero? '(rational)
     (lambda (x) (= 0 (numer x))))
;complex
(put '=zero? '(complex)
     (lambda (x) (and (= (real-part c))
                      (= (imag-part c)))))