#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

namespace GLD 
{

////////////////////////////////////////////////////////////
/// \brief to use time functions
////////////////////////////////////////////////////////////
class Time {
private:
    std::chrono::high_resolution_clock::time_point _init_time;
    std::chrono::high_resolution_clock::time_point _last_frame;
    double _delta_time;

public:

    /////////////////////////////////////////////////////////////////
    /// \brief determining window startup time. PUT IT IN INIT TIME
    /////////////////////////////////////////////////////////////////
    Time();

    ////////////////////////////////////////////////////////////
    /// \brief  get the current time based on init time
    ////////////////////////////////////////////////////////////
    double getTime();

    ////////////////////////////////////////////////////////////
    /// \brief PUT IT IN FRAME INICIALIZATION!!!
    ////////////////////////////////////////////////////////////
    void getFrameInit();

    ////////////////////////////////////////////////////////////
    /// \brief get the time variation between the 2 last frames
    ////////////////////////////////////////////////////////////
    double getDeltaTime();
};

}

GLD::Time::Time() {
    _init_time = std::chrono::high_resolution_clock::now();
};

double GLD::Time::getTime() {
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::duration<double>>(now - _init_time).count();
};

void GLD::Time::getFrameInit(){
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    _delta_time = std::chrono::duration_cast<std::chrono::duration<double>>(now - _last_frame).count();
    _last_frame = std::chrono::high_resolution_clock::now();
}

double GLD::Time::getDeltaTime() {
    return _delta_time;
}