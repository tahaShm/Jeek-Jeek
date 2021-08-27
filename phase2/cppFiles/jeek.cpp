#include"jeek.hpp"
#include"user.hpp"
Jeek::Jeek(){
	reJeeks = 0;
}
Jeek::Jeek(string _jeekText){
	if (_jeekText.size() <= MAX_JEEK_SIZE){
		text = _jeekText;
		reJeeks = 0;
	}
	else throw Too_Many_Characters();
}
vector<string> Jeek::get_mentionedUsers(){
	return mentionedUsers;
}
void Jeek::setId(string id){
	jeekId = id;
}
string Jeek::getId(){
	return jeekId;
}
void Jeek::showDetails(){
	cout << text << endl;
	for (int i=0;i<tags.size();i++)
		cout <<"#"<<tags[i]<<endl;
	for (int i=0;i<mentionedUsers.size();i++){
		cout<<"@"<<mentionedUsers[i]<<endl;
	}
	cout <<"Likes "<<likers.size()<<endl;
	cout <<"Rejeeks "<<reJeeks<<endl;
	cout << "comments :"<<endl;
	for (int i=0;i<comments.size();i++)
		cout <<comments[i].getId()<<endl;
}
string Jeek::getText(){
	return text;
}
bool Jeek::is_tag_valid(string hash_tag){
	bool is_valid = false;
	for (int i=0;i<tags.size();i++){
		if (tags[i] == hash_tag){
			is_valid = true;
			break;
		}
	}
	return is_valid;
}
void Jeek::addNewComment(string _commentText , string _commentId , string owner){
	comments.push_back(Comment(_commentText , _commentId , owner));
}
bool Jeek::is_comment_here(string _commentId){
	for (int i=0;i<comments.size();i++){
		if (comments[i].getId() == _commentId){
			return 1;
		}
	}
	return 0;
}
Comment* Jeek::get_the_comment(string _commentId){
	Comment * requestedComment = NULL;
	for (int i=0;i<comments.size();i++){
		if (comments[i].getId() == _commentId){
			requestedComment = &comments[i];
			break;
		}
	}
	return requestedComment;
}
void Jeek::addRejeek(){
	reJeeks++;
}
void Jeek::likeJeek(string liker){
	if (is_liker_unique(liker))	likers.push_back(liker);

}
bool Jeek::dislikeJeek(string disliker){
	if (!(is_liker_unique(disliker))){
		int dislikerId = findLiker(disliker);
		likers.erase(likers.begin() + dislikerId);
		return 1;
	}
	else return 0;
}
bool Jeek::is_liker_unique(string liker){
	for (int i=0;i<likers.size();i++)
		if (likers[i] == liker) return false;
	return true;
}
int Jeek::findLiker(string disliker){
	int id =INVALID;
	for (int i=0;i<likers.size();i++)
		if (likers[i] == disliker){
			id = i;
			break;
		}
	return id;	
}

void Jeek::clearJeek(){
	jeekId.clear();
	text.clear();
	tags.clear();
	mentionedUsers.clear();
	likers.clear();
	reJeeks = 0;
	comments.clear();
}
void Jeek::setText(string _text){
	if (_text.size() <= MAX_JEEK_SIZE)
		text = _text;
	else throw Too_Many_Characters();
}
void Jeek::addTag(string _tag){
	tags.push_back(_tag);
}
void Jeek::addMentioned(string _mentioned){
	mentionedUsers.push_back(_mentioned);
}
void Jeek::addLiker(string _liker){
	likers.push_back(_liker);
}

string Jeek::getDetails(){
	string s;
	s += text;
	s += "\n";
	for (int i=0;i<tags.size();i++)
		s += ("#" + tags[i]);
	s += "\n";
	for (int i=0;i<mentionedUsers.size();i++)
		s += ("@" + mentionedUsers[i]);
	return s;
}

int Jeek::getRejeeks(){
	return reJeeks;
}
int Jeek::getLikes(){
	return  likers.size();
}