#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int is_leap_year(int year);
double calculate_F(double x);
int minutes_to_closest(int hours, int minutes);

int main()
{
	setlocale(LC_CTYPE, "RUS");

	printf("=== Задание 1 ===\n");
	int year;
	printf("Введите год: ");
	scanf("%d", &year);

	int is_leap = is_leap_year(year);
	if (is_leap == 1)

	{
		printf("Год %d високосный\n", year);
	}

	else

	{
		printf("Год %d не високосный\n", year);
	}

	printf("=== Задание 2 ===\n");
	double x;
	printf("Введите значение x: ");
	scanf("%lf", &x);

	double F = calculate_F(x);
	printf("F(%.2lf) = %.4lf (%s)\n", x, F, (x <= 7.0) ? "x <= 7" : "x > 7");

	printf("=== Домашнее задание ===\n");
	int hours, minutes;
	printf("Введите время (часы 0-23): ");
	scanf("%d", &hours);
	printf("Введите время (минуты 0-59): ");
	scanf("%d", &minutes);

	int closest_minutes = minutes_to_closest(hours, minutes);

	int current = hours * 60 + minutes;
	int to_noon = abs(720 - current);
	int to_midnight = abs(1440 - current);
	if (current < 720)

	{
		to_midnight = current;
	}

	printf("Ближайшее время: %s. Осталось минут: %d\n", (to_noon <= to_midnight) ? "до полудня" : "до полуночи", closest_minutes);

	return 0;
}

int is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))

	{
		return 1;
	}

	return 0;
}

double calculate_F(double x)
{
	if (x <= 7.0)

	{
		return -3.0 * x + 9.0;
	}

	else

	{
		return 1.0 / (x - 7.0);
	}
}

int minutes_to_closest(int hours, int minutes)

{
	int all_minutes = hours * 60 + minutes;
	int diff_noon = abs(all_minutes - 720);
	int diff_midnight_start = all_minutes;
	int diff_midnight_end = 1440 - all_minutes;

	int diff_midnight = (diff_midnight_start < diff_midnight_end) ? diff_midnight_start : diff_midnight_end;

	if (diff_noon <= diff_midnight)

	{
		return diff_noon;	
	}

	else

	{
		return diff_midnight;
	}
}
