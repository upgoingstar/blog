//------------------------------------------------
// Includes
//------------------------------------------------

  #include "entities.hpp"
  #include <bits/stdc++.h>
  using namespace std;

//------------------------------------------------
// Method Implementation of Class User
//------------------------------------------------

  User::User() {
    this->anonymous = true;
  }

  User::~User() {}

  void User::valid(Name name, Email email, Password password) throw(invalid_argument) {
    if(name.empty() or email.empty() or password.empty()) {
      throw invalid_argument("Invalid informations to compose a user!");
    }
  }

  void User::set(Name name, Email email, Password password) {
    User::valid(name, email,password);
    this->name = name;
    this->password = password;
    this->email = email;
    this->anonymous = false;
  }

  Name User::get_name() throw(invalid_argument) {
    if(anonymous) {
      throw invalid_argument("This user is anonymous, doesn't have a name");
    }
    else {
      return this->name;
    }
  }

  void User::check_user(Email email, Password password) throw(invalid_argument) {
    if(this->email != email or this->password != password or email.empty() or password.empty()) {
      throw invalid_argument( "That is not your email or password!" );
    }
  }

//------------------------------------------------
// Method Implementation of Class Content
//------------------------------------------------

  Content::Content() {}

  Content::~Content() {}

  void Content::valid(Name author, Text content) throw(invalid_argument) {
    if(author.empty() or content.empty()) {
      throw invalid_argument("Invalid informations to compose a content!");
    }
  }

  void Content::set(Name author, Text content) {
    Content::valid(author, content);
    this->author = author;
    this->content = content;
  }

  void Content::add_avaliation(Name name, Avaliation avaliation) throw(invalid_argument) {
    if(has_avaliated[name]) {
      throw invalid_argument("This user has already avaliated!");
    }
    else {
      this->avaliations.push_back(avaliation);
      has_avaliated[name] = true;
    }
  }

  Name Content::get_author() {
    if(this->author.empty()){
      throw invalid_argument("There is no author!");
    }
    return this->author;
  }

  Text Content::get_content() {
    if(this->content.empty()){
      throw invalid_argument("There is no content to show!");
    }
    return this->content;
  }

  Avaliation Content::get_avaliation() {
    int total_sum = 0;
    int total_size = this->avaliations.size();

    for(int i = 0; i < avaliations.size(); i++) {
    	Avaliation avaliation = avaliations[i];
      total_sum += avaliation.get();
    }

    Avaliation ans;
    ans.set(total_sum / total_size);

    return ans;
  }

//------------------------------------------------
// Method Implementation of Class Comment
//------------------------------------------------

  Comment::Comment(Name author, Text comment_content) {
    Content::set(author, comment_content);
  }

  Comment::~Comment() {}

//------------------------------------------------
// Method Implementation of Class Post
//------------------------------------------------

  Post::Post(Name author, Text post_content) {
    Content::set(author, post_content);
    Post::allow_comments();
  }

  Post::~Post() {}

  void Post::allow_comments() {
    comments_allowed = true;
  }

  void Post::disallow_comments() {
    comments_allowed = false;
    this->comments.clear();
  }

  void Post::add_comment(Comment comment) throw(invalid_argument) {
    if(comments_allowed and number_comments[comment.get_author()] < comments_limit) {
      number_comments[comment.get_author()]++;
      this->comments.push_back(comment);
    }
    else {
      throw invalid_argument("This comment is not allowed!");
    }
  }

  vector<Comment> Post::get_comments() {
    if(this->comments.empty()){
      throw invalid_argument("There is no comments!");
    }
    return this->comments;
  }

//------------------------------------------------
// Method Implementation of Class Blog
//------------------------------------------------

	Blog::Blog(){}

  Blog::~Blog() {}

	void Blog::set(Name author, Name blog_name) throw(invalid_argument) {
  	if(author.empty() or blog_name.empty())
  		throw invalid_argument("Invalid blog name or author!");
    this->author = author;
    this->blog_name = blog_name;
  }

  Name Blog::get_author() {
    if(this->author.empty()){
      throw invalid_argument("There is no author!");
    }
    return this->author;
  }

  Name Blog::get_blog_name() {
    if(this->blog_name.empty()){
      throw invalid_argument("This blog has no name!");
    }
    return this->blog_name;
  }

  /*
    Add a post in the blog if you are the creator for the blog.
  */
  void Blog::add_post(Post post) throw(invalid_argument) {
    if(this->author != post.get_author()) {
      throw invalid_argument("You are not allowed to post in this blog!");
    }
    else {
      this->posts.push_back(post);
    }
  }

  vector<Post> Blog::get_posts() {
    if(this->posts.empty()){
      throw invalid_argument("There is no posts in this Blog!");
    }
    return this->posts;
  }
