
#include "../include/minitalk.h"
#include <signal.h>
#include <unistd.h>

int i = 0;

void sig_handler(int sig)
{
	if (sig == SIGUSR1)
			i++;
	else if (sig == SIGUSR2 && i != 0)
	{
		printf("%c\n", i);
		printf("mensaje terminado\n");
		i = 0;
	}
	else
		i = 0;
}


int main(void)
{
	signal(SIGUSR1, &sig_handler);
	signal(SIGUSR2, &sig_handler);

	ft_printf("PID:\t%d\n", getpid());
	while (1)
		pause();
	return (0);
}