
#pragma once

#include <string>

//State struct to define state
struct State
{
    std::string state;

    State()
    {
        state = "offline";
    }

    void setOnlineMode()
    {
        state = "online";
    }
    void setOfflineMode()
    {
        state = "offline";
    }

    std::string GetState()
    {
        return state;
    }

    bool isOnline()
    {
        if(state == "online")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


