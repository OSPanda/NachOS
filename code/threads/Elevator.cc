#include "Elevator.h"


Elevator::Elevator(char *debugName, int numFloors, int myID) 
{
	name = debugName;
	this->numFloors = numFloors;  // floor of building  
	id = myID; // mark one elevator
    request = new bool[numFloors+1];
    exit = new EventBarrier[numFloors+1];//barrier for going out
    upFloor = new EventBarrier[numFloors+1];
    downFloor = new EventBarrier[numFloors+1];
    con_lock = new Lock("lock for occupancy");
    con_closeDoor = new Condition("condition for close door");
    occupancy = 1000;// can setting
}

Elevator::~Elevator()
{
	delete[] request;
	delete[] exit;
	delete[] upFloor;
	delete[] downFloor;
	delete con_lock; 
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
	if(direction == 1){
		int waiters = upFloor[currentfloor].Waiters(); 
		closeDoorNum = waiters > occupancy? occupancy:waiters;
		con_lock->Release();
		upFloor[currentfloor].Signal();
	}else{
		int waiters = downFloor[currentfloor].Waiters(); 
		closeDoorNum = waiters > occupancy? occupancy:waiters;
		con_lock->Release();
		downFloor[currentfloor].Signal(); 
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
			upFloor[currentfloor].Complete();
		}else{
			downFloor[currentfloor].Complete(); 
		} 
		return false;
	}else{
		occupancy--;
		con_lock->Release();
		if(direction == 1){
			upFloor[currentfloor].Complete();
		}else{
			downFloor[currentfloor].Complete(); 
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
	/*upFloors = new Floor[numFloors+1];  // floor up barrier
	downFloors = new Floor[numFloors+1]; // floor down barrier*/
}

Building::~Building()
{
	/*delete[] upFloors;
	delete[] downFloors;*/
	delete elevator;
}

void 
Building::CallUp(int fromFloor)      
{  
	/*upFloors[fromFloor].e = elevator;*/
	
	// select one elevator 
	// ...
	elevator->getRequest()[floor] = true;
}


void 
Building::CallDown(int fromFloor)    //   ... down
{
	/*downFloors[fromFloor].e = elevator;*/
	
	// select one elevator 
	// ...

	elevator->getRequest()[floor] = true;
}

Elevator *
Building::AwaitUp(int fromFloor) 
{   // wait for elevator arrival & going up
	elevator->getUpFloor()[fromFloor].Wait(); 
	return elevator;  
}

Elevator *
Building::AwaitDown(int fromFloor) // ... down
{
	/*downFloors[fromFloor].b->Wait();*/
	elevator->getdownFloor()[fromFloor].Wait(); 
	return elevator;
}
