#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>

class Timer
{
    private:
        std::thread Thread;
        bool Alive = false; //state of the timer
        long CallNumber = -1L;  //number of times we will call a certain function
        long repeat_count = -1L;
        std::chrono::milliseconds interval = std::chrono::milliseconds(0);  //intervalo de default 0
        std::function<void(void)> funct = nullptr  ; //similar to a pointer to a function

        void SleepAndRun()
        {
            std::this_thread::sleep_for(interval); //bloquea el thread por un rato
            if(Alive)
                Function()();  //  el primero llama a la funcion Funcion, el segundo llama a la funcion que DEVUELVE Funcion.
        }

        void ThreadFunc() //ya me perdi, voy a revisar esto en otro momento.!!!!!!!!
        {
            if (CallNumber == Infinite)
                while(Alive)
                    SleepAndRun();
            else
                while(repeat_count--)
                    SleepAndRun();
        }
    public:
        static const long Infinite = -1L;

        Time(){}

        Timer(const std::function<void(void> &f) : funct(f) {}

        Timer(const std::function<void(void> &f,
              const unsigned long &i,
              const long repeat = Timer::Infinite) : funct(f) interval(std::chrono::milliseconds(i)),CallNumber(repeat) {}
};
#endif // TIMER_H
