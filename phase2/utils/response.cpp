#include "response.hpp"
#include <cstring>
#include <iostream>

using namespace std;

Response::Response() {
  code = 200;
  phrase = "Ok";
  headers["Content-Type"] = "text/plain";
}

int Response::getStatusCode() { return code; }

string Response::getStatusPhrase() { return phrase; }

void Response::setStatus(int _code, string _phrase) {
  phrase = _phrase;
  code = _code;
}

char *Response::print(int &size) {
  char *header_buffer = new char[BUFSIZE];
  string h = "";
  h += "HTTP/1.0 " + to_string(code) + " " + phrase + "\r\n";
  h += "Server: " + SERVER_NAME + " \r\n";
  h += "Content-Length: " + to_string(body.size()) + "\r\n";
  for (auto it = headers.begin(); it != headers.end(); it++)
    h += it->first + ": " + it->second + "\r\n";
  h += "\r\n";
  strcpy(header_buffer, h.c_str());
  int i;
  int hbsize = strlen(header_buffer);
  for (i = 0; i < body.size(); i++) {
    header_buffer[hbsize + i] = body[i];
  }
  size = i + hbsize;
  return header_buffer;
}

void Response::log() {
  const string NC = "\033[0;39m";
  const string K = "\033[1m";
  const string H = "\033[34;1m";
  const string G = "\033[32m";
  const string R = "\033[31m";
  string log = "";
  log += H + string("------- Response -------") + NC + string("\n");
  log += K + string("Status:\t") + NC + (code == 200 ? G : R) +
         to_string(code) + " " + phrase + NC + string("\n");
  log += K + string("Headers:") + NC + string("\n");
  for (auto it = headers.begin(); it != headers.end(); it++)
    log += "  " + urlDecode(it->first) + ": " + urlDecode(it->second) +
           string("\n");
  log += K + string("Body:\n") + NC + body + string("\n");
  log += H + string("------------------------") + NC + string("\n");
  cerr << log << endl;
}

void Response::setHeader(string name, string value) { headers[name] = value; }

void Response::setBody(string _body) { body = _body; }

string Response::getHeader(string name) { return ""; }

void Response::setSessionId(string sessionId) {
  setHeader("set-cookie", "sessionId=" + sessionId + ";");
}
