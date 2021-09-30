#include<stdio.h>

char* my_strcpy(char *destination, char *source)
{
    char *start = destination;

    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; 
    return start;
}


char* my_strncpy(char *destination, char *source,size_t n)
{
    char *start = destination;

    while(*source && n--)
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; 
    return start;
}

char* my_strncat(char* dest, const char* src, size_t num)
{
    int i, j;
 
    for (i = 0; dest[i] != '\0'; i++);
 
    for (j = 0; src[j] != '\0' || j < num; j++) 
        dest[i + j] = src[j];
 
    dest[i + j] = '\0';
 
    return dest;
}


char* my_strtok(char* s, char* d)
{
    static char* input = NULL;
    int i;
  
    if (s != NULL)
        input = s;
  
    if (input == NULL)
        return NULL;
  
    char* result = (char*) malloc((strlen(input) + 1)*sizeof (char));
  
    for (i = 0; input[i] != '\0'; i++){
        if (input[i] != d)
            result[i] = input[i];
  
        else 
        {
            result[i] = '\0';
            input = input + i + 1;
            return result;
        }
    }
  
    result[i] = '\0';
    input = NULL;

    return result;
}


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
        printf("%s \n",my_strncat(region,timeStamp,10));

      else if(choice1==2)
       printf("%s \n",my_strncat(region,timeStamp,19));
      
      else
        printf("Wrong Input...\n");
    }

    if(choice==2){
      printf("Press 1 for Timestamp with Date only \nPress 2 for Timestamp with Date & Time both \n");
      scanf("%d",&choice1);
      if(choice1==1)
      printf("%s \n",my_strncat(temp,timeStamp,10));

      else if(choice1==2)
      printf("%s \n",my_strncat(temp,timeStamp,19));

      else
        printf("Wrong Input... \n");
    }

    while(inputDataStream[i]!='\0'){
        if(inputDataStream[i]=='H'){
            token =my_strtok(parameterUnits,"-");
            my_strcpy(outputDataStream,h);
            my_strncpy(temp,(inputDataStream+i+1),5);
            tempVal=string2int(temp)/10.0;
            printf("%s %f %s\n",outputDataStream,tempVal,token);
            token=my_strtok(NULL,"-");
            if(token==NULL)
              break;
            i=i+6;
        }

        if(inputDataStream[i]=='T'){
            my_strcpy(outputDataStream,t);
            my_strncpy(temp,(inputDataStream+i+1),5);
            tempVal=(string2int(temp)-1000)/10.0;
            printf("%s %f %s\n",outputDataStream,tempVal,token);
            token=my_strtok(NULL,"-");
            if(token==NULL)
              break;
            i=i+6;
        }      

         if(inputDataStream[i]=='Z'){
            my_strcpy(outputDataStream,z);
            my_strncpy(temp,(inputDataStream+i+1),5);
            tempVaL=string2int(temp);
            printf("%s %d %s\n",outputDataStream,tempVaL,token);
            token=my_strtok(NULL,"-");
            if(token==NULL)
              break;
        }                       
        
    }

}