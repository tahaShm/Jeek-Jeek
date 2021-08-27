#ifndef __REPLY_H__
#define __REPLY_H__

#include"libraries.hpp"
#include"comment.hpp"
#include "functions.hpp"
#include "exceptions.hpp"
class Jeek;
class Reply{
public:
	Reply(string _replyText , string _replyId , string owner , string _Replied , bool _toCommentOrReply);
	string getId();
	string getText();
	string getOwnerName();
	bool is_reply_to_reply();
	bool is_reply_to_thisComment(string _commentId);
	bool is_reply_to_thisReply(string _replyId);
private:
	string replyId;
	bool toCommentOrReply;
	string text;
	
	string replyOwner;
	string  CReplied;
	string  RReplied;
};

#endif