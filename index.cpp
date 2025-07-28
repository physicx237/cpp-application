#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Task
{
  int id;
  string description;
  bool isActive;
};


class TaskApplication
{
private:
  vector<Task> tasks;
  vector<Task>* tasksPtr = &tasks;
public:
  void runApplication();
  void showMenu();
  void showTasks();
  void createTask();
  void editTask();
  void removeTask();
};

void TaskApplication::runApplication()
{
  showMenu();
}

void TaskApplication::showMenu()
{
  cout << "To display the task list, press the '1' key + 'Enter' key" << endl;
  cout << "To create a task, press the '2' key + 'Enter' key" << endl;
  cout << "To edit a task, press the '3' key + 'Enter' key" << endl;
  cout << "To remove a task, press the '4' key + 'Enter' key" << endl;
  cout << "Press 'q' key + 'Enter' key to exit from program" << endl;

  char ch;

  cin >> ch;

  switch (ch)
  {
  case '1':
    showTasks();
    break;
  case '2':
    createTask();
    break;
  case '3':
    editTask();
    break;
  case '4':
    removeTask();
    break;
  case 'q':
    exit(0);
    break;
  default:
    break;
  }
}

void TaskApplication::showTasks()
{
  for (size_t i = 0; i < tasksPtr->size(); i++)
  {
    cout << "ID: " << (*tasksPtr)[i].id << endl;
    cout << "Name: " << (*tasksPtr)[i].description << endl;
    cout << "Active: " << ((*tasksPtr)[i].isActive ? "Yes" : "No") << endl;
  }

  char ch;

  cout << "Press 'q' key + 'Enter' key to exit to the menu" << endl;
  cin >> ch;

  if (ch == 'q') showMenu();
}

void TaskApplication::createTask()
{
  Task* task = new Task;

  int* id = new int {tasksPtr->size() == 0 ? 0 : (*tasksPtr)[tasksPtr->size() - 1].id + 1};

  cout << "Description: ";
  cin >> task->description;
  
  task->id = *id;
  task->isActive = true;

  tasksPtr->push_back(*task);

  delete id;
  delete task;

  id = nullptr;
  task = nullptr;

  showMenu();
}

void TaskApplication::editTask()
{
  int* id = new int;

  cout << "Enter the task ID and press 'Enter' key" << endl;
  cin >> *id;

  for (size_t i = 0; i < tasksPtr->size(); i++)
  {
    if ((*tasksPtr)[i].id == *id)
    {
      string str;

      cout << "Enter a new task description and press 'Enter' key" << endl;
      cin >> (*tasksPtr)[i].description;

      cout << "Enter the new task activity value and press 'Enter' key" << endl;
      cin >> str;

      (*tasksPtr)[i].isActive = str == "Yes";

      showMenu();
    }
  }

  delete id;

  id = nullptr;
}

void TaskApplication::removeTask()
{
  int* id = new int;

  cout << "Enter the task ID and press 'Enter' key" << endl;
  cin >> *id;

  for (size_t i = 0; i < tasksPtr->size(); i++)
  {
    if ((*tasksPtr)[i].id == *id)
    {
      tasksPtr->erase(tasksPtr->begin() + i);

      showMenu();
    }
  }

  delete id;

  id = nullptr;
}

int main()
{
  TaskApplication taskApplication;

  taskApplication.runApplication();
}
