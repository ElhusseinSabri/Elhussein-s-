
/*
 * CS354: Shell project
 *
 * Template file.
 * You will need to add more code here to execute the command table.
 *
 * NOTE: You are responsible for fixing any bugs this code may have!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include "command.h"
using namespace std;

SimpleCommand::SimpleCommand()
{
	// Creat available space for 5 arguments
	_numberOfAvailableArguments = 5;
	_numberOfArguments = 0;
	_arguments = (char **) malloc( _numberOfAvailableArguments * sizeof( char * ) );
}

void
SimpleCommand::insertArgument( char * argument )
{
	if ( _numberOfAvailableArguments == _numberOfArguments  + 1 ) {
		// Double the available space
		_numberOfAvailableArguments *= 2;
		_arguments = (char **) realloc( _arguments,
				  _numberOfAvailableArguments * sizeof( char * ) );
	}
	
	_arguments[ _numberOfArguments ] = argument;

	// Add NULL argument at the end
	_arguments[ _numberOfArguments + 1] = NULL;
	
	_numberOfArguments++;
}

Command::Command()
{
	// Create available space for one simple command
	_numberOfAvailableSimpleCommands = 1;
	_simpleCommands = (SimpleCommand **)
		malloc( _numberOfSimpleCommands * sizeof( SimpleCommand * ) );

	_numberOfSimpleCommands = 0;
	_outFile = 0;
	_inputFile = 0;
	_errFile = 0;
	_background = 0;
}

void
Command::insertSimpleCommand( SimpleCommand * simpleCommand )
{
	if ( _numberOfAvailableSimpleCommands == _numberOfSimpleCommands ) {
		_numberOfAvailableSimpleCommands *= 2;
		_simpleCommands = (SimpleCommand **) realloc( _simpleCommands,
			 _numberOfAvailableSimpleCommands * sizeof( SimpleCommand * ) );
	}
	
	_simpleCommands[ _numberOfSimpleCommands ] = simpleCommand;
	_numberOfSimpleCommands++;
}

void
Command:: clear()
{
	for ( int i = 0; i < _numberOfSimpleCommands; i++ ) {
		for ( int j = 0; j < _simpleCommands[ i ]->_numberOfArguments; j ++ ) {
			free ( _simpleCommands[ i ]->_arguments[ j ] );
		}
		
		free ( _simpleCommands[ i ]->_arguments );
		free ( _simpleCommands[ i ] );
	}

	if ( _outFile ) {
		free( _outFile );
	}

	if ( _inputFile ) {
		free( _inputFile );
	}

	if ( _errFile ) {
		free( _errFile );
	}

	_numberOfSimpleCommands = 0;
	_outFile = 0;
	_inputFile = 0;
	_errFile = 0;
	_background = 0;
}

void
Command::print()
{
	printf("\n\n");
	printf("              COMMAND TABLE                \n");
	printf("\n");
	printf("  #   Simple Commands\n");
	printf("  --- ----------------------------------------------------------\n");
	
	for ( int i = 0; i < _numberOfSimpleCommands; i++ ) {
		printf("  %-3d ", i );
		for ( int j = 0; j < _simpleCommands[i]->_numberOfArguments; j++ ) {
			printf("\"%s\" \t", _simpleCommands[i]->_arguments[ j ] );
			
		}
	}

	printf( "\n\n" );
	printf( "  Output       Input        Error        Background\n" );
	//printf("\"%s\" \t", _simpleCommands[0]->_arguments[ 1 ] );

	printf( "  ------------ ------------ ------------ ------------\n" );
	printf( "  %-12s %-12s %-12s %-12s\n", _outFile?_outFile:"default",
		_inputFile?_inputFile:"default", _errFile?_errFile:"default",
		_background?"YES":"NO");
	printf( "\n\n" );
	
}

void
Command::execute()
{  int pid;
	// Don't do anything if there are no simple commands
	if ( _numberOfSimpleCommands == 0 ) {
		prompt();
		return;
	}
		 
   if ( _numberOfSimpleCommands > 1 ) {
		
    
		
		int fdpipe[2];
	if ( pipe(fdpipe) == -1) {
		perror( "cat_grep: pipe");
		exit( 2 );
	}
   
    else{
		int pid1=fork();
		if (pid1 == 0) {


	dup2( fdpipe[ 1 ], 1 );
		
		close(fdpipe[1]);

		execvp(_simpleCommands[0]->_arguments[0],_simpleCommands[0]->_arguments);
         

		}
		else{
			int pid2=fork();
			if(pid2 == 0){
					dup2( fdpipe[0], 0 );
					close(fdpipe[0]);
				execvp(_simpleCommands[1]->_arguments[0],_simpleCommands[1]->_arguments);

			}
		}
	}
		}


		
	
	else {
		
	
	

	// Print contents of Command data structure
	print();
	int defaultin = dup( 0 );
	int defaultout = dup( 1 );
	int defaulterr = dup( 2 );
	int outfd;

    
	pid = fork();
	if ( pid == -1 ) {
		perror( "ls: fork\n");
		exit( 2 );
	}

	if (pid == 0) {
		
		
		if(_inputFile){
            int inpfd=open(_inputFile,0) ;
			dup2(inpfd,0);
		}
        if(_outFile){
			if(_append){
				int outfd = open(_outFile , 0666);
				dup2( outfd, 1 );
	            close( outfd );
				dup2(outfd,1);	
            	dup2( defaultin, 0 );
	            dup2( defaulterr, 2 );
				
				
	 		}
    else{
	int outfd = creat( _outFile, 0666);
	            dup2( outfd, 1 );
	            close( outfd );
				dup2(outfd,1);
					
            	dup2( defaultin, 0 );
	            dup2( defaulterr, 2 );
	}

	
	
 }
	
		close(outfd);
		close( defaultin );
		close( defaultout );
		close( defaulterr );
		
		
		// You can use execvp() instead if the arguments are stored in an array
		execvp(_simpleCommands[0]->_arguments[0], _simpleCommands[0]->_arguments);
		//execvp(_simpleCommands[0]->_arguments[0],_simpleCommands[0]->_arguments);
         


		// exec() is not suppose to return, something went wrong
		//exit( 2 );
	}
	}
	
	if(_background==0){
	waitpid( pid, 0, 0 );
         //exit( 2 );
		 }
	
	clear();
	
	
	prompt();
}



// Shell implementation

void
Command::prompt()
{
	printf("myshell>");
	fflush(stdout);
}

Command Command::_currentCommand;
SimpleCommand * Command::_currentSimpleCommand;

int yyparse(void);

void ctrl_C(int y){
	printf("\nplease write exit if you want to exit the minishell or press enter to return to myshell\n" );
}
void log(int x){
	printf(" \na child was created\n");
	ofstream Myfile("logfile.txt");
	Myfile << "a child was terminated\n";
	Myfile.close();
	
}
 
int 
main()
{   
	Command::_currentCommand.prompt();
	sighandler_t sig=signal(SIGINT,ctrl_C);
	sighandler_t child=signal(SIGCHLD,log);
	 yyparse();
	
   

	
	return 0;
}

