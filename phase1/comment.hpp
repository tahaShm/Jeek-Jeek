#ifndef __COMMENT_H__
#define __COMMENT_H__

#include "libraries.hpp"
#include "functions.hpp"
#include "exceptions.hpp"
class User;
class Comment{
public:
	Comment(string _commentText , string _commentId , string owner);
	string getId();
	string getText();
private:
	string commentId;
	string text;
	string commentOwner;
};

#endif