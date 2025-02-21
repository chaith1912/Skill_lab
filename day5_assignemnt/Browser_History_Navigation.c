#include <stdio.h>
#include <string.h>

#define MAX 100

char backStack[MAX][100];
char forwardStack[MAX][100];
char currentPage[100];
int backTop = -1, forwardTop = -1;

void visit(const char *url) {
    if (strlen(currentPage) > 0) {
        strcpy(backStack[++backTop], currentPage);
    }
    strcpy(currentPage, url);
    forwardTop = -1;
    printf("Visited: %s\n", currentPage);
}

void goBack() {
    if (backTop == -1) {
        printf("No previous pages to go back to.\n");
        return;
    }
    strcpy(forwardStack[++forwardTop], currentPage);
    strcpy(currentPage, backStack[backTop--]);
    printf("Action: Go Back\nCurrent Page: %s\n", currentPage);
}

void goForward() {
    if (forwardTop == -1) {
        printf("No forward pages to go forward to.\n");
        return;
    }
    strcpy(backStack[++backTop], currentPage);
    strcpy(currentPage, forwardStack[forwardTop--]);
    printf("Action: Go Forward\nCurrent Page: %s\n", currentPage);
}

int main() {
    visit("google.com");
    visit("github.com");
    visit("stackoverflow.com");

    goBack();
    goBack();
    goForward();

    return 0;
}