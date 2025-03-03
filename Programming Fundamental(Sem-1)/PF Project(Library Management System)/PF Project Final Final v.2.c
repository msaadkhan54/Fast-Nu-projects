#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct Book {
    int serial;
    char title[50];
    long long isbn;
    char genre[20];
    char author[50];
    int availability;
};

struct User {
    char username[50];
    char password[50];
};

struct FineRecord {
    char username[50];
    char book_title[50];
    time_t issue_date;
    time_t due_date;
};

struct User user;

void addBook();
void removeBook();
void displayDirectory();
int get_next_serial_number();
void admin_login();
void login();
void logout();
void signup();
void admin_main();
void user_main();
void change_password();
void search_book();
void issue_book();
void return_book();
void view_users();
void clearScreen();
void check_fine(struct User *user);
void setTextColor(int color);

int main() {
    char choice[6];

    setTextColor(6);
    printf("\t\t\t     _        _   ____    _____    _____   _____  __     __\n");
    printf("\t\t\t    | |      | | |  _ \\  |  _  \\  |  _  | |  _  \\ \\ \\   / / \n");
    printf("\t\t\t    | |      | | | |_| | | |_| /  | |_| | | |_| /  \\ \\_/ /  \n");
    printf("\t\t\t    | |      | | |  _ /  |  _ |   |  _  | |  _ |    \\   / \n");
    printf("\t\t\t    | |____  | | | |_| \\ | | \\ \\  | | | | | | \\ \\    | |  \n");
    printf("\t\t\t    |______| |_| |_____/ |_|  \\_\\ |_| |_| |_|  \\_\\   |_|  \n\n\n");
    
    setTextColor(7);
    
    printf("\t\t\t\t\tLogin or Signup: ");
    scanf("%s", choice);

    if (strcmp(choice, "Signup") == 0) {
        signup();
    } else if (strcmp(choice, "Login") == 0) {
        printf("\n\t\t\t\t------------------------------------------\n\n");
        login();
    }

    return 0;
}

void signup() {
    char confirm[50];
    struct User s;
    FILE *file = fopen("Users.dat", "ab");

    if (file == NULL) {
        printf("\t\t\t\t\tError accessing user info file!\n");
        return;
    }

    printf("\t\t\t\t\tEnter Username: ");
    scanf(" %[^\n]", s.username);
    printf("\t\t\t\t\tEnter Password: ");
    scanf(" %[^\n]", s.password);
    
    
    do {
        printf("\t\t\t\t\tConfirm Password: ");
        scanf(" %[^\n]", confirm);

        if (strcmp(s.password, confirm) == 0) {
            fwrite(&s, sizeof(struct User), 1, file);
        } else {
            printf("\t\t\t\t\tPassword is not the same! Try Again!\n\n");
        }
    } while (strcmp(s.password, confirm) != 0);

    fclose(file);
    printf("\t\t\t\t\tAccount creation successful!\n");
}

void login()
{
    struct User s;
    int user_found = 0;
    char temp_user[50], temp_pass[50];
    FILE *file = fopen("Users.dat", "rb");

    if (file == NULL) {
        printf("\t\t\t\t\tError accessing user info file!\n");
        return;
    }

    printf("\t\t\t\t\tEnter Username: ");
    scanf(" %[^\n]", temp_user);

    if (strcmp(temp_user, "admin") == 0) {
			admin_login();
        user_found = 1;
    } else {
        while (fread(&s, sizeof(struct User), 1, file)) {
            if (strcmp(s.username, temp_user) == 0) {
                user_found = 1;
                while (1) {
                    printf("\t\t\t\t\tEnter Password: ");
                    scanf(" %[^\n]", temp_pass);

                    if (strcmp(s.password, temp_pass) == 0) {
                        printf("\t\t\t\t\tAccess granted!\n");
                        user = s;
                        while(1)
                        {
                        	clearScreen();
                        	user_main(&user);
						}
                        fclose(file);
                        return;
                    } else {
                        printf("\t\t\t\t\tIncorrect password! Try Again!\n");
                    }
                }
            }
        }
    }

    fclose(file);

    if (!user_found) {
        printf("\t\t\t\t\tUser was not found!\n");
    }
}


void admin_login() {
    char temp_pass[50];
    int tries = 0;

    while (tries < 3) {
        printf("\t\t\t\t\tEnter Admin Password: ");
        scanf(" %[^\n]", temp_pass);

        if (strcmp(temp_pass, "admin123") == 0) {
            printf("\t\t\t\t\tAccess granted!\n");
            clearScreen();
            admin_main();
            return;
        } else {
            printf("\t\t\t\t\tIncorrect password! Try Again!\n");
            tries++;
        }
    }
    printf("\t\t\t\t\tToo many failed attempts. Exiting...\n");
}

void logout() {
    memset(&user, 0, sizeof(struct User));
    
    printf("\n\n\t\t\t\t\tYou have successfully logged out.\n");
    
    clearScreen();
    login();
}

void admin_main() {
	int ch;

    while(1)
    {
    	printf("\t\t\t\t\t1. Add a new book\n");
    printf("\t\t\t\t\t2. Remove an existing book\n");
    printf("\t\t\t\t\t3. Display Directory\n");
    printf("\t\t\t\t\t4. View User Directory\n");
    printf("\t\t\t\t\t5. Logout\n");
    printf("\t\t\t\t\t6. Exit\n\n");

    printf("\t\t\t\t\t---------------------------\n");
    printf("\t\t\t\t\tEnter number 1-6: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
        	clearScreen();
            addBook();
            break;
        case 2:
        	clearScreen();
            removeBook();
            break;
        case 3:
        	clearScreen();
            displayDirectory();
            break;
        case 4:
        	clearScreen();
        	view_users();
        	break;
        case 5:
        	logout();
        	break;
        case 6:
            printf("\n\t\t\t\t\tExiting...\n");
            exit(0);
        default:
            printf("\n\t\t\t\t\tInvalid Input! Choose from 1-4\n");
    }
	}
}

void user_main() {
    int task;
	
    printf("\t\t\t\t\t1. Change my Password\n");
    printf("\t\t\t\t\t2. Issue a book\n");
    printf("\t\t\t\t\t3. Return a book\n");
    printf("\t\t\t\t\t4. See my fines\n");
    printf("\t\t\t\t\t5. Search for a book\n");
    printf("\t\t\t\t\t6. Logout\n");
    printf("\t\t\t\t\t7. Exit\n\n");

    printf("\t\t\t\t\t---------------------------\n");
    printf("\t\t\t\t\tEnter number 1-7: ");
    scanf("%d", &task);
    
    switch(task)
    {
    	case 1:
    		clearScreen();
    		change_password(&user);
    		break;
    	case 2:
    		clearScreen();
    		issue_book(&user);
    		break;
    	case 3:
    		clearScreen();
    		return_book(&user);
    		break;
    	case 4:
    		clearScreen();
    		check_fine(&user);
    		break;
    	case 5:
    		clearScreen();
    		search_book();
    		break;
    	case 6:
    		logout();
    		break;
    	case 7:
    		printf("\t\t\t\t\tExiting...\n");
    		exit(0);
    	default:
    		printf("Invalid Input! Enter a number between 1 and 6!\n");
    		break;
	}
}

void search_book() {
    struct Book b;
    char search_title[50];
    int found = 0;
    FILE *file = fopen("books.dat", "rb");

    if (file == NULL) {
        printf("\t\t\t\t\tError accessing book info file!\n");
        return;
    }

    printf("\t\t\t\t\tEnter the title of the book to search: ");
    scanf(" %[^\n]", search_title);

    while (fread(&b, sizeof(struct Book), 1, file)) {
        if (strcmp(b.title, search_title) == 0) {
            found = 1;
            printf("\t\t\t\t\tBook Found:\n");
            printf("\t\t\t\t\tTitle: %s\n", b.title);
            printf("\t\t\t\t\tAuthor: %s\n", b.author);
            printf("\t\t\t\t\tISBN: %lld\n", b.isbn);
            printf("\t\t\t\t\tGenre: %s\n", b.genre);
            printf("\t\t\t\t\tAvailability: %s\n\n", b.availability ? "Available" : "Not Available");
            break;
        }
    }

    if (!found) {
        printf("\t\t\t\t\tBook not found!\n");
    }

    fclose(file);
}

void issue_book(struct User *user) {
    struct Book b;
    char name[50];
    FILE *file = fopen("books.dat", "rb+");
    FILE *fines_file = fopen("fines.dat", "ab");
    time_t current_time = time(NULL);
    struct tm due_date;
    int found = 0;

    if (file == NULL || fines_file == NULL) {
        printf("\t\t\t\t\tError accessing file(s)!\n");
        if (file) fclose(file);
        if (fines_file) fclose(fines_file);
        return;
    }

    printf("\t\t\t\tEnter the name of the book to issue: ");
    scanf(" %[^\n]s", name);

    while (fread(&b, sizeof(struct Book), 1, file)) {
        if (strcmp(b.title, name) == 0 && b.availability) {
            found = 1;
            b.availability = 0;
            fseek(file, -sizeof(struct Book), SEEK_CUR);
            fwrite(&b, sizeof(struct Book), 1, file);

            due_date = *localtime(&current_time);
            due_date.tm_mday += 7;
            mktime(&due_date);

            fprintf(fines_file, "%s,%s,%ld,%ld\n", user->username, b.title, current_time, mktime(&due_date));

            printf("\t\t\t\tBook issued successfully! Due Date: %s\n", asctime(&due_date));
            break;
        }
    }

    if (!found) {
        printf("\t\t\t\tBook not found or not available!\n");
    }

    fclose(file);
    fclose(fines_file);	
}


void return_book(struct User *user) {
    struct Book b;
    char name[50];
    FILE *file = fopen("books.dat", "rb+");
    FILE *fines_file = fopen("fines.dat", "rb");
    FILE *temp_fines_file = fopen("temp_fines.dat", "wb");
    int found = 0;
    time_t current_time = time(NULL);

    if (file == NULL || fines_file == NULL || temp_fines_file == NULL) {
        printf("\t\t\t\t\tError accessing file(s)!\n");
        if (file) fclose(file);
        if (fines_file) fclose(fines_file);
        if (temp_fines_file) fclose(temp_fines_file);
        return;
    }

    printf("\t\t\t\tEnter the name of the book to return: ");
    scanf(" %[^\n]", name);

    while (fread(&b, sizeof(struct Book), 1, file)) {
        if (strcmp(b.title, name) == 0) {
            found = 1;
            b.availability = 1;
            fseek(file, -sizeof(struct Book), SEEK_CUR);
            fwrite(&b, sizeof(struct Book), 1, file);
            printf("\t\t\t\tBook returned successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\t\t\t\t\tBook not found in library records!\n");
    }

    found = 0;
    char username[50], book_title[50];
    time_t issue_date, due_date;
    while (fscanf(fines_file, "%[^,],%[^,],%ld,%ld\n", username, book_title, &issue_date, &due_date) != EOF) {
        if (strcmp(username, user->username) == 0 && strcmp(book_title, name) == 0) {
            found = 1;
            if (current_time > due_date) {
                int days_overdue = (current_time - due_date) / (24 * 60 * 60);
                double fine = days_overdue * 10.0;
                printf("\t\t\t\tYou have a fine of %.2f for late return!\n", fine);
            }
        } else {
            fprintf(temp_fines_file, "%s,%s,%ld,%ld\n", username, book_title, issue_date, due_date);
        }
    }

    if (!found) {
        printf("\t\t\t\tBook not found in issue records!\n");
    }

    fclose(file);
    fclose(fines_file);
    fclose(temp_fines_file);

    remove("fines.dat");
    rename("temp_fines.dat", "fines.dat");
}


void view_users() {
    struct User s;
    int i;
    FILE *file = fopen("Users.dat", "rb");
    if (file == NULL) {
        printf("Error opening file or no records found!\n");
        return;
    }

    printf("\n\n--- User Records ---\n\n");
    printf("%-20s %-30s\n", "Username", "Password");
    printf("----------------------------------------------------------------------------------\n");

    while (fread(&s, sizeof(struct User), 1, file)) {
        printf("%-20s %-30s\n", s.username, s.password);
    }
    fclose(file);
    printf("\n");
}

void addBook()
{
    struct Book s;
    FILE *file = fopen("books.dat", "ab");
    if (file == NULL) {
        printf("\t\t\t\t\tError opening file!\n");
        return;
    }

    printf("\t\t\t\t\tEnter Book Title: ");
    scanf(" %[^\n]", s.title);
    printf("\t\t\t\t\tEnter Author Name: ");
    scanf(" %[^\n]", s.author);
    printf("\t\t\t\t\tEnter ISBN: ");
    scanf("%lld", &s.isbn);
    printf("\t\t\t\t\tEnter Genre: ");
    scanf(" %[^\n]", s.genre);

    s.serial = get_next_serial_number();
    s.availability = 1;

    fwrite(&s, sizeof(struct Book), 1, file);
    fclose(file);

    printf("\t\t\t\t\tBook record added successfully!\n");
    clearScreen();
}

void removeBook() {
    struct Book s;
    int found = 0, i;
    char name[50];
    FILE *file = fopen("books.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (file == NULL || temp == NULL) {
        printf("\t\t\t\t\tError opening file!\n");
        if (file) fclose(file);
        if (temp) fclose(temp);
        return;
    }

    printf("\t\t\tEnter the name of the book to delete: ");
    scanf(" %[^\n]", name);

    struct Book books[100];
    int count = 0;

    while (fread(&s, sizeof(struct Book), 1, file)) {
        if (strcmp(s.title, name) == 0) {
            found = 1;
            printf("\t\t\tBook record with name '%s' deleted successfully!\n", name);
        } else {
            books[count++] = s;
        }
    }

    fclose(file);

    for (i = 0; i < count; i++) {
        books[i].serial = i + 1;
    }

    for (i = 0; i < count; i++) {
        fwrite(&books[i], sizeof(struct Book), 1, temp);
    }

    fclose(temp);

    if (!found) {
        printf("\t\t\t\t\tBook with name '%s' not found!\n", name);
        remove("temp.dat");
    } else {
        if (remove("books.dat") == 0) {
            if (rename("temp.dat", "books.dat") != 0) {
                printf("\t\t\t\t\tError renaming temporary file!\n");
            }
        } else {
            printf("\t\t\t\t\tError deleting original file!\n");
        }
    }
    clearScreen();
}


void displayDirectory()
{
    struct Book s;
    FILE *file = fopen("books.dat", "rb");
    if (file == NULL) {
        printf("Error opening file or no records found!\n");
        return;
    }

    printf("\n\n--- Book Records ---\n\n");
    printf("%-6s %-38s %-20s %-20s %s\n", "S.No.", "Title", "Author", "ISBN", "Genre");
    printf("----------------------------------------------------------------------------------------------------\n");

    while (fread(&s, sizeof(struct Book), 1, file)) {
        printf("%-6d %-38s %-20s %-20lld %-20s %d\n", s.serial, s.title, s.author, s.isbn, s.genre, s.availability);
    }
    fclose(file);
    printf("\n");
}

int get_next_serial_number()
{
    FILE *file = fopen("books.dat", "rb");
    int max_serial = 0;
    struct Book s;

    if (file == NULL) {
        return 1;
    }

    while (fread(&s, sizeof(struct Book), 1, file)) {
        if (s.serial > max_serial) {
            max_serial = s.serial;
        }
    }

    fclose(file);
    return max_serial + 1;
}
void check_fine(struct User *user) {
    FILE *fines_file = fopen("fines.dat", "rb");
	struct FineRecord fine_record;
	int found = 0;
	time_t current_time = time(NULL);
	
	if (fines_file == NULL) {
	    printf("\t\t\t\tError accessing fine records!\n");
	    return;
	}
	
	printf("\t\t\t\tChecking fines for user: %s\n", user->username);
	
	while (fread(&fine_record, sizeof(struct FineRecord), 1, fines_file)) {
	    printf("DEBUG: Read record: %s, %s, %ld, %ld\n", fine_record.username, fine_record.book_title, fine_record.issue_date, fine_record.due_date);
	
	    if (strcmp(fine_record.username, user->username) == 0) {
	        found = 1;
	        if (current_time > fine_record.due_date) {
	            int days_overdue = (current_time - fine_record.due_date) / (24 * 60 * 60);
	            double fine = days_overdue * 10.0;
	            printf("\t\t\t\tBook: %s | Fine: %.2f for %d day(s) overdue.\n", fine_record.book_title, fine, days_overdue);
	        }
	    }
}

if (!found) {
    printf("\t\t\t\tNo fines found for user %s.\n", user->username);
}

fclose(fines_file);
}

void change_password(struct User *user) {
    struct User s;
    int found = 0;
    char password[50], confirm[50];
    FILE *file = fopen("Users.dat", "rb"); 
    FILE *temp = fopen("temp.dat", "wb"); 
    
    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    while (fread(&s, sizeof(struct User), 1, file)) {
        if (strcmp(s.username, user->username) == 0) {
            found = 1;
            printf("\t\t\t\t\tEnter new password: ");
            scanf(" %[^\n]", password);
            printf("\t\t\t\t\tConfirm password: ");
            scanf(" %[^\n]", confirm);

            while (strcmp(password, confirm) != 0) {
                printf("\t\t\t\t\tPasswords do not match. Enter again:\n");
                printf("\t\t\t\t\tEnter new password: ");
                scanf(" %[^\n]", password);
                printf("\t\t\t\t\tConfirm password: ");
                scanf(" %[^\n]", confirm);
            }
            
            strcpy(s.password, password);
            printf("\t\t\t\t\tPassword updated successfully!\n");
        }
        
        fwrite(&s, sizeof(struct User), 1, temp);
    }
    
    fclose(file);
    fclose(temp);
    
    if (!found) {
        printf("\t\t\t\t\tUser with username '%s' not found!\n", user->username);
        remove("temp.dat");
    } else {
        remove("Users.dat"); 
        rename("temp.dat", "Users.dat");
    }
}

void clearScreen() {
    Sleep(1500);
	system("cls");
	
	setTextColor(6);
    printf("\t\t\t     _        _   ____    _____    _____   _____  __     __\n");
    printf("\t\t\t    | |      | | |  _ \\  |  _  \\  |  _  | |  _  \\ \\ \\   / / \n");
    printf("\t\t\t    | |      | | | |_| | | |_| /  | |_| | | |_| /  \\ \\_/ /  \n");
    printf("\t\t\t    | |      | | |  _ /  |  _ |   |  _  | |  _ |    \\   / \n");
    printf("\t\t\t    | |____  | | | |_| \\ | | \\ \\  | | | | | | \\ \\    | |  \n");
    printf("\t\t\t    |______| |_| |_____/ |_|  \\_\\ |_| |_| |_|  \\_\\   |_|  \n\n\n");
    
    setTextColor(7);
}

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
}
