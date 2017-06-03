#include "Elevator.h"


Elevator::Elevator(char *debugName, int numFloors, int myID) 
{
	name = debugName;
	this->numFloors = numFloors;  // floor of building  
	id = myID; // mark one elevator
    request = new bool[numFloors+1];
    exit = new EventBarrier[numFloors+1];//barrier for going out
    con_lock = new Lock("lock for occupancy");
    con_closeDoor = new Condition("condition for close door");
    occupancy = 0;// can setting
    capacity = 100;
}

Elevator::~Elevator()
{
	delete[] request;
	delete[] exit;
	delete con_lock; 
	delete con_closeDoor;
}
// signal exiters and enterers to action

void 
Elevator::OpenDoors()
{
	//let rider inside go out 
	exit[currentfloor].Signal();

	// calculate close door num;
	con_lock->Acquire();
	//let rider outside go in
    int waiters = b->getFloors()[currentfloor].e[direction].Waiters(); 
    closeDoorNum = waiters > (capacity - occupancy)?(capacity - occupancy):waiters;
    con_lock->Release();
    b->getFloors()[currentfloor].e[direction].Signal();
	// if(direction == 1){// up
	// 	int waiters = b->getFloors()[currentfloor].e[1].Waiters(); 
	// 	closeDoorNum = waiters > (capacity - occupancy)?(capacity - occupancy):waiters;
	// 	con_lock->Release();
	// 	b->getFloors()[currentfloor].e[1].Signal();
	// }else{// down
	// 	int waiters = b->getFloors()[currentfloor].e[0].Waiters(); 
	// 	closeDoorNum = waiters > (capacity - occupancy)?(capacity - occupancy):waiters;
	// 	con_lock->Release();
	// 	b->getFloors()[currentfloor].e[0].Signal(); 
	// }
}

void 	
Elevator::CloseDoors()
{   //if capacity has no limit,make sure people all in  
	// but if has limit,when it reach the capacity 
	
	//door should close 
	con_lock->Acquire();
	while(closeDoorNum != 0){
		con_closeDoor->Wait(con_lock);
	}

    b->getLock()->Acquire(); // Will there be any possible deadlock?
	if(direction == 1){
		b->getSrcUp()[currentfloor] = false;
	}else{
		b->getSrcDown()[currentfloor] = false;
	}
    b->getLock()->Release();
	
	request[currentfloor] = false;
	con_lock->Release();
}   

void
Elevator::VisitFloor(int floor)
{
	// reach the floor 
	alarms->Pause(abs(floor - currentfloor) * _COSTPERFLOOR);
	currentfloor = floor;
}

bool 
Elevator::Enter()
{
	// judge if there has enough occupancy
	// if no return false;
	con_lock->Acquire();
	if(occupancy == capacity){  //to avoid the rider request again 
		con_lock->Release();
		// to wait next time
        b->getFloors()[currentfloor].e[direction].Complete();
		// if(direction == 1){
		// 	b->getFloors()[currentfloor].e[1].Complete();
		// }else{
		// 	b->getFloors()[currentfloor].e[0].Complete(); 
		// } 
		return false;
	}else{
		occupancy++;
		con_lock->Release();
        b->getFloors()[currentfloor].e[direction].Complete();
		// if(direction == 1){
		// 	b->getFloors()[currentfloor].e[1].Complete();
		// }else{
		// 	b->getFloors()[currentfloor].e[0].Complete(); 
		// }
		return true;
	}
}

void
Elevator::Exit()
{
	con_lock->Acquire();
	occupancy--;
	con_lock->Release();
	exit[currentfloor].Complete();//go out
}

void
Elevator::RequestFloor(int floor)
{	
	request[floor] = true;
	con_lock->Acquire();
	closeDoorNum--;
	if(closeDoorNum == 0){
		con_closeDoor->Signal(con_lock);
	}
	con_lock->Release();
	exit[floor].Wait();
}

//building define
Building::Building(char *debugname, int numFloors, int numElevators)
{
	elevator = new Elevator(debugname, numFloors, 1);
	name = debugname;
	srcUp = new bool[numFloors+1];
	srcDown = new bool[numFloors+1];
	floors = new Floor[numFloors+1]; 
	mutex = new Lock("lock for building");
	floorNum = numFloors;
}

Building::~Building()
{
	delete elevator;
	delete[] floors;
	delete[] srcUp;
	delete[] srcDown;
	delete mutex;
}

void 
Building::CallUp(int fromFloor)      
{  
	/*upFloors[fromFloor].e = elevator;*/
	
	// select one elevator 
	// ...
	mutex->Acquire();
	srcUp[fromFloor] = true;
	mutex->Release();
}


void 
Building::CallDown(int fromFloor)    //   ... down
{
	/*downFloors[fromFloor].e = elevator;*/
	
	// select one elevator 
	// ...
	mutex->Acquire();
	srcDown[fromFloor] = true;
	mutex->Release();
}

Elevator *
Building::AwaitUp(int fromFloor) 
{   // wait for elevator arrival & going up
	floors[fromFloor].e[1].Wait(); 
	return elevator;  
}

Elevator *
Building::AwaitDown(int fromFloor) // ... down
{
	/*downFloors[fromFloor].b->Wait();*/
	floors[fromFloor].e[0].Wait(); 
	return elevator;
}


// elevator run function 
// author by huangxi
void
Building::RunElev(int eid) {
    Elevator *elev = elevator;
    int next; // Destination
    while (true) {
        next = 0;
        mutex->Acquire();
        if (elev->getDirection()) { // True when elevator is going down  
            // Find the farest floor having riders waiting to enter or exit the elevator in current direction
            for (int i = elev->getCurrentFloor(); i >= 1; --i) {
                if (srcDown[i] || elev->request[i]) { next = i; }
            }
        } else {
            for (int i = elev->getCurrentFloor(); i <= floorNum; ++i) {
                if (srcUp[i] || elev->request[i]) { next = i; }
            }
        }
        mutex->Release();
        if (!next && !elev->getOccupancy()) {    // No one onboard and no more waiting rider in current direction
            // Change direction
            elev->changeDirection();
            DEBUG('t', "Elevator %d changed direction to %d at floor %d\n", eid, elev->getDirection(), elev->getCurrentFloor());
            continue;
        }
        assert(next > 0 && "Elevator having people onboard but the Request array is not set correctly.");
        if (elev->getDirection()) {
            for (int i = elev->getCurrentFloor(); i >= next; --i) {
                elev->VisitFloor(i);
                // If any rider wanna enter or exit on floor i, open then close door
                if (srcDown[i] || elev->request[i]) {
                    DEBUG('t', "Elevator %d stopped at floor %d\n", eid, i);
                    elev->OpenDoors();
                    elev->CloseDoors();
                }
            }
        } else {
            for (int i = elev->getCurrentFloor(); i <= next; ++i) {
                elev->VisitFloor(i);
                if (srcUp[i] || elev->request[i]) {
                    DEBUG('t', "Elevator %d stopped at floor %d\n", eid, i);
                    elev->OpenDoors();
                    elev->CloseDoors();
                }
            }
        }
    }
}
