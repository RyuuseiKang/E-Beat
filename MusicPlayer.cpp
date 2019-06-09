#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer() {
	player.setMultiPlay(true);
}

MusicPlayer::~MusicPlayer() {

}

void MusicPlayer::SetMusic(string _musicName) {
	player.load(_musicName);
}

void MusicPlayer::play() {
	player.play();
}

long MusicPlayer::getPosition() {
	return player.getPositionMS();
}

