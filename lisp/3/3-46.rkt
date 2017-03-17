#lang planet neil/sicp
P1                   MUTEX                   P2
                       |
                       |
                      false
+----------------------+----------------------+
|                                             |
|                                             |
test-and-set!                            test-and-set!
     |                                        |
     |                                        |
    true                                    true
