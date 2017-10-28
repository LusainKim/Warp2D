#pragma once



/// <summary>
/// ���� ������ ���ν����� ����� Ŭ���� �ν��Ͻ��� �����ɴϴ�.
/// </summary>
///	<param name = "hWnd"> ������ �ڵ��Դϴ�. �ش� ������ �ڵ�� ����� Ŭ���� �ν��Ͻ��� ��ȯ�մϴ�. </param>
/// <returns> ����� Ŭ���� �ν��Ͻ� �����͸� ��ȯ�մϴ�. </returns>
template <typename FrameworkPtr>
FrameworkPtr GetUserDataPtr(HWND hWnd) noexcept
{
	return reinterpret_cast<FrameworkPtr>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
}

/// <summary>
/// �����ϰ� COM ��ü�� 1ȸ �����մϴ�. ������ �� ��ü�� ������ �ִ� �����͸� nullptr�� �ʱ�ȭ�մϴ�.
/// </summary>
///	<param name = "hWnd"> ������ �ڵ��Դϴ�. �� �ڵ� ������ �����͸� ã�� �� �ְ� �˴ϴ�. </param>
///	<param name = "ptr"> ������ �ڵ�� ����� �������Դϴ�. ��ü�� Ŭ���� �ν��Ͻ��� �����͸� ����մϴ�. </param>
/// <returns> LONG_PTR �������� ������� ��ȯ�մϴ�. </returns>
inline auto SetUserDataPtr(HWND hWnd, LPVOID ptr) noexcept
{
	return ::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(ptr));
}






