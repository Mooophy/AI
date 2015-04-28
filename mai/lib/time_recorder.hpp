#pragma once 
#include <chrono>

namespace mai
{
    namespace utility
    {
        class TimeRecorder
        {
        public:
            using Time = std::chrono::high_resolution_clock;
            using TimePoint = std::chrono::high_resolution_clock::time_point;

            explicit TimeRecorder(float& dura) :
                duration_{ dura }, start_{ Time::now() }, done_{}
            { }

            ~TimeRecorder()
            {
                duration_ = std::chrono::duration<float>((done_ = Time::now()) - start_).count();
            }
        private:
            float& duration_;
            TimePoint start_, done_;
        };
    }
}