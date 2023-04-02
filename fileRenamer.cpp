#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string fileType, oldname, newname;
    int startIndex, endIndex, increase;

    cout << "Shalom To File Renamer" << endl
         << "----------------------" << endl;
    
    cout << "Enter Type of Files To Be Renamed : ";
    cin >> fileType;
    
    fileType = "." + fileType;
    
    do {
        cout << "Enter Starting File Name Index Number: ";
        cin >> startIndex;

        cout << "Enter Ending File Name Index Number: ";
        cin >> endIndex;
        
        if (endIndex - startIndex + 1 > 999) {
            cout << "Number of files you wish to rename exceeds Maximum allowable file batch size which is maximum 999 file per proccess!" << endl;
        }
    }
    while (endIndex - startIndex + 1 > 999);
        

    cout << "Enter How Much you want to increase each file name as a number: ";
    cin >> increase;

    for(int i = startIndex; i <= endIndex; ++i)
    {
        oldname = to_string(i) + fileType;
        newname = to_string(increase + i) + fileType;

        if(rename(oldname.c_str(), newname.c_str()) != 0)
            cout << "Error occured while renaming " << i << fileType << endl;
    }

    return 0;
}
