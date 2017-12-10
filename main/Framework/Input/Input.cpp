#include "stdafx.h"
#include "Framework/Warp2DFramework.h"
#include "Input.h"

void CInputManager::ProcessInput(bool(&arrByte)[256])
{
	bool retval = false;
	BOOL bKeyState = GetKeyboardState(m_pKeyBuffer);
	UNREFERENCED_PARAMETER(bKeyState);

	for (auto& data : m_mRegisterKeyList)
	{
		auto& key = data.first;
		auto& btn = data.second;
		
		if (arrByte[key]) continue;
		arrByte[key] = true;

		if (1 == GetHighBit(m_pKeyBuffer[key]))
		{
			retval = true;
			btn.togleKey = 1;
			btn.down_event();
		}
		else if (1 == btn.togleKey) 
		{
			retval = true;
			btn.togleKey = 0;
			btn.up_event();
		}
	}
}

void CInputManager::bind(UCHAR key, CInputManager::Button && btn)
{
	if (m_mRegisterKeyList.find(key) != end(m_mRegisterKeyList)) m_mRegisterKeyList.erase(key);
	m_mRegisterKeyList.insert(make_pair(key, move(btn)));
}

bool CInputManager::replace(string tag, UCHAR newkey)
{
	auto p = find_if(begin(m_mRegisterKeyList), end(m_mRegisterKeyList), [&](const auto & p)
	{
		return p.second.tag == tag;
	});

	if (p == end(m_mRegisterKeyList))
		return false;

	// erase before key
	auto btn = move(m_mRegisterKeyList.at(p->first));
	m_mRegisterKeyList.erase(p->first);

	bind(newkey, move(btn));

	return true;
}
