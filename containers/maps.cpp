/**********************************************************/
//This program counts the frequency of words in the given
//input text file. 
/**********************************************************/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
	ifstream infile; // = "test.txt";
	map<string,int> wordfreq;
	string temp;

	infile.open("test.txt");

	while(infile>>temp) {
		if(wordfreq.find(temp) != wordfreq.end())
			wordfreq[temp]++;
		else
			wordfreq.insert(pair<string,int>(temp,1));
	}

	map<string,int>::iterator itr;
	for(itr = wordfreq.begin(); itr!= wordfreq.end(); itr++)
		cout << itr->first << " " << itr->second << endl;

	return 0;
}
