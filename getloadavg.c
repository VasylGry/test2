/*  getloadavg example  */
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{

double load[3];  
    
   if (getloadavg(load, 3) != -1)
   {  
        printf("load average : %f , %f , %f\n", load[0],load[1],load[2]);
   }

}
