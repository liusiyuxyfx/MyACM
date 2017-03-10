#lang planet neil/sicp
(define (make-from-mag-ang r a)
  (define (dispatch op)
    (cond ((eq? op 'rea-part) (* r (cos a)))
          ((eq? op 'imag-part) (* r (sin a)))
          ((eq? op 'magnitude) r)
          ((eq? op 'angle) a)
          (else (error "Unkown op --- MAKE-FROM-MAG-ANG" op)))) 
   dispatch) 
  
