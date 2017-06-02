/*

Here are the method signatures for the Elevator and Building classes.
You should feel free to add to these classes, but do not change the
existing interfaces.

*/
#ifndef ELEVATOR_H
#define EVEVATOR_H
#include "EventBarrier.h"
#include　"synch.h"
class Elevator {
   public:
     Elevator(char *debugName, int numFloors, int myID);
     ~Elevator();
     char *getName() { return name; }
   
     // elevator control interface: called by Elevator thread
     void OpenDoors();                //   signal exiters and enterers to action
     void CloseDoors();               //   after exiters are out and enterers are in
     void VisitFloor(int floor);      //   go to a particular floor
   
     // elevator rider interface (part 1): called by rider threads.
     bool Enter();                    //   get in
     void Exit();                     //   get out (iff destinationFloor)
     void RequestFloor(int floor);    //   tell the elevator our destinationFloor
     
     // insert your methods here, if needed
     bool* getRequest(){return request;}
     int   getCurrentFloor(){return currentfloor;}
     void  setBuilding(Building *building){b = building;}
   private:
     char *name;
   
     int currentfloor;           // floor where currently stopped
     int occupancy;              // how many riders currently onboard
   
     // insert() your data structures here, if needed
     int numFloors;
     int id;
     int direction;// 0 means down,1 means up  
     int destnation;
     bool* request; // mark request floor,if it is true 
     int status; // elevator status 0 means working 1 means free
     EventBarrier* exit;
     Lock *con_lock;
     int closeDoorNum;
     Condition *con_closeDoor;
     Building *b;
};

class Floor{
public:
    EventBarrier *e;
    Floor()
    {
      e = new EventBarrier[2]; // 0 means down,1 means up
    }
    ~Floor()
    {
      delete[] e;　
    }
};


   
class Building {
   public:
     Building(char *debugname, int numFloors, int numElevators);
     ~Building();
     char *getName() { return name; }
   
     				
     // elevator rider interface (part 2): called by rider threads
     void CallUp(int fromFloor);      //   signal an elevator we want to go up
     void CallDown(int fromFloor);    //   ... down
     Elevator *AwaitUp(int fromFloor); // wait for elevator arrival & going up
     Elevator *AwaitDown(int fromFloor); // ... down
     Floor* getFloors(){return floors;}
     bool*  getSrcUp(){return srcUp;} 
     bool*  getSrcDown(){return srcDown;}
     Lock*  getLock(){return mutex;}
   private:
     char *name;
     int floorNum;
     Elevator *elevator;
     Floor *floors;
     bool *srcUp;
     bool *srcDown;
     Lock *mutex;
     // insert your data structures here, if needed
};




#endif 


   // here's a sample portion of a rider thread body showing how we
   // expect things to be called.
   //
   // void rider(int id, int srcFloor, int dstFloor) {
   //    Elevator *e;
   //  
   //    if (srcFloor == dstFloor)
   //       return;
   //  
   //    DEBUG('t',"Rider %d travelling from %d to %d\n",id,srcFloor,dstFloor);
   //    do {
   //       if (srcFloor < dstFloor) {
   //          DEBUG('t', "Rider %d CallUp(%d)\n", id, srcFloor);
   //          building->CallUp(srcFloor);
   //          DEBUG('t', "Rider %d AwaitUp(%d)\n", id, srcFloor);
   //          e = building->AwaitUp(srcFloor);
   //       } else {
   //          DEBUG('t', "Rider %d CallDown(%d)\n", id, srcFloor);
   //          building->CallDown(srcFloor);
   //          DEBUG('t', "Rider %d AwaitDown(%d)\n", id, srcFloor);
   //          e = building->AwaitDown(srcFloor);
   //       }
   //       DEBUG('t', "Rider %d Enter()\n", id);
   //    } while (!e->Enter()); // elevator might be full!
   //  
   //    DEBUG('t', "Rider %d RequestFloor(%d)\n", id, dstFloor);
   //    e->RequestFloor(dstFloor); // doesn't return until arrival
   //    DEBUG('t', "Rider %d Exit()\n", id);
   //    e->Exit();
   //    DEBUG('t', "Rider %d finished\n", id);
   // }

