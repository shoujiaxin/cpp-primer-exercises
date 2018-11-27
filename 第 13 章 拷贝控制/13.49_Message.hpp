#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

class Folder;

class Message {
  // friend class Folder;
  friend void swap(Message &, Message &);

 public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message &);      // 拷贝构造函数
  Message(Message &&) noexcept;  // 移动构造函数
  ~Message();
  Message &operator=(const Message &);      // 拷贝赋值运算符
  Message &operator=(Message &&) noexcept;  // 移动赋值运算符
  void save(Folder &);
  void remove(Folder &);
  void addFolder(Folder *);
  void remFolder(Folder *);

 private:
  std::string contents;
  std::set<Folder *> folders;
  void add_to_Folders(const Message &);
  void remove_from_Folders();
  void move_Folders(Message *m);
};

class Folder {
  friend void swap(Folder &, Folder &);

 public:
  Folder() = default;
  Folder(const Folder &);
  ~Folder();
  Folder &operator=(const Folder &);
  void addMsg(Message *);
  void remMsg(Message *);

 private:
  std::set<Message *> msgs;
  void add_to_Messages(const Folder &);
  void remove_from_Messages();
};

void Message::add_to_Folders(const Message &m) {
  for (auto f : m.folders) {
    f->addMsg(this);
  }
}

void Message::remove_from_Folders() {
  for (auto f : folders) {
    f->remMsg(this);
  }
}

void Message::move_Folders(Message *m) {
  folders = std::move(m->folders);
  for (auto f : folders) {
    f->remMsg(m);
    f->addMsg(this);
  }
  m->folders.clear();
}

void Folder::add_to_Messages(const Folder &f) {
  for (auto m : f.msgs) {
    m->addFolder(this);
  }
}

void Folder::remove_from_Messages() {
  for (auto m : msgs) {
    m->remFolder(this);
  }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_Folders(m);
}

Message::Message(Message &&m) noexcept : contents(std::move(m.contents)) {
  move_Folders(&m);
}

Message::~Message() { remove_from_Folders(); }

Message &Message::operator=(const Message &rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

Message &Message::operator=(Message &&rhs) noexcept {
  if (this != &rhs) {
    remove_from_Folders();
    contents = std::move(rhs.contents);
    move_Folders(&rhs);
  }
  return *this;
}

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::addFolder(Folder *f) { folders.insert(f); }

void Message::remFolder(Folder *f) { folders.erase(f); }

Folder::Folder(const Folder &f) : msgs(f.msgs) { add_to_Messages(f); }

Folder::~Folder() { remove_from_Messages(); }

Folder &Folder::operator=(const Folder &rhs) {
  remove_from_Messages();
  msgs = rhs.msgs;
  add_to_Messages(rhs);
  return *this;
}

void Folder::addMsg(Message *m) { msgs.insert(m); }

void Folder::remMsg(Message *m) { msgs.erase(m); }

void swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto f : lhs.folders) {
    f->remMsg(&lhs);
  }
  for (auto f : rhs.folders) {
    f->remMsg(&rhs);
  }
  swap(lhs.contents, rhs.contents);
  swap(lhs.folders, rhs.folders);
  for (auto f : lhs.folders) {
    f->addMsg(&lhs);
  }
  for (auto f : rhs.folders) {
    f->addMsg(&rhs);
  }
}

void swap(Folder &lhs, Folder &rhs) {
  using std::swap;
  for (auto m : lhs.msgs) {
    m->remFolder(&lhs);
  }
  for (auto m : rhs.msgs) {
    m->remFolder(&rhs);
  }
  swap(lhs.msgs, rhs.msgs);
  for (auto m : lhs.msgs) {
    m->addFolder(&lhs);
  }
  for (auto m : rhs.msgs) {
    m->addFolder(&rhs);
  }
}

#endif
