#include<stdio.h>
#include<string.h>

int string2int(char* temp) {
  int c,val=0;

  for (c = 0; temp[c] != '\0'; c++) 
    val = val * 10 + temp[c]-'0'; 

  return val;
}


int main()
{
    char parameterUnits[]="% RH-C-ppm";
    char h[]="Humidity :";
    char t[]="Temperature :";
    char z[]="Carbon dioxide level :";
    char region[50]="India : ";
    char timeStamp[]="2021-09-27 13:25:07"; // YYYY-MM-DD hh:mm:ss
    char inputDataStream[]="H00345T01195Z00651";
    char outputDataStream[50]="",temp[50]="";
    float tempVal;
    int i=0,tempVaL,choice,n,choice1;
    char* token;

    printf("Press 1 for Timestamp with region \nPress 2 for Timestamp only \n");
    scanf("%d",&choice);
    if(choice==1){
      printf("Press 1 for Timestamp with Date only \nPress 2 for Timestamp with Date & Time both \n");
      scanf("%d",&choice1);
      if(choice1==1)
        printf("%s \n",strncat(region,timeStamp,10));

      else if(choice1==2)
       printf("%s \n",strncat(region,timeStamp,19));
      
      else
        printf("Wrong Input...\n");
    }

    if(choice==2){
      printf("Press 1 for Timestamp with Date only \nPress 2 for Timestamp with Date & Time both \n");
      scanf("%d",&choice1);
      if(choice1==1)
      printf("%s \n",strncat(temp,timeStamp,10));

      else if(choice1==2)
      printf("%s \n",strncat(temp,timeStamp,19));

      else
        printf("Wrong Input... \n");
    }

    while(inputDataStream[i]!='\0'){
        if(inputDataStream[i]=='H'){
            token =strtok(parameterUnits,"-");
            strcpy(outputDataStream,h);
            strncpy(temp,(inputDataStream+i+1),5);
            tempVal=string2int(temp)/10.0;
            printf("%s %f %s\n",outputDataStream,tempVal,token);
            token=strtok(NULL,"-");
            if(token==NULL)
              break;
            i=i+6;
        }

        if(inputDataStream[i]=='T'){
            strcpy(outputDataStream,t);
            strncpy(temp,(inputDataStream+i+1),5);
            tempVal=(string2int(temp)-1000)/10.0;
            printf("%s %f %s\n",outputDataStream,tempVal,token);
            token=strtok(NULL,"-");
            if(token==NULL)
              break;
            i=i+6;
        }      

         if(inputDataStream[i]=='Z'){
            strcpy(outputDataStream,z);
            strncpy(temp,(inputDataStream+i+1),5);
            tempVaL=string2int(temp);
            printf("%s %d %s\n",outputDataStream,tempVaL,token);
            token=strtok(NULL,"-");
            if(token==NULL)
              break;
        }                       
        
    }

}