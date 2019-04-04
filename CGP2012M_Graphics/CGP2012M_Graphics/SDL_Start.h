#pragma once
#include "SDL.h"

class SDL_Start
{
public:
	SDL_Window *win;
	SDL_GLContext glcontext;

	int w;
	int h;
	SDL_GLContext Init()
	{
		//SDL Initialise
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_DisplayMode DM;
		SDL_GetCurrentDisplayMode(0, &DM);
		auto width = DM.w;
		auto height = DM.h;
		w = width / 2;
		h = height / 2;

		//SDL create window
		win = SDL_CreateWindow("Jez Horton - CMP2012M - 16610629", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

		//set context attributes
		//sets opengl version to 4.3
		int major = 4, minor = 3;

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_PROFILE_CORE); //use core profile
		//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); //ask for forward compatible
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		// Create an OpenGL context associated with the window.
		glcontext = SDL_GL_CreateContext(win);

		return glcontext;
	}
};