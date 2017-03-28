#ifndef __MODULECASTLESCENE_H__
#define __MODULECASTLESCENE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Music;

class ModuleCastleScene : public Module
{
public:
	ModuleCastleScene();
	~ModuleCastleScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Mix_Music* music = nullptr;
	SDL_Rect background;
	bool fading = false;
	int yflag = -1788;
};

#endif