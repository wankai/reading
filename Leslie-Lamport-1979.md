[Leslie Lamport 1979](http://research.microsoft.com/en-us/um/people/lamport/pubs/multi.pdf)

How to Make Multiprocessor Computer That Correctly Executes Multiprocess Program
----

**点评：Lamport在此提出了构建顺序一致性(Sequential Consistent)多处理器系统的约束。**

## 单处理器系统

为了理解论文的内容，我们先看单处理器系统的设计

### sequential uniprocessor

给出下面一段程序，请你预测，程序执行完后，Y的值是什么
```c++
    // X的初始值为0
1.  X = 1
2.  Y = X + 1
```
让一个没学过编程的人来回答，他会毫不犹豫的说Y等于2，因为这是最自然的思考方式。
如果你问他如果第2句先执行呢，Y就等于1了哦！他会觉得你脑子有病。

一个对程序员友好的单处理器应该保证程序员能以最自然的方式，也就是顺序执行(sequential)的方式，来推断程序执行的结果。我们称这样的单处理器为sequential uniprocessor

### sequential uniprocessor的优化

现在有一家公司聘请你为他们设计一款sequential uniprocessor，你会怎么做？

很简单，每条指令都顺序执行不就行了吗！这样确实能保证sequential性质，但是性能会很低，因为全都是串行的。于是不久你就被公司开除了。

现代CPU内部结构非常复杂，指令执行的顺序不一定和程序表示的一致。为了保证sequential，CPU设计师对程序员承诺，虽然指令在底层是乱序执行的，不过你们能根据纸面程序的顺序来推断执行结果。

为什么乱序执行，还能保证结果正确呢？因为程序中的数据依赖关系是偏序的。

```c++
1.  X = 1
2.  Y = 2
3.  Z = X + 1
```
第3句必须等第1句执行完，但是第2句无论何时执行都对结果没影响。

一个完整的程序可以看成一个偏序网络，CPU执行指令时只要两个指令不存在依赖关系，可以随意决定执行顺序。


