#ifndef __ENTITY_H_INCLUDED__
#define __ENTITY_H_INCLUDED__

#include "domains.hpp"
#include <bits/stdc++.h>
using namespace std;

// TODO: make Auth::logout set currentUser to an empty User

/**
* @class Comment
* @brief Defines how a Comment should be.
* Defines what information a Comment has and how you can access it.
*/
class Comment {
	private:
		Id id; ///< The id of the Comment

		Id parentId; ///< The id of the Post which this Comment belongs

		Name author; ///< The author of the Comment

		Text content; ///< The content of the Comment

		map<Name, bool> has_avaliated; ///< The name of every User that avaliated

		vector<Avaliation> avaliations; ///< All the avaliations given to this content

		/**
		* @brief  Validate the Comment
		* @param  Id The id of the comment to validate  
		* @param  Id The parent id of the comment to validate   
		* @param  Name The author of the comment to validate 
		* @param  Text The content of the comment to validate 
		* Validate Comment by verifying if the id or the parent id or the author name or the text is empty. If it is, it will throw an error.
		*/
		void valid(Id, Id, Name, Text) throw(invalid_argument);
		/**
		* @brief  Warn if both Id's or Name or Text is empty.
		* @retval TRUE At least one of the strings is empty
		* @retval FALSE None of the strings is not empty
		*/
		bool empty();

	public:
		Comment(); ///< Constructor

		~Comment(); ///< Destructor

		/**
		* @brief  Get the id of the author of the comment
		* @return Id The id the author of the comment
		* Get the id of the author of the comment if it is not empty.
		*/
		Id get_id() throw(invalid_argument);
		/**
		* @brief  Get the parent id of the post
		* @return Id The parent id of the post
		* Get the parent id of the post if it is not empty.
		*/
		Id get_parent_id() throw(invalid_argument);
		/**
		* @brief  Get the name of the author of the comment
		* @return Name The name the author of the comment
		* Get the name of the author of the comment if it is not empty.
		*/
		Name get_author() throw(invalid_argument);
		/**
		* @brief  Get the content of the post
		* @return Text The content of the post
		* Get the content of the post if it is not empty.
		*/
		Text get_content() throw(invalid_argument);
		/**
		* @brief  Get the avaliation of the comment
		* @return Avaliation The avaliation of the comment
		* Get the avaliation of the comment if it is not empty.
		*/
		Avaliation get_avaliation();
		/**
		* @brief  Set all the variable needed for Comment
		* @param  Id The id of the comment to set  
		* @param  Id The parent id of the comment to set   
		* @param  Name The author of the comment to set 
		* @param  Text The content of the comment to set 
		*/
		void set(Id, Id, Name, Text);
		/**
		* @brief  Set the id of the comment
		* @param  Id The id of the comment to set  
		* Set the the id of the comment if the id received is valid
		*/
		void set_id(Id) throw(invalid_argument);
		/**
		* @brief  Set the parent id of the comment
		* @param  Id The parent id of the comment to set  
		* Set the the parent id of the comment if the parent id received is valid
		*/
		void set_parent_id(Id) throw(invalid_argument);
		/**
		* @brief  Set the author of the comment
		* @param  Name The author of the comment to set  
		* Set the the author of the comment if the author received is valid
		*/
		void set_author(Name) throw(invalid_argument);
		/**
		* @brief  Set the content of the comment
		* @param  Text The content of the comment to set  
		* Set the the content of the comment if the content received is valid
		*/
		void set_content(Text) throw(invalid_argument);
		/**
		* @brief  Add an avaliation
		* @param  Name The author of the avaliation to add
		* @param  Avaliation The avaliation to add 
		* Add an avaliation, making sure that no user do more than one avaliation.
		*/
		void set_avaliation(Name, Avaliation) throw(invalid_argument);
};

/**
* @class Post
* @brief Defines how a Post should be.
* Defines what information a Post has and how you can access it.
*/
class Post {
	private:
		Id id; ///< The id of the Post

		Id parentId; ///< The id of the Blog which this Post belongs

		Name author; ///< The author of the Post

		Text content; ///< The content of the Post

		map<Name, bool> has_avaliated; ///< The name of every User that avaliated

		vector<Avaliation> avaliations; ///< All the avaliations given to this content

		static const int comments_limit = 5; ///< Maximum number of times that a person can comment

		map<Name, int> number_comments; ///< The name of every User that has commented

		vector<Comment> comments; ///< All the Comments made for this Post

		bool comments_allowed; ///< If comments are allowed

		/**
		* @brief  Validate the Post
		* @param  Id The id of the post to validate  
		* @param  Id The parent id of the post to validate   
		* @param  Name The author of the post to validate 
		* @param  Text The content of the post to validate 
		* Validate Post by verifying if the id or the parent id or the author name or the text is empty. If it is, it will throw an error.
		*/
		void valid(Id, Id, Name, Text) throw(invalid_argument); 

		/**
		* @brief  Warn if both Id's or Name or Text is empty.
		* @retval TRUE At least one of the strings is empty
		* @retval FALSE None of the strings is not empty
		*/
		bool empty();

	public:
		Post(); ///< Constructor

		~Post();  ///< Destructor

		/**
		* @brief  Get the id of the post
		* @return Id The id of the post
		* Get the id of the post if it is not empty.
		*/
		Id get_id() throw(invalid_argument);
		/**
		* @brief  Get the parent id of the post
		* @return Id The parent id of the post
		* Get the parent id of the post if it is not empty.
		*/
		Id get_parent_id() throw(invalid_argument);
		/**
		* @brief   Get the name of the author of the post
		* @return Name The name the author of the post
		* Get the name of the author of the post if it is not empty.
		*/
		Name get_author() throw(invalid_argument);
		/**
		* @brief   Get the content of the post
		* @return Text The content of the post
		* Get the content of the post if it is not empty.
		*/
		Text get_content() throw(invalid_argument);
		/**
		* @brief   Get the avaliation of the post
		* @return Avaliation The avaliation of the post
		* Get the avaliation of the post if it is not empty.
		*/
		Avaliation get_avaliation();
		/**
		* @brief   Get the comments of the post
		* @return vector<Comment> the comments of the post
		* Get the comments of the post if it is not empty.
		*/
		vector<Comment> get_comments() throw(invalid_argument);
		/**
		* @brief  Set all the variable needed for Post
		* @param  Id The id of the post to set  
		* @param  Id The parent id of the post to set   
		* @param  Name The author of the post to set 
		* @param  Text The content of the post to set 
		*/
		void set(Id, Id, Name, Text);
		/**
		* @brief  Set the id of the post
		* @param  Id The id of the post to set  
		* Set the the id of the post if the id received is valid
		*/
		void set_id(Id) throw(invalid_argument);
		/**
		* @brief  Set the parent id of the post
		* @param  Id The parent id of the post to set  
		* Set the the parent id of the post if the parent id received is valid
		*/
		void set_parent_id(Id) throw(invalid_argument);
		/**
		* @brief  Set the author of the post
		* @param  Name The author of the post to set  
		* Set the the author of the post if the author received is valid
		*/
		void set_author(Name) throw(invalid_argument);
		/**
		* @brief  Set the content of the post
		* @param  Text The content of the post to set  
		* Set the the content of the post if the content received is valid
		*/
		void set_content(Text) throw(invalid_argument);
		/**
		* @brief  Add an avaliation
		* @param  Name The author of the avaliation to add
		* @param  Avaliation The avaliation to add 
		* Add an avaliation, making sure that no user do more than one avaliation.
		*/
		void set_avaliation(Name, Avaliation) throw(invalid_argument);
		/**
		* @brief  Add an comment
		* @param  Comment The comment to add 
		* Add an comment, making sure that no user do more than one comment.
		*/
		void set_comment(Comment) throw(invalid_argument);
		/**
		* @brief   Allow comments int this post
		* This function atribute true to commentsAllowed
		*/
		void allow_comments();
		/**
		* @brief   Disallow comments int this post
		* This function atribute false to commentsAllowed and delete every comment linked with this post
		*/
		void disallow_comments();
};

/**
* @class Blog
* @brief Defines how a Blog should be.
* @note The size is small for some reasons.
* Defines what information a Blog has and how you can access it.
*/
class Blog {
	private:
		Id id; ///< id of the Blog

		Name author; ///< The author of the Blog

		Name name; ///< The name of the Blog

		vector<Post> posts; ///< All Posts made in this Blog

		/**
		* @brief  Validate the Comment
		* @param  Id The id of the blog to validate 
		* @param  Name The author of the blog to validate
		* @param  Name The name of the blog to validate 
		* Validate Comment by verifying if the id or the parent id or the author name or the text is empty. If it is, it will throw an error.
		*/
		void valid(Id, Name, Name) throw(invalid_argument);

	public:
		Blog(); ///< Constructor

		~Blog(); ///< Destructor

		/**
		* @brief  Get the id of the author of the blog
		* @return Id The id the author of the blog
		* Get the id of the author of the blog if it is not empty.
		*/
		Id get_id() throw(invalid_argument);
		/**
		* @brief  Get the name of the author of the blog
		* @return Name The name the author of the blog
		* Get the name of the author of the blog if it is not empty.
		*/
		Name get_author() throw(invalid_argument);
		/**
		* @brief  Get the name of the blog
		* @return Name The name of the blog
		* Get the name of the blog if it is not empty.
		*/
		Name get_name() throw(invalid_argument);
		/**
		* @brief  Get the posts of the blog
		* @return A vector with Posts of the blog
		* Get the posts of the blog if it is not empty.
		*/
		vector<Post> get_posts() throw(invalid_argument);
		/**
		* @brief  Set all the variable needed for Blog
		* @param  Id The id of the blog to set  
		* @param  Name The author of the blog to set 
		* @param  Name The name of the blog to set  
		*/
		void set(Id, Name, Name);
		/**
		* @brief  Set the id of the blog
		* @param  Id The id of the blog to set  
		* Set the the id of the blog if the id received is valid
		*/
		void set_id(Id) throw(invalid_argument);
		/**
		* @brief  Set the author of the blog
		* @param  Name The author of the blog to set  
		* Set the the author of the blog if the author received is valid
		*/
		void set_author(Name) throw(invalid_argument);
		/**
		* @brief  Set the name of the blog
		* @param  Name The name of the blog to set  
		* Set the the name of the blog if the author received is valid
		*/
		void set_name(Name) throw(invalid_argument);
		/**
		* @brief  Add a post
		* @param  Post The post to add 
		*/
		void set_post(Post) throw(invalid_argument);
};

/**
* @class User
* @brief Defines the User
* Defines what information User has and how you can access it.
*/
class User{
	private:
		Id id; ///< The Id of the User

		Name name; ///< The name of the User

		Password password; ///< The password of the User

		Email email; ///< The email of the User

		bool anonymous; ///< If the current user is anonymous

		/**
		* @brief   Validate the User
		* @param  Id The id of the blog to set  
		* @param  Name The name of the user to set 
		* @param  Email The email of the user to set 
		* @param  Password The password of the user to set  
		* Validate User by verifying if the name, email or password are empty. If any of them are empty, it will not create.
		*/
		void valid(Id, Name, Email, Password) throw(invalid_argument);

	public:
		User();  ///< Constructor

		~User();  ///< Destructor

		/**
		* @brief   Get the id of the user
		* @return Id The id of the user
		* Get the id of the user if it is not empty.
		*/
		Id get_id() throw(invalid_argument);
		/**
		* @brief   Get the name of the user
		* @return Name The name of the user
		* Get the name of the user if it is not empty.
		*/
		Name get_name() throw(invalid_argument);
		/**
		* @brief   Get the email of the user
		* @return Email The email of the user
		* Get the email of the user if it is not empty.
		*/
		Email get_email() throw(invalid_argument);
		/**
		* @brief   Get the password of the user
		* @return Password The password of the user
		* Get the password of the user if it is not empty.
		*/
		Password get_password() throw(invalid_argument);
		/**
		* @brief  Set all the variable needed for Blog
		* @param  Id The id of the blog to set  
		* @param  Name The name of the user to set 
		* @param  Email The email of the user to set 
		* @param  Password The password of the user to set  
		*/
		void set(Id, Name, Email, Password);
		/**
		* @brief  Set the id of the user
		* @param  Id The id of the user to set  
		* Set the the id of the user if the id received is valid
		*/
		void set_id(Id) throw(invalid_argument);
		/**
		* @brief  Set the name of the user
		* @param  Name The name of the user to set  
		* Set the the name of the user if the name received is valid
		*/
		void set_name(Name) throw(invalid_argument);
		/**
		* @brief  Set the email of the user
		* @param  Email The email of the user to set  
		* Set the the email of the user if the author received is valid
		*/
		void set_email(Email) throw(invalid_argument);
		/**
		* @brief  Set the password of the user
		* @param  Password The password of the user to set  
		* Set the the password of the user if the password received is valid
		*/
		void set_password(Password) throw(invalid_argument);
};

/**
* @class Auth
* @brief Defines info needed in authenication
* Keeps informaition of the current user and can tell if someone is logged or not.
*/
class Auth {
	private:
		static bool userLogged; ///< If there is or not a user logged

		static User currentUser; ///< The current user logged

		Auth(); ///< Constructor

		~Auth(); ///< Destructor

	public:
		/**
		* @brief   Can tell if the user is logged
		* See if there is a user logged.
		* @return bool If the user is logged return TRUE, else FALSE.
		*/
		static bool user_logged();
		/**
		* @brief   Get the current User
		* If there is a user logged, return the current user
		* @return bool If the user is logged return TRUE, else FALSE.
		*/
		static User get_current_user() throw(invalid_argument);
		/**
		* @brief   Login the current user
		* Make atribute userLogged true and currentUser equal the user received
		* @param user The user to log in
		*/
		static void login(User);
		/**
		* @brief   Login the current user
		* Make atribute userLogged false and currentUser equal a empty User
		* @param user The user to log in
		*/
		static void logout();
};

#endif

