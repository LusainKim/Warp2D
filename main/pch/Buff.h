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
	
	Buff(float maxHP, float att, float def, float dex, float agi)
		: maxHP{ maxHP}
		, att{ att }
		, def{ def }
		, dex{ dex }
		, agi{ agi }
	{

	}

	template<typename ...Args>
	Buff(Args&& ...args)
	{
		InitBuff(std::forward<Args>(args)...);
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
	
		InitBuff(std::forward<Args>(args)...);
	}

	void InitBuff() { }

	Buff& operator+=(const Buff& buff)
	{
		maxHP += buff.maxHP;
		att += buff.att;
		def += buff.def;
		dex += buff.dex;
		agi += buff.agi;
		return *this;
	}

};

constexpr std::pair<Buff::TYPE, float> BUFF(Buff::TYPE type, float data)
{
	return std::make_pair(type, data);
 }

inline Buff operator+(const Buff& lhs, const Buff& rhs)
{
	return
	{
		  lhs.maxHP + rhs.maxHP
		, lhs.att + rhs.att	
		, lhs.def + rhs.def	
		, lhs.dex + rhs.dex	
		, lhs.agi + rhs.agi	
	};
}
