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

class Domain {
public:
  virtual string get(){} = 0;
  virtual void set(string){} = 0;
  virtual bool valid(string){} = 0;
}

//------------------------------------------------
// Class Name
//------------------------------------------------

class Name : public Domain {
private:
  const int size_limit = 20;
  string name;

public:
  Name(){};
  virtual string get(){};
  virtual void set(string){};
  virtual bool valid(string){};
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
  Password(){};
  virtual string get(){};
  virtual void set(string){};
  virtual bool valid(string){};
};

//------------------------------------------------
// Class Email
//------------------------------------------------

class Email : public Domain {
private:
  string email;

public:
  Email(){};
  virtual string get(){};
  virtual void set(string){};
  virtual bool valid(string){};
};

//------------------------------------------------
// Class Avaliation
//------------------------------------------------

class Avaliation : public Domain {
private:
  string avaliation;

public:
  Avaliation(){};
  virtual string get(){};
  virtual void set(string){};
  virtual bool valid(string){};
};

//------------------------------------------------
// Class Text
//------------------------------------------------

class Text : public Domain {
private:
  string text;

public:
  Text(){};
  virtual string get(){};
  virtual void set(string){};
  virtual bool valid(string){};
};

#endif
