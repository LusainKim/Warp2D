#pragma once

class CIndRes
{
public:
	CIndRes();
	~CIndRes();

	bool Initialize();
	bool CreateHwndRenderTarget(HWND hWnd, ID2D1HwndRenderTarget** m_pd2dRenderTarget);

	ID2D1Factory3*		d2dFactory()	const { return m_pd2dFactory.Get(); }
	IDWriteFactory3*	dwFactory()		const { return m_pdwFactory.Get(); }
	IWICImagingFactory*	wicFactory()	const { return m_wicFactory.Get(); }

private:
	ComPtr<ID2D1Factory3>		m_pd2dFactory;
	ComPtr<IDWriteFactory3>		m_pdwFactory;
	ComPtr<IWICImagingFactory>	m_wicFactory;
};

