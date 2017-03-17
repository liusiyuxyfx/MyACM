#lang racket
a:pe pa ma : 45
  pe ma pa : 35
  pa pe ma : 45
  pa ma pe : 50
  ma pa pe : 40
  ma pe pa : 40

b:  peter                    paul                     mary

       ______________________bank_______________________
      |                       |                         |
      |                       |                         |
access:balance:100     access:balance:100       access:balance:100
      |                       |                         |
      |                       |                         |
new value:100+10=110   new:value:100-20=80      new:value:100-50=50
      |                       |                         |
      |                       |                         |
      |                       |                         |
set! balance to 110           |                         |
      |                       |                         |
      |                       |                         |
      |                       |                         |
      +---->110        set! balance to 80               |
                              |                         |
                              |                         |
                              +---->80          set! balance to 50
                                                        |
                                                        |
                                                        |
                                                50<-----+