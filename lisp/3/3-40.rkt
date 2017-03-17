#lang planet neil/sicp
P1：分为两次访问和一次设置
P2：分为3次访问和一次设置

记P1的访问为fp11,fp12 设置为sp1
记P2的访问为fp21,fp22,fp23,设置为sp2；

则唯一影响访问的操作即是设置操作，所以通过sp1和sp2再进程中的穿插交错导致不同的结果

（1）若Sp1发生在sp2之前，则sp2不会影响P1内x的计算，即p1内的访问得到的x为10
 <I>    fp11->fp12->sp1->fp21->fp22->fp23->sp2 === 1e6
 <II>   fp11->fp12->fp21->sp1->fp22->fp23->sp2 === 1e5
 <III>  fp11->fp12->fp21->fp22->sp1->fp23->sp2 === 1e4
 <IV>   fp11->fp12->fp21->fp22->fp23->sp1->sp2 === 1e3

（2）若sp2发生在sp1之前，则sp1不会影响p2内x的计算，即p2内的访问得到的x为10
 <I>    fp21->fp22->fp23->sp2->fp11->fp12->sp1 === 1e6
 <II>   fp21->fp22->fp23->fp11->sp2->fp12->sp1 === 1e4
 <III>  fp21->fp22->fp23->fp11->fp12->sp2->sp1 === 1e2

所以共五种结果.
1e2
1e3
1e4
1e5
1e6