#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

#include "Time.hpp"

GLD::Time::Time() {
    _init_time  = std::chrono::high_resolution_clock::now();
    _last_frame = std::chrono::high_resolution_clock::now();
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
