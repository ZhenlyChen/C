#include <iostream>

typedef struct person{
	static int worldID = 0;
	int id;
	person():firendNum(0){
		id = worldID;
		worldID++;
	}
}person;

class group {
public:
group(int);
void displayGroup();
bool addMember(person &p);
bool deleteMember(person &p);
bool makeFriend(person &p1, person &p2);
bool breakRelation(person &p1, person &p2);
private:
	int gType;
	person* peoList[100];
	int size;
	int relation[100][100];
};

group::group(int _num){
	gType = _num;
	size = 0;
	reSize = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			relation[i][j] = -1;
		}
	}
}
void group::displayGroup(){
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Person_" << peoList[i]->id << ":"
		int count = 0;
		while(relation[i][count] != -1 && count < 100){
			if(count != 0) std::cout << ",";
			std::cout << " " << relation[i][count];
		}
	}
}
bool group::addMember(person &p){
	for (int i = 0; i < size; ++i)
	{
		if(peoList[i]->id == p.id) return false;
	}
	peoList[size] = p;
	size++;
	return true;
}
bool group::deleteMember(person &p){
	for (int i = 0; i < size; ++i)
	{
	    if(peoList[i]->id == p.id){
	    	for (int j = i; j < size - 1; ++j)
	    	{
	    		peoList[j] = peoList[j + 1];
	    		for (int k = 0; k < 100; ++k)
	    		{
	    			relation[j][k] = relation[j + 1][k];
	    		}
	    	}
	    	size--;
	    	return true;
	    }
	}
 	return false;
}
bool group::makeFriend(person &p1, person &p2){
	int p1Index = -1, p2Index = -1;
	for (int i = 0; i < size; ++i)
	{
		if(peoList[i]->id == p1.id)p1Index = i;
		if(peoList[i]->id = p2.id)p2Index = i;
	}
	if(p1Index != -1 && p2Index = -1){
		
		return true;
	}
	return false;
}
bool group::breakRelation(person &p1, person &p2);
