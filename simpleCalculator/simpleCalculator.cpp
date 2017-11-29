//Imported libraries which allow the use their functions.
#include <iostream>
#include <string>
#include <vector>

//Public declarations of methods.
void menu();
void add();
void subtract();
void multiply();
void divide();
void mean();

//Public declartions of variables.
float a, b;
char function;

/*
 *I have decided not to use the namespace because it is good practise
 *to use std:: as it will be better in larger projects and help other
 *users understand the code more easily. As well as providing other benefits.
 */
//using namespace std; 

void main() //Main method.
{
	system("Color 2"); //Sets the console foreground colour to 2.
	std::cout << "Welcome to simple calculator, I am Rob. \n"; //Output message to introduce the user to the console application.
	menu(); //This calls the menu method.
}

void clearstream() //A Method to clear the stream instead of having to write the functions everytime. (This function does not need to be declared because it is not used before it is created.
{
	std::cin.clear(); //Clear the in stream, to prevent errors.
	std::cin.ignore(sizeof(std::streamsize), '\n'); //Ignores the amount of characters I specify, in this case it's the stream size up until the \n character.
}

void exitmain()
{
	char exitApp; //Declare char variable.

	std::cout << "Would you like to exit the program? Y/N" << std::endl; //Output message to ask to user if he or she wants to return to the menu.
	std::cin >> exitApp; //Store user input in exitApp variable.
	std::cin.sync(); //Syncs the stream buffer with the input buffer, basically ignoring anything that could be left in the stream.

	if (exitApp == 'Y' || exitApp == 'y') //Check to see if the input value is y.
	{
		exit(0); //Closes the application. Alternatives are std::terminate(); or making the main void return 0.
	}
	else if (exitApp == 'N' || exitApp == 'n')
	{
		std::cin.sync(); //Syncs the stream buffer with the input buffer, basically ignoring anything that could be left in the stream.
		menu(); //Calls the menu method.
	}
	else
	{
		std::cout << "You entered an invalid option, please select either 'Y' or 'N'" << std::endl;
		std::cin.sync(); //Syncs the stream buffer with the input buffer, basically ignoring anything that could be left in the stream.
		exitmain(); //Calls the menu method.
	}
}

void menu()
{
	int menuOption = 0; //Int variable.

	//Basic output messages for a menu for the user to choose what he or she wants to do.
	std::cout << "\nPlease select a number." << std::endl;
	std::cout << "1: Addition" << std::endl;
	std::cout << "2: Subtraction" << std::endl;
	std::cout << "3: Multiplication" << std::endl;
	std::cout << "4: Division" << std::endl;
	std::cout << "5: Calculate Average (Mean)" << std::endl;
	std::cout << "6: Exit Program" << std::endl;

	std::cin.sync(); //Syncs the stream buffer with the input buffer, basically ignoring anything that could be left in the stream.
	std::cin >> menuOption; //Stores the user input into the menuOption variable.
	//std::cin.ignore(sizeof(std::streamsize), ' ');
	
	//clearstream(); //Calls the clearstream() method;

	if (!std::cin.fail()) //Fail If there is no errors trying to take the input.
	{
		switch (menuOption) //This is a switch which checks the menuOption variable and calls the correct method based on that number.
		{
		case 1:
			add(); //This calls the add method.
			break; //Breaks the switch i.e. stops or ends the switch.
		case 2:
			subtract(); //This calls the subtract method.
			break; // Breaks the switch i.e.stops or ends the switch.
		case 3:
			multiply(); //This calls the multiply method.
			break; //Breaks the switch i.e. stops or ends the switch.
		case 4:
			divide(); //This calls the divide method.
			break; //Breaks the switch i.e. stops or ends the switch.
		case 5:
			mean();
			break; //Breaks the switch i.e. stops or ends the switch.
		case 6:
			exitmain(); //This calls the exitmain method.
			break;
		default: //If a number which is not listed is selected.
			std::cout << "You have entered an invalid option." << std::endl;
			std::cin.sync(); //Syncs the stream buffer with the input buffer, basically ignoring anything that could be left in the stream.
			menu(); //Calls the menu method.
			break; //Breaks the switch i.e. stops or ends the switch.
		}
	}
	else
	{
		std::cout << "This option is not supported." << std::endl; //Outputs the messages and ends the line and clears buffer.
		clearstream(); //Calls the clearstream() method;
		std::cin.sync(); //Syncs the stream buffer with the input buffer, basically ignoring anything that could be left in the stream.
		menu(); //Goes to the menu method.
	}
}

void completedCalc(int number) //A method which takes a parameter. The parameter in this case is an int which is named number. This is used to return to the method the user was currently on.
{
	std::string returnMenu; //String variable.
	std::cout << "Would you like to return to the menu? Y/N" << std::endl; //Output message to ask to user if he or she wants to return to the menu.
	std::getline(std::cin, returnMenu); //Gets whole line input from the user and stores it in the returnMenu variable.

	if (returnMenu == "Y" || returnMenu == "y") //Check to see if the input value is y.
	{
		menu(); //Calls the menu method.
	}
	else if (returnMenu == "N" || returnMenu == "n") //Check to see if the input value is n.
	{
		switch (number) //This is a switch which checks the number variable and calls the correct method based on that number.
		{
		case 1:
			add(); //This calls the add method.
			break; //Breaks the switch i.e. stops or ends the switch.
		case 2:
			subtract(); //This calls the subtract method.
			break; //Breaks the switch i.e. stops or ends the switch.
		case 3:
			multiply(); //This calls the multiply method.
			break; //Breaks the switch i.e. stops or ends the switch.
		case 4:
			divide(); //This calls the divide method.
			break; //Breaks the switch i.e. stops or ends the switch.
		case 5:
			mean(); //This calls the mean method.
			break; //Breaks the switch i.e stops or ends the switch.
		default: // If a number which is not listed is selected.
			std::cout << "This function is not supported." << std::endl; //Outputs the messages and ends the line and clears buffer.
			system("pause"); //System pause which outputs a press any key to continue message and closes program upon pressing key.
			break; //Breaks the switch i.e. stops or ends the switch.
		}
	}
	else
	{
		std::cout << "You entered an invalid option, please select either 'Y' or 'N'" << std::endl; //Output message to tell the user they entered an invalid number.
		completedCalc(number); //Return to the completedCalc function with the original number for the method the user was on.
	}
}

void add() //This is a method which when called will perform an addition based on the numbers entered.
{
	std::cout << "Please enter all the numbers you would like to add together. e.g. 2 1 3" << std::endl; //Output message to ask user to enter 2 numbers.
	
	float value; //Declare float variable named value.
	float total = 0; //Declare float variable named total with the value of 0.

	std::vector<float> numberArray; //Create a vector array called numberArray.

	while (std::cin >> value) //While stream reads to value.
	{
		numberArray.push_back(value); //Add the value to the vector array.

		if (std::cin.get() == '\n') //If there is nothing else left (if we are at the last character) then break the while loop.
		{
			break; //Break the while loop.
		}
	}
	
	if (!std::cin.fail()) //Check to see if the cin function failed.
	{
		for (size_t i = 0; i < numberArray.size(); i++) //size_t is an unsigned int. numberArray.size is the size of the vector array (how many array items it has). For loop to iterate through all vector items.
		{
			total += numberArray[i]; //Add the current iteration value to the total variable.
		}

		std::cout << "The answer is: " << total << std::endl; //Output the answer.
		completedCalc(1); //Ask the user if he/she wants to return to the menu or continue with the current method.
	}
	else
	{
		std::cout << "You entered an incorrect value, returning to main menu." << std::endl; //Outputs the messages and ends the line and clears buffer.
		clearstream(); //Calls the clearstream() method;
		menu(); //Goes to the menu method.
	}
}

void subtract() //This is a method which when called will perform an subtraction based on the numbers entered.
{
	std::cout << "Please enter all the numbers you would like to subtract. e.g. 2 1 3" << std::endl; //Output message to ask user to enter 2 numbers.
	//std::cin >> a >> b; //Take the numbers and store them in a variable.
	//clearstream(); //Calls the clearstream() method;

	float value; //Declare float variable named value.
	float total = 0; //Declare float variable named total with the value of 0.

	std::vector<float> numberArray; //Create a vector array called numberArray.

	while (std::cin >> value) //While stream reads to value.
	{
		numberArray.push_back(value); //Add the value to the vector array.

		if (std::cin.get() == '\n') //If there is nothing else left (if we are at the last character) then break the while loop.
		{
			break; //Break the while loop.
		}
	}

	if (!std::cin.fail()) //Check to see if the cin function failed.
	{

		for (size_t i = 0; i < numberArray.size(); i++) //size_t is an unsigned int. numberArray.size is the size of the vector array (how many array items it has). For loop to iterate through all vector items.
		{
			if (i == 0) //If it's the first number, make the total variable equal to the first number.
			{
				total = numberArray[i];
			}
			else
			{
				total -= numberArray[i]; //Subtract the current iteration value from the total variable value and set the new total value.
			}
		}

		std::cout << "The answer is: " << total << std::endl; //Output the answer.
		completedCalc(2); //Ask the user if he/she wants to return to the menu or continue with the current method.
	}
	else
	{
		std::cout << "You entered an incorrect value, returning to main menu." << std::endl; //Outputs the messages and ends the line and clears buffer.
		clearstream(); //Calls the clearstream() method;
		menu(); //Goes to the menu method.
	}
}

void multiply() //This is a method which when called will perform an multiplication based on the numbers entered.
{
	std::cout << "Please enter all the numbers to multiply together. e.g. 2 1 3" << std::endl; //Output message to ask user to enter 2 numbers.
	//std::cin >> a >> b; //Take the numbers and store them in a variable.
	//clearstream(); //Calls the clearstream() method;

	float value; //Declare float variable named value.
	float total = 0; //Declare float variable named total with the value of 0.

	std::vector<float> numberArray; //Create a vector array called numberArray.

	while (std::cin >> value) //While stream reads to value.
	{
		numberArray.push_back(value); //Add the value to the vector array.

		if (std::cin.get() == '\n') //If there is nothing else left (if we are at the last character) then break the while loop.
		{
			break; //Break the while loop.
		}
	}

	if (!std::cin.fail()) //Check to see if the cin function failed.
	{

		for (size_t i = 0; i < numberArray.size(); i++) //size_t is an unsigned int. numberArray.size is the size of the vector array (how many array items it has). For loop to iterate through all vector items.
		{
			if (i == 0) //If it's the first number, make the total variable equal to the first number.
			{
				total = numberArray[i];
			}
			else
			{
				total *= numberArray[i]; //Multiply the current iteration value by the total variable value and set the new total value.
			}
		}

		std::cout << "The answer is: " << total << std::endl; //Output the answer.
		completedCalc(3); //Ask the user if he/she wants to return to the menu or continue with the current method.
	}
	else
	{
		std::cout << "You entered an incorrect value, returning to main menu." << std::endl; //Outputs the messages and ends the line and clears buffer.
		clearstream(); //Calls the clearstream() method;
		menu(); //Goes to the menu method.
	}
}

void divide() //This is a method which when called will perform an division based on the numbers entered.
{
	std::cout << "Please enter all the numbers you would like to divide by. e.g. 2 1 3 4" << std::endl; //Output message to ask user to enter 2 numbers.
	//std::cin >> a >> b; //Take the numbers and store them in a variable.
	//clearstream(); //Calls the clearstream() method;

	float value; //Declare float variable named value.
	float total = 0; //Declare float variable named total with the value of 0.

	std::vector<float> numberArray; //Create a vector array called numberArray.

	while (std::cin >> value) //While stream reads to value.
	{
		numberArray.push_back(value); //Add the value to the vector array.

		if (std::cin.get() == '\n') //If there is nothing else left (if we are at the last character) then break the while loop.
		{
			break; //Break the while loop.
		}
	}

	if (std::find(numberArray.begin(), numberArray.end(), 0) != numberArray.end()) //Check to see if the user is trying to divide by 0. find function looks in the boundaries specified, begin and end. If the specified value (0 in this case) is not found then it will returns the end, so if it's not end then our vector contains a 0, therefore user is trying to divide by 0. Sneaky.
	{
		std::cout << "Cannot divide by 0." << std::endl; //Output a message telling the user you can't divide by 0.
		completedCalc(4); //Ask the user if he/she wants to return to the menu or continue with the current method.
	}

	if (!std::cin.fail()) //Check to see if the cin function failed.
	{
		for (size_t i = 0; i < numberArray.size(); i++) //size_t is an unsigned int. numberArray.size is the size of the vector array (how many array items it has). For loop to iterate through all vector items.
		{
			if (i == 0) //If it's the first number, make the total variable equal to that because we can't divide by 0.
			{
				total = numberArray[i];
			}
			else
			{
				total /= numberArray[i]; // Divide by the current iteration value.
			}
		}

		std::cout << "The answer is: " << total << std::endl; //Output the answer.
		completedCalc(4); //Ask the user if he/she wants to return to the menu or continue with the current method.
	}
	else
	{
		std::cout << "You entered an incorrect value, returning to main menu." << std::endl; //Outputs the messages and ends the line and clears buffer.
		clearstream(); //Calls the clearstream() method;
		menu(); //Goes to the menu method.
	}
}

void mean()
{
	std::cout << "Please several numbers to calculate the average of. e.g. 2 1 3 4" << std::endl; //Output message to ask user to enter 2 numbers.
	//std::cin >> a >> b; //Take the numbers and store them in a variable.
	//clearstream(); //Calls the clearstream() method;

	float value; //Declare float variable named value.
	float total = 0; //Declare float variable named total with the value of 0.

	std::vector<float> numberArray; //Create a vector array called numberArray.

	while (std::cin >> value) //While stream reads to value.
	{
		numberArray.push_back(value); //Add the value to the vector array.

		if (std::cin.get() == '\n') //If there is nothing else left (if we are at the last character) then break the while loop.
		{
			break; //Break the while loop.
		}
	}

	if (!std::cin.fail()) //Check to see if the cin function failed.
	{
		for (size_t i = 0; i < numberArray.size(); i++) //size_t is an unsigned int. numberArray.size is the size of the vector array (how many array items it has). For loop to iterate through all vector items.
		{
			total += numberArray[i];
		}

		total = total / numberArray.size(); //Divide total by the amount of elements in the vector and assign total to the new value.

		std::cout << "The average is: " << total << std::endl; //Output the answer.
		completedCalc(5); //Ask the user if he/she wants to return to the menu or continue with the current method.
	}
	else
	{
		std::cout << "You entered an incorrect value, returning to main menu." << std::endl; //Outputs the messages and ends the line and clears buffer.
		clearstream(); //Calls the clearstream() method;
		menu(); //Goes to the menu method.
	}
}