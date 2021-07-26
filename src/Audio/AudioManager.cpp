#include "AudioManager.h"

AudioManager* AudioManager::privGetInstance()
{
	static AudioManager instance;
	return &instance;
}

AudioManager::AudioManager()
	:
	pList(nullptr),
	pSoundEng(irrklang::createIrrKlangDevice())
{
}

AudioManager::~AudioManager()
{
}

void AudioManager::Add(Audio* newAudio, Audio::Name newName, bool newLoop, bool newStartPause, bool newMakeTrace)
{
	AudioManager* pMan = AudioManager::privGetInstance();

	newAudio->SetName(newName);
	newAudio->SetSong(pMan->pSoundEng->play2D(newAudio->GetFileName(), newLoop, newStartPause, newMakeTrace));

	pMan->privAddToFront(newAudio, pMan->pList);
}

Audio* AudioManager::Find(const Audio::Name newName)
{
	AudioManager* pMan = AudioManager::privGetInstance();

	Audio* pTmp = pMan->pList;
	while (pTmp != nullptr)
	{
		if (pTmp->GetName() == newName)
		{
			return pTmp;
		}
		pTmp = pTmp->getNext();
	}

	return nullptr;
}

void AudioManager::Play(const Audio::Name newName)
{
	AudioManager* pMan = AudioManager::privGetInstance();
	Audio* pAudio = pMan->Find(newName);

	pAudio->Play();
}

void AudioManager::SetVolume(const Audio::Name newName, const float newVol)
{
	AudioManager* pMan = AudioManager::privGetInstance();
	Audio* pAudio = pMan->Find(newName);

	pAudio->SetVolume(newVol);
}

void AudioManager::Stop(const Audio::Name newName)
{
	AudioManager* pMan = AudioManager::privGetInstance();
	Audio* pAudio = pMan->Find(newName);

	pAudio->Stop();
}

void AudioManager::Terminate()
{
	AudioManager* pMan = AudioManager::privGetInstance();

	Audio* pTmp = pMan->pList;
	Audio* pTmp2 = nullptr;
	while (pTmp!= nullptr)
	{
		pTmp2 = pTmp;
		pTmp = pTmp->getNext();
		delete pTmp2;
	}

	pMan->pSoundEng->stopAllSounds();
	pMan->pSoundEng->removeAllSoundSources();
	pMan->pSoundEng->drop();
}

void AudioManager::privAddToFront(Audio* node, Audio*& head)
{
	assert(node);

	if (head == nullptr)
	{
		head = node;
		node->setNext(nullptr);
		node->setPrev(nullptr);
	}
	else
	{
		node->setNext(head);
		head->setPrev(node);
		head = node;
	}
}
