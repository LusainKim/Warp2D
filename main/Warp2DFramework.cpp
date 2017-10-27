#include "stdafx.h"
#include "IndRes.h"
#include "Warp2DFramework.h"

void CWarp2DFramework::OnCreate(HWND hWnd, HINSTANCE hInst, shared_ptr<CIndRes> indres)
{
	RegisterIndRes(indres);
	m_hWnd = hWnd;
	m_hInst = hInst;

	m_pIndRes->CreateHwndRenderTarget(hWnd, 800, 600, &m_pd2dRenderTarget);

	BuildObject();
}

// Scene ¸¸µé ¶§

void CWarp2DFramework::BuildObject()
{
	m_pd2dRenderTarget->CreateSolidColorBrush(ColorF{ ColorF::Crimson }, &m_pd2dsbrDefault);

	auto dwFactoy = m_pIndRes->dwFactory();

	dwFactoy->CreateTextFormat(
	  L"Arial"
	, nullptr
	, DWRITE_FONT_WEIGHT_NORMAL
	, DWRITE_FONT_STYLE_NORMAL
	, DWRITE_FONT_STRETCH_NORMAL
	, 30
	, L"ko-kr"
	, &m_pdwTextFormat);

	m_pdwTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	m_pdwTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);

	dwFactoy->CreateTextLayout(
		  L"Hello, World!"
		, 13
		, m_pdwTextFormat.Get()
		, 300
		, 100
		, &m_pdwTextLayout);
	
	auto wicFactory = m_pIndRes->wicFactory();
	LoadImageFromFile(wicFactory
		, m_pd2dRenderTarget.Get()
		, L"Hit1.png"
		, &m_pd2dbmpTest
	);

}

void CWarp2DFramework::FrameAdvance()
{
	Update(1.f / 60.f);
	Draw();

	Sleep(16);
}

void CWarp2DFramework::Draw()
{
	m_pd2dRenderTarget->BeginDraw();
	m_pd2dRenderTarget->Clear(ColorF{ ColorF::LightGray });

	m_pd2dRenderTarget->DrawRectangle(
		RectF(-50 + fPositionX, 100, 50 + fPositionX, 200)
		, m_pd2dsbrDefault.Get());

	m_pd2dRenderTarget->DrawTextLayout(
		  Point2F(0, 0)
		, m_pdwTextLayout.Get()
		, m_pd2dsbrDefault.Get()
	);

	m_pd2dRenderTarget->DrawText(
		  L"text"
		, 4
		, m_pdwTextFormat.Get()
		, RectF(400, 500, 600, 600)
		, m_pd2dsbrDefault.Get()
	);

	auto bmpSize = m_pd2dbmpTest->GetSize();

	m_pd2dRenderTarget->DrawBitmap(
		  m_pd2dbmpTest.Get()
		, RectF(100, 100, 100 + bmpSize.width * 0.25f, 100 + bmpSize.height)
		, min(1.f, currImg * 0.5f)
		, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR
		, RectF(  bmpSize.width * (int)currImg * 0.25f, 0
				, bmpSize.width * ((int)currImg + 1) * 0.25f, bmpSize.height)
	);

	m_pd2dRenderTarget->EndDraw();

}

void CWarp2DFramework::Update(float fTimeElapsed)
{
	fPositionX += (100 * fTimeElapsed);
	if (fPositionX > 800) fPositionX -= 800.f;

	if ((currImg += fTimeElapsed * 10) >= 4.f)
		currImg -= 4.f;

}
