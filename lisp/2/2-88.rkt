#lang sicp
(define (pos->neg p)
  (apply-generic 'pos->neg p))
(define (sub p1 p2)
  (apply-generic 'sub (list p1 p2)))

(put 'pos->neg 'polynomial
     (lambda (p)
       (make-poly (variable p)
                  (make-pos->neg (term-list p)))))

(put 'sub '(polynomial polynomial)
     (lambda (p1 p2)
       (tag (add-poly p1
                      (pos->neg p2)))))
     
(define (make-pos->neg p)
  (if (empty-termlist? p)
      p
      (let ((ft (first-term p))
            (rt (rest-terms p)))
        (adjoin-term (make-term (order term) (pos->neg (coeff term)))
                     (make-pos->neg rt)))))
