// ------------------------------------------------------------------------------------------
// Name: Roman Mashak
// Class: 24/FA C PROGRAMMING 1(151-001)
// Abstract: Final_Project_RM
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_RECORDS 1000
#define MAX_STR_LEN 50

// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------



// ------------------------------------------------------------------------------------------
// Name: typedef struct
// Abstract: Household record to collect and use data throughout the project.
// ------------------------------------------------------------------------------------------
typedef struct 
{
	char chrDate[MAX_STR_LEN];
	char chrState[MAX_STR_LEN];
	char chrCounty[MAX_STR_LEN];
	char chrRace[MAX_STR_LEN];
	int intHousehold_size;
	double dblYearly_income;
} HouseholdRecord;


// ------------------------------------------------------------------------------------------
// Name: readRecords
// Abstract: Read and Store data from Sample.csv to HouseholdRecord.
// ------------------------------------------------------------------------------------------
void readRecords(HouseholdRecord records[], int* count, FILE* file)
{
	char chrLine[300];
	while (fgets(chrLine, sizeof(chrLine), file))
	{
		sscanf_s(chrLine, "%[^,],%[^,],%[^,],%[^,],%d,%lf", records[*count].chrDate, sizeof(records[*count].chrDate), records[*count].chrState, sizeof(records[*count].chrState),records[*count].chrCounty, sizeof(records[*count].chrCounty), records[*count].chrRace, sizeof(records[*count].chrRace), &records[*count].intHousehold_size, &records[*count].dblYearly_income);
		(*count) += 1;
	}
}


// ------------------------------------------------------------------------------------------
// Name: displayTotalHouseholds
// Abstract: Function that displays the total amount of people surveyed.
// ------------------------------------------------------------------------------------------
void displayTotalHouseholds(HouseholdRecord records[], int count) 
{
	printf("\nTotal Households Surveyed: %d\n", count);
}


// ------------------------------------------------------------------------------------------
// Name: displayTotalByCounty
// Abstract: Function that displays the total amount of people surveyed, based on the county they live in, giving an average state total.
// ------------------------------------------------------------------------------------------
void displayTotalByCounty(HouseholdRecord records[], int count)
{
	int intHamilton = 0;
	int intButler = 0;
	int intBoone = 0;
	int intKenton = 0;

	for (int intIndex = 0; intIndex < count; intIndex += 1)
	{
		if (strcmp(records[intIndex].chrCounty, "Hamilton") == 0) intHamilton += 1;
		else if (strcmp(records[intIndex].chrCounty, "Butler") == 0) intButler += 1;
		else if (strcmp(records[intIndex].chrCounty, "Boone") == 0) intBoone += 1;
		else if (strcmp(records[intIndex].chrCounty, "Kenton") == 0) intKenton += 1;
	}

	printf("\nTotal Households surveyed by County:\n");
	printf("(Ohio): %d\n", intHamilton + intButler);
	printf("Hamilton: %d\n", intHamilton);
	printf("Butler: %d\n", intButler);
	printf("(Kentucky): %d\n", intBoone + intKenton);
	printf("Boone: %d\n", intBoone);
	printf("Kenton: %d\n", intKenton);
}


// ------------------------------------------------------------------------------------------
// Name: displayTotalByRace
// Abstract: Function that displays the total amount of people surveyed, based on their race.
// ------------------------------------------------------------------------------------------
void displayTotalByRace(HouseholdRecord records[], int count)
{
	int intCaucasian = 0;
	int	intAfricanAmerican = 0;
	int	intHispanic = 0;
	int	intAsian = 0;
	int	intOther = 0;

	for (int intIndex = 0; intIndex < count; intIndex += 1)
	{
		if (strcmp(records[intIndex].chrRace, "Caucasian") == 0) intCaucasian += 1;
		else if (strcmp(records[intIndex].chrRace, "African American") == 0) intAfricanAmerican += 1;
		else if (strcmp(records[intIndex].chrRace, "Hispanic") == 0) intHispanic += 1;
		else if (strcmp(records[intIndex].chrRace, "Asian") == 0) intAsian += 1;
		else if (strcmp(records[intIndex].chrRace, "Other") == 0) intOther += 1;
	}

	printf("\nTotal Households Surveyed by Race:\n");
	printf("(Caucasian): %d\n", intCaucasian);
	printf("(African American): %d\n", intAfricanAmerican);
	printf("(Hispanic): %d\n", intHispanic);
	printf("(Asian): %d\n", intAsian);
	printf("(Other): %d\n", intOther);

	return;
}


// ------------------------------------------------------------------------------------------
// Name: displayAverageIncome
// Abstract: Function that displays the Average income of the total people surveyed.
// ------------------------------------------------------------------------------------------
void displayAverageIncome(HouseholdRecord records[], int count)
{
	double dblTotalIncome = 0;

	for (int intIndex = 0; intIndex < count; intIndex += 1)
	{
		dblTotalIncome += records[intIndex].dblYearly_income;
	}

	printf("\nAverage Household Income: $%.2lf\n", dblTotalIncome / count);

	return;
}


// ------------------------------------------------------------------------------------------
// Name: displayAverageIncomeByCounty
// Abstract: Function that displays the Average income of each county, giving an average state income.
// ------------------------------------------------------------------------------------------
void displayAverageIncomeByCounty(HouseholdRecord records[], int count)
{
	int intHamilton = 0;
	int intButler = 0;
	int intBoone = 0;
	int intKenton = 0;

	double dblHamiltonIncome = 0;
	double dblButlerIncome = 0;
	double dblBooneIncome = 0;
	double dblKentonIncome = 0;

	for (int intIndex = 0; intIndex < count; intIndex += 1)
	{
		if (strcmp(records[intIndex].chrCounty, "Hamilton") == 0) 
		{
			dblHamiltonIncome += records[intIndex].dblYearly_income;
			intHamilton += 1;
		}
		else if (strcmp(records[intIndex].chrCounty, "Butler") == 0)
		{
			dblButlerIncome += records[intIndex].dblYearly_income;
			intButler += 1;
		}
		else if (strcmp(records[intIndex].chrCounty, "Boone") == 0)
		{
			dblBooneIncome += records[intIndex].dblYearly_income;
			intBoone += 1;
		}
		else if (strcmp(records[intIndex].chrCounty, "Kenton") == 0)
		{
			dblKentonIncome += records[intIndex].dblYearly_income;
			intKenton += 1;
		}
	}

	printf("\nAverage Household Income by County & State:\n");
	printf("(Ohio): %.2lf\n", ((dblHamiltonIncome + dblButlerIncome) / (intHamilton + intButler)));
	printf("Hamilton: %.2lf\n", dblHamiltonIncome);
	printf("Butler: %.2lf\n", dblButlerIncome);
	printf("(Kentucky): %.2lf\n", ((dblBooneIncome + dblKentonIncome) / (intBoone + intKenton)));
	printf("Boone: %.2lf\n", dblBooneIncome);
	printf("Kenton: %.2lf\n", dblKentonIncome);

	return;
}


// ------------------------------------------------------------------------------------------
// Name: displayAverageIncomeByRace
// Abstract: Function that displays the Average income of each race.
// ------------------------------------------------------------------------------------------
void displayAverageIncomeByRace(HouseholdRecord records[], int count)
{
	int intCaucasian = 0;
	int	intAfricanAmerican = 0;
	int	intHispanic = 0;
	int	intAsian = 0;
	int	intOther = 0;

	double dblCaucasianIncome = 0;
	double dblAfricanAmericanIncome = 0;
	double dblHispanicIncome = 0;
	double dblAsianIncome = 0;
	double dblOtherIncome = 0;

	for (int intIndex = 0; intIndex < count; intIndex += 1) 
	{
		if (strcmp(records[intIndex].chrRace, "Caucasian") == 0)
		{
			dblCaucasianIncome += records[intIndex].dblYearly_income;
			intCaucasian += 1;
		}
		else if (strcmp(records[intIndex].chrRace, "African American") == 0)
		{
			dblAfricanAmericanIncome += records[intIndex].dblYearly_income;
			intAfricanAmerican += 1;
		}
		else if (strcmp(records[intIndex].chrRace, "Hispanic") == 0)
		{
			dblHispanicIncome += records[intIndex].dblYearly_income;
			intHispanic += 1;
		}
		else if (strcmp(records[intIndex].chrRace, "Asian") == 0)
		{
			dblAsianIncome += records[intIndex].dblYearly_income;
			intAsian += 1;
		}
		else if (strcmp(records[intIndex].chrRace, "Other") == 0)
		{
			dblOtherIncome += records[intIndex].dblYearly_income;
			intOther += 1;
		}
	}

	printf("\nAverage Household Income by Race:\n");

	if (intCaucasian > 0)
	{
		printf("(Caucasian): %.2lf\n", dblCaucasianIncome / intCaucasian);
	}
	else
	{
		printf("(Caucasian): 0\n");
	}

	if (intAfricanAmerican > 0)
	{
		printf("(African American): %.2lf\n", dblAfricanAmericanIncome / intAfricanAmerican);
	}
	else
	{
		printf("(African American): 0\n");
	}

	if (intHispanic > 0)
	{
		printf("(Hispanic): %.2lf\n", dblHispanicIncome / intHispanic);
	}
	else
	{
		printf("(Hispanic): 0\n");
	}

	if (intAsian > 0)
	{
		printf("(Asian): %.2lf\n", dblAsianIncome / intAsian);
	}
	else
	{
		printf("(Asian): 0\n");
	}

	if (intOther > 0)
	{
		printf("(Other): %.2lf\n", dblOtherIncome / intOther);
	}
	else
	{
		printf("(Other): 0\n");
	}

	return;
}


// ------------------------------------------------------------------------------------------
// Name: displayPovertyStats
// Abstract: Function that displays the average percentage of people in poverty.
// ------------------------------------------------------------------------------------------
void displayPovertyStats(HouseholdRecord records[], int count)
{
	int intPovertyCount = 0;

	for (int intIndex = 0; intIndex < count; intIndex += 1)
	{
		if (records[intIndex].intHousehold_size == 1 && records[intIndex].dblYearly_income < 12000)
		{
			intPovertyCount += 1;
		}
		else if (records[intIndex].intHousehold_size == 2 && records[intIndex].dblYearly_income < 18000)
		{
			intPovertyCount += 1;
		}
		else if (records[intIndex].intHousehold_size == 3 && records[intIndex].dblYearly_income < 25000)
		{
			intPovertyCount += 1;
		}
		else if (records[intIndex].intHousehold_size == 4 && records[intIndex].dblYearly_income < 30000)
		{
			intPovertyCount += 1;
		}
		else if (records[intIndex].intHousehold_size >= 5 && records[intIndex].dblYearly_income < 40000)
		{
			intPovertyCount += 1;
		}
	}

	printf("\nPercentage Below Poverty: %d%%\n", (intPovertyCount * 100) / count);

	return;
}


// ------------------------------------------------------------------------------------------
// Name: displayPovertyStatsByCounty
// Abstract: Function that displays the average percentage of people in poverty based on the county, giving an average poverty percentage per state.
// ------------------------------------------------------------------------------------------
void displayPovertyStatsByCounty(HouseholdRecord records[], int count)
{
	int intHamilton = 0;
	int intButler = 0;
	int intBoone = 0;
	int intKenton = 0;

	int intHamiltonPoverty = 0;
	int intButlerPoverty = 0;
	int intBoonePoverty = 0;
	int intKentonPoverty = 0;

	for (int intIndex = 0; intIndex < count; intIndex += 1)
	{
		if (strcmp(records[intIndex].chrCounty, "Hamilton") == 0)
		{
			if (records[intIndex].intHousehold_size == 1 && records[intIndex].dblYearly_income < 12000)
			{
				intHamiltonPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 2 && records[intIndex].dblYearly_income < 18000)
			{
				intHamiltonPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 3 && records[intIndex].dblYearly_income < 25000)
			{
				intHamiltonPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 4 && records[intIndex].dblYearly_income < 30000)
			{
				intHamiltonPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size >= 5 && records[intIndex].dblYearly_income < 40000)
			{
				intHamiltonPoverty += 1;
			}

			intHamilton += 1;
		}
		else if (strcmp(records[intIndex].chrCounty, "Butler") == 0)
		{
			if (records[intIndex].intHousehold_size == 1 && records[intIndex].dblYearly_income < 12000)
			{
				intButlerPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 2 && records[intIndex].dblYearly_income < 18000)
			{
				intButlerPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 3 && records[intIndex].dblYearly_income < 25000)
			{
				intButlerPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 4 && records[intIndex].dblYearly_income < 30000)
			{
				intButlerPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size >= 5 && records[intIndex].dblYearly_income < 40000)
			{
				intButlerPoverty += 1;
			}

			intButler += 1;
		}
		else if (strcmp(records[intIndex].chrCounty, "Boone") == 0)
		{
			if (records[intIndex].intHousehold_size == 1 && records[intIndex].dblYearly_income < 12000)
			{
				intBoonePoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 2 && records[intIndex].dblYearly_income < 18000)
			{
				intBoonePoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 3 && records[intIndex].dblYearly_income < 25000)
			{
				intBoonePoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 4 && records[intIndex].dblYearly_income < 30000)
			{
				intBoonePoverty += 1;
			}
			else if (records[intIndex].intHousehold_size >= 5 && records[intIndex].dblYearly_income < 40000)
			{
				intBoonePoverty += 1;
			}

			intBoone += 1;
		}
		else if (strcmp(records[intIndex].chrCounty, "Kenton") == 0)
		{
			if (records[intIndex].intHousehold_size == 1 && records[intIndex].dblYearly_income < 12000)
			{
				intKentonPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 2 && records[intIndex].dblYearly_income < 18000)
			{
				intKentonPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 3 && records[intIndex].dblYearly_income < 25000)
			{
				intKentonPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 4 && records[intIndex].dblYearly_income < 30000)
			{
				intKentonPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size >= 5 && records[intIndex].dblYearly_income < 40000)
			{
				intKentonPoverty += 1;
			}

			intKenton += 1;
		}
	}

	printf("\nPercentage of Households in Poverty by County & State:\n");
	
	if (intHamilton > 0 || intButler > 0)
	{
		printf("(Ohio): %d%%\n", (((intHamiltonPoverty + intButlerPoverty) * 100) / (intHamilton + intButler)));
	}
	else
	{
		printf("(Ohio): 0%\n");
	}

	if (intHamilton > 0)
	{
		printf("Hamilton: %d%%\n", ((intHamiltonPoverty * 100) / intHamilton));
	}
	else
	{
		printf("Hamilton: 0%\n");
	}

	if (intButler > 0)
	{
		printf("Butler: %d%%\n", ((intButlerPoverty * 100) / intButler));
	}
	else
	{
		printf("Butler: 0%\n");
	}

	if (intHamilton > 0 || intButler > 0)
	{
		printf("(Kentucky): %d%%\n", (((intBoonePoverty + intKentonPoverty) * 100) / (intBoone + intKenton)));
	}
	else
	{
		printf("(Kentucky): 0%\n");
	}

	if (intBoone > 0)
	{
		printf("Boone: %d%%\n", ((intBoonePoverty * 100) / intBoone));
	}
	else
	{
		printf("Boone: 0%\n");
	}

	if (intKenton > 0)
	{
		printf("Kenton: %d%%\n", ((intKentonPoverty * 100) / intKenton));
	}
	else
	{
		printf("Kenton: 0%\n");
	}

	return;
}


// ------------------------------------------------------------------------------------------
// Name: displayPovertyStatsByRace
// Abstract: Function that displays the average percentage of people in poverty by race.
// ------------------------------------------------------------------------------------------
void displayPovertyStatsByRace(HouseholdRecord records[], int count)
{
	int intCaucasian = 0;
	int	intAfricanAmerican = 0;
	int	intHispanic = 0;
	int	intAsian = 0;
	int	intOther = 0;

	int intCaucasianPoverty = 0;
	int	intAfricanAmericanPoverty = 0;
	int	intHispanicPoverty = 0;
	int	intAsianPoverty = 0;
	int	intOtherPoverty = 0;

	for (int intIndex = 0; intIndex < count; intIndex += 1)
	{
		if (strcmp(records[intIndex].chrRace, "Caucasian") == 0)
		{
			if (records[intIndex].intHousehold_size == 1 && records[intIndex].dblYearly_income < 12000)
			{
				intCaucasianPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 2 && records[intIndex].dblYearly_income < 18000)
			{
				intCaucasianPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 3 && records[intIndex].dblYearly_income < 25000)
			{
				intCaucasianPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 4 && records[intIndex].dblYearly_income < 30000)
			{
				intCaucasianPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size >= 5 && records[intIndex].dblYearly_income < 40000)
			{
				intCaucasianPoverty += 1;
			}

			intCaucasian += 1;
		}
		else if (strcmp(records[intIndex].chrRace, "African American") == 0)
		{
			if (records[intIndex].intHousehold_size == 1 && records[intIndex].dblYearly_income < 12000)
			{
				intAfricanAmericanPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 2 && records[intIndex].dblYearly_income < 18000)
			{
				intAfricanAmericanPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 3 && records[intIndex].dblYearly_income < 25000)
			{
				intAfricanAmericanPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 4 && records[intIndex].dblYearly_income < 30000)
			{
				intAfricanAmericanPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size >= 5 && records[intIndex].dblYearly_income < 40000)
			{
				intAfricanAmericanPoverty += 1;
			}

			intAfricanAmerican += 1;
		}
		else if (strcmp(records[intIndex].chrRace, "Hispanic") == 0)
		{
			if (records[intIndex].intHousehold_size == 1 && records[intIndex].dblYearly_income < 12000)
			{
				intHispanicPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 2 && records[intIndex].dblYearly_income < 18000)
			{
				intHispanicPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 3 && records[intIndex].dblYearly_income < 25000)
			{
				intHispanicPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 4 && records[intIndex].dblYearly_income < 30000)
			{
				intHispanicPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size >= 5 && records[intIndex].dblYearly_income < 40000)
			{
				intHispanicPoverty += 1;
			}

			intHispanic += 1;
		}
		else if (strcmp(records[intIndex].chrRace, "Asian") == 0)
		{
			if (records[intIndex].intHousehold_size == 1 && records[intIndex].dblYearly_income < 12000)
			{
				intAsianPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 2 && records[intIndex].dblYearly_income < 18000)
			{
				intAsianPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 3 && records[intIndex].dblYearly_income < 25000)
			{
				intAsianPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 4 && records[intIndex].dblYearly_income < 30000)
			{
				intAsianPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size >= 5 && records[intIndex].dblYearly_income < 40000)
			{
				intAsianPoverty += 1;
			}

			intAsian += 1;
		}
		else if (strcmp(records[intIndex].chrRace, "Other") == 0)
		{
			if (records[intIndex].intHousehold_size == 1 && records[intIndex].dblYearly_income < 12000)
			{
				intOtherPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 2 && records[intIndex].dblYearly_income < 18000)
			{
				intOtherPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 3 && records[intIndex].dblYearly_income < 25000)
			{
				intOtherPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size == 4 && records[intIndex].dblYearly_income < 30000)
			{
				intOtherPoverty += 1;
			}
			else if (records[intIndex].intHousehold_size >= 5 && records[intIndex].dblYearly_income < 40000)
			{
				intOtherPoverty += 1;
			}

			intOther += 1;
		}
	}

	printf("\nPercentage of Households in Poverty by Race:\n");

	if (intCaucasian > 0)
	{
		printf("(Caucasian): %d%%\n", ((intCaucasianPoverty * 100) / intCaucasian));
	}
	else
	{
		printf("(Caucasian): 0\n");
	}

	if (intAfricanAmerican > 0)
	{
		printf("(African American): %d%%\n", ((intAfricanAmericanPoverty * 100) / intAfricanAmerican));
	}
	else
	{
		printf("(African American): 0\n");
	}

	if (intHispanic > 0)
	{
		printf("(Hispanic): %d%%\n", ((intHispanicPoverty * 100) / intHispanic));
	}
	else
	{
		printf("(Hispanic): 0\n");
	}

	if (intAsian > 0)
	{
		printf("(Asian): %d%%\n", ((intAsianPoverty * 100) / intAsian));
	}
	else
	{
		printf("(Asian): 0\n");
	}

	if (intOther > 0)
	{
		printf("(Other): %d%%\n", ((intOtherPoverty * 100) / intOther));
	}
	else
	{
		printf("(Other): 0\n");
	}

	return;
}


// ------------------------------------------------------------------------------------------
// Name: clearRecords
// Abstract: Function that clears the Household record.
// ------------------------------------------------------------------------------------------
void clearRecords()
{
	FILE *file = fopen("sample.csv", "w");
	if (file != NULL) 
	{
		fclose(file);
		printf("All household records have been cleared.\n");
	}
	else 
	{
		printf("Error clearing records.\n");
	}
}


// ------------------------------------------------------------------------------------------
// Name: displayMenu
// Abstract: Function that receives input the user makes to then display the information using Household records.
// ------------------------------------------------------------------------------------------
void displayMenu(HouseholdRecord records[], int count) {
	char chrUserChoice;

	printf("\nSelect choice:\n");
	printf("A. Total Households Surveyed\n");
	printf("B. Total Households Surveyed by County and State\n");
	printf("C. Total Households Surveyed by Race\n");
	printf("D. Average Household Income\n");
	printf("E. Average Household Income by County and State\n");
	printf("F. Average Household Income by Race\n");
	printf("G. Percentage below Poverty\n");
	printf("H. Percentage below Poverty by county and state\n");
	printf("I. Percentage below Poverty by race\n");
	printf("J. Exit\n");
	printf("\nEnter choice: ");
	scanf_s(" %c", &chrUserChoice);

	switch (chrUserChoice) 
	{
	case 'A':
		displayTotalHouseholds(records, count);
		break;
	case 'B':
		displayTotalByCounty(records, count);
		break;
	case 'C':
		displayTotalByRace(records, count);
		break;
	case 'D':
		displayAverageIncome(records, count);
		break;
	case 'E':
		displayAverageIncomeByCounty(records, count);
		break;
	case 'F':
		displayAverageIncomeByRace(records, count);
		break;
	case 'G':
		displayPovertyStats(records, count);
		break;
	case 'H':
		displayPovertyStatsByCounty(records, count);
		break;
	case 'I':
		displayPovertyStatsByRace(records, count);
		break;
	default:
		printf("Invalid choice.\n");
	}
}


// ------------------------------------------------------------------------------------------
// Name: displayMode
// Abstract: Function that pulls all recorded data and then displays all options to then be chosen for processing.
// ------------------------------------------------------------------------------------------
void displayMode()
{
	FILE* file = fopen("sample.csv", "r");
	HouseholdRecord records[MAX_RECORDS];
	int count = 0;

	if (file == NULL) 
	{
		printf("No data available.\n");
		return;
	}

	readRecords(records, &count, file);
	fclose(file);

	if (count == 0) 
	{
		printf("No records to display.\n");
		return;
	}

	displayMenu(records, count);
}


// ------------------------------------------------------------------------------------------
// Name: appendRecord
// Abstract: Function that records new householdRecords into the csv.
// ------------------------------------------------------------------------------------------
void appendRecord(HouseholdRecord* record, FILE* file) 
{
	fprintf(file, "%s,%s,%s,%s,%d,%.2lf\n", record->chrDate, record->chrState, record->chrCounty, record->chrRace, record->intHousehold_size, record->dblYearly_income);
	printf("\nRecord saved.\n");
}


// ------------------------------------------------------------------------------------------
// Name: writeMode
// Abstract: Function that records new data that is being inputed by the user, appending it to the csv afterwords.
// ------------------------------------------------------------------------------------------
void writeMode()
{
	FILE *file = fopen("sample.csv", "a");
	if (file == NULL)
	{
		printf("Error, could not open file for writing.\n");
		exit(1);
	}

	while (1)
	{
		HouseholdRecord record;
		int state_choice;
		int county_choice;
		int race_choice;

		printf("Enter the date of the survey (YYYY-MM-DD): ");
		scanf_s("%s", record.chrDate, (unsigned)_countof(record.chrDate));
		
		printf("Select state:\n1. Ohio\n2. Kentucky\nEnter choice: ");
		scanf_s("%d", &state_choice);
		if (state_choice == 1)
		{
			strcpy(record.chrState, "Ohio");
			printf("Select county:\n1. Hamilton\n2. Butler\nEnter choice: ");
			scanf_s("%d", &county_choice);
			strcpy(record.chrCounty, county_choice == 1 ? "Hamilton" : "Butler");
		}
		else if (state_choice == 2)
		{
			strcpy(record.chrState, "Kentucky");
			printf("Select county:\n1. Boone\n2. Kenton\nEnter choice: ");
			scanf_s("%d", &county_choice);
			strcpy(record.chrCounty, county_choice == 1 ? "Boone" : "Kenton");
		}
		else
		{
			printf("Invalid state choice.\n");
			continue;
		}

		printf("Select race:\n1. Caucasian\n2. African American\n3. Hispanic\n4. Asian\n5. Other\n Enter choice: ");
		scanf_s("%d", &race_choice);
		switch (race_choice)
		{
			case 1: strcpy(record.chrRace, "Caucasian"); break;
			case 2: strcpy(record.chrRace, "African American"); break;
			case 3: strcpy(record.chrRace, "Hispanic"); break;
			case 4: strcpy(record.chrRace, "Asian"); break;
			case 5: strcpy(record.chrRace, "Other"); break;
			default: 
				printf("Invalid race choice.\n");
				continue;
		}

		printf("Enter the number of people in the household: ");
		scanf_s("%d", &record.intHousehold_size);
		if (record.intHousehold_size <= 0)
		{
			printf("Household size must be greater than 0.\n");
			continue;
		}

		printf("Enter yearly household income: ");
		scanf_s("%lf", &record.dblYearly_income);
		if (record.dblYearly_income <= 0)
		{
			printf("Income must be greater than 0.\n");
			continue;
		}

		appendRecord(&record, file);

		char chrChoice;
		printf("Do you want to add another record? (y/n): ");
		scanf_s(" %c", &chrChoice);
		if (chrChoice != 'y' && chrChoice != 'Y')
		{
			break;
		}
	}

	fclose(file);
	return;
}


// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: Function that runs the software of the project by asking the user to choose 1 or 2, 
// begining the cycle for colecting, recording, and utilizing data of hosehold records.
// ------------------------------------------------------------------------------------------
int main()
{
	int intLoginChoice;
	
	printf("Welcome!\n");
	printf("Please select an option below: ");
	printf("Write Mode(1) | Display Mode(2) | Clear Cash(3): ");
	scanf_s("%d", &intLoginChoice);

	switch (intLoginChoice)
	{
		case 1:
			writeMode();
			break;
		case 2:
			displayMode();
			break;
		case 3:
			clearRecords();
			break;
		default:
			printf("Invalid choice, Please come by later.\n");
			exit(1);
	}

	return 0;
}



//Im sorry I wasnt arround for the last 3-4 weeks of the semster, I took family trips around europe for the holidays. 
// Still doesnt excuse me from being absent, but I thought it would be the right idea to let you know. :D 
//Thank you for being my profesor for this semester, I hope to see you in other classes in the future, and happy holidays!