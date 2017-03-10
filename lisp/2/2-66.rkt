#lang planet neil/sicp
(define (lookup given-key set-of-records)
  (if (null? set-of-records)
      false
      (cond ((= given-key (key record)) (entry set-of-records))
            ((< given-key (key record))
             (lookup givenkey (left-branch set-of-records)))
            ((> given-key (key record))
             (lookup givenkey (right-branch set-of-records))))))