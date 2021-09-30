#include<iostream> 
#include<queue> 
using namespace std;

void showq(queue<string> ProcessMessages)
{
    queue<string> PM = ProcessMessages;
        cout << '\n' << PM.front();
}

int main(){
    int pass,x;
    char str[20];
    char message_1[]="Open Connection Request";
    char message_2[]="Enter the Passcode";
    char message_3[]="Sensor can send datastream now";
    char message_4[]="Close Connection Request";
    queue<string> ProcessMessages;

     ProcessMessages.push(message_1);
     showq(ProcessMessages);
     ProcessMessages.pop(); 
     cout<<"\nConnection build successfully !!!\n";

     ProcessMessages.push(message_2);
     showq(ProcessMessages); 
     cin>>pass;
     ProcessMessages.pop();
     cout<<"\nPasscode entered successfully !!!\n";

     ProcessMessages.push(message_3);
     showq(ProcessMessages);
     ProcessMessages.pop();
     cout<<"\n";

     ProcessMessages.push(message_4);
     showq(ProcessMessages);
     ProcessMessages.pop();
     cout<<"\nConnection terminated successfully !!!";
    

}