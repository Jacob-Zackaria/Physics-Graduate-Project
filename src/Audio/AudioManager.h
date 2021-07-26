#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H


#include "Audio.h"

class AudioManager
{
public:

	AudioManager(const AudioManager&) = delete;
	const AudioManager& operator = (const AudioManager&) = delete;
	~AudioManager();

	static void Add(Audio* newAudio, Audio::Name newName, bool newLoop = false, bool newStartPause = true, bool newMakeTrace = true);
	static Audio* Find(const Audio::Name newName);
	static void Play(const Audio::Name newName);
	static void SetVolume(const Audio::Name newName, const float newVol);
	static void Stop(const Audio::Name newName);
	static void Terminate();

private:
	static AudioManager* privGetInstance();
	AudioManager();

	void privAddToFront(Audio* node, Audio*& head);

	Audio* pList;
	irrklang::ISoundEngine* pSoundEng;
};

#endif AUDIO_MANAGER_H