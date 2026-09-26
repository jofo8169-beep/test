#include "../code_2/CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{

     // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
     // DO NOT MODIFY ABOVE.

    // TODO
    CUSatelliteNetwork network;
    int choice = 0;
    while(choice !=5) {
        displayMenu();
        cin >> choice;
    
    if(choice ==1) {
        network.loadDefaultSetup();
        network.printNetwork();
    }else if(choice==2){
        network.printNetwork();
    }else if(choice ==3){
        string receiver;
        cout<< "Enter name of the recipient to receive the message: " <<endl;
        cin>>receiver;
        cout<<endl;
        network.transmitInfo(receiver);
    }else if(choice ==4) {
        string newName;
        string previous;
        int nDistance;
        cout<< "Enter a new satellite name: " <<endl;
        cin >> newName;
        cout <<"Enter distance of satellite from earth: " <<endl;
        cin>>nDistance;
        cout << "Enter the previous satellite name (or First): " <<endl;
        cin >>previous;

        for(int i =0; i<newName.length(); i++) {
            newName[i] = toupper(newName[i]);
        }

        while(previous!="First" && network.searchForSatellite(previous) ==nullptr) {
            cout << "INVALID(previous satellite name)...Please enter a VALID satellite name!" <<endl;
            cin>>previous;
        }
            if(previous == "First") {
                network.addSatelliteInfo("", newName, nDistance);
            }else{
                network.addSatelliteInfo(previous, newName, nDistance);
            }
            network.printNetwork();
        }else if(choice == 5) {
        cout << "Quitting..." <<endl;
    }
    }
    cout << "Goodbye!" <<endl;
    return 0;
}




/************************************************
           Definitions for main_2.cpp
************************************************/
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option: " << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Broadcast Info " << endl;
    cout << " 4. Add Satellite " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
