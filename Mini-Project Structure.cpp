
    #include <iostream>
    #include <string>
    #include <limits>
    #include <windows.h>
    using namespace std;

    struct General_Information{
        private:
            string name;
            string from , to;
            long int ID ;
        public:
            void setName( string );
            void setFrom( string );
            void setTo( string );
            void setID( long int );

            string getName();
            string getFrom();
            string getTo();
            long int getID();

            void showInfo();
            void form();
    };

    void General_Information::setName( string value ) { name = value; }
    void General_Information::setFrom( string value ) { from = value; }
    void General_Information::setTo( string value ) { to = value; }
    void General_Information::setID( long int value ) { ID = value; }

    string General_Information::getName() { return name; }
    string General_Information::getFrom() { return from; }
    string General_Information::getTo() { return to; }
    long int General_Information::getID(){ return ID ;}

    void General_Information::showInfo(){
        cout << endl << " Name : " << name << ", with ID : " << ID
             << endl << " From : " << from << " -> " << to ;
    }

    void General_Information::form(){
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\t Enter name : " ;
        getline(cin , name );
        cout << "\t Enter from : " ;
        getline(cin , from );
        cout << "\t Enter to : " ;
        getline(cin , to );
        cout << "\t Enter ID : ";
        cin >> ID;
    }

    struct Airplane{
        private:
            string airline ;
            string seat ;
            long double price ;
            bool existance = false ;

        public:
            General_Information info ;

            void setAirline( string );
            void setSeat( string );
            void setPrice( long double );
            void setExistance( bool );

            string getAirline();
            string getSeat();
            long double getPrice();
            bool getExistance();

            void makeProfile();
            void editProfile();
            void removeProfile();

            void showInfo();
            void form();
    };

    void Airplane::setAirline( string value ) { airline = value ;}
    void Airplane::setSeat( string value) { seat = value ;}
    void Airplane::setPrice( long double value ) { price = value ;}
    void Airplane::setExistance( bool value ) { existance = value ;}

    string Airplane::getAirline() { return airline;}
    string Airplane::getSeat() { return seat;}
    long double Airplane::getPrice() { return price;}
    bool Airplane::getExistance(){ return existance;}

    void Airplane::showInfo(){
        info.showInfo();
        cout << endl << "Airplane : " << airline << " , seat-" << seat
             << endl << "Price : " << price;
    }

    void Airplane::form(){
        info.form();
        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        cout << "\t Enter airline : " ;
        getline(cin , airline);
        cout << "\t Enter seat : " ;
        getline(cin , seat );
        cout << "\t Enter price : " ;
        cin >> price;
    }

    void Airplane::makeProfile(){
        if( !existance ){
            form();
            existance = true ;
        }
    }

    void Airplane::editProfile(){
        if( existance )
            form();
    }

    void Airplane::removeProfile(){
        if( existance )
            existance = false;
    }


    int mainMenu();
    int ticketsMenu();

    int findFreeSpaceInList( Airplane [], int Size );
    int findTicketByID( Airplane [] , int Size , long int id );

    int main(){

        const int list_size = 20 ;
        Airplane plane[list_size];
        int index ;
        bool flag = true ;
        while ( flag ){
            system("cls");
            switch( mainMenu()){
                case 1 : {
                    switch( ticketsMenu() ){
                        case 1 : { // ADD
                            index = findFreeSpaceInList( plane , list_size );
                            if ( index >= 0 )
                                plane[index].makeProfile();
                        }break;

                        case 2 : { // EDIT
                            long int search_id ;
                            cout << " \t Enter search ID :";
                            cin >> search_id ;
                            index = findTicketByID( plane , list_size , search_id );
                            if( index >=0  )
                                plane[index].editProfile();
                        }break;

                        case 3 : { // REMOVE
                            long int search_id ;
                            cout << " \t Enter search ID :";
                            cin >> search_id ;
                            index = findTicketByID( plane , list_size , search_id );
                            if( index >=0  )
                                plane[index].removeProfile();
                        }break;
                    }
                }break;

                case 2 : {
                    long int search_id ;
                    cout << " \t Enter search ID :";
                    cin >> search_id ;
                    index = findTicketByID( plane , list_size , search_id );
                    if( index >=0  )
                        plane[index].showInfo();
                }break;

                case 3 : {
                    for ( int i=0 ; i < list_size ; i++ )
                        if( plane[i].getExistance() )
                            plane[i].showInfo();
                }break;

                case 4 : {
                  //exit(1);
                  flag = false ;
                }break;

                default :
                    cout << endl << "\t  Wrong Entry ! " ;
            }
            Sleep(5000);
        }
    return 0;
    }

    int mainMenu(){
        int choice ;
        cout << endl << "1.\tAirplane Ticket."
             << endl << "2.\tFind Ticket."
             << endl << "3.\tShow All Ticket."
             << endl << "4.\tExit Program."
             << endl << "    please Choose : ";
        cin >> choice ;
        //
        return choice ;
    }

    int ticketsMenu(){
        int choice ;
        cout << endl << "1.\tAdd Ticket."
             << endl << "2.\tEdit Ticket."
             << endl << "3.\tRemove Ticket."
             << endl << "    Please choose : ";
        cin >> choice ;
        return choice ;
    }

    int findFreeSpaceInList( Airplane arr[] , int Size ){

        for ( int i=0 ; i < Size ; i++ )
            if( !arr[i].getExistance() )
                return i ;
        return -1 ;
    }

    int findTicketByID( Airplane arr[] , int Size , long int id ){
        for( int i=0 ; i < Size ; i++ )
            if( arr[i].info.getID() == id && arr[i].getExistance() )
                return i ;
        return -1 ;
    }
