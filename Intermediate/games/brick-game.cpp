#include <iostream.h>

#include <conio.h>

#include <ctype.h>                  //defining toupper

#include < process.h > //exit(0)
  #include < dos.h > #include < stdlib.h > #include < graphics.h > #include < stdio.h >

  #define NULL 0# define YES 1# define NO 0# define ESC 0x1b /* Define the escape key	*/

int MaxX, MaxY, MidX, MidY;
int bri[5][20];

int GraphDriver; /* The Graphics device driver		*/
int GraphMode; /* The Graphics mode value		*/
int MaxXX, MaxYY; /* The maximum resolution of the screen */
int MaxColors; /* The maximum # of colors available	*/
int ErrorCode; /* Reports any graphics errors		*/
struct palettetype palette; /* Used to read palette info*/

// Initialize the graphics mode
void Initialize(void);

// Display the last screen of bricks
void SayGoodbye(void);

// Changes the text style and report any error if encounter
void changetextstyle(int font, int direction, int charsize);

// Welcome screen of bricks game
mainscreen();

// Instruction messages of bricks game
screen();

// To display the bricks (in square box) and paddles in rectangle form 
and
bulbs rounded form
bricks();

// Delete a bricks when bulb hit it
delbrick(int, int);

// Echoes different musics
bell(int);

int graphmode = CGAHI, graphdriver = CGA, level; // resolution of
CGAHI = 640 x 200(col x row)

/*-------------------Mouse Library--------------*/

void InitMouse() //initializes the mouse
{
  union REGS in , out; in .x.ax = 33;
  int86(0x33, & in , & out);
}

void MousePos(int * x, int * y, int * click) { //stores back (x,y) values and click type
  //click=1: left click
  //2: right click
  //3: middle click
  union REGS in , out; in .x.ax = 3;
  int86(0x33, & in , & out);
  * click = (int) out.x.bx;
  * x = (int) out.x.cx;
  * y = (int) out.x.dx;
}
/*-----------------------End Of Mouse Methods----------*/

main
  () {
    union REGS ii, oo;

    int BallX, BallY, Base1, Base2, dx = 1, dy = -1, OldX, OldY;
    int totallayer[5] = {
      10,
      20,
      30,
      40,
      50
    }, max = 50, layer = 4;
    int i, flag = 0, speed = 15, score = 0, chance = 4, areareq;

    char * m1, * m2; //pointers to memory

    /* Function to initialise the graphics mode */
    initgraph( & graphdriver, & graphmode, "c:\tc\bgi");
    mainscreen();
    initgraph( & graphdriver, & graphmode, "c:\tc\bgi");
    /**************************************************/
    /* Function to initialise the mouse */
    InitMouse();
    /* get the maximum value of x and y coordinates of the screen */
    MaxX = getmaxx();
    MaxY = getmaxy();
    /* finding the center of the screen */
    MidX = MaxX / 2;
    MidY = MaxY / 2;

    /* create opening  screen and accept the level of the  player's  */
    level = screen();

    /* assign the  speed to ball as per the level chosen */
    switch (level) {
    case 'M':
    case 'm':
      speed = 10;
      break;

    case 'F':
    case 'f':
      speed = 3;
    }

    /* draw the four layer of bricks, the paddle and the ball */
    rectangle(0, 0, MaxX, MaxY - 12);
    bricks();
    rectangle(MidX - 25, MaxY - 7 - 12, MidX + 25, MaxY - 12);
    floodfill(MidX, MaxY - 1 - 12, 12);
    circle(MidX, MaxY - 13 - 12, 12);

    //	fillellipse ( MidX, MaxY - 13 - 12,12,12 ) ;
    floodfill(MidX, MaxY - 10 - 12, 12);

    /* memory allocation for storing the image of the paddle */
    areareq = imagesize(MidX - 12, MaxY - 18, MidX + 12, MaxY - 8);
    m1 = ((char * ) malloc(areareq));

    /* memory allocation for storing the image of the ball */
    areareq = imagesize(MidX - 25, MaxY - 7, MidX + 25, MaxY - 1);
    m2 = ((char * ) malloc(areareq));

    /* if unable to alloacte the memory  */
    if (m1 == NULL || m2 == NULL) {
      puts("Not Enough memory!!");
      exit(1);
    }

    /* image of the paddle and the ball is stored into allocated memory */
    getimage(MidX - 12, MaxY - 7 - 12 - 12 + 1, MidX + 12, MaxY - 8 -
      12,
      m1);
    getimage(MidX - 25, MaxY - 7 - 12, MidX + 25, MaxY - 1 - 12, m2);

    /* store current position of the paddle and ball */
    Base1 = MidX - 25;
    Base2 = MaxY - 7 - 12;
    BallX = MidX - 12;
    BallY = MaxY - 7 - 12 + 1 - 12;

    /* display balls remaining ( initially 3 ) */
    gotoxy(45, 25);
    cout << "Balls :";
    for (i = 0; i < 3; i++) {
      circle(515 + i * 35, MaxY - 5, 12);
      floodfill(515 + i * 35, MaxY - 5, 12);
    }

    /* display starting score */
    gotoxy(1, 25);
    cout << "Score:   ";
    gotoxy(16, 25);
    cout << score;

    /* select font and alignment for displaying text */
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    changetextstyle(GOTHIC_FONT, HORIZ_DIR, 4);

    while (1) {
      flag = 0;

      /* saving current x and y coordinates of the ball */
      OldX = BallX;
      OldY = BallY;

      /* update ballx and bally to move the ball in correct direction */
      BallX = BallX + dx;
      BallY = BallY + dy;

      /* according to the position of ball the layer of bricks is 
determined
*/
      if (BallY > 40) {
        max = 50;
        layer = 4;
      } else {
        if (BallY > 30) {
          max = 40;
          layer = 3;
        } else {
          if (BallY > 20) {
            max = 30;
            layer = 2;
          } else {
            if (BallY > 10) {
              max = 20;
              layer = 1;
            } else {
              max = 10;
              layer = 0;
            }
          }
        }
      }

      /* if the ball hits the right boundary, move it to the left */
      if (BallX > (MaxX - 24 - 1)) {
        bell(5);
        BallX = MaxX - 24 - 1;
        dx = -dx;
      }

      /* if the ball hits the left boundary, move it to the right */
      if (BallX < 1) {
        bell(5);
        BallX = 1;
        dx = -dx;
      }

      /* if the ball hits the top boundary, move it down */
      if (BallY < 1) {
        bell(5);
        BallY = 1;
        dy = -dy;
      }

      /* if the ball is in the area of the bricks */
      if (BallY < max) {
        /* if there is no brick  at the top of the ball */
        if (bri[layer][(BallX + 10) / 32] == 1) {
          /*  if the ball touches a brick */
          for (i = 1; i <= 6; i++) {
            /* check whether there is a brick to the right of the ball */
            if (bri[layer][(BallX + i + 10) / 32] == 0) {
              /* if there is a brick */
              BallX = BallX + i;
              flag = 1;
              break;
            }

            /* check whether there is a brick to the left of the ball */
            if (bri[layer][(BallX - i + 10) / 32] == 0) {
              BallX = BallX - i;
              flag = 1;
              break;
            }
          }

          /* if the ball does not touch a brick at the top, left or right */
          if (!flag) {
            /* check if the ball has moved above the current layer */
            if (BallY < totallayer[layer - 1]) {
              /* if so, change current layer appropriately */
              layer--;
              max = totallayer[layer];
            }

            /* restore the image of the ball at the old coordinates */
            putimage(OldX, OldY, m1, OR_PUT);

            /* erase the image at the old coordinates */
            putimage(OldX, OldY, m1, XOR_PUT);

            /* place the image of the ball at the new coordinates */
            putimage(BallX, BallY, m1, XOR_PUT);

            /*  delay for fewseconds*/
            delay(speed);

            /* carry on moving the ball */
            continue;
          }
        }

        /* when ball touch the brick control comes to this point */
        bell(5); /* play music */

        /* erase the touched brick  */
        delbrick((BallX + 10) / 32, layer);

        /* if the brick hit is on the extreme right */
        if ((BallX + 10) / 32 == 19)
          line(MaxX, 0, MaxX, 50); /* redraw right boundary */

        /* if the brick hit is on the extreme left */
        if ((BallX + 10) / 32 == 0)
          line(0, 0, 0, 50); /* redraw left boundary */

        /* if the brick hit is in the topmost layer */
        if (layer == 0)
          line(0, 0, MaxX, 0); /* redraw top boundary */

        /* set appropriate array element to 1 to indicate absence of brick 
         */
        bri[layer][(BallX + 10) / 32] = 1;

        BallY = BallY + 1; /* update the y coordinate */
        dy = -dy; /* change the current direction of the ball */
        score += 10; /* increment the score by 10 */
        gotoxy(16, 25);
        cout << score; /* display latest score */

        /* if the first brick is hit during a throw*/
      }

      /* if  ball reached the bottom */
      if (BallY > 180 - 12) {

        /* if paddle missed the ball */
        if (BallX < Base1 - 20 || BallX > Base1 + 50) {
          /* continue the decrement of the ball */
          while (BallY < 177) {
            /* erase the image of the ball at the old coordinates */
            putimage(OldX, OldY, m1, XOR_PUT);

            /* put the image of the ball at the new coordinates */
            putimage(BallX, BallY, m1, XOR_PUT);

            /* introduce delay for fewseconds */
            delay(speed);

            /* saveing current x and y coordinates of the ball */
            OldX = BallX;
            OldY = BallY;

            /* update ballx and bally to move the ball in correct direction */
            BallX = BallX + dx;
            BallY = BallY + dy;
          }

          chance--; /* decrement the total number of chances */
          score -= 10; /* decrement 10 points for each ball lost */
          gotoxy(16, 25);
          cout << score; /* display latest score */
          bell(1);

          /* erase one  of the available balls */
          if (chance)
            putimage(515 + (chance - 1) * 35 - 12, MaxY - 10, m1, XOR_PUT);

          /* if the last ball is being played */
          if (chance == 1) {
            gotoxy(45, 25);
            cout << "Last ball... careful!";
          }

          /* if all the balls are lost */
          if (!chance) {
            gotoxy(45, 25);
            cout << "Press any key to continue ...              ";
            outtextxy(MidX, MidY, "Better luck next time");
            bell(2);

            closegraph();
            restorecrtmode();
            closegraph(); /* Close the graphics mode */
            Initialize(); /* Intialize the graphics mode */
            setbkcolor(4);
            SayGoodbye(); /* Display the That's all Folks message */
            closegraph(); /* Return the system to text mode	*/
            exit(0);
          }
        }

        /* if ball is collected on paddle */
        bell(4);
        BallY = 180 - 12; /* restore the y coordinate of ball */
        dy = -dy; /* move the ball upwards */
      }

      /* put the image of the ball at the old coordinates */
      putimage(OldX, OldY, m1, OR_PUT);

      /* erase the image of the ball at the old coordinates */
      putimage(OldX, OldY, m1, XOR_PUT);

      /* put the image of the ball at the upadted coordinates */
      putimage(BallX, BallY, m1, XOR_PUT);

      /* If score becomes 500 for every level player the speed of the ball
will
		   be standard PLAYER playing Fast level feel reduction of speed n
PLAYER
		   playing slow or medium level feel increment in speed... */

      if (score == 600)
        speed = 6;

      /* if all the bricks have been knockout */
      if (score == 800 - ((4 - chance) * 10)) {
        outtextxy(MidX, MidY, "Winner !!");

        if (score < 800)
          outtextxy(MidX, MidY + 30, "Try to score 800");
        else
          outtextxy(MidX, MidY + 30, " GREAT!");

        bell(2);
        SayGoodbye(); /* Display the That's all Folks message */

        closegraph();
        restorecrtmode();
        exit(0);
      }

      /* introduce delay for few seconds */
      delay(speed);

      /* if the key is pressed to exit the game */
      if (kbhit()) {
        /* interrupt issue to obtain the ascii and scan codes of key hit */
        ii.h.ah = 0;
        int86(22, & ii, & oo);
        /* if Esc key has been pressed */
        if (oo.h.ah == 1)
          exit(0);
      }
      /* put the image of the paddle at the old coordinates */
      putimage(Base1, Base2, m2, OR_PUT);

      /* erase the image of the paddle at the old coordinates */
      putimage(Base1, Base2, m2, XOR_PUT);

      //			/* if Esc key has been pressed */
      //			if ( oo.h.ah == 1 )
      //				exit ( 0 ) ;

      /* right arrow key */
      //			if ( oo.h.ah == 75 )
      //				Base1 = //Base1 - 25 ;
      /* left arrow key */
      //			if ( oo.h.ah == 77 )
      //				Base1= Base1 + 25 ;
      /**********************************************************/
      //dummy variables are useless
      //to get current x co-ordinate of the
      //mouse pointer pointer of Base1 is passed
      //the result is copied in the variable
      int ydummy, clickdummy;
      MousePos( & Base1, & ydummy, & clickdummy);

      /* if paddle goes beyond left boundary */
      if (Base1 < 0)
        Base1 = 0;
      /* if paddle goes beyond right boundary */
      if (Base1 > 589)
        Base1 = 589;
      /* put the image of the paddle at the proper position */
      putimage(Base1, Base2, m2, XOR_PUT);
      //		}
    }
    closegraph();
    Initialize();
    SayGoodbye(); /* Give user the closing screen 	*/
    closegraph(); /* Return the system to text mode	*/
    return (0);
  }

/* This function creates the opening screen and displyed instruction
related to the game
along with two option play or exit.After selecting the paly option it
display
three levels of the game and according to your choice you can select 
any
level.
This selected level is returned by this function to the mainprogram
according to which
the speed is assigned to the ball*/

screen() {
    int i, j, lx = 0, ly = 0, ch;

    rectangle(1, 1, 600, 195);
    setbkcolor(4);
    /* set the textstyle for displaying instruction */
    changetextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    outtextxy(150, 55, "         Instructions        ");
    changetextstyle(4, HORIZ_DIR, 5);
    outtextxy(130, 0, " B R I C K S");
    changetextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    outtextxy(30, 68, "Use mouse to move the paddle"); // can also 
    use
    KEYBOARD after activating keyboard event(use LEFT and RIGHT keys to move the PADDLE outtextxy(30, 88, "If you don't collect the ball on the paddle, you
          lose the ball.
          " ) ;
          outtextxy(30, 108, "On loosing a ball you loose 10 points."); outtextxy(30, 128, "On taking a brick you gain 10 points."); changetextstyle(7, HORIZ_DIR, 3); outtextxy(100, 148, "Press any key to continue ..."); bell(3); /* ring music */ fflush(stdin);
          //	if ( getch() == 0 )
          //		getch() ;

          closegraph(); initgraph( & graphdriver, & graphmode, "c:\tc\bgi"); rectangle(2, 2, 620, 195); setbkcolor(4);
          /* display the main menu */
          while (1) {

            changetextstyle(4, HORIZ_DIR, 5);
            outtextxy(60, 8, "Options Available:");
            outtextxy(150, 55, "Play ( P )");
            outtextxy(150, 125, "Exit ( E )");

            ch = 0;

            /* continue untill you select the correct choice  */
            while (!(ch == 'E' || ch == 'P')) {
              fflush(stdin);

              /* if a special key is hit, flush the keyboard buffer */
              if ((ch = getch()) == 0)
                getch();
              else
                ch = toupper(ch);
              /* store the uppercase of the choice 
made*/
            }

            if (ch == 'P')
              break;
            if (ch == 'E')
              exit(0);

          }

          //	setviewport ( 1, 125 - 12, MaxX - 1, MaxY - 1, 1 ) ;
          //	clearviewport() ;
          closegraph(); initgraph( & graphdriver, & graphmode, "c:\tc\bgi"); rectangle(2, 2, 620, 195); setbkcolor(4);

          /* display menu for the diffrent levels */
          changetextstyle(7, HORIZ_DIR, 3); outtextxy(60, 8, "Select the level for play:"); outtextxy(150, 50, "Slow ( S )"); outtextxy(150, 100, "Medium ( M )"); outtextxy(150, 150, "Fast ( F )");

          /* accept user's choice */
          fflush(stdin);
          if ((ch = getch()) == 0)
            getch();

          clearviewport();

          /* return the choice selected by the user */
          return (ch);
        }

        /* This function draws bricks at the start of the game.There are four
        layers of
        the bricks  */
        bricks() {
          int i, j, lx = 0, ly = 0;

          for (i = 0; i < 5; i++) /* 5 rows */ {
            for (j = 0; j < 30; j++) /* 20 columns */ {
              /* draw a brick at appropriate coordinates */
              rectangle(lx, ly, lx + 20, ly + 7);
              floodfill(lx + 1, ly + 1, 2);

              lx = lx + 32;
            }

            lx = 0;
            ly = ly + 10;
          }
        }

        /* This function erases the  brick which is knock by the ball */
        delbrick(int b, int l) {
          /* b - brick number, l - layer */

          setcolor(BLACK);
          rectangle(b * 32, l * 10, (b * 32) + 20, (l * 10) + 7);
          rectangle(b * 32 + 1, l * 10, (b * 32) + 20 - 1, (l * 10) + 7 -
            1);
          rectangle(b * 32 + 2, l * 10, (b * 32) + 20 - 2, (l * 10) + 7 -
            2);
          rectangle(b * 32 + 3, l * 10, (b * 32) + 20 - 3, (l * 10) + 7 -
            3);
          rectangle(b * 32 + 4, l * 10, (b * 32) + 20 - 4, (l * 10) + 7 -
            4);
          rectangle(b * 32 + 5, l * 10, (b * 32) + 20 - 5, (l * 10) + 7 -
            5);
          rectangle(b * 32 + 6, l * 10, (b * 32) + 20 - 6, (l * 10) + 7 -
            6);
          setcolor(CGA_YELLOW);
        }

        /* plays different types of music */
        bell(int m_no) {
          /* natural frequencies of 7 notes */
          float wave[6] = {
            120.81,
            136.83,
            144.81,
            154.61,
            216,
            240
          };
          int n, i;

          switch (m_no) {
          case 1:
            for (i = 0; i < 6; i++) {
              sound(wave[i] * 1);
              delay(30);
            }
            nosound();
            break;

          case 2:
            for (i = 0; i < 15; i++) {
              n = random(6);
              sound(wave[n] * 2);
              delay(100);
            }
            nosound();
            break;

          case 3:
            //	while ( !kbhit() )
            {
              n = random(6);
              sound(wave[n] * 2);
              delay(100);
            }
            nosound();

            /* flush the keyboard buffer */
            if (getch() == 0)
              getch();

            break;

          case 4:
            for (i = 5; i >= 0; i--) {
              sound(wave[i] * 4);
              delay(15);
            }
            nosound();
            break;

          case 5:
            sound(wave[2] * 5);
            delay(50);
            nosound();
          }
        }
        /*									*/
        /*	INITIALIZE: Initializes the graphics system and reports 	*/
        /*	any errors which occured.					*/
        /*									*/

        void Initialize(void) {
          int xasp, yasp; /* Used to read the aspect ratio*/

          GraphDriver = DETECT; /* Request auto-detection	*/
          initgraph( & GraphDriver, & GraphMode, "c:\tc\bgi");
          ErrorCode = graphresult(); /* Read result of initialization*/
          if (ErrorCode != grOk) {
            /* Error occured during init	*/
            printf(" Graphics System Error: %s
              ", grapherrormsg( ErrorCode ) );
              exit(1);
            }

            getpalette( & palette); /* Read the palette from board	*/
            MaxColors = getmaxcolor() + 1; /* Read maximum number of colors*/

            MaxXX = getmaxx();
            MaxYY = getmaxy(); /* Read size of screen		*/

          }
          /*									*/
          /*	SAYGOODBYE: Give a closing screen to the user before leaving.	*/
          /*									*/

          void SayGoodbye(void) {
            struct viewporttype viewinfo; /* Structure to read viewport	*/
            int h, w;

            //  MainWindow( "== Finale ==" );

            getviewsettings( & viewinfo); /* Read viewport settings	*/
            changetextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
            settextjustify(CENTER_TEXT, CENTER_TEXT);

            h = viewinfo.bottom - viewinfo.top;
            w = viewinfo.right - viewinfo.left;
            cleardevice();

            // StatusLine( "Press any key to EXIT" );

            getch();

            cleardevice(); /* Clear the graphics screen	*/

          }

          //}

          /*									*/
          /*	CHANGETEXTSTYLE: similar to settextstyle, but checks for	*/
          /*	errors that might occur while loading the font file.		*/
          /*									*/

          void changetextstyle(int font, int direction, int charsize) {
              int ErrorCode;

              graphresult(); /* clear error code		*/
              settextstyle(font, direction, charsize);
              ErrorCode = graphresult(); /* check result 		*/
              if (ErrorCode != grOk) {
                /* if error occured		*/
                closegraph();
                printf(" Graphics System Error: %s
                  ", grapherrormsg( ErrorCode ) );
                  exit(1);
                }
              }

              /* The main function body of main screen which displays the main screen
              creating the opening screen display */
              mainscreen() {
                int maxx, maxy, in , area;

                // get maximum x, y coordinates of the screen
                maxx = getmaxx();
                maxy = getmaxy();

                // setbkcolor sets the current background color using the palette
                setbkcolor(RED);

                // Draws a rectangle (graphics mode)
                rectangle(0, 0, maxx, maxy);

                // sets the line style and text justification in screen
                changetextstyle(10, HORIZ_DIR, 4);

                // displaying the output text on main screen
                outtextxy(140, 0, "  WELCOME");
                outtextxy(170, 50, "     TO ");
                outtextxy(140, 100, "    BRICKS");
                changetextstyle(7, HORIZ_DIR, 3);
                bell(3);
                outtextxy(110, 160, "Press any key to continue...");

                // Flushes the standard input device
                fflush(stdin);
                getch();
                closegraph();

              }