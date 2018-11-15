#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

class Folder;

class Message {
  friend class Folder;
  friend void swap(Message &, Message &);

 public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message &);
  ~Message();
  Message &operator=(const Message &);
  void save(Folder &);
  void remove(Folder &);

 private:
  std::string contents;
  std::set<Folder *> folders;
  void add_to_Folders(const Message &);
  void remove_from_Folders();
};

class Folder {
 public:
  Folder() = default;
  Folder(const Folder &);
  ~Folder();
  Folder &operator=(const Folder &);
  void addMsg(Message *);
  void remMsg(Message *);

 private:
  std::set<Message *> msgs;
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

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_Folders(m);
}

Message::~Message() { remove_from_Folders(); }

Message &Message::operator=(const Message &rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
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

#endif
