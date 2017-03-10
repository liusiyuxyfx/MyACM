#lang planet neil/sicp
(define (add-complex c1 c2)
  (make-from-real-imag (add (real-part c1) (real-part c2))
                       (add (imag-part c1) (imag-part c2))))
(define (sub-complex c1 c2)
  (make-from-real-imag (sub (real-part c1) (real-part c2))
                       (sub (imag-part c1) (imag-part c2))))
(define (mul-complex c1 c2)
  (make-from-real-imag (mul (magnitude c1) (magnitude c2))
                       (add (angle c1) (angle c2))))
(define (div-complex c1 c2)
  (make-from-real-imag (div (magnitude c1) (magnitude c2))
                       (sub (angle c1) (angle c2))))

(define (sine x) (apply-generic 'sine x))
(define (cosine x) (apply-generic 'cosine x))
;scheme-number
(put 'sine 'scheme-number
     (lambda (x)
       (tag (sin x))))
(put 'cosine 'scheme-number
     (lambda (x)
       (tag (cos x))))
;rational
(put 'sine 'rational
     (lambda (x)
       (tag (sin (/ (numer x)
                    (denom x))))))
(put 'cosine 'rational
     (lambda (x)
       (tag (cos (/ (numer x)
                    (denom x))))))