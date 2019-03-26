#ifndef __SCENE_H_
#define __SCENE_H_

#include <iostream>

#include "Scene/EntryScene.h"
#include "Scene/MusicSelect.h"
#include "Scene/InitializeScene.h"

enum Scene {
	INITIALIZE,
	ENTRY,
	MUSIC_SELECT,
	INGAME
};

#endif /* __SCENE_H_ */
