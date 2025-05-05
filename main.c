#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char description[100];
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char desc[]) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->description, desc);
    newTask->next = head;
    head = newTask;
}

void deleteTask(int index) {
    if (head == NULL) return;

    Task* temp = head;

    if (index == 0) {
        head = head->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) return;

    Task* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void displayTasks() {
    Task* temp = head;
    int index = 0;
    while (temp != NULL) {
        printf("%d. %s\n", index++, temp->description);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char desc[100];

    while (1) {
        printf("\n1. Add Task\n2. Delete Task\n3. View Tasks\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // to clear input buffer

        switch (choice) {
            case 1:
                printf("Enter task: ");
                fgets(desc, sizeof(desc), stdin);
                desc[strcspn(desc, "\n")] = '\0';
                addTask(desc);
                break;
            case 2:
                printf("Enter task index to delete: ");
                int idx;
                scanf("%d", &idx);
                deleteTask(idx);
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}

