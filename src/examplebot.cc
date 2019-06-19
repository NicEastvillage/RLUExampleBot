#include "rlbot/bot.h"

Bot::Bot(int _index, int _team, std::string _name)
{
}

Input Bot::GetOutput(Game game)
{
    Input controller;

    controller.throttle = 1;

    vec3 target_local = dot(game.ball.x - game.my_car->x, game.my_car->o);
    float angle = atan2(target_local[1], target_local[0]);
    controller.steer = clip(3.0f * angle, -1.0f, 1.0f);

	return controller;
}
