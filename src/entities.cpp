//------------------------------------------------
// Includes
//------------------------------------------------

  #include "../hdr/entities.hpp"
  #include <bits/stdc++.h>
  using namespace std;

//------------------------------------------------
// Method Implementation of Class User
//------------------------------------------------

  User::User() {
    this->anonymous = true;
  }

  User::~User() {}

  /*
    Validate User by verifying if any of the arguments (name, email and password) already exists, so that there are no two users with the same name or email and password.
    TODO: Need refactoring!
  */
  void User::valid(Name name, Email email, Password password) throw(invalid_argument) {
    if(name.empty() || email.empty() || password.empty()) {
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
      throw invalid_argument("This user don't have a name");
    }
    else {
      return this->name;
    }
  }

  /*
    Check if the email and password given correspond to a real User.
    TODO: Need refactoring!
  */
  void User::check_user(Email email, Password password) throw(invalid_argument) {
    if(this->email != email || this->password != password || !email.empty() || !password.empty()) {
      throw invalid_argument( "That is not your email or password!" );
    }
  };

//------------------------------------------------
// Method Implementation of Class Content
//------------------------------------------------

  Content::Content() {}

  Content::~Content() {}

  /*
    Verify if the arguments are not empty.
  */
  void Content::valid(Name author, Text content) throw(invalid_argument) {
    if(!author.empty() || !content.empty()) {
      throw invalid_argument("Invalid informations to compose a content!");
    }
  }

  /*
    It receives the name of the author of the content and the content.
  */
  void Content::set(Name author, Text content) {
    Content::valid(author, content);
    this->author = author;
    this->content = content;
  }

  /*
    Add an avaliation, making sure that no user do more than one avaliation.
    It receives a the name of the current user and the avaliation.
  */
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

  /*
    Gets the arithmetic mean of all avaliations given the to content in question.
  */
  Avaliation Content::get_avaliation() {
    int total_sum = 0;
    int total_size = this->avaliations.size();

    for(Avaliation avaliation : this->avaliations) {
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

  /*
    Allow comments to be made by other users.
  */
  void Post::allow_comments() {
    comments_allowed = true;
  }

  /*
    Disallow comments. This excludes all current comments.
  */
  void Post::disallow_comments() {
    comments_allowed = false;
    this->comments.clear();
  }

  /*
    Add a comment if possible (no user can comment more than 5 times and the post has to autorize comments).
  */
  void Post::add_comment(Comment comment) throw(invalid_argument) {
    if(comments_allowed && number_comments[comment.get_author()] < comments_limit) {
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

  Blog::Blog(Name author, Name blog_name) {
    this->author = author;
    this->blog_name = blog_name;
  }

  Blog::~Blog() {}

  void Blog::set(Name author, Name blog_name) {
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
  void Blog::add_post(Name name, Post post) throw(invalid_argument) {
    if(this->author != name) {
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
