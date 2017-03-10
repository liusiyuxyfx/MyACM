#lang planet neil/sicp
;a
;出现死循环

;b
;没有,在apply-generic找不到相应的方法是，会将两个相同类型的数据相互转换，然而由于采用了
;递归的过程，这一转换回不断的进行下去，所以会进入死循环

;c
(define (apply-generic op . args)
    (let ((type-tags (map type-tag args)))
        (let ((proc (get op type-tags)))
            (if proc
                (apply proc (map contents args))
                (if (= (length args) 2)
                    (let ((type1 (car type-tags))
                          (type2 (cadr type-tags))
                          (a1 (car args))
                          (a2 (cadr args)))
                        (if (equal? type1 type2)                                    
                            (error "Same type no method") 
                            (let ((t1->t2 (get-coercion type1 type2))
                                  (t2->t1 (get-coercion type2 type1)))
                                (cond (t1->t2
                                        (apply-generic op (t1->t2 a1) a2))
                                      (t2->t1
                                        (apply-generic op a1 (t2->t1 a2)))
                                      (else
                                        (error "No method for these types"
                                                (list op type-tags)))))))
                    (error "No method for these types"
                            (list op type-tags)))))))