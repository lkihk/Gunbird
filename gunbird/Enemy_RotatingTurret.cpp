#include "Application.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "Enemy_RotatingTurret.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL_timer.h"
#include <cmath>



Enemy_RotatingTurret::Enemy_RotatingTurret(int x, int y, int option) : Enemy(x, y, option)
{

	specialanimation = true;
	
	//normal base animation
	normal_base_anim.PushBack({ 506, 250, 28, 35 });
	normal_base_anim.PushBack({ 536, 249, 28, 36 });
	normal_base_anim.PushBack({ 566, 250, 28, 35 });
	normal_base_anim.PushBack({ 596, 249, 28, 36 });
	normal_base_anim.PushBack({ 626, 250, 28, 35 });
	normal_base_anim.PushBack({ 656, 250, 28, 35 }); 
	normal_base_anim.loop = true;
	normal_base_anim.speed = 0.2f;

	//hit base animation
	hit_base_anim.PushBack({ 506, 311, 28, 35 });
	hit_base_anim.PushBack({ 536, 310, 28, 36 });
	hit_base_anim.PushBack({ 566, 311, 28, 35 });
	hit_base_anim.PushBack({ 596, 310, 28, 36 });
	hit_base_anim.PushBack({ 626, 311, 28, 35 });
	hit_base_anim.PushBack({ 656, 311, 28, 35 });
	hit_base_anim.loop = true;
	hit_base_anim.speed = 0.2f;

	//damaged base animation
	damaged_base_anim.PushBack({ 506, 250, 28, 35 });
	damaged_base_anim.PushBack({ 536, 249, 28, 36 });
	damaged_base_anim.PushBack({ 566, 250, 28, 35 });
	damaged_base_anim.PushBack({ 596, 249, 28, 36 });
	damaged_base_anim.PushBack({ 626, 250, 28, 35 });
	damaged_base_anim.PushBack({ 656, 250, 28, 35 });
	damaged_base_anim.loop = true;
	damaged_base_anim.speed = 0.2f;


	down.PushBack({ 484, 384, 27, 32 });
	down_hit.PushBack({ 484, 512, 27, 32 });
	down_damaged.PushBack({ 484, 640, 27, 32 });

	downr1.PushBack({ 511, 384, 27, 32 });
	downr1_hit.PushBack({ 511, 512, 27, 32 });
	downr1_damaged.PushBack({ 511, 640, 27, 32 });

	downr2.PushBack({ 538, 384, 27, 32 });
	downr2_hit.PushBack({ 538, 512, 27, 32 });
	downr2_damaged.PushBack({ 538, 640, 27, 32 });

	downr3.PushBack({ 565, 384, 27, 32 });
	downr3_hit.PushBack({ 565, 512, 27, 32 });
	downr3_damaged.PushBack({ 565, 640, 27, 32 });

	downr4.PushBack({ 592, 384, 27, 32 });
	downr4_hit.PushBack({ 592, 512, 27, 32 });
	downr4_damaged.PushBack({ 592, 640, 27, 32 });

	downr5.PushBack({ 619, 384, 27, 32 });
	downr5_hit.PushBack({ 619, 512, 27, 32 });
	downr5_damaged.PushBack({ 619, 640, 27, 32 });

	downr6.PushBack({ 647, 384, 27, 32 });
	downr6_hit.PushBack({ 647, 512, 27, 32 });
	downr6_damaged.PushBack({ 647, 640, 27, 32 });

	downr7.PushBack({ 673, 384, 27, 32 });
	downr7_hit.PushBack({ 673, 512, 27, 32 });
	downr7_damaged.PushBack({ 673, 640, 27, 32 });

	right.PushBack({ 700, 384, 27, 32 });
	right_hit.PushBack({ 700, 512, 27, 32 });
	right_damaged.PushBack({ 700, 640, 27, 32 });

	rightu1.PushBack({ 484, 416, 27, 32 });
	rightu1_hit.PushBack({ 484, 544, 27, 32 });
	rightu1_damaged.PushBack({ 484, 672, 27, 32 });

	rightu2.PushBack({ 511, 416, 27, 32 });
	rightu2_hit.PushBack({ 511, 544, 27, 32 });
	rightu2_damaged.PushBack({ 511, 672, 27, 32 });

	rightu3.PushBack({ 538, 416, 27, 32 });
	rightu3_hit.PushBack({ 538, 544, 27, 32 });
	rightu3_damaged.PushBack({ 538, 672, 27, 32 });

	rightu4.PushBack({ 565, 416, 27, 32 });
	rightu4_hit.PushBack({ 565, 544, 27, 32 });
	rightu4_damaged.PushBack({ 565, 672, 27, 32 });

	rightu5.PushBack({ 592, 416, 27, 32 });
	rightu5_hit.PushBack({ 592, 544, 27, 32 });
	rightu5_damaged.PushBack({ 592, 672, 27, 32 });

	up.PushBack({ 619, 416, 27, 32 });
	up_hit.PushBack({ 619, 544, 27, 32 });
	up_damaged.PushBack({ 619, 672, 27, 32 });

	upl1.PushBack({ 647, 416, 27, 32 });
	upl1_hit.PushBack({ 647, 544, 27, 32 });
	upl1_damaged.PushBack({ 647, 672, 27, 32 });

	upl2.PushBack({ 673, 416, 27, 32 });
	upl2_hit.PushBack({ 673, 544, 27, 32 });
	upl2_damaged.PushBack({ 673, 672, 27, 32 });

	upl3.PushBack({ 700, 416, 27, 32 });
	upl3_hit.PushBack({ 700, 544, 27, 32 });
	upl3_damaged.PushBack({ 700, 672, 27, 32 });

	upl4.PushBack({ 484, 448, 27, 32 });
	upl4_hit.PushBack({ 484, 576, 27, 32 });
	upl4_damaged.PushBack({ 484, 704, 27, 32 });

	upl5.PushBack({ 511, 448, 27, 32 });
	upl5_hit.PushBack({ 511, 576, 27, 32 });
	upl5_damaged.PushBack({ 511, 704, 27, 32 });

	upl6.PushBack({ 538, 448, 27, 32 });
	upl6_hit.PushBack({ 538, 576, 27, 32 });
	upl6_damaged.PushBack({ 538, 704, 27, 32 });

	left.PushBack({ 565, 448, 27, 32 });
	left_hit.PushBack({ 565, 576, 27, 32 });
	left_damaged.PushBack({ 565, 704, 27, 32 });

	leftd1.PushBack({ 592, 448, 27, 32 });
	leftd1_hit.PushBack({ 592, 576, 27, 32 });
	leftd1_damaged.PushBack({ 592, 704, 27, 32 });

	leftd2.PushBack({ 619, 448, 27, 32 });
	leftd2_hit.PushBack({ 619, 576, 27, 32 });
	leftd2_damaged.PushBack({ 619, 704, 27, 32 });

	leftd3.PushBack({ 647, 448, 27, 32 });
	leftd3_hit.PushBack({ 647, 576, 27, 32 });
	leftd3_damaged.PushBack({ 647, 704, 27, 32 });

	leftd4.PushBack({ 673, 448, 27, 32 });
	leftd4_hit.PushBack({ 673, 576, 27, 32 });
	leftd4_damaged.PushBack({ 673, 704, 27, 32 });

	leftd5.PushBack({ 700, 448, 27, 32 });
	leftd5_hit.PushBack({ 700, 576, 27, 32 });
	leftd5_damaged.PushBack({ 700, 704, 27, 32 });

	leftd6.PushBack({ 484, 480, 27, 32 });
	leftd6_hit.PushBack({ 484, 608, 27, 32 });
	leftd6_damaged.PushBack({ 484, 736, 27, 32 });

	dead.PushBack({ 426, 428, 32, 33 });

	
	collider = App->collision->AddCollider({ 0, 0, 28, 36 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	animation = &normal_base_anim;

	extra_animation = &down;

	if (option == 0)
	{ 
		path.PushBack({ 0.0f, 0.4f }, 2400); 
		path.PushBack({ 0.66f, 0.4f },10000);
	}//stand
	if (option == 1)	
	{ 

		path.PushBack({ 0.0f, 0.4f }, 2100);
		path.PushBack({ 0.0f, 0.6f }, 300);
		path.PushBack({ 0.66f, 0.6f }, 10000);
		
	}//move down
	if (option == 2)	//move right
	{
		path.PushBack({ 0.0f, 0.4f }, 2400);
		path.PushBack({ 0.99f ,0.4f }, 100000);
	}

	

	original_pos.x = x;
	original_pos.y = y;

	hp = 2.0f;
	damaged_hp = 1.0f;
	death_type = SMALL_ENEMY;
	dead_anim = true;
	flying = false;
	killscore = 500;
}

void Enemy_RotatingTurret::Move()
{
	position = original_pos + path.GetCurrentPosition();
	
	if (anim_type == DEAD)
	{
		path.Stop();
		if (App->enemies->xcrolling == 1)
		path.PushBack({ 0.66f, 0.4f }, 10000);
		else if (App->enemies->xcrolling == 0)
			path.PushBack({ 0.0f, 0.4f }, 10000);
		else if (App->enemies->xcrolling == 2)
			path.PushBack({ 0.0f, 0.0f }, 10000);
		else if(App->enemies->xcrolling == 3)
			path.PushBack({ 0.66f, 0.4f }, 10000);
		else if (App->enemies->xcrolling == 4)
			path.PushBack({ 0.0f, 0.0f }, 10000);
		else
			path.PushBack({ 0.0f, 0.4f }, 10000);

	}

	if (hp <= 0) anim_type = DEAD;

	if (status == NORMAL) { animation = &normal_base_anim; }
	if (status == HIT) { animation = &hit_base_anim; }
	if (status == DAMAGED) 
	{
		if (counter == 0)
			animation = &damaged_base_anim;
		else
			animation = &normal_base_anim;
	}
	
	
	angle = AngleCalc(App->player->position, position);

	if (counter == 20)
		counter = 0;

	if (angle > 7.5 && angle <= 22.5)
	{
		if (status == NORMAL) { extra_animation = &	rightu1; }
		if (status == HIT) { extra_animation = &rightu1_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &rightu1_damaged;
			else
				extra_animation = &rightu1;
		}
	}
	else if (angle > 22.5 && angle <= 37.5)
	{
		if (status == NORMAL) { extra_animation = &rightu2; }
		if (status == HIT) { extra_animation = &rightu2_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &rightu2_damaged;
			else
				extra_animation = &rightu2;
		}
	}
	else if (angle > 37.5 && angle <= 52.5)
	{
		if (status == NORMAL) { extra_animation = &rightu3; }
		if (status == HIT) { extra_animation = &rightu3_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &rightu3_damaged;
			else
				extra_animation = &rightu3;
		}
	}
	else if (angle > 52.5 && angle <= 67.5)
	{
		if (status == NORMAL) { extra_animation = &rightu4; }
		if (status == HIT) { extra_animation = &rightu4_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &rightu4_damaged;
			else
				extra_animation = &rightu4;
		}
	}
	else if (angle > 67.5 && angle <= 82.5)
	{
		if (status == NORMAL) { extra_animation = &rightu5; }
		if (status == HIT) { extra_animation = &rightu5_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &rightu5_damaged;
			else
				extra_animation = &rightu5;
		}
	}
	else if (angle > 82.5 && angle <= 96.43)
	{
		if (status == NORMAL) { extra_animation = &up; }
		if (status == HIT) { extra_animation = &up_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &up_damaged;
			else
				extra_animation = &up;
		}
	}
	else if (angle > 96.43 && angle <= 109.29)
	{
		if (status == NORMAL) { extra_animation = &upl1; }
		if (status == HIT) { extra_animation = &upl1_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &upl1_damaged;
			else
				extra_animation = &upl1;
		}
	}
	else if (angle > 109.29 && angle <= 122.15)
	{
		if (status == NORMAL) { extra_animation = &upl2; }
		if (status == HIT) { extra_animation = &upl2_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &upl2_damaged;
			else
				extra_animation = &upl2;
		}
	}
	else if (angle > 122.15 && angle <= 135.01)
	{
		if (status == NORMAL) { extra_animation = &upl3; }
		if (status == HIT) { extra_animation = &upl3_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &upl3_damaged;
			else
				extra_animation = &upl3;
		}
	}
	else if (angle > 135.01 && angle <= 147.87)
	{
		if (status == NORMAL) { extra_animation = &upl4; }
		if (status == HIT) { extra_animation = &upl4_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &upl4_damaged;
			else
				extra_animation = &upl4;
		}
	}
	else if (angle > 147.87 && angle <= 160.73)
	{
		if (status == NORMAL) { extra_animation = &upl5; }
		if (status == HIT) { extra_animation = &upl5_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &upl5_damaged;
			else
				extra_animation = &upl5;
		}
	}
	else if (angle > 160.73 && angle <= 173.59)
	{
		if (status == NORMAL) { extra_animation = &upl6; }
		if (status == HIT) { extra_animation = &upl6_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &upl6_damaged;
			else
				extra_animation = &upl6;
		}
	}
	else if (angle > 173,59 && angle <= 186.43)
	{
		if (status == NORMAL) { extra_animation = &left; }
		if (status == HIT) { extra_animation = &left_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &left_damaged;
			else
				extra_animation = &left;
		}
	}
	else if (angle > 186.43 && angle <= 199.29)
	{
		if (status == NORMAL) { extra_animation = &leftd1; }
		if (status == HIT) { extra_animation = &leftd1_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &leftd1_damaged;
			else
				extra_animation = &leftd1;
		}
	}
	else if (angle > 199.29 && angle <= 212.15)
	{
		if (status == NORMAL) { extra_animation = &leftd2; }
		if (status == HIT) { extra_animation = &leftd2_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &leftd2_damaged;
			else
				extra_animation = &leftd2;
		}
	}
	else if (angle > 212.15 && angle <= 225.01)
	{
		if (status == NORMAL) { extra_animation = &leftd3; }
		if (status == HIT) { extra_animation = &leftd3_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &leftd3_damaged;
			else
				extra_animation = &leftd3;
		}
	}
	else if (angle > 225.01 && angle <= 237.87)
	{
		if (status == NORMAL) { extra_animation = &leftd4; }
		if (status == HIT) { extra_animation = &leftd4_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &leftd4_damaged;
			else
				extra_animation = &leftd4;
		}
	}
	else if (angle > 237.87 && angle <= 250.73)
	{
		if (status == NORMAL) { extra_animation = &leftd5; }
		if (status == HIT) { extra_animation = &leftd5_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &leftd5_damaged;
			else
				extra_animation = &leftd5;
		}
	}
	else if (angle > 250.73 && angle <= 263.59)
	{
		if (status == NORMAL) { extra_animation = &leftd6; }
		if (status == HIT) { extra_animation = &leftd6_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &leftd6_damaged;
			else
				extra_animation = &leftd6;
		}
	}
	else if (angle > 263.59 && angle <= 275.625)
	{
		if (status == NORMAL) { extra_animation = &down; }
		if (status == HIT) { extra_animation = &down_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &down_damaged;
			else
				extra_animation = &down;
		}
	}
	else if (angle > 275.625 && angle <= 286.875)
	{
		if (status == NORMAL) { extra_animation = &downr1; }
		if (status == HIT) { extra_animation = &downr1_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &downr1_damaged;
			else
				extra_animation = &downr1;
		}
	}
	else if (angle > 286.875 && angle <= 298.125)
	{
		if (status == NORMAL) { extra_animation = &downr2; }
		if (status == HIT) { extra_animation = &downr2_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &downr2_damaged;
			else
				extra_animation = &downr2;
		}
	}
	else if (angle > 298.125 && angle <= 309.375)
	{
		if (status == NORMAL) { extra_animation = &downr3; }
		if (status == HIT) { extra_animation = &downr3_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &downr3_damaged;
			else
				extra_animation = &downr3;
		}
	}
	else if (angle > 309.375 && angle <= 320.625)
	{
		if (status == NORMAL) { extra_animation = &downr4; }
		if (status == HIT) { extra_animation = &downr4_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &downr4_damaged;
			else
				extra_animation = &downr4;
		}
	}
	else if (angle > 320.625 && angle <= 331.875)
	{
		if (status == NORMAL) { extra_animation = &downr5; }
		if (status == HIT) { extra_animation = &downr5_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &downr5_damaged;
			else
				extra_animation = &downr5;
		}
	}
	else if (angle > 331.875 && angle <= 343.125)
	{
		if (status == NORMAL) { extra_animation = &downr6; }
		if (status == HIT) { extra_animation = &downr6_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &downr6_damaged;
			else
				extra_animation = &downr6;
		}
	}
	else if (angle > 343.125 && angle <= 354.375)
	{
		if (status == NORMAL) { extra_animation = &downr7; }
		if (status == HIT) { extra_animation = &downr7_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &downr7_damaged;
			else
				extra_animation = &downr7;
		}
	}
	else
	{
		if (status == NORMAL) { extra_animation = &right; }
		if (status == HIT) { extra_animation = &right_hit; }
		if (status == DAMAGED)
		{
			if (counter == 0)
				extra_animation = &right_damaged;
			else
				extra_animation = &right;
		}
	}

	counter++;

	if (status == NORMAL)
		animation = &normal_base_anim;

	if (status == HIT)
		animation = &hit_base_anim;
	if (status == DAMAGED)
	{
		if (counter == 0)
			animation = &damaged_base_anim;
		else
			animation = &normal_base_anim;
	}

	if (hp <= 0)
	{
		animation = &dead;
		collider->rect.h = 0;
		collider->rect.y = -100;
		collider->rect.x = 1000;
		collider->rect.w = 0;
	}

}

void Enemy_RotatingTurret::Special_animation()
{
	

	if (hp > 0)
	App->render->Blit(App->enemies->sprites, position.x + 1, position.y - 10, &(extra_animation->GetCurrentFrame()));
		//flag2.GetCurrentFrame();
		//flag3.GetCurrentFrame();

	/*if (status == HIT)
	{
		App->render->Blit(App->enemies->sprites, position.x + 29, position.y - 15, &flag2.GetCurrentFrame());
		flag.GetCurrentFrame();
		flag3.GetCurrentFrame();
	}

	if (status == DAMAGED)
	{
		App->render->Blit(App->enemies->sprites, position.x + 29, position.y - 15, &flag3.GetCurrentFrame());
		flag.GetCurrentFrame();
		flag2.GetCurrentFrame();
	}*/

}
void Enemy_RotatingTurret::Shoot()
{
	if (position.y > 0 && position.y < SCREEN_HEIGHT && reloadd == 0 && anim_type != DEAD)
	{
		bullet_speed = ShootCalculator({ position.x + 5, position.y + 10 }, { App->player->position.x, App->player->position.y });
		App->particles->AddParticle(App->particles->smallshot, position.x + 5, position.y + 10, COLLIDER_ENEMY_SHOT, bullet_speed.x/1.5, bullet_speed.y/1.5);
	}
	reloadd++;
	if (reloadd == 60) reloadd = 0;
	//App->particles->AddParticle(App->particles->smallshot, position.x + 9, position.y + 44, COLLIDER_ENEMY_SHOT, speed.x, speed.y, false);


	
}