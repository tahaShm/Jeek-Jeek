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