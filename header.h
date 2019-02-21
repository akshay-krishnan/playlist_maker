//      Header file for play list application
//      Created by : Akshay Krishnan  &  Srivatsa G S

#include<conio.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

#include<fstream>

using namespace std;
void clear_screen (void);
void delay(int );
 void gotoxy(int ,int );

struct Node         //declaring play list node structure
{
        char info[30];
        Node *next;
        Node *prev;
 };

class DoublyLinkedList      // class containing play list functions
{
private:

     Node *head;
     Node *tail;
     Node *current;
     bool savef;

public:

    DoublyLinkedList()      // constructor used to initialize head,tail and current node of play list
    {
        head=NULL;
        tail=NULL;
        current=NULL;
        savef=1;
    }

    bool isempty()          //function to check if play list is empty
    {
        if(head==NULL)
            return 1;
        else return 0;
    }


    void append(char *sng)  //append song at end, new song is current song
    {
        Node *temp;
        temp = new Node;
        temp->prev = temp->next = NULL;
        strcpy( temp->info , sng );
        if(isempty())
        {
            current=temp;
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
            current=temp;
        }
        savef=0;
    }

    void insertBefore(char *sng)    //to insert a song before the current song, new song becomes current song
    {
        class Node *temp;
        temp = new Node;
        temp->prev = temp->next = NULL;
        strcpy( temp->info , sng );
        if(isempty())
            head=tail=current=temp;
        else if(current->prev!=NULL)
           {
            current->prev->next=temp;
            temp->prev=current->prev;
            temp->next=current;
            current->prev=temp;
            current=temp;
            }
        else
        {
            current->prev=temp;
            temp->next=current;
            head=temp;
            current=temp;
        }
        savef=0;
        }

    void insertAfter(char *sng)
    {
       class Node *temp;
       temp = new Node;
        temp->prev = temp->next = NULL;
        strcpy( temp->info , sng );
        if(isempty())
            head=tail=current=temp;
        else
            if(current->next!=NULL)
            {
                current->next->prev=temp;
                temp->prev=current;
                temp->next=current->next;
                current->next=temp;
                current=temp;
            }
            else
                append(temp->info);
        savef=0;
        return;
    }

    void gotoFirstSong()
    {
        if(isempty())
        {
            clear_screen();
            gotoxy(34, 10);
            cout<<"playlist is empty!"<<endl;
            gotoxy(30, 12);
            cout<<"please add songs to playlist!"<<endl;
            gotoxy(30, 14);
            cout<<"press any key to continue..."<<endl;
            getch();
        }
        else current=head;
    }

    void gotoLastSong()
    {
        if(isempty())
        {
            clear_screen();
            gotoxy(34, 10);
            cout<<"playlist is empty!"<<endl;
            gotoxy(30, 12);
            cout<<"please add songs to playlist!"<<endl;
            gotoxy(30, 14);
            cout<<"press any key to continue..."<<endl;
            getch();
        }
        else current=tail;
    }


    void playCurrent()
   {
        if(isempty())
        {
            clear_screen();
            gotoxy(34, 10);
            cout<<"playlist is empty!"<<endl;
            gotoxy(30, 12);
            cout<<"please add songs to playlist!"<<endl;
            gotoxy(34, 13);
            cout<<"press any key to continue.."<<endl;
            getch();
        }
        else
        {
            system("cls");
            cout<<"current song::"<<endl
                <<current->info<<endl<<endl;
            if(current->prev!=NULL)
            cout<<"previous song::"<<endl
                <<current->prev->info<<endl<<endl;
            if(current->next!=NULL)
            cout<<"next song::"<<endl
                <<current->next->info<<endl;
            delay(6000);
            }
    }

    void nextSong()
    {
        if(current->next!=NULL)
            current=current->next;
        else
        {
            clear_screen();
            gotoxy(34, 12);
            cout<<"currently at last song..";
            delay(2000);
        }
    }

    void prevSong()
    {
        if(current->prev!=NULL)
        current=current->prev;
        else
        {
            clear_screen();
            gotoxy(34, 12);
            cout<<"currently at first song..";
            delay(2000);
        }
    }

    void playForward()
    {
        if(isempty())
        {
            clear_screen();
            gotoxy(34, 10);
            cout<<"playlist is empty!"<<endl;
            gotoxy(30, 12);
            cout<<"please add songs to playlist!"<<endl;
            gotoxy(34, 13);
            cout<<"press any key to continue.."<<endl;
            getch();
        }
        else
        {
            while(current!=NULL)
            {
                playCurrent();
                current=current->next;
            }
            current=tail;
            clear_screen();
            gotoxy(34, 12);
            cout<<"end of playlist";
            gotoxy(30, 13);
            cout<<"press any key to go to main menu";
            getch();
        }
    }

    void playReverse()
    {
        if(isempty())
        {
            clear_screen();
            gotoxy(34, 10);
            cout<<"playlist is empty!"<<endl;
            gotoxy(30, 12);
            cout<<"please add songs to playlist!"<<endl;
            gotoxy(34, 13);
            cout<<"press any key to continue.."<<endl;
            getch();
        }
        else
        {
            while(current!=NULL)
            {
                system("cls");
                cout<<"current song::"<<endl
                    <<current->info<<endl<<endl;
                if(current->next!=NULL)
                    cout<<"previous song::"<<endl
                    <<current->next->info<<endl<<endl;
                if(current->prev!=NULL)
                    cout<<"next song::"<<endl
                    <<current->prev->info<<endl;
                delay(6000);
                current=current->prev;
            }
            current=head;
            clear_screen();
            gotoxy(34, 12);
            cout<<"end of playlist!";
            gotoxy(30, 13);
            cout<<"press any key to go to main menu...";
            getch();
        }
    }

    void printAllSongs()
    {
        system("cls");
        if(isempty())
        {
            clear_screen();
            gotoxy(34, 12);
            cout<<"playlist is empty!";
            gotoxy(30, 13);
            cout<<"please add songs to playlist!"<<endl;
            gotoxy(30, 14);
            cout<<"press any key to continue..."<<endl;
            getch();
        }
        else
        {
            class Node *temp;
            temp = new Node;

            temp=head;
            cout<<endl<<"the songs in the playlist are..."<<endl<<endl;
            while(temp!=NULL)
            {
                cout<<temp->info<<endl;
                temp=temp->next;
            }
        }

        cout<<endl<<endl<<"press any key to go back to main menu..."<<endl;
        getch();
        }

    void homeList(int a, int b)
    {
        gotoxy(a,b);
        if(isempty())
        {
            cout<<"PLAYLIST EMPTY!";
            return;
        }
        cout<<"-- NOW PLAYING --";
        int x, y;
        x=a;
        y=b+2;
        Node *temp;
        temp = new Node;

        temp=head;
        while(temp!=NULL)
        {
            gotoxy(x, y);
            if(temp==current)
                cout<<temp->info<<" <-";
            else cout<<temp->info;
            temp=temp->next;
            y++;
        }
        y++;
        gotoxy(x , y);


    }

    void removeSong(char *sng)
	{
	 Node *T;
	 int found = 0;
	 if(!strcmp(head->info, sng))
	{
	    T = head;
	    if(head->next==NULL)
        {
            delete( T );
            head=current=tail=NULL;
            clear_screen();
                     gotoxy(30, 9);
                     cout<<"song has been deleted...";
                     gotoxy(30, 10);
                     cout<<"there are no more songs in the playlist";
                     gotoxy(30, 12);
                     cout<<"press any key to go to main menu..";
                     getch();
                     return;
        }
	    head= head->next;
	    head->prev = NULL;
	    current=head;
	    delete( T );
	    found = 1;
	}
	else

	{
	   T = head ;
	   while( T != tail )
	   {
		if(!strcmp(T->info, sng))
		{
		  T->next->prev = T->prev;
	 	  T->prev->next = T->next;
	 	  current=T->next;
		  delete( T );
		  found = 1;
		  break;
		}
	      T = T->next;
	  }
	  if(T==tail)
        if(!strcmp(T->info , sng))
      {
          current=T->prev;
          tail=T->prev;
          T->prev->next=NULL;
          delete(T);
          found=1;
      }
	}

	if( found ==0)
    {
        clear_screen();
        gotoxy(37,12);
        cout<<"Song not found..";
        delay(3000);
    }
	else
    {
        clear_screen();
        gotoxy(37,12);
        cout<<"Deleted successfully..";
        delay(3000);
    }
    savef=0;
	}

	void goToSong(char *sng)
	{
	 Node *T;
	 int found = 0;
	 T = head;
     if(head->next==NULL)
     {
        if(!strcmp(head->info, sng))
        {
            head=current=tail;
            found=1;
        }
        else
            found=0;
     }

	else
    {
	   T = head ;
	   while( T!= NULL )
	   {
		if(!strcmp(T->info, sng))
		{
		  current=T;
		  found=1;
		  break;
		}
	      T = T->next;
	   }
    }

	if( found ==0)
    {
        clear_screen();
        gotoxy(37,12);
        cout<<"Song not found..";
        delay(3000);
    }

    }

    void save(void)
    {
    if(head!=NULL)
    {
    clear_screen();
    char name[20];
    gotoxy(30,8);
    cout<<"enter a name for playlist";
    gotoxy(30,10);
    cin.getline(name, 20);
    strcat(name, ".txt");
    fstream fp;
    fp.open(name, ios::out|ios::in|ios::app);
    Node *temp;
    temp = new Node;
    temp=head;
    while(temp!=NULL)
    {
    fp<<temp->info<<endl;
    temp=temp->next;
    }

    fp.close();
    gotoxy(28,12);
    cout<<"playlist "<<name<<" was saved successfully!";
    savef=1;
    gotoxy(28,13);
    cout<<"press any key to continue...";
    getch();
    }

    else
    {
     clear_screen();
     cout<<"playlist is empty"<<endl
         <<"add songs first"<<endl;
    }
    }

    void load(void)
    {
    if(head!=NULL)
        savef=0;
    int n=getcount();
    clear_screen();
    char name[20];
    gotoxy(30,8);
    cout<<"enter the name of playlist";
    gotoxy(31,10);
    cin.getline(name, 20);
    strcat(name, ".txt");
    char ch[30];
    int i=0;
    fstream fp;
    fp.open(name, ios::in);
    while(!(fp).eof())
    {
    fp.getline(ch,30);
    if(strcmp(ch,"\0"))
    append(ch);
    }
    current=head;
    for(i=1;i<=n;i++)
    current=current->next;
    fp.close();
        }

    void Exitapp(void)
    {
        if(savef==1)
            exit(0);
        else
        {
            clear_screen();
            char ch;
            gotoxy(25,9);
            cout<<"playlist not saved, save before exit?";
            gotoxy(34,11);
            cout<<"(Y/N/C)";
            gotoxy(34,12);
            cin>>ch;
            cin.ignore();
            if((ch=='y')||(ch=='Y'))
            {
                save();
                exit(0);
            }
            else
                if((ch=='N')||(ch=='n'))
                exit(0);

        }
    }

    int getcount(void)
    {
        int n=0;
        Node *temp;
        temp = new Node;
        temp=head;
        while(temp!=current)
        {
            temp=temp->next;
            n++;
        }
        return n;
    }

};
void delay(int sec)
{
clock_t goal= sec + clock();
while (goal>clock());
}

void clear_screen ()
{
    DWORD n;                         /* Number of characters written */
    DWORD size;                      /* number of visible characters */
    COORD coord = {0};               /* Top left screen position */
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    /* Get a handle to the console */
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

    GetConsoleScreenBufferInfo ( h, &csbi );

    /* Find the number of characters to overwrite */
    size = csbi.dwSize.X * csbi.dwSize.Y;

    /* Overwrite the screen buffer with whitespace */
    FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
    GetConsoleScreenBufferInfo ( h, &csbi );
    FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

    /* Reset the cursor to the top left position */
    SetConsoleCursorPosition ( h, coord );
}
 COORD coord={0,0};
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

