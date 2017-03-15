#lang sicp
(define (assoc keys records)
        (cond ((null? records) false)
              ((equal? keys (caar records)) (car records))
              (else (assoc keys (cdr records)))))
(define (lookup keys table)
        (cond ((null? keys) false)
              ((null? (cdr keys))
               (let ((records (assoc (car keys) (cdr table))))
                 ((if records
                     (cdr records)
                     false))))
               (else ((let ((subtable (assoc (car keys) (cdr table))))
                       ((if subtable
                           (lookup (cdr keys) subtable)
                           false)))))))
(define (make-table)
  (list '*table*))

(define (insert! keys value table)
        (let ((record (assoc (car keys) (cdr table))))
          (if record
              (if (null? (cdr keys))
                  (set-cdr! record value)
                  (insert! (cdr keys) record))
              (if (null? (cdr keys))
                  (set-cdr! table
                            (cons (insert! (cdr keys) value (list (car keys) '()))
                                  (cdr table)))
                  (set-cdr! table (cons (cons (car keys) value)
                                        (cdr table)))))))