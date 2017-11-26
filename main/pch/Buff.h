#pragma once

#include <memory>

struct Buff
{
	enum TYPE
	{
		  HP
		, ATT
		, DEF
		, DEX
		, AGI
		, CUSTOM
	};

	float	maxHP	= 0.f;

	float	att		= 0.f;
	float	def		= 0.f;

	float	dex		= 0.f;
	float	agi		= 0.f;

	template<typename ...Args>
	Buff(Args&& ...args)
	{
		InitBuff(args...);
	}

	template<typename ...Args>
	void InitBuff(std::pair<TYPE, float>& type, Args&& ...args)
	{
		switch (type.first)
		{
		case HP:	maxHP	= type.second;		break;

		case ATT:	att		= type.second;		break;
		case DEF:	def		= type.second;		break;
							
		case DEX:	dex		= type.second;		break;
		case AGI:	agi		= type.second;		break;
		}
	
		InitBuff(args...);
	}
};

constexpr std::pair<Buff::TYPE, float> BUFF(Buff::TYPE type, float data)
{
	return std::make_pair(type, data);
}
