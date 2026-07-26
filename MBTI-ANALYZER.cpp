#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include "uz.h" 
#include<algorithm>
#include <cctype>  
using namespace std;
class MBTI;
int main();
class MBTI {
public:
    string type;
    string name;
    string username;
    string password;
    int introversion;
    int extroversion;
    int sensing;
    int feeling;
    int judging;
    int perceiving;
    int intuition;
    int thinking;
    bool authenticated =false;
    MBTI(){
         cout<<"\n";
    }
    MBTI(int it, int ex, int ie, int se, int th, int fe, int ju, int per) 
        : introversion(it), extroversion(ex), intuition(ie), sensing(se), 
          thinking(th), feeling(fe), judging(ju), perceiving(per) {}
    MBTI(string u, string p): username(u), password(p){
    ifstream infile("userdata.txt");
    string fileUser, filePass;

    if (!infile) {
        cerr << "Error: Cannot open users file.\n";
        return;
    }
    while(infile >> fileUser >> filePass) {
        if (username == fileUser && password == filePass) {
            authenticated = true;
            break;
        }
    }
    infile.close();
    if (authenticated) {
         cout<<"\n";
        cout << "Login successful. Welcome, " << username << "!\n";
        cout<<"Please enter Your MBTI: \n";
        getline(cin,type);
        transform(type.begin(),type.end(),type.begin(), ::toupper);
        cout<<"Youre type is: "<<type<<endl;
    } else {
        cout<<"\n";
        cout << " Login failed. Invalid credentials.\n Redirecting to Main\n";
        main();
    }
    }
    void login(string n){
         cout<<"\n";
        cout<<"Welcome! (NOTE: As a guest user, the personality-enhancing games are out of your scope! Feel free to Sign Up!)"<<endl;
        if(!authenticated){
            int su;
            cout<<"Want to Sign Up Instead? \n 1.Yes, 2.No \n";
            cin>>su;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(su==1){
                MBTI m;
                m.signUp();
            } else{
                cout<<"Continuing as a guest. \n";
                MBTI guest;
                guest.gameMenu();
            }
        }
    }
    void allocate(const string &type) {
         cout<<"\n";
        introversion = 50; extroversion = 50;
        sensing = 50; intuition = 50;
        thinking = 50; feeling = 50;
        judging = 50; perceiving = 50;

        if (type == "INFJ") {
            introversion = 80; extroversion = 20;
            intuition = 80; sensing = 20;
            thinking = 80; feeling = 20;
            judging = 80; perceiving = 20;
        } else if (type == "ESFP") {
            introversion = 20; extroversion = 80;
            sensing = 80; intuition = 20;
            feeling = 80; thinking = 20;
            perceiving = 80; judging = 20;
        }else if (type == "INTJ") {
        introversion = 80; extroversion = 20;
        intuition = 80; sensing = 20;
        thinking = 80; feeling = 20;
        judging = 80; perceiving = 20;
    } else if (type == "ENTP") {
        introversion = 20; extroversion = 80;
        intuition = 80; sensing = 20;
        thinking = 80; feeling = 20;
        perceiving = 80; judging = 20;
    } else if (type == "ISFJ") {
        introversion = 80; extroversion = 20;
        sensing = 80; intuition = 20;
        feeling = 80; thinking = 20;
        judging = 80; perceiving = 20;
    } else if (type == "ESTJ") {
        introversion = 20; extroversion = 80;
        sensing = 80; intuition = 20;
        thinking = 80; feeling = 20;
        judging = 80; perceiving = 20;
    } else if (type == "INFP") {
        introversion = 80; extroversion = 20;
        intuition = 80; sensing = 20;
        feeling = 80; thinking = 20;
        perceiving = 80; judging = 20;
    } else if (type == "ENFJ") {
        introversion = 20; extroversion = 80;
        intuition = 80; sensing = 20;
        feeling = 80; thinking = 20;
        judging = 80; perceiving = 20;
    } else if (type == "ISTP") {
        introversion = 80; extroversion = 20;
        sensing = 80; intuition = 20;
        thinking = 80; feeling = 20;
        perceiving = 80; judging = 20;
    } else if (type == "ESTP") {
        introversion = 20; extroversion = 80;
        sensing = 80; intuition = 20;
        thinking = 80; feeling = 20;
        perceiving = 80; judging = 20;
    } else if (type == "ISFP") {
        introversion = 80; extroversion = 20;
        sensing = 80; intuition = 20;
        feeling = 80; thinking = 20;
        perceiving = 80; judging = 20;
    } else if (type == "ESFJ") {
        introversion = 20; extroversion = 80;
        sensing = 80; intuition = 20;
        feeling = 80; thinking = 20;
        judging = 80; perceiving = 20;
    } else if (type == "INTP") {
        introversion = 80; extroversion = 20;
        intuition = 80; sensing = 20;
        thinking = 80; feeling = 20;
        perceiving = 80; judging = 20;
    } else if (type == "ENTJ") {
        introversion = 20; extroversion = 80;
        intuition = 80; sensing = 20;
        thinking = 80; feeling = 20;
        judging = 80; perceiving = 20;
    }else if (type == "ENFP") {
    introversion = 20; extroversion = 80;
    intuition = 80; sensing = 20;
    feeling = 80; thinking = 20;
    perceiving = 80; judging = 20;
} else if (type == "ISTJ") {
    introversion = 80; extroversion = 20;
    sensing = 80; intuition = 20;
    thinking = 80; feeling = 20;
    judging = 80; perceiving = 20;
} else {
            cout<<"\n";
            std::cout << "Unrecognized MBTI type. Setting defaults.\n";
            cout<<"Continue to menu or exit?";
            string k;
            cin>>k;
            if(k=="exit" || k=="Exit"){
                exit(0);
            } else{
                main();
                cout<<endl;
            }
        }
    }

    void display() const {
        std::cout << "Introversion: " << introversion << "\n";
        std::cout << "Extroversion: " << extroversion << "\n";
        std::cout << "Sensing: " << sensing << "\n";
        std::cout << "Intuition: " << intuition << "\n";
        std::cout << "Thinking: " << thinking << "\n";
        std::cout << "Feeling: " << feeling << "\n";
        std::cout << "Judging: " << judging << "\n";
        std::cout << "Perceiving: " << perceiving << "\n";
    }
    void redirectToPersonality(const string& type);
    void signUp(){
        User u;
        MBTI m;
        u.signUp();
        int b;
        string a;
        cout<<endl;
        cout<<"Please Enter Your MBTI: ";
        cin>>a;
        transform(a.begin(), a.end(), a.begin(), ::toupper);
        type = a;
        m.allocate(a);
        cout<<endl;
        string q;
        cout<<username<<", would you like a peview of your MBTI statistics? \n";
        cin.ignore();
        getline(cin,q);
       transform(q.begin(), q.end(), q.begin(), ::tolower);
        if(q=="yes"){
            cout<<"Your MBTI statistics are: \n";
            m.display();
        }
        else{
            cout<<"Moving On! \n";
        }
        cout<<"Are You Ready to Explore Yourself through Games and Our Personality Insights?\n 1.yes \n 2.no \n";
            while (true) {
        cin >> b;
        if (cin.fail() || (b != 1 && b != 2)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter 1 for yes or 2 for no: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the rest of the input line
            break; // Valid input, exit loop
        }
    }
        if(b==1){
            authenticated=true;
            run();
        }
        if(b==2){
            int w;
            cout<<"Thank you for visiting! Want to Exit or Return to the Main Menu? \n 1. Exit 2.Main Menu \n";
            if(w==1){
            cout<<"Come back soon! Goodbye <3 \n";
            exit(0);
            }else{
            cout<<"Returning to Main: \n";
            main();
            }
        }
    }
    void stats();
    void run() {
    int choice;
    cout << username<<", Ready to master your personality?\n"
         << "P.S If You're a guest user, the personality-enhancing games are out of your scope!\n" 
         << "1. Determine your personality\n"
         << "2. Explore yourself\n";
    if (authenticated) {
        cout << "3. Enhance yourself (games)\n";
    }
    cout << "Enter choice: \n";
    cin >> choice;
 while (cin.fail() || (choice < 1 || (choice > 3 && authenticated))) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a valid choice (1";
        if (authenticated) {
            cout << ", 2, or 3";
        }
        cout << "): ";
        cin >> choice;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input       
    }
    cin.ignore();
        if (choice == 1) {
            quiz();
        } else if (choice == 2) {
            string pt;
            cout << "Please enter your personality type (e.g., ESFP):\n ";
        getline(cin,pt);
        transform(pt.begin(),pt.end(),pt.begin(), ::toupper);
            redirectToPersonality(pt);
        } else if (choice == 3) {
            gameMenu();
        } else {
            cout << "Invalid choice.\n";
        }
    }
    string quiz() {
        char answers[12];
        int E = 0, I = 0;
        int S = 0, N = 0;
        int T = 0, F = 0;
        int J = 0, P = 0;

        cout << "Answer each question with A or B:\n";

        for (int i = 0; i < 12; ++i) {
            cout << "\nQ" << i + 1 << ": ";
            switch (i) {
                case 0: cout << "At a party: A. Mingle with many | B. Stick with known\n"; break;
                case 1: cout << "Solve problems: A. Experience | B. Abstract\n"; break;
                case 2: cout << "Work style: A. Logical | B. Caring\n"; break;
                case 3: cout << "Comfort: A. Plan | B. Spontaneous\n"; break;
                case 4: cout << "Talk: A. Speak easily | B. Reflect\n"; break;
                case 5: cout << "Learn: A. Instructions | B. Theories\n"; break;
                case 6: cout << "Decide: A. Logic | B. Feelings\n"; break;
                case 7: cout << "Workspace: A. Organized | B. Casual\n"; break;
                case 8: cout << "Around people: A. Energized | B. Drained\n"; break;
                case 9: cout << "Info: A. Concrete | B. Symbolic\n"; break;
                case 10: cout << "Tough decisions: A. Sense | B. Emotion\n"; break;
                case 11: cout << "Lifestyle: A. Scheduled | B. Flexible\n"; break;
            }

            cin >> answers[i];
            answers[i] = toupper(answers[i]);

            if (answers[i] != 'A' && answers[i] != 'B') {
                cout << "Invalid input. Please enter A or B.\n";
                --i;
                continue;
            }

            switch (i) {
                case 0: case 4: case 8: answers[i] == 'A' ? E++ : I++; break;
                case 1: case 5: case 9: answers[i] == 'A' ? S++ : N++; break;
                case 2: case 6: case 10: answers[i] == 'A' ? T++ : F++; break;
                case 3: case 7: case 11: answers[i] == 'A' ? J++ : P++; break;
            }
        }
        type = "";
        type += (E >= I ? "E" : "I");
        type += (S >= N ? "S" : "N");
        type += (T >= F ? "T" : "F");
        type += (J >= P ? "J" : "P");

        cout << "\nYour MBTI type is: " << type << endl;
        if(authenticated){
            MBTI u;
            cout<<"The Statistics of Your Type are: \n ";
            u.allocate(type);
            u.display();
        }
        cout<<"Would you like to explore your personality? \n"; 
        string s;
        getline(cin,s);
        if(s =="Yes" || s == "yes"){
        redirectToPersonality(type);
        }
        else{
            MBTI m;
            m.run();
        }
        return type;
    }
    void gameMenu();
    void reloadstats();
    void sensingIntuitionGame();
    void introVSExtro();
    void feelVSthink();
    void judgeVSpercieve();
};

class ESFP : public MBTI {
private:
    string Answer;

public:

    ESFP() {
        this->type = "ESFP";
    }

    ESFP(string u, string p) : MBTI(u, p) {
        this->type = "ESFP";
    }
    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ISTJ - The Logistician\n";
        cout << "2. ISFJ - The Defender\n\n";
        cout << " Why?\n";
        cout << "ESFPs are playful and spontaneous, while ISTJs and ISFJs bring stability, loyalty, and thoughtful structure to the relationship.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Entertainer' (ESFP)!\n";
        cout << "You're energetic, outgoing, and love to live in the moment.\n\n";

        cout << " Recommended Careers for ESFP:\n";
        cout << "1. Event Planner\n";
        cout << "2. Actor or Performer\n";
        cout << "3. Fashion Stylist\n";
        cout << "4. Marketing Executive\n\n";

        cout << "Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 65%   [-------------------        ]\n";
        cout << "Creativity:      85%   [-----------------------    ]\n";
        cout << "Empathy:         90%   [---------------------------]\n";
        cout << "Leadership:      70%   [---------------------------]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ESTP : public MBTI {
private:
    string Answer;

public:
    ESTP() {
        this->type = "ESTP";
    }

    ESTP(string u, string p) : MBTI(u, p) {
        this->type = "ESTP";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ISFJ - The Defender\n";
        cout << "2. ISTJ - The Logistician\n\n";
        cout << " Why?\n";
        cout << "ESTPs thrive on excitement and action, and ISFJs/ISTJs offer a grounded, loyal support system that helps balance the ESTP's high energy.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Entrepreneur' (ESTP)!\n";
        cout << "You're energetic, bold, and love taking risks and living in the fast lane.\n\n";

        cout << " Recommended Careers for ESTP:\n";
        cout << "1. Sales Representative\n";
        cout << "2. Emergency Medical Technician (EMT)\n";
        cout << "3. Entrepreneur\n";
        cout << "4. Stockbroker\n\n";

        cout << " Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 75%   [---------------            ]\n";
        cout << "Creativity:      80%   [----------------           ]\n";
        cout << "Empathy:         60%   [------------               ]\n";
        cout << "Leadership:      85%   [--------------------       ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ESTJ : public MBTI {
private:
    string Answer;

public:
    ESTJ() {
        this->type = "ESTJ";
    }

    ESTJ(string u, string p) : MBTI(u, p) {
        this->type = "ESTJ";
    }

    void compatibility() {
        cout << "\n❤️ Most Compatible Personality Types:\n";
        cout << "1. ISFP - The Adventurer\n";
        cout << "2. INFP - The Mediator\n\n";
        cout << "🔍 Why?\n";
        cout << "ESTJs are structured and take-charge individuals who benefit from the flexible, values-driven nature of ISFPs and INFPs.\n\n";
    }

    void explore() {
        cout << "\n🏛️ Welcome, 'The Executive' (ESTJ)!\n";
        cout << "You're organized, dedicated, and a natural leader who values tradition and order.\n\n";

        cout << "💼 Recommended Careers for ESTJ:\n";
        cout << "1. Military Officer\n";
        cout << "2. Judge\n";
        cout << "3. Project Manager\n";
        cout << "4. School Administrator\n\n";

        cout << "📊 Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 90%   [------------------------=   ]\n";
        cout << "Creativity:      55%   [---------                   ]\n";
        cout << "Empathy:         65%   [------------                ]\n";
        cout << "Leadership:      95%   [--------------------------- ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ESFJ : public MBTI {
private:
    string Answer;

public:
    ESFJ() {
        this->type = "ESFJ";
    }

    ESFJ(string u, string p) : MBTI(u, p) {
        this->type = "ESFJ";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ISFP - The Adventurer\n";
        cout << "2. INFP - The Mediator\n\n";
        cout << " Why?\n";
        cout << "ESFJs are warm and caring, and they form strong emotional bonds with those who share their values but also bring a touch of creativity and individuality.\n\n";
    }
    void explore() {
        cout << "\n Welcome, 'The Consul' (ESFJ)!\n";
        cout << "You're caring, organized, and value harmony in your social circles.\n\n";

        cout << "💼 Recommended Careers for ESFJ:\n";
        cout << "1. Nurse\n";
        cout << "2. Teacher\n";
        cout << "3. Social Worker\n";
        cout << "4. Event Coordinator\n\n";

        cout << " Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 70%   [----------------           ]\n";
        cout << "Creativity:      60%   [------------               ]\n";
        cout << "Empathy:         95%   [---------------------------]\n";
        cout << "Leadership:      75%   [------------------         ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ENFP : public MBTI {
private:
    string Answer;

public:
    ENFP() {
        this->type = "ENFP";
    }

    ENFP(string u, string p) : MBTI(u, p) {
        this->type = "ENFP";
    }

    void compatibility() {
        cout << "\nMost Compatible Personality Types:\n";
        cout << "1. INFJ - The Advocate\n";
        cout << "2. INTJ - The Architect\n\n";
        cout << "🔍 Why?\n";
        cout << "ENFPs are dreamers and adventurers, and INFJs/INTJs offer grounded insight, depth, and strategic thinking that complements ENFPs' free-spirited nature.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Campaigner' (ENFP)!\n";
        cout << "You're enthusiastic, creative, and thrive on new ideas and people connections.\n\n";

        cout << "💼 Recommended Careers for ENFP:\n";
        cout << "1. Public Relations Specialist\n";
        cout << "2. Psychologist\n";
        cout << "3. Creative Director\n";
        cout << "4. Travel Writer\n\n";

        cout << "Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 75%   [---------------            ]\n";
        cout << "Creativity:      95%   [-------------------------- ]\n";
        cout << "Empathy:         85%   [--------------------       ]\n";
        cout << "Leadership:      70%   [----------------           ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ENTP : public MBTI {
private:
    string Answer;

public:
    ENTP() {
        this->type = "ENTP";
    }

    ENTP(string u, string p) : MBTI(u, p) {
        this->type = "ENTP";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. INFJ - The Advocate\n";
        cout << "2. INFP - The Mediator\n\n";
        cout << " Why?\n";
        cout << "ENTPs are intellectually curious and thrive on debate. INFJs and INFPs bring emotional depth and values-based guidance that balance the ENTP's spontaneity.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Debater' (ENTP)!\n";
        cout << "You're quick-witted, curious, and love exploring new ideas through debate and experimentation.\n\n";

        cout << " Recommended Careers for ENTP:\n";
        cout << "1. Lawyer\n";
        cout << "2. Entrepreneur\n";
        cout << "3. Advertising Executive\n";
        cout << "4. Innovation Strategist\n\n";

        cout << "📊 Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 90%   [------------------------   ]\n";
        cout << "Creativity:      95%   [---------------------------]\n";
        cout << "Empathy:         70%   [----------------           ]\n";
        cout << "Leadership:      80%   [----------------           ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ENFJ : public MBTI {
private:
    string Answer;

public:
    ENFJ() {
        this->type = "ENFJ";
    }

    ENFJ(string u, string p) : MBTI(u, p) {
        this->type = "ENFJ";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. INFP - The Mediator\n";
        cout << "2. ISFP - The Adventurer\n\n";
        cout << " Why?\n";
        cout << "ENFJs are empathetic leaders who inspire others. INFPs and ISFPs offer authenticity and emotional resonance that complement the ENFJ's drive.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Protagonist' (ENFJ)!\n";
        cout << "You're charismatic, inspiring, and passionate about helping others reach their potential.\n\n";

        cout << " Recommended Careers for ENFJ:\n";
        cout << "1. Teacher\n";
        cout << "2. Psychologist\n";
        cout << "3. Human Resources Manager\n";
        cout << "4. Motivational Speaker\n\n";

        cout << " Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 80%   [----------------           ]\n";
        cout << "Creativity:      85%   [--------------------       ]\n";
        cout << "Empathy:         95%   [---------------------------]\n";
        cout << "Leadership:      90%   [------------------------   ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ENTJ : public MBTI {
private:
    string Answer;

public:
    ENTJ() {
        this->type = "ENTJ";
    }

    ENTJ(string u, string p) : MBTI(u, p) {
        this->type = "ENTJ";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. INTP - The Logician\n";
        cout << "2. INFP - The Mediator\n\n";
        cout << " Why?\n";
        cout << "ENTJs are strategic leaders who value intellect and efficiency. INTPs challenge their thinking, while INFPs soften their assertiveness with empathy.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Commander' (ENTJ)!\n";
        cout << "You're decisive, strategic, and natural at taking charge in both professional and personal settings.\n\n";

        cout << "💼 Recommended Careers for ENTJ:\n";
        cout << "1. CEO or Executive\n";
        cout << "2. Management Consultant\n";
        cout << "3. Lawyer\n";
        cout << "4. Political Leader\n\n";

        cout << " Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 95%   [---------------------------]\n";
        cout << "Creativity:      80%   [-----------------          ]\n";
        cout << "Empathy:         60%   [-------------              ]\n";
        cout << "Leadership:      100%  [---------------------------]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ISFP : public MBTI {
private:
    string Answer;

public:
    ISFP() {
        this->type = "ISFP";
    }

    ISFP(string u, string p) : MBTI(u, p) {
        this->type = "ISFP";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ESFJ - The Consul\n";
        cout << "2. ESTJ - The Executive\n\n";
        cout << " Why?\n";
        cout << "ISFPs are gentle and sensitive, and they pair well with structured and caring types who help them grow.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Adventurer' (ISFP)!\n";
        cout << "You're quiet, artistic, and deeply in touch with your emotions and environment.\n\n";

        cout << "💼 Recommended Careers for ISFP:\n";
        cout << "1. Artist\n";
        cout << "2. Interior Designer\n";
        cout << "3. Chef\n";
        cout << "4. Physical Therapist\n\n";

        cout << "Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 60%   [------------               ]\n";
        cout << "Creativity:      95%   [---------------------------]\n";
        cout << "Empathy:         90%   [-------------------------- ]\n";
        cout << "Leadership:      50%   [----------                 ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ISTP : public MBTI {
private:
    string Answer;

public:
    ISTP() {
        this->type = "ISTP";
    }

    ISTP(string u, string p) : MBTI(u, p) {
        this->type = "ISTP";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ESFJ - The Consul\n";
        cout << "2. ENFJ - The Protagonist\n\n";
        cout << " Why?\n";
        cout << "ISTPs are logical and independent, complemented by emotional and sociable partners who bring out their softer side.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Virtuoso' (ISTP)!\n";
        cout << "You're practical, logical, and love solving hands-on problems with efficiency.\n\n";

        cout << "💼 Recommended Careers for ISTP:\n";
        cout << "1. Mechanic\n";
        cout << "2. Pilot\n";
        cout << "3. Software Engineer\n";
        cout << "4. Forensic Scientist\n\n";

        cout << " Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 90%   [-----------------------    ]\n";
        cout << "Creativity:      70%   [---------------            ]\n";
        cout << "Empathy:         55%   [---------------            ]\n";
        cout << "Leadership:      65%   [---------------            ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ISFJ : public MBTI {
private:
    string Answer;

public:
    ISFJ() {
        this->type = "ISFJ";
    }

    ISFJ(string u, string p) : MBTI(u, p) {
        this->type = "ISFJ";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ESFP - The Entertainer\n";
        cout << "2. ESTP - The Entrepreneur\n\n";
        cout << " Why?\n";
        cout << "ISFJs are nurturing and responsible, pairing well with spontaneous types who bring excitement into their lives.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Defender' (ISFJ)!\n";
        cout << "You're loyal, compassionate, and always ready to support those around you.\n\n";

        cout << " Recommended Careers for ISFJ:\n";
        cout << "1. Nurse\n";
        cout << "2. Librarian\n";
        cout << "3. Office Manager\n";
        cout << "4. Elementary School Teacher\n\n";

        cout << "Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 70%   [---------------            ]\n";
        cout << "Creativity:      60%   [---------------            ]\n";
        cout << "Empathy:         95%   [---------------------------]\n";
        cout << "Leadership:      65%   [---------------------------]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();

            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class ISTJ : public MBTI {
private:
    string Answer;

public:
    ISTJ() {
        this->type = "ISTJ";
    }

    ISTJ(string u, string p) : MBTI(u, p) {
        this->type = "ISTJ";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ESFP - The Entertainer\n";
        cout << "2. ESTP - The Entrepreneur\n\n";
        cout << " Why?\n";
        cout << "ISTJs are reliable and principled, and they appreciate the zest and spontaneity that extroverted sensing types bring.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Logistician' (ISTJ)!\n";
        cout << "You're dependable, detail-oriented, and take pride in your integrity.\n\n";

        cout << "💼 Recommended Careers for ISTJ:\n";
        cout << "1. Accountant\n";
        cout << "2. Auditor\n";
        cout << "3. Military Officer\n";
        cout << "4. Lawyer\n\n";

        cout << " Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 85%   [--------------------       ]\n";
        cout << "Creativity:      50%   [------------------         ]\n";
        cout << "Empathy:         65%   [-----------------------    ]\n";
        cout << "Leadership:      80%   [-----------------------    ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class INFJ : public MBTI {
private:
    string Answer;

public:
    INFJ() {
        this->type = "INFJ";
    }

    INFJ(string u, string p) : MBTI(u, p) {
        this->type = "INFJ";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ENFP - The Campaigner\n";
        cout << "2. ENTP - The Debater\n\n";
        cout << " Why?\n";
        cout << "INFJs are insightful and visionary, and they find balance with spontaneous and creative extroverts who share their idealism.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Advocate' (INFJ)!\n";
        cout << "You're idealistic, thoughtful, and driven by a deep sense of purpose.\n\n";

        cout << "💼 Recommended Careers for INFJ:\n";
        cout << "1. Counselor\n";
        cout << "2. Writer\n";
        cout << "3. Psychologist\n";
        cout << "4. Nonprofit Director\n\n";

        cout << "Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 85%   [----------------------     ]\n";
        cout << "Creativity:      90%   [------------------------   ]\n";
        cout << "Empathy:         100%  [---------------------------]\n";
        cout << "Leadership:      75%   [---------------            ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class INTJ : public MBTI {
private:
    string Answer;

public:
    INTJ() {
        this->type = "INTJ";
    }

    INTJ(string u, string p) : MBTI(u, p) {
        this->type = "INTJ";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ENFP - The Campaigner\n";
        cout << "2. ENTP - The Debater\n\n";
        cout << " Why?\n";
        cout << "INTJs are strategic thinkers who value competence. ENFPs and ENTPs bring energy, vision, and emotional intelligence that broaden INTJs' perspectives.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Architect' (INTJ)!\n";
        cout << "You're strategic, logical, and highly independent. You see the bigger picture and love solving complex problems.\n\n";

        cout << " Recommended Careers for INTJ:\n";
        cout << "1. Scientist\n";
        cout << "2. Software Architect\n";
        cout << "3. Engineer\n";
        cout << "4. Strategic Consultant\n\n";

        cout << " Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 95%   [---------------------------]\n";
        cout << "Creativity:      80%   [----------------           ]\n";
        cout << "Empathy:         60%   [----------------           ]\n";
        cout << "Leadership:      85%   [--------------------       ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class INFP : public MBTI {
private:
    string Answer;

public:
    INFP() {
        this->type = "INFP";
    }

    INFP(string u, string p) : MBTI(u, p) {
        this->type = "INFP";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ENFJ - The Protagonist\n";
        cout << "2. ENTJ - The Commander\n\n";
        cout << " Why?\n";
        cout << "INFPs are idealistic and authentic, pairing well with strong, visionary types who provide direction and leadership.\n\n";
    }

    void explore() {
        cout << "\n Welcome, 'The Mediator' (INFP)!\n";
        cout << "You're deeply introspective, idealistic, and guided by strong values and a sense of meaning.\n\n";

        cout << " Recommended Careers for INFP:\n";
        cout << "1. Writer or Poet\n";
        cout << "2. Therapist\n";
        cout << "3. Graphic Designer\n";
        cout << "4. Social Worker\n\n";

        cout << " Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 70%   [---------------------------]\n";
        cout << "Creativity:      95%   [---------------------------]\n";
        cout << "Empathy:         100%  [---------------------------]\n";
        cout << "Leadership:      60%   [-----------                ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
class INTP : public MBTI {
private:
    string Answer;

public:
    INTP() {
        this->type = "INTP";
    }

    INTP(string u, string p) : MBTI(u, p) {
        this->type = "INTP";
    }

    void compatibility() {
        cout << "\n Most Compatible Personality Types:\n";
        cout << "1. ENTJ - The Commander\n";
        cout << "2. ENFJ - The Protagonist\n\n";
        cout << " Why?\n";
        cout << "INTPs are analytical and curious. They benefit from structured, charismatic partners who can help them act on their ideas.\n\n";
    }

    void explore() {
        cout << "\nWelcome, 'The Logician' (INTP)!\n";
        cout << "You're a thinker, curious and analytical. You enjoy exploring abstract concepts and theories.\n\n";

        cout << "💼 Recommended Careers for INTP:\n";
        cout << "1. Philosopher\n";
        cout << "2. Computer Programmer\n";
        cout << "3. Data Scientist\n";
        cout << "4. Inventor\n\n";

        cout << " Fun Trait Score Breakdown:\n";
        cout << "Problem Solving: 95%   [---------------------------]\n";
        cout << "Creativity:      85%   [--------------------       ]\n";
        cout << "Empathy:         55%   [------------               ]\n";
        cout << "Leadership:      60%   [-------------              ]\n\n";

        cout << "Do you want to know your most compatible personality types? (yes/no): ";
        cin >> Answer;

        if (Answer == "yes" || Answer == "YES") {
            compatibility();
            int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
        } else {
            cout << "\nNo worries! You can always explore later.\n";
            run();
        }
    }
};
void MBTI::redirectToPersonality(const string& type) {
    if (type == "ESFP") {
        ESFP esfp;
        esfp.explore();
    } else if (type == "ISTJ") {
        ISTJ istj;
        istj.explore();
    } else if (type == "INFP") {
        INFJ infj; 
        infj.explore();
    } else if (type == "ENTJ") {
        ENTJ entj; 
        entj.explore();
    } else if (type == "ISFP") {
        ISFP isfp;
         isfp.explore();
    } else if (type == "ESTJ") {
        ESTJ estj; 
        estj.explore();
    } else if (type == "INTJ") {
        INTJ intj;
        intj.explore();
    } else if (type == "ESFJ") {
        ESFJ esfj;
        esfj.explore();
    } else if (type == "INTP") {
        INTP intp; 
        intp.explore();
    } else if (type== "ESTP") {
        ESTP estp; 
        estp.explore();
    } else if (type=="ISFJ") {
        ISFJ isfj; 
        isfj.explore();
    } else if (type == "ENFP") {
        ENFP enfp; 
        enfp.explore();
    } else if (type == "INFJ") {
        INFJ infj;
        infj.explore();
    } else if (type == "ENTP") {
         ENTP entp; 
         entp.explore();
    } else if (type == "ISTP") {
         ISTP istp;
         istp.explore();
    } else if (type == "ENFJ") {
         ENFJ enfj; 
         enfj.explore();
    } else {
        cout << "Sorry, we don't have details for personality type '" << type << "' yet.\n";
    }
};
class Stats{
    MBTI mbti;

public:
    void allocate(const std::string &type) {
        mbti.allocate(type);
    }
    void displayMBTI() const {
        mbti.display();
    }
};

void MBTI::gameMenu() {
    int gchoice;
    cout << "\nGame Mania! 🥈 \n Two categories : Challenge yourself with Free Fun Games! Or Sign Up or Log In to ";
    cout << "Choose a game: \n 1. Intuition & Sensing \n 2.Introversion VS Extroversion \n 3.Judging VS Percieving \n 4.Feeling VS Thinking \n"; 
    cin >> gchoice;
    switch (gchoice) {
        case 1:
              sensingIntuitionGame();
            break;
       case 2:
            introVSExtro();
            break;
        case 3: 
            judgeVSpercieve();
            break;
        case 4: 
        feelVSthink();
        default:
            cout << "Invalid choice.\n";
    }
}
// add the games; // do the same 3 day rule// and then add then copy this code but replace the word sensing for whatever is suitable:

void MBTI::sensingIntuitionGame(){
   cout << "\n🎮 Sensing vs Intuition: Visual Patterns vs Abstract Reasoning\n";
    cout << "Choose the day you're playing (1, 2 or 3): ";
    int day;
    cin >> day;
    while (day < 1 || day > 3) {
        cout << "Please enter a valid day (1, 2 or 3): ";
        cin >> day;
    }
    // Initialize s and i
    int s = 0;
    int i = 0;
    // Visual patterns for each day (text based)
    const char* visualPatterns[3][2] = {
        { "XXOXO", "O" },  // Day 1: Identify the odd character
        { "AABAA", "B" },  // Day 2: Identify the odd character
        { "11211", "2" }   // Day 3: Identify the odd character
        };
    // Abstract reasoning questions for each day
    struct AbstractQuestion {
        const char* question;
        const char* answer;
    };
    AbstractQuestion abstractQuestions[3] = {
        { "What is the next letter in the sequence: A, B, A, B, ...?", "A" },
        { "If R is to S as T is to __?", "U" },
        { "What comes next in the series: 2, 4, 8, 16, ...?", "32" }
    };
    // Visual pattern question
    cout << "\nDay " << day << " Visual Pattern question:\n";
    cout << "Here is a sequence of characters: " << visualPatterns[day - 1][0] << "\n";
    cout << "Which character is different? (Enter exactly): ";
    string answer;
    cin >> answer;
    if (answer == visualPatterns[day - 1][1]) {
        cout << "🌈 Great visual recognition! (Sensing)\n";
        s = 1;
    } else {
        cout << "👀 Try again. Focus on the sequence.\n";
    }
    // Abstract reasoning question
    cout << "\nNow, answer this abstract reasoning question:\n";
    cout << abstractQuestions[day - 1].question << "\n";
    cout << "Your answer: ";
    cin >> answer;
    if (answer == abstractQuestions[day - 1].answer) {
        cout << "✨ Excellent abstract thinking! (Intuition)\n";
        i = 1;
    } else {
        cout << "🤔 Think differently. Try to see the underlying pattern.\n";
    }
    cout << "\nThanks for playing Day " << day << " of Sensing vs Intuition!\n";

    if (day == 3 && s == 1 && i == 0) {  
        MBTI m;
        m.allocate(type);
        m.sensing = m.sensing +2;
        cout<<"Current stats are: ";
        m.display();

    }
    if (day == 3 && s == 0 && i == 1){
   
       MBTI m;
        m.allocate(type);
        m.intuition = m.intuition +2;
        cout<<"Current stats are: ";
        m.display();
    }
    if (day == 3 && s == 1 && i == 1){
     MBTI m;
        m.allocate(type);
        m.intuition = m.intuition +2;
        m.sensing+=2;
        cout<<"Current stats are: ";
        m.display();
    }
    int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
};
 void MBTI::introVSExtro() {
    cout << "\n Introvert vs Extrovert: Social Scenarios\n";
    cout << "Choose the day you're playing (1, 2 or 3): ";
    int day;
    cin >> day;
    while (day < 1 || day > 3) {
        cout << "Please enter a valid day (1, 2 or 3): ";
        cin >> day;
    }

    int introvert = 0;
    int extrovert = 0;

    string responses[3][2] = {
        {
            "You're at a big party. Do you:\n1) Stick with a small group or find a quiet corner\n2) Mingle with everyone and dance?",
            "You're invited to two events on the same night. Do you:\n1) Choose the quieter one with a close friend\n2) Pick the one with the most people?"
        },
        {
            "It's a weekend. Do you prefer:\n1) Reading or relaxing alone\n2) Going out and doing something social?",
            "In a group project, do you:\n1) Prefer to work on your own part quietly\n2) Take charge and keep everyone energized?"
        },
        {
            "When meeting someone new, do you:\n1) Wait for them to initiate conversation\n2) Introduce yourself confidently?",
            "You have free time. Do you:\n1) Recharge alone at home\n2) Call friends and make plans?"
        }
    };

    for (int i = 0; i < 2; ++i) {
        cout << "\n" << responses[day - 1][i] << "\nEnter 1 or 2: ";
        int choice;
        cin >> choice;
        while (choice != 1 && choice != 2) {
            cout << "Please enter 1 or 2: ";
            cin >> choice;
        }
        if (choice == 1) introvert++;
        else extrovert++;
    }

    if (introvert > extrovert) {
        cout << "\n🧘 You seem more Introverted — you enjoy depth, solitude, and reflection.\n";
    } else if (extrovert > introvert) {
        cout << "\n🎉 You seem more Extroverted — you thrive in connection, energy, and activity.\n";
    } else {
        cout << "\n⚖️ You show traits of both Introversion and Extroversion — balanced and flexible!\n";
    }

    cout << "\nThanks for playing Day " << day << " of Introvert vs Extrovert!\n";

    // ✅ On Day 3, apply stat updates in-memory using MBTI object
    if (day == 3) {
        MBTI m;
        m.allocate(type);
        if (introvert > extrovert) {
            m.introversion += 2;
        } else if (extrovert > introvert) {
            m.extroversion += 2;
        } else {
            m.introversion += 1;
            m.extroversion += 1;
        }
        cout << "Your updated stats are:\n";
        m.display();
    }
    int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
};
void MBTI::feelVSthink() {
    cout << "\n--- Logic Grid Puzzle Game: Thinking vs Feeling ---\n";
    cout << "Choose the day you're playing (1, 2 or 3): ";
    int day;
    cin >> day;
    while (day < 1 || day > 3) {
        cout << "Please enter a valid day (1, 2 or 3): ";
        cin >> day;
    }

    int f = 0;
    int t = 0;

    cout << "Clues:\n";
    cout << "1. Alice does not own the dog.\n";
    cout << "2. The person with the cat is Bob.\n";
    cout << "3. Charlie does not have a dog or bird.\n";
    cout << "Who owns the Dog, Cat, and Bird?\n";

    string people[3] = { "Alice", "Bob", "Charlie" };
    string pets[3] = { "Dog", "Cat", "Bird" };
    string solution_pets[3] = { "Bird", "Cat", "Dog" };
    string answer_pets[3];

    cin.ignore();

    for (int i = 0; i < 3; i++) {
        cout << "Who does " << people[i] << " own? (Dog/Cat/Bird): ";
        getline(cin, answer_pets[i]);

        transform(answer_pets[i].begin(), answer_pets[i].end(), answer_pets[i].begin(), ::tolower);
        if (!answer_pets[i].empty())
            answer_pets[i][0] = toupper(answer_pets[i][0]);

        bool valid = false;
        for (int j = 0; j < 3; j++) {
            if (answer_pets[i] == pets[j]) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << "Invalid pet name. Try again.\n";
            i--;
        }
    }

    bool correct = true;
    for (int i = 0; i < 3; i++) {
        if (answer_pets[i] != solution_pets[i]) {
            correct = false;
            break;
        }
    }

    if (correct) {
        cout << " Correct! You solved the puzzle.\n";
        t = 1;
    } else {
        cout << " Incorrect. Try again or review the clues.\n";
        f = 1;
    }

    if (day== 3 && t==f) {  
        MBTI m;
        m.allocate(type);
        m.feeling = m.feeling +2;
        m.thinking = m.thinking+2;
        cout<<"Current stats are: ";
        m.display();
    } if(day==3 && t>f){
         MBTI m;
        m.allocate(type);
        m.thinking = m.thinking+2;
        cout<<"Current stats are: ";
        m.display();
    }else{
         MBTI m;
        m.allocate(type);
        m.feeling = m.feeling +2;
        cout<<"Current stats are: ";
        m.display();
    }
    int p;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>p;
    if(p==1){
        main();
    }if(p==2){
        gameMenu();
    }else{
        exit(0);
    }
};
void MBTI::judgeVSpercieve() {
    cout << "\n--- Escape Room Logic Game: Judging vs Perceiving ---\n";
    cout << "Choose the day you're playing (1, 2 or 3): ";
    int day;
    cin >> day;
    while (day < 1 || day > 3) {
        cout << "Please enter a valid day (1, 2 or 3): ";
        cin >> day;
    }

    int j = 0, p = 0;
    bool allCorrect = true;

    cout << "You are locked in a room. Solve the puzzles to escape.\n";

    cout << "\nPuzzle 1: What number comes next in the series?\n";
    cout << "2, 6, 12, 20, 30, ?\n";
    int ans1;
    cin >> ans1;
    if (ans1 == 42) {
        cout << "Correct! You've unlocked the first lock.\n";
    } else {
        cout << "Incorrect. Hint: The numbers are of the form n*(n+1).\n";
        allCorrect = false;
    }
    if (allCorrect) {
        cout << "\nPuzzle 2: I speak without a mouth and hear without ears. What am I?\n";
        cin.ignore();
        string answer2;
        getline(cin, answer2);
        transform(answer2.begin(), answer2.end(), answer2.begin(), ::tolower);

        if (answer2.find("echo") != string::npos) {
            cout << "Well done! You solved the riddle.\n";
        } else {
            cout << "That's not correct. The answer was 'echo'.\n";
            allCorrect = false;
        }
    }
    if (allCorrect) {
        cout << "\nFinal Puzzle: Decode this number code:\n";
        cout << "8 5 12 12 15\n(Hint: A=1, B=2, ..., Z=26)\n";
        string answer3;
        getline(cin, answer3);
        transform(answer3.begin(), answer3.end(), answer3.begin(), ::tolower);

        if (answer3.find("hello") != string::npos) {
            cout << "Congratulations! You've escaped the room!\n";
        } else {
            cout << "Incorrect code. The correct code spells 'HELLO'.\n";
            allCorrect = false;
        }
    }
    if (day == 3) {
        MBTI m;
        m.allocate(type);
        if (allCorrect) {
            m.judging += 2;
        } else {
            m.perceiving += 2;
        cout << "Your updated stats are:\n";
        m.display();
        }
    }
    int o;
    cout<<"Choose What You'd like to do: \n 1.Return to main menu, \n 2. Game menu.\n 3.Exit\n";
    cin>>o;
    if(o==1){
        main();
    }if(o==2){
        gameMenu();
    }else{
        exit(0);
    }

};

int main(){
cout<<" Welcome to the Myers-Briggs 16 personality test program! \n This program was developed ny Alizay Kashif and Huda Jafri \n Enjoy! \n";
MBTI mbti;
int choice;
    cout << "Please choose an option to continue further: \n";
    cout << "1. Sign In\n2. Register\n3. Play as Guest\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    MBTI m1;
    cin.ignore(); 
    if (choice == 1) {
        cout<<"Please Enter Your Credentials To Further Proceed: \n";
        string username, password;
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);
        MBTI user(username, password);
        cout<<"\n";
        user.run();
         cout<<"\n";
    } else if (choice == 2) {
         cout<<"\n";
        mbti.signUp();
 cout<<"\n";
    } else if (choice == 3) {
        string name;
        cout << "Enter your name: \n";
        getline(cin, name);
         cout<<"\n";
        mbti.login(name);
         cout<<"\n";
        mbti.run();
    } else {
        cout << " Invalid choice. Exiting program.\n";
    }
    return 0;
}
