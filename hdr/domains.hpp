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
protected:
  string value;
  virtual void valid(string) throw(invalid_argument) = 0;
public:
  string get();
  void set(string);
};

//------------------------------------------------
// Class Name
//------------------------------------------------

class Name : public Domain {
private:
  const int size_limit = 20;
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
  const int allowed_size = 5;
  const int repetition_limit = 1;
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
// Class Avaliation
//------------------------------------------------

class Avaliation : public Domain {
private:
  void valid(string) throw(invalid_argument);

public:
  Avaliation();
  ~Avaliation();
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

#endif
