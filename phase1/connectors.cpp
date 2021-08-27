#include "connectors.hpp"
void processProgram(JeekJeek & jeekJeeker){
	string line;
	bool isJeekInLine = false;
	Jeek newJeek;
	while (getline(cin , line)){
		try{
			if (line.size() != 0)
				processLine(line , isJeekInLine , jeekJeeker , newJeek);
		}
		catch (Invalid_Operand ex){
		cerr << "Ex : Invaid operand" << endl;
	}
	catch (Incorrect_Inputs ex){
		cerr << "Ex : Incorrect inputs" << endl;
	}
	catch (Repetitive_User ex){
		cerr << "Ex : Repetitive username" << endl;
	}
	catch (Invalid_User){
		cerr << "Ex : Invalid user" << endl;
	}
	catch (Incorrect_Password){
		cerr << "Ex : Incorrect password" << endl;
	}
	catch (User_Is_In){
		cerr << "Ex : Previously a user logged in" << endl;
	}
	catch (User_Is_Not_In){
		cerr << "Ex : No user logged in" << endl;
	}
	catch (Invalid_JeekId){
		cerr << "Ex : Invalid jeekId" << endl;
	}
	catch (Invalid_Tag){
		cerr << "Ex : Invalid tag" << endl;
	}
	catch (Invalid_CommentId){
		cerr << "Ex : Invalid commentId" << endl;
	}
	catch (Invalid_ReplyId){
		cerr << "Ex : Invalid replyId" << endl;
	}
	catch (Second_Like){
		cerr << "Ex : Second like" << endl;
	}
	catch (Incorrect_Dislike){
		cerr << "Ex : Dislike without like" << endl;
	}
	catch (Repetitive_Follower){
		cerr << "Ex : Repetitive follower" << endl;
	}
	catch (Incorrect_Unfollow){
		cerr << "Ex : Pointless unfollow" << endl;
	}
	catch (Too_Many_Characters){
		cerr << "Ex : exceeding maximum size : " << MAX_JEEK_SIZE << endl;
	}
	}
}
void processLine(string line , bool & isJeekInLine , JeekJeek & jeekJeeker , Jeek & newJeek){
	string operand = getFirstWord(line);
	if (!(isJeekInLine)){
		if (operand == SIGNUP)	doSignUp(line , jeekJeeker);
		else if (operand == LOGIN) doLogIN(line , jeekJeeker);
		else if (operand == LOGOUT) doLogOUT(line , jeekJeeker);
		else if (operand == JEEK) isJeekInLine = true;
		else if (operand == SEARCH) doSearch(line , jeekJeeker);
		else if (operand == COMMENT) doComment(line , jeekJeeker);
		else if (operand == REPLY) doReply(line , jeekJeeker);
		else if (operand == REJEEK) doReJeek(line , jeekJeeker);
		else if (operand == SHOWJEEK) doShowJeek(line , jeekJeeker);
		else if (operand == SHOWCOMMENT) doShowComment(line , jeekJeeker);
		else if (operand == SHOWREPLY) doShowReply(line , jeekJeeker);
		else if (operand == LIKE) doLike(line , jeekJeeker);
		else if (operand == DISLIKE) doDislike(line , jeekJeeker);
		else if (operand == FOLLOW) doFollow(line , jeekJeeker);
		else if (operand == UNFOLLOW) doUnfollow(line , jeekJeeker);
		else if (operand == NOTIFICATIONS) doNotification(line , jeekJeeker);
		else throw Invalid_Operand();
	}
	else {
		if (operand == TEXT) addText(line , jeekJeeker , newJeek);
		else if (operand == TAG) addTag(line , jeekJeeker , newJeek);
		else if (operand == MENTION) addMention(line , jeekJeeker , newJeek);
		else if (operand == PUBLISH){
			doPublish(line , jeekJeeker , newJeek);
			isJeekInLine = false;
		}
		else if (operand == ABORT){
			doAbort(line , jeekJeeker , newJeek);
			isJeekInLine = false;
		}
		else throw Invalid_Operand();
	}
}
string getFirstWord(string line){
	int counter = 0;
	string firstWord;
	while (counter < line.size()){
		if (!(is_space(line[counter])))
			firstWord += line[counter];
		else break;
		counter++;
	}
	return firstWord;
	
}
bool is_space(char c){
	if (c == ' ' || c == '\t')	return 1;
	else return 0;
}
void doSignUp(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	string _username , _displayName , _password;
	if (numOfSpaces == 3){
		vector <string> words = getSeparatedWords(line);
		_username = words[1];
		_displayName = words[2];
		_password = words[3];
		jeekJeeker.signUp(_username , _displayName , _password); 
	}
	else throw Incorrect_Inputs();
}
void doLogIN(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	string _username , _password;
	if (numOfSpaces == 2){
		vector <string> words = getSeparatedWords(line);
		_username = words[1];
		_password = words[2];
		jeekJeeker.logIn(_username , _password);
	}
	else throw Incorrect_Inputs();
}
void doLogOUT(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 0)
		jeekJeeker.logOut();
	else throw Incorrect_Inputs();
}
void doSearch(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	string _username , hash_tag;
	if (numOfSpaces == 1){
		vector <string> words = getSeparatedWords(line);
		if (words[1][0] == '@'){
			_username = words[1];
			_username.erase(_username.begin() + 0);
			jeekJeeker.searchUser(_username);
		}
		else if (words[1][0] == '#'){
			hash_tag = words[1];
			hash_tag.erase(hash_tag.begin() + 0);
			jeekJeeker.searchHashTag(hash_tag);
		}
		else throw Incorrect_Inputs();
	}
	else throw Incorrect_Inputs();
}
void doComment(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	string _jeekId , _commentText;
	if (numOfSpaces >= 2){
		vector <string> words = getSeparatedWords(line);
		_jeekId = words[1];
		for (int i=2;i<=numOfSpaces;i++)
			_commentText += words[i];
		jeekJeeker.addComment(_jeekId , _commentText);
	}
	else throw Incorrect_Inputs();
}
void doReply(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces >= 2){
		string replyText , commentId , replyId;
		vector <string> words = getSeparatedWords(line);
		for (int i=2;i<=numOfSpaces;i++)
			replyText += words[i];
		if (words[1][0] == 'c'){
			commentId = words[1];
			jeekJeeker.addReplyToComment(commentId , replyText);
		}
		else if (words[1][0] == 'r'){
			replyId = words[1];
			jeekJeeker.addReplyToReply(replyId , replyText);
		}
		else throw Incorrect_Inputs();
	}
	else throw Incorrect_Inputs();
}
void doReJeek(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 1){
		vector <string> words = getSeparatedWords(line);
		string _jeekId = words[1];
		jeekJeeker.reJeek(_jeekId);
	}
	else throw Incorrect_Inputs();
}
void doShowJeek(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 1){
		vector <string> words = getSeparatedWords(line);
		string _jeekId = words[1];
		jeekJeeker.showJeek(_jeekId);
	}
	else throw Incorrect_Inputs();

}
void doShowComment(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 1){
		vector <string> words = getSeparatedWords(line);
		string _commentId = words[1];
		jeekJeeker.showComment(_commentId);
	}
	else throw Incorrect_Inputs();
}
void doShowReply(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 1){
		vector <string> words = getSeparatedWords(line);
		string _replyId = words[1];
		jeekJeeker.showReply(_replyId);
	}
	else throw Incorrect_Inputs();
}
void doLike(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 1){
		vector <string> words = getSeparatedWords(line);
		string _jeekId = words[1];
		jeekJeeker.like(_jeekId);
	}
	else throw Incorrect_Inputs();
}
void doDislike(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 1){
		vector <string> words = getSeparatedWords(line);
		string _jeekId = words[1];
		jeekJeeker.dislike(_jeekId);
	}
	else throw Incorrect_Inputs();
}
void doFollow(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 1){
		vector <string> words = getSeparatedWords(line);
		string _username = words[1];
		jeekJeeker.follow(_username);
	}
	else throw Incorrect_Inputs();
}
void doUnfollow(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 1){
		vector <string> words = getSeparatedWords(line);
		string _username = words[1];
		jeekJeeker.unfollow(_username);
	}
	else throw Incorrect_Inputs();
}
void doNotification(string line , JeekJeek & jeekJeeker){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 0)
		jeekJeeker.showNotifications();
	else throw Incorrect_Inputs();
}
void addText(string line , JeekJeek & jeekJeeker , Jeek & newJeek){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces >= 1){
		string _text;
		vector <string> words = getSeparatedWords(line);
		for (int i=1;i<=numOfSpaces;i++)
			_text += words[i];
		newJeek.setText(_text);
	}
	else throw Incorrect_Inputs();
}
void addTag(string line , JeekJeek & jeekJeeker , Jeek & newJeek){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 1){
		string _tag;
		vector <string> words = getSeparatedWords(line);
		_tag = words[1];
		newJeek.addTag(_tag);
	}
	else throw Incorrect_Inputs();
}
void addMention(string line , JeekJeek & jeekJeeker , Jeek & newJeek){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 1){
		string _mentioned;
		vector <string> words = getSeparatedWords(line);
		_mentioned = words[1];
		newJeek.addMentioned(_mentioned);
	}
	else throw Incorrect_Inputs();
}
void doPublish(string line , JeekJeek & jeekJeeker , Jeek & newJeek){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 0){
		jeekJeeker.addNewJeek(newJeek);
		newJeek.clearJeek();
	}
	else throw Incorrect_Inputs();

}
void doAbort(string line , JeekJeek & jeekJeeker , Jeek & newJeek){
	int numOfSpaces = getSpaces(line);
	if (numOfSpaces == 0)
		newJeek.clearJeek();
	else throw Incorrect_Inputs();
}
vector<string> getSeparatedWords(string line){
	int numOfSpaces = getSpaces(line);
	vector <string> separatedWords(numOfSpaces + 1);
	int spaceCounter = 0;
	for (int i=0;i<line.size();i++){
		if (i<line.size()-1 && is_space(line[i]) && is_space(line[i+1]) == 0) spaceCounter++;
		else if (is_space(line[i]) == 0)
			separatedWords[spaceCounter] += line[i];
	} 
	return separatedWords;
}
int getSpaces(string line){
	int spaces = 0;
	for (int i=0;i<line.size();i++){
		if (i<line.size()-1 && is_space(line[i]) && is_space(line[i+1]) == 0)	spaces++;
	}
	return spaces;
}	