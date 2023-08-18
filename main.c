#include <stdio.h>
#include <stdlib.h>

#define MAX_SNIPPETS 100
#define MAX_TITLE_LENGTH 50
#define MAX_CODE_LENGTH 1000

struct CodeSnippet {
    char title[MAX_TITLE_LENGTH];
    char code[MAX_CODE_LENGTH];
};

int main() {
    struct CodeSnippet snippets[MAX_SNIPPETS];
    int snippet_count = 0;
    
    while (1) {
        printf("Code Snippet Organizer\n");
        printf("1. Add Snippet\n2. View Snippets\n3. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (snippet_count < MAX_SNIPPETS) {
                    printf("Enter snippet title: ");
                    scanf("%s", snippets[snippet_count].title);
                    printf("Enter code:\n");
                    scanf(" %[^\n]", snippets[snippet_count].code);
                    snippet_count++;
                } else {
                    printf("Maximum number of snippets reached.\n");
                }
                break;
            case 2:
                printf("Code Snippets:\n");
                for (int i = 0; i < snippet_count; i++) {
                    printf("%d. %s\n", i + 1, snippets[i].title);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
}
