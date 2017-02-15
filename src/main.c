/**************************************
 *
 *
 * ************************************/

#include <stdio.h> //standard input output. used for printf
#include <ctype.h> //used for isprint
#include <unistd.h> //used for getopt
#include <stdlib.h> //used for abort
void qlist ()
{
	printf ("Following is the list of implemented crograms.\n");
	return;
}

void crac_help ()
{
	printf ("This is option help.\n");
	return;
}

int main(int argc, char *argv[])
{
	int opt;
	int qvalue;
	int index;

	while((opt = getopt(argc, argv, "lhq:")) != -1) {
		switch (opt) {
			case 'q' :
				qvalue = atoi(optarg);
				printf ("qvalue: %s\n", qvalue);
				break;
			case 'l' :
				qlist();
				break;
			case 'h' :
				crac_help();
				break;
			case '?' : 
		printf ("%c\n", opt);
		printf ("%c\n", optopt);
				if (optopt == 'q')
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint(optopt))
					fprintf (stderr, "Unknown option '-%c'.\n", optopt);
				else
					fprintf (stderr, "Unknown option character '\\x%x'.\n", optopt);
				return 1;
			default  :
				abort();
		}
		for (index = optind; index < argc; index++)
			printf("Non option argument %s\n", argv[index]);
		return 0;
	}
}
