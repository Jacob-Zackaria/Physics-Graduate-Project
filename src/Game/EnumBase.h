#ifndef ENUM_NAME_H
#define ENUM_NAME_H

#ifndef ENUM_BASE
#define ENUM_BASE

struct EnumBase
{
	enum class Name
	{
		Stubb // needed for overloading
	};

	bool operator == (EnumBase tmp)
	{
		return (this->value == tmp.value);
	}

	int value;
};

#endif

struct ModelName : public EnumBase
{
	ModelName(ModelName::Name n)
	{
		this->value = (unsigned int)n;
	}

	enum class Name
	{
		Sprite = 0x60000,
		Cube,
		Circle,
		Box,
		Tri,
		NOT_INITIALIZED
	};
};

#endif