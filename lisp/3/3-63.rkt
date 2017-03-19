#lang planet neil/sicp
原版在stream-map时，guesses记录了多次计算的结果，当下一次计算的时候，就可以
利用上一次计算的结果进行计算
而louis的版本，在每次调用结尾都需要调用一次sqrt-stream x，则其需要从1从新开始算，
这就使得其每一步都为O(N)
则，上面是O(N)，下面是O(N^2)

去掉memeq，两者都为O(N^2)
