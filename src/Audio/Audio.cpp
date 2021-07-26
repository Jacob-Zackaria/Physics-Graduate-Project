#include "Audio.h"

Audio::Audio(const char* newAudio)
	:
	pName(Audio::Name::NOT_INITIALIZED),
	pAudio(newAudio),
	pSong(nullptr),
	pNext(nullptr),
	pPrev(nullptr)
{
}

Audio::~Audio()
{
	this->pSong->drop();
}

void Audio::Play()
{
	this->pSong->setPlayPosition(0);
	this->pSong->setIsPaused(false);
}

void Audio::Stop()
{
	this->pSong->setIsPaused(true);
}

void Audio::SetSong(irrklang::ISound* newSong)
{
	this->pSong = newSong;
}

const char* Audio::GetFileName()
{
	return this->pAudio;
}

void Audio::SetVolume(const float newVol)
{
	this->pSong->setVolume(newVol);
}


Audio::Name Audio::GetName()
{
	return this->pName;
}

void Audio::SetName(Audio::Name newName)
{
	this->pName = newName;
}


//-----links----
void Audio::setNext(Audio* newNext)
{
	this->pNext = newNext;
}

void Audio::setPrev(Audio* newPrev)
{
	this->pPrev = newPrev;
}

Audio* Audio::getNext() const
{
	return (this->pNext);
}

Audio* Audio::getPrev() const
{
	return (this->pPrev);
}
