#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int posNum = 0;
    pid_t numID;
 
    printf("Sayiyi giriniz: ");
    scanf("%d", &posNum);
    if(posNum < 0){
        printf("Pozitif bir sayi giriniz !!! = ");
        scanf("%d", &posNum);
    }
    numID = fork(); 
    if(numID == 0){
        do{
        	if(posNum % 2 != 0)
          	posNum = (posNum * 3) + 1;
        	else if(posNum % 2 == 0)
          	posNum = posNum / 2;
	        printf("%d\n", posNum);
        }
        while(posNum != 1);
    }
    else{
        printf("pid %d \n", numID);
        wait(NULL);
    }
    
    return EXIT_SUCCESS;   
}
