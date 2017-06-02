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
    occupancy = 1000;// can setting
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
	if(direction == 1){// up
		int waiters = b->getFloors()[currentfloor].e[1].Waiters(); 
		closeDoorNum = waiters > occupancy? occupancy:waiters;
		con_lock->Release();
		b->getFloors()[currentfloor].e[1].Signal();
	}else{// down
		int waiters = b->getFloors()[currentfloor].e[0].Waiters(); 
		closeDoorNum = waiters > occupancy? occupancy:waiters;
		con_lock->Release();
		b->getFloors()[currentfloor].e[0].Signal(); 
	}
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

	if(direction == 1){
		b->getLock()->Acquire(); 
		b->getSrcUp()[currentfloor] = false;
		b->getLock()->Release();
	}else{
		b->getLock()->Acquire(); 
		b->getSrcDown()[currentfloor] = false;
		b->getLock()->Release();
	}
	
	request[currentfloor] = false;
	con_lock->Release();
}   

void
Elevator::VisitFloor(int floor)
{
	// reach the floor 
	currentfloor = floor;
}

bool 
Elevator::Enter()
{
	// judge if there has enough occupancy
	// if no return false;
	con_lock->Acquire();
	if(occupancy == 0){  //to avoid the rider request again 
		con_lock->Release();
		// to wait next time
		if(direction == 1){
			b->getFloors()[currentfloor].e[1].Complete();
		}else{
			b->getFloors()[currentfloor].e[0].Complete(); 
		} 
		return false;
	}else{
		occupancy--;
		con_lock->Release();
		if(direction == 1){
			b->getFloors()[currentfloor].e[1].Complete();
		}else{
			b->getFloors()[currentfloor].e[0].Complete(); 
		}
		return true;
	}
}

void
Elevator::Exit()
{
	con_lock->Acquire();
	occupancy++;
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
	elevator = new Elevator(debugname,numFloors,1);
	name = debugName
	srcUp = new bool[numFloors+1];
	srcDown = new bool[numFloors+1];
	floors = new Floor[numFloors+1]; 
	mutex = new Lock("lock for building");
	floorNum = numFloors;
}

Building::~Building()
{
	/*delete[] upFloors;
	delete[] downFloors;*/
	delete elevator;
	delete[] src;	
	delete[] floors;
}

void 
Building::CallUp(int fromFloor)      
{  
	/*upFloors[fromFloor].e = elevator;*/
	
	// select one elevator 
	// ...
	mutex->Acquire();
	srcUp[floor] = true;
	mutex->Release();
}


void 
Building::CallDown(int fromFloor)    //   ... down
{
	/*downFloors[fromFloor].e = elevator;*/
	
	// select one elevator 
	// ...
	mutex->Acquire();
	srcDown[floor] = true;
	mutex->Release();
}

Elevator *
Building::AwaitUp(int fromFloor) 
{   // wait for elevator arrival & going up
	floors[fromFloor].Wait(); 
	return elevator;  
}

Elevator *
Building::AwaitDown(int fromFloor) // ... down
{
	/*downFloors[fromFloor].b->Wait();*/
	floors[fromFloor].Wait(); 
	return elevator;
}
