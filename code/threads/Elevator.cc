#include "Elevator.h"


Elevator::Elevator(char *debugName, int numFloors, int myID) 
{
	name = debugName;
	this->numFloors = numFloors;  // floor of building  
	id = myID; // mark one elevator
	floors = new EventBarrier[2*numFloors+1];
}

Elevator::~Elevator()
{
	delete[] floors;

}
// signal exiters and enterers to action
void 
Elevator::OpenDoors()
{
	// rider inside go out and rider outside go in
	if(direction == 0){ // down
		floors[currentfloor*2-1].Signal(); // to let rider in 

	}else{ // up
		floors[currentfloor*2].Signal();
	}

}

void 	
Elevator::CloseDoors()
{   //if capacity has no limit,make sure people all in  
	// but if has limit,when it reach the capacity 
	// door should close 



}   

void
VisitFloor(int floor)
{

}

void 
Elevator::Enter()
{	
	if(direction == 0){ // down
		floors[currentfloor*2-1].Complete();
	}else{ // up
		floors[currentfloor*2].Complete();
	}
}

void
Elevator::Exit()
{



}

void
Elevator::RequestFloor(int floor)
{



}

//buiding define
Building::Building(char *debugname, int numFloors, int numElevators)
{
	name = debugName
	elevator = new Elevator(debugname,numFloors,1);// just one elevator
	
}

Building::~Building()
{
	delete elevator; 
}


void 
Building::CallUp(int fromFloor)      
{   //  signal an elevator we want to go up
	
}


void 
Building::CallDown(int fromFloor)    //   ... down
{
	
}

Elevator *
Building::AwaitUp(int fromFloor) 
{   // wait for elevator arrival & going up
	
}

Elevator *
Building::AwaitDown(int fromFloor) // ... down
{
	

}
