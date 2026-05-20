#include <pthreadh>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	pthread_t tid;
	unsigned int count;
	unsigned int i;

	tid = pthread_self();
	return(0);
}