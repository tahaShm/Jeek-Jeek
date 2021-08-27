#ifndef __JEEK_H__
#define __JEEK_H__

#include "comment.hpp"
#include "functions.hpp"
#include "exceptions.hpp"
#define MAX_JEEK_SIZE 140
class Jeek{
public:
	Jeek();
	Jeek(string _jeekText);
	Jeek(string _text , string _tag1 , string _tag2 , string m1);
	vector<string> get_mentionedUsers();
	void setId(string id);
	string getId();
	void showDetails();
	string getText();
	bool is_tag_valid(string hash_tag);
	void addNewComment(string _commentText , string _commentId , string owner);
	bool is_comment_here(string _commentId);
	Comment* get_the_comment(string _commentId);
	void addRejeek();
	void likeJeek(string liker);
	bool dislikeJeek(string disliker);
	bool is_liker_unique(string liker);
	int findLiker(string disliker);
	
	void clearJeek();
	void setText(string _text);
	void addTag(string _tag);
	void addMentioned(string _mentioned);
	void addLiker(string _liker);

	string getDetails();
private:
	string jeekId;
	string text;
	vector <string> tags;
	vector <string> mentionedUsers;
	vector <string> likers;
	int reJeeks;
	vector <Comment> comments;
};

#endif

