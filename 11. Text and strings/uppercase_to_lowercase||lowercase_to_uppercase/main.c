#include <stdio.h>
#include "letter_changer.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    printf("Wpisz cos:\n");
    char text[1001] = {'\0'};
    char* ukaz_text = text;
    int i;
    char symbol;

    enum letter_changer_t c;

    for (i = 0; i < 1000; i++)
    {

        scanf("%c", &symbol);
        if (symbol == '\n')
        {
            *(ukaz_text+i) = '\0';
            break;
        }
        *(ukaz_text + i) = symbol;
    }
    if (i == 1000)
    {
        while(getchar() != '\n'){}
    }
    printf("Jesli wielkie wcisnij: B, male: S\n");
    char litera;
    scanf("%c", &litera);
    while (litera != 'B' && litera != 'b' && litera != 'S' && litera != 's')
    {
        printf("Incorrect input\n");
        printf("Jesli wielkie wcisnij: B, male: S\n");
        scanf(" %c", &litera);
    }
    if (litera == 'B' || litera == 'b')
    {
        c = TO_UPPER;
    }
    else
        c = TO_LOWER;

    change_letter_size(ukaz_text, c);
    printf("%s", ukaz_text);
    /*
    char textt[] = "\"Considering the current sad state of our computer programs, software development is clearly still a black art, and cannot yet be called an engineering discipline.\" - Bill Clinton\nThe most important property of a program is whether it accomplishes the intention of its user. - C.A.R. Hoare\n\"Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live.\" - Martin Golding\n\"PHP is a minor evil perpetrated and created by incompetent amateurs, whereas Perl is a great and insidious evil, perpetrated by skilled but perverted professionals.\" - Jon Ribbens\n\"We may encounter many defeats but we must not be defeated.\"- Maya Angelou\nWe are made wise not by the recollection of our past, but by the responsibility for our future. - George Bernard Shaw\nObject-oriented programming is an exceptionally bad idea which could only have originated in California. - Edsger Dijkstra\n\"Hardware: The parts of a computer system that can be kicked.\" - Jeff Pesis\n\"FORTRAN is not a flower but a weed &#8212; it is hardy, occasionally blooms, and grows in every computer.\" - Alan J. Perlis.\n\"Any sufficiently advanced technology is indistinguishable from magic.\" - Arthur C Clarke \nThe real danger is not that computers will begin to think like men, but that men will begin to think like computers.-Sydney J. Harris\nArtificial intelligence will reach human levels by around 2029. Follow that out further to, say, 2045, we will have multiplied the intelligence, the human biological machine intelligence of our civilization a billion-fold. - Ray Kurzweil\n\"To iterate is human, to recurse divine.\" - L. Peter Deutsch\nWise men speak because they have something to say; fools because they have to say something. - Plato\nThe most disastrous thing that you can ever learn is your first programming language. - Alan Kay\nAll this modern technology just makes people try to do everything at once.-Bill Watterson\nIt is better to be feared than loved, if you cannot be both. - Niccolo Machiavelli\nForget artificial intelligence - in the brave new world of big data, it\'s artificial idiocy we should be looking out for. - Tom Chatfield\n";
    char *text_copy_2 = change_letter_size(textt, TO_UPPER);
    printf("\"CONSIDERING THE CURRENT SAD STATE OF OUR COMPUTER PROGRAMS, SOFTWARE DEVELOPMENT IS CLEARLY STILL A BLACK ART, AND CANNOT YET BE CALLED AN ENGINEERING DISCIPLINE.\" - BILL CLINTON\nTHE MOST IMPORTANT PROPERTY OF A PROGRAM IS WHETHER IT ACCOMPLISHES THE INTENTION OF ITS USER. - C.A.R. HOARE\n\"ALWAYS CODE AS IF THE GUY WHO ENDS UP MAINTAINING YOUR CODE WILL BE A VIOLENT PSYCHOPATH WHO KNOWS WHERE YOU LIVE.\" - MARTIN GOLDING\n\"PHP IS A MINOR EVIL PERPETRATED AND CREATED BY INCOMPETENT AMATEURS, WHEREAS PERL IS A GREAT AND INSIDIOUS EVIL, PERPETRATED BY SKILLED BUT PERVERTED PROFESSIONALS.\" - JON RIBBENS\n\"WE MAY ENCOUNTER MANY DEFEATS BUT WE MUST NOT BE DEFEATED.\"- MAYA ANGELOU\nWE ARE MADE WISE NOT BY THE RECOLLECTION OF OUR PAST, BUT BY THE RESPONSIBILITY FOR OUR FUTURE. - GEORGE BERNARD SHAW\nOBJECT-ORIENTED PROGRAMMING IS AN EXCEPTIONALLY BAD IDEA WHICH COULD ONLY HAVE ORIGINATED IN CALIFORNIA. - EDSGER DIJKSTRA\n\"HARDWARE: THE PARTS OF A COMPUTER SYSTEM THAT CAN BE KICKED.\" - JEFF PESIS\n\"FORTRAN IS NOT A FLOWER BUT A WEED &#8212; IT IS HARDY, OCCASIONALLY BLOOMS, AND GROWS IN EVERY COMPUTER.\" - ALAN J. PERLIS.\n\"ANY SUFFICIENTLY ADVANCED TECHNOLOGY IS INDISTINGUISHABLE FROM MAGIC.\" - ARTHUR C CLARKE \nTHE REAL DANGER IS NOT THAT COMPUTERS WILL BEGIN TO THINK LIKE MEN, BUT THAT MEN WILL BEGIN TO THINK LIKE COMPUTERS.-SYDNEY J. HARRIS\nARTIFICIAL INTELLIGENCE WILL REACH HUMAN LEVELS BY AROUND 2029. FOLLOW THAT OUT FURTHER TO, SAY, 2045, WE WILL HAVE MULTIPLIED THE INTELLIGENCE, THE HUMAN BIOLOGICAL MACHINE INTELLIGENCE OF OUR CIVILIZATION A BILLION-FOLD. - RAY KURZWEIL\n\"TO ITERATE IS HUMAN, TO RECURSE DIVINE.\" - L. PETER DEUTSCH\nWISE MEN SPEAK BECAUSE THEY HAVE SOMETHING TO SAY; FOOLS BECAUSE THEY HAVE TO SAY SOMETHING. - PLATO\nTHE MOST DISASTROUS THING THAT YOU CAN EVER LEARN IS YOUR FIRST PROGRAMMING LANGUAGE. - ALAN KAY\nALL THIS MODERN TECHNOLOGY JUST MAKES PEOPLE TRY TO DO EVERYTHING AT ONCE.-BILL WATTERSON\nIT IS BETTER TO BE FEARED THAN LOVED, IF YOU CANNOT BE BOTH. - NICCOLO MACHIAVELLI\nFORGET ARTIFICIAL INTELLIGENCE - IN THE BRAVE NEW WORLD OF BIG DATA, IT\'S ARTIFICIAL IDIOCY WE SHOULD BE LOOKING OUT FOR. - TOM CHATFIELD\n");
    printf("\n\n\n\n\n\n");
    printf("%s", text_copy_2);*/
    return 0;
}

