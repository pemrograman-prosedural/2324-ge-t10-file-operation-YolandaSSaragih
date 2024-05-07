#include "student.h"
#include <assert.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */



void assign_student(struct student_t *student,struct dorm_t *dorm){
    if(student->gender == dorm->residents_num){
            if(dorm->capacity > dorm->residents_num){
             dorm->residents_num++;
             student->dorm = dorm;
         }else{
            student->dorm = NULL;
         }
    }
}   

void move_student(struct student_t *student, struct dorm_t *target){
    if(student->dorm == NULL){
        assign_student(student,target);
        return;
    }
    student->dorm->residents_num--;
    student->dorm = target;
    student->dorm->residents_num++;
}

void print_student(struct student_t *student,int size){
    for(int indeks = 0 ; indeks < size ; indeks){
        switch (student[indeks].gender)
        {
            case GENDER_FEMALE:
            print("%s|%s|%s|female\n",student[indeks].id,student[indeks].name,student[indeks].year);
            student[indeks].printed_before = 1;
            break;

            case GENDER_MALE:
            print("%s|%s|%s|male\n",student[indeks].id,student[indeks].name,student[indeks].year);
            student[indeks].printed_before = 1;
            break;
        }
    }
}

void print_student_detail(struct student_t *student,int size){
    for(int indeks = 0 ; indeks < size ; indeks++){
        switch (student[indeks].gender)
        {
            case GENDER_FEMALE:
            if(student[indeks].dorm != NULL && student[indeks].printed_before != 0){
                printf("%s|%s|%s|female|%s\n",student[indeks].id,student[indeks].name,student[indeks].year,student[indeks].dorm->name);
                break;
            }
         printf("%s|%s|%s|female|unassigned|\n",student[indeks].id,student[indeks].name,student[indeks].year);
         student[indeks].printed_before = 1;
         break;

         case GENDER_MALE:
         if(student[indeks].dorm != NULL && student[indeks].printed_before != 0){
            printf("%s|%s|%s|male|%s\n",student[indeks].id,student[indeks].name,student[indeks].year,student[indeks].dorm->name);
                break;
            }
         printf("%s|%s|%s|male|unassigned|\n",student[indeks].id,student[indeks].name,student[indeks].year);
         student[indeks].printed_before = 1;
         break;
        }
    }
}

struct student_t create_student(char *_id, char *_name, char *_year,enum gender_t _gender){
    struct student_t newstudent;

    memset(newstudent.id,'\0',strlen(newstudent.id));
    memset(newstudent.name,'\0',strlen(newstudent.name));
    memset(newstudent.year,'\0',strlen(newstudent.year));

    strcpy(newstudent.id, _id);
    strcpy(newstudent.name, _name);
    strcpy(newstudent.year, _year);

    newstudent.gender = _gender;
    newstudent.dorm = NULL;
    newstudent.printed_before = 0;

    newstudent.print_student = &print_student;
    newstudent.print_student_detail = &print_student_detail;

    return newstudent;
}