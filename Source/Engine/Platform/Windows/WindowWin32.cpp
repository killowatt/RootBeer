#include "WindowWin32.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}
void WindowWin32::Update()
{
	MSG msg;
	GetMessage(&msg, NULL, 0, 0);
	TranslateMessage(&msg);
	DispatchMessage(&msg);
}

WindowWin32::WindowWin32(const char* title, int32 width, int32 height)
{
	instance = GetModuleHandle(0);

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = instance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"RootBeer";

	RegisterClassEx(&wc);

	wchar_t* wideTitle = new wchar_t[strlen(title) + 1];
	MultiByteToWideChar(CP_UTF8, 0, title, -1, wideTitle, strlen(title) + 1);

	handle = CreateWindow(
		L"RootBeer",
		wideTitle,
		WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT,
		width, height,
		NULL,
		NULL,
		instance,
		NULL
	);

	delete wideTitle;

	ShowWindow(handle, 5);
	UpdateWindow(handle);
}