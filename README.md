# Get_next_line

## Introduction
The get_next_line project is a function that reads a file and returns a line, ending with a newline character. This function allows you to read a file line by line, even if the lines are larger than the buffer size provided.

## Implementation
The get_next_line function is implemented in the get_next_line.c file, and relies on two helper functions: prepare_new_line and fixed_line. The former reads from the file descriptor and concatenates the buffer into a temporary string until a newline character is reached or the file is completely read. The latter takes the temporary string and extracts the next line, returning it as a newly-allocated string. Additionally, there is the get_nextline function, which retrieves the rest of the temporary string, starting from the character after the newline character.

Following functions were used:
- ft_strjoining: a function to join two strings.
- ft_strlen: a function to calculate the length of a string.
- ft_strchr: a function that searches for a character in a string.
- prepare_new_line: a function that reads from the file descriptor and prepares a new line.
- fixed_line: a function that fixes the current line if it contains a newline character.
- get_nextline: a function that gets the next line and returns it.
- 
## Usage

To use the get_next_line function, include the get_next_line.h header file in your program, and call the function with the file descriptor of the file you want to read. The function will return the next line of the file as a string, or NULL if there is an error or the end of the file has been reached.

It's important to note that the get_next_line function dynamically allocates memory, so it's necessary to free the memory that is allocated after you are finished with it. You can use the standard library free function for this purpose.

