#lang planet neil/sicp
(define (make-zero-crossings input-stream last-value pre-avpt)
  (let ((avpt (/ (+ (stream-car input-stream) last-value) 2)))
    (cons-stream (sign-change-detector avpt pre-avpt)
                 (make-zero-crossings (stream-cdr input-stream)
                                      (stream-car input-stream)
                                      avpt))))
;louis错在在将本次平滑信号与前一次实测信号进行了比较，那么这里实际上还是没有
;排除噪声干扰