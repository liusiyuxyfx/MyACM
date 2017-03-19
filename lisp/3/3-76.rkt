#lang planet neil/sicp
(define (smooth s)
  (let ((avpt (/ (+ (stream-car stream)
                    (stream-car (stream-cdr stream)))
                 2)))
    (cons-stream avpt (smooth (stream-cdr s)))))
(define (make-zero-crossings input-stream smooth)
  (stream-map sign-change-detector
              (smooth input-stream)
              (cons-stream 0 (smooth input-stream))))