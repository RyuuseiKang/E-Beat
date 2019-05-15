//
//  Parser.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/05/2019.
//

#include "Parser.hpp"

Parser::Parser() {
	noteFile.open(ofToDataPath("sus.sus"));
	ofBuffer buff = noteFile.readToBuffer();

	cout << buff.getText();
}

Parser::~Parser() {

}

void Parser::Parse() {

}
