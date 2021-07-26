#ifndef LINE_COLLIDER_H
#define LINE_COLLIDER_H

#include "InputSystem.h"
#include "GameObjectMan.h"
class LineCollider : InputSystem
{
public:

	struct ObjectPos
	{
		GameObject2D* gameObj;
		b2Vec2 pos;

		// links
		ObjectPos* pNext;
		ObjectPos* pPrev;

		ObjectPos(GameObject2D* newGameObj, b2Vec2 newPos)
			:
			gameObj(newGameObj),
			pos(newPos),
			pNext(nullptr),
			pPrev(nullptr)
		{
		}

		~ObjectPos()
		{
			GameObjectMan::Delete(this->gameObj);
		}

		//-----links----
		void ObjectPos::setNext(ObjectPos* newNext)
		{
			this->pNext = newNext;
		}

		void ObjectPos::setPrev(ObjectPos* newPrev)
		{
			this->pPrev = newPrev;
		}

		ObjectPos* ObjectPos::getNext() const
		{
			return (this->pNext);
		}

		ObjectPos* ObjectPos::getPrev() const
		{
			return (this->pPrev);
		}
	};

	struct LineInstance
	{
		LineInstance(b2Vec2 newStartPos)
			:
			startPos(newStartPos),
			objectPos(nullptr),
			pNext(nullptr),
			pPrev(nullptr)
		{
		}

		~LineInstance()
		{
			ObjectPos* newGame = this->objectPos;
			ObjectPos* new2 = nullptr;
			while (newGame != nullptr)
			{
				new2 = newGame;
				newGame = newGame->getNext();
				privRemove(new2, this->objectPos);
				delete new2;
			}
		}

		//-----links----
		void LineInstance::setNext(LineInstance* newNext)
		{
			this->pNext = newNext;
		}

		void LineInstance::setPrev(LineInstance* newPrev)
		{
			this->pPrev = newPrev;
		}

		LineInstance* LineInstance::getNext() const
		{
			return (this->pNext);
		}

		LineInstance* LineInstance::getPrev() const
		{
			return (this->pPrev);
		}

		void LineInstance::Add(GameObject2D* newObj, b2Vec2 newPos)
		{
			ObjectPos* newGameObj = new ObjectPos(newObj, newPos);

			this->privAddToEnd(newGameObj, this->objectPos);
		}

		void privAddToEnd(ObjectPos* node, ObjectPos*& head);
		void privRemove(ObjectPos* pNewData, ObjectPos*& pHead);

		b2Vec2 startPos;
		ObjectPos* objectPos;

		// links
		LineInstance* pNext;
		LineInstance* pPrev;
	};

	LineCollider(Color::Type newColor);
	LineCollider(const LineCollider&) = delete;
	const LineCollider& operator = (const LineCollider&) = delete;
	virtual ~LineCollider();

	virtual void Update() override;

	void Render();
	void DrawSegment(b2Vec2 s, b2Vec2 e);
	
	void privAddToEnd(LineInstance* node, LineInstance*& head);
	void privRemove(LineInstance* pNewData, LineInstance*& pHead);

	GraphicsObject_Box* pGrObj;
	LineInstance* lineInstance;
	Color::Type lineCol;
};


#endif LINE_COLLIDER_H