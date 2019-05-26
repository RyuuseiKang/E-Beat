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

// typedef vector<tuple<int, string, vector<string>>> tapNote;
// typedef vector<tuple<int, string, vector<string>>> slideNote[36];

typedef map<int, vector<tuple<string, string>>> note;

typedef struct note_data {
	// tapNote tapNotes;
	// slideNote slideNotes;

	note notes;
	map<int, float> bpms;
}note_data;

typedef struct meta_data {
	string TITLE;
	string ARTIST;
	string DESIGNER;
	int DIFFICULTY;
	string PLAYLEVEL;
	string SONGID;
	string WAVE;
	float WAVEOFFSET;
	string JACKET;
	int MEASUREBS;
	int HISPEED;
	int MEASUREHS;

}meta_data;

class Parser {
public:
	Parser();
	~Parser();
	
private:
	ofFile noteFile;

	note_data noteData;
	meta_data metaData;

	vector<string> ParseNoteToVectorString(string str);
	void Parse();

	void ParseMetaData(string _str);
	void ParseData(string _str);

};

#endif // __PARSER_HPP_


/* 

// 메타 데이터 부

#MEASUREBS 소절 오프셋



// 데이터 부

#AAABB:CCDDEEFF
AAA: Bar
BB: Channel
CCDDEEFF: Data

#aaa1b  노트
		

#aaa2bc 롱노트
		

#aaa3bc 슬라이드 노트
		

#aaa4bc 에어 액션
		
		
#aaa5b  에어 노트
		


*/