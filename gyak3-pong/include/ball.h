#ifndef BALL_H
#define BALL_H

/**
 * Ball position and speed
 */
typedef struct Ball
{
    float x;
    float y;
    float rotation;
    float radius;
    float speed_x;
    float speed_y;
    float rot_speed;
} Ball;

/**
 * Move the ball to the given position.
 */
void init_ball(Ball* ball, float x, float y);

/**
 * Update the ball.
 * @param time elapsed time in seconds.
 */
void update_ball(Ball* ball, double time);

/**
 * Render the ball.
 */
void render_ball(Ball* ball);

void resize_ball(Ball* ball, float size);

#endif /* BALL_H */
