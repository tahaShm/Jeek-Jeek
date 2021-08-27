#ifndef __USER_H__
#define __USER_H__

#include "jeek.hpp"
#include "functions.hpp"
#include "exceptions.hpp"

class User{
public:
	User();
	User(string _username , string _displayName , string _password);
	string getUsername();
	string get_displayName();
	bool is_its_username(string _username);
	bool is_its_password(string _password);
	void clearAll();
	void addJeek(Jeek newJeek);
	bool is_jeek_here(string _jeekId);
	void show_jeek(string _jeekId);
	vector<string> showSearchedDetails();
	vector<string> searchTag(string hash_tag);
	void add_comment(string _jeekId , string _commentText , string _commentId , string owner);
	bool isCommentHere(string _commentId);
	Comment* get_comment(string _commentId);
	string getjeekText(string _jeekId);
	void rejeeked(string _jeekId);
	bool like(string _jeekId , string liker);
	bool dislike(string _jeekId , string disliker);
	void addFollower(string follower);
	bool has_this_follower(string _username);
	void addFollowing(string _following);
	void deleteFollower(string _username);
	void deleteFollowing(string _username);
	void addNewNotification(string newNotification);
	void showNotifications();
	vector<string> getfollowers();

	string checkJeekDetails(string jeekDetail);
	string get_jeek_datails(string _jeekId);
	Jeek* get_jeek(string _jeekId);
	bool is_new_liker(string _jeekId , string _username);
	int getJeekLikes(string _jeekId);
	int getJeekRejeeks(string _jeekId);

private:
	string username;
	string displayName;
	string password;
	vector <Jeek> jeeks;
	vector <string> followers;
	vector <string> followings;
	vector <string> notifications;	
};

#endif