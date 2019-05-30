//
//  Parser.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/05/2019.
//

#include "Parser.hpp"

template <typename Out>
void split(const string &s, char delim, Out result)
{
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		*(result++) = item;
}

vector<string> split(const string &s, const char delim)
{
	vector<string> elems;
	split(s, delim, back_inserter(elems));

	return elems;
}

std::string ReplaceAll(std::string &str, const std::string &from, const std::string &to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}

Parser::Parser()
{
	noteFile.open(ofToDataPath("sus.sus"));

	Parse();
}

Parser::~Parser()
{
}

vector<string> Parser::ParseNoteToVectorString(string str)
{
	vector<string> parseData;

	for (int i = 0; i < str.length() / 2; i++)
	{
		parseData.push_back(str.substr(i * 2, 2));
	}

	return parseData;
}

note_data Parser::getNoteData()
{
	return noteData;
}
meta_data Parser::getMetaData()
{
	return metaData;
}

int Parser::getMaxBar() {
	return maxBar;
}

void Parser::Parse()
{
	ofBuffer buff = noteFile.readToBuffer();

	for (const std::string &line : buff.getLines())
	{
		if (line.substr(0, 1).c_str()[0] == '#')
		{
			try
			{
				if (line.find(":") != string::npos)
					ParseData(line);
				else
					ParseMetaData(line);
			}
			catch (int expn)
			{
			}
		}
	}

	noteData;
	metaData;

	// ofBuffer buff = noteFile.readToBuffer();
	//
	// for (const std::string& line : buff.getLines()) {
	// 	// 여기서 한줄씩 처리
	//
	//
	// 	if (line.substr(0, 1).c_str()[0] == '#') {
	// 		try {
	// 			// 여기가 데이터부분
	// 			vector<string> v = split(line, ':');
	// 			char _noteType = v.at(0).substr(4, 1).c_str()[0];
	//
	// 			if (v.size() < 2) throw 0;
	//
	// 			if (v.at(0).substr(1, 3) == "BPM")
	// 				data.bpms.push_back(atoi(v.at(1).c_str()));
	//
	// 			else if (v.at(0).substr(1, 3) == "TIL")
	// 				NULL;
	//
	// 			// #aaa1~ 처리
	// 			else if (_noteType == '1') {
	// 				data.tapNotes.push_back(tuple<int, string, vector<string>>(
	// 					atoi(v.at(0).substr(1, 3).c_str()),
	// 					v.at(0).substr(4, 3),
	// 					ParseNoteToVectorString(v.at(1))
	// 					));
	// 			}
	//
	// 			// #aaa5~ 처리
	// 			else if (_noteType == '5') {
	//
	// 			}
	//
	// 			// #aaa3~ 처리
	// 			else if (_noteType == '3') {
	//
	// 				char preventDuplication = v.at(0).substr(6, 1).c_str()[0];
	//
	// 				int _notePos;
	// 				if (preventDuplication >= 'a')
	// 					_notePos = preventDuplication - 87;
	// 				else
	// 					_notePos = preventDuplication - 48;
	//
	// 				data.slideNotes[_notePos].push_back(tuple<int, string, vector<string>>(
	// 					atoi(v.at(0).substr(1, 3).c_str()),
	// 					v.at(0).substr(5, 1),
	// 					ParseNoteToVectorString(v.at(1))
	// 					));
	// 			}
	//
	// 		} catch (int expn) {
	//
	// 		}
	//
	// 		std::cout << "LINE: " << line << std::endl;
	// 	}
	// }
	//
	// sort(data.tapNotes.begin(), data.tapNotes.end());

	/*

	cout << "NOTES ---------------------------------------" << endl;

	for (int i = 0; i < data.tapNotes.size(); i++) {
		for(int j = 0; j < get<2>(data.tapNotes.at(i)).size(); j++)
			cout << get<0>(data.tapNotes.at(i)) << "," << get<1>(data.tapNotes.at(i)) << ":" << get<2>(data.tapNotes.at(i)).at(j) << endl;

		cout << endl;
	}

	cout << "BPMS ----------------------------------------" << endl;

	for (int i = 0; i < data.bpms.size(); i++) {
		cout << i << "," << data.bpms.at(i) << endl;
	}

	cout << "SLIDE NOTES ---------------------------------" << endl;

	for (int i = 0; i < 36; i++){
		for (int j = 0; j < data.slideNotes[i].size(); j++) {
			for (int k = 0; k < get<2>(data.slideNotes[i].at(j)).size(); k++)
				cout << i << "," << j << ": " << get<0>(data.slideNotes[i].at(j)) << "," << get<1>(data.slideNotes[i].at(j)) << "," << get<2>(data.slideNotes[i].at(j)).at(k) << endl;

			cout << endl;
		}
		
	}
	*/
}

bool isExist(string _str)
{
	return 0;
}

void Parser::ParseMetaData(string _str)
{
	vector<string> v = split(_str, ' ');

	string command = v.at(0);

	command = command.substr(1, command.length() - 1);

	string val;
	try
	{
		val = v.at(1);
	}
	catch (int expn)
	{
		val = "";
	}

	val = ReplaceAll(v.at(1), "\"", "");

	if (command == "TITLE")
		metaData.TITLE = val;

	else if (command == "ARTIST")
		metaData.ARTIST = val;

	else if (command == "DESIGNER")
		metaData.DESIGNER = val;

	else if (command == "DIFFICULTY")
		metaData.DIFFICULTY = stoi(val);

	else if (command == "PLAYLEVEL")
		metaData.PLAYLEVEL = val;

	else if (command == "SONGID")
		metaData.SONGID = val;

	else if (command == "WAVE")
		metaData.WAVE = val;

	else if (command == "WAVEOFFSET")
		metaData.WAVEOFFSET = stof(val);

	else if (command == "JACKET")
		metaData.JACKET = val;

	else if (command == "MEASUREBS")
		metaData.MEASUREBS = stoi(val);

	else if (command == "HISPEED")
		metaData.MEASUREBS = stoi(val);

	else if (command == "MEASUREHS")
		metaData.MEASUREBS = stoi(val);
}

void Parser::ParseData(string _str)
{
	vector<string> v = split(_str, ':');

	string remarks = v.at(0);

	if (remarks.substr(0, 1) != "#")
		return;

	remarks = remarks.substr(1, remarks.length() - 1);

	string val = ReplaceAll(v.at(1), " ", "");

	if (remarks.substr(0, 3) == "BPM")
		noteData.bpms[atoi(remarks.substr(3, 2).c_str())] = stof(val);

	else
	{
		int nowBar = atoi(remarks.substr(0, 3).c_str());
		(maxBar < nowBar) ? maxBar = nowBar;
		noteData.notes[nowBar].push_back(tuple<string, string>(
			remarks.substr(3, 3),
			v.at(1)));
	}
}
