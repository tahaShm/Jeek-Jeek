#include "reply.hpp"
#include "user.hpp"
#include "comment.hpp"
#include "jeek.hpp"
Reply::Reply(string _replyText , string _replyId , string owner , string _Replied , bool _toCommentOrReply){
	RReplied = INVALID;
	CReplied = INVALID;
	text = _replyText;
	replyOwner = owner;
	replyId = _replyId;
	if (_toCommentOrReply == 1)
		RReplied = _Replied;
	else 
		CReplied = _Replied;
	toCommentOrReply = _toCommentOrReply;
}

string Reply::getId(){
	return replyId;
}
string Reply::getText(){
	return text;
}
string Reply::getOwnerName(){
	return replyOwner;
}
bool Reply::is_reply_to_reply(){
	return toCommentOrReply;
}
bool Reply::is_reply_to_thisComment(string _commentId){
	if (toCommentOrReply == 0 && CReplied == _commentId)	return true;
	else return false;
}
bool Reply::is_reply_to_thisReply(string _replyId){
	if (toCommentOrReply == 1 && RReplied == _replyId)	return true;
	else return false;
}