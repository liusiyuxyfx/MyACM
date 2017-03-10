#lang planet neil/sicp
(define (raise x) (apply-generic 'raise x))

;scheme-number
(put 'raise '(scheme-number) (lambda (x) (make-rational n 1)))

;rational
(define (rational->real-number x) (make-real (/ (numer x) (denom x))))
(put 'raise '(rational) rational->real-number)

;real-number
(define (real-number->complex x) (make-complex-from-real-imag x 0))
(put 'raise '(real-number) real-number->complex)