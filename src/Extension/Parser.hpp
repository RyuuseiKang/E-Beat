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

typedef vector<tuple<int, string, string>> note;

struct note_data {
	note notes;
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