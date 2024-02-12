#include <iostream>

using namespace std;

#define MAXSIZE 19
#define X_MAXSIZE MAXSIZE
#define Y_MAXSIZE MAXSIZE

const unsigned int UP = 1;
const unsigned int RIGHT = 2;
const unsigned int DOWN = 4;
const unsigned int LEFT = 8;

#if 0
class Robot
{
    private:
        unsigned int x;
        unsigned int y;
        unsigned int direction;
    public:
        Robot():x(0),y(1),direction(RIGHT)
        {

        }
        ~Robot()
        {

        }
        /* History ? */
};
#endif

class Maze
{
    public:
        Maze()
        {

        };

        ~Maze()
        {

        };

        unsigned int GetShape(unsigned int x, unsigned int y);
        void DrawMaze(unsigned int shape);

        /* Make mouse move forward. */
        void Forward(int &x, int &y, int direction);

        /* Check if mouse is in maze. */
        bool StillInMaze(int x, int y);

        /* Check if wall is in front of mouse. */
        int WallAhead(int x, int y, int direction);

        void TurnLeft(int direction);
        void TurnRight(int direction);

        /* 
         * right hand on wall algorithm as below. 
         * 1. Go forward
         * 2. If it is still in maze,
         *  2.1 Turn 90 degrees clockwise(to the right.)
         *  2.2 If there's wall in front of it,
         *      2.2.1 Turn 90 degrees counterclockwise(to the left).
         *  2.3 Go forward.
         *  2.4 Go to ".2"
         * 3. Success to exit Maze.
         * */
        void RightHandOnWall(int x, int y, int direction);

    private:
        /* 1: Wall, 0: Way */
        bool _mazeArray[Y_MAXSIZE][X_MAXSIZE] = 
                          /* Left 0, 1  2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18 Right */
                          { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, /* 0 Up */
                            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 }, /* 1 */
                            { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 }, /* 2 */
                            { 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 }, /* 3 */
                            { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 }, /* 4 */
                            { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 }, /* 5 */
                            { 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 }, /* 6 */
                            { 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, /* 7 */
                            { 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, /* 8 */
                            { 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, /* 9 */
                            { 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, /* 10 */
                            { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1 }, /* 11 */
                            { 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1 }, /* 12 */
                            { 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 }, /* 13 */
                            { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 }, /* 14 */
                            { 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 }, /* 15 */
                            { 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1 }, /* 16 */
                            { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, /* 17 */
                            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } }; /* 18 Down*/
};

/* It returns shape of wall */
unsigned int Maze::GetShape(unsigned int x, unsigned int y)
{
    unsigned int ret = 0;

    if(_mazeArray[y][x])
    {
        if (y > 0 && _mazeArray[y-1][x])
            ret |= UP;
        if (y < Y_MAXSIZE -1 && _mazeArray[y+1][x])
            ret |= DOWN;
        if (x > 0 && _mazeArray[y][x-1])
           ret |= LEFT;
        if (x < X_MAXSIZE - 1 && _mazeArray[y][x+1])
           ret |= RIGHT; 
    }

    return ret;
}

void Maze::DrawMaze(unsigned int shape)
{
    switch (shape)
    {

        default:
        break;
    }
}

/* Check if mouse is in maze. */
bool Maze::StillInMaze(int x, int y)
{

    return true;
}

/* Check if wall is in front of mouse. */
int Maze::WallAhead(int x, int y, int direction)
{
    return 0;
}

void Maze::TurnLeft(int direction)
{
    return;
}

void Maze::TurnRight(int direction)
{
    return;
}

/* 
 * right hand on wall algorithm as below. 
 * 1. Go forward
 * 2. If it is still in maze,
 *  2.1 Turn 90 degrees clockwise(to the right.)
 *  2.2 If there's wall in front of it,
 *      2.2.1 Turn 90 degrees counterclockwise(to the left).
 *  2.3 Go forward.
 *  2.4 Go to ".2"
 * 3. Success to exit Maze.
 * */
void Maze::RightHandOnWall(int x, int y, int direction)
{

}

int main()
{

	return 0;
}
