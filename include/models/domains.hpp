class Name {
  const int size_limit = 20;
  string name;

  Name(){}

  Name(string){}

  bool valid_name(string){}
};

class Password {
  const int allowed_size = 5;
  const int repetition_limit = 1;
  string password;

  Password(){}

  Password(string){}

  bool valid_password(string){}
};

class Email {
  string email;

  Email(){}

  Email(string){}

  bool valid_email(string){}
};
