#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//TODO:Add Validation!

struct Task {
    std::string toDo = "empty";
    char priority = 0;
    char completed = 'f';
};

static std::vector<Task> tasks;

void Welcome() {

std::cout << "Welcome to this simple Checklist program!" << std::endl
	  << "Type:" << std::endl << "'View' - View Checklist." << std::endl
	  << "'Add' - Add new items to the Checklist." << std::endl
	  << "'Remove' - Remove items from the Checklist." << std::endl
	  << "'Complete' - Mark tasks as completed." << std::endl
	  << "'Save' - To save the list." << std::endl
	  << " " << std::endl;
}

void SaveList() {

    std::ofstream output;
    int SIZE = tasks.size();

    output.std::ofstream::open("list.txt");

    for (int i = 0; i < SIZE; ++i) {
	
	output << tasks[i].priority 
	       << tasks[i].completed
	       << tasks[i].toDo << std::endl;
    }

    output.std::ofstream::close();
}

void LoadList() {

    std::ifstream input;
    std::string line;
    Task addTask;

    input.std::ifstream::open("list.txt");

    while (getline(input, line)) {
	addTask.priority = line[0];
	addTask.completed = line[1];
	line.erase(0, 2);
	addTask.toDo = line;
	tasks.push_back(addTask);
    }

    input.std::ifstream::close();
}

void CompleteTasks() {
    int index;
    std::cin >> index;
    tasks[index].completed = 'c';
}

void AddTasks() {
    std::string enteredString;
    char enteredPriority;
    Task newTask;

    std::cin.ignore();
    getline(std::cin, enteredString, '-');

    std::cin >> enteredPriority;

    newTask.toDo = enteredString;
    newTask.priority = enteredPriority;
    tasks.push_back(newTask);
}

void RemoveTasks() {
    int index;
    std::cin >> index;
    tasks.erase(tasks.begin() + index);
}

void ViewList() {

    int SIZE = tasks.size();
    for (int i = 0; i < SIZE; ++i) {
	std::cout << tasks[i].toDo << " - " << tasks[i].priority;

	if (tasks[i].completed == 'c')
	    std::cout << " [X]" << std::endl;
	else { std::cout << " [ ]" << std::endl; }
    }
}

void getInput() {
	
	while(true) {
	std::string inputOperation;
	std::cin >> inputOperation;

	if (inputOperation == "Add") {
	    std::cout << "Add: ";
	    AddTasks();
	}
	else if (inputOperation == "Remove") {
	    std::cout << "Remove: ";
	    RemoveTasks();
	}
	else if (inputOperation == "Complete") {
	    std::cout << "Complete: ";
	    CompleteTasks();
	}
	else if (inputOperation == "View") {
	    ViewList();
	}
	else if (inputOperation == "Save") {
	    SaveList();
	}
	else if (inputOperation == "clear") {
	    system("clear");
	    Welcome();
	}
	else if (inputOperation == "exit") {
	    break;
	}
    }
}

int main() {

    LoadList();
    Welcome();
    getInput();

    return 0;
}
