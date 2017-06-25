#ifndef __CONTROLLER_H_INCLUDED__
#define __CONTROLLER_H_INCLUDED__

#include "domains.hpp"
#include "entity.hpp"
#include "stubs.hpp"
#include <bits/stdc++.h>
using namespace std;

// TODO: remove this public functions -> make them friends or something like that

/**
* @class CommentController
* @brief Responsible for manipulating the logic around Comment, including create, showing, updating and destroying
* @note It is aware of both CommentView and CommentModel 
*/
class CommentController : public Comment {

	/// Permits CommentView to be aware of this class and use everything.
	friend class CommentView;

	private:
		CommentController(); ///< Constructor

		~CommentController(); ///< Destructor

		/**
		* @brief   Controls the logic of showing a comment
		* @param comment This comment this controller will show
		* Render a page with information of a comment. This page is used to see a comment.
		*/
		static void show(Comment);
		/**
		* @brief   Controls the logic of editing a comment
		* @param comment The comment that we want to edit.
		* Render a page to fill the information needed to update the comment if you are the owner of the comment
		*/
		static void edit(Comment);
		/**
		* @brief   Controls the logic of deleting a comment
		* Render a page of confirmation to confirm if that is what the owner wants. Then erase from persistence this specific comment.
		* @param comment The comment that the owner wants to delete.
		* @return bool If the comment was deleted of not
		*/
		static bool destroy(Comment);
		
		static void avaliation(Comment);

	public:
		/**
		* @brief   Controls the logic of showing all comments
		* @param post The post from where to extract the comments.
		* Render a page that show all comments. If there is no comments to show, it will tell the current user that there are no blogs.
		*/
		static void index(Post);
		/**
		* @brief   Controls the logic for creating a new Comment
		* Render a page to fill the information needed to create a new Comment and then save in the persistence.
		*/
		static void create();
};

/**
* @class PostController
* @brief Responsible for manipulating the logic around Post, including create, showing, updating and destroying
* @note It is aware of both PostView and PostModel 
*/
class PostController : public Post {

	/// Permits PostView to be aware of this class and use everything.
	friend class PostView;

	private:
		PostController(); ///< Constructor

		~PostController(); ///< Destructor

		/**
		* @brief   Controls the logic of showing a Post
		* @param post This post this controller will show
		* Render a page with information of a post. This page is used to see a post.
		*/
		static void show(Post);
		/**
		* @brief   Controls the logic of editing a post
		* @param post The post that we want to edit.
		* Render a page to fill the information needed to update the post if you are the owner of the post
		*/
		static void edit(Post);
		/**
		* @brief   Controls the logic of deleting a post
		* @param post The post that the owner wants to delete.
		* @return bool If the post was deleted or not
		* Render a page of confirmation to confirm if that is what the owner wants. Then erase from persistence this specific post.
		*/
		static bool destroy(Post);
	
		static void avaliation(Post);
	public:
		/**
		* @brief   Controls the logic of showing all posts
		* @param blog The blog from where to extract the posts.
		* Render a page that show all posts. If there is no posts to show, it will tell the current user that there are no blogs
		*/
		static void index(Blog);
		/**
		* @brief   Controls the logic for creating a new Post
		* Render a page to fill the information needed to create a new Post and then save in the persistence.
		*/
		static void create();
};

/**
* @class BlogController
* @brief Responsible for manipulating the logic around Blog, including create, showing, updating and destroying
* @note It is aware of both BlogView and BlogModel 
*/
class BlogController : public Blog {

	/// Permits WelcomeController to be aware of this class and use everything.
	friend class WelcomeController;

	private:
		BlogController(); ///< Constructor

		~BlogController(); ///< Destructor

		/**
		* @brief  Controls the logic of showing all blogs
		* Render a page that show all blogs. If there is no blogs to show, it will tell the current user that there are no blogs.
		*/
		static void index() throw(invalid_argument);
		/**
		* @brief  Controls the logic of showing to the current user all blogs he created.
		* Render a page that show all blogs current user created. If there is no blogs to show, it will tell the current user that there is no Blogs
		*/
		static void user_blogs() throw(invalid_argument);
		/**
		* @brief  Controls the logic for creating a new Blog
		* Render a page to fill the information needed to create a new Blog and then save in the persistence.
		*/
		static void create() throw(invalid_argument);
		/**
		* @brief  Controls the logic of showing a Blog
		* @param  blog This blog this controller will show
		* Render a page with information of a blog. This page is used to see a blog.
		*/
		static void show(Blog);
		/**
		* @brief  Controls the logic of editing a blog
		* @param  blog The blog that we want to edit.
		* Render a page to fill the information needed to update the blog if you are the owner of the blog
		*/
		static void edit(Blog);
		/**
		* @brief  Controls the logic of deleting a blog
		* @param  blog The blog that the owner wants to delete.
		* @return bool If the blog was deleted or not
		* Render a page of confirmation to confirm if that is what the owner wants. Then erase from persistence this specific blog.
		*/
		static bool destroy(Blog) throw(invalid_argument);
};

/**
* @class UserController
* @brief Responsible for manipulating the logic around User, including create, showing, updating and destroying
* @note It is aware of both UserView and UserModel 
*/
class UserController : public User {

	/// Permits UserView to be aware of this class and use everything.
	friend class UserView;

	private:
		UserController(); ///< Constructor

		~UserController(); ///< Destructor

		/**
		* @brief  Controls the logic of editing a user
		* @param  user The user that we want to edit.
		* Render a page to fill the information needed to update the user if you are the owner of the user
		*/
		static void edit();
		/**
		* @brief  Controls the logic of deleting a user
		* @param  user The user that the owner wants to delete.
		* @return bool If the user was deleted or not
		* Render a page of confirmation to confirm if that is what the owner wants. Then erase from persistence this specific user.
		*/
		static bool destroy(User);

	public:
		/**
		* @brief  Controls the logic for creating a new User
		* Render a page to fill the information needed to create a new User and then save in the persistence.
		*/
		static void create();
		/**
		* @brief  Controls the logic of showing the current user
		* Render a page with information of the current user. This page is used as a profile page.
		*/
		static void show();
};

/**
* @class AuthController
* @brief Responsible for the login and logout of users
* @note It is aware of both AuthView and AuthModel 
*/
class AuthController : public Auth {

	/// Permits AuthView to be aware of this class and use everything.
	friend class AuthView;

	private:
		AuthController(); ///< Constructor

		~AuthController(); ///< Destructor

	public:
		/**
		* @brief  Control the logic of login
		* Render the page of login and verify if the user typed is real. If it is, the user is now logged.
		*/
		static void login();
		/**
		* @brief  Control the logic of logout
		* Render the page of logout to verify if the current user really wants to logout. If the current user really wants it, the user is logged out.
		*/
		static void logout();
};

/**
* @class WelcomeController
* @brief Responsible for the home page
*/
class WelcomeController {

	/// Permits WelcomeView to be aware of this class and use everything.
	friend class WelcomeView;

	private:
		WelcomeController(); ///< Constructor

		~WelcomeController(); ///< Destructor

	public:
		/**
		* @brief  Controls the logic of the home page
		* Render the home page of the application that changes if the user is logged and take the user to different parts of the application.
		*/
		static void home_page();
};

#endif
