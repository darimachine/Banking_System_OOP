# Banking_System NO DYNAMIC,STATIC CASTS!!!

# Banking System OOP Project

## Description

This project is a banking system simulation implemented using Object-Oriented Programming (OOP) principles in C++. The system includes functionality for managing banks, clients, bank employees, and external employees. The system supports various operations such as creating banks, signing up users, logging in, and handling different user commands.

## Installation

To set up the project on your local machine, follow these steps:

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/darimachine/Banking_System_OOP
    cd Banking_System_OOP
    ```

2. **Open the Project in Visual Studio**:
    - Open Visual Studio.
    - Go to `File` > `Open` > `Project/Solution`.
    - Navigate to the cloned repository and open the solution file (`.sln`).
    - If you face problems while Building, create new project and paste folders,with .cpp and .h files in your project, Or put every .h and .cpp in to your project but you must fix #include paths!!

3. **Build the Project**:
    - In Visual Studio, build the solution by going to `Build` > `Build Solution`.

## Usage

After building the project, you can run the executable to start the banking system simulation. The following commands are available:

### General Commands

- `create_bank <bank_name>`: Creates a new bank.
- `signup`: Opens the menu for signing up a client, employee, or external employee.
- `login`: Opens the menu for logging in with username and password.
- `save`: Saves the current progress and exits the program.
- `load`: Loads the previous progress and changes the logged user to the previous one.
- `help`: Displays more instructions on what you can do when logged in.

### User Commands

Depending on the logged-in user type (Client, Bank Employee, or External Employee), different commands are available. Once logged in, type `help` to see the specific commands for your user type.

## Features

- **Bank Management**: Create and manage multiple banks.
- **User Management**: Sign up and log in as a client, bank employee, or external employee.
- **Task Management**: Handle various tasks specific to bank employees and external employees.
- **Persistence**: Save and load the state of the system.

### Design Patterns Used

This project employs several design patterns to ensure a robust and maintainable codebase. Here are some of the patterns used:

1. **Singleton**: 
    - The `BankSystem` class is implemented as a singleton to ensure that there is only one instance of the banking system running, providing a global point of access to the system.

2. **Factory Method**: 
    - The project uses factory methods to create instances of different types of tasks (e.g., `OpenAccountTask`, `CloseAccountTask`). This pattern helps in encapsulating the object creation process and makes the code more modular.

3. **Command Pattern**:
    - The `RunCommand` class and various command classes (`HandleBankEmployeeCommands`, `HandleClientCommands`, `HandleExternalEmployeeCommand`, `HandleNoneCommand`) use the command pattern. This encapsulates a request as an object, thereby allowing for parameterization of clients with queues, requests, and operations.

4. **Strategy Pattern**:
    - The system utilizes the strategy pattern to handle different types of user commands based on the logged-in user type. Different command classes implement the same interface but provide different behavior.

### How the Program Works

1. **Initialization**:
    - The system starts by initializing the `BankSystem` singleton. This involves setting up the necessary data structures and loading any saved state from previous sessions if available.

2. **User Interaction**:
    - Users interact with the system through a command-line interface. They can create banks, sign up as different types of users, log in, and execute various commands.

3. **Command Execution**:
    - Based on the logged-in user type, different command handlers are invoked. These handlers execute the appropriate actions (e.g., creating an account, handling tasks) and provide feedback to the user.

4. **Task Management**:
    - Bank employees and external employees receive tasks that they need to complete. These tasks are managed using a task queue and are processed based on the specific requirements of each task type.

5. **Persistence**:
    - The system supports saving and loading its state. Users can save the current state of the system, including all banks, users, and tasks, and reload this state in future sessions.


