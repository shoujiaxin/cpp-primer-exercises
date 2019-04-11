# 5.1 简单语句

### 练习 5.1

> 什么是空语句？什么时候会用到空语句？

空语句是最简单的语句，它只含有一个单独的分号，不执行任何逻辑上的功能。当程序的某个地方，语法上需要一条语句但是逻辑上不需要时，使用空语句。

### 练习 5.2

> 什么是块？什么时候会用到块？

块（复合语句）是指用花括号括起来的（可能为空的）语句和声明的序列。当程序的某个地方，语法书需要一条语句，但是逻辑上需要多条语句时，使用块。

### 练习 5.3

> 使用逗号运算符（参见 4.10 节，第 140 页）重写 1.4.1 节（第 10 页）的 while 循环，使它不再需要块，观察改写之后的代码的可读性提高了还是降低了。

```cpp
while (sum += val, val < 10) {
  ++val;
}
```

循环体与条件语句写在一起，可读性降低了

# 5.2 语句作用域

### 练习 5.4

> 说明下列例子的含义，如果存在问题，试着修改它。
> 
> (a) `while (string::iterator iter != s.end()) { /* ... */}`
> 
> (b) 
> 
> ```cpp
> while (bool status = find(word)) { /* ... */ }
> if (!status) { /* ... */ }
> ```

- 使用迭代器遍历 `string` 类型的对象 `s`

  ```cpp
    auto iter = s.begin();
    while (iter != s.end()) { /* ... */ }
  ```
- 将 `find(word)` 的返回值赋给 `bool` 类型的对象 `status`，在 `while` 和 `if` 语句中分别判断 `status` 的真假

  ```cpp
    bool status = find(word);
    while (status) { /* ... */ }
    if {!status} { /* ... */ }
  ```

# 5.3 条件语句

## 5.3.1 if 语句

### [练习 5.5](5.5.cpp)

> 写一段自己的程序，使用 if else 语句实现把数字转换为字母成绩的要求。

### [练习 5.6](5.6.cpp)

> 改写上一题的程序，使用条件运算符（参见 4.7 节，第 134 页）代替 if else 语句。

### 练习 5.7

> 改正下列代码段中的错误。
> 
> (a)
> 
> ```cpp
> if (ival1 != ival2)
>   ival1 = ival2
> else
>   ival1 = ival2 = 0;
> ```
> 
> (b)
> 
> ```cpp
> if (ival < minval)
>   minval = ival;
>   occurs = 1;
> ```
> 
> (c)
> 
> ```cpp
> if (int ival = get_value())
>   cout << "ival = " << ival << endl;
> if (!ival)
>   cout << "ival = 0\n";
> ```
> 
> (d)
> 
> ```cpp
> if (ival = 0)
>   ival = get_value();
> ```

- 第二行修改为 `ival1 = ival2;`
- 修改为

  ```cpp
  if (ival < minval) {
    minval = ival;
    occurs = 1;
  }
  ```
- 修改为

  ```cpp
  if (int ival = get_value()) {
    cout << "ival = " << ival << endl;
    if (!ival) {
      cout << "ival = 0\n";
    }
  }
  ```
- 判断条件修改为 `ival == 0`

### 练习 5.8

> 什么是“悬垂 else”？C++ 语言是如何处理 else 子句的？

悬垂 else 是指在 if else 语句中，else 分支和 if 分支的匹配问题。C++ 规定 else 与离它最近的尚未匹配 if 匹配。

## 5.3.2 switch 语句

### [练习 5.9](5.9.cpp)

> 编写一段程序，使用一系列 if 语句统计从 cin 读入的文本中有多少元音字母。

### [练习 5.10](5.10.cpp)

> 我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计元音字母的大写形式，也就是说，新程序遇到 'a' 和 'A' 都应该递增 aCnt 的值，以此类推。

### [练习 5.11](5.11.cpp)

> 修改统计元音字母的程序，使其也能统计空格、制表符、和换行符的数量。

### [练习 5.12](5.12.cpp)

> 修改统计元音字母的程序，使其能统计含以下两个字符的字符序列的数量： ff、fl 和 fi。

### 练习 5.13

> 下面显示的每个程序都含有一个常见的编码错误，指出错误在哪里，然后修改它们。
> 
> (a)
> 
> ```cpp
> unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
> char ch = next_text();
> switch (ch) {
>   case 'a':
>     aCnt++;
>   case 'e':
>     eCnt++;
>   default:
>     iouCnt++;
> }
> ```
> 
> (b)
> 
> ```cpp
> unsigned index = some_value();
> switch (index) {
>   case 1:
>     int ix = get_value();
>     ivec[ix] = index;
>     break;
>   default:
>     ix = ivec.size() - 1;
>     ivec[ix] = index;
> }
> ```
> 
> (c)
> 
> ```cpp
> unsigned evenCnt = 0, oddCnt = 0;
> int digit = get_num() % 10;
> switch (digit) {
>   case 1, 3, 5, 7, 9:
>     oddcnt++;
>     break;
>   case 2, 4, 6, 8, 10:
>     evencnt++;
>     break;
> }
> ```
> 
> (d)
> 
> ```cpp
> unsigned ival = 512, jval = 1024, kval = 4096;
> unsigned bufsize;
> unsigned swt = get_bufCnt();
> switch (swt) {
>   case ival:
>     bufsize = ival * sizeof(int);
>     break;
>   case jval:
>     bufsize = jval * sizeof(int);
>     break;
>   case kval:
>     bufsize = kval * sizeof(int);
>     break;
> }
> ```

- 没有 `break`

  ```cpp
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
      case 'a':
        ++aCnt;
        break;
      case 'e':
        ++eCnt;
        break;
      default:
        ++iouCnt;
        break;
    }
  ```
- 变量 `ix` 在 `case 1` 标签的作用域内初始化，但是在 `default` 标签的作用域内被赋值

  ```cpp
    unsigned index = some_value();
    switch (index) {
      case 1:
        ivec[get_value()] = index;
        break;
      default:
        ivec[ivec.size() - 1] = index;
    }
  ```
- `case` 标签必须是整型常量表达式（第 161 页）

  ```cpp
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = ged_num() % 10;
    switch (digit) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 9:
        ++oddCnt;
        break;
      case 2:
      case 4:
      case 6:
      case 8:
      case 10:
        ++evenCnt;
        break;
    }
  ```
- `case` 标签必须是整型常量表达式

  ```cpp
    constexpr unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch (swt) {
      case ival:
        bufsize = ival * sizeof(int);
        break;
      case jval:
        bufsize = jval * sizeof(int);
        break;
      case kval:
        bufsize = kval * sizeof(int);
        break;
    }
  ```

# 5.4 迭代语句

## 5.4.1 while 语句

### [练习 5.14](5.14.cpp)

> 编写一段程序，从标准输入中读取若干 string 对象并查找连续重复出现的单词，所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。例如：如果输入是：
> 
> `how now now now brown cow cow`
> 
> 那么输出应该表明单词 now 连续出现了 3 次。

## 5.4.2 传统的 for 语句

### 练习 5.15

> 说明下列循环的含义并改正其中的错误。
> 
> (a)
> 
> ```cpp
> for (int ix = 0; ix != sz; ++ix) { /* ... */ }
> if (ix != sz)
>   // ...
> ```
> 
> (b)
> 
> ```cpp
> int ix;
> for (ix != sz; ++ix) { /* ... */ }
> ```
> 
> (c)
> 
> ```cpp
> for (int ix = 0; ix != sz; ++ix, ++sz) { /*...*/ }
> ```

- `ix` 从 0 递增到 `sz`。if 语句无用，修改如下

  ```cpp
    for (int ix = 0; ix < sz, ++ix) { /* ... */ }
  ```
- `ix` 从 0 递增到 `sz`。缺少 init-statement，修改如下

  ```cpp
    for (int ix = 0; ix < sz; ++ix) { /* ... */ }
  ```
- `ix` 从 0 递增到 `sz`。`sz` 也在递增，死循环，修改如下

  ```cpp
    for (int ix = 0; ix < sz; ++ix) { /* ... */ }
  ```

### 练习 5.16

> while 循环特别适用于那种条件不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。for 循环更像是在按步骤迭代，它的索引值在某个范围内依次变化。根据每种循环的习惯各自编写一段程序，然后分别用另一种循环改写。如果只能使用一种循环，你倾向于使用哪种呢？为什么？

更倾向于 for，使用更方便，也更灵活

### [练习 5.17](5.17.cpp)

> 假设有两个包含整数的 vector 对象，编写一段程序，检验其中一个 vector 对象是否是另一个的前缀。为了实现这一目标，对于两个不等长的 vector 对象，只需挑出长度较短的那个，把它的所有元素和另一个 vector 对象比较即可。例如，如果两个 vector 对象的元素分别是 0、1、1、2 和 0、1、1、2、3、5、8，则程序的返回结果应该为真。

## 5.4.4 do while 语句

### 练习 5.18

> 说明下列循环的含义并改正其中的错误。
> 
> (a)
> 
> ```cpp
> do
>   int v1, v2;
>   cout << "Please enter two numbers to sum:";
>   if (cin >> v1 >> v2) cout << "Sum is: " << v1 + v2 << endl;
> while (cin);
> ```
> 
> (b)
> 
> ```cpp
> do {
>   // ...
> } while (int ival = get_response());
> ```
> 
> (c)
> 
> ```cpp
> do {
>   int ival = get_response();
> } while (ival);
> ```

- 计算两个数的和。语句块未加括号，修改如下

  ```cpp
    do {
      int v1, v2;
      cout << "Please enter two numbers to sum: ";
      if (cin >> v1 >> v2) cout << "Sum is: " << v1 + v2 << endl;
    } while (cin);
  ```
- 循环直到 `ival` 为 0。condition 使用的变量必须定义在循环体之外，修改如下

  ```cpp
    init ival;
    do {
      // ...
    } while (ival = get_response())
  ```
- 同上

### [练习 5.19](5.19.cpp)

> 编写一段程序，使用 do while 循环重复地执行下述任务：首先提示用户输入两个 string 对象，然后挑出较短的那个并输出它。

# 5.5 跳转语句

## 5.5.1 break 语句

### [练习 5.20](5.20.cpp)

> 编写一段程序，从标准输入中读取 string 对象的序列直到连续出现两个相同的单词或者所有的单词都读完为止。使用 while 循环一次读取一个单词，当一个单词连续出现两次时使用 break 语句终止循环。输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。

## 5.5.2 continue 语句

### [练习 5.21](5.21.cpp)

> 修改 [5.5.1 节](#551-break-语句)（第 171 页）练习题的程序，使其找到的重复单词必须以大写字母开头。

## 5.5.3 goto 语句

### 练习 5.22

> 本节的最后一个例子跳回到 begin，其实使用循环能更好的完成该任务。重写这段代码，注意不再使用 goto 语句。

```cpp
int sz;
do {
  sz = get_size();
} while (sz <= 0);
```

# 5.6 try 语句块和异常处理

## 5.6.3 标准异常

### [练习 5.23](5.23.cpp)

> 编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。

### [练习 5.24](5.23.cpp)

> 修改你的程序，使得当第二个数是 0 时抛出异常。先不要设定 catch 子句，运行程序并真的为除数输入 0，看看会发生什么？

代码同上。若程序无 catch 语句编译报错 `error: expected catch`；若 catch 语句后的块为空，则无任何现象

### [练习 5.25](5.25.cpp)

> 修改上一题的程序，使用 try 语句块去捕获异常。catch 子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行 try 语句块的内容。

---

上一章：[第 4 章 表达式](../第%204%20章%20表达式)

下一章：[第 6 章 函数](../第%206%20章%20函数)
