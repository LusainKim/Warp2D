#include "stdafx.h"

#include "Framework/Warp2DFramework.h"
#include "Framework/IndRes/IndRes.h"

#include "TestScene.h"


CTestScene::CTestScene()
{
}


CTestScene::~CTestScene()
{
}

bool CTestScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_LBUTTONDOWN:	
	case WM_MBUTTONDOWN:	
	case WM_RBUTTONDOWN:	
	case WM_MOUSEMOVE:		
	case WM_LBUTTONUP:		
	case WM_MBUTTONUP:		
	case WM_RBUTTONUP:		
	case WM_MOUSEWHEEL:		
		break;
	default:
		return false;
	}

	return(true);
}

bool CTestScene::OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_SIZE:
		{
			auto rcClient = m_pFramework->GetClientSize();
			m_Camera.SetClientSize(Point2F(rcClient.right, rcClient.bottom));
		}
		break;

	case WM_LBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MOUSEMOVE:
	case WM_LBUTTONUP:
	case WM_MBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MOUSEWHEEL:
		return OnProcessingMouseMessage(hWnd, nMessageID, wParam, lParam);

	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_CHAR:
		return OnProcessingKeyboardMessage(hWnd, nMessageID, wParam, lParam);

	default:
		return false;
	}

	return true;
}

bool CTestScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 'A':		m_ptPlayer.x -= 10.f;
			break;
		case 'W':		m_ptPlayer.y -= 10.f;
			break;
		case 'D':		m_ptPlayer.x += 10.f;
			break;					 
		case 'S':		m_ptPlayer.y += 10.f;
			break;
		case 'Z':		m_Camera.Scale(m_Camera.GetScale() * 2.f);
			break;
		case 'X':		m_Camera.Scale(m_Camera.GetScale() * 0.5f);
			break;
		case 'G':
			m_uiInventory.GetItem(m_upItem.get());
			break;
		case 'H':
			m_uiInventory.GetItem(nullptr);
		default:
			return false;
		}
		break;
	default:
		return false;
	}
	return(true);
}

bool CTestScene::OnCreate(wstring && tag, CWarp2DFramework * pFramework)
{
	if (!Base::OnCreate(std::move(tag), pFramework)) return false;

	auto rcClient = m_pFramework->GetClientSize();
	m_Camera.SetClientSize(Point2F(rcClient.right, rcClient.bottom));

	auto rendertarget = pFramework->GetRenderTarget();

	rendertarget->CreateSolidColorBrush(ColorF{ ColorF::Crimson }, &m_pd2dsbrDefault);

	m_Camera.SetPosition(m_ptPlayer);
	m_Camera.SetAnchor(Point2F(0.f, 0.f));

	m_upItem = make_unique<CItem>(
		Point2F(100, 100), RectF(-10, -10, 10, 10));

	m_upItem->RegisterImage(
		m_pIndRes.get(), rendertarget.Get(), "Buckler.png");

	m_uiInventory.BuildObject(this);

	return true;
}

void CTestScene::Update(float fTimeElapsed)
{
	m_Camera.SetPosition(m_ptPlayer);
	m_uiInventory.Update(fTimeElapsed);
}

void CTestScene::Draw(ID2D1HwndRenderTarget * pd2dRenderTarget)
{
	auto cameramtx = m_Camera.RegenerateViewMatrix();
	pd2dRenderTarget->SetTransform(cameramtx);

	pd2dRenderTarget->FillRectangle(
		  RectF(-10, -10, 10, 10) + m_ptPlayer
		, m_pd2dsbrDefault.Get());


	pd2dRenderTarget->DrawRectangle(
		RectF(50, 50, 70, 70)
		, m_pd2dsbrDefault.Get());

	m_upItem->Draw(pd2dRenderTarget);

	m_uiInventory.Draw(pd2dRenderTarget);
}
