// Implementação métodos da Classe Name
Name::Name(){}

Name::Name(string n){
    if(valid_name(n)){
      name = n;
    }
}

bool Name::valid_name(string n){
  if(n.size() > size_limit){
    return false;
  }

  for(auto c : n){
    if(!isalpha(c)){
      return false;
    }
  }
}

// Implementação métodos da Classe Password
Password::Password(){}

Password::Password(string p){
    if(valid_password(p)){
      password = p;
    }
}

bool Password::valid_password(string p){
  if(p.size() != allowed_size){
    return false;
  }

  map<char,int> repeat;

  for(auto c : p){
    repeat[c]++;
    if(repeat[c] > repetition_limit){
      return false;
    }
  }

  return true;
}

// Implementação métodos da Classe Email
Email::Email(){}

Email::Email(string e){
    if(valid_email(e)){
      email = e;
    }
}

bool Email::valid_email(string e){
  for(auto c : e){
    if(!isalpha(c) && c != '@' && c != '.'){
      return false;
    }

    if(i > 0 && isalpha(e[i-1]) && isalpha(e[i])){
      e.erase(i--);
    }
  }

  if(e.size() != 5 || e[1] != '@' || e[3] != '.' || !isalpha(e[0]) || !isalpha(e[2]) || !isalpha(e[4])){
    return false;
  }

  return true;
}
