#include "functions.hpp"
string int_to_string(int input){
	if (input == 0 ) return "0";
	else {
		int temp = input;
		int zero = int('0');
		string out_put , out_put2;
		while (temp>0){
			out_put += char(zero + temp%10);
			temp = temp/10;
		}
		for (int i=out_put.size()-1;i>=0;i--)	out_put2 += out_put[i];
		return out_put2; 
	}
}
string changeWord(string body , string w1 , string w2){
	int start = body.find(w1);
	int end = start + w1.size();
	string word1,word2,word3 , changedString;
	for (int i=0;i<start;i++) word1 += body[i];
	for (int i=start;i<end;i++) word2 += body[i];
	for (int i=end;i<body.size();i++) word3 += body[i];
	changedString += word1;
	changedString += w2;
	changedString += word3;
	return changedString;
}