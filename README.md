# Project 'SIMPLE SHELL'

This README.md file provides an overview of the various files present in the project and their corresponding functions. Each section corresponds to a specific file, and the functions within that file are listed along with a brief explanation of their purposes.

## `atoi.c`

- **_interactive**: This function handles interactive mode for the shell.
- **_isalpha**: A function to check if a character is alphabetic or not.
- **_atoi**: A custom implementation of the `atoi` function to convert a string to an integer.

## `buitins1.c`

- **_history**: Function related to managing the history of commands.
- **unset_alias**: Function to unset or remove an alias.
- **set_alias**: Function to set or create an alias.
- **print_alias**: Function to print the aliases.
- **_alias**: Function to handle the alias command.

## `buitins.c`

- **_cd**: Function to change the current directory.
- **_customexit**: Function to handle custom exit from the shell.

## `customized_func1.c`

- **_strcpy**: Custom implementation of the `strcpy` function.
- **_strdup**: Custom implementation of the `strdup` function.
- **_puts**: Custom function to print a string.
- **_putchar**: Custom function to print a single character.

## `customized_func.c`

- **_strlen**: Custom implementation of the `strlen` function.
- **_strcmp**: Custom implementation of the `strcmp` function.
- **starts_with**: Function to check if a string starts with a specific prefix.
- **_strcat**: Custom implementation of the `strcat` function.

## `env.c`

- **_customsetenv**: Function to set a custom environment variable.
- **_customunsetenv**: Function to unset a custom environment variable.
- **_env**: Function to display the current environment variables.
- **populate_env_list**: Function to populate a linked list with environment variables.
- **_getenv**: Function to get the value of a specific environment variable.

## `execute.c`

- **fork_cmd**: Function to fork and execute a command.

## `exit.c`

- **_strncpy**: Custom implementation of the `strncpy` function.
- **_strncat**: Custom implementation of the `strncat` function.
- **_strchr**: Custom implementation of the `strchr` function.

## `getenv.c`

- **get_environ**: Function to get the environment variable list.
- **_unsetenv**: Custom implementation of the `unsetenv` function.
- **_setenv**: Custom implementation of the `setenv` function.

## `getinfo.c`

- **clear_info**: Function to clear memory used for storing information.
- **set_info**: Function to set the information related to the shell.
- **free_info**: Function to free the memory allocated for the shell information.

## `get_line.c`

- **input_buf**: Function to handle the input buffer.
- **get_input**: Function to get user input.
- **read_buf**: Function to read from the input buffer.
- **_getline**: Custom implementation of the `getline` function.
- **sigintHandler**: Signal handler function for handling SIGINT.

## `history.c`

- **get_history_file**: Function to get the history file path.
- **write_history**: Function to write the command history to a file.
- **read_history**: Function to read the command history from a file.
- **build_history_list**: Function to build a linked list with command history.
- **renumber_history**: Function to renumber the history nodes.

## `list.c`

- **add_node**: Function to add a new node to the linked list.
- **add_node_end**: Function to add a new node at the end of the linked list.
- **print_list_str**: Function to print the linked list of strings.
- **delete_node_at_index**: Function to delete a node at a specific index.
- **free_list**: Function to free the memory occupied by the linked list.

## `lists1.c`

- **list_len**: Function to get the length of the linked list.
- **list_to_strings**: Function to convert the linked list into an array of strings.
- **print_list**: Function to print the linked list.
- **node_starts_with**: Function to check if a node starts with a specific prefix.
- **get_node_index**: Function to get the index of a specific node in the linked list.

## `main.c`

- **main**: The main function that serves as the entry point for the shell.

## `memory_management.c`

- **bfree**: Function to free a memory block.
- **_memset**: Custom implementation of the `memset` function.
- **ffree**: Function to free a file stream.
- **_realloc**: Custom implementation of the `realloc` function.

## `parser.c`

- **_putfd**: Function to print file descriptors.
- **_putsfd**: Function to write a string to a file descriptor.
- **dup_chars**: Function to duplicate characters from a string.
- **is_executable**: Function to check if a file is executable.
- **find_path**: Function to find the full path of a command.

## `printerr_func.c`

- **_erratoi**: Function to convert a string to an integer, handling errors.
- **print_error**: Function to print error messages.
- **print_d**: Function to print an integer.
- **convert_number**: Function to convert an integer to a string.
- **remove_comments**: Function to remove comments from a string.

## `prompt.c`

- **prompt**: Function to display the shell prompt.

## `shell.h`

- **struct liststr**: Structure definition for the linked list of strings.
- **struct passinfo**: Structure definition for passing information within the shell.
- **struct builtin**: Structure definition for built-in commands.

## `shell_loop.c`

- **is_builtin**: Function to check if a command is a built-in command.
- **check_cmd**: Function to check if a command is valid.
- **hsh**: The main loop function for the shell.

## `tokenizer.c`

- **is_delim**: Function to check if a character is a delimiter.
- **strtow**: Function to tokenize a string into words.

## `variables.c`

- **checkChainCont**: Function to check for chain continuation.
- **substitute_alias**: Function to substitute an alias in the command.
- **isChain**: Function to check if a command contains a chain.
- **substitute_string**: Function to substitute variables in a string.
- **substitute_vars**: Function to substitute variables in the command.
