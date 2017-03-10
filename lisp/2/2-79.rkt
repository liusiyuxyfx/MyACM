#lang planet neil/sicp
(define (equ? numb1 numb2)
  (apply-generic 'equ? num1 numb2))

;;scheme-number

(put 'equ? '(scheme-number scheme-number)
     (lambda (num1 num2) (= num1 num2)))
;;rational
(put 'equ? '(rational rational)
     (lambda (rat1 rat2)
       (and (= (number ret1) (number ret2))
            (= (denom ret1) (denom ret2)))))
;;complex
(put 'equ? '(complex complex)
     (lambda (com1 com2)
       (and (= (magnitude com1) (magnitude com2))
            (= (angle com1) (angle com2)))))