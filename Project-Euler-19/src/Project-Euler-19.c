/*
 ============================================================================
 Name        : Project-Euler-19.c
 Author      : kanurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define START_YEAR 1900
#define START_MONTH 1

enum Days {
	mon, sun, tue, wed, thr, fri, sat
};

int months[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int isLeapYear(int year) {

	return ((((year % 100)) && (!(year % 4))) || (!(year % 400)));
}
int getLeapYearsCount(int startYear, int lastyear) { //both included
	int count = 0, year;
	if (startYear > lastyear)
		return count;

	for (year = startYear; year <= lastyear; year++) {

		if (isLeapYear(year)) {
			count++;
		}
	}
	return count;
}
int getDayNumber(int startYear,int currentMonth, int currentYear) { //return no of days before this month past.
	int monthNumber, dayCount = 0, leapYearsCount, previousYear,
			daysToPreviousYear = 0;
	int daysInCurrentyear = 0;

	previousYear = currentYear - 1;
	leapYearsCount = getLeapYearsCount(startYear, previousYear);

	daysToPreviousYear = 365 * (previousYear - startYear + 1) + leapYearsCount;

	for (monthNumber = 1; monthNumber < currentMonth; monthNumber++) {

		if (monthNumber == 2 && isLeapYear(currentYear)) {
			daysInCurrentyear += (months[monthNumber] + 1);

		} else {
			daysInCurrentyear += months[monthNumber];
		}
	}

	dayCount = daysToPreviousYear + daysInCurrentyear;

	return dayCount;
}
int main(void) {

	int year, month, sundayCount = 0, dayCount;

	for (year = 1901; year <= 2000; year++) {
		for (month = START_MONTH; month <= 12; month++) {

			dayCount = getDayNumber(START_YEAR,month, year) + 1;
			if (dayCount % 7 == 0) {
				sundayCount++;
			}
		}
	}

	printf("%d", sundayCount);

	return EXIT_SUCCESS;
}
