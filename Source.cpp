#include "SixDegreesOfBacon.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
//#include "graph.h"
//graph should have Node, and edge; node as the actor; edge as connection between actor and movie

using namespace std;

int main(int argc, char* argv[])
{
	//ifstream infile("input.txt");
	int i = 0;
	SixDegreesOfBacon BaconTest;
	string line;
	
	i = (strcmp(argv[1], "-v") != 0) ? 1 : 2;
	ifstream infile(argv[i]);
	
	while (getline(infile, line))
	{
		//cout << line << endl;
		BaconTest.MakeGraph(line);
	}

	if (strcmp(argv[1], "-v") == 0 && BaconTest.FindActors(argv[3], argv[4]))
	{
		BaconTest.Print(argv[1]);
	}
	else if (strcmp(argv[1], "-v") != 0 && BaconTest.FindActors(argv[2], argv[3]))
	{
		BaconTest.Print("");
	}

	return 0;
}
