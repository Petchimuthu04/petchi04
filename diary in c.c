#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    char date[20];
    char content[200];
};

struct Diary {
    struct DiaryEntry entries[MAX_ENTRIES];
    int count;
};

void addEntry(struct Diary *diary, const char *date, const char *content) {
    if (diary->count < MAX_ENTRIES) {
        strcpy(diary->entries[diary->count].date, date);
        strcpy(diary->entries[diary->count].content, content);
        diary->count++;
    } else {
        printf("Diary is full.\n");
    }
}

void displayDiary(struct Diary *diary) {
    printf("Diary Entries:\n");
    for (int i = 0; i < diary->count; i++) {
        printf("Date: %s\nContent: %s\n\n", diary->entries[i].date, diary->entries[i].content);
    }
}

int main() {
    struct Diary myDiary = { .count = 0 };
    char date[20];
    char content[200];

    while (1) {
        printf("Enter date (or 'exit' to quit): ");
        scanf("%s", date);

        if (strcmp(date, "exit") == 0) {
            break;
        }

        getchar();

        printf("Enter content: ");
        fgets(content, sizeof(content), stdin);

        addEntry(&myDiary, date, content);
    }

    displayDiary(&myDiary);

    return 0;
}
