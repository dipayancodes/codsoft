#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back({description, false});
    }

    void viewTasks() {
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << i + 1 << ". " << tasks[i].description << " - " 
                      << (tasks[i].completed ? "Completed" : "Pending") << "\n";
        }
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        } else {
            std::cout << "Invalid task number.\n";
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;
    std::string taskDescription;

    do {
        std::cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                int taskToComplete;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskToComplete;
                toDoList.markTaskAsCompleted(taskToComplete - 1);
                break;
            case 4:
                int taskToRemove;
                std::cout << "Enter task number to remove: ";
                std::cin >> taskToRemove;
                toDoList.removeTask(taskToRemove - 1);
                break;
            case 5:
                std::cout << "Exiting To-Do List Manager.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

