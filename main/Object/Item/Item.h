#pragma once
#include "Object/Object.h"



class CIndRes;

class CItem 
	: public CObject
{
public:
	CItem(D2D_POINT_2F pt, D2D_RECT_F rc = RectF());
	virtual ~CItem() override;

	virtual void Update(float fTimeElapsed) override;
	virtual void Draw(ID2D1HwndRenderTarget* RenderTarget) override;

	virtual void RegisterImage(CIndRes* indres,
		ID2D1HwndRenderTarget* RenderTarget, path filename);

	virtual void RegisterImage(const ComPtr<ID2D1Bitmap1>& bmp);
	virtual void RegisterImage(ComPtr<ID2D1Bitmap1>&& bmp) noexcept;

	ID2D1Bitmap1* GetBitmap() const { return m_bmpImage.Get(); }
protected:

	ComPtr<ID2D1Bitmap1>		m_bmpImage;
};
