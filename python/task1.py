import sys

class ToDoList:
    def __init__(self):
        self.tasks = []

    def add_task(self, description):
        self.tasks.append({"description": description, "completed": False})

    def update_task(self, index, new_description):
        if 0 <= index < len(self.tasks):
            self.tasks[index]["description"] = new_description

    def mark_task_completed(self, index):
        if 0 <= index < len(self.tasks):
            self.tasks[index]["completed"] = True

    def delete_task(self, index):
        if 0 <= index < len(self.tasks):
            del self.tasks[index]

    def view_tasks(self):
        for i, task in enumerate(self.tasks, 1):
            status = "Done" if task["completed"] else "Pending"
            print(f"{i}. {task['description']} - {status}")

def main():
    todo_list = ToDoList()
    while True:
        print("\n1. Add Task\n2. Update Task\n3. Mark Task Completed\n4. Delete Task\n5. View Tasks\n6. Exit")
        choice = input("Choose an option: ")
        if choice == "1":
            description = input("Enter task description: ")
            todo_list.add_task(description)
        elif choice == "2":
            index = int(input("Enter task number to update: ")) - 1
            new_description = input("Enter new task description: ")
            todo_list.update_task(index, new_description)
        elif choice == "3":
            index = int(input("Enter task number to mark as completed: ")) - 1
            todo_list.mark_task_completed(index)
        elif choice == "4":
            index = int(input("Enter task number to delete: ")) - 1
            todo_list.delete_task(index)
        elif choice == "5":
            todo_list.view_tasks()
        elif choice == "6":
            sys.exit("Exiting To-Do List Application")
        else:
            print("Invalid choice, please try again.")

if __name__ == "__main__":
    main()

