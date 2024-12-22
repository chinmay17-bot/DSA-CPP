#include <stdio.h>
#include <string.h>

struct student
{
    char name[100];
    int age;
    int class;
};

void display(struct student stu){
    printf("%s\t", stu.name);
}
 
int main(){
    // struct student stu= {"name", 12, 1};
    // display(stu);
    int x= (1,2,3);
    printf("%d", x);
    // if(x=1) printf("done");
}