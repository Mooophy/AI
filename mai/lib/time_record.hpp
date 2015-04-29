#pragma once 
#include <chrono>

namespace mai
{
    namespace utility
    {
        //
        //  class TimeRecord
        //  an RAII style timer using std::chrono in c++ 11
        //
        class TimeRecord
        {
        public:
            using Time = std::chrono::high_resolution_clock;
            using TimePoint = std::chrono::high_resolution_clock::time_point;

            explicit TimeRecord(float& dura) :
                duration_{ dura }, start_{ Time::now() }, done_{}
            { }

            ~TimeRecord()
            {
                duration_ = std::chrono::duration<float>((done_ = Time::now()) - start_).count();
            }
        private:
            float& duration_;
            TimePoint start_, done_;
        };
    }
}