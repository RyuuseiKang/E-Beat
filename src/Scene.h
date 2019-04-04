#ifndef __SCENE_H_
#define __SCENE_H_

#include <iostream>

#include "Scene/EntryScene.h"
#include "Scene/MusicSelect/MusicSelect.h"
#include "Scene/Initialize/InitializeScene.h"

enum Scene {
	INITIALIZE,
	ENTRY,
	MUSIC_SELECT,
	INGAME
};

#endif /* __SCENE_H_ */
