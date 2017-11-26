#pragma once

#include "Object/Object.h"

class CIndRes;
class CItem;



struct UserInfo
{
	float	maxHP;
	float	HP;

	float	att;
	float	def;

	float	dex;
	float	agi;

	UINT	level;
	UINT	exp;

	bool GetExp(int exp) { this->exp += exp; return LevelUp(); }
	bool LevelUp()
	{
		if (exp < level * 100) return false;
		exp -= level * 100;
		level++;

		maxHP += 12;
		HP = maxHP;
		att += 1.125f;
		def++;
		dex += 3;
		agi += 2;
		return true;
	}
	constexpr static UserInfo GetInfoFromLevel(UINT level) 
	{
		return {
			static_cast<float>(level * 12 + 100),
			static_cast<float>(level * 12 + 100),
			static_cast<float>(10 + level * 1.125f),
			static_cast<float>(5 + level),
			static_cast<float>(level * 3),
			static_cast<float>(5 + level * 2),
			level,
			0
		};
	}
};

class CPlayer
	: public CObject
{
public:
	enum Dir { left = 1, top = 3, right = 2, bottom = 0 };

	CPlayer(D2D_SIZE_U pt);
	virtual ~CPlayer() override;

	virtual void Update(float fTimeElapsed) override;
	virtual void Draw(ID2D1HwndRenderTarget* RenderTarget) override;
	virtual void DrawUI(ID2D1HwndRenderTarget* RenderTarget) override;

	virtual void RegisterImage(CIndRes* indres,
		ID2D1HwndRenderTarget* RenderTarget, path filename, D2D_SIZE_U szSprite);

	virtual void RegisterImage(const ComPtr<ID2D1Bitmap1>& bmp, D2D_SIZE_U szSprite);
	virtual void RegisterImage(ComPtr<ID2D1Bitmap1>&& bmp, D2D_SIZE_U szSprite) noexcept;

	void Move(Dir dir);

	const D2D_SIZE_U& GetCoord() const { return m_szCoord; }

	void GetDamage(float att)
	{
		m_UserInfo.HP = max(0, m_UserInfo.HP - max(0, att - m_UserInfo.def));
		m_UserInfo.GetExp(rand() % 3 + 1);
	}

private:

	ComPtr<ID2D1Bitmap1>		m_bmpImage;
	D2D_SIZE_U					m_szCoord;

	Dir							m_Direction;
	D2D_SIZE_U					m_szSprite;
	UINT						m_iSprite;

	float						m_fTick;

public:
	const UserInfo& GetInfo() const { return m_UserInfo; }

private:
	UserInfo					m_UserInfo;

public:
	friend class CUIInventory;

private:
	list<unique_ptr<CItem>>		m_lstItem;


};
