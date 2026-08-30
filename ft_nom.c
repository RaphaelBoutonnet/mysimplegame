#include "wom.h"

char	*ft_nom(void)
{
	write(1, "\033[2J\033[H\033[?25l", 13); // Efface l'ecran du terminal et le curseur
	struct timespec req = {0, PAUSE_100MS};
	req.tv_nsec = PAUSE_1S; // Set la pause a 1 seconde au lieu de 100ms.
	write(1, "Bienvenue sur World of Malloc.\nChoisis le nom de ton personnage :\n\n", 67);
	char	buffer;
	char	*nomperso;
	nomperso = malloc((sizeof(char) * 50) + 1);
	if (nomperso == NULL)
		return NULL;
	int (i) = 0;
	while (read(0, &buffer, 1) && buffer != '\n')
	{
		if (i == 0)
			write(1, "\nEnchante ", 10);
		write(1, &buffer, 1);
		nomperso[i] = buffer;
		i++;
	}
	nomperso[i] = '\0';
	write(1, " !\n\n", 4);
	nanosleep(&req, NULL); // Pause de 1s
	nanosleep(&req, NULL); // Pause de 1s
	return (nomperso);
}
