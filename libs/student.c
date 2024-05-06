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
            case
        }
    }
}