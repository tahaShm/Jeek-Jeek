#include "jeekjeek.hpp"
JeekJeek::JeekJeek(){
	is_user_in = false;
	numOfJeeks = 0;
	numOfComments = 0;
	numOfReplies = 0;
}	
bool JeekJeek::signUp(string _username , string _displayName , string _password){
	bool was_successful = false;
	vector<string> usersInName;
	if (is_user_in)
		for (int i=0;i<usersIn.size();i++)
			usersInName.push_back(usersIn[i]->getUsername());
	if (isUsernameUnique(_username)){
		users.push_back(User(_username , _displayName , _password));
		was_successful = true;
	}
	if (is_user_in){
		usersIn.clear();
		for (int i=0;i<usersInName.size();i++){
			int id = findUser(usersInName[i]);
			if (id != INVALID){
				usersIn.push_back(&users[id]);
			}
		}
	}
	return was_successful;
}
bool JeekJeek::isUsernameUnique(string _username){
	bool is_unique = true;
	for (int i=0;i<users.size();i++)
		if (users[i].getUsername() == _username){
			is_unique = false;
			break;
		}
	return is_unique;	
}
string JeekJeek::logIn(string _username , string _password){
	int userId;
	userId = findUser(_username);
	if (userId != INVALID){
		if (users[userId].is_its_password(_password)){
			usersIn.push_back(&users[userId]);
			is_user_in = true;
			return users[userId].get_displayName();
		}
	}
	return "";
}
int JeekJeek::findUser(string _username){
	int id = INVALID;
	for (int i=0;i<users.size();i++){
		if (users[i].is_its_username(_username)){
			id = i;
			break;
		}
	}
	return id;
}
void JeekJeek::logOut(string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID) usersIn.erase(usersIn.begin() + id);
		if(usersIn.size() == 0)	is_user_in = false;
	}
}
void JeekJeek::addNewJeek(Jeek newJeek , string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID){
			User* userIn = getLoggedInUser(id);
			numOfJeeks ++;
			newJeek.setId("jeekId" + int_to_string(numOfJeeks));
			userIn->addJeek(newJeek);
			vector <string> userInFollowers = userIn->getfollowers();
			for (int i=0;i<userInFollowers.size();i++){
				string newNotification = userIn->getUsername() + " jeeked " + newJeek.getId();
				addNotification(newNotification , userInFollowers[i]);
			}
			notifyMentionedUsers(newJeek , user_in);
		}
	}
}
void JeekJeek::notifyMentionedUsers(Jeek newJeek , string user_in){
	vector <string> _mentionedUsers = newJeek.get_mentionedUsers();
	for (int i=0;i<_mentionedUsers.size();i++){
		string newNotification = user_in + " mentioned you in " + newJeek.getId();
		addNotification(newNotification , _mentionedUsers[i]); 
	}
}
void JeekJeek::showJeek(string _jeekId){
	int userId = findUserOnJeekId(_jeekId);
	if (userId != INVALID)
		users[userId].show_jeek(_jeekId);
}
int JeekJeek::findUserOnJeekId(string _jeekId){
	int id = INVALID;
	for (int i=0;i<users.size();i++){
		if (users[i].is_jeek_here(_jeekId)){
			id = i;
			break;
		}
	}
	return id;
}
vector<string> JeekJeek::searchUser(string _username){
	bool found = false;
	vector<string> jeeksFound;
	for (int i=0;i<users.size();i++){
		if (users[i].getUsername() == _username){
			jeeksFound = users[i].showSearchedDetails();
			found = true;
			break;
		}
	}
	return jeeksFound;
}
vector<string> JeekJeek::searchHashTag(string hash_tag){
	vector<string> jeeksFound;
	for (int i=0;i<users.size();i++){
		vector<string> newJeeks = users[i].searchTag(hash_tag);
		for (int j=0;j<newJeeks.size();j++)
			jeeksFound.push_back(newJeeks[j]);
	}
	return jeeksFound;
}
void JeekJeek::addComment(string _jeekId , string _commentText , string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID){
			User* userIn = getLoggedInUser(id);
			int userId = findUserOnJeekId(_jeekId);
			if (userId != INVALID){
				numOfComments ++;
				users[userId].add_comment(_jeekId , _commentText , "commentId"+int_to_string(numOfComments) , userIn->getUsername());
				string newNotification = userIn->getUsername() + " commented on " +_jeekId;
				addNotification(newNotification , users[userId].getUsername());
			}
		}	
	}
}
void JeekJeek::addReplyToComment(string _commentId , string _replyText , string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID){
			User* userIn = getLoggedInUser(id);
			Comment* requestedComment = getComment(_commentId);
			if (requestedComment != NULL){
				numOfReplies ++;
				replies.push_back(Reply(_replyText , "replyId" + int_to_string(numOfReplies) , userIn->getUsername() , requestedComment->getId() , 0));
				int id = findUserOnCommentId(_commentId);
				string newNotification =  userIn->getUsername() + " replied " + _commentId;
				addNotification(newNotification , users[id].getUsername());
			}
		}
	}
}
Comment* JeekJeek::getComment(string _commentId){
	int userId = findUserOnCommentId(_commentId);
	Comment* requestedComment = NULL;
	if (userId != INVALID)
		requestedComment = users[userId].get_comment(_commentId);
	return requestedComment;
}
int JeekJeek::findUserOnCommentId(string _commentId){
	int id = INVALID;
	for (int i=0;i<users.size();i++)
		if (users[i].isCommentHere(_commentId)){
			id = i;
			break;
		}
	return id;	
}
void JeekJeek::addReplyToReply(string _replyId , string _replyText , string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID){
			User* userIn = getLoggedInUser(id);
			int repliedId = findReply(_replyId);
			if (repliedId != INVALID){
				numOfReplies++;
				replies.push_back(Reply(_replyText , "replyId" + int_to_string(numOfReplies) , userIn->getUsername() , replies[repliedId].getId() , 1));
				int id = findUserOnReplyId(_replyId);
				string newNotification = userIn->getUsername() + " replied " + _replyId;
				addNotification(newNotification , users[id].getUsername());
			}
		}
	}
}
int JeekJeek::findReply(string _replyId){
	int id = INVALID;
	for (int i=0;i<replies.size();i++)
		if (replies[i].getId() == _replyId){
			id = i;
			break;
		}
	return id;	
}
int JeekJeek::findUserOnReplyId(string _replyId){
	int id = INVALID;
	for (int i=0;i<replies.size();i++)
		if (replies[i].getOwnerName() == _replyId){
			id = i;
			break;
		}
	return id;
}
void JeekJeek::reJeek(string _jeekId , string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID){
			User* userIn = getLoggedInUser(id);
			int userId = findUserOnJeekId(_jeekId);
			if (userId != INVALID){
				string _jeekText = "ReJeeked:" + users[userId].getjeekText(_jeekId);
				users[userId].rejeeked(_jeekId);
				Jeek newRejeek(_jeekText);
				addNewJeek(newRejeek , user_in);
				string newNotification = userIn->getUsername() + " rejeeked " + _jeekId;
				addNotification(newNotification , users[userId].getUsername());
			}
		}
	}
}
void JeekJeek::showComment(string _commentId){
	int userId = findUserOnCommentId(_commentId);
	Comment* requestedComment = NULL;
	if (userId != INVALID){
		requestedComment = users[userId].get_comment(_commentId);
		if (requestedComment != NULL){
			cout << users[userId].get_displayName() << endl;
			cout << requestedComment->getText() << endl;
			cout << "Replies:" << endl;
			for (int i=0;i<replies.size();i++){
				if (replies[i].is_reply_to_reply() == 0 && replies[i].is_reply_to_thisComment(_commentId))
					cout <<replies[i].getId()<<endl;
			}
		}

	}
	else Invalid_CommentId();
}
void JeekJeek::showReply(string _replyId){
	int reply_id = findReply(_replyId);
	if (reply_id != INVALID){
		string ownerName = replies[reply_id].getOwnerName();
		int userId = findUser(ownerName);
		User* owner = &users[userId];
		if (owner != NULL){
			cout << owner->get_displayName() << endl;
			cout <<replies[reply_id].getText() << endl;
			cout << "Replies:" << endl;
			for (int i=0;i<replies.size();i++){
				if (replies[i].is_reply_to_reply() == 1 && replies[i].is_reply_to_thisReply(_replyId))
					cout << replies[i].getId()<<endl;
			}
		}
	}
}
void JeekJeek::like(string _jeekId , string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID){
			User* userIn = getLoggedInUser(id);
			bool is_like_successful = false;
			int id = findUserOnJeekId(_jeekId);
			if (id != INVALID){
				is_like_successful = users[id].like(_jeekId , userIn->getUsername());
				if (is_like_successful){
					string newNotification = userIn->getUsername() + " liked " + _jeekId;
					addNotification(newNotification , users[id].getUsername());
				}
			}
		}
	}
}
void JeekJeek::dislike(string _jeekId , string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID){
			User* userIn = getLoggedInUser(id);
			bool is_dislike_successful = false;
			int id = findUserOnJeekId(_jeekId);
			if (id != INVALID){
				is_dislike_successful = users[id].dislike(_jeekId , userIn->getUsername());
				if (is_dislike_successful){
					string newNotification = userIn->getUsername() + " disliked " + _jeekId;
					addNotification(newNotification , users[id].getUsername());
				}
			}
		}
	}
}
void JeekJeek::follow(string _username , string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID){
			User* userIn = getLoggedInUser(id);
			User * followed = getUserOnName(_username);
			if (followed != NULL){
				if (followed->has_this_follower(userIn->getUsername()) == 0){
					followed->addFollower(userIn->getUsername());
					userIn->addFollowing(followed->getUsername());
				}
			}
		}
	}
}
User* JeekJeek::getUserOnName(string _username){
	for (int i=0 ; i<users.size() ; i++){
		if (users[i].getUsername() == _username){
			return &users[i];
			break;
		} 
	}
	return NULL;
}
void JeekJeek::unfollow(string _username , string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID){
			User* userIn = getLoggedInUser(id);
			User* followed = getUserOnName(_username);
			if (followed != NULL){
				string name = userIn->getUsername();
				if (followed->has_this_follower(name)){
					followed->deleteFollower(name);
					userIn->deleteFollowing(followed->getUsername());
				}
			}
		}
	}
}
void JeekJeek::addNotification(string newNotification , string _username){
	int userId = findUser(_username);
	if (userId != INVALID)
		users[userId].addNewNotification(newNotification);
}
void JeekJeek::showNotifications(string user_in){
	if (is_user_in){
		int id = findLoggedInUser(user_in);
		if (id != INVALID){
			User* userIn = getLoggedInUser(id);
			userIn->showNotifications();
		}
	}
}

vector<string> JeekJeek::search(string searched){
	char firstC = searched[0];
	searched.erase(searched.begin());
	vector<string> jeeksFound;
	if (firstC == '@') jeeksFound = searchUser(searched);
	else if (firstC == '#') jeeksFound = searchHashTag(searched);
	return jeeksFound;
}


int JeekJeek::findLoggedInUser(string _username){
	for (int i=0;i<usersIn.size();i++){
		if (usersIn[i]->getUsername() == _username) return i;
	}
	return INVALID;
}
User* JeekJeek::getLoggedInUser(int id){
	return usersIn[id];
}
string JeekJeek::getDisplayname(string _username){
	int id = findUser(_username);
	if (id != INVALID)
		return users[id].get_displayName();
	else return "";
}

string JeekJeek::getJeekId(string jeekDetail){
	string _jeekId;
	for (int i=0;i<users.size();i++){
		_jeekId = users[i].checkJeekDetails(jeekDetail);
		if (!(_jeekId.empty())) return _jeekId;
	}
	return "";
}

string JeekJeek::getJeekDetails(string _jeekId){
	int id = findUserOnJeekId(_jeekId);
	string details;
	if (id != INVALID){
		details = users[id].get_jeek_datails(_jeekId);
		return details;
	}
	return "";
}

string JeekJeek::getUsernameOnJeekId(string _jeekId){
	int id = findUserOnJeekId(_jeekId);
	if (id != INVALID)
		return users[id].getUsername();
	else return "";	 
}

Jeek* JeekJeek::getJeek (string _jeekId){
	int id = findUserOnJeekId(_jeekId);
	if (id != INVALID)
		return users[id].get_jeek(_jeekId);
	else return NULL;
}
int JeekJeek::likes(string _jeekId){
	int id = findUserOnJeekId(_jeekId);
	if (id != INVALID) return users[id].getJeekLikes(_jeekId);
	return 0;
}
int JeekJeek::reJeeks(string _jeekId){
	int id = findUserOnJeekId(_jeekId);
	if (id != INVALID) return users[id].getJeekRejeeks(_jeekId);
	return 0;
}
bool JeekJeek::isNewLiker(string _jeekId , string _username){
	int id = findUserOnJeekId(_jeekId);
	if (id != INVALID)
		return users[id].is_new_liker(_jeekId , _username);
	else return true;
}