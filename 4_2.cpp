#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <time.h>
#include <fstream>
#include "winners.hpp"
using namespace std;


int main(){
	vector<float> results = {5.322, 8.76, 2.12, 745.981, 23.6, 87.3};
	
	vector<float> top = top3(results);
	float mole = second2last(results);
	
	
	cout << "De top 3 is: " << top[0] << ", " << top[1] << ", " << top[2] << "\n";
	cout << "De mol is : " << mole << "\n";
}