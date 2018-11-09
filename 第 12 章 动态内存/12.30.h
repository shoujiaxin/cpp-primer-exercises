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
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream& is);
  QueryResult query(const std::string& sought) const;

 private:
  std::shared_ptr<std::vector<std::string>> file;  // 输入文件
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
  friend std::ostream& print(std::ostream& os, const QueryResult& qr);

 public:
  QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
              std::shared_ptr<std::vector<std::string>> f)
      : sought(s), lines(p), file(f) {}

 private:
  std::string sought;  // 查询单词
  std::shared_ptr<std::set<TextQuery::line_no>> lines;
  std::shared_ptr<std::vector<std::string>> file;
};

TextQuery::TextQuery(std::ifstream& is) : file(new std::vector<std::string>) {
  std::string text;
  while (getline(is, text)) {
    file->push_back(text);
    int n = file->size() - 1;  // 当前行号
    std::istringstream line(text);
    std::string word;
    while (line >> word) {
      auto& lines = wm[word];
      if (!lines) {
        lines.reset(new std::set<line_no>);
      }
      lines->insert(n);
    }
  }
}

QueryResult TextQuery::query(const std::string& sought) const {
  static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
  auto loc = wm.find(sought);
  if (loc == wm.end()) {
    return QueryResult(sought, nodata, file);  // 未找到
  } else {
    return QueryResult(sought, loc->second, file);
  }
}

std::ostream& print(std::ostream& os, const QueryResult& qr) {
  os << qr.sought << " occurs " << qr.lines->size()
     << ((qr.lines->size() > 1) ? " times" : " time") << std::endl;
  for (auto num : *qr.lines) {
    os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num)
       << std::endl;
  }
  return os;
}

#endif
