#ifndef SIXDEGREESOFBACON_H
#define SIXDEGREESOFBACON_H
#include "Node.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

class SixDegreesOfBacon
{
public:
	SixDegreesOfBacon(); //Default constructor
	~SixDegreesOfBacon(); //Default destructor
	bool FindActors(string Actor1, string Actor2); //Finds the connection between the two actors using BFS
	void MakeGraph(string DataFromFile); //Takes the data from the string and creates my nodes
	void Print(string command); //Prints the results
private:
	Node* tempNode; //My tempNode
	string tempNameHolder; //Holder for parsing names
	string tempMovieHolder; //Holder for parsing movie names
	queue<Node*> BaconQueue; //My queue for BFS
	vector<Node*> Nodes; //Held my nodes
};
#endif

