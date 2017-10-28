#pragma once



/// <summary>
/// 현재 윈도우 프로시저와 연결된 클래스 인스턴스를 가져옵니다.
/// </summary>
///	<param name = "hWnd"> 윈도우 핸들입니다. 해당 윈도우 핸들과 연결된 클래스 인스턴스를 반환합니다. </param>
/// <returns> 연결된 클래스 인스턴스 포인터를 반환합니다. </returns>
template <typename FrameworkPtr>
FrameworkPtr GetUserDataPtr(HWND hWnd) noexcept
{
	return reinterpret_cast<FrameworkPtr>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
}

/// <summary>
/// 안전하게 COM 객체를 1회 해제합니다. 해제한 뒤 객체를 가지고 있던 포인터를 nullptr로 초기화합니다.
/// </summary>
///	<param name = "hWnd"> 윈도우 핸들입니다. 이 핸들 값으로 데이터를 찾을 수 있게 됩니다. </param>
///	<param name = "ptr"> 윈도우 핸들과 연결될 데이터입니다. 대체로 클래스 인스턴스의 포인터를 사용합니다. </param>
/// <returns> LONG_PTR 형식으로 결과값을 반환합니다. </returns>
inline auto SetUserDataPtr(HWND hWnd, LPVOID ptr) noexcept
{
	return ::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(ptr));
}






