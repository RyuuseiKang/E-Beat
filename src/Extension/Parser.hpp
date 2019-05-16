//
//  Parser.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/05/2019.
//

#ifndef __PARSER_HPP_
#define __PARSER_HPP_

#include <iostream>
#include "../ofMain.h"

typedef vector<tuple<int, string, string>> tapNote;
typedef vector<tuple<int, string, string>> slideNote[36];

struct note_data {
	tapNote tapNotes;
	slideNote slideNotes;
	vector<float> bpms;
};

class Parser {
public:
	Parser();
	~Parser();


private:
	ofFile noteFile;

	
	note_data data;
	

	void Parse();
};

#endif // __PARSER_HPP_


/* 

#aaa1b  노트
		

#aaa2bc 롱노트
		

#aaa3bc 슬라이드 노트
		

#aaa4bc 에어 액션
		
		
#aaa5b  에어 노트
		


*/