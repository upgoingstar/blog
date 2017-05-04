#include<bits/stdc++.h>
#include "../hdr/domains.hpp"
#include "../hdr/test_domains.hpp"
using namespace std;

int main(){
  TestName nome;
  try{
    nome.verify();
    cout << "Nome certo\n";
  }
  catch(invalid_argument erro){
    cout << "Nome errado\n";
  }


  TestPassword senha;
  try{
    senha.verify();
    cout << "Senha certa\n";
  }
  catch(invalid_argument erro){
    cout << "Senha errada\n";
  }


  TestEmail email;
  try{
    email.verify();
    cout << "Email certo\n";
  }
  catch(invalid_argument erro){
    cout << "Email errado\n";
  }


  TestText texto;
  try{
    texto.verify();
    cout << "Texto certo\n";
  }
  catch(invalid_argument erro){
    cout << "Texto errado\n";
  }

  TestAvaliation av;
  try{
    av.verify();
    cout << "Avaliacao certa\n";
  }
  catch(invalid_argument erro){
    cout << "Avaliacao errada\n";
  }
  return 0;
}
