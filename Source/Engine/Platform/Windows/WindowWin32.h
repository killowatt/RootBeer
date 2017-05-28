#pragma once

#include "../../Window.h"
#include <Windows.h>

class WindowWin32 : public SystemWindow
{
	HINSTANCE instance;
	HWND handle;

public:
	void Update();

	WindowWin32(const char* title, int32 width, int32 height);
};