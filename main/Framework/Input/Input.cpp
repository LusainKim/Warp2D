#include "stdafx.h"
#include "Framework/Warp2DFramework.h"
#include "Input.h"

void CInputManager::ProcessInput()
{
	bool bProcessedByScene = false;
	BOOL bKeyState = GetKeyboardState(m_pKeyBuffer);
	UNREFERENCED_PARAMETER(bKeyState);

	if (m_pNowScene) bProcessedByScene = m_pNowScene->ProcessInput(m_pKeyBuffer);

	if (!bProcessedByScene)
	{
		// TODO: ...
	}
}
