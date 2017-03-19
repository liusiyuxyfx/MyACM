(define (display-line s)
  (newline)
  (display s))
(define (stream-enumerate-interval low high)
  (if (> low high)
      the-empty-stream
      (cons-stream
       low
       (stream-enumerate-interval (+ low 1) high))))
(define (show x)
  (display-line x)
  x)

(define x (stream-map show (stream-enumerate-interval 0 10)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;理论上由于延时，在执行x时应当返回一个空的表，当ref x 5时，应由1到5逐一打印
;但是用racket并不是这样，其方式与原本的并没有什么区别，但是用MIT-scheme
;就得到了理论结果，只能理解为racket并没有很好的将delay解释为一个特殊形式