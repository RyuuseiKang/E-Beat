//
//  Parser.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/05/2019.
//

#include "Parser.hpp"

template <typename Out>
void Parser::split(const string &s, char delim, Out result) {
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		*(result++) = item;
}

vector<string> Parser::split(const string &s, const char delim) {
	vector<string> elems;
	split(s, delim, back_inserter(elems));

	return elems;
}

std::string Parser::ReplaceAll(std::string &str, const std::string &from, const std::string &to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}

Parser::Parser() {

}

Parser::Parser(string filePath) {
	noteFile.open(ofToDataPath(filePath));

	Parse();
}

Parser::~Parser() {
}

vector<string> Parser::ParseNoteToVectorString(string str) {
	vector<string> parseData;

	for (int i = 0; i < str.length() / 2; i++) {
		parseData.push_back(str.substr(i * 2, 2));
	}

	return parseData;
}

note_data Parser::getNoteData() {
	return noteData;
}
meta_data Parser::getMetaData() {
	return metaData;
}

int Parser::getMaxBar() {
	return maxBar;
}

void Parser::Parse() {
	ofBuffer buff = noteFile.readToBuffer();

	for (const std::string &line : buff.getLines())	{
		if (line.substr(0, 1).c_str()[0] == '#') {
			try {
				if (line.find(":") != string::npos)
					ParseData(line);
				else
					ParseMetaData(line);
			}
			catch (int expn) {
			}
		}
	}

	noteData;
	metaData;

}

bool isExist(string _str) {
	return 0;
}

void Parser::ParseMetaData(string _str) {
	vector<string> v = split(_str, ' ');

	string command = v.at(0);

	command = command.substr(1, command.length() - 1);

	string val;
	try	{
		val = v.at(1);
	} catch (int expn) {
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

	else if (command == "REQUEST") {
		metaData.REQUEST.insert(pair<string, string>(v.at(1), v.at(2)));
	}
		
}

void Parser::ParseData(string _str) {
	vector<string> v = split(_str, ':');

	string remarks = v.at(0);

	if (remarks.substr(0, 1) != "#")
		return;

	remarks = remarks.substr(1, remarks.length() - 1);

	string val = ReplaceAll(v.at(1), " ", "");
	val = ReplaceAll(val, "\"", "");

	if (remarks.substr(0, 3) == "BPM")
		noteData.bpms[atoi(remarks.substr(3, 2).c_str())] = stof(val);

	else if (remarks.substr(0, 3) == "TIL") {
		string _value = ReplaceAll(split(_str, '"')[1]," ", "");
		vector<string> value = split(_value, ',');
		for (int i = 0; i < split(_value, ',').size(); i++) {
			if (value[i] == "") continue;
			int first = stoi(split(value[i], '\'')[0]);
			int second = stoi(split(split(value[i], '\'')[1], ':')[0]);
			int third = stof(split(value[i], ':')[1]);
			noteData.speeds[first][second] = third;
		}
		
	}
		

	else {
		int nowBar = atoi(remarks.substr(0, 3).c_str());
		(maxBar < nowBar) ? maxBar = nowBar : NULL;
		noteData.notes[nowBar][remarks.substr(3, 3)] = v.at(1);
	}
}
