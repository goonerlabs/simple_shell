# SIMPLE_SHELL																L
This shell is a command-line emulator that provides an interface for Unix operating systems.

It is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.                                         
                                                                                
main.c
Contains the main code of the shell where all the rest of the other functions are used to make the shell run.

Makes the Shell run continously and also listens for signals when a user presses ctrl + c

Returns 0 on success and 1 when something goes wrong as the shell
