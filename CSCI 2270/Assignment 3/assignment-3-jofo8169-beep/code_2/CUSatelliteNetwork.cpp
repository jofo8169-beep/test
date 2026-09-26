/********************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/********************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*     This class uses a linked-list of satellite structs to        */
/*     represent communication paths between satellites             */
/********************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

/*
 * Purpose: Add a new satellite to the network
 *   between the satellite *previous and the satellite that follows it in the network.
 * @param previous - name of the satellite that comes before the new satellite
 * @param satelliteName - name of the new satellite
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) {
    // TODO
    CUSatellite* newNode = new CUSatellite; 
    newNode->name = satelliteName;
    newNode->distanceFromEarth = distance;
    newNode->numberMessages =0;
    newNode->message = "";
    if(previous == "") {
        newNode->next = head;
        head = newNode;
        cout << "adding: " << satelliteName << " (HEAD)" <<endl;
    }else{
        CUSatellite* previousNode = head;
        while(previousNode != nullptr && previousNode->name !=previous) {
            previousNode = previousNode->next;
        }
            if(previousNode == nullptr){
                cout<< "Cannot add new node; previous node not found\n" << endl;
                delete newNode;
                return;
            }
            newNode->next = previousNode->next;
            previousNode->next = newNode;
            cout << "adding: "<<satelliteName << " (prev: " <<previousNode->name << ")" << endl;
        

    }
}


/*
 * Purpose: populates the network with the predetermined satellites
 * @param none
 * @return none
 */

void CUSatelliteNetwork::loadDefaultSetup(){
    // TODO 
    addSatelliteInfo("", "MAVEN", 9);
    addSatelliteInfo("", "JUNO", 4);
    addSatelliteInfo("", "PIONEER", 5);
    addSatelliteInfo("", "GALILEO", 6);
    addSatelliteInfo("", "KEPLER", 10);
    addSatelliteInfo("", "TESS", 2);

}


/*
 * Purpose: Search the network for the specified satellite and return a pointer to that node
 * @param satelliteName - name of the satellite to look for in network
 * @return pointer to node of satelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName){
    // TODO
    CUSatellite* node = head;        
    while(node != nullptr && node->name != satelliteName){
        node = node->next;
    }
    return node;
}


/*
 * Purpose:
 * @param string receiver
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver) {
    // TODO
    if(head == nullptr) {
        cout << "Empty list" <<endl;
        return;
    }
    if(searchForSatellite(receiver) == nullptr){
        cout<<"Satellite not found" <<endl;
        return;
    }
    CUSatellite* node = head;
    while(node != nullptr) {
        node->message = "distance of " +node->name +" from earth is " +to_string(node->distanceFromEarth);
        node->numberMessages++;
        cout<<node->name<< " [# messages received: " << node->numberMessages<<"] received: " << node->message <<endl;
        if(node->name == receiver) {
            break;
        }
        node=node->next;
    }
}

/*
 * Purpose: prints the current list nicely
 * @param none
 * @return none
 */
void CUSatelliteNetwork::printNetwork() {
     /*
    DO NOT MODIFY THIS FUNCTION
    This function is already complete and is used for testing of other functions. 
    */
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    CUSatellite* ptr = head;
    if (ptr == NULL) {
        cout << "nothing in path" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "(" << ptr->distanceFromEarth << ")" <<" -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
