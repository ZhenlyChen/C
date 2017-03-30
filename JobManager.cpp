#include "JobManager.h"
#include <iostream>
JobManager* JobManager::instance = NULL;
JobManager* JobManager::getInstance(){
	if(JobManager::instance == NULL){
		JobManager* instance = new JobManager();
	}
	return instance;
}
bool JobManager::deleteInstance(){
	if(instance){
		clear();
		delete instance;
		return 1;
	}
	return 0;
}

void JobManager::addJob(int priority){
	Job* temp = new Job(priority);
	if(jobFrontPointer != NULL) temp->setNext(jobFrontPointer);
	jobFrontPointer = temp;
}
void JobManager::finishOneJob(){
	Job* temp = jobFrontPointer;
	if(temp == NULL) return;
	if(temp->getNext() == NULL){
		delete temp;
		jobFrontPointer == NULL;
	}
	while(temp->getNext()->getNext() != NULL){
		temp = temp->getNext();
	}
	delete temp->getNext();
	temp->setNext(NULL);

}

void JobManager::sortJob(){

}

void JobManager::printJob(){
	if(jobFrontPointer == NULL)return;
	std::cout << jobFrontPointer->toString();
	Job* temp = jobFrontPointer->getNext();
	while(temp != NULL){
		std::cout << "->" <<temp->toString();
		temp = temp->getNext();
	}
}
int JobManager::getNumOfJob(){
	Job* temp = jobFrontPointer;
	if(temp == NULL)return 0;
	int count = 1;
	while(temp->getNext() != NULL){
		count++;
		temp = temp->getNext();
	}
	return count;

}
void JobManager::clear(){
	Job* temp = jobFrontPointer;
	while(temp != NULL){
		Job* ptr = temp;
		temp = temp->getNext();
		delete ptr;
	}
	jobFrontPointer = NULL;
}
JobManager::~JobManager(){
	clear();
	instance = NULL;
}
JobManager::JobManager(){
	jobFrontPointer = NULL;
}
JobManager::JobManager(const JobManager& other){

}
 void JobManager::operator=(const JobManager& other){

 }
