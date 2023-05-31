# Function Reference

| Function      	| Description                                                  									|
| ----------------- | --------------------------------------------------------------------------------------------- |
| readline      	| Reads a line of input from the user                           								|
| rl_clear_history 	| Clears the history of previously entered lines              									|
| rl_on_new_line 	| Sets the terminal to a new line                               								|
| rl_replace_line 	| Replaces the current line of input with a new line            								|
| rl_redisplay  	| Redraws the current input line                                								|
| add_history   	| Adds a line to the history of previously entered lines        								|
| printf        	| Prints formatted output to the console                        								|
| malloc        	| Allocates memory for a block of a specified size              								|
| free          	| Frees a previously allocated block of memory                  								|
| write         	| Writes data to a file descriptor or file                      								|
| access        	| Checks if a file or directory exists and has the specified permissions 						|
| open          	| Opens a file or creates a new file                            								|
| read          	| Reads data from a file descriptor or file                     								|
| close         	| Closes a file descriptor                                      								|
| fork          	| Creates a new process by duplicating the existing process     								|
| wait          	| Suspends execution until any of its child processes terminates								|
| waitpid       	| Suspends execution until a specific child process terminates									|
| wait3         	| Suspends execution until any of its child processes terminates and retrieves resource usage 	|
| wait4         	| Suspends execution until a specific child process terminates and retrieves resource usage 	|
| signal        	| Sets a specific function to handle a particular signal         								|
| sigaction     	| Sets the action for a specific signal                          								|
| sigemptyset   	| Initializes an empty signal set                               								|
| sigaddset     	| Adds a specific signal to a signal set                         								|
| kill          	| Sends a signal to a process                                   								|
| exit          	| Terminates the calling process                                								|
| getcwd        	| Gets the current working directory                            								|
| chdir         	| Changes the current working directory                         								|
| stat          	| Retrieves file or file system status                          								|
| lstat         	| Retrieves file or file system status (does not follow symbolic links) 						|
| fstat         	| Retrieves file status given a file descriptor                 								|
| unlink        	| Removes a file or symbolic link                               								|
| execve        	| Executes a program                                           									|
| dup           	| Duplicates a file descriptor                                  								|
| dup2          	| Duplicates a file descriptor to a specified file descriptor   								|
| pipe          	| Creates a pipe for interprocess communication                 								|
| opendir       	| Opens a directory for reading                                 								|
| readdir       	| Reads a directory entry                                       								|
| closedir      	| Closes a directory                                            								|
| strerror      	| Returns a string describing the error code                    								|
| perror        	| Prints a descriptive error message to stderr                  								|
| isatty        	| Checks if a file descriptor refers to a terminal              								|
| ttyname       	| Returns the name of the terminal associated with a file descriptor 							|
| ttyslot       	| Returns the index of the current terminal in the terminal database 							|
| ioctl         	| Performs control operations on a terminal                     								|
| getenv        	| Retrieves the value of an environment variable                								|
| tcsetattr     	| Sets terminal attributes                                      								|
| tcgetattr     	| Gets terminal attributes                                      								|
| tgetent       	| Initializes the terminfo database                             								|
| tgetflag      	| Retrieves a boolean capability from the terminfo database      								|
| tgetnum       	| Retrieves a numeric capability from the terminfo database      								|
| tgetstr       	| Retrieves a string capability from the terminfo database       								|
| tgoto         	| Translates a cursor motion to a string                        								|
| tputs         	| Outputs a string to the terminal                              								|
| ----------------- | --------------------------------------------------------------------------------------------- |