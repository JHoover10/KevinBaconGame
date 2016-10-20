#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

struct Node
{
	std::string ActorName; //Holds the actors name
	std::string MovieName; //Holds the name of the movie the actor was in
	bool isVisted; //Checks to see if that node has already been visited
	std::vector<Node*> Path; //Holds the path while searching
	
};
#endif
