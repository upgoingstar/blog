#include <bits/stdc++.h>

using namespace std;

class Domain{
public:
	string sss;

	void set (string s){
		sss = s;
	}

	friend istream& operator>>(istream& is, Domain& domain) {  
	    string str;
	    getline(is,str);
	    //is >> str;  
	    domain.set(str);
	    return is;  
	}  
};

int main(){
	Domain x;
	cin >> x;
	cout << "aaa " << x.sss << endl;
}