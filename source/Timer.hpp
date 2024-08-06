#pragma once
#include <chrono>
#include <fstream>

class Timer
{
    public:
        Timer(const char* file_path)
        {
            file.open(file_path, std::ios::boolalpha);
            m_StartTimepoint = std::chrono::high_resolution_clock::now();
        }

        ~Timer()
        {
            auto endTimepoint = std::chrono::high_resolution_clock::now();

            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
            auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

            auto duration = end - start;
            double ms = duration * 0.001;


            file << duration << "us (" << ms << "ms)" << std::endl;
            printf("%lluus (%.3fms)\n", duration, ms);
        }
    
    private:
        std::ofstream file;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};