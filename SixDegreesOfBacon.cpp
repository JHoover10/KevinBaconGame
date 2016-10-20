#include "SixDegreesOfBacon.h"


SixDegreesOfBacon::SixDegreesOfBacon()
{
}


SixDegreesOfBacon::~SixDegreesOfBacon()
{
}


bool SixDegreesOfBacon::FindActors(string Actor1, string Actor2)
{
	bool Actor1Exist = false; //Check for correct actor name
	bool Actor2Exist = false; //Check for correct actor name

	//Checks the nodes to see if those actors exsist in the node list
	for (int i = 0; i < Nodes.size(); i++)
	{
		if (Nodes.at(i)->ActorName == Actor1)
		{
			Actor1Exist = true;
		}
		else if (Nodes.at(i)->ActorName == Actor2)
		{
			Actor2Exist = true;
		}
	}
	
	//Prints out an error number depending on which actor is false
	if (Actor1Exist == false && Actor2Exist == false)
	{
		cout << "-1 -2\n";
		return 0;
	}
	else if (Actor1Exist == false)
	{
		cout << "-1\n";
		return 0;
	}
	else if (Actor2Exist == false)
	{
		cout << "-2\n";
		return 0;
	}
	
	//Searches the list for all the movies the starting actor was in
	for (int i = 0; i < Nodes.size(); i++)
	{
		if (Nodes.at(i)->ActorName == Actor2)
		{
			BaconQueue.push(Nodes.at(i));
			Nodes.at(i)->isVisted = true;
		}
	}

	//Does a breath first search of the node list checking to see if the next node in the
	//queue is the goal actor
	while ((!BaconQueue.empty()) && (BaconQueue.front()->ActorName != Actor1))
	{
		tempNode = BaconQueue.front();
		BaconQueue.pop();


		for (int i = 0; i < Nodes.size(); i++)
		{
			if ((!Nodes.at(i)->isVisted) && (Nodes.at(i)->MovieName == tempNode->MovieName
				|| Nodes.at(i)->ActorName == tempNode->ActorName))
			{
				Nodes.at(i)->isVisted = true;
				BaconQueue.push(Nodes.at(i));
				Nodes.at(i)->Path = tempNode->Path;
				Nodes.at(i)->Path.push_back(tempNode);
			}
		}
	}
	
	//Prints an error if a path doesn't exsist
	if (BaconQueue.empty())
	{
		cout << "-3";
		return 0;
	}
	
	return 1;
}


void SixDegreesOfBacon::MakeGraph(string DataFromString)
{
	//Takes the lines from the string and takes the data to fill in the actors name and movie
	//for the nodes
	for (int i = 0; i < DataFromString.length(); i++)
	{
		if (DataFromString[i] == '|')
		{
			tempNameHolder = DataFromString.substr(0, i);
			tempMovieHolder = DataFromString.substr((i + 1), (DataFromString.length() - 1));
			break;
		}
	}
	
	//Creates a new node containing the data from the string
	tempNode = new Node;
	tempNode->ActorName = tempNameHolder;
	tempNode->MovieName = tempMovieHolder;
	tempNode->isVisted = false;

	Nodes.push_back(tempNode);
}


void SixDegreesOfBacon::Print(string command)
{
	tempNode = BaconQueue.front(); //Makes tempNode my goal node
	tempNode->Path.push_back(BaconQueue.front()); //Append my goal node to the path
	
	if (command == "-v")
	{
		//Prints the exact path that connects both actors
		for (int i = 0; i < tempNode->Path.size(); i++)
		{
			cout << tempNode->Path.at(i)->ActorName << " was in " << tempNode->Path.at(i)->MovieName
				<< " with " << tempNode->Path.at(i + 1)->ActorName << '.' << endl;
			i++;
		}
		
		//Prints the distance between the two actors
		cout << tempNode->Path.size() - 2 << endl;
	}
	else
	{
		//Prints the distance between the two actors
		cout << tempNode->Path.size() - 2 << endl;
	}
}
