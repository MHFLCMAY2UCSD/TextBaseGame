//Michael Huang
//HW7.cpp
//CISP 360

#include<iostream>
#include<limits>
using namespace std;


void program_greeting();

int simple_menu();

void explain();

void cls();

string pre_name();

bool pre_sex();

bool ethnic();

bool street_creds();

void pause();

int exposition(string, bool, bool, bool);

int first_room(bool, bool);

int riots();

int desire_lawsuit();

int depression();

bool second_room(string);

bool third_room(bool, bool, bool);

int quiz_validation(int);

bool quiz_time();

void fourth_room(bool, bool, bool);

//Specification C1 - Five Rooms
int fifth_room(int);

//Specification A1 - Add more rooms
int sixth_room(int, string, bool, bool, bool);

void stats(int, string, bool, bool, bool, bool , int);

bool keep_playing();

class Player{   //TODO
private:
string name;
string sex;
string ethnicity;

public:
};

int main(){

	int tip;

	string you;
	bool sex;
	bool ethnicity;
	bool personality;
	bool wrong_turn;

	//Inventory
	bool substance = false;
	int money = 0;
	int final_key;
	int ending_result;

	bool game;

	//Introduction to this program.
	program_greeting();

	//Simple Menu.
	tip = 1;
	while(tip == 1){

		tip = simple_menu();

		if(tip == 1){
			explain();
		}
		else if(tip == 2){
			game = true;
			break;
		}
		else{
			game = false;
			break;
		}
	}


	//GameLoop
	while(game){

		int ice_breaker;

		//Pre-game

		you = pre_name();

		sex = pre_sex();

		ethnicity = ethnic();

		personality = street_creds();

		ice_breaker = exposition(you, sex, ethnicity, personality);

		wrong_turn = false;

		//Multiple-Path
        if(ice_breaker == 1){
            money = first_room(sex, ethnicity);

            pause();
        }
        else if(ice_breaker == 2){
            substance = second_room(you);

            pause();
        }
        else if(ice_breaker == 3){
            wrong_turn = third_room(sex, ethnicity, personality);

            pause();
        }

        ending_result = 1;
        if(wrong_turn == false){
                fourth_room(substance, ethnicity, personality);

                pause();

                final_key = fifth_room(money);

                pause();

                ending_result = sixth_room(final_key, you, sex, ethnicity, personality);

                pause();

        }

        if(ending_result == 0){
            cout<<"\nCongratulations.  Winner.  Winner.  Chicken Dinner!"<<endl;

            stats(final_key, you, sex, ethnicity, personality, substance, money);
        }
        else{
            cout<<"\n*You Lose*\n"<<endl;

            stats(final_key, you, sex, ethnicity, personality, substance, money);
        }

        game = keep_playing();

	}

	return 0;
}


void program_greeting(){
	cout<<"A Welcome Message"<<endl<<"Name: Michael Huang"<<endl<<
		"Date: July-29-2021"<<endl<<endl;

	cout<<"Disclaimer:  Job Interview is a satire, parody, commentary, and "
		<<"entertainment, which may or may not use actual names often "
		<<"in quasi-real and/or fictitious narration.  All narration "
		<<"in Job Interview is fiction hence constitute as fake."
		<<"  This media is only for entertainment purposes.\n"<<endl;
}


int simple_menu(){

	int options;

	cout<<"1. Explain"<<endl;
	cout<<"2. Play"<<endl;
	cout<<"3. Quit"<<endl;

	cin>>options;

	while(options < 1 || options > 3){
		cout<<"\nThis is not a valid input.  Please try agian.\n"<<endl;

		cin>>options;
	}

	return options;
}


void explain(){
	cout<<"\nTo play this game.  Enter the character you see associated "<<
		"to the options of your desire.  Have fun and good luck at "<<
		"getting to and accepted to your job interview.\n"<<endl;
}

void cls(){
	system("clear");  //TODO Change to 'clear' before turning it in.
}


//Specification C2 - Player Name
string pre_name(){

    cls();

	string name;

	cout<<"Tell me.  What is your first name?"<<endl;

	cin>>name;

	return name;
}


bool pre_sex(){

	cls();

	string sex_pre;

	cout<<"What is your gender?  Male/Female/Other"<<endl;

	cin>>sex_pre;

	sex_pre[0] = toupper(sex_pre[0]);

	cout<<sex_pre<<endl; //TODO

    //Specification C3 - Input Validation
	while(sex_pre[0] != 'M' && sex_pre[0] != 'F' && sex_pre[0] != 'O'){
		cout<<"This is not a valid input.  Please enter M/F/O."<<endl;

		cin>>sex_pre;

		sex_pre[0] = toupper(sex_pre[0]);
	}

	if(sex_pre[0] == 'M'){
		return true;
	}
	else{
		return false;
	}
}


bool ethnic(){

	cls();

	string race;

	cout<<"Please enter your ethnicity."<<endl;

	cin>>race;

	for(int i = 0; i < 6; ++i){
		race[i] = toupper(race[i]);
	}

	if(race == "WHITE"){
		return true;
	}
	else{
		return false;
	}
}


bool street_creds(){

	cls();

	string person;

	cout<<"What is your personality?  likable or not likable?"<<endl;

	cin>>person;

	person[0] = toupper(person[0]);

	while(person[0] != 'L' && person[0] != 'N'){
		cout<<"Please type the entire word(S).  likable or not "<<
			"likable"<<endl;

		cin>>person;

		person[0] = toupper(person[0]);
	}

	if(person[0] == 'L'){
		return true;
	}
	else{
		return false;
	}
}

void pause(){

    string words;

    cout<<"\nType Continue to continue\n"<<endl;

    cin>>words;

    for(int i = 0; i < 9; i++){
        words[i] = toupper(words[i]);
    }

    while(words != "CONTINUE"){
        cout<<"Please try again."<<endl;

        cin>>words;

        for(int i = 0; i < 9; i++){
            words[i] = toupper(words[i]);
        }
    }
}


int exposition(string n, bool s, bool e, bool p){

	cls();

	string gender;
	string m_or_m;
	string cool_not_cool;

	//Options
	char where;
	int map;

	//sex
	if(s == true){
		gender = "a Male.";
	}
	else{
		gender = "Not Male.";
	}

	//Majority of Minority
	if(e == true){
		m_or_m = "Majority";
	}
	else{
		m_or_m = "Minority";
	}

	//likable or Not likable
	if(p == true){
		cool_not_cool = "likable.";
	}
	else{
		cool_not_cool = "Not likable.";
	}


	cout<<"You are a know as "<<n<<".  "<<endl;
	cout<<"You are "<<gender<<endl;
	cout<<"You are also the "<<m_or_m<<" race."<<endl;
	cout<<"And you personally are "<<cool_not_cool<<endl;

	//Exposition
	cout<<"\nYou are in the heart of Hollywood.  You are trying to get to "
		<<"your job interview."<<endl;
	cout<<"Which route would you take?  (N, E, S, W)"<<endl<<endl;

	//Options
	cout<<"(N): You see in the distant there seem to be a man "<<endl;
	cout<<"looking back at you.  You cannot make out who it is."<<endl;

	cout<<"(E): In the distant you notice there is an alley which seems "<<endl;
	cout<<"	to be populated one strangers."<<endl;

	cout<<"(S): Over the horizon you seems to notice a person."<<endl;
	cout<<"	Look to be a law enforcer."<<endl;

	cout<<"(W): Over yonder you seems to notice a familiar face."<<endl;
	cout<<"	You don't know who it is but you think she is someone famous."<<endl;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cin>>where;  //Find out why it is set to 'L'.

	where = toupper(where);

	while(where != 'N' && where != 'E' && where != 'S' &&
		where != 'W'){
		cout<<"Please enter either (N/E/S/W)"<<endl;

		cin>>where;

		where = toupper(where);
	}

	//Logic gate for where
	if(where == 'N'){
		map = 1;
	}
	else if(where == 'E'){
		map = 2;
	}
	else if(where == 'S'){
		map = 3;
	}
	else{
		map = 4;
	}

	return map;
}


int first_room(bool gender, bool race){

    cls();

	string wants;

	int dinero;

    //Specification C4 - Abbreviated Room Description
	cout<<"North: Tax Collector\n"<<endl;

	cout<<"As you walk down this path, you bump into a sort of tax "<<
		"collector dress in a cheap vampire costume."<<endl<<
		"Vampire Tax Collector Man: 'I vant to suck your blood. "<<
		"Either through appraisement or you giving me money."<<
		"  I am Count Taxcula.  I thought this would be an easier way "<<
		"for people to know that their hopes and dreams are going "<<
		"to be suck right out of them."<<endl;

	cout<<"\nWhat will you do?\n"<<endl;

    //Specification B1 - Add more command options
	if(gender == false || race == false){
		cout<<"(Tweet): Tweet about his privileges and how he is "<<
			"using it to oppressed you who does not have the "<<
			"luxury of such privilege(s)"<<endl;
	}
	cout<<"1. I do not have money or anything worth appraising. (Kick him"<<
		" in the balls and rob him.)"<<endl;
	cout<<"2. (Enter into a philosophical discussion on the objective "<<
		"meaning of life and how it is meaningless."<<endl;

	cin>>wants;

	while(wants[0] != 'T' && wants[0] != 't' && wants[0] != '1' && wants[0] != '2'){
		cout<<"This is not a valid input.  Just type the words or "<<
			"letter(s)."<<endl;

		cin>>wants;
	}

	if(wants[0] == 'T' || wants[0] == 't'){
		dinero = riots();
	}
	else if(wants[0] == '1'){
		dinero = desire_lawsuit();
	}
	else{
		dinero = depression();
	}

	return dinero;
}


int riots(){

	int cha_ching;

	cout<<"\n*You have chosen the (Tweet) path."<<endl;
	cout<<"(You processed to use your gender or race or both to insight "<<
		"a riot from radical groups of either side.  They all swarm "<<
		"the Tax Collector.  On your way out you noticed he dropped "<<
		"his wallet.  (You convince yourself to take it))"<<endl;

	cout<<"\nYou went back from where you came from.\n"<<endl;

	cout<<"You gain 60 bucks"<<endl;

	cha_ching = 60;

	return cha_ching = 60;
}


int desire_lawsuit(){

	int cha_ching;

	cout<<"\n(You've grown tired of him demanding you to pay.  You "<<
		"decided to assault him then rob him.)"<<endl;
	cout<<"\nYou kicked him in the balls\n"<<endl;
	cout<<"Count Taxcula: *groan in pain* MY VAMPIRIC BALLS!!!\n"<<endl;
	cout<<"You quickly grabbed his wallet and ran.  You dropped some "<<
		"money along the way.\n"<<endl;
	cout<<"You went back from where you came from.\n"<<endl;

	cout<<"You gain 40 bucks"<<endl;

	cha_ching = 40;

	return cha_ching;
}


int depression(){

	int cha_ching;

	cout<<"\n(You asked Count Taxcula to sit down with you so you can talked about"<<
		" what he is doing is meaningless in the big picture."<<endl;

	cout<<"\nCount Taxcula: Wow, I never really thought about it like "<<
		"that.  I guess I am just too privileged to ascend to such "<<
		"a mind set."<<endl;
	cout<<"\nAfter that you walked back from where you came from as "<<
		"this was not the path to your job interview.)"<<endl;

	cha_ching = 0;

	return cha_ching;
}


bool second_room(string champ){

    cls();

    int hero;
    int ex_things;
    bool win;

    hero = 3;
    ex_things = 3;

    cout<<"East: Two Homeless man\n"<<endl;

    cout<<"You walk down this ally filled with trash and used needles.  Your senses heighten as you kept walking while looking for a way out.)"<<endl;
    cout<<"\nStranger: Hey you got some spare change and while you're here do you want to buy my course on 'AlgoPro' which is not a copy of 'AlgoExpert'?\n"<<endl;
    cout<<"(That startled you and you process to go into APE MODE and charged at the stranger.\n"<<endl;
    cout<<"Out of fear the Stranger who turns out to be an Ex-Google, Ex-FaceBook, Ex-Husband, and now Ex-Millionaire Patrick Shyu defense himself.)"<<endl;

    cout<<"\n"<<champ<<": "<<hero<<"/3"<<"  "<<"TechLead: "<<ex_things<<"/3"<<endl;

    //Specification B2 - Add combat
    while(hero > 0 && ex_things > 0){

        int attacks;

        cout<<"\nAttacks"<<endl<<"========"<<endl;
        cout<<"1. (Talk about how bad 'AlgoPro' is) (-1)"<<endl;
        cout<<"2. (Tell him he is a third rate person with a fourth rate Crypto) (-2)"<<endl;
        cout<<"3. (Start pounding your fragile chest like the APE you are) (Does nothing)"<<endl;

        cin>>attacks;

        while(attacks < 1 || attacks > 3){
            cout<<"Patrick saw your moment of weakness and hit you with the fact that he was a millionaire/ Google lead/ FaceBook employee/ husband/ and father"<<endl;
            cout<<"(-1)"<<endl;

            hero -= 1;

            cout<<"\nPlease try again.  Enter the values you see."<<endl;

            cin>>attacks;
        }

        if(attacks == 1){
            ex_things -= 1;
        }
        else if(attacks == 2){
            ex_things -= 2;
        }

        if(ex_things > 0){

                cout<<"(Patrick kept telling you about how great Crypto is: (-1))"<<endl;

                hero -= 1;
        }
        cout<<champ<<": "<<hero<<"/3"<<"  "<<"TechLead: "<<ex_things<<"/3"<<endl;
    }

    //Specification B3 - Add more monster
    if(hero < 1){
        cout<<"(You lost to Patrick.  You left with a heavy heart and a broken pride)"<<endl;

        win = false;
    }
    else if(ex_things < 1){
        cout<<"\n(You Defeated TechLead, but at what cost?"<<endl;
        cout<<"You saw on the ground a needle filled with a sort of substance.  You took it."<<endl;
        cout<<"Too bad you do not know what is inside since you never attended any D.A.R.E rallies back in school.)"<<endl;

        win = true;
    }
    return win;
}


bool third_room(bool gender, bool race, bool cool){

    cls();

    bool jail;

    cout<<"West: The Busy Streets of Hollywood\n"<<endl;

    cout<<"(As you are trying to find the building for your job interview, you bump into a Police Officer)"<<endl;
    cout<<"\nYou processed to greet the officer:  Good day officer."<<endl;

    if(gender == true && race == true){
        cout<<"\nOfficer:  Good day to you good sir.  Be careful, these streets are not safe for a fine gentleman like you.  You best move along."<<endl;

        jail = false;
    }
    else if(gender == false && race == true){
        cout<<"\nOfficer:  Good day to you good ma'am.  Be careful, these streets are not safe for a fine lady like you.  You best move along."<<endl;

        jail = false;
    }
    else{
        cout<<"\nOfficer:  Halt for one moment.  It is a new law of the city for me to test you on the anything if your refuse or fail "<<
            "it is straight to ADX Florence you go."<<endl;
        cout<<"\n(You cannot disagree or not comply as his right hand is tightly gripped onto the holster of his service weapon)"<<endl;

        jail = quiz_time();
    }

    return jail;
}


int quiz_validation(int values){

    int angry_meter;

    angry_meter = 0;
    while(values < 1 || values > 4 && angry_meter < 4){
        cout<<"\nOfficer:  Those weren't even the options?"<<endl;

        if(angry_meter < 3){
            cout<<"Try again: "<<endl;

            cin>>values;

            angry_meter += 1;
        }
        else{
            cout<<"Ok, we got a funny guy huh?  Guess what?  Straight to jail."<<endl;

            values = 6;

            angry_meter += 1;
        }
    }

    return values;

    }


bool quiz_time(){

    int question_one;
    int question_two;
    int question_three;
    int question_four;
    int question_five;

    cout<<"\nOkay, now the first question is: "<<endl<<"=============================="<<endl;
    cout<<"This should be easy.  What does the first amendment state?\n"<<endl;
    cout<<"1. Right to Free Speech"<<endl;
    cout<<"2. Right to bear arms"<<endl;
    cout<<"3. I am Tyler, the Creator.  Look. (Sings Earthquake)"<<endl;
    cout<<"4. I love my gun and American.  I will never leave my house or my pregnant girlfriend if I do not have a 1995 Ford F150."<<endl;

    cin>>question_one;

    question_one = quiz_validation(question_one);

    if(question_one == 6){
        cout<<"Officer: Bye\n"<<endl;

        return true;
    }

    cout<<"\nAlright, second question is: "<<endl<<"=============================="<<endl;
    cout<<"How many stars are on the American Flag?\n"<<endl;
    cout<<"1. Enough"<<endl;
    cout<<"2. 13"<<endl;
    cout<<"3. 50"<<endl;
    cout<<"4. Not Enough"<<endl;

    cin>>question_two;

    question_two = quiz_validation(question_two);

    if(question_two == 6){
        cout<<"Officer: Bye\n"<<endl;

        return true;
    }

    cout<<"\nAlright, third question is: "<<endl<<"=============================="<<endl;
    cout<<"Next one.  What does Al gore fear the most?\n"<<endl;
    cout<<"1. Climate Change"<<endl;
    cout<<"2. Man-Bear-Pig"<<endl;
    cout<<"3. Electoral College"<<endl;
    cout<<"4. George W. Bush"<<endl;

    cin>>question_three;

    question_three = quiz_validation(question_three);

    if(question_three == 6){
        cout<<"Officer: Bye\n"<<endl;

        return true;
    }

    cout<<"\nAlright, fourth question is: "<<endl<<"=============================="<<endl;
    cout<<"This is gonna get hard.  What happens if you get scared half to death twice?\n"<<endl;
    cout<<"1. You die"<<endl;
    cout<<"2. C'est la vie"<<endl;
    cout<<"3. Clutch in the gulag"<<endl;
    cout<<"4. Bro, just arrest me already."<<endl;

    cin>>question_four;

    question_four = quiz_validation(question_four);

    if(question_four == 6){
        cout<<"Officer: Bye\n"<<endl;

        return true;
    }

    cout<<"\nAlright, fifth question is: "<<endl<<"=============================="<<endl;
    cout<<"Aight, last one.  What do you think of me?\n"<<endl;
    cout<<"1. A Racist"<<endl;
    cout<<"2. An American"<<endl;
    cout<<"3. A bad cop"<<endl;
    cout<<"4. A friend to my people"<<endl;

    cin>>question_four;

    question_four = quiz_validation(question_four);

    if(question_four == 6){
        cout<<"Officer: Bye\n"<<endl;

        return true;
    }

    int result = 0;
    if(question_one == 1 || question_one == 4){
        result += 1;
    }

    if(question_two == 3){
        result += 1;
    }

    if(question_three == 2){
        result += 1;
    }

    if(question_four == 1){
        result += 1;
    }

    if(question_five == 2){
        result += 1;
    }

    if(result >= 3){

        cout<<"Ok, you are alright I guess.\n"<<endl;

        return false;
    }
    else{
        cout<<"GG, NO RE"<<endl;

        return true;
    }
}

void fourth_room(bool drugs, bool race, bool cool){

    cls();

    string fate;

    cout<<"\nWest: Downtown Hollywood, Demi Lavato\n"<<endl;

    cout<<"(After some walking around you encounter the one and only Demi Lavato.  Once she notice you she began to talk about how "<<
        "if she continued her path of destruction and substance abuse she would had ended up like DMX.)"<<endl;
    cout<<"Demi: If I didn't come clean, I would had ended up like DMX.  I am so thankful that wasn't me.  Like do you want to hear about "<<
        "my story?"<<endl;
    cout<<"\nWhat will you do?\n"<<endl;

    while(true){

        if(drugs == true){
            cout<<"(substances): Give her the substance and walk away.  You know she won't follow you when she is occupied."<<endl;
        }

        if(race == false){
            cout<<"(Threat): Threaten to make a tweet about how she is bashing another L.A small business."<<endl;
        }

        cout<<"1. Say Yes, you would like to hear her talk about herself more."<<endl;
        cout<<"2. Say No"<<endl;
        cout<<"3. Just run as fast as you can.  Run Forrest! Run!"<<endl;

        cin>>fate;

        while(fate[0] != 'S' && fate[0] != 's' && fate[0] != 'T' && fate[0] != 't' && fate[0] != '1' && fate[0] != '2' && fate[0] != '3'){
            cout<<"Invalid input, try agin."<<endl;

            cin>>fate;
        }

        if(fate[0] == 'S' || fate[0] == 's'){
            cout<<"\nDemi: Is that what I think it is?\n"<<endl;
            cout<<"(Demi started to act more like gollum from Lord of the Rings each seconds as she is in the present of that substance from Patrick."<<endl;
            cout<<"\nYou offer the needle to her.  She snatched it out of your hand as quick as humanly possible and ran away.)"<<endl;

            break;
        }

        if(fate[0] == 'T' || fate[0] == 't'){
            cout<<"\nDemi: You wouldn't.  (as her eyes widen in fear and confusion.)"<<endl;
            cout<<"(Demi took a step back and in silence you just walked pass her.)"<<endl;
            cout<<"Before you are out of her earshot you whispered to her, 'Remember my face.  I am your worse nightmare.'"<<endl;

            break;
        }

        if(fate[0] == '3'){
            cout<<"\nYou ran.  She gave chase but a small frozen yogurt shop had caught her attention.  (You were relieved)"<<endl;

            break;
        }

        if(fate[0] == '1' || fate[0] == '2'){
            cout<<"\nIt seems she didn't even care for the respond as she just kept talking about herself hoping to seek emotions from you."<<endl;
        }
    }
}

int fifth_room(int cheddar){

    cls();

    //Specification A2 - Use an arry of structs
    int cookies_combo[11];
    int correct_result;
    int options;
    int karma;

    for(int i; i < 11; i++){
        cookies_combo[i] = 0;
    }

    cout<<"\nFurther West: Girl Scouts\n"<<endl;

    cout<<"(You finally see the building your are suppose to be for the interview.  You went over to a car window to make sure you yourself "<<
        "look picture ready for the interview.  As you approach the building you were stopped and surrounded by girl scouts.  There are too many "<<
        "to fight or run away from.  You think to yourself, 'is this the my final obstacle before getting that sweet job?'.)"<<endl;

    cout<<"Scout Leader:  Hello, would you like to buy some cookies?"<<endl;
    cout<<"\n(You declined, but they still would not budgets.)\n"<<endl;
    cout<<"\nScout Leader: I am sorry, but to let you go on any further you must buy 8 total box of cookies from the first two most popular selections.\n"<<endl;
    cout<<"(The scouts then wiped out all assortment of cookies.)"<<endl;
    cout<<"\nScout Leader: Due to low cookies sales we were given orders by corporate to be more confrontational."<<endl;
    cout<<"Scout Leader:  Now please do us both a favor and buy the cookies.  Sarah over there had put three adults behind bars by any means I may add."<<endl;

    cout<<"\nWhat will you do?\n"<<endl;

    if(cheddar > 5){

        cout<<"*It is ok, I have ordered these to from least to most favorites\n"<<endl;

        correct_result = 0;
        while(cheddar > 0 && correct_result != 8){
            cout<<"Money: "<<cheddar<<endl<<endl;
            cout<<"1. 	Samoas"<<endl;
            cout<<"2. 	Tagalongs"<<endl;
            cout<<"3. 	Do-si-dos"<<endl;
            cout<<"4. 	Thin Mints"<<endl;
            cout<<"5. 	Toffee-tastic"<<endl;
            cout<<"6. 	S'Mores"<<endl;
            cout<<"7. 	Lemon-Ups"<<endl;
            cout<<"8. 	Trefoils"<<endl;
            cout<<"9. 	Lemonades"<<endl;
            cout<<"10.	Toast-Yays!"<<endl;
            cout<<"11.	Caramel Chocolate Chip"<<endl;

            cin>>options;

            while(options < 1 || options > 11){
                cout<<"Those are not options. Try again."<<endl;

                cin>>options;
            }

            cookies_combo[options - 1] += 1;

            cheddar -= 5;

            correct_result = cookies_combo[0] + cookies_combo [1];

            cout<<cookies_combo[0]<<"lol"<<cookies_combo[1]<<endl;

            cout<<correct_result<<endl;
        }
    }

    if(correct_result == 8){
        cout<<"Scout Leader:  Thank you come again."<<endl;

        karma = 0;
    }

    if(cheddar < 5){
        cout<<"Money: "<<cheddar<<endl;
        cout<<"(Out of sheer desperation you acted manic ran straight at them.  This worked but you were scared that your employer might had saw you.)"<<endl;
        cout<<"\n*By the way, I lied.  The cookies are actually sorted from most favorites to least.\n"<<endl;

        karma = 1;
    }

    return karma;
}

int sixth_room(int g_s, string title, bool gender, bool race, bool cool){

	cls();

    int hired = 0;
    int ending;

    cout<<"Final Destination\n"<<endl;

    cout<<"(You finally made it.  The job of your dream in the heart of Hollywood.  McDonald.  Where people who couldn't make it comes so "<<
        "they would not have to go back home and face their families and their own shame)"<<endl;
    cout<<"\n(You saw the manager as he asked you to come as he is ready for the interview.)\n"<<endl;
    cout<<"\nMcEmployer: Hello welcome to McDonald "<<title<<" let me see your resume.\n"<<endl;

    if(g_s == 1){
        cout<<"Man, I don't know how you did it but the reason why I am stuck here is because of those Girl Scouts.  They run me clean each time I come to work."<<endl;
        cout<<"I tried to not bring anything but they would just take my shoes or slash my tires."<<endl;
    }
    else{
        cout<<"Yeah, I would had done the same.  Those Girl Scouts are insane"<<endl;
    }

    if(title[0] > 'j' || title[0] > 'J'){
        cout<<"\n"<<title<<" huh?  That's one funny name.\n"<<endl;

    }
    else{
        cout<<"\n"<<title<<" I like that name.  It suits you very much."<<endl;
    }

    if(g_s == 0){
        hired += 2;
    }

    if(toupper(title[0]) < 'J'){
        hired += 1;
    }

    if(gender == true){
        hired += 1;
    }

    if(race == true){
        hired += 1;
    }

    if(cool == true){
        hired += 3;
    }

    if(hired >= 6){
        cout<<"Well, looks good.  You are hired."<<endl;

        ending = 0;
    }
    else{
        cout<<"Sorry, it seems like you don't even meet the requirements of flipping burgers or talking to strangers."<<endl;

        ending = 1;
    }

    return ending;
}

void stats(int g_s, string title, bool gender, bool race, bool cool, bool drugs, int live){

    cout<<"\nACHIEVEMENT(S)\n"<<endl;

    cout<<"Money left: "<<live<<endl;

    if(drugs == true){
        cout<<"You found drugs!!!!!"<<endl;
    }
    if(g_s == 0){
        cout<<"You found the secret Girl Scout cookies combo!!!!!"<<endl;
    }
    if(toupper(title[0]) < 'J'){
        cout<<"Your name was cool"<<endl;
    }
    if(gender == true){
        cout<<"Sad.  But men tend to be hired more"<<endl;
    }
    if(race == true){
        cout<<"Double sad.  But color of one's skin matters"<<endl;
    }
    if(cool == true){
        cout<<"I am glad we both think you are likable."<<endl;
    }
}


//Specification A3 - Let the player replay again until the player prompt to stop.
bool keep_playing(){

    string answer;
    bool gate_way;

    cout<<"Do you want to play again? (Y/N)"<<endl;

    cin>>answer;

    answer[0] = toupper(answer[0]);

    while(answer[0] != 'Y' && answer[0] != 'N'){
        cout<<"Please try again.  Invalid answer"<<endl;

        cin>>answer;

        answer[0] = toupper(answer[0]);
    }

    if(answer[0] == 'Y'){
        gate_way = true;
    }
    else{
        gate_way = false;
    }

    return gate_way;
}




