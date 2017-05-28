#pragma once
#include "Engine.h"

class SystemWindow
{
public:
	virtual void Update() = 0;

};

class Window
{
	SystemWindow* platformWindow;

public:
	void Update();


	void ChangeTitle();

	Window();
	Window(const char* title, int32 width, int32 height);
	~Window();
};
