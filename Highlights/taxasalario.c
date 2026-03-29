#include<stdio.h>

int main(){
    float salary,taxa,taxa2;
    scanf("%f",&salary);

    if(salary >= 0){
        if (salary <= 2000){
            printf("Isento\n");
        }
        else if (salary <= 3000){
            printf("R$ %.2f\n", (salary - 2000) * 8/100);
        }
        else if (salary <=4500){
            salary -= 3000;
            taxa = 1000 * 8/100;
            salary = salary * 18/100;
            
            printf("R$ %.2f\n", salary + taxa);
        }
        else{
            salary -= 3000;
            taxa = 1000 * 8/100;
            salary -= 1500;
            taxa2 = 1500 * 18/100;
            salary = salary * 28/100;

            printf("R$ %.2f\n", salary + taxa + taxa2);
        }
    }
return 0;
}