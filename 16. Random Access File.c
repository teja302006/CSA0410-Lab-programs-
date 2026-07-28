#include <stdio.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee emp;

    fp = fopen("employee.dat", "wb+");

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(emp), 1, fp);

    rewind(fp);

    fread(&emp, sizeof(emp), 1, fp);

    printf("\nEmployee Details\n");
    printf("ID     : %d\n", emp.id);
    printf("Name   : %s\n", emp.name);
    printf("Salary : %.2f\n", emp.salary);

    fclose(fp);

    return 0;
}
