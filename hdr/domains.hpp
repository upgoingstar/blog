//------------------------------------------------
// GUARDS
//------------------------------------------------

#ifndef __DOMAINS_H_INCLUDED__
#define __DOMAINS_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include <iostream>
#include <string>
#include <map>
using namespace std;

//------------------------------------------------
// Abstract Class Domain
//------------------------------------------------

//TODO: como ficaria para colocar o throw nesse caso
class Domain {
public:
  virtual string get() = 0;
  virtual void set(string) = 0;
  virtual bool valid(string) throw(invalid_argument) = 0;
}

//------------------------------------------------
// Class Name
//------------------------------------------------

class Name : public Domain {
private:
  const int size_limit = 20;
  string name;

public:
  Name();
  ~Name();
  virtual string get();
  virtual void set(string);
  virtual bool valid(string);
};

//------------------------------------------------
// Class Password
//------------------------------------------------

class Password : public Domain {
private:
  const int allowed_size = 5;
  const int repetition_limit = 1;
  string password;

public:
  Password();
  ~Password();
  virtual string get();
  virtual void set(string);
  virtual bool valid(string);
};

//------------------------------------------------
// Class Email
//------------------------------------------------

class Email : public Domain {
private:
  string email;

public:
  Email();
  ~Email();
  virtual string get();
  virtual void set(string);
  virtual bool valid(string);
};

//------------------------------------------------
// Class Avaliation
//------------------------------------------------

class Avaliation : public Domain {
private:
  string avaliation;

public:
  Avaliation();
  ~Avaliation();
  virtual string get();
  virtual void set(string);
  virtual bool valid(string);
};

//------------------------------------------------
// Class Text
//------------------------------------------------

class Text : public Domain {
private:
  string text;

public:
  Text();
  ~Text();
  virtual string get();
  virtual void set(string);
  virtual bool valid(string);
};

#endif
