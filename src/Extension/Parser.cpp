//
//  Parser.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/05/2019.
//

#include "Parser.hpp"

template<typename Out>
void split(const string &s, char delim, Out result) {
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		*(result++) = item;
}

vector<string> split(const string &s, const char delim) {
	vector<string> elems;
	split(s, delim, back_inserter(elems));

	return elems;
}

Parser::Parser() {
	noteFile.open(ofToDataPath("sus.sus"));
	
	Parse();
}

Parser::~Parser() {

}

void Parser::Parse() {
	ofBuffer buff = noteFile.readToBuffer();

	for (const std::string& line : buff.getLines()) {
		// 여기서 한줄씩 처리


		try{
			
		// 여기가 데이터부분
		vector<string> v = split(line, ':');

		if (v.size() < 2) throw 0;

		if (v.at(0).substr(1, 3) == "BPM")
			data.bpms.push_back(atoi(v.at(1).c_str()));
		else if (v.at(0).substr(1, 3) == "TIL")
			NULL;
		else
			data.notes.push_back(tuple<int, string, string>(atoi(v.at(0).substr(1, 3).c_str()), v.at(0).substr(4, 3), v.at(1)));

		} catch(int expn){

		}

		std::cout << "LINE: " << line << std::endl;
	}
	
	sort(data.notes.begin(), data.notes.end());

	cout << "NOTES ---------------------------------------" << endl;

	for (int i = 0; i < data.notes.size(); i++) {
		cout << get<0>(data.notes.at(i)) << "," << get<1>(data.notes.at(i)) << ":" << get<2>(data.notes.at(i)) << endl;
	}

	cout << "BPMS ---------------------------------------" << endl;

	for (int i = 0; i < data.bpms.size(); i++) {
		cout << i << "," << data.bpms.at(i) << endl;
	}
}

bool isExist(string _str) {
	return 0;
}