#include "domains.hpp"
#include <bits/stdc++.h>
using namespace std;

// DOMAIN ABSTRACT CLASS ---------------------------------------------------------------------------------

	Domain::Domain() {}

	Domain::~Domain() {}

	string Domain::get() const {
		if(this->value.empty()) {
			throw invalid_argument( "String is empty!" );
		}
		return this->value;
	}

	void Domain::set(string value) {
		this->valid(value);
		this->value = value;
	}

	bool Domain::empty() {
		return this->value.empty();
	}

	bool Domain::operator!=(const Domain &other) const {
		return !(this->value == other.value);
	}

	bool Domain::operator==(const Domain &other) const {
		return this->value == other.value;
	}

	bool Domain::operator==(const string &other) const {
		return this->value == other;
	}

	bool Domain::operator<(const Domain &other) const {
		return this->value < other.value;
	}

	ostream& operator<<(ostream& os, const Domain& domain) {  
			os << domain.get();  
			return os;  
	}  

	istream& operator>>(istream& is, Domain& domain) {  
			string str;
			getline(is, str); 
			domain.set(str);
			return is;  
	}  

// NAME CLASS ---------------------------------------------------------------------------------------------

	void Name::valid(string n) throw(invalid_argument) {
		if(int(n.size()) > size_limit) {
			throw invalid_argument( "Name is to big!" );
		}

		if(n.empty()) {
			throw invalid_argument( "Name is empty!" );
		}

		for(int i = 0; i < int(n.size()); i++) {
			char c = n[i];
			if(!isalpha(c) and c != ' ') {
				throw invalid_argument( "There is unpermited caracters!" );
			}
		}
	}

// PASSWORD CLASS -----------------------------------------------------------------------------------------

	void Password::valid(string p) throw(invalid_argument) {
		if(p.empty()) {
			throw invalid_argument( "There is no password!" );
		}

		if(int(p.size()) != allowed_size) {
			throw invalid_argument( "Password size diferent from allowed!" );
		}

		map<char,int> repeat;

		for(int i = 0; i < int(p.size()); i++) {
			char c = p[i];
			repeat[c]++;
			if(repeat[c] > repetition_limit) {
				throw invalid_argument( "There is repeated caracters!" );
			}
		}
	}

// EMAIL CLASS --------------------------------------------------------------------------------------------

	void Email::valid(string e) throw(invalid_argument) {
		for(int i = 0; i < int(e.size()); i++) {
			if(!isalpha(e[i]) and e[i] != '@' and e[i] != '.') {
				throw invalid_argument( "There is unpermit caracters!" );
			}

			if(i > 0 and isalpha(e[i-1]) and isalpha(e[i])) {
				e.erase(i,1);
				i--;
			}
		}

		if(int(e.size()) != 5 or e[1] != '@' or e[3] != '.' or !isalpha(e[0]) or !isalpha(e[2]) or !isalpha(e[4])) {
			throw invalid_argument( "Invalid email!" );
		}
	}

// TEXT CLASS ---------------------------------------------------------------------------------------------

	void Text::valid(string t) throw(invalid_argument) {
		if(t.empty()) {
			throw invalid_argument( "There is no text!" );
		}

		if(int(t.size()) > 50) {
			throw invalid_argument( "This text is too big!" );
		}
	}

// ID CLASS ---------------------------------------------------------------------------------------------

	void Id::valid(string id) throw(invalid_argument) {
		if(id.empty()) {
			throw invalid_argument( "There is no id!" );
		}
		// TODO: verify if there is a non digit caracter
		// if(find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end()) {
		// 	throw invalid_argument( "There is a non digit caracter here!" );
		// }
	}

// AVALIATION CLASS ---------------------------------------------------------------------------------------

	Avaliation::Avaliation() {
		this->value = 0;
	}

	Avaliation::~Avaliation() {}

	int Avaliation::get() const {
		return this->value;
	}

	void Avaliation::set(int avaliation) {
		valid(avaliation);
		this->value = avaliation;
	}

	void Avaliation::valid(int a) throw(invalid_argument) {
		if(a > 5 or a < 0) {
			throw invalid_argument( "Invalid number!" );
		}
	}

	ostream& operator<<(ostream& os, const Avaliation& avaliation) {  
			os << avaliation.get();  
			return os;  
	}  

	istream& operator>>(istream& is, Avaliation& avaliation) {  
			int n;
			is >> n;  
			avaliation.set(n);
			return is;  
	}  
