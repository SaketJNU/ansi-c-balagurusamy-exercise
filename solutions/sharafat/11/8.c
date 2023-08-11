#include <stdio.h>
#include <stdlib.h>

struct date 
{
    int day;
    int month;
    int year;
};

void input_date(struct date *date)
{
    printf("Enter date in DD/MM/YYYY format: ");
    scanf("%d/%d/%d", &date->day, &date->month, &date->year);
}

void validate_data(struct date *date)
{
    if (date->year < 1)
    {
        printf("Invalid year\n");
        exit(1);
    }
    if (date->month < 1 || date->month > 12)
    {
        printf("Invalid month\n");
        exit(1);
    }
    if ((date->day < 1 || date->day > 31) || (date-> day > 30 && (date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11)) || (date->day > 28 && date->month == 2) || (date->day > 29 && date->month == 2 && (date->year % 4 != 0 || (date->year % 100 == 0 && date->year % 400 != 0))))
    {
        printf("Invalid day\n");
        exit(1);
    }
}

int compare_two_date(struct date *one, struct date *two)
{
    if (one->year > two->year)
    {
        return(1);
    }
    else if (one->year < two->year)
    {
        return(0);
    }
    else
    {
        if (one->month > two->month)
        {
            return(1);
        }
        else if (one->month < two->month)
        {
            return(0);
        }
        else
        {
            if (one->day > two->day)
            {
                return(1);
            }
            else if (one->day < two->day)
            {
                return(0);
            }
            else
            {
                return(0);
            }
        }
    }
}

void print_date(struct date *date)
{
    printf("Date: %d/%d/%d\n", date->day, date->month, date->year);
}

int main()
{
    struct date date1, date2;
    input_date(&date1);
    validate_data(&date1);

    input_date(&date2);
    validate_data(&date2);

    if (!compare_two_date(&date1, &date2))
    {
        printf("Earlier date: ");
        print_date(&date1);
    }
    else
    {
        printf("Earlier date: ");
        print_date(&date2);
    }
    return 0;
}