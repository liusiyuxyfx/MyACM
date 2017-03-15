#lang planet neil/sicp
(define (or-gate a1 a2 output)
  (let ((f1 (make-wire))
        (f2 (make-wire))
        (and1 (make-wire)))
    (inverter a1 f1)
    (inverter a2 f2)
    (and1 f1 f2 and1)
    (inverter and1 output)))