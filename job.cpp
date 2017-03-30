#include "Job.h"
#include <string>
#include <sstream>
int Job::number = 0;
Job::Job(int priority){
	id = number;
	number++;
	this->priority = priority;
	nextJob = NULL;
}
void Job::setId(int id){this->id = id;}
int Job::getId() const{return id;}
void Job::setPriority(int priority){this->priority = priority;}
int Job::getPriority() const{return priority;}
void Job::setNext(Job *job){

}
Job *Job::getNext() const{return nextJob;}
std::string Job::toString(){
	stringstream stemp;
	stemp << "[" << id << ":" << priority << "]";
	return stemp.str();
}
