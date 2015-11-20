[Leslie Lamport 1979](http://research.microsoft.com/en-us/um/people/lamport/pubs/multi.pdf)

How to Make Multiprocessor Computer That Correctly Executes Multiprocess Program
----

*Lamport在此提出了构建顺序一致性(Sequential Consistent)多处理器系统的约束。*

## 单处理器系统

人类总是倾向按照程序的纸面顺序(Program Order)来推理程序执行的结果。

计算机系统的设计者应该尽力满足这种要求，否则程序员会觉得你的系统很难用。但是，为了达到
