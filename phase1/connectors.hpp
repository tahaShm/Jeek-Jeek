#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "libraries.hpp"
#include "jeekjeek.hpp"
#define SIGNUP "signup"
#define LOGIN "login"
#define LOGOUT "logout"
#define JEEK "jeek"
#define TEXT "text"
#define TAG "tag"
#define MENTION "mention"
#define PUBLISH "publish"
#define ABORT "abort"
#define SEARCH "search"
#define COMMENT "comment"
#define REPLY "reply"
#define REJEEK "rejeek"
#define SHOWJEEK "showJeek"
#define SHOWCOMMENT "showComment"
#define SHOWREPLY "showReply"
#define LIKE "like"
#define DISLIKE "dislike"
#define FOLLOW "follow"
#define UNFOLLOW "unfollow"
#define NOTIFICATIONS "notifications"

void processProgram(JeekJeek & jeekJeeker);
void processLine(string line , bool &isJeekInLine , JeekJeek & jeekJeeker , Jeek & newJeek);

string getFirstWord(string line);
bool is_space(char c);
void doSignUp(string line , JeekJeek & jeekJeeker);
void doLogIN(string line , JeekJeek & jeekJeeker);
void doLogOUT(string line , JeekJeek & jeekJeeker);
void doSearch(string line , JeekJeek & jeekJeeker);
void doComment(string line , JeekJeek & jeekJeeker);
void doReply(string line , JeekJeek & jeekJeeker);
void doReJeek(string line , JeekJeek & jeekJeeker);
void doShowJeek(string line , JeekJeek & jeekJeeker);
void doShowComment(string line , JeekJeek & jeekJeeker);
void doShowReply(string line , JeekJeek & jeekJeeker);
void doLike(string line , JeekJeek & jeekJeeker);
void doDislike(string line , JeekJeek & jeekJeeker);
void doFollow(string line , JeekJeek & jeekJeeker);
void doUnfollow(string line , JeekJeek & jeekJeeker);
void doNotification(string line , JeekJeek & jeekJeeker);
void addText(string line , JeekJeek & jeekJeeker , Jeek & newJeek);
void addTag(string line , JeekJeek & jeekJeeker , Jeek & newJeek);
void addMention(string line , JeekJeek & jeekJeeker , Jeek & newJeek);
void doPublish(string line , JeekJeek & jeekJeeker , Jeek & newJeek);
void doAbort(string line , JeekJeek & jeekJeeker , Jeek & newJeek);
vector<string> getSeparatedWords(string line);

int getSpaces(string line);


#endif