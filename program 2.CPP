#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<conio.h>

    void symm(int x, int y, int cx, int cy)
    {
        putpixel(x+cx,y+cy,RED);
        putpixel(y+cx,x+cy,RED);
        putpixel(y+cx,-x+cy,RED);
        putpixel(x+cx,-y+cy,RED);
        putpixel(-x+cx,-y+cy,RED);
        putpixel(-y+cx,-x+cy,RED);
	putpixel(-y+cx,x+cy,RED);
	putpixel(-x+cx,y+cy,RED);
    }

    void main()
    {
	
	int gdriver = DETECT, gmode, errorcode;
	int x,y,r,cx,cy,E,SE,D;


	initgraph(&gdriver, &gmode,"C://Turbo//TC//BGI");

	
	errorcode = graphresult();


	if (errorcode != grOk)
	{
	    printf("Graphics error: %s\n", grapherrormsg(errorcode));
	    printf("Press any key to halt:");
	    getch();
	    exit(1);
	}

	cout<<"\nEnter centre(x): ";
	cin>>cx;
	cout<<"\nEnter centre(y): ";
	cin>>cy;
	cout<<"\nEnter radius: ";
	cin>>r;
	cleardevice();
	x=0;
	y=r;

	symm(x,y,cx,cy);

	D=1-r;

	while(y>x)
	{
	    if(D<=0)
	    {
		E=(2*x)+3;
		D+=E;
		x++;
	    }
	    else
	    {
		SE=(2*x)-(2*y)+5;
		D+=SE;
		x++;
		y--;
	    }
	    symm(x,y,cx,cy);
	}

	
	getch();
	closegraph();
    }
