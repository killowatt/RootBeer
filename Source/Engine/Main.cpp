#include "Window.h"

int main()
{
	Window window(u8"Hello你好مرحباこんにちは", 1280, 720);

	while (true)
		window.Update();
}