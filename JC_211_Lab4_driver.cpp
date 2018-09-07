#include "JC_211_Lab4.h"

int main() {

	//Declare database
	database main;
	main.initialize();
	main.menu();
	return 0;
}

/*

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
SCREENSHOT
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Menu:
1) View all contacts
2) Add contact
3) Edit a contact
4) Delete a contact
0) Exit program

Input:

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
SCREENSHOT: VIEW ALL
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Existing contacts (10)

1) John Doe johndoe@email.com 0000000000
2) Jane Doe janedoe@email.com 1111111111
3) Ecks Dee ecksdee@email.com 2222222222
4) Fish Guy fishguy@email.com 3333333333
5) Other Guy otherguy@email.com 4444444444
6) That Guy thatguy@email.com 5555555555
7) Some Guy someguy@email.com 6666666666
8) Ultra Guy ultraguy@email.com 7777777777
9) Cow Guy cowguy@email.com 8888888888
10) Super Guy superguy@email.com 999999999

Menu:
1) View all contacts
2) Add contact
3) Edit a contact
4) Delete a contact
0) Exit program

Input:

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
SCREENSHOT: DELETE
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DELETE CONTACT
Existing contacts (10)

1) John Doe johndoe@email.com 0000000000
2) Jane Doe janedoe@email.com 1111111111
3) Ecks Dee ecksdee@email.com 2222222222
4) Fish Guy fishguy@email.com 3333333333
5) Other Guy otherguy@email.com 4444444444
6) That Guy thatguy@email.com 5555555555
7) Some Guy someguy@email.com 6666666666
8) Ultra Guy ultraguy@email.com 7777777777
9) Cow Guy cowguy@email.com 8888888888
10) Super Guy superguy@email.com 999999999

Enter contact ID: 4
Fish Guy fishguy@email.com 3333333333
has been deleted.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
SCREENSHOT: ADD
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Existing contacts (11)

1) John Doe johndoe@email.com 0000000000
2) Jane Doe janedoe@email.com 1111111111
3) Ecks Dee ecksdee@email.com 2222222222
4) Fish Guy fishguy@email.com 3333333333
5) Other Guy otherguy@email.com 4444444444
6) That Guy thatguy@email.com 5555555555
7) Some Guy someguy@email.com 6666666666
8) Ultra Guy ultraguy@email.com 7777777777
9) Cow Guy cowguy@email.com 8888888888
10) Super Guy superguy@email.com 999999999
11) Yuliya Lector yl@gmail.com 5556465111

Menu:
1) View all contacts
2) Add contact
3) Edit a contact
4) Delete a contact
0) Exit program

Input:


* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
SCREENSHOT: ADD (Dupe #)
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

ADD CONTACT
Enter name: Happy
Fish
Enter email: h@gmail.com
Enter phone number: 1111111111

Contact Jane Doe already has the phone number '1111111111'
Phone numbers must be UNIQUE. Contact cannot be added.


* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
SCREENSHOT: EDIT
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

EDIT CONTACT
Existing contacts (10)

1) John Doe johndoe@email.com 0000000000
2) Jane Doe janedoe@email.com 1111111111
3) Ecks Dee ecksdee@email.com 2222222222
4) Fish Guy fishguy@email.com 3333333333
5) Other Guy otherguy@email.com 4444444444
6) That Guy thatguy@email.com 5555555555
7) Some Guy someguy@email.com 6666666666
8) Ultra Guy ultraguy@email.com 7777777777
9) Cow Guy cowguy@email.com 8888888888
10) Super Guy superguy@email.com 999999999

Enter contact ID: 3

EDITING: Ecks Dee ecksdee@email.com 2222222222

What do you want to change?

1) Name
2) E-mail address
3) Phone number

1

Enter name: Farfetched Guy
Name updated to Farfetched Guy.

NEW: Farfetched Guy ecksdee@email.com 2222222222

*/