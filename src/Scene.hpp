#ifndef __SCENE_HPP_
#define __SCENE_HPP_

#include <iostream>

#include "Scene/Initialize/InitializeScene.hpp"
#include "Scene/EntryScene.hpp"
#include "Scene/MusicSelect/MusicSelect.hpp"
#include "Scene/Ingame/Ingame.hpp"

enum Scene {
	INITIALIZE,
	ENTRY,
	MUSIC_SELECT,
	INGAME
};

#endif /* __SCENE_HPP_ */