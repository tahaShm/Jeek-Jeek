#include "utils/utilities.hpp"
#include "server/server.hpp"
#include "cppFiles/jeekjeek.hpp"
#include <iostream>
#define BIGNUM 1000000

using namespace std;

extern JeekJeek jeekJeeker;
extern map <string , string> sessionIds; 
void setNewSessionId(Response* res, string _username );
string getFirst(string thisSessionId);
void setPrimaryJeeks();

class ShowPage : public RequestHandler {
  string filePath;
public:
  ShowPage(string _filePath);
  Response *callback(Request *req);
};

class ShowImage : public RequestHandler {
  string filePath;
public:
  ShowImage(string _filePath);
  Response *callback(Request *req);
};

class SignupHandler : public RequestHandler {
public:
  Response *callback(Request *req);
};

class LoginHandler : public RequestHandler {
public:
  Response *callback(Request *req);
};

class LogoutHandler : public RequestHandler {
public:
  Response *callback(Request *req);
};

class SearchHandler : public RequestHandler {
public:
  Response *callback(Request *req);
};

class JeekDetailHandler : public RequestHandler {
  Response *callback(Request *req);
};   

class RejeekHandler : public RequestHandler {
  Response *callback(Request * req);
};

class LikeHandler : public RequestHandler{
  Response *callback(Request * req);
};   