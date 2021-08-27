#include "user.hpp"
User::User(){}
User::User(string _username , string _displayName , string _password){
	username = _username;
	displayName = _displayName;
	password = _password;
}
string User::getUsername(){
	return username;
}
string User::get_displayName(){
	return displayName;
}
bool User::is_its_username(string _username){
	if (username == _username) return 1;
	return 0;
}
bool User::is_its_password(string _password){
	if (password == _password) return 1;
	return 0;
}
void User::clearAll(){
	username.clear();
	displayName.clear();
	password.clear();
	jeeks.clear();
	followers.clear();
	followings.clear();
	notifications.clear();
}
void User::addJeek(Jeek newJeek){
	jeeks.push_back(newJeek);
}
bool User::is_jeek_here(string _jeekId){
	bool is_here = false;
	for (int i=0;i<jeeks.size();i++){
		if (jeeks[i].getId() == _jeekId){
			is_here = true;
			break;
		}
	}
	return is_here;
}
void User::show_jeek(string _jeekId){
	for (int i=0;i<jeeks.size();i++){
		if (jeeks[i].getId() == _jeekId){
			cout << displayName << endl;
			jeeks[i].showDetails();
			break;
		}
	}
}
vector<string> User::showSearchedDetails(){
	vector<string> J;
	for (int i=0;i<jeeks.size();i++){
		J.push_back(jeeks[i].getDetails());
	}
	return J;
}
vector<string> User::searchTag(string hash_tag){
	bool found = false;
	vector<string> J;
	for (int i=0;i<jeeks.size();i++){
		if (jeeks[i].is_tag_valid(hash_tag)){
			J.push_back(jeeks[i].getDetails());
			found = true;
		}
	}
	cout <<hash_tag<<endl;
	return J;
}
void User::add_comment(string _jeekId , string _commentText , string _commentId , string owner){
	for (int i=0;i<jeeks.size();i++)
		if (jeeks[i].getId() == _jeekId){
			jeeks[i].addNewComment(_commentText , _commentId , owner);
			break;
		}	
}
bool User::isCommentHere(string _commentId){
	bool isHere = false;
	for (int i=0;i<jeeks.size();i++){
		if (jeeks[i].is_comment_here(_commentId)){
			isHere = true;
			break;
		}
	}
	return isHere;
}
Comment* User::get_comment(string _commentId){
	Comment * requestedComment = NULL;
	for (int i=0;i<jeeks.size();i++){
		if (jeeks[i].is_comment_here(_commentId)){
			requestedComment = jeeks[i].get_the_comment(_commentId);
			break;
		}
	}
	return requestedComment;
}
string User::getjeekText(string _jeekId){
	for (int i=0;i<jeeks.size();i++)
		if (jeeks[i].getId() == _jeekId)
			return jeeks[i].getText();
	return "";	
}
void User::rejeeked(string _jeekId){
	for (int i=0;i<jeeks.size();i++)
		if (jeeks[i].getId() == _jeekId){
			jeeks[i].addRejeek();
			break;
		}
}
bool User::like(string _jeekId , string liker){
	for (int i=0;i<jeeks.size();i++)
		if (jeeks[i].getId() == _jeekId){
			jeeks[i].likeJeek(liker);
			return 1;
		}
	return 0;	
}
bool User::dislike(string _jeekId , string disliker){
	for (int i=0;i<jeeks.size();i++)
		if (jeeks[i].getId() == _jeekId){
			if (jeeks[i].dislikeJeek(disliker))
				return 1;
		}
	return 0;	
}
void User::addFollower(string follower){
	followers.push_back(follower);
}
bool User::has_this_follower(string _username){
	bool has_this = false;
	for (int i=0;i<followers.size();i++)
		if (followers[i] == _username){
			has_this = true;
			break;
		}
	return has_this;	
}
void User::addFollowing(string _following){
	followings.push_back(_following);
}
void User::deleteFollower(string _username){
	int id = INVALID;
	for (int i=0;i<followers.size();i++)
		if (followers[i] == _username){
			id = i;
			break;
		}
	if (id != INVALID)
		followers.erase(followers.begin() + id);
}
void User::deleteFollowing(string _username){
	int id = INVALID;
	for (int i=0;i<followings.size();i++)
		if (followings[i] == _username){
			id = i;
			break;
		}
	if (id != INVALID)
		followings.erase(followings.begin() + id);
}
void User::addNewNotification(string newNotification){
	notifications.push_back(newNotification);
}
void User::showNotifications(){
	for (int i=0;i<notifications.size();i++)
		cout << notifications[i] << endl;
	notifications.clear();
}
vector<string> User::getfollowers(){
	return followers;
}