/* Finds a country based on dialing code entered by the user, and then prints 
 * information about the country */

#include <stdio.h>

#define NUM_COUNTRIES 32

/* prototypes */
struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[NUM_COUNTRIES] = 
{{"Argentina",              54}, {"Bangladesh",              880},
 {"Brazil",                 55}, {"Burma (Myanmar)",          95},
 {"China",                  86}, {"Colombia",                 57},
 {"Congo, Dem. Rep. of",   243}, {"Egypt",                    20},
 {"Ethiopia",              251}, {"France",                   33},
 {"Germany",                49}, {"India",                    91},
 {"Indonesia",              62}, {"Iran",                     98},
 {"Italy",                  39}, {"Japan",                    81},
 {"Mexico",                 52}, {"Nigeria",                 234},
 {"Pakistan",               92}, {"Philippines",              63},
 {"Poland",                 48}, {"Russia",                    7}, 
 {"South Africa",           27}, {"South Korea",              82},
 {"Spain",                  34}, {"Sudan",                   249},
 {"Thailand",               66}, {"Turkey",                   90},
 {"Ukraine",               380}, {"United Kingdom",           44},
 {"United States",           1}, {"Vietnam",                  84}};

int read_code(const struct dialing_code *a, int n);

int main(void)
{
    int found_code;

    for (;;) {
        found_code = read_code(country_codes, NUM_COUNTRIES); 

        if (found_code == -2) {
            printf("\nError: you have entered an incorrect country code.\n");
            continue;
        } else if (found_code == -1) {
            printf("\nYou have chosen to exit the program; goodbye.\n");
            return 0;
        }

        printf("\nCountry: %s\n", (country_codes[found_code].country));
    }

    return 0;
}

int read_code(const struct dialing_code *a, int n)
{
    int usr_code, i;

    printf("\nPlease enter international dialing code (-1 to quit): \n");
    scanf("%d", &usr_code);

    if (usr_code == -1) {
        return usr_code;
    }

    for (i = 0; i < n; i++) {
        if (a[i].code == usr_code) {
            return i;
        }
    }

    return -2;
}
