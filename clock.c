#include <stdio.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define sleep_one_second() Sleep(1000)
#else
    #include <unistd.h>
    #define sleep_one_second() sleep(1)
#endif

int main(){
    setvbuf(stdout, NULL, _IONBF, 0);

    while (1) {
        time_t raw_time;
        struct tm *now;

        time(&raw_time);
        now = localtime(&raw_time);

    printf("\rTime: %02d:%02d:%02d", 
               now->tm_hour, 
               now->tm_min, 
               now->tm_sec);

    sleep_one_second();
    }
    return 0;
}
