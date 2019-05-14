//
//  note.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/05/2019.
//

#ifndef __NOTE_HPP_
#define __NOTE_HPP_

#include <iostream>
#include "../ofMain.h"

class note {
public:
	note();
	~note();

	void addNote(string data);

private:
	int pos;
};

#endif // __NOTE_HPP_