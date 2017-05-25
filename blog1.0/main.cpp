#include <bits/stdc++.h>
#include "domains.hpp"
#include "test_domains.hpp"
#include "test_entities.hpp"
using namespace std;

int main(){
  TestName nome;
  try{
    nome.verify();
    cout << "Classe Nome certa\n";
  }
  catch(invalid_argument erro){
    cout << "Classe Nome errada\n";
  }

  TestPassword senha;
  try{
    senha.verify();
    cout << "Classe Senha certa\n";
  }
  catch(invalid_argument erro){
    cout << "Classe Senha errada\n";
  }

  TestEmail email;
  try{
    email.verify();
    cout << "Classe Email certa\n";
  }
  catch(invalid_argument erro){
    cout << "Classe Email errada\n";
  }

  TestText texto;
  try{
    texto.verify();
    cout << "Classe Texto certa\n";
  }
  catch(invalid_argument erro){
    cout << "Classe Texto errada\n";
  }

  TestAvaliation av;
  try{
    av.verify();
    cout << "Classe Avaliacao certa\n";
  }
  catch(invalid_argument erro){
    cout << "Classe Avaliacao errada\n";
  }

  TestUser user;
  try{
    user.verify();
    cout << "Classe Usuario certa\n";
  }
  catch(invalid_argument erro){
    cout << "Classe Usuario errada\n";
  }

  TestComment comentario;
  try{
    comentario.verify();
    cout << "Classe Comentario certa\n";
  }
  catch(invalid_argument erro){
    cout << "Classe Comentario errada\n";
  }


  TestPost post;
  try{
    post.verify();
    cout << "Classe Post certa\n";
  }
  catch(invalid_argument erro){
    cout << "Classe Post errada\n";
  }

  TestBlog blog;
  try{
    blog.verify();
    cout << "Classe Blog certa\n";
  }
  catch(invalid_argument erro){
    cout << "Classe Blog errada\n";
  }

  cout << "Aperte [enter] para sair." << endl;
  
  getchar();
  return 0;
}
