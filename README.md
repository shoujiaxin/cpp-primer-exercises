# 《C++ Primer 中文版（第 5 版）》练习



## 练习环境

- 操作系统：`macOS Mojave Version 10.14`
- 编译器：`Apple LLVM version 10.0.0 (clang-1000.11.45.2)`
- 编辑器：`Microsoft Visual Studio Code`



## 目录

- [第 1 章 开始](第%201%20章%20开始/第%201%20章%20开始.md)
- 第 I 部分 C++ 基础
  - [第 2 章 变量和基本类型](第%202%20章%20变量和基本类型/第%202%20章%20变量和基本类型.md)
  - [第 3 章 字符串、向量和数组](第%203%20章%20字符串、向量和数组/第%203%20章%20字符串、向量和数组.md)
  - [第 4 章 表达式](第%204%20章%20表达式/第%204%20章%20表达式.md)
  - [第 5 章 语句](第%205%20章%20语句/第%205%20章%20语句.md)
  - [第 6 章 函数](第%206%20章%20函数/第%206%20章%20函数.md)
  - [第 7 章 类](第%207%20章%20类/第%207%20章%20类.md)

- 第 II 部分 C++ 标准库
  - [第 8 章 IO 库](第%208%20章%20IO%20库/第%208%20章%20IO%20库.md)
  - [第 9 章 顺序容器](第%209%20章%20顺序容器/第%209%20章%20顺序容器.md)
  - [第 10 章 泛型算法](第%2010%20章%20泛型算法/第%2010%20章%20泛型算法.md)
  - [第 11 章 关联容器](第%2011%20章%20关联容器/第%2011%20章%20关联容器.md)
  - [第 12 章 动态内存](第%2012%20章%20动态内存/第%2012%20章%20动态内存.md)
- 第 III 部分 类设计者的工具
  - [第 13 章 拷贝控制](第%2013%20章%20拷贝控制/第%2013%20章%20拷贝控制.md)
  - [第 14 章 重载运算与类型转换](第%2014%20章%20重载运算与类型转换/第%2014%20章%20重载运算与类型转换.md)
  - [第 15 章 面向对象程序设计](第%2015%20章%20面向对象程序设计/第%2015%20章%20面向对象程序设计.md)
  - [第 16 章 模版与泛型编程](第%2016%20章%20模版与泛型编程/第%2016%20章%20模版与泛型编程.md)
- 第 IV 部分 高级主题
  - [第 17 章 标准库特殊设施](第%2017%20章%20标准库特殊设施/第%2017%20章%20标准库特殊设施.md)
  - [第 18 章 用于大型程序的工具](第%2018%20章%20用于大型程序的工具/第%2018%20章%20用于大型程序的工具.md)
  - [第 19 章 特殊工具与技术](第%2019%20章%20特殊工具与技术/第%2019%20章%20特殊工具与技术.md)
  



## 书中的错误

1. **第 330 页，表 9.19**：`q.pop()` 删除 `queue` 的首元素或 `priority_queue` 的最高优先级的元素，但不返回此元素。
2. **第 352 页**：如果我们希望能改变一个被捕获的变量的值，就必须在参数列表尾加上关键字 `mutable`。因此，可变 `lambda` 不能省略参数列表。
3. **第 374 页**：因此一个 `unordered_multiset` 是一个允许重复关键字，元素无序保存的集合。
4. ~~**第 415 页，练习 12.12**：p 和 sp 的定义如下，对于接下来的对 process 的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因：~~



## 新标准修改

1. **第 267 页，7.5.6 字面值常量类**：[C++14 标准](https://zh.wikipedia.org/zh-hans/C%2B%2B14)删除了 *`constexpr` 函数成员是隐式 `const` 的*，新标准中，非静态成员函数可以为非 `const`。
