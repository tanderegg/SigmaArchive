#ifndef SDL_SYS_H
#define SDL_SYS_H

#include <map>

#include "IOpSys.h"
#include "SDL.h"

class SDLSys : public IOpSys {
public:
	SDLSys() { SDL_Init(SDL_INIT_EVERYTHING); this->_IsFullscreen = false; }
	virtual ~SDLSys() { SDL_GL_DeleteContext(this->_Context); SDL_DestroyWindow(this->_Window); SDL_Quit(); }

	virtual void* CreateGraphicsWindow();
	virtual void ToggleFullscreen();

	virtual bool MessageLoop();
	
	virtual bool SetupTimer();
	virtual double GetDeltaTime();
	
	virtual bool KeyDown(int key, bool focused = false);
	
	virtual void Present();

	virtual int GetWindowWidth();
	virtual int GetWindowHeight();

private:
	SDL_Window *_Window;
	SDL_GLContext _Context;

	// Keyboard state
	std::map<char, bool> _KeyStates;

	double _Frequency;
	long long _LastTime;

	bool _IsFullscreen;
};

#endif