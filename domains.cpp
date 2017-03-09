#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#define NICKNAME_SIZE_LIMIT 20
#define PASSWORD_SIZE 5
#define PASSWORD_REPETICION_LIMIT 1

class Nick {
  string name;
  
  Nick(string nick){
		if(nick.size() > NICKNAME_SIZE_LIMIT){
			throw invalid_argument( "invalid name" );
		}
		
		for(auto c : u_nickname){
			if(!isalpha(c)){
        throw invalid_argument( "invalid name" );
			}
		}
  }
}

class Keys {
  string password;
  
  Keys(string psswrd){
		if(psswrd.size() != PASSWORD_SIZE){
			throw invalid_argument( "invalid password" );
		}

		map<char,int> repeat;

		for(auto c : psswrd){
			repeat[c]++;

			if(repeat[c] > PASSWORD_REPETICION_LIMIT){
				throw invalid_argument( "invalid password" );
			}
		}
	}
}

class Mail {
  string email;

	Mail(string mail){
		for(int i = 0; i < mail.size(); i++){
			if(!isalpha(mail[i]) && mail[i] != '@' && mail[i]!= '.'){
				throw invalid_argument( "invalid mail" );
			}

			if(i > 0 && isalpha(mail[i-1]) && isalpha(mail[i])){
				u_email.erase(i--);
			}
		}

		if(mail.size() != 5 || mail[1] != '@' || mail[3] != '.' || !isalpha(mail[0]) || !isalpha(mail[2]) || !isalpha(mail[4])){
			throw invalid_argument( "invalid mail" );
		}
	}
}

int main(){}
