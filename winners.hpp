#ifndef WINNERS_HPP
#define WINNERS_HPP

#include <vector>
using namespace std;

vector<float> top3(vector<float> scores){
	float eerste = 0;
	float tweede = 0;
	float derde = 0;
	vector<float> topdrie;
	for(unsigned int i = 0; i < scores.size(); i++){
		if(scores[i] > eerste){
			derde = tweede;
			tweede = eerste;
			eerste = scores[i];
		}
		else if(scores[i] > tweede){
			derde = tweede;
			tweede = scores[i];
		}
		else if(scores[i] > derde){
			derde = scores[i];
		}
	}
	topdrie.push_back(eerste);
	topdrie.push_back(tweede);
	topdrie.push_back(derde);
	return topdrie;
}



float second2last(vector<float> scores){
	float resultaat;
	float laatste = scores[0];
	for(unsigned int j = 0; j < scores.size(); j++){
		if(scores[j] < laatste){
			resultaat = laatste;
			laatste = scores[j];
		}
	}
	return resultaat;
}

#endif /* WINNERS_HPP */