#include <bits/stdc++.h>
#include<fstream>
#include<conio.h>
using namespace std;
int  k=0;
class team
{
    char captain[20],coach[20],city[20],owner[20];
    char player[11][30],date[10],time[5],stadium[30],country[15];
    int d,m,y,mi,h;
    int trun[11],tmatch[11],tcatch[11],twicket[11];
    char ptype[15];

int temp=0;
    public:

        char teamname[30],tname[2][30];
        char teamid[5];
        void teamdetails();
        void showdetails();
        void readdetails();
        void searchdetails(char *);
        void deletedetails(char *);
        void updatedetails(char *);
        void wplayerlist();
        void rplayerlist();
        void readplist();
        void writeplist();
        void wschedule();
        void rschedule();
        void showschedule();
        void timedate();
        void rtimedate();
        void scoring();
};
void team::scoring()
{
    int n,p;
    int i=0;
    int j=0;
    int w=0;

    while(1){getch();
    system("cls");
    cout<<"\t\t\t\tIPL Scoring System\n";
    cout<<"\t\t*************************************************\n\n";
    cout<<tname[0]<<" VS "<<tname[1]<<endl<<endl;
    if(k==0)
    {
        cout<<"Inning "<<k+1<<endl;
        cout<<"___________________________________\n";
        cout<<"Batting:"<<tname[0]<<endl;
    }
    else
       {   cout<<"Inning 2"<<endl;
        cout<<"___________________________________\n";
           cout<<"Batting:"<<tname[1]<<endl;}
    cout<<"1.add 1 run\n";
     cout<<"2.add 2 run\n";
      cout<<"3.add 3 run\n";
       cout<<"4.add 4 run\n";
        cout<<"6.add 6 run\n";
        cout<<"7.Current score\n";
        cout<<"8.Wicket!!\n";
        cout<<"9.End the Inning\n";
        cout<<"10.Exit\n";

        cin>>n;
if(w==10 | j==180)
               {
                         n=9;
                     }
    switch(n)
    {
        case 1:{j++;
            i=i+1;
            cout<<"Run:"<<i;
        cout<<"\n\n";
        break;}
        case 2:
            {
                j++;
            i=i+2;
                cout<<"Run:"<<i<<endl;
                cout<<"\n";}break;
          case 3:
            {
                 j++;
            i=i+3;
                cout<<"Run:"<<i<<endl;}break;
                case 4:
            { j++;
                i=i+4;
                cout<<"Four!!!!\n";
                cout<<"Run:"<<i<<endl;}break;
                case 6:
            {
             j++;
            i=i+6;
             cout<<"Six!!!!\n";
                cout<<"Run:"<<i<<endl;}break;
                case 7:{cout<<"*****************************************************\n";
               cout<<"Current score in "<<j <<" balls is "<<i<<" with loss of "<<w<<" Wickets\n";
               cout<<"*****************************************************\n"; }break;
                case 8:{++w;
                    cout<<"Wicket!!!!!\n";

                    break;}

                case 9:{++k;

                    cout<<"Inning "<< k <<" Ended!!!!\n";
                    if(k==1)
                    {
                        cout<<tname[0];
                        cout<<"\n____________________\n";
                    }
                    else{
                        cout<<tname[1];
                        cout<<"\n____________________\n";
                    }

                    cout<<"\nTotal score in "<<j <<" balls is "<<i<<" with loss of "<<w<<" Wickets";
                    cout<<"\n---------------------------------------------------------------------\n";
                    ofstream s;
                    s.open("score.txt",ios::app|ios::binary);
                    s<<"Inning "<< k <<" Ended!!!!\n";
                    s<<tname[0]<<" VS "<<tname[2]<<endl;
                    if(k==1)
                    {
                        s<<tname[0];

                    }
                    else{
                      s<<tname[1];

                    }
                    s<<"Total score in "<<j <<" balls is "<<i<<" with loss of "<<w<<" Wickets";
                    s.close();
                    if(k==2)
                    {
                        cout<<"\n\n___________________________________________________________________";
                        cout<<"\nMatch Ended!!!!!!\n\n";
                        cout<<tname[0]<<" score:"<<temp<<endl<< tname[1]<<" score:"<<i<<endl<<endl;
                        if(temp>i){cout<<tname[0]<<" won the match!!!!!!";}
                        else{cout<<tname[1]<<" won the match!!!!!!";}
                        cout<<"\n___________________________________________________________________";
                        cout<<"\n\nThanks for using this software!!!!!!!!!\n\n\n\n";
                        exit(0);
                    }
                    else{temp=i;
                        scoring();}
                        }
                        case 10:{cout<<"\nIPL scoring system interrupted!!!!!!!\n";
                            exit(0);};
                    default:{cout<<"Enter valid run\n";
                    break;
                    }
    }
    }
}
//Writing team details
void team::teamdetails()
{
fflush(stdin);
    cout<<"\nTeam name:"; cin.getline(teamname,30);
    cout<<"Team Id:"; cin.getline(teamid,5);
    cout<<"City:"; cin.getline(city,20);
    cout<<"Captain:"; cin.getline(captain,20);
    cout<<"Owner:"; cin.getline(owner,20);
    cout<<"Coach:"; cin.getline(coach,20);
    cout<<"\n";
}
//display team details
void team::showdetails()
{fflush(stdin);
      cout<<endl;
      cout<<"Name    :"<<teamname<<endl;
      cout<<"Team Id :"<<teamid<<endl;
      cout<<"City    :"<<city<<endl;
      cout<<"Captain :"<<captain<<endl;
      cout<<"Owner   :"<<owner<<endl;
      cout<<"Coach   :"<<coach<<endl<<endl;
}
//searching
void team::searchdetails(char *t)
{
    int counter=0;
    ifstream f;
    f.open("team.txt",ios::in|ios::binary);
    if(!f)
        cout<<"File not found\n";
    else{
    f.read((char*)this,sizeof(*this));
    while(!f.eof()){
    if(!stricmp(t,teamid)){
        showdetails();
        counter++;
    }
        f.read((char*)this,sizeof(*this));
    }
    if(counter==0)
        cout<<"Record not found";
}
f.close();
cout<<"press any key for MAIN MENU";
getch();
}
//deleting team details
void team::deletedetails(char *t)
{
    fflush(stdin);
    ifstream din;
    ofstream dout;
    din.open("team.txt",ios::in|ios::binary);
    if(!din){cout<<"File does not exist\n";}
    else{
            //getch();
        dout.open("temp.txt",ios::out|ios::binary);
        din.read((char*)this,sizeof(*this));
    while(!din.eof()){
        if(stricmp(teamid,t))
            dout.write((char*)this,sizeof(*this));
            din.read((char*)this,sizeof(*this));
    }
    din.close();
    dout.close();
    //getch();
    remove("team.txt");
    //getch();
    rename("temp.txt","team.txt");
}}
//updating team details
void team::updatedetails(char *t)
{
    fstream upd;
    upd.open("team.txt",ios::in|ios::ate|ios::app|ios::binary);
    if(!upd)
        cout<<"File not found\n";
        else{upd.seekg(0);
            upd.read((char*)this,sizeof(*this));
            while(!upd.eof())
            {
                if(!stricmp(t,teamid))
                {
                    teamdetails();
                 upd.seekp(upd.tellg()-sizeof(*this));
                    upd.write((char*)this,sizeof(*this));
                 }
                  upd.read((char*)this,sizeof(*this));
            }
    }
upd.close();
}
//Read team details
void team::readdetails()
{   int m=0;
    ifstream t1;
    t1.open("team.txt",ios::in|ios::binary);
    t1.seekg(0);
    if(!t1)
    {
        cout<<"\nFile not found\n";
    }
    else{
    t1.read((char *)this,sizeof(*this));
    while(!t1.eof())
      {
        cout<<"    Team "<<++m;
        cout<<endl<<"--------------";
        showdetails();
        t1.read((char *)this,sizeof(*this));
        }
    t1.close();
    }}
    //input team players name
void team::wplayerlist(){
    cin.ignore();
        cout<<"Team name:";cin.getline(teamname,30);
        cout<<"Team ID :";cin.getline(teamid,5);
        int m,n;
        cout<<"Enter no. of players to add:";
        cin>>m;
    for(int i=0;i<m;i++){
            cout<<i+1<<".";
cin.ignore();
    cin.getline(player[i],30);
    //cout<<"Enter specialisation :";
    cout<<"select specialisation :"<<endl;
    cout<<"1.Batsman"<<endl;
    cout<<"2.Bowler"<<endl;
    cout<<"3.All rounder"<<endl;
    cin>>n;
    switch(n){
    case 1:{
        strcpy(ptype,"Batsman");
        cout<<ptype<<endl;
        break;}
    case 2:{strcpy(ptype,"Bowler");
    cout<<ptype<<endl;
    break;}
    case 3:{strcpy(ptype,"All rounder");
    cout<<ptype<<endl;
    break;}
    default:{cout<<"select valid option!!!!!";break;}
    }
    cout<<"Total matches    :";cin>>tmatch[i];
    cout<<"Total Runs       :";cin>>trun[i];
    cout<<"Total wickets    :";cin>>twicket[i];
    cout<<"Total catches    :";cin>>tcatch[i];
}
}
//writing team player list
void team::writeplist()
{
        ofstream pl;
        pl.open("players.txt",ios::app|ios::binary);
        fflush(stdin);
        //for(int j=0;j<1;j++)
        //{
            //cout<<"Team name:";
            //cin.getline(teamname,30);
        //cout<<i+1<<".";
        wplayerlist();//}
        pl.write((char *)this,sizeof(*this));
        pl.close();
}
//display team players
void team::rplayerlist()
{
    cout<<"Team:"<<teamname<<" ["<<teamid<<"]"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for(int i=0;i<2;i++)
    {
        cout<<i+1<<"."<<player[i]<<endl;
        cout<<"-----------------------------\n";
        cout<<"Specialisation  :"<<ptype<<endl;
        cout<<"Total matches   :"<<tmatch[i]<<endl;
        cout<<"Total Runs      :"<<trun[i]<<endl;
        cout<<"Total wickets   :"<<twicket[i]<<endl;
        cout<<"Total catches   :"<<tcatch[i]<<endl<<endl;
    }
    //while(!*this);
}
//read team players list from file
void team::readplist()
{
fflush(stdin);
char t[5];
        int counter=0;
        cout<<"      IPL PLAYERS LIST(Team wise)";
        cout<<"\n****************************************\n";
    ifstream rp;
    rp.open("players.txt",ios::in|ios::binary);
    if(!rp)
        cout<<"File not found\n";
    else{
            cout<<"Enter Team ID to search:";cin.getline(t,5);
    rp.read((char*)this,sizeof(*this));
    while(!rp.eof()){
    if(!stricmp(t,teamid)){

      rplayerlist();
        counter++;
    }
        rp.read((char*)this,sizeof(*this));
    }
    if(counter==0)
        cout<<"Record not found";
}
rp.close();
cout<<"press any key for MAIN MENU";
    }
//Generating full match schedule
void team::timedate(){

      team s;
     cout<<"Enter Date"<<endl;
     cout<<"Date:";
        cin>>d;
        cout<<"Month:";
        cin>>m;
        cout<<"Year:";
        cin>>y;
        if(d>31 || m>12 || 2050<y || y<2018)
        {
            cout<<"Enter valid date"<<endl;
            s.timedate();
        }
        cout<<"Enter time\n";
        cout<<"Hrs:";
        cin>>h;
         cout<<"Min:";
        cin>>mi;
        if(mi>59 || h>23)
        {cout<<"Enter valid time!!!!";
        s.timedate();
        }
    }
void team::rtimedate()
    {
        cout<<d<<"/"<<m<<"/"<<y<<"       ";
        cout<<h<<":"<<mi<<"      ";
    }
void team::wschedule()
{
    //cin.ignore();
     ofstream wsc;
wsc.open("schedule.txt",ios::app|ios::binary);
    cout<<"    IPL schedule"<<"\n ********************\n";
int i=0;
char p;
    //for(int i=0;i<2;i++){
    do{
     cout<<"Match "<<++i<<endl;
       timedate();
       cin.ignore();
       cout<<"Enter Team 1 name\n";
    cin.getline(tname[0],30);
    cout<<"Enter Team 2 name\n";
    cin.getline(tname[1],30);
    cout<<"Enter Stadium name:";
    cin.getline(stadium,30);
    cout<<endl;
    wsc.write((char *)this,sizeof(*this));
    cout<<"Enter 'y' to add more:";
    cin>>p;}
    while(p=='y');


wsc.close();
cout<<"\nWritten successfully!!!!!";
    getch();
}
int temp1=0;
void team::showschedule()
{

    cout<<++temp1<<".       |"<<setw(5)<<tname[0]<<"  vs"<<setw(5)<<tname[1]<<"  |"<<setw(4)<<d<<"/"<<setw(2)<<m<<"/"<<setw(4)<<y<<"  |"<<setw(5)<<h<<":"<<setw(2)<<mi<<"   | "<<setw(15)<<stadium<<setw(18)<<"|"<<endl;

    cout<<"----------------------------------------------------------------------------------------"<<endl;
}
void team::rschedule()
{
    ifstream rsc;
       cout<<"\n\n\t\t\t\t\t\tIPL 2019 Schedule";
    cout<<"\n\t\t\t\t\t*****************************"<<endl;
    cout<<"_______________________________________________________________________________________"<<endl;
    cout<<"|"<<"Match"<<"   |"<<setw(14)<<"Teams "<<"  |"<<setw(12)<<"Date"<<"  |"<<setw(8)<<"time"<<"   |"<<setw(15)<<"Place"<<setw(19)<<"  |"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    rsc.open("schedule.txt",ios::in|ios::binary);
    if(!rsc)
        cout<<"File not found!!!!";
    else{
    rsc.read((char *)this,sizeof(*this));
    while(!rsc.eof())
    {
        showschedule();
        rsc.read((char *)this,sizeof(*this));
    }
    }
    rsc.close();
    getch();
}

int main()
{
    team t,p;
    team h,score;
    int n;
    while(1){

    system("CLS");
    cout<<"\t\t\t\t\tIPL Cricket Tournament Organizer"<<endl;
    cout<<"\t\t\t\t\t*************************************\n";
    cout<<"\t\t\t\t\t1. Write team details"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t\t2. Read team details"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t\t3. Search team details"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t\t4. Delete team details"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t\t5. update team details"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t\t6. Write players list"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t\t7. Display players list"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t\t8. Write Match schedule"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t\t9. Display Match schedule"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t\t10. IPL Scoring System "<<endl;
    cout<<"\t\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t\t11.Exit"<<endl;
    cout<<"\t\t\t\t\t*************************************\n";
    cout<<"\t\t\t\t\tEnter your choice:";cin>>n;
    cout<<"\t\t\t\t\t_____________________________________"<<endl;

    switch(n){
    case 1:{
        cout<<"Enter the no. of team to add:";
       int m;
       cin>>m;
    ofstream T;
    T.open("team.txt",ios::app|ios::binary);
    for(int i=0;i<m;i++)
    {
        cout<<"\nEnter team "<<(i+1)<<" details:"<<endl;
        t.teamdetails();
        T.write((char *)&t,sizeof(t));
    }
    T.close();
    cout<<"press any key for MAIN MENU";
    getch();}
    break;
    case 2:{cin.ignore();
        p.readdetails();
    cout<<"press any key for MAIN MENU";
    getch();}
    break;

    case 3:{
            fflush(stdin);
            char t[30];
            cout<<"Enter team name to search:";
            cin.getline(t,20);
            p.searchdetails(t);

        }
        break;
        case 4:{
            cout<<"      IPL Teams"<<endl;
            cout<<"----------------------"<<endl;
            p.readdetails();
            char t[5];
            cout<<"Enter team Id to delete:";
            fflush(stdin);
            cin.getline(t,5);
            p.deletedetails(t);
            cout<<"After deletion"<<endl;
            p.readdetails();
            cout<<"Press any key for MAIN MENU";
    getch();
        }
        break;
        case 5:{
            cin.ignore();
             cout<<"      IPL Teams"<<endl;
            //cout<<"----------------------"<<endl;
            h.readdetails();
            char t[5];
            cout<<"Enter team Id to update:";
            cin.getline(t,5);
            h.updatedetails(t);
              cout<<"After updation"<<endl;
            h.readdetails();
            cout<<"Press any key for MAIN MENU";
            getch();
        }
        break;
        case 6:{
            cin.ignore();
            h.writeplist();
            cout<<"Written successfully!!!!!!!!!!";
            getch();
            }
            break;
        case 7:{
            cin.ignore();
            h.readplist();
            getch();
            }
            break;

        case 8:{cin.ignore();
        h.wschedule();
        }
        break;
        case 9:{cin.ignore();
        h.rschedule();
        }
        break;
        case 10:{cin.ignore();

            cout<<"Enter the team names:";
            cin.getline(score.tname[0],30);
    cin.getline(score.tname[1],30);
            score.scoring();
        }
    case 11:
        {cout<<"\n\n\t\t\t\t\t\t\t\tThank You"<<endl;
cout<<"\t\t\t\t\t\t***********************************\n\n";
            exit(0);}
    break;
    default:
        cout<<"Enter valid number";
    }
    }
}
