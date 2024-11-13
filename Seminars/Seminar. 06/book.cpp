#include <vector>
#include <iostream>
#include <queue>

class MyCalendar 
{
private:

    std::vector<std::vector<int>> events;

public:

    MyCalendar() {}

    bool book(int startTime, int endTime) 
    {

        for (const auto& event : events) 
        {

            if (startTime < event[1] && endTime > event[0]) return false;

        }
 
        events.push_back({ startTime, endTime });
        return true;

    }

};
