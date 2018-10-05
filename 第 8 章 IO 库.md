[TOC]

# 第 8 章 IO 库

## 8.1 IO 类

### 8.1.2 条件状态

- 8.1

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



- 8.2

  ```c++
  int main(int argc, char const* argv[]) {
    ReadData(std::cin);
    return 0;
  }
  ```



- 8.3

  `badbit`、`failbit`、`eofbit` 中任意一个被置位，`while` 循环就会终止



## 8.2 文件输入输出

### 8.2.1 使用文件流对象

- 8.4

  ```c++
  void ReadFile(std::string file, std::vector<std::string>& vec) {
    std::ifstream input(file);
    std::string line;
  
    while (getline(input, line)) {
      vec.push_back(line);
    }
  }
  ```



- 8.5

  ```c++
  void ReadFile(std::string file, std::vector<std::string>& vec) {
    std::ifstream input(file);
    std::string line;
  
    while (input >> line) {
      vec.push_back(line);
    }
  }
  ```



- 8.6

  ```c++
  int main(int argc, char const* argv[]) {
    Sales_data total;
    std::ifstream input(argv[1]);
    if (read(input, total)) {
      Sales_data trans;
      while (read(input, trans)) {
        if (total.isbn() == trans.isbn())
          total.combine(trans);
        else {
          print(std::cout, total) << std::endl;
          total = trans;
        }
      }
      print(std::cout, total) << std::endl;
    } else {
      std::cerr << "No data?!" << std::endl;
    }
    return 0;
  }
  ```



### 8.2.2 文件模式

- 8.7

  ```c++
  int main(int argc, char const* argv[]) {
    Sales_data total;
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);
    if (read(input, total)) {
      Sales_data trans;
      while (read(input, trans)) {
        if (total.isbn() == trans.isbn())
          total.combine(trans);
        else {
          print(output, total) << std::endl;
          total = trans;
        }
      }
      print(output, total) << std::endl;
    } else {
      std::cerr << "No data?!" << std::endl;
    }
    return 0;
  }
  ```



- 8.8

  ```c++
  int main(int argc, char const* argv[]) {
    Sales_data total;
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2], std::ofstream::app);
    if (read(input, total)) {
      Sales_data trans;
      while (read(input, trans)) {
        if (total.isbn() == trans.isbn())
          total.combine(trans);
        else {
          print(output, total) << std::endl;
          total = trans;
        }
      }
      print(output, total) << std::endl;
    } else {
      std::cerr << "No data?!" << std::endl;
    }
    return 0;
  }
  ```



## 8.3 string 流

### 8.3.1 使用 istringstream

- 8.9

  ```c++
  int main(int argc, char const* argv[]) {
    std::string str = "Hello World!";
    std::istringstream is(str);
    ReadData(is);
    return 0;
  }
  ```



- 8.10

  ```c++
  int main(int argc, char const* argv[]) {
    std::vector<std::string> strVec;
    ReadFile("/Users/shoujiaxin/Workspace/Projects/Exercise/input.txt", strVec);
  
    for (auto& str : strVec) {
      std::istringstream iss(str);
      std::string word;
      while (iss >> word) {
        std::cout << word << std::endl;
      }
    }
    return 0;
  }
  ```



- 8.11

  需要在 `while` 循环体中将流 `record` 中所有条件状态位复位，修改如下

  ```c++
  std::string line, word;
  std::vector<PersonInfo> people;
  std::istringstream record;
  while (getline(std::cin, line)) {
    PersonInfo info;
    record.str(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
    record.clear();
  }
  ```



- 8.12

  `PersonInfo` 定义为聚合类即可，聚合类没有类内初始值。



### 8.3.2 使用 ostringstream

- 8.13

  ```c++
  std::string line, word;
  std::vector<PersonInfo> people;
  std::ifstream is("./input.txt");
  while (getline(is, line)) {
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }
  ```



- 8.14
  - 使用引用避免对类类型的拷贝
  - 在循环体中不需要修改 `entry` 和 `nums` 对象
