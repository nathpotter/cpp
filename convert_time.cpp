#include <iostream>
#include <conio.h>
#include <ctime>

#define UTC (+7)

using namespace std;

int main()
{
	time_t curr_time; //Ex. Jan 01, 2023 (Long value)
	tm * curr_tm; //Separated by time structure (tm)

	char date_string[100];
	char time_string[100];
	
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	
	strftime(date_string, sizeof(date_string), "Canada date is %A, %d %B %Y", curr_tm);
	strftime(time_string, sizeof(time_string), "Canada time is %H:%M:%S", curr_tm);
	
	cout << date_string << endl;
	cout << time_string << endl;

    time_t rawtime;
    struct tm * ptm;

    time(&rawtime);
    ptm = gmtime(&rawtime);

    puts ("Current time around the World:");
    char str_date[256];
    strftime(str_date, sizeof(str_date), "%A, %d %B %Y", ptm);
    printf("Asian (Thailand) Date: %s\n", str_date);
    printf ("Asian (Thailand) Time:  %2d:%02d:%02d\n", (ptm->tm_hour+UTC)%24, ptm->tm_min, ptm->tm_sec);

    return 0;
}