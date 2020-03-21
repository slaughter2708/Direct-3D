#include "App.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include "WindowsThrowMacro.h"



App::App() : wnd(800, 600, "Graphics Window")
{
}


int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;

	
	wnd.gfx().ClearBuffer(c, c, 0.5f);

	wnd.gfx().DrawTestTriangle
	(
		timer.Peek(), 
		wnd.mouse.GetPosX(), wnd.mouse.GetPosY()
	);

//#define DBOUT()
//	{
//		std::ostringstream os;
//		os << "pos X : " << wnd.mouse.GetPosX() << " " <<
//			"Pos Y : " << wnd.mouse.GetPosY() << std::endl;
//		OutputDebugString(os.str().c_str());
//	}
	
	DBOUT()
	{
		std::ostringstream os;
			os << "pos X : " << wnd.mouse.GetPosX() << " " <<
				"Pos Y : " << wnd.mouse.GetPosY() << std::endl;
			OutputDebugString(os.str().c_str());
	}
	wnd.gfx().EndFrame();
}

void App::write()
{

}


