#lang planet neil/sicp
;a
;上面将求导操作映射成了一个操作和数据类型的表格
(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp) (if (same-variable? exp var) 1 0))
        (else ((get 'deriv (operator exp)) (operands exp) 
                                           var))))
(define (operator exp) (car exp))
(define (operands exp) (cdr exp))
;b
;;;;sum
(define (intall-sum-deriv-package)
  ;; internal procedures
  (define (sum? x)
    (and (pair? x) (eq? (car x) '+)))
  (define (addend s) (cadr s))
  (define (augend s) (caddr s))
  (define (make-sum a1 a2)
    (cond ((=number? a1 0) a2)
          ((=number? a2 0) a1)
          ((and (number? a1) (number? a2)) (+ a1 a2))
          (else list('+ a1 a2))))
  ;;interface to the rest of the system
  (put 'deriv '(+) (lambda (exp var) (make-sum (deriv (addend exp) var)
                                               (deriv (augend exp) var))))
  'done)

;;;;product
(define (install-product-deriv-package)
  (define (make-product m1 m2)
    ;; internal procedures
    (cond ((or (=number? m1 0) (=number? m2 0)) 0)
          ((=number? m1 1) m2)
          ((=number? m2 1) m1)
          ((and (number? m1) (number? m2)) (* m1 m2))
          (else (list '* m1 m2))))
  (define (product? x)
    (and (pair? x) (eq? (car x) '*)))
  (define (multiplier p) (cadr p))
  (define (multiplicand p) (caddr p))
  ;;interface to the rest of the system
  (put 'deriv '(*) (lambda (exp var) (make-sum (make-product (multiplier exp)
                                                             (deriv (multiplicand exp) var))
                                               (make-product (deriv (multiplier exp) var)
                                                             (multiplicand exp)))))
  'done)

;c
(define (install-exp-deriv-package)
  (define (exponentiation? x)
    (and (pair? x) (eq? (car x) '**)))
  (define (base x)
    (cadr x))
  (define (exponent x)
    (caddr x))
  (define (make-exponentiation base exp)
    (cond ((=number? exp 0) 1)
          ((=number? base 1) 1)
          ((=number? exp 1) base)
          ((and (number? base) (number? exp)) (expt base exp))
          (else (list '** base exp))))
  ;;;;interface
  (put 'deriv '(**) (lambda (exp var) (make-product (make-product (exponent exp)
                                                                  (make-exponentiation (base exp)
                                                                                       (make-sum (exponent exp) -1)))
                                                    (deriv (base exp) var))))
  'done)