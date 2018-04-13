#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;

void cyclisch(const char & ch, const int & n){
	char result = ch;
	if(n > 0){
		for(unsigned int i = 0; i < n; i++){
			int tmp = 0;
			if(bitset<7>(result)[6] == 1){
				tmp = 1;
			}
			result <<= 1;
			if(tmp == 1){
				result |= (1 << 0);
			}
		}
	}
	else if(n < 0){
		for(int j = n; j < 0; j++){
			int tmp = 0;
			if(bitset<7>(result)[0] == 1){
				tmp = 1;
			}
			result >>= 1;
			if(tmp ==1){
				result |= (1 << 6);
			}
		}
	}
	cout << bitset<7>(result);
}


int main(){
	cyclisch('a', -4);
}