#lang sicp

(define (make-interval a b) (cons a b))
(define (upper-bound x) (max (car x) (cdr x)))
(define (lower-bound x) (min (car x) (cdr x)))
(define (check x y)
  (cond ((and (> (* x y) 0) (> x 0)) 1) ;both > 0
        ((and (> (* x y) 0) (< x 0)) 2) ;both < 0
        ((< (* x y) 0) 3)))             ;different symbol : l < 0,u > 0
 
(define (mul-interval x y)
  (let ((ux (upper-bound x))
        (lx (lower-bound x))
        (ly (lower-bound y))
        (uy (upper-bound y)))
    (let ((cx (check ux lx))
          (cy (check uy ly)))
      (cond ((= cx 1)
             (cond ((= cy 1) (make-interval (* lx ly) (* ux uy)))
                   ((= cy 2) (make-interval (* ux ly) (* ux uy)))
                   ((= cy 3) (make-interval (* ux ly) (* uy lx)))))
            ((= cx 2)
             (cond ((= cy 1) (make-interval (* lx uy) (* ux uy)))
                   ((= cy 2) (make-interval (max (* lx ly) (* ux uy)
                                            (min (* lx uy) (* ux ly)))))
                   ((= cy 3) (make-interval (* ux ly) (* lx ly)))))
            ((= cx 3)
             (cond ((= cy 1) (make-interval (* lx uy) (* ux ly)))
                   ((= cy 2) (make-interval (* lx ly) (* lx uy)))
                   ((= cy 3) (make-interval (* ux uy) (* lx ly)))))))))
