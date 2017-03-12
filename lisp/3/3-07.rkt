#lang planet neil/sicp
(define (make-account balance password)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount))
    balance)
  (define (dispatch pass? m)
    (if (eq? pass? password)
        (cond ((eq? m 'withdraw) withdraw)
              ((eq? m 'deposit) deposit)
              (else "unkown requese -- make-account"))
        "incorrect password"))
  dispatch)
(define (make-joint account pass-word new-password)
  (if  (number? ((account pass-word 'deposit) 0))
       (lambda (input-password m)
         (if (eq? new-password input-password)
             (account pass-word m)
             (error "wrong pass-word")))
       (error "cannot connect to target account - wrong password for it")))
(define peter-acc (make-account 100 'secret-password))
((peter-acc 'secret-password 'withdraw) 40)
((peter-acc 'secret-password 'deposit) 50)
(define paul-acc (make-joint peter-acc 'secret-password 'new))
((paul-acc 'new 'withdraw) 20)