#include "../hdr/test_domains.hpp"
#include "../hdr/domains.hpp"
#include <bits/stdc++.h>
using namespace std;

TestDomain::TestDomain(){}

TestDomain::~TestDomain(){}

void TestDomain::success_scenario(string value,Domain &testAuxiliar){
	try{
		testAuxiliar.set(value);
		try{
			string testAuxiliar2 = testAuxiliar.get();
			if(testAuxiliar2 != value){
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(invalid_argument erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestDomain::failure_scenario(string value,Domain &testAuxiliar){
	bool daerro = false;
	try{
		testAuxiliar.set(value);
		daerro = true;
	}
	catch(invalid_argument erro){
		try{
			testAuxiliar.get();
			daerro = true;
		}
		catch(invalid_argument erro){}
	}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
}


TestName::TestName() {}

TestName::~TestName() {}

void TestName::verify(){
	{
		Name testAuxiliar;
		success_scenario(correct,testAuxiliar);
	}
	Name testAuxiliar;
	failure_scenario(incorrect,testAuxiliar);
}

TestPassword::TestPassword() {}

TestPassword::~TestPassword() {}

void TestPassword::verify(){
	{
		Password testAuxiliar;
		success_scenario(correct,testAuxiliar);
	}
	Password testAuxiliar;
	failure_scenario(incorrect,testAuxiliar);
}

TestEmail::TestEmail() {}

TestEmail::~TestEmail() {}

void TestEmail::verify(){
	{
		Email testAuxiliar;
		success_scenario(correct,testAuxiliar);
	}
	Email testAuxiliar;
	failure_scenario(incorrect,testAuxiliar);
}

TestText::TestText() {}

TestText::~TestText() {}

void TestText::verify(){
	{
		Text testAuxiliar;
		success_scenario(correct,testAuxiliar);
	}
	Text testAuxiliar;
	failure_scenario(incorrect,testAuxiliar);
}

TestAvaliation::TestAvaliation() {}

TestAvaliation::~TestAvaliation() {}

void TestAvaliation::success_scenario(int value){
	Avaliation testAuxiliar;
	try{
		testAuxiliar.set(value);
		try{
			int testAuxiliar2 = testAuxiliar.get();
			if(testAuxiliar2 != value){
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(invalid_argument erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestAvaliation::failure_scenario(int value){
	Avaliation testAuxiliar;
	bool daerro = false;
	try{
		testAuxiliar.set(value);
		daerro = true;
	}
	catch(invalid_argument erro){
		try{
			testAuxiliar.get();
			daerro = true;
		}
		catch(invalid_argument erro){}
	}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
}

void TestAvaliation::verify(){
	success_scenario(correct);
	failure_scenario(incorrect);
}
