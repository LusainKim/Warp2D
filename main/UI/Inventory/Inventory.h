#pragma once

#include "UI/UIBase.h"

class CItem;

class CUIInventory
	: public CUIBase
{
public:
	CUIInventory();
	~CUIInventory();

	void DrawClient(ID2D1HwndRenderTarget* pd2dRenderTarget) override;
	void DrawCaption(ID2D1HwndRenderTarget* pd2dRenderTarget) override;
	
	void BuildObject(CScene* scene) override;
	
	void Update(float fTimeElapsed) override;
	void GetItem(CItem* item) { m_pItem = item; }

private:

	ComPtr<ID2D1SolidColorBrush>		m_hbrCaption;
	ComPtr<ID2D1SolidColorBrush>		m_hbrClient;
	ComPtr<ID2D1SolidColorBrush>		m_hbrText;

	ComPtr<ID2D1Bitmap1>				m_bmpFrame;
	D2D_RECT_F							m_rcItem;
	CItem*								m_pItem = nullptr;


	ComPtr<IDWriteTextFormat>			m_dwTextFormat;
};
