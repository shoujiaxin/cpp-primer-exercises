#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult;

class TextQuery {
 public:
  TextQuery(std::ifstream &ifs);
  QueryResult query(const std::string &str);

 private:
  std::shared_ptr<std::vector<std::string>> text;                // 全部文本
  std::map<std::string, std::shared_ptr<std::set<int>>> rowNum;  // 单词 - 行号
};

class QueryResult {
  friend std::ostream &print(std::ostream &os, const QueryResult &qr);

 public:
  QueryResult(const std::shared_ptr<std::vector<std::string>> t,
              const std::string &s, const std::shared_ptr<std::set<int>> r)
      : text(t), word(s), row(r) {}

 private:
  std::shared_ptr<std::vector<std::string>> text;  // 全部文本
  std::string word;                                // 要查询的单词
  std::shared_ptr<std::set<int>> row;              // 单词所在行号
};

TextQuery::TextQuery(std::ifstream &ifs) {
  text = std::make_shared<std::vector<std::string>>();
  std::string line;
  int currRow = 0;
  while (getline(ifs, line)) {
    text->push_back(line);

    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
      if (rowNum.find(word) == rowNum.end()) {
        rowNum[word] = std::make_shared<std::set<int>>();
      }
      rowNum[word]->insert(currRow);
    }

    ++currRow;
  }
}

QueryResult TextQuery::query(const std::string &str) {
  if (rowNum.find(str) == rowNum.end()) {
    return QueryResult(this->text, str, nullptr);
  }
  return QueryResult(this->text, str, rowNum[str]);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  auto cnt = (qr.row == nullptr) ? 0 : qr.row->size();
  os << qr.word << " occurs " << cnt << ((cnt > 1) ? " times" : " time")
     << std::endl;

  auto row_it = qr.row->begin();
  while (row_it != qr.row->end()) {
    os << "\t(line " << *row_it << ") " << qr.text->at(*row_it) << std::endl;
    ++row_it;
  }

  return os;
}

#endif
