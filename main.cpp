//       PLAYLIST MAKER APPLICATION
//              PlayGen 1.0
//   By Akshay Krishnan & G S Srivatsa


#include"header.h"


int main()
{
    char song[30];
    int choice;
    class DoublyLinkedList a;

    while(1)
    {
        clear_screen();
        cout<<endl<<"enter a choice::"<<endl<<endl
            <<"1. Append song"<<endl
            <<"2. Insert before"<<endl
            <<"3. Insert after"<<endl
            <<"4. Play current song"<<endl
            <<"5. Remove Song"<<endl
            <<"6. Find a song"<<endl
            <<"7. Go to first song"<<endl
            <<"8. Go to last song"<<endl
            <<"9. Next song"<<endl
            <<"10. Previous song"<<endl
            <<"11. Play Forward"<<endl
            <<"12. Play Reverse"<<endl
            <<"13. Print all songs in list"<<endl
            <<"14. Save"<<endl
            <<"15. Load"<<endl
            <<"16. EXIT"<<endl;

        a.homeList(42,2);
        gotoxy(8,20);
        cout<<"choice: ";
        cin>>choice;
        cin.ignore();


        switch(choice)
        {
        case 1 :
            clear_screen();
            cout<<"enter the song to be appended"<<endl<<endl;
            cin.getline(song,30);
            a.append(song);
            break;

        case 2 :
            clear_screen();
            cout<<"enter the song to be inserted"<<endl<<endl;
            cin.getline(song,30);
            a.insertBefore(song);
            break;

        case 3 :
            clear_screen();
            cout<<"enter the song to be inserted"<<endl<<endl;
            cin.getline(song,30);
            a.insertAfter(song);
            break;

        case 4 :
            clear_screen();
            a.playCurrent();
            delay(6000);
            break;

        case 5 :
            clear_screen();
            cout<<"enter the song to be removed"<<endl<<endl;
            cin.getline(song,30);
            a.removeSong(song);
            break;

        case 6 :
            clear_screen();
            cout<<"enter the song to got to"<<endl<<endl;
            cin.getline(song,30);
            a.goToSong(song);
            break;

        case 7 :
            a.gotoFirstSong();
            break;

        case 8 :
            a.gotoLastSong();
            break;

        case 9 :
            a.nextSong();
            break;

        case 10 :
            a.prevSong();
            break;

        case 11 :
            a.playForward();
            break;

        case 12 :
            a.playReverse();
            break;

        case 13 :
            a.printAllSongs();
            break;

        case 14 :
            a.save();
            break;

        case 15 :
            a.load();
            break;

        case 16 :
            a.Exitapp();
        }

     }
}

