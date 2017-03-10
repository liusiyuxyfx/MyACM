#lang planet neil/sicp
(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))
      (if proc
          (apply proc (map contents args))
          (if (= (length args) 2)
              (let ((a1 (car args))
                    (a2 (cadr args)))
                (cond ((transform a1 a2)
                       (apply-generic op (transform a1 a2) a2)))
                      (else
                        (error "No method for these types")))))))))
;这里假设有一个方法（weight-of-type type）可以返回一个类型的权重，并且事先给所有类型由低到高的
;按层次增顺序的赋予权重（cons type weight)
(define (transform a1 a2)
  (let ((type1 (type-tag a1))
        (type2 (type-tag a2)))
    (let ((w1 (weight-of-type type1))
          (w2 (weight-of-type type2)))
      (cond ((= w1 w2) a1)
            ((< w1 w2) (transform (raise a1) a2))
            ((> w1 w2) (transform a1 (raise a2)))))))
          
        