#ifndef VIEW_H_INCLUDED__
#define VIEW_H_INCLUDED__

#include "domains.hpp"
#include "entity.hpp"

// TODO: finish the new style of documentation

/**
* @class UserView
* @brief Controls interface for User with the user of the system 
* Has all the pages of CRUD
*/
class UserView {

	/// Permits UserController to be aware of this class and use everything.
	friend class UserController;

	private:
		UserView(); ///< Constructor

		~UserView(); ///< Destructor

		/*
		* Render create page to serve as a sign up page
		* Return the new user 
		*/
		static User create_page() throw(invalid_argument);
		/*
		* Render profile page
		* Receives the user
		*/
		static string show_page(User, bool);
		/*
		* Render a page to change password
		* Receives the user
		* Return the updated user
		*/
		static User edit_page(User) throw(invalid_argument);
		/*
		* Render delete page to confirm the user intention to delete his account
		*/
		static bool delete_page(bool);

		static void deleted_page();
};

/**
* @class BlogView
* @brief Controls interface for blog with the user of the system 
* Has all the pages of CRUD
*/
class BlogView {

	/// Permits CommentController to be aware of this class and use everything.
	friend class BlogController;

	private:
		BlogView(); ///< Constructor

		~BlogView(); ///< Destructor

		/*
		* Render all blogs names
		* Receives the all the blogs
		*/
		static string index_page(vector<Blog>, bool);
		/*
		* Render create blog page
		*/
		static Blog create_page() throw(invalid_argument);
		/*
		* Render edit profile page
		* Receives the id of blog
		*/
		static string show_page(Blog, bool);
		/*
		* Render a page to change password
		* Receives the Comment
		* Return the updated Comment
		*/
		static Blog edit_page(Blog) throw(invalid_argument);
		/*
		* Render edit profile page
		* Receives the id of blog
		*/
		static bool delete_page(bool);

		static void deleted_page();
		/*
		* Render menu page
		* Receives a boolean for error
		*/
		static string menu_page(bool);
};

/**
* @class PostView
* @brief Controls interface for Post with the user of the system 
* Has all the pages of CRUD
*/
class PostView {

	/// Permits PostController to be aware of this class and use everything.
	friend class PostController;

	private:
		PostView(); ///< Constructor

		~PostView(); ///< Destructor

		/*
		* Render create page to serve as a sign up page
		* Return the new Comment 
		*/
		static string index_page(vector<Post>, bool) throw(invalid_argument);
		/*
		* Render create post page
		*/
		static Post create_page() throw(invalid_argument);
		/*
		* Render show page
		* Receives the id of post and a boolean (if boolean true, show all posts)
		*/
		static string show_page(Post, bool);
		/*
		* Render edit profile page
		* Receives the id of post
		*/
		static Post edit_page(Post) throw(invalid_argument);
		/*
		* Render edit profile page
		* Receives the id of post
		*/
		static bool delete_page(bool);

		static void deleted_page();
		
		static string avaliation_page(Post, bool);
		
		static void finish_avaliation_page(bool); 
};

/**
* @class CommentView
* @brief Controls interface for Comment with the user of the system 
* Has all the pages of CRUD
*/
class CommentView {

	/// Permits CommentController to be aware of this class and use everything.
	friend class CommentController;

	private:
		CommentView(); ///< Constructor

		~CommentView(); ///< Destructor
		/*
		* Render create page to serve as a sign up page
		* Return the new Comment 
		*/
		static string index_page(vector<Comment>, bool) throw(invalid_argument);
		/*
		* Render create page to serve as a sign up page
		* Return the new Comment 
		*/
		static Comment create_page() throw(invalid_argument);
		/*
		* Render profile page
		* Receives the Comment
		*/
		static string show_page(Comment, bool);
		/*
		* Render a page to change password
		* Receives the Comment
		* Return the updated Comment
		*/
		static Comment edit_page(Comment) throw(invalid_argument);
		/*
		* Render delete page to confirm the Comment intention to delete his account
		*/
		static bool delete_page(bool);

		static void deleted_page();
		
		static string avaliation_page(Comment, bool);
		
		static void finish_avaliation_page(bool); 
};

/**
* @class WelcomeView
* @brief Controles the home page
* Includes Home Page with menu for the program
*/
class WelcomeView {

	/// Permits WelcomeController to be aware of this class and use everything.
	friend class WelcomeController;

	private:
		WelcomeView(); ///< Constructor

		~WelcomeView(); ///< Destructor
		/*
		* Render home page
		*/
		static string home_page(bool); 
};

/**
* @class AuthView
* @brief Controls the interface of authentication
* Includes Login Page and Logout Page
*/
class AuthView : public Auth {

	/// Permits AuthController to be aware of this class and use everything.
	friend class AuthController;

	private:
		AuthView(); ///< Constructor

		~AuthView(); ///< Destructor

		/*
		* Renderiza tela de login
		*/ 
		static void login_page(Email&, Password&);

		static void finish_login_page(bool);
		/*
		* Renderiza tela de logout (so uma confimarcao pro usuario)
		*/
		static string logout_page();
};

#endif
