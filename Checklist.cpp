#include <iostream>
#include <string>

void Welcome() {

std::cout << "Welcome to this simple Checklist program!" << std::endl;
std::cout << "Type:" << std::endl << "'View' - View Checklist." << std::endl
	  << "'Add' - Add new items to the Checklist." << std::endl
	  << "'Remove' - Remove items from the Checklist." << std::endl
	  << "'Complete' - Mark tasks as completed." << std::endl
	  << " " << std::endl;
}

void AddTasks() {

std::cout << ">> ";

std::string enteredString;
int enteredPriority;

std::cin.ignore();
getline(std::cin, enteredString, '-');

std::cin >> enteredPriority;

std::cout << enteredString;
std::cout << enteredPriority;

}

void getInput() {

std::string inputOperation;
std::cin >> inputOperation;

    if (inputOperation == "Add") {
	AddTasks();
    }
    else if (inputOperation == "Remove") {
	std::cout << "Removing" << std::endl;
    }
    else if (inputOperation == "Complete") {
	std::cout << "Completing" << std::endl;
    }
    else if (inputOperation == "View") {
	std::cout << "Viewing" << std::endl;
    }
}

int main() {
    
    struct Task {
	std::string toDo = "empty";
	int priority = 0;
	bool completed = false;
    };

Task tasks [100];

Welcome();
getInput();

    return 0;
}
