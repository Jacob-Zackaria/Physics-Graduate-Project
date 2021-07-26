#ifndef SCENE_H
#define SCENE_H

#include "SceneLink.h"
class Scene
{
public:
	enum class Name
	{
		FIRST_LEVEL,
		SECOND_LEVEL,
		THIRD_LEVEL,
		FOURTH_LEVEL,
		FIFTH_LEVEL,
		SIXTH_LEVEL,
		SEVENTH_LEVEL,
		EIGHTH_LEVEL,
		LOAD_LEVEL,
		NOT_INITIALIZED
	};

	Scene();
	Scene(const Scene&) = delete;
	const Scene& operator = (const Scene&) = delete;
	virtual ~Scene();

	Name GetName();
	void SetName(Scene::Name newName);

	void Add(GameObject2D* newObj);
	virtual void AddSceneElements() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Clean() = 0;
	void DeleteSceneElements();
	void Delete(GameObject2D* newObj);


	//-----links----
	void setNext(Scene* newNext);
	void setPrev(Scene* newPrev);
	Scene* getNext() const;
	Scene* getPrev() const;

	void privAddToFront(SceneLink* node, SceneLink*& head);
	void privRemove(SceneLink* pNewData, SceneLink*& pHead);

private:
	Scene::Name pName;
	SceneLink* gameObj;

	// links
	Scene* pNext;
	Scene* pPrev;

};

#endif SCENE_H