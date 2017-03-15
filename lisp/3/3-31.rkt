
#lang planet neil/sicp
因为将过程添加到待处理表是由after-delay调用的，而添加过程是，如果不立即运行，则不会将其添加到待处理表中，换言之，运行propagate时就不会由这个新过程