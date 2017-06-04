#ifndef __MODULEVILLAGESCENE_H__
#define __MODULEVILLAGESCENE_H__

#include "Module.h"
#include "Path.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleVillageScene : public Module
{
public:
	ModuleVillageScene();
	~ModuleVillageScene();

	bool Start();
	update_status Update();
	bool CleanUp();

	void ModuleVillageScene::Side_scrolling();
	void ModuleVillageScene::OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	SDL_Texture* graphics3 = nullptr;
	SDL_Texture* graphics4 = nullptr;
	SDL_Texture* train = nullptr;
	SDL_Rect background1;
	SDL_Rect background2;
	SDL_Rect npi;

	Animation train_back;
	Animation train_mid;
	Animation train_front;
	float yflag;
	float xflag;
	int track_repeat;
	float ycounter;
	bool cinematic;
	int timer;
	int timer2;
	float speed;
	bool timerup;
	bool on_rails;
	bool going_left;
	bool scroll_timer;
	bool scrolling;
	float back_train_y;
	float mid_train_y;
	float front_train_y;
	float train_x;
	float train_speedy;
	float train_speedx;

};

#endif
