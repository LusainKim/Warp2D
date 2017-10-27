#pragma once

class CIndRes;

class CWarp2DFramework
{

public:
	CWarp2DFramework() = default;

	void RegisterIndRes(shared_ptr<CIndRes> indres) { m_pIndRes = indres; }

	// Framework 만들 때
	void OnCreate(HWND hWnd, HINSTANCE hInst, shared_ptr<CIndRes> indres);

	// Scene 만들 때
	void BuildObject();

	void FrameAdvance();

	void Draw();

	void Update(float fTimeElapsed);

	// Framework에 필요한 것들.
private:
	
	HWND							m_hWnd				{ nullptr }	;
	HINSTANCE						m_hInst				{ nullptr }	;

	shared_ptr<CIndRes>				m_pIndRes			{ nullptr }	;

	ComPtr<ID2D1HwndRenderTarget>	m_pd2dRenderTarget	{ nullptr }	;

	// Scene에 필요한 것들.
private:

	ComPtr<ID2D1SolidColorBrush>	m_pd2dsbrDefault	{ nullptr }	;
	ComPtr<IDWriteTextFormat>		m_pdwTextFormat		{ nullptr };
	ComPtr<IDWriteTextLayout>		m_pdwTextLayout		{ nullptr }	;

	ComPtr<ID2D1Bitmap1>			m_pd2dbmpTest;
	float currImg = 0;
	float fPositionX = 100.f;
};