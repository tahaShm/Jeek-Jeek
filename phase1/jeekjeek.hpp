#ifndef __JEEKJEEK_H__
#define __JEEKJEEK_H__

#include "user.hpp"
#include "reply.hpp"
#include "functions.hpp"
#include "exceptions.hpp"

class JeekJeek{
public:
	JeekJeek();
	void signUp(string _username , string _displayName , string _password);
		bool isUsernameUnique(string _username);
	string logIn(string _username , string _password);
		int findUser(string _username);
	void logOut(string user_in);
	void addNewJeek(Jeek newJeek , string user_in);
		void notifyMentionedUsers(Jeek newJeek , string user_in);
	void showJeek(string _jeekId);
		int findUserOnJeekId(string _jeekId);
	vector<string> searchUser(string _username);
	vector<string> searchHashTag(string hash_tag);
	void addComment(string _jeekId , string _commentText , string user_in);
	void addReplyToComment(string _commentId , string _replyText , string user_in);
		Comment* getComment(string _commentId);
		int findUserOnCommentId(string _commentId);
	void addReplyToReply(string _replyId , string _replyText, string user_in);	
		int findReply(string _replyId);
		int findUserOnReplyId(string _replyId);
	void reJeek(string _jeekId, string user_in);
	void showComment(string _commentId);
	void showReply(string _replyId);
	void like(string _jeekId, string user_in);
	void dislike(string _jeekId, string user_in);
	void follow(string _username, string user_in);
		User* getUserOnName(string _username);
	void unfollow(string _username, string user_in);
	void addNotification(string newNotification , string _username);
	void showNotifications(string user_in);

		vector<string> search(string searched);

		int findLoggedInUser(string _username);
		User* getLoggedInUser(int id);		

private:
	vector <User> users;
	vector<User*> usersIn;
	vector <Reply> replies;
	bool is_user_in;
	int numOfJeeks;
	int numOfComments;
	int numOfReplies;
};

#endif