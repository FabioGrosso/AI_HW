#include <iostream>
#include "Agent.h"

using namespace std;

Agent::Agent ()
{

}

Agent::~Agent ()
{

}

void Agent::Initialize ()
{
    worldState.worldSize = 4;
    worldState.agentHasArrow = true;
    worldState.agentHasGold = false;
    worldState.agentLocation = Location(1,1);
    worldState.agentOrientation = RIGHT;
}

Action Agent::Process (Percept& percept)
{
    Action action;
//    cout<<"\nPos :["<< worldState.agentLocation.X << ","<< worldState.agentLocation.Y<<"]\n";
    if(percept.Glitter)
    {
        action = GRAB;
        worldState.agentHasGold = true; // got gold
    }else if (worldState.agentHasGold && (worldState.agentLocation == Location(1,1)))
    {
        action = CLIMB;
    }else if(worldState.agentLocation.X == 4 && worldState.agentHasArrow && worldState.agentOrientation == UP)
    {
        action = SHOOT;
        worldState.agentHasArrow = false; // arrow used
    }else if(worldState.agentLocation.Y == 4 && worldState.agentHasArrow && worldState.agentOrientation == RIGHT)
    {
        action = SHOOT;
        worldState.agentHasArrow = false; // arrow used
    }else{
        int r = (rand() % 3)+ 1;; // 1 to 3 random number
        if(r==1)
        {
            action = TURNLEFT; // turn and update Ori
            if(worldState.agentOrientation == RIGHT)
            {
                worldState.agentOrientation = UP;
            }else if(worldState.agentOrientation == UP)
            {
                worldState.agentOrientation = LEFT;
            }else if(worldState.agentOrientation == LEFT)
            {
                worldState.agentOrientation = DOWN;
            }else if(worldState.agentOrientation == DOWN)
            {
                worldState.agentOrientation = RIGHT;
            }
        }else if(r==2)
        {
            action = TURNRIGHT; // turn and update Ori
            if(worldState.agentOrientation == RIGHT)
            {
                worldState.agentOrientation = DOWN;
            }else if(worldState.agentOrientation == DOWN)
            {
                worldState.agentOrientation = LEFT;
            }else if(worldState.agentOrientation == LEFT)
            {
                worldState.agentOrientation = UP;
            }else if(worldState.agentOrientation == UP)
            {
                worldState.agentOrientation = RIGHT;
            }
        }else if(r==3)
        {
            action = GOFORWARD; // move on and update position
            if(worldState.agentOrientation == RIGHT && worldState.agentLocation.X < worldState.worldSize)
            {
                worldState.agentLocation.X +=1;
            }else if(worldState.agentOrientation == UP && worldState.agentLocation.Y < worldState.worldSize)
            {
                worldState.agentLocation.Y +=1;
            }else if(worldState.agentOrientation == LEFT && worldState.agentLocation.X > 1)
            {
                worldState.agentLocation.X -=1;
            }else if(worldState.agentOrientation == DOWN && worldState.agentLocation.Y > 1)
            {
                worldState.agentLocation.Y -=1;
            }
        }
    }
    return action;
}

void Agent::GameOver (int score)
{

}