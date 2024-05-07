// 12S23034 - PARIAMA MARKUS
// 12S23050 - YOLANDA SEPTANIA

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv)
{
    
    int student_size = 0;
    struct student_t student[100];

    int dorm_size = 0;
    struct dorm_t dorms[100];

    char input[100];

    char print_command[10][100];
    int student_print_all[50];
    int student_print_all_detail[50];
    int dorm_print_all_detail[50];
    int command_counter = 0;

    FILE *storage = fopen("dorm-repository.txt", "r+");
    FILE *storage = fopen("student-repository.txt", "r+");

    while(1){
        int inputPointer = 0;

        while(1){
            char karakter = getchar();

            if (karakter != '\r' && karakter != '\n')
            {
                input[inputPointer] = karakter;
                input[++inputPointer] = '\0';
            }
            else
            {
                if (karakter == '\r')
                {
                    continue;
                }

                if (karakter == '\n')
                {
                    break;
                }
            }

        }
        if(strcmp(input,"---") == 0){
            break;
        }else{
            int counter = 0;
            char inputBuffer[5][30];
            char *token = strtok(input,"#");

            while(token != NULL){
                strcpy(inputBuffer[counter],token);
                counter++;
                token = strtok(NULL,"#");
            }

            fflush(stdin);

            if(strcmp(inputBuffer[0], "student-print-all")==0){
                strcpy(print_command[command_counter],"student-print-all");
                student_print_all[command_counter] = student_size;
                command_counter++;
            }else if(strcmp(inputBuffer[0],"student-print-all-detail")==0){
                strcpy(print_command[command_counter],"student-print-all-detail");
                student_print_all_detail[command_counter] = student_size;
                command_counter++;
            }else if(strcmp(inputBuffer[0],"student-add") == 0){

                if(strcmp(inputBuffer[4],"male") == 0){
                        students[student_size] = create_student(
                            inputBuffer[1],
                             inputBuffer[2],
                            inputBuffer[3],
                            GENDER_MALE
                        );
                        student_size++;  
                }

                if(strcmp(inputBuffer[4], "female") == 0){
                    students[student_size] = create_student(
                        inputBuffer[1],
                        inputBuffer[2],
                        inputBuffer[3],
                        GENDER_FEMALE
                    );
                    student_size++;
                }
            }else if(strcmp(inputBuffer[0],"assign-student") == 0){
                for(int std = 0 ; std < student_size ; ++std){
                    if(strcmp(students[std].id,inputBuffer[1]) == 0){
                        for(int drm = 0 ; drm < dorm_size ; ++drm){
                            if(strcmp(dorms[drm].name,inputBuffer[2]) == 0){
                                assign_student(&student[std],&dorms[drm]);
                                break;
                            }
                        }
                        break;
                    }
                }
            }

            if(strcmp(inputBuffer[0],"move-student") == 0){
                for(int std = 0 ; std < student_size ; ++std){
                    if(strcmp(students[std].id,inputBuffer[1]) == 0){
                        for(int drm = 0 ; drm < dorm_size ; ++drm){
                            if(strcmp(dorms[drm].name,inputBuffer[2]) == 0){
                                if(students[std].dorm == NULL){
                                    move_student(&student[std],&dorms[drm]);
                                }
                                move_student(&students[std],&dorms[drm]);
                                 break;
                            }
                        }
                    break;
                }
            }
        }

        if(strcmp(inputBuffer[0],"dorm-add") == 0){
            if(strcmp(inputBuffer[3],"male") == 0){
                dorms[dorm_size] = create_dorm(
                    inputBUffer[1],
                    atoi(inputBuffer[2]),
                    GENDER_MALE
                );
                dorm_size++;
            }

        }    
        }
    }
    return 0;

}