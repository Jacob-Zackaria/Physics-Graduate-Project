#ifndef AUDIO_H
#define AUDIO_H

#include "irrKlang.h"

class Audio
{
public:
	enum class Name
	{
		BACKGROUND,
		PIG_SING_7,
		RED_BIRD_YELL,
		NOT_INITIALIZED
	};

	Audio(const char* newAudio);
	Audio(const Audio&) = delete;
	const Audio& operator = (const Audio&) = delete;
	~Audio();

	void Play();
	void Stop();
	void SetSong(irrklang::ISound* newSong);
	const char* GetFileName();
	void SetVolume(const float newVol);

	Name GetName();
	void SetName(Audio::Name newName);

	//-----links----
	void setNext(Audio* newNext);
	void setPrev(Audio* newPrev);
	Audio* getNext() const;
	Audio* getPrev() const;

private:
	Audio::Name pName;
	const char* pAudio;
	irrklang::ISound* pSong;

	// links
	Audio* pNext;
	Audio* pPrev;

};

#endif AUDIO_H