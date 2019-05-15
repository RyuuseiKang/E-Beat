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

class Parser {
public:
	Parser();
	~Parser();


private:
	ofFile noteFile;

	void Parse();
};

#endif // __PARSER_HPP_