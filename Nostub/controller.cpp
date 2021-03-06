#include "controller.hpp"
#include "view.hpp"
#include "entity.hpp"
#include "domains.hpp"
#include "model.hpp"
#include <bits/stdc++.h>
using namespace std;

// TODO: do not let it comment if the post disllow it
// TODO: make Post show call this funtion, but in a form CommentController::index(vector<Comment> comments)

// COMMENT CONTROLLER CLASS ------------------------------------------------------------------------------

	void CommentController::index(Post post){
		const int EXIT = 0;

		bool error = false;
		bool exit = false;
		

		while(!exit){
			vector<Comment> comments = Stub::get_comments(post);
			string option = CommentView::index_page(comments, error);

			error = false;

			int id;
			try{
				id = stoi(option);
				if(id > int(comments.size())) throw invalid_argument("Invalid id");
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}
			switch(id){
				case EXIT:
					exit = true;
					break;
				default:
					CommentController::show(comments[(unsigned long)(id - 1)]);
					break;
			}
		}
	}

	void CommentController::create() {
		try {
			Comment comment = CommentView::create_page();                 // render create page and receive a new comment
			// CommentModel::save(Comment);                               // Send to model to save it             // TODO: put a stub in here (later implement)
		} 
		catch(invalid_argument erro) {}
	}

	void CommentController::show(Comment comment) {
		const int EXIT = 0;
		const int EVALUATE = 1;
		const int EDIT = 2;
		const int DELETE = 3;

		bool exit = false;
		bool error = false;

		while(!exit) {
			string option = CommentView::show_page(comment, error);          // render show page

			int op;
			try{
				op = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			try {
				if(Auth::user_logged() && comment.get_author() == Auth::get_current_user().get_name()) {
					switch(op) {
						case EXIT:
							exit = true;
							break;
						case EVALUATE:
							CommentController::avaliation(comment);
							break;
						case EDIT:
							CommentController::edit(comment);
							break;
						case DELETE:
							exit = CommentController::destroy(comment);
							break;
						default:
							throw invalid_argument("Invalid option!");
							break;
					}
				}
				else if(Auth::user_logged()) {
					switch(op) {
						case EXIT:
							exit = true;
							break;
						case EVALUATE:
							CommentController::avaliation(comment);
							break;
						default:
							throw invalid_argument("Invalid option!");
							break;
					}
				}
				else{
					switch(op) {
						case EXIT:
							exit = true;
							break;
						default:
							throw invalid_argument("Invalid option!");
							break;
					}
				}
			} catch(invalid_argument erro) {
				error = true;
			}
		}
	}

	void CommentController::edit(Comment comment) {
		try{
			comment = CommentView::edit_page(comment);                    // render edit page and get new comment
			// CommentModel::update(comment);                             // safe using the model                 // TODO: put a stub in here (later implement) 
		} 
		catch(invalid_argument erro) {}
	}

	void CommentController::avaliation(Comment comment) {
		bool exit = false;
		bool error = false;

		while(!exit){
			string option = CommentView::avaliation_page(comment, error);
			error = false;

			int value;
			try{
				value = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			Avaliation avaliation;

			try{
				avaliation.set(value);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			try{
				comment.set_avaliation(Auth::get_current_user().get_name(), avaliation);
				CommentView::finish_avaliation_page(true);
				Stub::update_comment(comment);
				break;
			}
			catch(invalid_argument erro){
				CommentView::finish_avaliation_page(false);
				break;
			}
		}
	}


	bool CommentController::destroy(Comment comment) {
		bool error = false;
		const int SIM = 1;
		const int NAO = 0;
		
		while(true){
			string option;
			try{
				option = CommentView::delete_page(error);
				error = false;
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}
			
		int op;
			try{
				op = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			switch(op){
				case SIM:
					Stub::destroy_comment(comment);
					CommentView::deleted_page();
					return true;
				case NAO:
					return false;
			}
		}
	}

// POST CONTROLLER CLASS --------------------------------------------------------------------------------

	void PostController::index(Blog blog){
		const int EXIT = 0;

		bool error = false;
		bool exit = false;
		

		while(!exit){
		vector<Post> posts = Stub::get_posts(blog);
			string option = PostView::index_page(posts, error);

			error = false;

			int id;
			try{
				id = stoi(option);
				if(id > int(posts.size())) throw invalid_argument("Invalid id");
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}
			switch(id){
				case EXIT:
					exit = true;
					break;
				default:
					PostController::show(posts[(unsigned long)(id - 1)]);
					break;
			}
		}
	}

	void PostController::create() {
		try {
			Post post = PostView::create_page();                          // render create page and receive a new post
			// PostModel::save(Post);                                     // Send to model to save it             // TODO: put a stub in here (later implement)
		} 
		catch(invalid_argument erro) {}
	}

	void PostController::show(Post post) {
		const int EXIT = 0;
		const int COMMENTS = 1;
		const int NEWCOMMENT = 2;
		const int EVALUATE = 3;
		const int EDIT = 4;
		const int DISALLOW = 5;
		const int DELETE = 6;

		bool exit = false;
		bool error = false;

		while(!exit) {
			string option = PostView::show_page(post, error);                // render show page
			error = false;
			
		int op;
			try{
				op = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			try {
				if(Auth::user_logged() && post.get_author() == Auth::get_current_user().get_name()){
					switch(op) {
						case EXIT:
							exit = true;
							break;
						case COMMENTS:
							CommentController::index(post);
							break;
						case NEWCOMMENT:
							CommentController::create();
							break;  
						case EDIT:
							PostController::edit(post);
							break;
						case DISALLOW:
							post.disallow_comments();
							break;
						case DELETE:
							 exit = PostController::destroy(post);
							break;
						case EVALUATE:
							PostController::avaliation(post);
							break;
						default:
							throw invalid_argument("Invalid option!");
							break;
					}
				}
				else if(Auth::user_logged()){
					switch(op) {
						case EXIT:
								exit = true;
								break;
						case COMMENTS:
							CommentController::index(post);
							break;
						case NEWCOMMENT:
							CommentController::create();
							break;  
						case EVALUATE:
							PostController::avaliation(post);
							break;
						default:
							throw invalid_argument("Invalid option!");
							break;
					}
				}
				else{
					switch(op) {
						case EXIT:
								exit = true;
								break;
						case COMMENTS:
							CommentController::index(post);
							break;
						default:
							throw invalid_argument("Invalid option!");
							break;
					}
				}
			} catch(invalid_argument erro) {
				error = true;
			}
		}
	}

	void PostController::avaliation(Post post) {
		bool exit = false;
		bool error = false;

		while(!exit){
			string option = PostView::avaliation_page(post, error);
			error = false;

			int value;
			try{
				value = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			Avaliation avaliation;

			try{
				avaliation.set(value);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			try{
				post.set_avaliation(Auth::get_current_user().get_name(), avaliation);
				PostView::finish_avaliation_page(true);
				Stub::update_post(post);
				break;
			}
			catch(invalid_argument erro){
				PostView::finish_avaliation_page(false);
				break;
			}
		}
	}

	void PostController::edit(Post post) {
		try{
			post = PostView::edit_page(post);                             // render edit page and get new post
			// PostModel::update(post);                                   // safe using the model                 // TODO: put a stub in here (later implement) 
		}
		catch(invalid_argument erro) {}
	}

	bool PostController::destroy(Post post) {
		bool error = false;
		const int SIM = 1;
		const int NAO = 0;
		
		while(true){
			string option;
			try{
				option = PostView::delete_page(error);
				error = false;
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}
			
		int op;
			try{
				op = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			switch(op){
				case SIM:
					Stub::destroy_post(post);
					PostView::deleted_page();
					return true;
				case NAO:
					return false;
			}
		}
	}

// BLOG CONTROLLER CLASS --------------------------------------------------------------------------------

	void BlogController::index() throw(invalid_argument){
		const int EXIT = 0;

		bool exit = false;
		bool error = false;
		
		vector<Blog> blogs = Stub::get_all_blogs();                  // get all Blogs from model

		while(!exit){
			string option = BlogView::index_page(blogs, error);           // render page with all blogs
			
			int id;
			try{
				id = stoi(option);
				if(id > int(blogs.size())) throw invalid_argument("Invalid id");
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			switch(id){
				case EXIT:
					exit = true;
					break;
				default:
					BlogController::show(blogs[(unsigned long)(id - 1)]);
					break;
			}
		}
	}

	void BlogController::user_blogs() throw(invalid_argument) {
		const int EXIT = 0;
		
		bool exit = false;
		bool error = false;
		
		
		while(!exit){
			vector<Blog> blogs = Stub::get_blogs(Auth::get_current_user());  // get all Blogs from model
			string option = BlogView::index_page(blogs, error);
			error = false;
			
			int id;
			try{
				id = stoi(option);
				if(id > int(blogs.size())) throw invalid_argument("Invalid id");
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			switch(id){
				case EXIT:
					exit = true;
					break;
				default:
					BlogController::show(blogs[(unsigned long)(id - 1)]);
					break;
			}
		}
	}

	void BlogController::create() throw(invalid_argument) {
		try {
			Blog blog = BlogView::create_page();                           // render create page and receive a new blog
			// BlogModel::save(user);                                      // Send to model to save it             // TODO: put a stub in here (later implement)
		} 
		catch(invalid_argument erro) {}
	}

	void BlogController::show(Blog blog){
		const int EXIT = 0;
		const int VIEWPOST = 1;
		const int NEWPOST = 2;
		const int DELETEBLOG = 3;
		
		bool exit = false;
		bool error = false;
		
		while(!exit){
			string option = BlogView::show_page(blog, error);
			error = false;
			
			int op;
			try{
				op = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			if(Auth::user_logged() && Auth::get_current_user().get_name() == blog.get_author()){
					switch(op){
						case EXIT:
							exit = true;
							break;
						case VIEWPOST:
							PostController::index(blog);
							break;
						case NEWPOST:
							PostController::create();
							break;
						case DELETEBLOG:
							exit = BlogController::destroy(blog);
							break;
						default:
							error = true;
							break;
					}
				}
				else{
					switch(op){
						case EXIT:
							exit = true;
							break;
						case VIEWPOST:
							PostController::index(blog);
							break;
						default:
							error = true;
							break;
					}
				}
		} 
	}

	void BlogController::edit(Blog blog) {
		try{
			blog = BlogView::edit_page(blog);                             // render edit page and get new blog
			// BlogModel::update(blog);                                   // safe using the model                 // TODO: put a stub in here (later implement) 
		}
		catch(invalid_argument erro) {}
	}

	bool BlogController::destroy(Blog blog) throw(invalid_argument) {
		bool error = false;
		const int SIM = 1;
		const int NAO = 0;
		
		while(true){
			string option;
			try{
				option = BlogView::delete_page(error);
				error = false;
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			int op;
			try{
				op = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}
			
			switch(op){
				case SIM:
					Stub::destroy_blog(blog);
					BlogView::deleted_page();
					return true;
				case NAO:
					return false;
			}
		}
	}

// USER CONTROLLER CLASS ---------------------------------------------------------------------------------

	void UserController::create() {
		User user = UserView::create_page();                            // render create page and receive a new user
			
		if(UserModel::find(user.get_email())){
			cout << "Email ja em uso." << endl;
			cout << "Aperte 'ENTER' para retornar" << endl;
			getchar();
		}
		else{
			cout << "Nova conta criada com sucesso!" << endl << "Aperte 'ENTER' para retornar ao menu principal" << endl;
			getchar();
			UserModel::add(user);         
		}
			
	}

	void UserController::show() {
		const int EXIT = 0;
		const int CHANGE_PASSWORD = 1;
		const int DELETE_ACCOUNT = 2;

		bool exit = false;
		bool error = false;

		User user = Auth::get_current_user();                           // get the current user

		while(!exit) {
			string option = UserView::show_page(user, error);                // render show page

			int op;
			try{
				op = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			try {
				switch(op) {
					case EXIT:
						exit = true;
						break;
					case CHANGE_PASSWORD:
						UserController::edit();
						break;
					case DELETE_ACCOUNT:
						exit = UserController::destroy(user);
						break;
					default:
						throw invalid_argument("Invalid option!");
						break;
				}
			} catch(invalid_argument erro) {
				error = true;
			}
		}
	}

	void UserController::edit() {
		try{
			User user = Auth::get_current_user();                         // get the current user           
			user = UserView::edit_page(user);                             // render edit page and get new user
			UserModel::update(user);                                   // safe using the model                 // TODO: put a stub in here (later implement) 
		} catch(invalid_argument erro) {}
	}

	bool UserController::destroy(User user) {
		bool error = false;
		const int SIM = 1;
		const int NAO = 0;
		
		while(true){
			string option;
			try{
				option = UserView::delete_page(error);
				error = false;
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}
			
			int op;
			try{
				op = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			switch(op){
				case SIM:
					UserModel::destroy(user);
					UserView::deleted_page();
					Auth::logout();
					return true;
				case NAO:
					return false;
			}
		}
	}

// AUTH CONTROLLER CLASS ---------------------------------------------------------------------------------

	void AuthController::login() {
		bool error = false;
		
		Email email;
		Password password;
		
		try {
			// TODO: verify if the email is passed as reference so it can be altered within this function
			AuthView::login_page(email, password);
		} catch(invalid_argument erro) {
			error = true;
		}

		error |= !UserModel::autenticate(email, password);;
		
		AuthView::finish_login_page(error);

		if(not error) {
			Auth::login(UserModel::get(email)); 
		} 
	}

	void AuthController::logout() {
		const int SIM = 1;
		const int NAO = 2;
		
		string option = AuthView::logout_page();
		
		int op;
			try{
			op = stoi(option);
			}
			catch(invalid_argument erro){
				throw invalid_argument("Invalid option!");
			}

		switch(op){
			case SIM:
				// TODO: verify implementation to see if can be used like that
				Auth::logout();
			case NAO:
				return;
			default:
				throw invalid_argument("Invalid option!");
		}
	}

// WELCOME CONTROLLER CLASS ------------------------------------------------------------------------------

	void WelcomeController::home_page() {
		const int EXIT = 0;
		const int LOGIN = 1;
		const int LOGOUT = 1;
		const int REGISTER = 2;
		const int ACCOUNT = 2;
		const int LISTBLOGS = 3;
		const int MYBLOGS = 4;
		const int CREATEBLOG = 5;
		
		bool exit = false;
		bool error = false;

		while(!exit){
			string option = WelcomeView::home_page(error);
			error = false;
			
			int op;
			try{
				op = stoi(option);
			}
			catch(invalid_argument erro){
				error = true;
				continue;
			}

			try{
				if(Auth::user_logged()) {
					switch(op){
						case LOGOUT:
							AuthController::logout();
							break;
						case ACCOUNT:
							UserController::show();
							break;
						case LISTBLOGS:
							BlogController::index();
							break;
						case MYBLOGS:
							BlogController::user_blogs();
							break;
						case CREATEBLOG:
							BlogController::create();
							break;
						case EXIT:   
								exit = true; 
								break;
						default:
								throw invalid_argument("Invalid option!");
								break;
					}
				} else {
					switch(op) {
						case LOGIN:
							AuthController::login();
							break;
						case REGISTER:
							UserController::create();
							break;
						case LISTBLOGS: 
							BlogController::index();
							break;
						case EXIT:    
							exit = true; 
							break;
						default:
							throw invalid_argument("Invalid option!");
							break;
					}
				}
			} catch(invalid_argument erro) {
				error = true;
			}
		}
	}

