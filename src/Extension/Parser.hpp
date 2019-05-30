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

typedef struct note_data
{
	// tapNote tapNotes;
	// slideNote slideNotes;

	note notes;
	map<int, float> bpms;
	map<int, float> speeds;
} note_data;

typedef struct meta_data
{
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

} meta_data;

class Parser
{
public:
	Parser();
	~Parser();

	note_data getNoteData();
	meta_data getMetaData();

	int getMaxBar();

private:
	ofFile noteFile;

	note_data noteData;
	meta_data metaData;

	vector<string> ParseNoteToVectorString(string str);
	void Parse();

	void ParseMetaData(string _str);
	void ParseData(string _str);

	int maxBar = 0;
};

#endif // __PARSER_HPP_

/* 

// 메타 데이터 부
#TITLE 타이틀
#ARTIST 아티스트명
#DESIGNER 디자이너 이름
#DIFFICULTY 난이도(BASIC, NORMAL, EXPERT, MASTER)
#PLAYLEVEL 레벨
#SONGID 노래 ID
#WAVE 노래 파일
#WAVEOFFSET 노래 오프셋
#JACKET 자켓 이름
#MEASUREBS 소절 오프셋


// 데이터 부
#AAABCD:EEFFGGHH
AAA 마디(BAR)
BCD 채널
	B 타입
		0 속성
		1 탭(Tap)
		2 롱
		3 슬라이드
		4 에어 롱
		5 에어 노트
	C 롱노트 동일 그룹 명시자
	D 실제 노트위치
EEFFGGHH 데이터(VALUE)


#aaa1b  노트
		

#aaa2bc 롱노트
		

#aaa3bc 슬라이드 노트
		

#aaa4bc 에어 액션
		
		
#aaa5b  에어 노트
		


*/
