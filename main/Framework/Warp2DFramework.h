#pragma once

class CIndRes;
class CTimer;

class CWarp2DFramework
{

public:
	CWarp2DFramework() = default;

	void RegisterIndRes(shared_ptr<CIndRes> indres) { m_pIndRes = indres; }
	void RegisterTimer(shared_ptr<CTimer> timer) { m_pTimer = timer; }

	// Framework ���� ��
	void OnCreate(HWND hWnd, HINSTANCE hInst, shared_ptr<CIndRes> indres, shared_ptr<CTimer> timer);

	// Scene ���� ��
	void BuildObject();

	void FrameAdvance();

	void Draw();

	void Update(float fTimeElapsed);

	// Framework ���� ȣ���ϴ� ������ ���ν����Դϴ�.
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	// Framework�� �ʿ��� �͵�.
private:
	
	HWND							m_hWnd				{ nullptr }	;
	HINSTANCE						m_hInst				{ nullptr }	;

	shared_ptr<CIndRes>				m_pIndRes			{ nullptr }	;
	shared_ptr<CTimer>				m_pTimer			{ nullptr }	;

	ComPtr<ID2D1HwndRenderTarget>	m_pd2dRenderTarget	{ nullptr }	;

	// Scene�� �ʿ��� �͵�.
private:

	ComPtr<ID2D1SolidColorBrush>	m_pd2dsbrDefault	{ nullptr }	;
	ComPtr<IDWriteTextFormat>		m_pdwTextFormat		{ nullptr };
	ComPtr<IDWriteTextLayout>		m_pdwTextLayout		{ nullptr }	;

	ComPtr<ID2D1Bitmap1>			m_pd2dbmpTest;
	float currImg = 0;
	float fPositionX = 100.f;
};