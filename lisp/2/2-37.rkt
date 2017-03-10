#lang planet neil/sicp 
(define vector1 (list 1 2 3 4))
(define vector2 (list 2 3 4 5))
(define matrix1 (list (list 1 2 3 2)
                      (list 1 2 2 1)
                      (list 1 3 3 4)
                      (list 1 2 3 5)))
(define matrix2 (list (list 1 2 3 4)
                     (list 4 5 6 6)
                     (list 6 7 8 9)))

(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))
(define (accumulate-n op init seqs)
  (if (null? (car seqs))
      nil
      (cons (accumulate op init (map car seqs))
            (accumulate-n op init (map cdr seqs)))))

(define (dot-product v w)
  (accumulate + 0 (map  * v w)))
(display (dot-product vector1 vector2))

(define (matrix-*-vector m v)
  (map (lambda (m) (dot-product m v))
       m))
(newline)
(display (matrix-*-vector matrix1 vector1))

(define (transpose mat)
  (accumulate-n cons nil mat))
(newline)
(display (transpose matrix1))

(define (matrix-*-matrix m n)
  (let ((cols (transpose n)))
    (map (lambda (x) (matrix-*-vector cols x))
         m)))
(newline)
(display (matrix-*-matrix matrix1 matrix2))