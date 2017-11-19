#pragma once

#include <stack>
#include <map>

class CInputManager
{
public:
	struct Button
	{
		function<void()> down_event;
		function<void()> doing_event;
		function<void()> up_event;
	};

	void ProcessInput();

private:
	UCHAR m_pKeyBuffer[256];
	
	map<UCHAR, stack<Button>> m_mRegisterKeyList;

};