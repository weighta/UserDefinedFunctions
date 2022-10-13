//User-Defined Functions
//CSIS 111-BO2
//

//Include statements
#include <iostream>
#include <fstream>
#include <iomanip> //Used for decimal precision when using cout
#include "macros.h"

//Global declarations: Constants and type definitions only -- no variables
const char maxNames = 1 << 4; //Use 16 maximum names that can be stored at compile time.

//Function prototypes
void PrintName(char* names) {
	say(names); //Print the names to the console with the 'say' macro
}
float Perc(int* score) {
	return (float)score[0] / score[1]; //Cast the first variable to a float so that the entire expression becomes a float
}
char* ScorePrompt(float score) {
	char context[5][1 << 5] = { "Excellent", "Well Done", "Good", "Needs Improvement", "Fail" }; //Define a 'string array' for convenience
	//Scores determined as follows
	if (score > 0.9) return context[0];
	else if (score > 0.8) return context[1];
	else if (score > 0.7) return context[2];
	else if (score >= 0.6) return context[3];
	else return context[4];
}
void DisplayFile() {
	std::ifstream inFile; //Call ifstream for file reading
	char names[maxNames][maxNames]; //Maximum of maxNames characters in Last Name allowed
	int scores[maxNames][2]; //Store scores in same mannor as names as a maxNames x 2
	float percs[maxNames]; //Maximum number of names is the same number of score percentage ratios
	char numNames; //Use char for number of names because there will never be more than 127 names
	char i = 0; //Use as index for fileStream

	inFile.open("scores.txt"); //Open the scores data file into stream
	do {
		inFile >> names[i]; //Read the characters of the name
		inFile >> scores[i][0]; //Read points achieved
		inFile >> scores[i++][1]; //Read maximum possible points achievable
	} while ((!inFile.eof()) && inFile); //Ensure within stream and not null
	numNames = i; //index equals the number of Names found

	for (int i = 0; i < numNames; i++) {
		PrintName(names[i]); //Call printname function for outputting name to console
		say(' ');
		percs[i] = Perc(scores[i]);
		say((int)ceil(100 * percs[i])); //Round up with ceiling, multiply by 100 for shifting decimal two spaces to the right
		say("% ");
		sayf(percs[i]); //Macro for floating point output precision based on custom macros.h header file
		say(' ');
		say(ScorePrompt(percs[i])); //Call scoreprompt for calculating the type of congradulating context based on score
		say('\n');
	}
}

int main()
{
	//In cout statement below SUBSTITUTE your name and lab number
	sayl("Alexander Weight -- Lab 5\n");

	//Variable declarations

	//Program logic
	DisplayFile(); //All starts here, cleaned up main!

	//Closing program statements
	say('\n');
	system("pause");
	return 0;
}