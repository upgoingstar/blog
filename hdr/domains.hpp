//------------------------------------------------
// GUARDS
//------------------------------------------------

#ifndef __DOMAINS_H_INCLUDED__
#define __DOMAINS_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------

  #include <bits/stdc++.h>
  using namespace std;

//------------------------------------------------
// Abstract Class Domain
//------------------------------------------------

class Domain {
protected:
  string value;
  bool empty;
  virtual void valid(string) throw(invalid_argument) = 0;
public:
  Domain();
  ~Domain();
  bool exist(){
    return empty;
  }
  string get();
  void set(string);
  bool operator!=(const Domain &other) const;
  bool operator==(const Domain &other) const;
  bool operator<(const Domain &other) const;
};

//------------------------------------------------
// Class Name
//------------------------------------------------

class Name : public Domain {
private:
  static const int size_limit = 20;
  void valid(string) throw(invalid_argument);

public:
  Name();
  ~Name();
};

//------------------------------------------------
// Class Password
//------------------------------------------------

class Password : public Domain {
private:
  static const int allowed_size = 5;
  static const int repetition_limit = 1;
  void valid(string) throw(invalid_argument);

public:
  Password();
  ~Password();
};

//------------------------------------------------
// Class Email
//------------------------------------------------

class Email : public Domain {
private:
  void valid(string) throw(invalid_argument);

public:
  Email();
  ~Email();
};

//------------------------------------------------
// Class Text
//------------------------------------------------

class Text : public Domain {
private:
  void valid(string) throw(invalid_argument);

public:
  Text();
  ~Text();
};

//------------------------------------------------
// Class Avaliation
//------------------------------------------------
//TODO: verificar possibilidade de integrar com a classe domain
class Avaliation {
private:
  int value;
  void valid(int) throw(invalid_argument);

public:
  Avaliation();
  ~Avaliation();
  int get();
  void set(int);
};

#endif
