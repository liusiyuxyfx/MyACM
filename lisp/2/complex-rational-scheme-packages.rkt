#lang sicp
;table
(define operation-table (make-table))
(define get (operation-table 'lookup-proc))
(define put (operation-table 'insert-proc!))
;;tag
(define (attach-tag type-tag contents)
    (cons type-tag contents))

(define (type-tag datum)
    (if (pair? datum)
        (car datum)
        (error "Bad tagged datum -- TYPE-TAG" datum)))

(define (contents datum)
    (if (pair? datum)
        (cdr datum)
        (error "Bad tagged datum -- CONTENTS" datum)))

;;;apply-generic
(define (apply-generic op . args)
    (let ((type-tags (map type-tag args)))
        (let ((proc (get op type-tags)))
            (if proc
                (apply proc (map contents args))
                (error 
                    "No method for these types -- APPLY-GENERIC"
                    (list op type-tags))))))
;;generate selected
(define (real-part z) (apply-generic 'real-part z))
(define (imag-part z) (apply-generic 'imag-part z))
(define (magnitude z) (apply-generic 'magnitude z))
(define (angle z) (apply-generic 'angle z))

;;scheme-package

(define (install-scheme-number-package)

    ;; internal procedures
    (define (tag x)
        (attach-tag 'scheme-number x))

    ;; interface to rest of the system
    (put 'make 'scheme-number
        (lambda (x)
            (tag x)))

    (put 'equ? '(scheme-number scheme-number)
        (lambda (x y)
            (= x y)))
'done)

(define (make-scheme-number n)
    ((get 'make 'scheme-number) n))

;;comlex-package
(define (install-complex-package)

    ;; imported procedures from rectangular and polar packages
    (define (make-from-real-imag x y)
        ((get 'make-from-real-imag 'rectangular) x y))

    (define (make-from-mag-ang r a)
        ((get 'make-from-mag-ang 'polar) r a))

    ;; internal procedures
    (define (add-complex z1 z2)
        (make-from-real-imag (+ (real-part z1) (real-part z2))
                             (+ (imag-part z1) (imag-part z2))))

    (define (sub-complex z1 z2)
        (make-from-real-imag (- (real-part z1) (real-part z2))
                             (- (imag-part z1) (imag-part z2))))

    (define (mul-complex z1 z2)
        (make-from-mag-ang (* (magnitude z1) (magnitude z2))
                           (+ (angle z1) (angle z2))))

    (define (div-complex z1 z2)
        (make-from-mag-ang (/ (magnitude z1) (magnitude z2))
                           (- (angle z1) (angle z2))))

    ;; interface to rest of the system
    (define (tag z)
        (attach-tag 'complex z))

    (put 'add '(complex complex)
        (lambda (z1 z2)
            (tag (add-complex z1 z2))))

    (put 'sub '(complex complex)
        (lambda (z1 z2)
            (tag (sub-complex z1 z2))))

    (put 'mul '(complex complex)
        (lambda (z1 z2)
            (tag (mul-complex z1 z2))))

    (put 'div '(complex complex)
        (lambda (z1 z2)
            (tag (div-complex z1 z2))))

    (put 'make-from-real-imag 'complex
        (lambda (x y)
            (tag (make-from-real-imag x y))))

    (put 'make-from-mag-ang 'complex
        (lambda (x y)
            (tag (make-from-mag-ang x y))))

'done)

(define (make-complex-from-real-imag x y)
    ((get 'make-from-real-imag 'complex) x y))

(define (make-complex-from-mag-ang r a)
    ((get 'make-from-mag-ang 'complex) r a))

;rational-package
(define (install-rational-package)
    
    ;; internal procedures
    (define (numer x)
        (car x))

    (define (denom x)
        (cdr x))

    (define (make-rat n d)
        (let ((g (gcd n d)))
            (cons (/ n g) (/ d g))))

    ;; interface to rest of the system
    (define (tag x)
        (attach-tag 'rational x))

    (put 'make 'rational
        (lambda (n d)
            (tag (make-rat n d))))

    (put 'equ? '(rational rational)
        (lambda (x y)
            (and (= (numer x) (numer y))
                 (= (denom x) (denom y)))))

'done)

(define (make-rational n d)
    ((get 'make 'rational) n d))
