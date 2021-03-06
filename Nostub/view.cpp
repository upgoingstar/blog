#include "view.hpp"
#include "controller.hpp"
#include "entity.hpp"
#include <bits/stdc++.h>
using namespace std;

// USER VIEW CLASS -----------------------------------------------------------------------------------------

User UserView::create_page() throw(invalid_argument) {
	Name userName;
	Email userEmail;
	Password userPassword;

	system("clear || cls");
	
	cout << "Um nome deve conter apenas letras e espacos. Alem disso, deve conter no maximo 20 caracteres." << endl;
	cout << "Digite um nome: ";
	try {
		cin >> userName;  
	} catch(invalid_argument erro) {
		cout << "Nome em formato incorreto." << endl;
		cout << "Aperte 'ENTER' para retornar" << endl;
		getchar();
		
		throw invalid_argument("Nome em formato incorreto.");
	}
	
	cout << "Um email deve estar no formato 'l(arroba)l.l'', onde 'l' sao palavras que contem apenas letras." << endl;
	cout << "Digite um e-mail: ";
	try {
		cin >> userEmail; 
	} catch(invalid_argument erro) {
		cout << "Email em formato incorreto." << endl;
		cout << "Aperte 'ENTER' para retornar" << endl;
		getchar();
		
		throw invalid_argument("Email em formato incorreto.");
	}
	
	cout << "Uma seha deve conter ate 5 caracteres sem repeticao." << endl;
	cout << "Digite uma senha: ";
	try {
		cin >> userPassword;  
	} catch(invalid_argument erro) {
		cout << "Senha em formato incorreto." << endl;
		cout << "Aperte 'ENTER' para retornar" << endl;
		getchar();
		
		throw invalid_argument("Senha em formato incorreto.");
	}
	
  stringstream ss;
  time_t seconds = time(0);
  
  ss << seconds;
  
  string s = ss.str();
 
  Id id;
  id.set(s);
  
  User newUser;
  newUser.set(id, userName, userEmail, userPassword);
	
	
	return newUser;
}

string UserView::show_page(User user, bool error) {

		system("clear || cls");

		cout << "Perfil" << endl;
		cout << endl;
		cout << "Nome: " << user.get_name() << endl;
		cout << endl;

		if(error) {
			error = false;
			cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
		}

		cout << "0 - Sair" << endl;
		cout << "1 - Mudar senha" << endl;
		cout << "2 - Deletar conta" << endl;
		cout << endl;
		cout << "> ";

		string option;
		getline(cin, option);
	

		return option;
}

User UserView::edit_page(User user) throw(invalid_argument) {
	Password  newPassword;

	system("clear || cls");

	cout << "Mudando Senha" << endl;
	cout << endl;
	cout << "Digite a nova senha: ";

	try {
		cin >> newPassword;
	} catch(invalid_argument erro) {
		cout << "Essa senha nao pode ser usada!" << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		throw invalid_argument("Essa senha nao pode ser usada!");
	}

	try {
		user.set_password(newPassword);
		cout << "Senha alterada com sucesso!" << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		return user;
	} catch(invalid_argument arro) {
		cout << "Houve um erro no sistema! Tente novamente mais tarde." << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		throw invalid_argument("Houve um erro no sistema! Tente novamente mais tarde.");
	}
}

bool UserView::delete_page(bool error) {
	const static int SIM = 1;
	const static int NAO = 2;

	system("clear || cls");
	
	if(error){
		cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
	}

	cout << "Tem certeza que deseja deletar seu usuario?" << endl;
	cout << "1 - Sim" << endl;
	cout << "2 - Nao" << endl;
	cout << "> ";
	
	string option;
	getline(cin,option);
	
	int op;
		try{
			op = stoi(option);
		}
		catch(invalid_argument erro){
			throw invalid_argument("Invalid option!");
		}
	
	switch(op) {
		case SIM:
			return true;
		case NAO:
			return false;
		default:
			throw invalid_argument("Opcao invalida, escolha uma das opcoes listadas na tela!");
	}
}

void UserView::deleted_page() {
	system("clear || cls");
	
	cout << "O usuario foi excluido com sucesso, aperte ENTER para retornar ao menu principal." << endl;
	getchar();
}

// BLOG VIEW CLASS -----------------------------------------------------------------------------------------

string BlogView::index_page(vector<Blog> blogs, bool error) {
	system("clear || cls"); 
		
	if(error) {
			cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
		}
		
		cout << "0 - Sair" << endl;
		for(int i = 0; i < int(blogs.size()); ++i){
			cout << i+1 << " - " << blogs[i].get_name() << endl;
		}
		
		cout << endl;
		cout << "> ";
		
		string option;
		getline(cin,option);
		
		return option;
}

Blog BlogView::create_page() throw(invalid_argument) {
	User user = Auth::get_current_user();
	Name blogAuthor = user.get_name();
		Name blogName;
		
	system("clear || cls");
	
	cout << "Um nome deve conter apenas letras e espacos. Alem disso, deve conter no maximo 20 caracteres." << endl;
	cout << "Digite um nome: ";
	try {
		cin >> blogName;  
	} catch(invalid_argument erro) {
		cout << "Nome em formato incorreto." << endl;
		cout << "Aperte 'ENTER' para retornar" << endl;
		getchar();
		
		throw invalid_argument("Nome em formato incorreto.");
	}
	
	Blog newBlog;
	newBlog.set(blogAuthor, blogName);
	
	cout << "Novo blog criada com sucesso!" << endl;
	cout << "Aperte 'ENTER' para retornar ao menu principal" << endl;
	getchar();
	
	
	return newBlog;
}

string BlogView::show_page(Blog blog, bool error) {
	system("clear || cls");
	cout << blog.get_name() << endl << endl;
	
	if(error){
		cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
	}
	
	cout << "0 - Sair" << endl;
	cout << "1 - Acessar post" << endl;
	if(Auth::user_logged() && Auth::get_current_user().get_name() == blog.get_author()){
		cout << "2 - Adicionar post" << endl;
		cout << "3 - Deletar blog" << endl;
	}
	cout << endl;
	cout << "> ";
	
	string option;
	getline(cin,option);
	
	
	return option;
}

Blog BlogView::edit_page(Blog blog) throw(invalid_argument) {
	Name newName;

	system("clear || cls");

	cout << "Mudando Nome do Blog" << endl;
	cout << endl;
	cout << "Digite o novo nome: ";

	try {
		cin >> newName;
	} catch(invalid_argument erro) {
		cout << "Esse nome e invalido!" << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		throw invalid_argument("Essa nome nao pode ser usado!");
	}

	try {
		blog.set_name(newName);
		cout << "Nome alterado com sucesso!" << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		return blog;
	} catch(invalid_argument arro) {
		cout << "Houve um erro no sistema! Tente novamente mais tarde." << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		throw invalid_argument("Houve um erro no sistema! Tente novamente mais tarde.");
	}
}

bool BlogView::delete_page(bool error) {
	const static int SIM = 1;
	const static int NAO = 2;

	system("clear || cls");
	
	if(error){
		cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
	}

	cout << "Tem certeza que deseja deletar seu blog?" << endl;
	cout << "1 - Sim" << endl;
	cout << "2 - Nao" << endl;
	cout << "> ";
	
	string option;
	getline(cin,option);
	
	int op;
		try{
			op = stoi(option);
		}
		catch(invalid_argument erro){
			throw invalid_argument("Invalid option!");
		}
	
	switch(op) {
		case SIM:
			return true;
		case NAO:
			return false;
		default:
			throw invalid_argument("Opcao invalida, escolha uma das opcoes listadas na tela!");
	}
}

void BlogView::deleted_page() {
	system("clear || cls");
	
	cout << "O blog foi excluido com sucesso, aperte ENTER para retornar a lista de blogs." << endl;
	getchar();
}

string BlogView::menu_page(bool error) {
	system("clear || cls");
	cout << "Blogs" << endl;
	
	if(error) {
		error = false;
		cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
	}
	
	cout << "0 - Sair" << endl;
	cout << "1 - Listar blogs" << endl;
	if(Auth::user_logged()){
		cout << "2 - Meus blogs" << endl;
		cout << "3 - Criar blog" << endl;
	}
	
	cout << "> ";

	string option;
	getline(cin,option);
	
 
	return option;
}

// POST VIEW CLASS -----------------------------------------------------------------------------------------

string PostView::index_page(vector<Post> posts, bool error) throw(invalid_argument) {
	system("cls || clear");
	
	if(error) {
		cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
	} 
	
	cout << "0 - Sair" << endl << endl;
	for(int i = 0; i < int(posts.size()); ++i){
		cout << i+1 << " - " << posts[i].get_author() << ": " << posts[i].get_content() << endl;
		cout << "Avaliacao: " << posts[i].get_avaliation().get() << endl << endl;
	}
	
	cout << endl;
	cout << "> ";
	string option;
	getline(cin,option);
	
	
	return option;
}

Post PostView::create_page() throw(invalid_argument) {
	const int NAO = 0;
	const int SIM = 1;
	
	User user = Auth::get_current_user();
	Name postAuthor = user.get_name();
	Text postContent;

	system("clear || cls");

	cout << "Um post deve conter no maximo 50 caracteres." << endl;   // TODO: conferir se e somente isso msm
	cout << "Digite o post: ";
	try {
		cin >> postContent;  
	} catch(invalid_argument erro) {
		cout << "Post invalido." << endl;
		cout << "Aperte 'ENTER' para retornar" << endl;
		getchar();
		
		throw invalid_argument("Post invalido.");
	}
	
	Post newPost;
	newPost.set_author(postAuthor);
	newPost.set_content(postContent);

	system("clear || cls");
	cout << "Autoriza comentarios na postagem?" << endl;
	cout << "0 - Nao" << endl;
	cout << "1 - Sim" << endl;

	try {
		string option;
		getline(cin,option);
	
	int op;
		try{
			op = stoi(option);
		}
		catch(invalid_argument erro){
			throw invalid_argument("Invalid option!");
		}
	
		switch(op) {
			case NAO:
				newPost.disallow_comments();
				break;
			case SIM:
				newPost.allow_comments();
				break;
			default:
				throw invalid_argument("Opcao invalida");
				break;
		}
	} catch(invalid_argument erro) {
		cout << "Opcao invalida" << endl;
		cout << "Aperte 'ENTER' para retornar" << endl;
		getchar();
		
		throw invalid_argument("Opcao invalida");
	}

	cout << "Novo post criado com sucesso!" << endl;
	cout << "Aperte 'ENTER' para retornar ao menu principal" << endl;
	getchar();
	
	
	return newPost;
}

string PostView::show_page(Post post, bool error) {
	system("clear || cls");

	cout << "Post" << endl;
	cout << endl;
	cout << post.get_author() << endl;
	cout << post.get_content() << endl;
	cout << endl;

	if(error) {
		error = false;
		cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
	}

	cout << "0 - Sair" << endl;
	cout << "1 - Comentarios" << endl;
	
	if(Auth::user_logged()) {
		cout << "2 - Adicionar comentario" << endl;
		cout << "3 - Avaliar" << endl;
		
		if(post.get_author() == Auth::get_current_user().get_name()) {
			cout << "4 - Editar" << endl;
			cout << "5 - Desativar Comentarios" << endl;
			cout << "6 - Deletar" << endl;
		}
	}

	cout << endl;
	cout << "> ";

	string option;
	getline(cin, option);
	

	return option;
}

Post PostView::edit_page(Post post) throw(invalid_argument) {
	Text newContent;

	system("clear || cls");

	cout << "Mudando Post" << endl;
	cout << endl;
	cout << "Digite o novo post: ";

	try {
		cin >> newContent;
	} catch(invalid_argument erro) {
		cout << "Esse post e invalido!" << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		throw invalid_argument("Essa senha nao pode ser usada!");
	}

	try {
		post.set_content(newContent);
		cout << "Post alterado com sucesso!" << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		return post;
	} catch(invalid_argument arro) {
		cout << "Houve um erro no sistema! Tente novamente mais tarde." << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		throw invalid_argument("Houve um erro no sistema! Tente novamente mais tarde.");
	}
}

bool PostView::delete_page(bool error) {
	const static int SIM = 1;
	const static int NAO = 2;

	system("clear || cls");
	
	if(error){
		cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
	}

	cout << "Tem certeza que deseja deletar seu post?" << endl;
	cout << "1 - Sim" << endl;
	cout << "2 - Nao" << endl;
	cout << "> ";
	
	string option;
	getline(cin,option);
	
	int op;
		try{
			op = stoi(option);
		}
		catch(invalid_argument erro){
			throw invalid_argument("Invalid option!");
		}
	
	switch(op) {
		case SIM:
			return true;
		case NAO:
			return false;
		default:
			throw invalid_argument("Opcao invalida, escolha uma das opcoes listadas na tela!");
	}
}

void PostView::deleted_page() {
	system("clear || cls");
	
	cout << "O post foi excluido com sucesso, aperte ENTER para retornar a lista de posts." << endl;
	getchar();
}

string PostView::avaliation_page(Post post, bool error){
	system("clear || cls");
	cout << post.get_content() << endl;
	cout << "Avaliacao: " << post.get_avaliation().get() << endl << endl;
	
	if(error){
		cout << "Valor para avaliacao incorreto!" << endl << endl;
	}
	
	cout << "Digite um valor entre 0 e 5 para avaliar o post." << endl;
	
	cout << endl;
	string value;
	getline(cin,value);
	
	return value;
}

void PostView::finish_avaliation_page(bool evaluated){
	cout << endl;
	
	if(evaluated){
		cout << "Sua avaliacao foi registrada com sucesso, aperte ENTER para retornar a pagina de comentario" << endl;
	}	
	else{
		cout << "Voce ja avaliou este post, aperte ENTER para retornar a pagina de post" << endl;
	}
	
	getchar();
}

// COMMENT VIEW CLASS ----------------------------------------------------------------------------------------

string CommentView::index_page(vector<Comment> comments, bool error) throw(invalid_argument) {
	system("cls || clear");
	
		if(error) {
			cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
		} 
	
	cout << "0 - Sair" << endl << endl;
	for(int i = 0; i < int(comments.size()); ++i){
		cout << i+1 << " - " << comments[i].get_author() << ": " << comments[i].get_content() << endl;
		cout << "Avaliacao: " << comments[i].get_avaliation().get() << endl << endl;
	}
	
	cout << endl;
	cout << "> ";
	string option;
	getline(cin,option);
	
	
	return option;
}

Comment CommentView::create_page() throw(invalid_argument) {
	User user = Auth::get_current_user();
	Name commentAuthor = user.get_name();
	Text commentContent;

	system("clear || cls");

	cout << "Um comentario deve conter no maximo 50 caracteres." << endl;   // TODO: conferir se e somente isso msm
	cout << "Digite um comentario: ";
	try {
		cin >> commentContent;  
	} catch(invalid_argument erro) {
		cout << "Comentario invalido." << endl;
		cout << "Aperte 'ENTER' para retornar" << endl;
		getchar();
		
		throw invalid_argument("Comentario invalido.");
	}
	
	Comment newComment;
	newComment.set_author(commentAuthor);
	newComment.set_content(commentContent);

	cout << "Novo comentario criado com sucesso!" << endl;
	cout << "Aperte 'ENTER' para retornar ao menu principal" << endl;
	getchar();
	
	
	return newComment;
}

string CommentView::show_page(Comment comment, bool error) {
	system("clear || cls");

	cout << "Comentario" << endl;
	cout << endl;
	cout << comment.get_author() << endl;
	cout << comment.get_content() << endl;
	cout << endl;

	if(error) {
		error = false;
		cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
	}

	cout << "0 - Sair" << endl;
	if(Auth::user_logged() && comment.get_author() == Auth::get_current_user().get_name()){
		cout << "1 - Avaliar" << endl;
		
		if(comment.get_author() == Auth::get_current_user().get_name()){
			cout << "2 - Editar" << endl;
			cout << "3 - Deletar" << endl;
		}
	}
	
	cout << endl;
	cout << "> ";

	string option;
	getline(cin, option);
	

	return option;
}

Comment CommentView::edit_page(Comment comment) throw(invalid_argument) {
	Text newContent;

	system("clear || cls");

	cout << "Mudando Comentario" << endl;
	cout << endl;
	cout << "Digite o novo comentario: ";

	try {
		cin >> newContent;
	} catch(invalid_argument erro) {
		cout << "Esse comentario e invalido!" << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		throw invalid_argument("Esse comentario nao pode ser usado!");
	}

	try {
		comment.set_content(newContent);
		cout << "Comentario alterado com sucesso!" << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		return comment;
	} catch(invalid_argument arro) {
		cout << "Houve um erro no sistema! Tente novamente mais tarde." << endl;
		cout << "Aperte 'ENTER' para voltar." << endl;
		getchar();
		
		throw invalid_argument("Houve um erro no sistema! Tente novamente mais tarde.");
	}
}

bool CommentView::delete_page(bool error) {
	const static int SIM = 1;
	const static int NAO = 2;

	system("clear || cls");
	
	if(error){
		cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
	}

	cout << "Tem certeza que deseja deletar seu comentario?" << endl;
	cout << "1 - Sim" << endl;
	cout << "2 - Nao" << endl;
	cout << "> ";
	
	string option;
	getline(cin,option);
	
	int op;
	try{
		op = stoi(option);
	}
	catch(invalid_argument erro){
		throw invalid_argument("Invalid option!");
	}
	
	switch(op) {
		case SIM:
			return true;
		case NAO:
			return false;
		default:
			throw invalid_argument("Opcao invalida, escolha uma das opcoes listadas na tela!");
	}
}

void CommentView::deleted_page() {
	system("clear || cls");
	
	cout << "O post foi excluido com sucesso, aperte ENTER para retornar a lista de comentarios." << endl;
	getchar();
}

string CommentView::avaliation_page(Comment comment, bool error){
	system("clear || cls");
	cout << comment.get_content() << endl << endl;
	cout << "Avaliacao: " << comment.get_avaliation().get() << endl << endl;
	
	if(error){
		cout << "Valor para avaliacao incorreto!" << endl << endl;
	}
	
	cout << "Digite um valor entre 0 e 5 para avaliar o comentario." << endl;
	
	cout << endl;
	string value;
	getline(cin,value);
	
	return value;
}

void CommentView::finish_avaliation_page(bool evaluated){
	cout << endl;
	
	if(evaluated){
		cout << "Sua avaliacao foi registrada com sucesso, aperte ENTER para retornar a pagina de comentario" << endl;
	}	
	else{
		cout << "Voce ja avaliou este post, aperte ENTER para retornar a pagina de comentario" << endl;
	}
	
	getchar();
}

// WELCOME VIEW CLASS ----------------------------------------------------------------------------------------

string WelcomeView::home_page(bool error) {
	system("clear || cls"); 
	cout << "Bem-vindo a Blog - a plataforma de blogs mais supimpa do mundo!" << endl << endl;
		
	if(error) {
		cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl; 
	}

	cout << "0 - Sair" << endl;
	if(Auth::user_logged()) {
		cout << "1 - Deslogar" << endl;
		cout << "2 - Perfil" << endl;
	cout << "3 - Listar blogs" << endl;
		cout << "4 - Listar meus blogs" << endl;
	cout << "5 - Criar um novo blog" << endl; 
	} else {
	cout << "1 - Logar" << endl;
	cout << "2 - Registrar" << endl; 
	cout << "3 - Listar blogs" << endl;
	}
		
	cout << endl;
	cout << "> ";
	string option;

	getline(cin, option);
	
	
	return option;
}

// AUTH VIEW CLASS ------------------------------------------------------------------------------------------

void AuthView::login_page(Email& email, Password& password) {
	system("clear || cls");
	cout << "Log-in" << endl << endl;
	
	try{
		cout << "E-mail: ";
		cin >> email;
		
	} catch(invalid_argument erro) {
		throw invalid_argument("Email incorreto.");
	}

	try{
		cout << "Senha: ";
		cin >> password;
		
	} catch(invalid_argument erro) {
		throw invalid_argument("Senha incorreta.");
	}
}

void AuthView::finish_login_page(bool error){
	if(error) {
	system("clear || cls");
	cout << "E-mail ou senha incorretos!" << endl << "Aperte 'ENTER' para retonar ao menu principal." << endl;
	getchar();
	
	} else {
	system("clear || cls");
	cout << "Log-in realizado com sucesso!" << endl << "Aperte 'ENTER' para continuar." << endl;
	getchar();
	 
	}
}

string AuthView::logout_page() {
	system("clear || cls");
	cout << "Tem certeza que deseja deslogar de sua conta?" << endl;
	cout << "1 - Sim" << endl;
	cout << "2 - Nao" << endl;
	
	string option;
	getline(cin,option);
	
	return option;
}
