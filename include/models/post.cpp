//TODO: add comment structure
class Post{
	string author;
	string post;

	vector<int> grades; //keep all grades given to a single post to later calculate it

	Post(string u_author, string u_post){
		author = u_author;
		post = u_post;
	}

	//TODO: find a way to count how many way a person already comment, a person can only comment 5 times
	void add_comment(){}

	//TODO: learn how does this work. A person can give grades more than 1 time?
	//TODO: verify problems with this implementation
	//TODO: verify if the grade send if between 1 and 5
	void add_grade(int grade){
		grades.push_back(grade);
	}

	int final_grade(){
		int grade = 0;

		for(auto i : grades){
			grade += i;
		}

		return grade / grades.size();
	}
};
