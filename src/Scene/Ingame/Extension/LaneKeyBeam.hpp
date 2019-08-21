//
//  LaneKeyBeam.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 17/08/2019.
//

#ifndef __LANE_KEY_BEAM_HPP_
#define __LANE_KEY_BEAM_HPP_

#include "../ofMain.h"

class LaneKeyBeam {
public:
	LaneKeyBeam();
	~LaneKeyBeam();

	void SetKey(short _key);
	void draw();

private:
	const double width = 14.25;
	const double y = 677;

	void SetAnimation(short _keyNum);

	bool keyPressed[16];
	char keyAnimation[16];

	ofMesh mesh[16];
};

#endif // __LANE_KEY_BEAM_HPP_
