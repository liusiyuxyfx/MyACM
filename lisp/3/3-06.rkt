#lang planet neil/sicp 
(define random-init 100)
(define (rand-update x) (random x))
(define rand
  (let ((x random-init))
    (define (dispatch m)
      (cond ((eq? m 'generate) (begin (set! x (rand-update x)) x))
            ((eq? m 'reset) (lambda (v) (set! x v)))))
  dispatch))

(rand 'generate)
(rand 'generate)
(rand 'generate)
((rand 'reset) 1000)
(rand 'generate)
((rand 'reset) 10000)
(rand 'generate)