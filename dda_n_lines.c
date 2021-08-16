// Implemented using Turbo C
// Steps to enable Graphics Library in Turbo C.   
// Option -> Linkers -> Libraries -> Graphics Library

 #include<stdio.h>
 #include<conio.h>
 #include<math.h>
 #include<graphics.h>

 int Sign(int diff)
 {
	if(diff < 0)
		return (-1);
	else
		return (1);
       //	else
	      //	return 0;
 }

 int DDA(float x1, float y1, float x2, float y2)
 {
	int i = 1;
	float dx, dy, x, y, xinc, yinc, length;
   
	dx = x2 - x1;
	dy = y2 - y1;
   
	if(abs(dx) >= abs(dy))
		length = abs(dx);
	else
		length = abs(dy);
   
	xinc = dx/length;
	yinc = dy/length;
   
	x = x1 + (0.5)*Sign(xinc);
	y = y1 + (0.5)*Sign(yinc);
	
   while(i <= length)
	{
	       //	Plot(Integer(x),Integer(y))
		putpixel((int)x, (int)y, 3);
     
		x = x + xinc;
		y = y + yinc;
     
		i = i + 1;
	}
	return 0;
 }

 int main()
 {
	int gd=DETECT,gm,i=1,n;
	float x1,y1,x2,y2;
   
	initgraph(&gd,&gm,"C:\\TC\\BGI");
   
	printf("        ********** Line Plotting Program ********\n");
	printf("                    DDA Line ALGORITHM\n");
	
  printf("Enter Number of Lines"); //Eg: 6
	scanf("%d",&n);
  
  // To create a star put no of lines = 6 and enter follwoing values of (x1,y1) and (x2,y2)
  // 200 400 250 300
  // 250 300 300 400
  // 200 400 300 400
  // 200 325 300 325
  // 300 325 250 425
  // 200 325 250 425
   
	for(i=1;i<=n;i++)
	{
		printf("Enter values of Start and End points (x1,y1) and (x2,y2):\n"); 
		scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
		DDA(x1,y1,x2,y2);
	}
   
	printf("---------------------------------------------------------");
   
	getch(); // If this line is giving error remove it.
	closegraph();
	return 0;
 }
