#include "Application.h"
#include "ModuleParticles.h"
#include "Enemy_Balloon.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL_timer.h"
#include <cmath>



Enemy_Balloon::Enemy_Balloon(int x, int y, int option) : Enemy(x, y, option)
{
	aditionalanimation = true;

	fly.PushBack({ 0, 0, 53, 53 });
	fly.PushBack({ 53, 0, 53, 53 });
	fly.PushBack({ 106, 0, 53, 53 });
	fly.PushBack({ 159, 0, 53, 53 });
	fly.PushBack({ 212, 0, 53, 53 });
	fly.speed = 0.45f;
	
	fly2.PushBack({ 265, 0, 53, 53 });
	fly2.speed = 0.45f;

	fly3.PushBack({ 0, 0, 53, 53 });
	fly3.PushBack({ 53, 0, 53, 53 });
	fly3.PushBack({ 106, 0, 53, 53 });
	fly3.PushBack({ 159, 0, 53, 53 });
	fly3.PushBack({ 212, 0, 53, 53 });
	fly3.PushBack({ 318, 0, 53, 53 });
	fly3.speed = 0.45f;

	extra_animation = &fly;

	//path.PushBack({ 0.0f, 0.55f }, 220);
	//path.PushBack({ 0.0f, 2.0f }, 55);
	if (position.y < 0)
	{
		path.PushBack({ 0.0f, 0.0f }, 25);
		path.PushBack({ 0.0f, 1.5f }, 46);
		counter++;
	}
	
	if (counter != 0)
	{
		path.PushBack({ 0.0f, 0.0f }, 140);
		path.PushBack({ 0.0f, 1.5f }, 65);
		path.PushBack({ 0.0f, 0.0f }, 345);
		path.PushBack({ 0.0f, 1.0f }, 500);
	}
	else	
	{
		path.PushBack({ 0.0f, 0.0f }, 120);
		path.PushBack({ 0.0f, 1.5f }, 65);
		path.PushBack({ 0.0f, 0.0f }, 270);
		path.PushBack({ 0.0f, 1.0f }, 500);
	}
	
	//.PushBack({ 0.0f, 0.0f }, 120);
	//path.PushBack({ 0.0f, 2.0f }, 10000);

	collider = App->collision->AddCollider({ 0, 0, 42, 53 }, COLLIDER_TYPE::COLLIDER_ENEMY_F, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	killscore = 500;
	hp = 19.0f;
	damaged_hp = 7;
	death_type = MEDIUM_ENEMY;

	if (position.x < 112)
		drops_powerup = true;

	if (position.x > 112)
		drops_bomb = true;
	flying = true;
}

void Enemy_Balloon::Move()
{
	position = original_pos + path.GetCurrentPosition();

	if (status == NORMAL)
		extra_animation = &fly;

	if (status == HIT)
		extra_animation = &fly2;

	if (status == DAMAGED)
		extra_animation = &fly3;
}



void Enemy_Balloon::Shoot()
{
	if (path.steps[2].active == true || path.steps[4].active == true)
	{
		if (reload == 0 || reload == 40)
		{
			/*distance.x = App->player->position.x - position.x;
			distance.y = App->player->position.y - position.y;

			module = sqrtf(powf(distance.x, 2) + powf(distance.y, 2));

			distance.x /= module;
			distance.y /= module;

			speed.x = distance.x*BULLET_SPEED;
			speed.y = distance.y*BULLET_SPEED;*/


			App->particles->AddParticle(App->particles->smallshot, position.x + 25, position.y + 44, COLLIDER_ENEMY_SHOT, 2, 1, false);
			App->particles->AddParticle(App->particles->smallshot, position.x + 9, position.y + 44, COLLIDER_ENEMY_SHOT, -2, 1, false);
			App->particles->AddParticle(App->particles->presmallshot, position.x + 24, position.y + 43, COLLIDER_ENEMY_SHOT, 2, 1, false);
			App->particles->AddParticle(App->particles->presmallshot, position.x + 8, position.y + 43, COLLIDER_ENEMY_SHOT, -2, 1, false);

			//App->particles->AddParticle(App->particles->smallshot, position.x + 9, position.y + 44, COLLIDER_ENEMY_SHOT, speed.x, speed.y, false);

		}
		reload++;
}
	
	else if( reload != 0)
	{
		reload = 0;
	}
	
}
void Enemy_Balloon::Extra_animation()
{
	App->render->Blit(App->enemies->sprites, position.x, position.y, &(extra_animation->GetCurrentFrame()));
}
