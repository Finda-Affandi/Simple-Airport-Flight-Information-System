// Nama    : Finda Affandi
// NIM     : 672020113

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <process.h>

// Deklarasi Variabel

struct log {
        int logh;
        int logm;
        int logdd;
        int logmm;
        int logyy;
        char logN[100];
        struct log *next;
}*loghd, *logcur, *logtal;

struct data {
        char code[50];
        char airline[50];
        char type[50];
        char dest[50];
        char desttyp[50];
        char date[50];;
        char clock[50];
        struct data *next;
}*head, *current, *tail;

time_t getTime;
char user[50], pass[50], dateString[50];
int i, j, x, y, z, a, b, c, cmpr, hours, minutes, day, month, year, rightuser, rightpass, slct, lim, autoX, plh;
int dispT[100][100];
char cd[50], al[50], tp[50], ds[50], dt[50], de[50], cl[50], srch[100], ed[100], newVal[100], del[50], strLog[100], yynn[100];
char sorting[100][100][100];
char disp[100][100][100];
char searching[100][100][100];
char temp[100][100];

void add();
void addFirst();
void delt();
void display();
void edit();
void editing();
void gotoxy();
void history();
void insert();
void insertLog();
void loading();
void login();
void pop();
void popHead();
void popTail();
void search();
void sort();
void sortLog();
void timeNow();
void mainMenu();


void main() {
       addFirst();
       rightpass = 1;
       rightuser = 1;
       system("color 60");
       login();
       rightuser = strcmp(user, "admin");
       rightpass = strcmp(pass, "admin");
       if (rightuser != 0) {
               gotoxy(51,25);system("pause>nul | echo Username Salah!");
               strcpy(strLog, "Gagal login karena salah username");
               insertLog(strLog);
               system("cls");
               main();
       }
       else if (rightpass != 0) {
               gotoxy(51,25);system("pause>nul | echo Password Salah!");
               strcpy(strLog, "Gagal login karena salah Password");
               insertLog(strLog);
               system("cls");
               main();
       }
       else {
               strcpy(strLog, "Admin berhasil login");
               insertLog(strLog);
               system("cls");
               loading();
               system("cls");
               mainMenu();
       }
}


void timeNow() {
        time(&getTime);
        struct tm *local = localtime(&getTime);
        hours = local->tm_hour;
        minutes = local->tm_min;
        day = local->tm_mday;
        month = local->tm_mon;
        year = local->tm_year;
        strftime(dateString, 64, "%A, %d %B %Y", local);
}


void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void login() {
        gotoxy(4,1);printf("Today is : "); 
        timeNow(); 
        puts(dateString);
        gotoxy(108,1);printf("|%02d:%02d|", hours, minutes);
        gotoxy(46,4);printf("                __        ");
        gotoxy(46,5);printf("|   _  _ . _   |__)_  _  _");
        gotoxy(46,6);printf("|__(_)(_)|| )  |  (_|(_)(-");
        gotoxy(46,7);printf("      _/             _/   ");
        gotoxy(52,9);printf("   .d8888b.\n");
        gotoxy(52,10);printf("   88'  `88\n");
        gotoxy(52,11);printf("   88.  .88\n");
        gotoxy(52,12);printf("   `88888P'\n\n");
        gotoxy(52,13);printf(" a88P    Y88o\n");
        gotoxy(52,14);printf("d8'        `8b\n");
        gotoxy(52,15);printf("88          88");
        gotoxy(41,19);printf("====================================");
        gotoxy(41,18);printf("Username : ");
        scanf("%s", &user);
        gotoxy(41,21);printf("====================================");
        gotoxy(41,20);printf("Password : ");
        
        char ch;
        i = 0;
        while((ch = (char) _getch()) !='\r') {
                pass[i] = ch;
                printf("*");

                i++;
        }

}

void loading() {
        gotoxy(20,2);printf("                                       &&&");                                     
        gotoxy(20,3);printf("                                      &&&&&");                                     
        gotoxy(20,4);printf("                                      &&&&&");                                    
        gotoxy(20,5);printf("                                      &&&&&");                                    
        gotoxy(20,6);printf("                                      &&&&&");                                    
        gotoxy(20,7);printf("                                 &&& .&&&&&. &&&");                               
        gotoxy(20,8);printf("                          .#.   &&&&&&&&&&&&&&&&&   .#.");                          
        gotoxy(20,9);printf("                          &&&&&&&&&&&&&&&&&&&&&&&&&&&&#");                         
        gotoxy(20,10);printf("                       *&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*");                      
        gotoxy(20,11);printf("                    &&&&&&&&&&.       &&&&&       .&&&&&&&&&&");                  
        gotoxy(20,12);printf("                  *.                  &&&&&                  .*");                                     
        gotoxy(20,13);printf("                                      &&&&&");                                     
        gotoxy(20,14);printf("                                      &&&&&");                                     
        gotoxy(20,15);printf("                                      &&&&&");                                     
        gotoxy(20,16);printf("                                     &&&&&&&");                                    
        gotoxy(20,17);printf("                                 &&&&&&&&&&&&&&&");                                
        gotoxy(20,18);printf("                            #########       #########");
        gotoxy(52,22);printf("Please wait ...");
        gotoxy(31,24);
        for(i=1;i<=60;i++){
                for(j=0;j<=30000000;j++);
                printf("%c", 177);
        }
}

void insertLog(char n[]) {
	logcur = (struct log*)malloc(sizeof(struct log));
        time(&getTime);
        struct tm *local = localtime(&getTime);
        logcur->logh = local->tm_hour;
        logcur->logm = local->tm_min;
        logcur->logdd = local->tm_mday;
        logcur->logmm = local->tm_mon;
        logcur->logyy = local->tm_year;
	strcpy(logcur->logN, n);

	if(head == NULL){
		loghd = logtal = logcur;
	}
	else{
		logcur->next = loghd;
		loghd = logcur;
	}
}

void insert(char code[], char airline[], char type[], char dest[], char desttyp[], char date[], char clock[]){
        current = (struct data*)malloc(sizeof(struct data));
        strcpy(current->code, code);
        strcpy(current->airline, airline);
        strcpy(current->type, type);
        strcpy(current->dest, dest);
        strcpy(current->desttyp, desttyp);
        strcpy(current->date, date);
        strcpy(current->clock, clock);

        if (head == NULL) {
                head = tail = current;
        }
        else {
                tail->next = current;
                tail = current;
        }
        tail->next = NULL;
}

void display() {
        gotoxy(30,1);printf("===============================================================");
        gotoxy(50,2);printf("Lihat Jadwal Penerbangan");
        gotoxy(30,3);printf("===============================================================");
        gotoxy(2,5);printf("No");
        gotoxy(6,5);printf("Kode");
        gotoxy(18,5);printf("Maskapai");
        gotoxy(44,5);printf("Tipe Pesawat");
        gotoxy(61,5);printf("Destinasi");
        gotoxy(76,5);printf("Tipe Destinasi");
        gotoxy(94,5);printf("Tanggal TakeOff");
        gotoxy(111,5);printf("Jam");
        gotoxy(1,6);printf("====================================================================================================================");
        current = head;
        i = 0;
        while (current != NULL) {
                strcpy(disp[i][0], current->code);
                strcpy(disp[i][1], current->airline);
                strcpy(disp[i][2], current->type);
                strcpy(disp[i][3], current->dest);
                strcpy(disp[i][4], current->desttyp);
                strcpy(disp[i][5], current->date);
                strcpy(disp[i][6], current->clock);
                current = current->next;
                i++;
        }
        
        autoX = 7;
        for (i = 0; i < lim; i++) {
                gotoxy(2, autoX);printf("%d", i+1);
                gotoxy(6, autoX);printf("%s", disp[i][0]);
                gotoxy(18, autoX);printf("%s", disp[i][1]);
                gotoxy(44, autoX);printf("%s", disp[i][2]);
                gotoxy(61, autoX);printf("%s", disp[i][3]);
                gotoxy(76, autoX);printf("%s", disp[i][4]);
                gotoxy(94, autoX);printf("%s", disp[i][5]);
                gotoxy(111, autoX);printf("%s", disp[i][6]);
                autoX++;
        }

        gotoxy(1,autoX);printf("====================================================================================================================");

        gotoxy(51,autoX+3);system("pause>nul | echo Klik enter untuk kembali!");
        strcpy(strLog, "Admin melihat data jadwal penerbangan");
        insertLog(strLog);
        system("cls");
        mainMenu();
}

void addFirst() {
        strcpy(cd, "GIA768");
        strcpy(al, "Garuda Indonesia");
        strcpy(tp, "Boeing 777");
        strcpy(ds, "Denpasar");
        strcpy(dt, "Domestik");
        strcpy(de, "13 April 2022");
        strcpy(cl, "07.30");
        insert(cd, al, tp, ds, dt, de, cl);
        strcpy(cd, "SIA998");
        strcpy(al, "Singapore Airlines");
        strcpy(tp, "Airbus A340");
        strcpy(ds, "Singapore");
        strcpy(dt, "Internasional");
        strcpy(de, "13 April 2022");
        strcpy(cl, "07.45");
        insert(cd, al, tp, ds, dt, de, cl);
        strcpy(cd, "ETD221");
        strcpy(al, "Etihad");
        strcpy(tp, "Airbus A380");
        strcpy(ds, "Abu Dhabi");
        strcpy(dt, "Internasional");
        strcpy(de, "13 April 2022");
        strcpy(cl, "08.15");
        insert(cd, al, tp, ds, dt, de, cl);
        lim = 3;
}

void add() {
        gotoxy(30,1);printf("===============================================================");
        gotoxy(49,2);printf("Tambah Jadwal Penerbangan");
        gotoxy(30,3);printf("===============================================================");
        gotoxy(37,5);printf("|");
        gotoxy(37,6);printf("|");
        gotoxy(85,5);printf("|");
        gotoxy(85,6);printf("|");
        gotoxy(39,5);printf("Jumlah data maksimum yang dapat di input\t: 5");
        gotoxy(39,6);printf("Masukan jumlah data yang ingin di input\t: ");
        scanf("%d", &z);

        autoX = 8;
        if (z <= 5) {
                for (i = 0; i < z; i++) {
                        gotoxy(30,autoX++);printf("---------------------------------------------------------------");
                        gotoxy(42,autoX++);printf("=> Jadwal Penerbangan %d", lim+1);
                        gotoxy(45,autoX++);printf("Kode Penerbangan\t: ");
                        scanf("%s", &cd);
                        gotoxy(45,autoX++);printf("Maskapai\t\t: ");
                        scanf(" %[^\n]s", &al);
                        gotoxy(45,autoX++);printf("Tipe Pesawat\t: ");
                        scanf(" %[^\n]s", &tp);
                        gotoxy(45,autoX++);printf("Destinasi\t\t: ");
                        scanf(" %[^\n]s", &ds);
                        gotoxy(45,autoX++);printf("Tipe Destinasi\t: ");
                        scanf("%s", &dt);
                        gotoxy(45,autoX++);printf("Tanggal\t\t: ");
                        scanf(" %[^\n]s", &de);                        
                        gotoxy(45,autoX++);printf("Waktu TakeOFf\t: ");
                        scanf("%s", &cl);
                        gotoxy(30,autoX++);printf("---------------------------------------------------------------");
                        insert(cd, al, tp, ds, dt, de, cl);
                        lim++;
                        autoX = autoX + 2;
                        strcpy(strLog, "Admin menambahkan data dengan kode penerbangan ");
                        strcat(strLog, cd);
                        insertLog(strLog);
                }
                gotoxy(51, autoX+2);system("pause>nul | echo Data berhasil ditambahkan!");
                system("cls");
                mainMenu();
        }

        else {
                gotoxy(51, 8);system("pause>nul | echo Jumlah melebihi batas!");
                system("cls");
                add();
        }

        system("pause");
        system("cls");
        mainMenu();
}

void editing() {
        gotoxy(30,1);printf("===============================================================");
        gotoxy(50,2);printf("Edit Jadwal Penerbangan");
        gotoxy(30,3);printf("===============================================================");
        gotoxy(2,5);printf("Data yang akan diubah :");
        gotoxy(2,7);printf("No");
        gotoxy(6,7);printf("Kode");
        gotoxy(18,7);printf("Maskapai");
        gotoxy(44,7);printf("Tipe Pesawat");
        gotoxy(61,7);printf("Destinasi");
        gotoxy(76,7);printf("Tipe Destinasi");
        gotoxy(94,7);printf("Tanggal TakeOff");
        gotoxy(111,7);printf("Jam");
        gotoxy(1,8);printf("====================================================================================================================");
        autoX = 9;
        if (z != -1) {
                gotoxy(2, autoX);printf("%d", 1);
                gotoxy(6, autoX);printf("%s", temp[0]);
                gotoxy(18, autoX);printf("%s", temp[1]);
                gotoxy(44, autoX);printf("%s", temp[2]);
                gotoxy(61, autoX);printf("%s", temp[3]);
                gotoxy(76, autoX);printf("%s", temp[4]);
                gotoxy(94, autoX);printf("%s", temp[5]);
                gotoxy(111, autoX);printf("%s", temp[6]);
        }
        gotoxy(1,autoX+1);printf("====================================================================================================================");

        autoX++;
        slct = 0;
        gotoxy(30,autoX+3);printf("===============================================================");
        gotoxy(43,autoX+4);printf("Data yang ingin diubah :");
        gotoxy(45,autoX+6);printf("1. Kode");
        gotoxy(45,autoX+7);printf("2. Maskapai");
        gotoxy(45,autoX+8);printf("3. Tipe");
        gotoxy(45,autoX+9);printf("4. Destinasi");
        gotoxy(65,autoX+6);printf("5. Tipe Destinasi");
        gotoxy(65,autoX+7);printf("6. Tanggal TakeOff");
        gotoxy(65,autoX+8);printf("7. Jam ");
        gotoxy(30,autoX+12);printf("===============================================================");
        gotoxy(43,autoX+11);printf("Data yang ingin diubah :");
        scanf("%d", & slct);


        switch(slct) {
                case 1 :
                        current = head;
                        while (current != NULL) {
                                cmpr = strcmp(ed, current->code);
                                if (cmpr == 0) {
                                        gotoxy(43,autoX+14);printf("Kode Sebelumnya\t: %s", current->code) ;
                                        gotoxy(43,autoX+15);printf("Kode Baru\t\t: ");
                                        scanf(" %[^\n]s", &newVal);
                                        strcpy(current->code, newVal);
                                        gotoxy(51,autoX+18);system("pause>nul | echo Data berhasil di ubah!");
                                        strcpy(strLog, "Admin mengubah data kode penerbangan pada kode penerbangan ");
                                        strcat(strLog, ed);
                                        insertLog(strLog);
                                        system("cls");
                                        mainMenu();
                                }
                                current = current->next;
                        }
                        break;
                case 2 :
                        current = head;
                        while (current != NULL) {
                                cmpr = strcmp(ed, current->code);
                                if (cmpr == 0) {
                                        gotoxy(43,autoX+14);printf("Maskapai Sebelumnya\t: %s", current->airline) ;
                                        gotoxy(43,autoX+15);printf("Maskapai Baru\t: ");
                                        scanf(" %[^\n]s", &newVal);
                                        strcpy(current->airline, newVal);
                                        gotoxy(51,autoX+18);system("pause>nul | echo Data berhasil di ubah!");
                                        strcpy(strLog, "Admin mengubah data maskapai pada kode penerbangan ");
                                        strcat(strLog, ed);
                                        insertLog(strLog);
                                        system("cls");
                                        mainMenu();
                                }
                                current = current->next;
                        }
                        break;
                case 3 :
                        current = head;
                        while (current != NULL) {
                                cmpr = strcmp(ed, current->code);
                                if (cmpr == 0) {
                                        gotoxy(43,autoX+14);printf("Tipe Pesawat Sebelumnya\t: %s", current->type) ;
                                        gotoxy(43,autoX+15);printf("Tipe Pesawat Baru\t\t: ");
                                        scanf(" %[^\n]s", &newVal);
                                        strcpy(current->type, newVal);
                                        gotoxy(51,autoX+18);system("pause>nul | echo Data berhasil di ubah!");
                                        strcpy(strLog, "Admin mengubah data tipe pesawat pada kode penerbangan ");
                                        strcat(strLog, ed);
                                        insertLog(strLog);
                                        system("cls");
                                        mainMenu();
                                }
                                current = current->next;
                        }
                        break;
                case 4 :
                        current = head;
                        while (current != NULL) {
                                cmpr = strcmp(ed, current->code);
                                if (cmpr == 0) {
                                        gotoxy(43,autoX+14);printf("Destinasi Sebelumnya\t: %s", current->dest) ;
                                        gotoxy(43,autoX+15);printf("Destinasi Baru\t: ");
                                        scanf(" %[^\n]s", &newVal);
                                        strcpy(current->dest, newVal);
                                        gotoxy(51,autoX+18);system("pause>nul | echo Data berhasil di ubah!");
                                        strcpy(strLog, "Admin mengubah data destinasi pada kode penerbangan ");
                                        strcat(strLog, ed);
                                        insertLog(strLog);
                                        system("cls");
                                        mainMenu();
                                }
                                current = current->next;
                        }
                        break;
                case 5 :
                        current = head;
                        while (current != NULL) {
                                cmpr = strcmp(ed, current->code);
                                if (cmpr == 0) {
                                        gotoxy(43,autoX+14);printf("Tipe Destinasi Sebelumnya\t: %s", current->desttyp) ;
                                        gotoxy(43,autoX+15);printf("Tipe Destinasi Baru\t: ");
                                        scanf(" %[^\n]s", &newVal);
                                        strcpy(current->desttyp, newVal);
                                        gotoxy(51,autoX+18);system("pause>nul | echo Data berhasil di ubah!");
                                        strcpy(strLog, "Admin mengubah data tipe destinasi pada kode penerbangan ");
                                        strcat(strLog, ed);
                                        insertLog(strLog);
                                        system("cls");
                                        mainMenu();
                                }
                                current = current->next;
                        }
                        break;
                case 6 :
                        current = head;
                        while (current != NULL) {
                                cmpr = strcmp(ed, current->code);
                                if (cmpr == 0) {
                                        gotoxy(43,autoX+14);printf("Tanggal Sebelumnya\t: %s", current->date) ;
                                        gotoxy(43,autoX+15);printf("Tanggal Baru\t\t: ");
                                        scanf(" %[^\n]s", &newVal);
                                        strcpy(current->date, newVal);
                                        gotoxy(51,autoX+18);system("pause>nul | echo Data berhasil di ubah!");
                                        strcpy(strLog, "Admin mengubah data tanggal pada kode penerbangan ");
                                        strcat(strLog, ed);
                                        insertLog(strLog);
                                        system("cls");
                                        mainMenu();
                                }
                                current = current->next;
                        }
                        break;
                case 7 :
                        current = head;
                        while (current != NULL) {
                                cmpr = strcmp(ed, current->code);
                                if (cmpr == 0) {
                                        gotoxy(43,autoX+14);printf("Jam Sebelumnya\t: %s", current->clock) ;
                                        gotoxy(43,autoX+15);printf("Jam Baru\t\t: ");
                                        scanf(" %[^\n]s", &newVal);
                                        strcpy(current->clock, newVal);
                                        gotoxy(51,autoX+18);system("pause>nul | echo Data berhasil di ubah!");
                                        strcpy(strLog, "Admin mengubah data jam pada kode penerbangan ");
                                        strcat(strLog, ed);
                                        insertLog(strLog);
                                        system("cls");
                                        mainMenu();
                                }
                                current = current->next;
                        }
                        break;

                        
        }
        
}

void edit() {
        gotoxy(30,1);printf("===============================================================");
        gotoxy(50,2);printf("Edit Jadwal Penerbangan");
        gotoxy(30,3);printf("===============================================================");
        gotoxy(2,6);printf("No");
        gotoxy(6,6);printf("Kode");
        gotoxy(18,6);printf("Maskapai");
        gotoxy(44,6);printf("Tipe Pesawat");
        gotoxy(61,6);printf("Destinasi");
        gotoxy(76,6);printf("Tipe Destinasi");
        gotoxy(94,6);printf("Tanggal TakeOff");
        gotoxy(111,6);printf("Jam");
        gotoxy(1,7);printf("====================================================================================================================");
        current = head;
        i = 0;
        while (current != NULL) {
                strcpy(disp[i][0], current->code);
                strcpy(disp[i][1], current->airline);
                strcpy(disp[i][2], current->type);
                strcpy(disp[i][3], current->dest);
                strcpy(disp[i][4], current->desttyp);
                strcpy(disp[i][5], current->date);
                strcpy(disp[i][6], current->clock);
                current = current->next;
                i++;
        }
        
        autoX = 8;
        for (i = 0; i < lim; i++) {
                gotoxy(2, autoX);printf("%d", i+1);
                gotoxy(6, autoX);printf("%s", disp[i][0]);
                gotoxy(18, autoX);printf("%s", disp[i][1]);
                gotoxy(44, autoX);printf("%s", disp[i][2]);
                gotoxy(61, autoX);printf("%s", disp[i][3]);
                gotoxy(76, autoX);printf("%s", disp[i][4]);
                gotoxy(94, autoX);printf("%s", disp[i][5]);
                gotoxy(111, autoX);printf("%s", disp[i][6]);
                autoX++;
        }

        gotoxy(1,autoX);printf("====================================================================================================================");
        gotoxy(30,autoX+4);printf("================================================");
        gotoxy(30,autoX+3);printf("Masukan kode yang ingin di ubah : ");
        scanf("%s", &ed);

        current = head;
        i = 0;
        z = -1;
        while (current != NULL) {
                cmpr = strcmp(ed, current->code);
                if (cmpr == 0) {
                        z = i + 1;
                        strcpy(temp[0], current->code);
                        strcpy(temp[1], current->airline);
                        strcpy(temp[2], current->type);
                        strcpy(temp[3], current->dest);
                        strcpy(temp[4], current->desttyp);
                        strcpy(temp[5], current->date);
                        strcpy(temp[6], current->clock);
                }
                current = current->next;
                i++;
        }

        if (z == -1) {
                gotoxy(33,autoX+7);system("pause>nul | echo Kode yang anda inputkan tidak ada di dalam Database!");
                system("cls");
                edit();
        }
        else {
               system("cls");
               editing(); 
        }

        
}

void popHead(){
	current=head;
	if(head==NULL){
		printf("No data");
	}else if(head==tail){
		head=tail=NULL;
		free(current);
	}else{
		head=head->next;
		free(current);
	}
}

void popTail(){
	if(head==NULL){
		printf("No data");
	}else if(head==tail){
		head=tail=NULL;
		free(current);
	}else{
		struct data *temp=head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		current=tail;
		tail=temp;
		free(current);
		tail->next=NULL;
	}
}

void pop(char in[]) {
        int cmp1, cmp2, cmp3;
	struct data *temp=head;
        cmp1 = strcmp(head->code, in);
        cmp2 = strcmp(tail->code, in);
        cmp3 = strcmp(temp->next->code, in);
        if(head==NULL){
		printf("No data");
	}else if(cmp1 == 0){
		popHead();
	}else if(cmp2 == 0){
		popTail();
	}else{
		while(cmp3!=0 && temp!=tail){
			temp=temp->next;
		}
		current=temp->next;
		temp->next=temp->next->next;
		free(current);
	}
}

void delt() {
        gotoxy(30,1);printf("===============================================================");
        gotoxy(50,2);printf("Hapus Jadwal Penerbangan");
        gotoxy(30,3);printf("===============================================================");
        gotoxy(2,6);printf("No");
        gotoxy(6,6);printf("Kode");
        gotoxy(18,6);printf("Maskapai");
        gotoxy(44,6);printf("Tipe Pesawat");
        gotoxy(61,6);printf("Destinasi");
        gotoxy(76,6);printf("Tipe Destinasi");
        gotoxy(94,6);printf("Tanggal TakeOff");
        gotoxy(111,6);printf("Jam");
        gotoxy(1,7);printf("====================================================================================================================");
        current = head;
        i = 0;
        while (current != NULL) {
                strcpy(disp[i][0], current->code);
                strcpy(disp[i][1], current->airline);
                strcpy(disp[i][2], current->type);
                strcpy(disp[i][3], current->dest);
                strcpy(disp[i][4], current->desttyp);
                strcpy(disp[i][5], current->date);
                strcpy(disp[i][6], current->clock);
                current = current->next;
                i++;
        }
        
        autoX = 8;
        for (i = 0; i < lim; i++) {
                gotoxy(2, autoX);printf("%d", i+1);
                gotoxy(6, autoX);printf("%s", disp[i][0]);
                gotoxy(18, autoX);printf("%s", disp[i][1]);
                gotoxy(44, autoX);printf("%s", disp[i][2]);
                gotoxy(61, autoX);printf("%s", disp[i][3]);
                gotoxy(76, autoX);printf("%s", disp[i][4]);
                gotoxy(94, autoX);printf("%s", disp[i][5]);
                gotoxy(111, autoX);printf("%s", disp[i][6]);
                autoX++;
        }

        gotoxy(1,autoX);printf("====================================================================================================================");
        gotoxy(30,autoX+4);printf("================================================");
        gotoxy(30,autoX+3);printf("Masukan kode yang ingin di hapus : ");
        scanf("%s", &del);
        current = head;
        z = -1;
        cmpr = 0;
        while (current != NULL) {
                cmpr = strcmp(current->code, del);
                
                if (cmpr == 0) {
                        z = 5;
                }
                current = current->next;
        }
        if (z != -1) {
                pop(del);
        }
        else {  
                gotoxy(37,autoX+6);system("pause>nul | echo Kode yang anda inputkan tidak ada!");
                system("cls");
                delt();
        }
        lim--;
        strcpy(strLog, "Admin menghapus data dengan kode ");
        strcat(strLog, del);
        insertLog(strLog);
        gotoxy(46, autoX+7);system("pause>nul | echo Data berhasil dihapus!"); 
        system("cls");
        mainMenu();
}

void search() {
        gotoxy(30,1);printf("===============================================================");
        gotoxy(50,2);printf("Cari Jadwal Penerbangan");
        gotoxy(30,3);printf("===============================================================");
        gotoxy(30,5);printf("Cari Berdasarkan :");
        gotoxy(47,7);printf("1. Kode Penerbangan");
        gotoxy(47,8);printf("2. Maskapai");
        gotoxy(47,9);printf("3. Tipe Pesawat");
        gotoxy(47,10);printf("4. Destinasi");
        gotoxy(47,11);printf("5. Tipe Destinasi");
        gotoxy(47,12);printf("6. Tanggal TakeOff");
        gotoxy(47,13);printf("7. Batal");
        gotoxy(30,15);printf("===============================================================");
        gotoxy(30,17);printf("===============================================================");
        gotoxy(32,16);printf("Masukan Pilihan Anda : ");
        scanf("%d", &slct);
        if (slct == 7) {
                system("cls");
                mainMenu();
        }
        gotoxy(30,20);printf("============================================");
        gotoxy(32,19);printf("Masukan kata kunci : ");
        scanf(" %[^\n]s", &srch);

        current = head;
        i = 0;
        while (current != NULL) {
                strcpy(searching[i][0], current->code);
                strcpy(searching[i][1], current->airline);
                strcpy(searching[i][2], current->type);
                strcpy(searching[i][3], current->dest);
                strcpy(searching[i][4], current->desttyp);
                strcpy(searching[i][5], current->date);
                strcpy(searching[i][6], current->clock);
                current = current->next;
                i++;
        }

        z = -1;

        for (i = 0; i < lim; i++) {
                cmpr = strcmp(srch, searching[i][slct-1]);
                if (cmpr == 0) {
                        z = i + 1;
                }
        }

        if (z == -1) {
                gotoxy(32, 22);printf("== Maaf data yang anda cari tidak ditemukan di Database ! ==");
                strcpy(strLog, "Admin mencari data dengan kata kunci ");
                strcpy(yynn, " (Data tidak ditemukan)");
                strcat(strLog, srch);
                strcat(strLog, yynn);
                insertLog(strLog);
        }
        else {
                gotoxy(30, 22);printf("== Data yang anda cari ditemukan di indeks %d pada Database ! ==", z);
                strcpy(strLog, "Admin mencari data dengan kata kunci ");
                strcpy(yynn, " (Data ditemukan)");
                strcat(strLog, srch);
                strcat(strLog, yynn);
                insertLog(strLog);
        }

        printf("\n\n");
        autoX = 28;
        
        if (z != -1) {     
                gotoxy(46, autoX-3);system("pause>nul | echo Klik Enter untuk menampilkan data");   
                gotoxy(2,autoX);printf("No");
                gotoxy(6,autoX);printf("Kode");
                gotoxy(18,autoX);printf("Maskapai");
                gotoxy(44,autoX);printf("Tipe Pesawat");
                gotoxy(61,autoX);printf("Destinasi");
                gotoxy(76,autoX);printf("Tipe Destinasi");
                gotoxy(94,autoX);printf("Tanggal TakeOff");
                gotoxy(111,autoX);printf("Jam");
                gotoxy(1,autoX+1);printf("====================================================================================================================");        
                gotoxy(2, autoX+2);printf("%d", z);
                gotoxy(6, autoX+2);printf("%s", searching[z-1][0]);
                gotoxy(18, autoX+2);printf("%s", searching[z-1][1]);
                gotoxy(44, autoX+2);printf("%s", searching[z-1][2]);
                gotoxy(61, autoX+2);printf("%s", searching[z-1][3]);
                gotoxy(76, autoX+2);printf("%s", searching[z-1][4]);
                gotoxy(94, autoX+2);printf("%s", searching[z-1][5]);
                gotoxy(111, autoX+2);printf("%s", searching[z-1][6]);
                gotoxy(1,autoX+3);printf("====================================================================================================================");        

        }

        gotoxy(51,autoX+5);system("pause>nul | echo Klik enter untuk kembali!");
        system("cls");
        mainMenu();

}

void sortLog(int plh) {
        i = 0;
        current = head;
        while (current != NULL) {
                strcpy(sorting[i][0], current->code);
                strcpy(sorting[i][1], current->airline);
                strcpy(sorting[i][2], current->type);
                strcpy(sorting[i][3], current->dest);
                strcpy(sorting[i][4], current->desttyp);
                strcpy(sorting[i][5], current->date);
                strcpy(sorting[i][6], current->clock);
                current = current->next;
                i++;
        }

        for (a = 0; a < lim; a++) {
                for (b = a+1; b < lim; b++) {
                        for (c = 0; c < 50; c++) {
                                if (sorting[a][plh-1][c] < sorting[b][plh-1][c]){
                                        break;
                                }
                                else if (sorting[a][plh-1][c] > sorting[b][plh-1][c]) {
                                        strcpy(temp[0], sorting[a][0]);
                                        strcpy(temp[1], sorting[a][1]);
                                        strcpy(temp[2], sorting[a][2]);
                                        strcpy(temp[3], sorting[a][3]);
                                        strcpy(temp[4], sorting[a][4]);
                                        strcpy(temp[5], sorting[a][5]);
                                        strcpy(temp[6], sorting[a][6]);

                                        strcpy(sorting[a][0], sorting[b][0]);
                                        strcpy(sorting[a][1], sorting[b][1]);
                                        strcpy(sorting[a][2], sorting[b][2]);
                                        strcpy(sorting[a][3], sorting[b][3]);
                                        strcpy(sorting[a][4], sorting[b][4]);
                                        strcpy(sorting[a][5], sorting[b][5]);
                                        strcpy(sorting[a][6], sorting[b][6]);

                                        strcpy(sorting[b][0], temp[0]);
                                        strcpy(sorting[b][1], temp[1]);
                                        strcpy(sorting[b][2], temp[2]);
                                        strcpy(sorting[b][3], temp[3]);
                                        strcpy(sorting[b][4], temp[4]);
                                        strcpy(sorting[b][5], temp[5]);
                                        strcpy(sorting[b][6], temp[6]);
                                        break;
                                }
                        }
                }
        }

        autoX = 10;
        gotoxy(2,autoX-2);printf("No");
        gotoxy(6,autoX-2);printf("Kode");
        gotoxy(18,autoX-2);printf("Maskapai");
        gotoxy(44,autoX-2);printf("Tipe Pesawat");
        gotoxy(61,autoX-2);printf("Destinasi");
        gotoxy(76,autoX-2);printf("Tipe Destinasi");
        gotoxy(94,autoX-2);printf("Tanggal TakeOff");
        gotoxy(111,autoX-2);printf("Jam");
        gotoxy(1,autoX-1);printf("====================================================================================================================");
        for (i = 0; i < lim; i++) {
                gotoxy(2, autoX);printf("%d", i+1);
                gotoxy(6, autoX);printf("%s", sorting[i][0]);
                gotoxy(18, autoX);printf("%s", sorting[i][1]);
                gotoxy(44, autoX);printf("%s", sorting[i][2]);
                gotoxy(61, autoX);printf("%s", sorting[i][3]);
                gotoxy(76, autoX);printf("%s", sorting[i][4]);
                gotoxy(94, autoX);printf("%s", sorting[i][5]);
                gotoxy(111, autoX);printf("%s", sorting[i][6]);
                autoX++;
        }
        gotoxy(1,autoX);printf("====================================================================================================================");

        gotoxy(51,autoX+3);system("pause>nul | echo Klik enter untuk kembali!");
        system("cls");
        mainMenu();
}

void sort() {
        gotoxy(30,1);printf("===============================================================");
        gotoxy(49,2);printf("Urutkan Jadwal Penerbangan");
        gotoxy(30,3);printf("===============================================================");
        gotoxy(30,5);printf("Urutkan Berdasarkan :");
        gotoxy(47,7);printf("1. Kode Penerbangan");
        gotoxy(47,8);printf("2. Maskapai");
        gotoxy(47,9);printf("3. Tipe Pesawat");
        gotoxy(47,10);printf("4. Destinasi");
        gotoxy(47,11);printf("5. Tipe Destinasi");
        gotoxy(47,12);printf("6. Waktu TakeOff");
        gotoxy(47,13);printf("7. Batal");
        gotoxy(30,15);printf("===============================================================");
        gotoxy(30,17);printf("===============================================================");
        gotoxy(32,16);printf("Masukan Pilihan Anda : ");
        scanf("%d", &plh);

        switch(plh) {
                case 1 :
                        system("cls");
                        gotoxy(30,1);printf("===============================================================");
                        gotoxy(45,2);printf("Urutkan Jadwal Penerbangan");
                        gotoxy(30,3);printf("===============================================================");
                        gotoxy(30,5);printf("Urutkan Berdasarkan > Kode Penerbangan");
                        sortLog(plh);
                        strcpy(strLog, "Admin mengurutkan data berdasarkan kode penerbangan ");
                        insertLog(strLog);
                        break;
                case 2 :
                        system("cls");  
                        gotoxy(30,1);printf("===============================================================");
                        gotoxy(45,2);printf("Urutkan Jadwal Penerbangan");
                        gotoxy(30,3);printf("===============================================================");
                        gotoxy(30,5);printf("Urutkan Berdasarkan > Maskapai"); 
                        strcpy(strLog, "Admin mengurutkan data berdasarkan maskapai ");
                        insertLog(strLog);                   
                        sortLog(plh);
                        break;
                case 3 :
                        system("cls");
                        gotoxy(30,1);printf("===============================================================");
                        gotoxy(45,2);printf("Urutkan Jadwal Penerbangan");
                        gotoxy(30,3);printf("===============================================================");
                        gotoxy(30,5);printf("Urutkan Berdasarkan > Tipe Pesawat");
                        strcpy(strLog, "Admin mengurutkan data berdasarkan tipe pesawat ");
                        insertLog(strLog);
                        sortLog(plh);
                        break;
                case 4 :
                        system("cls");
                        gotoxy(30,1);printf("===============================================================");
                        gotoxy(45,2);printf("Urutkan Jadwal Penerbangan");
                        gotoxy(30,3);printf("===============================================================");
                        gotoxy(30,5);printf("Urutkan Berdasarkan > Destinasi");
                        strcpy(strLog, "Admin mengurutkan data berdasarkan destinasi ");
                        insertLog(strLog);
                        sortLog(plh);
                        break;
                case 5 :
                        system("cls");
                        gotoxy(30,1);printf("===============================================================");
                        gotoxy(45,2);printf("Urutkan Jadwal Penerbangan");
                        gotoxy(30,3);printf("===============================================================");
                        gotoxy(30,5);printf("Urutkan Berdasarkan > Tipe Destinasi");
                        strcpy(strLog, "Admin mengurutkan data berdasarkan tipe destinasi ");
                        insertLog(strLog);
                        sortLog(plh);
                        break;
                case 6 :
                        system("cls");
                        gotoxy(30,1);printf("===============================================================");
                        gotoxy(45,2);printf("Urutkan Jadwal Penerbangan");
                        gotoxy(30,3);printf("===============================================================");
                        gotoxy(30,5);printf("Urutkan Berdasarkan > Waktu TakOff");
                        strcpy(strLog, "Admin mengurutkan data berdasarkan waktu takeoff ");
                        insertLog(strLog);
                        sortLog(plh);
                        break;
                case 7 :
                        system("cls");
                        mainMenu();
                        break;
        }

        
}

void history() {
        gotoxy(30,1);printf("===============================================================");
        gotoxy(50,2);printf("Riwayat Aktivitas Admin");
        gotoxy(30,3);printf("===============================================================");
        gotoxy(1,6);printf("====================================================================================================================");
        gotoxy(4,7);printf("No");
        gotoxy(10,7);printf("Waktu");
        gotoxy(45,7);printf("Aktivitas");
        gotoxy(1,8);printf("====================================================================================================================");
        int llim = 0;
        logcur = loghd;
        i = 0;
        autoX = 9;
        while (logcur != NULL) {
                dispT[i][0] = logcur->logh;
                dispT[i][1] = logcur->logm;
                dispT[i][2] = logcur->logdd;
                dispT[i][3] = logcur->logmm;
                dispT[i][4] = logcur->logyy;
                strcpy(disp[i][0], logcur->logN);
                logcur = logcur->next;
                llim++;
                i++;
        }
        z = 1;
        for (i = llim-1; i >= 0; i--) {
                gotoxy(4, autoX);printf("%d", z);
                gotoxy(10, autoX);printf("%02d", dispT[i][0]);
                gotoxy(12, autoX);printf(":");
                gotoxy(13, autoX);printf("%02d", dispT[i][1]);
                gotoxy(19, autoX);printf("%02d/", dispT[i][2]);
                gotoxy(22, autoX);printf("%02d/", dispT[i][3]);
                gotoxy(25, autoX);printf("%02d", dispT[i][4]-100);
                gotoxy(45, autoX);printf("%s", disp[i][0]);
                autoX++;
                z++;
        }

        gotoxy(51,autoX+2);system("pause>nul | echo Klik enter untuk kembali!");
        system("cls");
        mainMenu();
}

void mainMenu() {
        slct = 0;
        gotoxy(30,1);printf("===============================================================");
        gotoxy(45,2);printf("Selamat Datang di Aplikasi Admin");
        gotoxy(42,3);printf("Penjadwalan Penerbangan Bandara Namexx");
        gotoxy(30,4);printf("===============================================================");
        gotoxy(53,6);printf("== Menu Utama ==");
        gotoxy(47,8);printf("1. Tampilkan Isi Database");
        gotoxy(47,9);printf("2. Tambah Jadwal Penerbangan");
        gotoxy(47,10);printf("3. Ubah Jadwal Penerbangan");
        gotoxy(47,11);printf("4. Hapus Jadwal Penerbangan");
        gotoxy(47,12);printf("5. Cari Penerbangan");
        gotoxy(47,13);printf("6. Urutkan Jadwal Penerbangan");
        gotoxy(47,14);printf("7. Lihat Riwayat Aktivitas");
        gotoxy(47,15);printf("8. Keluar");
        gotoxy(78,28);printf("Developed by : Finda Affandi - 672020113");
        gotoxy(30,17);printf("===============================================================");
        gotoxy(30,19);printf("===============================================================");
        gotoxy(32,18);printf("Masukan Pilihan Anda : ");
        scanf("%d", &slct);
        switch(slct) {
                case 1 : 
                        system("cls");
                        display();
                        break;
                case 2 : 
                        system("cls");
                        add();
                        break;
                case 3 :
                        system("cls");
                        edit();
                        break;
                case 4 : 
                        system("cls");
                        delt();
                        break;
                case 5 : 
                        system("cls");
                        search();
                        break;
                case 6 : 
                        system("cls");
                        sort();
                        break;
                case 7 :
                        system("cls");
                        history();
                        break;
                case 8 :
                        gotoxy(51,21);printf("Anda yakin ingin keluar?(Y/N)");
                        char yesno[10];
                        int cmp;
                        gotoxy(63, 23);printf("=");
                        gotoxy(67, 23);printf("=");
                        gotoxy(65, 23);scanf("%s", &yesno);
                        cmp = strcmp(yesno, "y");
                        if (cmp == 0) {
                                exit(0);
                        }
                        else {
                                system("cls");
                                mainMenu();
                        }
                default :
                        gotoxy(51,21);system("pause>nul | echo Inputan salah, mohon ulangi!");
                        system("cls");
                        mainMenu();
        }
        
}