#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void compress() {
    string line;
    ifstream myfile ("/Users/twanhoogveld/Desktop/C++/Week 4/Week 4/old.txt");
    if (myfile.is_open()){
        while ( getline (myfile, line) ){
            for(int i=0; i< line.length(); i++){
                if(line[i] == '\t'){
                    line.erase(i,1);
                }
                else{
                    continue;
                }}
            cout << line << "\n";
        }
        myfile.close();
    }else{
        cout << "Unable to open file";
    }
}

int main(){
    compress();
}
