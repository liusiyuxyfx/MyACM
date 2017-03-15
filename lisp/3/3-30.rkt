#lang planet neil/sicp
(define (ripple-carry-adder A B S C)
  (define (iter ak bk sk ck-in)
    (if (not (and (null? ak) (null? bk)))
        (let ((ck-out (make-wire)))
          ((set-signal! ck-out (get-signal ck-in))
           (full-adder (car ak) (car bk) ck-out (car sk) C)
           (iter (cdr ak) (cdr bk) (cdr sk) C)))))
  (iter A B S C))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
n-sum-delay = n * (full-adder-delay)
            = n * (2 * half-adder-delay + or-gate-delay)
            = n * (2 * (2 * and-gate-delay + inverter-gate-delay + or-gate-delay) + or-gate-delay)
            = n * (4 * and-gate-delay + 2 * inverter-gate-delay + 3 * or-gate-delay)
        
      