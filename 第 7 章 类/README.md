# 7.1 定义抽象数据类型

## 7.1.1 设计 Sales_data 类

### [练习 7.1](7.1.cpp)

> 使用 [2.6.1 节练习](../第%202%20章%20变量和基本类型/#练习-240)定义的 Sales_data 类为 1.6 节（第 21 页）的交易处理程序编写一个新版本。

## 7.1.2 定义改进的 Sales_data 类

### [练习 7.2](7.2.h)

> 曾在 [2.6.2 节的练习](../第%202%20章%20变量和基本类型/#练习-241)（第 67 页）中编写了一个 Sales_data 类，请向这个类添加 combine 函数和 isbn 成员。

### [练习 7.3](7.3.cpp)

> 修改 7.1.1 节（第 229 页）的交易处理程序，令其使用这些成员。

### [练习 7.4](7.4.h)

> 编写一个名为 Person 的类，使其表示人员的姓名和地址。使用 string 对象存放这些元素，接下来的练习将不断充实这个类的其他特征。

### [练习 7.5](7.5.h)

> 在你的 Person 类中提供一些操作使其能够返回姓名和地址。这些函数是否应该是 const 的呢？解释原因。

是 const 的，这些函数不修改 this 所指的对象，使用 cosnt 能提高函数的灵活性

## 7.1.3 定义类相关的非成员函数

### [练习 7.6](7.6.h)

> 对于函数 add、read 和 print，定义你自己的版本。

### [练习 7.7](7.7.cpp)

> 使用这些新函数重写 [7.1.2 节（第 233 页）练习](#练习-73)中的交易处理程序。

### 练习 7.8

> 为什么 read 函数将其 Sales_data 参数定义成普通的引用，而 print 函数将其参数定义成常量引用？

因为 `read` 需要修改 `Sales_data` 对象，而 `print` 不需要

### [练习 7.9](7.9.h)

> 对于 [7.1.2 节（第 233 页）练习](#练习-75)中的代码，添加读取和打印 Person 对象的操作。

### 练习 7.10

> 在下面这条 if 语句中，条件部分的作用是什么？
> 
> ```cpp
> if (read(read(cin, data1), data2))
> ```

从 `cin` 读取数据，依次存入 `data1` 和 `data2`

## 7.1.4 构造函数

### [练习 7.11](7.11.cpp)

> 在你的 Sales_data 类中添加构造函数，然后编写一段程序令其用到每个构造函数。

### [练习 7.12](7.12.h)

> 把只接受一个 istream 作为参数的构造函数定义移到类的内部。

### [练习 7.13](7.13.cpp)

> 使用 istream 构造函数重写第 229 页的程序。

### 练习 7.14

> 编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。

```cpp
Sales_data::Sales_data() : units_sold(0), price(0), revenue(0) {}
```

### [练习 7.15](7.15.h)

> 为你的 Person 类添加正确的构造函数。

# 7.2 访问控制与封装

### 练习 7.16

> 在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在 public 说明符之后？什么样的成员应该定义在 private 说明符之后？

一个类可以包含 0 个或多个访问说明符，且某个访问说明符能出现多少次没有严格规定；每个访问说明符指定了接下来的成员的访问级别，其有效范围直到下一个访问说明符或者到达类的结尾处为止。（第 240 页）

### 练习 7.17

> 使用 class 和 struct 时有区别吗？如果有，是什么？

使用 struct 和 class 定义类唯一的区别就是默认的访问权限：前者字第一个访问说明符之前的成员是 public 的；后者则是 private 的。

### 练习 7.18

> 封装是何含义？它有什么用处？

封装即隐藏类的实现细节。封装的用处有：强制用户使用接口、隐藏实现细节，控制用户访问权限。封装的益处：

- 确保用户代码不会无意间破坏封装对象的状态
- 被封装的类的具体实现细节可以随时改变，而无须调整用户级别的代码

### 练习 7.19

> 在你的 Person 类中，你将把哪些成员声明成 public 的？哪些声明成 private 的？解释你这样做的原因。

构造函数以及成员函数 `Name` 和 `Address` 是 public 的，数据成员 `name` 和 `address` 是 private 的

## 7.2.1 友元

### 练习 7.20

> 友元在什么时候有用？请分别举出使用友元的利弊。

其他类或者函数访问类的非公有成员时需要使用友元。

利：其他类或函数能直接访问类的非公有成员

弊：牺牲了封装性与可维护性

### [练习 7.21](7.21.h)

> 修改你的 Sales_data 类使其隐藏实现的细节。你之前编写的关于 Sales_data 操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其工作正常。

### [练习 7.22](7.22.h)

> 修改你的 Person 类使其隐藏实现的细节。

# 7.3 类的其他特性

## 7.3.1 类成员再探

### [练习 7.23](7.23.h)

> 编写你自己的 Screen 类型。

### [练习 7.24](7.24.h)

> 给你的 Screen 类添加三个构造函数：一个默认构造函数；另一个构造函数接受宽和高的值，然后将 contents 初始化成给定数量的空白；第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化后屏幕的内容。

### 练习 7.25

> Screen 能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能？为什么？

能，类只包含内置类型和 string 成员，其拷贝和赋值的合成版能够正常工作（第 240 页）。

### [练习 7.26](7.26.h)

> 将 Sales_data::avg_price 定义成内联函数。

## 7.3.2 返回 *this 的成员函数

### [练习 7.27](7.27.cpp)

> 给你自己的 Screen 类添加 move、set 和 display 函数，通过执行下面的代码检验你的类是否正确。
> 
> ```cpp
> Screen myScreen(5, 5, 'X');
> myScreen.move(4, 0).set('#').display(cout);
> cout << "\n";
> myScreen.display(cout);
> cout << "\n";
> ```

输出

```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
```

### 练习 7.28

> 如果 move、set 和 display 函数的返回类型不是 Screen& 而是 Screen，则在上一个练习中奖会发生什么？

输出

```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

### 练习 7.29

> 修改你的 Screen 类，令 move、set 和 display 函数返回 Screen 并检查程序的运行结果，在上一个练习中你的推测正确吗？

第一个输出为临时的 `Screen` 对象，第二个输出为 `myScreen`

### 练习 7.30

> 通过 this 指针使用成员的做法虽然合法，但是有点多余。讨论显示使用指针访问成员的优缺点。

优点：

- 程序意图更明确
- 成员函数的形参可以与成员变量相同

缺点：

- 代码显得更复杂

## 7.3.3 类类型

### 练习 7.31

> 定义一对类 X 和 Y，其中 X 包含一个指向 Y 的指针，而 Y 包含一个类型为 X 的对象。

```cpp
struct Y;
struct X {
  Y *py;
};

struct Y {
  X x;
};
```

## 7.3.4 类的作用域

### [练习 7.32](7.32.h)

> 定义你自己的 Screen 和 Window_mgr，其中 clear 是 Window_mgr 的成员，是 Screen 的友元。

# 7.4 类的作用域

### 练习 7.33

> 如果我们给 Screen 添加一个如下所示的 size 成员将发生什么情况？如果出现了问题，请尝试修改它。
> 
> ```cpp
> pos Screen::size() const { return height * width; }
> ```

报错未定义标识符 `pos`，应修改为

```cpp
Screen::pos Screen::size() const { return height * width; }
```

## 7.4.1 名字查找与类的作用域

### 练习 7.34

> 如果我们把第 256 页 Screen 类的 pos 的 typedef 放在类的最后一行会发生什么情况？

报错 `error: unknown type name 'pos'`

### 练习 7.35

> 解释下面代码的含义，说明其中的 Type 和 initVal 分别使用了哪个定义。如果代码存在错误，尝试修改它。
> 
> ```cpp
> typedef string Type;
> Type initVal();
> class Exercise {
>  public:
>   typedef double Type;
>   Type setVal(Type);
>   Type initVal();
> 
>  private:
>   int val;
> };
> Type Exercise::setVal(Type parm) {
>   val = parm + initVal();
>   return val;
> }
> ```

在类中，如果成员使用了外层作用域中的某个名字，而该名字代表一种类型，则类不能再之后重新定义该名字，即重新定义类型名字是一种错误的行为（第 255 页）。若编译器不负责检查重新定义类型的名字，则可修改为

```cpp
Exercise::Type Exercise::serVal(Type parm) {
  val = parm + initVal();
  return val;
}
```

# 7.5 构造函数再探

## 7.5.1 构造函数初始值列表

### 练习 7.36

> 下面的初始值是错误的，请找出问题所在并尝试修改它。
> 
> ```cpp
> struct X {
>   X(int i, int j) : base(i), rem(base % j) {}
>   int rem, base;
> };
> ```

`rem` 在 `base` 之前被初始化，修改如下

```cpp
struct X {
  X(int i, int j) : rem(i % j), base(i) {}
  int rem, base;
};
```

### 练习 7.37

> 使用本节提供的 Sales_data 类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有的数据成员的值。
> 
> ```cpp
> Sales_data first_item(cin);
> int main() {
>   Sales_data next;
>   Sales_data last("9-999-99999-9");
> }
> ```

- `first_item` 使用 `Sales_data(std::istream &is);`，数据成员从输入流中读取
- `next` 使用默认构造函数，`bookNo = ""; units_sold = 0; revenue = 0.0;`
- `last` 使用 `Sales_data(std::string s = "");`，`bookNo = "9-999-99999-9"; units_sold = 0; revenue = 0.0;`

### 练习 7.38

> 有些情况下我们希望提供 cin 作为接受 istream& 参数的构造函数的默认实参，请声明这样的构造函数。

```cpp
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```

### 练习 7.39

> 如果接受 string 的构造函数和接受 istream& 的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？

不合法，如果一个构造函数为所有参数都提供了默认实参，则它实际上也定义了默认构造函数。若接受 `string` 的构造函数和接受 `istream&` 的构造函数都使用默认实参，则无法区分使用哪一个默认构造函数。

### 练习 7.40

> 从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
> 
> (a) Book
> 
> (b) Date
> 
> (c) Employee
> 
> (d) Vehicle
> 
> (e) Object
> 
> (f) Tree

```cpp
class Employee {
  public:
  Employee() = default;
  Employee(int i, std::string n, int ag = 0, std::string p = "",
           std::string ad = "")
    : id(i), name(n), age(ag), phone(p), address(ad) {}

  private:
  int id;
  std::string name;
  int age;
  std::string phone;
  std::string address;
};
```

## 7.5.2 委托构造函数

### [练习 7.41](7.41.cpp)

> 使用委托构造函数重新编写你的 Sales_data 类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建 Sales_data 对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。

- 定义变量 `Sales_data data1;`，输出

  ```
    Sales_data(const std::string&, unsigned, double)
    Sales_data()
  ```
- 定义变量 `Sales_data data2("abc");`，输出

  ```
    Sales_data(const std::string&, unsigned, double)
    Sales_data(const std::string&)
  ```

### 练习 7.42

> 对于你在[练习 7.40（参见 7.5.1 节，第 261 页）](#练习-740) 中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。

```cpp
class Employee {
  public:
  Employee() = default;
  Employee(int i, std::string n, int ag, std::string p, std::string ad)
    : id(i), name(n), age(ag), phone(p), address(ad) {}
  Employee(int i, std::string n) : Employee(i, n, 0, "", "") {}

  private:
  int id;
  std::string name;
  int age;
  std::string phone;
  std::string address;
};

int main(int argc, char const* argv[]) {
  Sales_data data(std::cin);
  return 0;
}
```

## 7.5.3 默认构造函数的作用

### 练习 7.43

> 假定有一个名为 NoDefault 的类，它有一个接受 int 的构造函数，但是没有默认构造函数。定义类 C，C 有一个 NoDefault 类型的成员，定义 C 的默认构造函数。

```cpp
class NoDefault {
  public:
  NoDefault(int i) {}
};

class C {
  public:
  C() : c_member(0) {}

  private:
  NoDefault c_member;
};
```

### 练习 7.44

> 下面这条声明合法吗？如果不，为什么？
> 
> ```cpp
> vector<NoDefault> vec(10);
> ```

不合法，`NoDefault` 类没有默认构造函数

### 练习 7.45

> 如果在上一个练习中定义的 vector 的元素类型是 C，则声明合法吗？为什么？

合法，`C` 类有默认构造函数

### 练习 7.46

> 下面哪些论断是不正确的？为什么？
> 
> (a) 一个类必须至少提供一个构造函数。
> 
> (b) 默认构造函数是参数列表为空的构造函数。
> 
> (c) 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。
> 
> (d) 如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。

- 不正确，当类没有声明任何构造函数时，编译器会自动生成默认构造函数。
- 不正确，默认构造函数无须任何实参，但一个所有参数都有默认实参的构造函数也定义了默认构造函数。
- 不正确，没有默认构造函数则编译器无法初始化类对象。
- 不正确，只有当类没有声明任何构造函数时，编译器才会自动生成默认构造函数。

## 7.5.4 隐式的类类型转换

### 练习 7.47

> 说明接受一个 string 参数的 Sales_data 构造函数是否应该是 explicit 的，并解释这样做的优缺点。

使用 `explicit` 的构造函数可以抑制构造函数定义的隐式转换，但是需要显示地使用构造函数才能转换，意图更加明确，但是代码略显繁琐

### 练习 7.48

> 假定 Sales_data 的构造函数不是 explicit 的，则下述定义将执行什么样的操作？
> 
> ```cpp
> string null_isbn("9-999-9999-9");
> Sales_data item1(null_isbn);
> Sales_data item2("9-999-99999-9");
> ```

使用构造函数直接初始化 `item1` 和 `item2`

### 练习 7.49

> 对于 combine 函数的三种不同声明，当我们调用 i.combine(s) 时分别发生什么情况？其中 i 是一个 Sales_data，而 s 是一个 string 对象。

- 把 `s` 隐式地转换成 `Sales_data`
- 报错，编译器只会自动地执行一步类型转换（第 264 页）
- `const` 的 `combine` 函数无法修改对象 `i`

### 练习 7.50

> 确定在你的 Person 类中是否有一些构造函数应该是 explicit 的。

```cpp
explicit Person(std::istream& is) { read(is, *this); }
```

### 练习 7.51

> vector 将其单参数的构造函数定义成 explicit 的，而 string 则不是，你觉得原因何在？

`string` 的单参数构造函数是将 `const char*`，即字面值常量，隐式地转换为 `string`；而 `vector` 的单参数构造函数接受的参数是容器的大小，若不是 `explicit` 则可能会引起歧义。

## 7.5.5 聚合类

### 练习 7.52

> 使用 2.6.1 节（第 64 页）的 Sales_data 类，解释下面的初始化过程。如果存在问题，尝试修改它。
> 
> ```cpp
> Sales_data item = {"987-0590353403", 25, 15.99};
> ```

成员初始值列表可以用来初始化聚合类的数据成员，而第 64 页的 `Sales_data` 类的数据成员有类内初始值，故其不是聚合类，修改如下

```cpp
struct Sales_data {
  std::string bookNo;
  unsigned units_sold;
  double revenue;
};
```

## 7.5.6 字面值常量

### 练习 7.53

> 定义你自己的 Debug。

```cpp
class Debug {
  public:
  constexpr Debug() = default;
  constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(0) {}
  constexpr bool any() const { return hw | io | other; }
  void set_hw(bool h) { hw = h; }
  void set_io(bool i) { io = i; }
  void set_other(bool o) { other = o; }

  private:
  bool hw = true;
  bool io = true;
  bool other = true;
};
```

### 练习 7.54

> Debug 中以 set_ 开头的成员应该被声明成 constexpr 吗？如果不，为什么？

不应该，`constexpr` 函数的唯一可执行语句是返回语句，而 `set_` 开头的成员函数需要修改数据成员。

### 练习 7.55

> 7.5.5 节（第 266 页）的 Data 类是字面值常量类吗？请解释原因。

不是，数据成员都是字面值类型的聚合类才是字面值常量类（第 267 页）。

# 7.6 类的静态成员

### 练习 7.56

> 什么是类的静态成员？它有何优点？静态成员与普通成员有何区别？

类的静态成员存在于任何对象之外，与类本身直接相关，而与类的各个对象无关的成员。

### 练习 7.57

> 编写你自己的 Account 类。

```cpp
class Account {
  public:
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double newRate) { interestRate = newRate; }

  private:
  std::string owner;
  double amount;
  static double interestRate;
  static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();
```

### 练习 7.58

> 下面的静态数据成员的声明和定义有错误吗？请解释原因。
> 
> ```cpp
> // example.h
> class Example {
>  public:
>   static double rate = 6.5;
>   static const int vecSize = 20;
>   static vector<double> vec(vecSize);
> };
> 
> // example.c
> #include "example.h"
> double Example::rate;
> vector<double> Example::vec;
> ```

不能在类内初始化非 `const` 的 `static` 成员，修改如下

```cpp
class Example {
  public:
  static double rate;
  static const int vecSize = 20;
  static std::vector<double> vec;
};

double Example::rate = 6.5;
std::vector<double> Example::vec(vecSize);
```

---

上一章：[第 6 章 函数](../第%206%20章%20函数)

下一章：[第 8 章 IO 库](../第%208%20章%20IO%20库)
