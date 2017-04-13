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

//TODO: como ficaria para colocar o throw nesse caso
class Domain {
private:
  virtual void valid(string) throw(invalid_argument) = 0;
public:
  virtual string get() = 0;
  virtual void set(string) = 0;
};

//------------------------------------------------
// Class Name
//------------------------------------------------

class Name : public Domain {
private:
  const int size_limit = 20;
  string name;
  void valid(string) throw(invalid_argument);

public:
  Name();
  ~Name();
  string get();
  void set(string);
};

//------------------------------------------------
// Class Password
//------------------------------------------------

class Password : public Domain {
private:
  const int allowed_size = 5;
  const int repetition_limit = 1;
  string password;
  void valid(string) throw(invalid_argument);

public:
  Password();
  ~Password();
  string get();
  void set(string);
};

//------------------------------------------------
// Class Email
//------------------------------------------------

class Email : public Domain {
private:
  string email;
  void valid(string) throw(invalid_argument);

public:
  Email();
  ~Email();
  string get();
  void set(string);
};

//------------------------------------------------
// Class Avaliation
//------------------------------------------------

class Avaliation : public Domain {
private:
  string avaliation;
  void valid(string) throw(invalid_argument);

public:
  Avaliation();
  ~Avaliation();
  string get();
  void set(string);
};

//------------------------------------------------
// Class Text
//------------------------------------------------

class Text : public Domain {
private:
  string text;
  void valid(string) throw(invalid_argument);

public:
  Text();
  ~Text();
  string get();
  void set(string);
};

#endif
