# 8.1 IO 类

## 8.1.2 条件状态

### 练习 8.1

> 编写函数，接受一个 istream& 参数，返回值类型也是 istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。

```c++
std::istream& ReadData(std::istream& is) {
  std::string data;
  while (is >> data) {
    std::cout << data << std::endl;
  }
  is.clear();
  return is;
}
```



### [练习 8.2](8.2.cpp)

>测试函数，调用参数为 cin。



### 练习 8.3

> 什么情况下，下面的 while 循环会终止？
>
> ```c++
> while (cin >> i) /* ... */
> ```

`badbit`、`failbit`、`eofbit` 中任意一个被置位，`while` 循环就会终止



# 8.2 文件输入输出

## 8.2.1 使用文件流对象

### 练习 8.4

> 编写函数，以读模式打开一个文件，将其内容读入到一个 string 的 vector 中，将每一行作为一个独立的元素存于 vector 中。

```c++
void ReadFile(std::string file, std::vector<std::string>& vec) {
  std::ifstream input(file);
  if (input) {
    std::string line;
    while (getline(input, line)) {
      vec.push_back(line);
    }
  }
}
```



### 练习 8.5

> 重写上面的程序，将每个单词作为一个独立的元素进行存储。

```c++
void ReadFile(std::string file, std::vector<std::string>& vec) {
  std::ifstream input(file);
  if (input) {
    std::string line;
    while (input >> line) {
       vec.push_back(line);
    }
  }
}
```



### [练习 8.6](8.6.cpp)

> 重写 [7.1.1 节](../第%207%20章%20类/第%207%20章%20类.md/#711-设计-sales_data-类)的书店程序（第 229 页），从一个文件中读取交易记录。将文件名作为一个参数传递给 main（参见 6.2.5 节，第 196 页）。



## 8.2.2 文件模式

### [练习 8.7](8.7.cpp)

> 修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给 main 函数。



### [练习 8.8](8.8.cpp)

> 修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。



# 8.3 string 流

## 8.3.1 使用 istringstream

### [练习 8.9](8.9.cpp)

> 使用你为 [8.1.2 节（第 281 节）第一个练习](#练习-81)所编写的函数打印一个 istringstream 对象的内容。



### [练习 8.10](8.10.cpp)

> 编写程序，将来自一个文件中的行保存在一个 vector 中。然后使用一个 istringstream 从 vector 读取数据元素，每次读取一个单词。



### [练习 8.11](8.11.cpp)

> 本节的程序在外层 while 循环中定义了 istringstream 对象。如果 record 对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将 record 的定义移到 while 循环之外，验证你设想的修改方法是否正确。

需要在 `while` 循环体中将流 `record` 中所有条件状态位复位。



### 练习 8.12

> 我们为什么没有在 PersonInfo 中使用类内初始化？

`PersonInfo` 定义为聚合类即可，聚合类没有类内初始值。



## 8.3.2 使用 ostringstream

### [练习 8.13](8.13.cpp)

> 重写本节的电话号码程序，从一个命名文件而非 cin 读取数据。



### 练习 8.14

> 我们为什么将 entry 和 nums 定义为 const auto& ？

- 使用引用避免对类类型的拷贝
- 在循环体中不需要修改 `entry` 和 `nums` 对象



---

上一章：[第 7 章 类](../第%207%20章%20类/第%207%20章%20类.md)

下一章：[第 9 章 顺序容器](../第%209%20章%20顺序容器/第%209%20章%20顺序容器.md)
