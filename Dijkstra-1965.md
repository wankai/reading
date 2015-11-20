[Dijkstra-1965](http://www.di.ens.fr/~pouzet/cours/systeme/bib/dijkstra.pdf)

Solution of a Problem in Concurrent Programming Control
----
**点评：上古时代以临界区问题敲开并行编程的大门**

## 问题
N个线程的多线程程序，内有循环结构，循环体内都有个临界区，怎样才能保证任意时刻至多有一个线程在执行自己的临界区？
并且要满足下面4个约束

1. 不做任何线程执行速度的假设。这是任何一个并行系统都要遵守的约定。
2. 对等性。不存在哪个线程要优先进入临界区。
3. 非阻塞性。临界区外可能由阻塞代码，但是不能阻塞除自己外的线程进入临界区。
4. 没有活锁。

## 方案

```c++
while (true) {
  b[i] = false;
  if (k != i) {
    c[i] = true;
    if (b[k]) k = i;
    continue;
  } else {
    c[i] = false;
    for (j = 1; j <= N; j++) {
      if (j != 2 && !c[j]) continue;
    }
  }
  
  // critical section here
  
  c[i] = true;
  b[i] = true;
  
  // remainder of the cycle in which blocking is allowed
  
}
```

## 证明
