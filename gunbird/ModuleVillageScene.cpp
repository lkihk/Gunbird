#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleIntroScene.h"
#include "ModuleVillageScene.h"
#include "ModuleCastleScene.h"
#include "ModuleMineScene.h"
#include "ModuleScoreScene.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL.h"



ModuleVillageScene::ModuleVillageScene()
{
	background1.h = 5632;
	background1.w = 544;
	background1.x= 0;
	background1.y = 0;

	background2.h = 4000;
	background2.w = 544;
	background2.x = 0;
	background2.y = 0;

	offscreen_wall_down.h = 5;
	offscreen_wall_down.w = 244;
	offscreen_wall_down.x = -10;
	offscreen_wall_down.y = 330;

	offscreen_wall_up.h = 5;
	offscreen_wall_up.w = 244;
	offscreen_wall_up.x = -10;
	offscreen_wall_up.y = -15;

	offscreen_wall_left.h = 340;
	offscreen_wall_left.w = 5;
	offscreen_wall_left.x = -15;
	offscreen_wall_left.y = -10;

	offscreen_wall_right.h = 340;
	offscreen_wall_right.w = 5;
	offscreen_wall_right.x = 234;
	offscreen_wall_right.y = -10;

	train_back.PushBack({ 9, 801, 75, 187 });
	train_back.PushBack({ 116, 801, 75, 187 });
	train_back.speed = 0.5f;

	train_mid.PushBack({ 4, 553, 87, 245 });
	train_mid.PushBack({ 111, 553, 87, 245 });
	train_mid.speed = 0.5f;

	train_front.PushBack({ 3,241, 88, 296 });
	train_front.PushBack({ 116,241 , 88, 296 });
	train_front.PushBack({ 219,241, 88, 296 });
	train_front.PushBack({ 338,241, 88, 296 });
	train_front.PushBack({ 460,241, 88, 296 });
	train_front.PushBack({ 614,241, 88, 296 });
	train_front.PushBack({ 730,241, 88, 296 });
	train_front.PushBack({ 865,241, 88, 296 });

	train_front.speed = 0.5f;


}

ModuleVillageScene::~ModuleVillageScene()
{}    

bool ModuleVillageScene::Start()
{
	LOG("Loading village scene");
	App->enemies->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->player->Enable();
	App->player2->Enable();
	App->scene_village->Enable();

	yflag = -5312;
	xflag = -320;
	ycounter = 0;
	speed = 0.4;

	back_train_y = -730 + 488;
	mid_train_y = -730 + 261;
	front_train_y = -730;
	train_x = -187;
	
	
	cinematic = false;
	timerup = false;
	on_rails = false;
	going_left = true;
	scroll_timer = false;
	scrolling = false;

	graphics = App->textures->Load("assets/images/backgrounds/Village lower background.png");
	graphics2 = App->textures->Load("assets/images/backgrounds/Village upper background.png");
	graphics3 = App->textures->Load("assets/images/backgrounds/Village train background.png");
	graphics4 = App->textures->Load("assets/images/backgrounds/Village train background.png");
	train = App->textures->Load("assets/images/train.png");


	App->audio->audio = App->audio->Load("assets/bgm/village.ogg");
	Mix_PlayMusic(App->audio->audio, -1);


	App->collision->AddCollider(offscreen_wall_down, COLLIDER_WALL);
	App->collision->AddCollider(offscreen_wall_up, COLLIDER_WALL);
	App->collision->AddCollider(offscreen_wall_left, COLLIDER_WALL);
	App->collision->AddCollider(offscreen_wall_right, COLLIDER_WALL);

	//---ENEMIES---
	//--Adding Rotating Turrets--
	//---Two at the beginning--
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 3, -60, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 35, -60, 0);

	//---The four at the bridge---
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 35, -340, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 65, -340, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 133, -340, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 165, -340, 0);

	//---Three standing---
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 70, -890, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 39,-890, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 101, -890, 0);

	//---Three moving down

	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 137, -890, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 173, -890, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, 209, -890, 1);

	//---Three moving down---
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, -30, -840, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, -60, -840, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::ROTATINGTURRET, -90, -840, 2);

	//--Adding Green Robot--
	App->enemies->AddEnemy(ENEMY_TYPES::GREENROBOT, 73, -90, 0);

	//--Adding Window Guns--
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWGUN, 26, -122, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::WINDOWGUN, 170, -122, 0);

	//--Adding Balloons--
	App->enemies->AddEnemy(ENEMY_TYPES::BALLOON, 50, 20, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::BALLOON, 150, -50, 0);

	//--Adding Rooftop Turrets--
	App->enemies->AddEnemy(ENEMY_TYPES::TWOCANNONTURRET, 26, -525, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::TWOCANNONTURRET, 26, -585, 0);

	App->enemies->AddEnemy(ENEMY_TYPES::FOURCANNONTURRET, 160, -520, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::FOURCANNONTURRET, 160, -580, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::FOURCANNONTURRET, 160, -460, 0);
	
	//--Adding Flying Gunners--
	//App->enemies->AddEnemy(ENEMY_TYPES::FLYINGGUNNER, 160, -520, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::FLYINGGUNNER, 160, -460, 0);

	return true;
}

bool ModuleVillageScene::CleanUp()
{
	LOG("Unloading village scene");
	
	App->enemies->Disable();
	App->particles->Disable();
	App->collision->Disable();
	App->player->Disable();
	App->player2->Disable();
	App->scene_village->Disable();

	
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->textures->Unload(graphics3);
	App->textures->Unload(graphics4);
	App->textures->Unload(train);

	return true;
}

// Update: draw background
update_status ModuleVillageScene::Update()
{
	if (!on_rails)
	{
		if (yflag <= -4350)
		{
			yflag += speed;
			train_speedy = 0.4f;
			train_speedx = 0.0f;
		}

		if (yflag >= -4350 && xflag < -129)
		{
			xflag += 0.66;
			yflag += speed;
			train_speedx = 0.22;
			train_speedy = 0.4f;
			
		}
		if (yflag >= -4234 && !cinematic)
		{
			train_speedx = 0.0f;
			train_speedy = 0.0f;
			if (!timerup)
			{
				timer = SDL_GetTicks() + 3500;
				timerup = true;
			}
			if (SDL_GetTicks() > timer)
			{
				cinematic = true;
				App->audio->audio = App->audio->Load("assets/bgm/trump.ogg");
				Mix_PlayMusic(App->audio->audio, -1);
			}
		}

		if (xflag < -60 && cinematic)
		{
			xflag += 0.66;
			yflag += speed;
			timerup = false;
		
			if (train_speedy > 0) { train_speedy *= 0.8; }
			else { train_speedy = -5.4f; }
			train_speedx = 0.22;
		}
		if (xflag >= -60 && !timerup && !scrolling)
		{
			timer2 = SDL_GetTicks() + 2000;
			timerup = true;
			train_speedx = 0.0f;
			train_speedy = 0.0f;
		}
		if (SDL_GetTicks() > timer2 && xflag >= -60 && speed < 10.0 && !scrolling)
		{
			if (train_speedy > -1.0) { train_speedy -= 0.1; }
			speed *= 1.015;
			yflag += speed;
		}
		if (yflag >= 320.0f)
		{
			on_rails = true;
			yflag = -3680;
		}

		if (speed >= 10.0)
		{
			Side_scrolling();
			scrolling == true;
		}

		


	App->render->Blit(graphics, xflag, yflag, &background1, 10.0f);

	

	App->render->Blit(graphics2, xflag, yflag, &background1, 10.0f);
	App->render->Blit(graphics3, xflag, yflag-4000, &background2, 10.0f);

	}

	if (on_rails)
	{
		Side_scrolling();
		if(yflag >= 3680)
		{
			yflag = -3680;
		}
		App->render->Blit(graphics3, xflag, yflag - 4000, &background2, 10.0f);
		App->render->Blit(graphics4, xflag, yflag, &background2, 10.0f);
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_UP)
	{
		speed = 0.4;
	}

	if ((App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN || App->player->out && App->player2->out) && !App->fade->fading)
	{
		App->fade->FadeToBlack(this, App->scene_score, 2.0f);

	}
	if ((App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN ) && !App->fade->fading)
	{
		App->fade->FadeToBlack(this, App->scene_intro, 2.0f);
	}
	App->render->Blit(graphics, xflag, yflag, &background1, 10.0f);
	//BS to make the tank blit under the bridge v
	if (tank_on && tank_inScreen)
	{
		App->render->Blit(App->enemies->sprites, tank_position.x, tank_position.y, &(tank_anim->GetCurrentFrame()));
		if (tank_hp > 0)
		{
			App->render->Blit(App->enemies->sprites, tank_position.x + 10, tank_position.y + 13, &(tank_extra1->GetCurrentFrame()));
			App->render->Blit(App->enemies->sprites, tank_position.x + 46, tank_position.y + 13, &(tank_extra2->GetCurrentFrame()));
		}
	}
	tank_on = true;
	//BS to make the tank blit under the bridge ^
	App->render->Blit(graphics2, xflag, yflag, &background1, 10.0f);
	App->render->Blit(graphics3, xflag, yflag - 4000, &background2, 10.0f);
	App->render->Blit(train, train_x += train_speedx, front_train_y += train_speedy, &(train_front.GetCurrentFrame()), 10.0f);
	App->render->Blit(train, train_x += train_speedx, mid_train_y += train_speedy, &(train_mid.GetCurrentFrame()), 10.0f);
	App->render->Blit(train, train_x += train_speedx, back_train_y +=train_speedy, &(train_back.GetCurrentFrame()), 10.0f);

	//-167

	return UPDATE_CONTINUE;
}

void ModuleVillageScene::Side_scrolling()
{
	if (going_left && !scroll_timer)
	{
		yflag += speed;
		xflag += 0.66;
		train_speedx = 0.22;
		if (xflag >= 0)
		{
			timer = SDL_GetTicks() + 1000;
			scroll_timer = true;
		}
	}

	else if (scroll_timer)
	{
		yflag += speed;
		if (SDL_GetTicks() >= timer)
		{
			scroll_timer = false;
			if (going_left)
			{
				going_left = false;
			}
			else
			{
				going_left = true;
			}
		}
	}

	if (!going_left && !scroll_timer)
	{
		yflag += speed;
		xflag -= 0.66;
		train_speedx = 0.22;
		if (xflag <= -60)
		{
			timer = SDL_GetTicks() + 1000;
			scroll_timer = true;
		}
	}
}

void ModuleVillageScene::OnCollision(Collider* c1, Collider* c2)
{

}
