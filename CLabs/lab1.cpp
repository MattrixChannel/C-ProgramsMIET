#include <iostream>
#include <iomanip>

#define MAXNAMELEN 30
#define DBNAME "save.txt"

using namespace std;

struct Account {
	int id;
	char* name;
	char* fam;
	double sum;
};

void dbInfo(Account* db, int dbSize, int longestName, int longestFam) {
	Account* u = db;
	longestFam++;
	longestName++;
	cout << "ID" << setw(longestFam) << "Fam" << setw(longestName) << "Name" << ' ' << "Debt" << endl;
	cout << "---------------------------------------------\n\n";
	for (int i = 0; i < dbSize; i++) {
		cout << u->id << setw(longestFam) << u->fam << setw(longestName) << u->name << ' ' << u->sum << '\n';
		u++;
	}
}

void newAccount(Account* db, int dbSize, int* longestName, int* longestFam) {
	Account newAcc;

	cout << endl;

	newAcc.id = dbSize - 1;

	char buf[MAXNAMELEN];

	cout << "Surname: ";
	cin >> buf;

	newAcc.fam = new char[strlen(buf) + 1];
	strcpy_s(newAcc.fam, strlen(buf) + 1, buf);

	if (strlen(buf) > *longestFam) *longestFam = strlen(buf);

	cout << "Name: ";
	cin >> buf;

	newAcc.name = new char[strlen(buf) + 1];
	strcpy_s(newAcc.name, strlen(buf) + 1, buf);

	if (strlen(buf) > *longestName) *longestName = strlen(buf);

	cout << "Deposit: ";
	cin >> newAcc.sum;

	db[dbSize - 1] = newAcc;
	cout << "\nAccount has been succesfully added to data base" << endl;
}

void getAccountInfo(Account acc) {
	cout << "\nId:\t" << acc.id << endl;

	cout << "Surname:\t" << acc.fam << endl;

	cout << "Name:\t" << acc.name << endl;

	cout << "Deposit:\t" << acc.sum << endl << endl;
}

void motd() {
	cout << "\n/////////////// What do you want to do?\n";
	cout << "Save DB to hard drive:                1\n";
	cout << "Show the DB:                          2\n";
	cout << "Add new account:                      3\n";
	cout << "Get account info:                     4\n";
	cout << "Find accounts with deposit more than: 5\n";
	cout << "Exit:                                 0\n";
	cout << "\nType a number: ";
}

void main() {
	Account* db = (Account*)calloc(1, sizeof(Account));
	FILE* dbFile;
	int dbLen = 0;
	fopen_s(&dbFile, DBNAME, "a+");

	int except = 0;

	int longestName = 5;
	int longestFam = 5;

	for (int i = 0; !feof(dbFile); i++) {
		dbLen++;
		db = (Account*)realloc(db, dbLen * sizeof(Account));

		char buf[MAXNAMELEN];

		//newAcc.fam = new char[strlen(buf) + 1];
		//strcpy_s(newAcc.fam, strlen(buf) + 1, buf);

		//db[i].fam = new char[MAXNAMELEN];
		//db[i].name = new char[MAXNAMELEN];

		fscanf_s(dbFile, "%ld", &(db[i].id));
		if (feof(dbFile)) {
			except = 1;
			break;
 		}
		fscanf_s(dbFile, "%s", buf, MAXNAMELEN);

		if (strlen(buf) > longestFam) longestFam = strlen(buf);

		db[i].fam = new char[strlen(buf) + 1];
		strcpy_s(db[i].fam, strlen(buf) + 1, buf);

		fscanf_s(dbFile, "%s", buf, MAXNAMELEN);

		if (strlen(buf) > longestName) longestName = strlen(buf);

		db[i].name = new char[strlen(buf) + 1];
		strcpy_s(db[i].name, strlen(buf) + 1, buf);

		fscanf_s(dbFile, "%lf", &(db[i].sum));

	}
	fclose(dbFile);

	if (except == 1) {
		free(db);
		db = (Account*)calloc(1, sizeof(Account));
		dbLen = 1;
		newAccount(db, dbLen, &longestFam, &longestName);
	}

	dbInfo(db, dbLen, longestName, longestFam);
	//cout << "DbLen: " << db[0].fam << endl;
	while (true) {
		motd();
		char var;
		cin >> var;

		bool found4 = false;
		double sum5 = 0;

		int id4 = -1;

		switch (var) {
		case '1':
			FILE * dbFile;

			fopen_s(&dbFile, DBNAME, "w");

			for (int i = 0; i < dbLen; i++)
			{
				fprintf(dbFile, "%ld ", (db[i].id));
				fprintf(dbFile, "%s ", db[i].fam, MAXNAMELEN);// Было 15 вместо maxnamelen
				fprintf(dbFile, "%s ", db[i].name, MAXNAMELEN);
				fprintf(dbFile, "%lf", (db[i].sum));
				if (i != dbLen - 1) fprintf(dbFile, "\n");
			}
			fclose(dbFile);
			break;
		case '2':
			dbInfo(db, dbLen, longestName, longestFam);
			break;
		case '3':
			dbLen++;
			db = (Account*)realloc(db, dbLen * sizeof(Account));
			newAccount(db, dbLen, &longestFam, &longestName);
			break;
		case '4':
			cout << "Enter Surname: ";
			char surname4[MAXNAMELEN];
			cin >> surname4;
			cout << "Enter Name: ";
			char name4[MAXNAMELEN];
			cin >> name4;

			for (int i = 0; i < dbLen; i++) {
				if (strcmp(name4, db[i].name) == 0 && strcmp(surname4, db[i].fam) == 0) {
					found4 = true;
					getAccountInfo(db[i]);
					break;
				}
			}

			if (!found4) cout << "Not found";

			break;
		case '5':
			cout << "Enter a number, accounts with deposit higher than it will be shown:" << endl;
			cin >> sum5;

			for (int i = 0; i < dbLen; i++)
			{
				if (db[i].sum > sum5) getAccountInfo(db[i]);
			}
			break;
		case '0':
			for (int i = 0; i < dbLen; ++i) {
				delete[] db[i].name;
				delete[] db[i].fam;
			}
			free(db);
			return;
		default:
			cout << "Unexpected symbol, please try again\n";
			break;
		}
	}
}
