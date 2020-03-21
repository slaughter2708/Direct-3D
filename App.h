#pragma once
#include "Window.h"
#include "Timer.h"


class App
{
public:
	App();
	// MASTER FRAME / GAME LOOP
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	Timer timer;
	int x = wnd.mouse.GetPosX();
	int y = wnd.mouse.GetPosY();


	void write();
};