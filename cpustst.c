#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
 
int main(int argC,char* argV[])
{
	char str[100];
	const char d[2] = " ";
	char* token;
	int i = 0,times,lag;
	long int sum = 0, idle, lastSum = 0,lastIdle = 0;
	float f_sum, f_idle, f_load;
	
	long double idleFraction;
 
	if(argC!=3)
		printf("Usage : %s <number of times /proc/stat should be polled followed by delay in seconds.>",argV[0]);
 
	else{
		times = atoi(argV[1]);
		lag = atoi(argV[2]);
 
		while(times>0){
			FILE* fp = fopen("/proc/stat","r");
	        i = 0;
			fgets(str,100,fp);
			fclose(fp);
			token = strtok(str,d);
 
			while(token!=NULL){
				token = strtok(NULL,d);
				if(token!=NULL){
					sum += atoi(token);
 
				if(i==3)
					idle = atoi(token);
 
				i++;
			}
		}
 
//		printf("\nIdle for : %lf %% of the time.",(1.0 - (idle-lastIdle)*1.0/(sum-lastSum))*100);
        f_idle = idle - lastIdle;
        f_sum = sum - lastSum;
        if(lastSum != 0.0){
            f_load = 100.0 - ((f_sum - f_idle) / f_sum) * 100.0;
		    printf("\nLoad: %lf %% I: %ld lI: %ld  S: %ld lS: %ld fi: %lf fs: %lf", f_load, idle, lastIdle, sum, lastSum, f_idle, f_sum);
        }
        else
            printf("\nStart cpustst...");
		lastIdle = idle;
		lastSum = sum;
 
 
		times--;
		sleep(lag);
		}
		printf("\n");	
	}
	return 0;
}

