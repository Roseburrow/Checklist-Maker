#include <iostream>
#include <string>
#include <vector>

struct Task {
    std::string toDo = "empty";
    int priority = 0;
    bool completed = false;
};

static std::vector<Task> tasks;

void Welcome() {

std::cout << "Welcome to this simple Checklist program!" << std::endl;
std::cout << "Type:" << std::endl << "'View' - View Checklist." << std::endl
	  << "'Add' - Add new items to the Checklist." << std::endl
	  << "'Remove' - Remove items from the Checklist." << std::endl
	  << "'Complete' - Mark tasks as completed." << std::endl
	  << " " << std::endl;
}

void AddTasks() {

std::string enteredString;
int enteredPriority;
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

	if (tasks[i].completed == true)
	    std::cout << " [X]" << std::endl;
	else { std::cout << " [ ]" << std::endl; }
    }
}

void getInput() {

    while (true) {
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
	    std::cout << "Completing" << std::endl;
	}
	else if (inputOperation == "View") {
	    ViewList();
	}
    }
}

int main() {

for (int j = 0; j < 5; ++j) {
    
    Task addTask;
    addTask.toDo = std::to_string(j);
    addTask.priority = 1;
    addTask.completed = true;
    tasks.push_back(addTask);

}

Welcome();
getInput();

    return 0;
}
