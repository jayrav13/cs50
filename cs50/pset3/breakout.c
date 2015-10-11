//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// height and width of the game's paddle in pixels
#define PADDLE_HEIGHT 15
#define PADDLE_WIDTH 80
#define PADDLE_FLOAT 50

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // velocity
    double xVelocity = 0.0;
    double yVelocity = 0.0;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // TODO
        // create MOUSE_EVENT to keep track of pointer
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        //instantiate variable to check for collision
        GObject object = detectCollision(window, ball);
        
        // if there is an event that happened
        if (event != NULL)
        {
            // if that event was a mouse movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // establish the location of the paddle accordingly
                // y value = independent of mouse
                // x value = dependent on mouse
                double x = getX(event) - getWidth(paddle) / 2;
                double y = HEIGHT - PADDLE_HEIGHT - PADDLE_FLOAT;
                setLocation(paddle, x, y);
            }
            // if the mouse was clicked
            // set a random x and y velocity, as this would have
            // only happened at the beginning of game play, and
            // we need to start the players off.
            if(getEventType(event) == MOUSE_CLICKED)
            {
                xVelocity = drand48()*2;
                yVelocity = 2.0;
            }
        }
        
        // if there was a collision, and the object variable
        // has something in it
        if(object != NULL)
        {
            // if the object was the paddle, easy - change y direct.
            if(object == paddle)
            {
                yVelocity = -yVelocity;
            }
            // if not, if it was a "GRect", it could only be the bricks.
            else if(strcmp(getType(object),"GRect") == 0)
            {
                // remove that brick from the window, increment/decrement points/bricks, respectively.
                removeGWindow(window, object);
                points = points + 1;
                bricks = bricks - 1;
                
                // change the direction of the ball, and update scoreboard.
                yVelocity = -yVelocity;
                updateScoreboard(window, label, points);
            }
        }
        
        // react to all sides
        
        // reaction to hitting the bottom of the screen.
        if(getY(ball) + getHeight(ball) > HEIGHT)
        {
            // stop the ball, reduce life, wait for the user to click and set the
            // ball at the beginning location.
            xVelocity = 0.0;
            yVelocity = 0.0;
            lives = lives - 1;
            waitForClick();
            setLocation(ball, WIDTH/2 - 10, HEIGHT/2 - 10);
        }
        // reaction to hitting either side wall
        if(getX(ball) + getWidth(ball) > WIDTH || getX(ball) < 0)
        {
            // just go in the other direction!
            xVelocity = -xVelocity;
        }
        // reaction to hitting the top
        if(getY(ball) < 0)
        {
            // just go in the other direction!
            yVelocity = -yVelocity;
        }
        
        // move, pause ball so that you can actually "play"
        move(ball, xVelocity, yVelocity);
        pause(10);
        
    }

    // wait for click before exiting after the user loses
    waitForClick();

    // after click, game over. exit.
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    // initialize variable for bricks.
    GRect bricks;
    
    // set array for the 5 possible colors, as strings.
    string colors[5];
    colors[0] = "RED";
    colors[1] = "ORANGE";
    colors[2] = "YELLOW";
    colors[3] = "GREEN";
    colors[4] = "BLUE";
    
    // loop through all columns.
    for(int i = 0; i < COLS; i++)
    {
        // loop through all rows.
        for(int j = 0; j < ROWS; j++)
        {
            // create a new brick with equal dimensions, set the color and add.
            bricks = newGRect(i*40 + 4,j*20 + 50, (WIDTH/COLS) - 10, 15);
            setFilled(bricks, true);
            setColor(bricks, colors[j]);
            add(window, bricks);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    // establish new ball, fill it with black color, return ball.
    GOval ball = newGOval(WIDTH/2 - 10, HEIGHT/2 - 10, 20, 20);
    setFilled(ball, true);
    setColor(ball, "BLACK");
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    //establish new paddle, fill it with black color, return paddle.
    GRect paddle = newGRect(((WIDTH/2) - (PADDLE_WIDTH/2)), (HEIGHT - PADDLE_HEIGHT - PADDLE_FLOAT), PADDLE_WIDTH, PADDLE_HEIGHT);
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    // establish label for scoreboard, add it to the window, return label.
    double x, y;
    GLabel label;
    label = newGLabel("0");
    setFont(label,"SansSerif-18");
    x = (getWidth(window) - getWidth(label)) / 2;
    y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    add(window, label);
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
