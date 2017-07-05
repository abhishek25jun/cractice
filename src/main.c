/**************************************
 *
 *
 * ************************************/

#include "include.h"
#include <stdio.h> //standard input output. used for printf
#include <ctype.h> //used for isprint
#include <unistd.h> //used for getopt
#include <stdlib.h> //used for abort

int arr[] = {12, 23, 10, 1, 50, 55};

void qlist ()
{
	printf ("Following is the list of implemented crograms.\n");
	printf ("1	count number of set bits in an integer\n");
	printf ("2	reverse bits in an integer\n");
	printf ("3	check if nth bit of integer is ON or OFF\n");
	printf ("4	bubble sort\n");
	printf ("5	selection sort\n");
	printf ("6	insertion sort\n");
	return;
}

void crac_help ()
{
	printf ("This is option help.\n");
	return;
}

void select_crogram(unsigned int option)
{
	switch (option) {
		case 1:
			printf ("count number of set bits in 7\n");
			count_set_bits1(7);
			count_set_bits2(7);
			break;
		case 2:
			printf ("reverse bits in 6\n");
			reverse_bits(6);
			break;
		case 3:
			printf ("check if 8th bit of 0xff000000 is ON or OFF\n");
			check_nth_bit(0xff000000, 8);
			break;
		case 4:
			printf ("bubble sort\n");
			bubblesort(arr, 6);
			break;
		case 5:
			printf ("selection sort\n");
			selectionsort(arr, 6);
			break;
		case 6:
			printf ("insertion sort\n");
			insertionsort(arr, 6);
			break;
		default:
			printf("unknown option\n");
			break;
	}
}

int main(int argc, char *argv[])
{
	unsigned int opt;
	unsigned int qvalue;
	unsigned int index;

	while((opt = getopt(argc, argv, "lhq:")) != -1) {
		switch (opt) {
			case 'q' :
				qvalue = atoi(optarg);
				printf ("qvalue: %d\n", qvalue);
				select_crogram(qvalue);
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
				crac_help();
				abort();
		}
		for (index = optind; index < argc; index++)
			printf("Non option argument %s\n", argv[index]);
		return 0;
	}
}
