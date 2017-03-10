#lang planet neil/sicp
(define (flatmap proc seq)
  (accumulate append nil (map proc seq)))

(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))

(define (enumerate-interval low high)
  (if (> low high)
      nil
      (cons low (enumerate-interval (+ low 1) high))))

(define (filter predicate sequence)
  (cond ((null? sequence) nil)
        ((predicate (car sequence))
         (cons (car sequence)
               (filter predicate (cdr sequence))))
        (else (filter predicate (cdr sequence)))))

(define (prime? x) 
   (define (test divisor) 
     (cond ((> (* divisor divisor) x) true) 
           ((= 0 (remainder x divisor)) false) 
           (else (test (+ divisor 1))))) 
   (test 2))

(define (prime-sum? pair)
  (prime? (+ (car pair) (cadr pair))))

(define (make-pair-sum pair)
  (list (car pair) (cadr pair) (+ (car pair) (cadr pair))))

(define (queens board-size) 
   (define (queen-cols k) 
     (if (= k 0) 
         (list empty-board) 
         (filter 
          (lambda (positions) (safe? k positions)) 
          (flatmap 
           (lambda (rest-of-queens) 
             (map (lambda (new-row) 
                    (adjoin-position new-row k rest-of-queens)) 
                  (enumerate-interval 1 board-size))) 
           (queen-cols (- k 1)))))) 
   (queen-cols board-size))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
