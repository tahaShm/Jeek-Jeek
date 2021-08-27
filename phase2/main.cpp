#include "utils/utilities.hpp"
#include "server/server.hpp"
#include "cppFiles/jeekjeek.hpp"
#include <iostream>
#define BIGNUM 1000000

using namespace std;

JeekJeek jeekJeeker;
map <string , string> sessionIds;
void setNewSessionId(Response* res, string _username );
string getFirst(string thisSessionId);
void setPrimaryJeeks();

class ShowPage : public RequestHandler {
  string filePath;

public:
  ShowPage(string _filePath) { filePath = _filePath; }
  Response *callback(Request *req) {
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string body = readFile(filePath.c_str());
    res->setBody(readFile(filePath.c_str()));
    return res;
  }
};

class ShowImage : public RequestHandler {
  string filePath;
public:
  ShowImage(string _filePath) { filePath = _filePath; }
  Response *callback(Request *req) {
    Response *res = new Response;
    res->setHeader("Content-Type", "image/png");
    string body = readFile(filePath.c_str());
    res->setBody(body);
    return res;
  }
};
class SignupHandler : public RequestHandler {
public:
  Response *callback(Request *req) {
    Response *res = new Response;
    string username = req->getBodyParam("username");
    string displayName = req->getBodyParam("displayname");
    string password = req->getBodyParam("password");
    bool signup_was_successful = jeekJeeker.signUp(username , displayName , password);
    res->setHeader("Content-Type", "text/html");
    string body;
    if (signup_was_successful){
      body = readFile("htmlFiles/login.html" );
      body = changeWord(body , "placeholder=\"Username\"" , "value=\"" + username + "\"");
      body = changeWord(body , "placeholder=\"Password\"" , "value=\"" + password + "\"");
    }
    else
      body = readFile("htmlFiles/signup.html" );
    res->setBody(body);
    return res;
  }
};
class LoginHandler : public RequestHandler {
public:
  Response *callback(Request *req) {
    Response *res = new Response;
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    string displayName = jeekJeeker.logIn(username , password);
    res->setHeader("Content-Type", "text/html");
    string body;
    if (!displayName.empty()){
      body = readFile("htmlFiles/home.html" ); 
      body = changeWord(body , "USERNAME" , username);
      body = changeWord(body , "PASSWORD" , "Private :)");
      body = changeWord(body , "DISPLAYNAME" , displayName);
      setNewSessionId(res , username);
      vector <string> jeeksFound = jeekJeeker.search("@" + username);
      for (int i=jeeksFound.size()-1;i>=0;i--)
      body = changeWord(body , "<!-- -->" ,"<p>" + jeeksFound[i] +"<form class=\"form-signin\" action=\"/jeekDetail\"  method=\"post\"><input type=\"hidden\" name=\"jeekId\" value=\""+jeekJeeker.getJeekId(jeeksFound[i])+"\"><button class=\"btn btn-lg btn-primary\"type=\"submit\">more Details</button></form><p>" + "\n" + "<!-- -->" );
    
      res->setBody(body);
      return res;
    }
    else{
      body = readFile("htmlFiles/login.html");
      res->setBody(body);
      return res;
    }
  }
};

class LogoutHandler : public RequestHandler {
public:
  Response *callback(Request *req) {
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string body = readFile("htmlFiles/mainPage.html" );
    res->setBody(body);
    string thisSessionId = req->getSessionId();
    string username = getFirst(thisSessionId);
    if (!username.empty()){
      jeekJeeker.logOut(username);
      sessionIds.erase(username);
    }
    return res;
  }
};
class SearchHandler : public RequestHandler {
public:
  Response *callback(Request *req) {
    Response *res = new Response;
    string userIn = getFirst(req->getSessionId());
    string displayName;
    if (!userIn.empty()){
      displayName = jeekJeeker.getDisplayname(userIn);
    }
    string searched = req->getBodyParam("search");
    res->setHeader("Content-Type" , "text/html");
    string body = readFile("htmlFiles/home.html");
    body = changeWord(body , "USERNAME" , userIn);
    body = changeWord(body , "PASSWORD" , "Private :)");
    body = changeWord(body , "DISPLAYNAME" , displayName);
    vector <string> jeeksFound = jeekJeeker.search(searched);
    
    for (int i=jeeksFound.size()-1;i>=0;i--)
      body = changeWord(body , "<!-- -->" ,"<p>" + jeeksFound[i] +"<form class=\"form-signin\" action=\"/jeekDetail\"  method=\"post\"><input type=\"hidden\" name=\"jeekId\" value=\""+jeekJeeker.getJeekId(jeeksFound[i])+"\"><button class=\"btn btn-lg btn-primary\"type=\"submit\">more Details</button></form><p>" + "\n" + "<!-- -->" );
    res->setBody(body); 
    return res;
  }
};
class JeekDetailHandler : public RequestHandler {
  Response *callback(Request *req) {
    Response *res = new Response;
    res->setHeader("Content-Type" , "text/html");
    string body = readFile("htmlFiles/jeekDetail.html");

    string userIn = getFirst(req->getSessionId());
    string _jeekId = req->getBodyParam("jeekId");
    bool isNewLiker = jeekJeeker.isNewLiker(_jeekId , userIn);
    string username = jeekJeeker.getUsernameOnJeekId(_jeekId) , jeekDetail = jeekJeeker.getJeekDetails(_jeekId);
    int likes = jeekJeeker.likes(_jeekId) , rejeeks = jeekJeeker.reJeeks(_jeekId);
    body = changeWord(body , "USERNAME" , username);
    body = changeWord(body , "JEEKDETAILS" , jeekDetail);
    body = changeWord(body , "LIKES" , int_to_string(likes));
    body = changeWord(body , "REJEEKS" , int_to_string(rejeeks));
    if (isNewLiker)
      body = changeWord(body , "<input type=\"image\" " , "<input type=\"hidden\" name=\"jeekId\" value=\"" + _jeekId +"\"><input type=\"image\" src=\"/dislike_icon\"" );
    else 
      body = changeWord(body , "<input type=\"image\" " , "<input type=\"hidden\" name=\"jeekId\" value=\"" + _jeekId +"\"><input type=\"image\" src=\"/like_icon\"" );
    body = changeWord(body , "<button class=" , "<input type=\"hidden\" name=\"jeekId\" value=\"" + _jeekId +"\"><button class=");

    res->setBody(body);
    return res;
  }
};
class RejeekHandler : public RequestHandler {
  Response *callback(Request * req) {
    Response *res = new Response;
    res->setHeader("Content-Type" , "text/html");
    string body = readFile("htmlFiles/jeekDetail.html");
    string userIn = getFirst(req->getSessionId());
    string _jeekId = req->getBodyParam("jeekId");
    jeekJeeker.reJeek(_jeekId , userIn);

    bool isNewLiker = jeekJeeker.isNewLiker(_jeekId , userIn);
    string username = jeekJeeker.getUsernameOnJeekId(_jeekId) , jeekDetail = jeekJeeker.getJeekDetails(_jeekId);
    int likes = jeekJeeker.likes(_jeekId) , rejeeks = jeekJeeker.reJeeks(_jeekId);
    body = changeWord(body , "USERNAME" , username);
    body = changeWord(body , "JEEKDETAILS" , jeekDetail);
    body = changeWord(body , "LIKES" , int_to_string(likes));
    body = changeWord(body , "REJEEKS" , int_to_string(rejeeks));
    if (isNewLiker)
      body = changeWord(body , "<input type=\"image\" " , "<input type=\"hidden\" name=\"jeekId\" value=\"" + _jeekId +"\"><input type=\"image\" src=\"/dislike_icon\"" );
    else 
      body = changeWord(body , "<input type=\"image\" " , "<input type=\"hidden\" name=\"jeekId\" value=\"" + _jeekId +"\"><input type=\"image\" src=\"/like_icon\"" );
    body = changeWord(body , "<button class=" , "<input type=\"hidden\" name=\"jeekId\" value=\"" + _jeekId +"\"><button class=");

    res->setBody(body);
    return res;
  }
};
class LikeHandler : public RequestHandler{
  Response *callback(Request * req) {
    Response *res = new Response;
    res->setHeader("Content-Type" , "text/html");
    string body = readFile("htmlFiles/jeekDetail.html");
    string userIn = getFirst(req->getSessionId());
    string _jeekId = req->getBodyParam("jeekId");

    bool isNewLiker = jeekJeeker.isNewLiker(_jeekId , userIn);
    if (isNewLiker) jeekJeeker.like(_jeekId , userIn);
    else jeekJeeker.dislike(_jeekId , userIn);
    isNewLiker = jeekJeeker.isNewLiker(_jeekId , userIn);
    string username = jeekJeeker.getUsernameOnJeekId(_jeekId) , jeekDetail = jeekJeeker.getJeekDetails(_jeekId);
    int likes = jeekJeeker.likes(_jeekId) , rejeeks = jeekJeeker.reJeeks(_jeekId);
    body = changeWord(body , "USERNAME" , username);
    body = changeWord(body , "JEEKDETAILS" , jeekDetail);
    body = changeWord(body , "LIKES" , int_to_string(likes));
    body = changeWord(body , "REJEEKS" , int_to_string(rejeeks));
    if (isNewLiker)
      body = changeWord(body , "<input type=\"image\" " , "<input type=\"hidden\" name=\"jeekId\" value=\"" + _jeekId +"\"><input type=\"image\" src=\"/dislike_icon\"" );
    else 
      body = changeWord(body , "<input type=\"image\" " , "<input type=\"hidden\" name=\"jeekId\" value=\"" + _jeekId +"\"><input type=\"image\" src=\"/like_icon\"" );
    body = changeWord(body , "<button class=" , "<input type=\"hidden\" name=\"jeekId\" value=\"" + _jeekId +"\"><button class=");

    res->setBody(body);
    return res;
  }
};
void setNewSessionId(Response* res, string _username ){
  bool repetitive = false;
  string newSessionId;
  map <string,string>:: iterator ite;
  ite = sessionIds.find(_username);
  if (ite == sessionIds.end()){
    while (true){
      newSessionId = int_to_string(rand() % BIGNUM);
      map <string,string>:: iterator it = sessionIds.begin();
      for(int i=0;i<sessionIds.size();i++,(*it++))
        if (it->second == newSessionId){ 
          repetitive = true;
          break;
        }
      if (repetitive == false){ 
        res->setSessionId(newSessionId);
        sessionIds[_username] = newSessionId;  
        break;
      }
    }
  }
}
string getFirst(string thisSessionId){
  map <string,string>:: iterator it = sessionIds.begin();
  for(int i=0;i<sessionIds.size();i++,(*it++))
    if (it->second == thisSessionId)
      return it->first;
  return "";  
}
void setPrimaryJeeks(){
  jeekJeeker.signUp("taha" , "T.A.H.A" , "taha1378");
  jeekJeeker.signUp("ali" , "ALI" , "alipass");
  jeekJeeker.signUp("baran" , "BARAN" , "baranpass");
  jeekJeeker.signUp("reza" , "REZA" , "rezapass");
  jeekJeeker.logIn("taha" , "taha1378");
  jeekJeeker.logIn("ali" , "alipass");
  jeekJeeker.logIn("baran" , "baranpass");
  jeekJeeker.logIn("reza" , "rezapass");
  Jeek newJeek1 , newJeek2 , newJeek3 , newJeek4 , newJeek5 , newJeek6 , newJeek7 , newJeek8 , newJeek9 , newJeek10;
  newJeek1.setText("first Jeek ever");
  newJeek2.setText("Hello World");
  newJeek3.setText("Goodbye World");
  newJeek4.setText("I met you In California . You told me you loved him in Georgia");
  newJeek5.setText("Your heart's in the ground, frozen over . My heart in the sky, supernova ");
  newJeek6.setText("Let it GO, Let it GO");
  newJeek7.setText("I am one with the wind and sky");
  newJeek8.setText("Let it GO, Let it GO");
  newJeek9.setText("You'll never see me cry");
  newJeek10.setText("salam");
  newJeek1.addTag("start");
  newJeek3.addTag("end");
  newJeek5.addTag("mood");
  newJeek9.addTag("Frozen");
  newJeek2.addMentioned("ali");
  newJeek10.addMentioned("taha");
  jeekJeeker.addNewJeek(newJeek1 , "taha");
  jeekJeeker.addNewJeek(newJeek2 , "taha");
  jeekJeeker.addNewJeek(newJeek3 , "taha");
  jeekJeeker.addNewJeek(newJeek4 , "ali");
  jeekJeeker.addNewJeek(newJeek5 , "ali");
  jeekJeeker.addNewJeek(newJeek6 , "baran");
  jeekJeeker.addNewJeek(newJeek7 , "baran");
  jeekJeeker.addNewJeek(newJeek8 , "baran");
  jeekJeeker.addNewJeek(newJeek9 , "baran");
  jeekJeeker.addNewJeek(newJeek10 , "reza");
  jeekJeeker.logOut("taha");
  jeekJeeker.logOut("ali");
  jeekJeeker.logOut("baran");
  jeekJeeker.logOut("reza");
}
int main(int argc, char **argv) {  
  srand (time(NULL));
  try { 
    Server server(argc > 1 ? atoi(argv[1]) : 5000);
    setPrimaryJeeks();
    server.get("/home_icon", new ShowImage("htmlFiles/home.jpg"));
    server.get("/jeek_icon", new ShowImage("htmlFiles/jeekjeek.jpg"));
    server.get("/like_icon", new ShowImage("htmlFiles/like.png"));
    server.get("/dislike_icon", new ShowImage("htmlFiles/dislike.png"));
    server.get("/", new ShowPage("htmlFiles/mainPage.html"));
    server.get("/home", new ShowPage("htmlFiles/home.html"));
    server.get("/signup_page", new ShowPage("htmlFiles/signup.html"));
    server.get("/login_page", new ShowPage("htmlFiles/login.html"));
    server.post("/login", new LoginHandler());
    server.post("/signup", new SignupHandler());
    server.post("/logout", new LogoutHandler());
    server.post("/search" , new SearchHandler());
    server.post("/jeekDetail"  , new JeekDetailHandler());
    server.post("/rejeek" , new RejeekHandler());
    server.post("/like" , new LikeHandler());
    server.run();  
  }
  catch (Server::Exception e) {
    cerr << e.getMessage() << endl;
  }
}