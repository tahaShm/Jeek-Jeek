#include "comment.hpp"
#include "user.hpp"
Comment::Comment(string _commentText , string _commentId , string owner){
	text = _commentText;
	commentId = _commentId;
	commentOwner = owner;
}
string Comment::getId(){
	return commentId;
}
string Comment::getText(){
	return text;
}
