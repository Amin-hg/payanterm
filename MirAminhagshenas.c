//MirAminHagshenas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define ID_LENGTH 20

typedef struct {
 char firstName[NAME_LENGTH];
 char lastName[NAME_LENGTH];
 char nationalCode[ID_LENGTH];
} Record;

void saveToFile(Record records[], int count) {
 FILE *file = fopen("data.txt", "w");
 if (file == NULL) {
 printf("Khata dar egraye file \n");
 return;
 }
 
 for (int i = 0; i < count; i++) {
 fprintf(file, "%s,%s,%s\n", records[i].firstName, records[i].lastName, records[i].nationalCode);
 }
 
 fclose(file);
 printf("Etelaat ba movafagiat anjam shod.\n");
}

void searchByName(Record records[], int count, const char* name) {
 int found = 0;
 for (int i = 0; i < count; i++) {
 if (strcmp(records[i].firstName, name) == 0 || strcmp(records[i].lastName, name) == 0) {
 printf("Yaft shod  %s %s, Kodmeli: %s\n", records[i].firstName, records[i].lastName, records[i].nationalCode);
 found = 1;
 }
 }
 if (!found) {
 printf("Hich recorde ba nam '%s' yaft nashod \n", name);
 }
}

void searchByNationalCode(Record records[], int count, const char* nationalCode) {
 int found = 0;
 for (int i = 0; i < count; i++) {
 if (strcmp(records[i].nationalCode, nationalCode) == 0) {
 printf("Yaft shod  %s %s, Kodmeli: %s\n", records[i].firstName, records[i].lastName, records[i].nationalCode);
 found = 1;
 }
}
 if (!found) {
 printf("Hich recorde ba nam '%s' yaft nashod \n", nationalCode);
 }
}

int main() {
 Record records[MAX_RECORDS];
 int count = 0;
int choice;

 do {
 printf("\n1. Afzodan record\n");
printf("2. Gost o go bar asas nam \n");
 printf("3. Gost o go bar asas kod meli\n");
 printf("4. Exit\n");
 printf(" Entekhab konid ");
 scanf("%d", &choice);
 getchar(); 

 switch (choice) {
 case 1:
if (count < MAX_RECORDS) {
 printf("Num : ");
 fgets(records[count].firstName, NAME_LENGTH, stdin);
 strtok(records[count].firstName, "\n");  

 printf("Num Khanevadege : ");
 fgets(records[count].lastName, NAME_LENGTH, stdin);
 strtok(records[count].lastName, "\n"); 

 printf("Kodmeli : ");
 fgets(records[count].nationalCode, ID_LENGTH, stdin);
 strtok(records[count].nationalCode, "\n"); 

 count++;
saveToFile(records, count);
 } else {
 printf("Hade aksar record ha resed .\n");
 }
 break;
 case 2:
 {
 char name[NAME_LENGTH];
 printf("Num ya NumKhanevadege baraye gost o go  ");
 fgets(name, NAME_LENGTH, stdin);
 strtok(name, "\n"); 
 searchByName(records, count, name);
 }
 break;
 case 3:
 {
 char nationalCode[ID_LENGTH];
 printf("Kod meli baraye gost o go : ");
 fgets(nationalCode, ID_LENGTH, stdin);
strtok(nationalCode, "\n"); 
 searchByNationalCode(records, count, nationalCode);
 }
 break;
 case 4:
 printf("Exit az barname.\n");
 break;
 default:
 printf("Gozene namotabar ast Dobare talash konid.\n");
 }
 } while (choice != 4);

 return 0;
}