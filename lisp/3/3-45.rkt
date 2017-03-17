#lang planet neil/sicp
在serialized-exchange 中，exchange处于balanced-serialized串行组内，当
两个不同的账户调用一个共同资源时，就会发现一个串行组内有两个相同的withdraw
，这样就会发生冲突。