#include<iostream> 
#include<queue> 
using namespace std;

void showq(queue<string> dataStream)
{
    queue<string> DS = dataStream;
    while(!DS.empty()){
        cout << DS.front();
        DS.pop();
    }
}

int main(){
    queue<string> mainDataStream,backupDataStream;

    char dataByte1[]="ABC\n";
    char dataByte2[]="DEF\n";
    char dataByte3[]="GHI\n";
    char dataByte4[]="JKL\n";

    char backupDataByte[]="Data Backed Up";

    cout<<"Data Stream ::\n";
    
    mainDataStream.push(dataByte1);
    mainDataStream.push(dataByte2);
    mainDataStream.push(dataByte3);
    mainDataStream.push(dataByte4);

    backupDataStream.push(backupDataByte);
   
    mainDataStream.swap(backupDataStream);

    showq(backupDataStream);

    if(mainDataStream.size()==1)
      cout<<"Data Backed Up Successfully !!!";
}
   