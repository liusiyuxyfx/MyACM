#lang planet neil/sicp
(define (stream-map proc . argstreams)
  (if (stream-null? (car argstreams))
      the-empty-stream
      (cons-stream
       (apply proc (map (lambda (s)
                          (stream-car s))
                        argstreams))
       (apply stream-map
              (cons proc (map (lambda (s) (stream-cdr s))
                              argstreams))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (memo-proc proc)
  (let ((already-run? false) (result false))
    (lambda ()
      (if (not already-run?)
          (begin (set! result (proc))
                 (set! already-run? true)
                 result)
          result))))
(define (delay b)
  (memo-proc (lambda () b)))
(define (force delayed-object)
  (delayed-object))
(define (stream-car stream) (car stream))
(define (stream-cdr stream) (force (cdr stream)))
(define (cons-stream a b)
  (cons a (delay b)))
(define (stream-for-each proc s)
  (if (stream-null? s)
      'done
      (begin (proc (stream-car s))
             (stream-for-each proc (stream-cdr s)))))
(define (display-stream s)
  (stream-for-each display-line s))
(define (display-line s)
  (newline)
  (display s))
(define (stream-enumerate-interval low high)
  (if (> low high)
      the-empty-stream
      (cons-stream
       low
       (stream-enumerate-interval (+ low 1) high))))