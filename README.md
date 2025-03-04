# File Management Utility

## Overview
This project is a simple command-line utility for managing files in a specified directory. It allows users to list files, create new text files, and delete files within a chosen directory. The program is developed in C and is designed for Windows operating systems.

## Features
- **List Files:** Displays all files in the specified directory.
- **Create File:** Allows the user to create a new text file with a custom name and content.
- **Delete File:** Enables the user to delete a specified file from the directory.
- **Input Handling:** Includes error handling for invalid paths, filenames, and user inputs.

## Prerequisites
- Windows Operating System
- A C compiler (e.g., MinGW, MSVC)

## Compilation
To compile the program, use a C compiler like MinGW:
```sh
gcc -o file_manager file_manager.c
```

## Usage
1. Run the executable:
```sh
file_manager.exe
```
2. Enter the directory path where you want to manage files.
3. Choose an option from the menu:
   - **1:** List files in the directory.
   - **2:** Create a new file (provide a filename and enter content).
   - **3:** Delete an existing file.
   - **4:** Exit the program.

## Example Output
```
Enter the path you want to work in: C:\Users\User\Documents
[INFO] The path has been introduced: C:\Users\User\Documents\

Menu:
1. List files
2. Create a file
3. Delete a file
4. Exit
Choose an option: 1
Files in directory C:\Users\User\Documents:
- file1.txt
- file2.txt
```

## Notes
- The program uses `_access()` to check directory existence and `_findfirst()` for listing files.
- File creation allows writing a single line of text input.
- The program ensures proper memory management by freeing allocated memory before exiting.

## License
This project is open-source and can be modified or distributed freely.
