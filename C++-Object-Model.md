构造函数语义
---
构造和析构是C++的核心，其中构造要更复杂一些。

类是构造对象的蓝图，每一个类都需要构造函数，因为一个不能构造对象的类是没有意义的。

### Trivial Default Constructor

```c++
class A
{
 public:
  void foo();
 private:
  int a;
  double b;
};
```

> 思考：为什么用户定义的空缺省构造函数被认为是non-trivial的

### 用户定义的构造函数

编译器可能会在构造函数中插入代码以保证：

1. 组合得来的子对象被正确构造
2. 继承得来的子对象被正确构造
3. 如果有虚函数，vptr被正确设置
4. 如果有虚继承，虚表中有相应的设置

### 无构造函数

#### Trivial Default Construtible

如果构造函数不需要做任何事就能确保对象的正确性，那么编译器就不会合成这个缺省构造函数

#### Non-trivial Default Constructible

1. 如果该类的构造函数可以是trivial的，那么缺省构造函数可以什么都不做，所以编译器并不会生成一个缺省构造函数。
2. 如果该类的构造函数必须是non-trivial的，那么编译器必须做些事儿，保证对象被正确地构造。

trivial在这里可以理解为，不对内存做任何初始化就能保证构造的正确性。一个类被称为"Trivial Default Constructible"必须满足以下条件




