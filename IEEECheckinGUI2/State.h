
#pragma once

#include <string>

//State struct to define state
struct State
{
    std::string state;

    std::string eventName, location;
    int eventNumber, points;

    State()
    {
        points = 0;
        state = "offline";
        eventName = "Default";
        location = "Default";
        eventNumber = 0;
    }

    std::string getName(){
        return eventName;
    }
    void setName(std::string EventName){
        eventName = EventName;
    }
    std::string getLocation(){
        return location;
    }
    void setLocation(std::string eventLocation){
        location = eventLocation;
    }
    int getPoints(){
        return points;
    }
    void setPoints(int Points){
        points = Points;
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


