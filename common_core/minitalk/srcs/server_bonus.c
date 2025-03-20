#include "../ft_printf/ft_printf.h"
#include "../ft_printf/libft/libft.h"
#include <signal.h>

void    send_char(int pid, unsigned char oct)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if ((oct & (1 << bit)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        bit++;
        usleep(100);
    }
}

void    send_string(int pid, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        send_char(pid, (unsigned char)str[i]);
        i++;
    }
    send_char(pid, (unsigned char)'\n');
}

void    handler(int sig, siginfo_t *info, void *context)
{
    static int bit;
    static unsigned int buffer;
    //static int  char_count;

    (void) context;
    //char_count = 0;
    if (sig == SIGUSR1)
        buffer |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", (unsigned char)buffer);
        if ((unsigned char)buffer == '\n')
        {
            ft_printf("Hola?\n");
            send_string(info->si_pid, "Message received\n");
        }
        bit = 0;
        buffer = 0;
        //char_count++;
    }
}

int main(void)
{
    struct sigaction    sigact;

    sigact.sa_sigaction = &handler;
    sigact.sa_flags = SA_SIGINFO;
    ft_printf("Server PID: %d\n", getpid());
    sigaction(SIGUSR2, &sigact, NULL);
	sigaction(SIGUSR1, &sigact, NULL);
    while (1)
        pause();
    return (0);
}