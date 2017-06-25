#ifndef __MODEL_H_INCLUDED__
#define __MODEL_H_INCLUDED__

#include "domains.hpp"
#include "entity.hpp"
#include <bits/stdc++.h>
using namespace std;

/**
* @class UserModel
* @brief Defines interface with persistence.
* @note General functions are static, a more specific one is not. All of them are private
* This class get data from the persistence module. It selects the data that will be returned. 
*/
class UserModel : public User {

	/// Permits UserController to be aware of this class and use everything.
	friend class UserController;
	public:
		static const string FILENAME; ///< The name of the file that contains the data

		/**
		* @brief  Get all users
		* @return All Users in the system
		* This function extract all Users in the db_users.txt file and return them
		*/
		static vector<User> get_all();
		/**
		* @brief  Add a new user
		* @param  user The User object to save
		* @note   The userId given is based on the number of seconds passed since 1972
		* This function add to the end of users.txt the information of the User object given
		*/
		static void add(User);
		/**
		* @brief  Add a vector of new users
		* @param  user The User object to save
		* @note   The userId given is based on the number of seconds passed since 1972
		* This function add to the end of users.txt the information of the User object given
		*/
		static void add(vector<User>);
			/**
		* @brief  Search for a user
		* @param  email The Email object to search
		* @param  name The Name object to search
		* @note   The userId given is based on the number of seconds passed since 1972
		* This function return true if a user that matches the given email and password exist
		*/
		static bool autenticate(Email, Password);
			/**
		* @brief  Search for a user
		* @param  email The Email object to search
		* @note   The userId given is based on the number of seconds passed since 1972
		* This function return true if a user that matches the given email exist
		*/
		static bool find(Email);
		/**
		* @brief  Update a user
		* @param  user The User object to update
		* This function find the user given (through userId) in users.txt and update it 
		*/
		static void update(User);
		/**
		* @brief  Destroy a user
		* @param  user The User object to destroy
		* This function find the user given (through userId) in users.txt and destroy
		*/
		static void destroy(User);
		/**
		* @brief  Get a user from persistence
		* @param  email The Email object to identify the user
		* This function find the user that matches the given email
		*/
		static User get(Email);
};

/**
* @class BlogModel
* @brief Defines interface with persistence.
* @note General functions are static, a more specific one is not. All of them are private
* This class get data from the persistence module. It selects the data that will be returned. 
*/
class BlogModel : public Blog {

	/// Permits BlogController to be aware of this class and use everything.
	friend class BlogController;

	private:
		/**
		* @brief  Get all blogs
		* @return A vector of Blogs with all blogs
		* This function extract all blogs in the db_blogs.txt file and return them 
		*/
		static vector<Blog> all();
		/**
		* @brief  Get all blogs that belongs to a specific user
		* @param  user The User object that has the blogs
		* @return A vector of Blogs with all blogs found
		* This function extract all blogs in the db_blogs.txt file that have blogAuthorId equal to userId and return them
		*/ 
		static vector<Blog> from_user(User);
};

/**
* @class PostModel
* @brief Defines interface with persistence.
* @note  General functions are static, a more specific one is not. All of them are private
* This class get data from the persistence module. It selects the data that will be returned. 
*/
class PostModel : public Post {

	/// Permits PostController to be aware of this class and use everything.
	friend class PostController;

	private:
		/**
		* @brief  Get all posts that belongs to a specific User
		* @param  blog A Blog object that has the posts
		* @return A vector of Posts with all posts related with the blog given
		* This function extract all Posts in the db_posts.txt file that have postOriginId equal to blogId and return them
		*/
		static vector<Post> all_from(Blog);
		/**
		* @brief  Get all posts that belongs to a specific Blog and was made by a specific User
		* @param  blog A Blog object that has the posts
		* @param  user The User object that has the posts
		* @return A vector of Posts with all posts found
		* This function extract all Posts in the db_posts.txt file that have postOriginId equal to blogId and postAuthorId equal to userId and return them
		*/ 
		static vector<Post> from_user(Blog, User);
};

/**
* @class CommentModel
* @brief Defines interface with persistence.
* @note General functions are static, a more specific one is not. All of them are private
* This class get data from the persistence module. It selects the data that will be returned. 
*/
class CommentModel : public Comment {

	/// Permits CommentController to be aware of this class and use everything.
	friend class CommentController;

	private:
		/**
		* @brief  Get all comments that belongs to a specific User
		* @param  post A Post object that has the comments
		* @return A vector of Comments with all comments related with the post given
		* This function extract all comments in the db_comments.txt file that have commentOriginId equal to postId and return them
		*/
		static vector<Comment> all_from(Post);
		/**
		* @brief  Get all comments that belongs to a specific Blog and was made by a specific User
		* @param  blog A Blog object that has the comments
		* @param  user The User object that has the comments
		* @return A vector of Comments with all comments found
		* This function extract all comments in the db_comments.txt file that have commentOriginId equal to blogId and commentAuthorId equal to userId and return them
		*/ 
		static vector<Comment> from_user(Post, User);
};

#endif
