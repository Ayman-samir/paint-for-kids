#include "GUI.h"

//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	isfilled = false;
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = PINK;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
	//mo
	//setFillcolor(RED);
	
	
}


//======================================================================================//
//								Input Functions										    //
//======================================================================================//


void GUI::GetPointClicked(int &x, int &y) const
{

	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_ELPS: return DRAW_ELPS;
			case ITM_HEX: return DRAW_HEX;
			case ITM_FILLCOLOR: return CHNG_FILL_CLR;
 			case ITM_EXIT: return EXIT;	
			
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}	

}
//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\Menu_Sqr.jpg";
	MenuItemImages[ITM_ELPS] = "images\\MenuItems\\Menu_Elps.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\HEX.jpg";
	MenuItemImages[ITM_FILLCOLOR] = "images\\MenuItems\\colors.jpg";
	
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i< COLOR_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
	

}


//////////////////////////////////////////////////////////////////////////////////////////
// drow color menu items 

void GUI::CreateColorMenu()const
{

	string MenuItemcolors[COLOR_COUNT];
	MenuItemcolors[ITM_red] = "images\\MenuItems\\red.jpg";
	MenuItemcolors[ITM_green] = "images\\MenuItems\\green.jpg";
	MenuItemcolors[ITM_yellow] = "images\\MenuItems\\yellow.jpg";
	MenuItemcolors[ITM_blue] = "images\\MenuItems\\blue.jpg";
	MenuItemcolors[ITM_defaultclr] = "images\\MenuItems\\x.jpg";
	
	

	int ix = UI.MenuItemWidth *(COLOR_COUNT /2)+15;
	
	int iy = UI.ToolBarHeight * 2 - 32;
	
	for(int i=0; i< COLOR_COUNT; i++)
		
	pWind->DrawImage(MenuItemcolors[i], i*ix/2,iy,UI.MenuItemWidth, UI.ToolBarHeight);
	
	
	 
	
	


}
void GUI::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}
void GUI::ClearColorMenu()
	{

	int ix = UI.MenuItemWidth * (DRAW_ITM_COUNT / 2) + 15;
	//CWI.height = CWI.menuItemHeight * 3 - 32;
	int iy = UI.ToolBarHeight * 2 - 32;

		pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, iy, UI.MenuItemWidth* DRAW_ITM_COUNT+30,  UI.StatusBarHeight*2.5);
	//PrintMessage("clear colors menu");
	

	

	}

//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor()const 	//get current filling color
{	
	
	return UI.FillColor;


}
//////////////////////////////////////////////////////////////////////////////////////////
	
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void GUI::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);
	pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);
	
}

void GUI::DrawEllipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

	
		
}

// hexagon drow git

void GUI::DrawHex(Point TopLeft, int Llen, int Rlen, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	//2.4- Calculate array of points :
	int px1 = TopLeft.x, px2 = TopLeft.x + Llen, px3 = TopLeft.x + (1.5 * Llen), px4 = (TopLeft.x + Llen), px5 = px1, px6 = TopLeft.x - (0.5 * Llen);
	int py1 = TopLeft.y, py2 = py1, py3 = TopLeft.y + Rlen, py4 = TopLeft.y + (2 * Rlen), py5 = py4, py6 = TopLeft.y + Rlen;
	int hX[6] = { px1,px2,px3,px4,px5,px6 };
	int hY[6] = { py1,py2,py3,py4,py5,py6 };
	for (int i = 0; i < 6; i++)
	{
		/*if (!(hY[i] >= UI.ToolBarHeight && hY[i] < UI.height - UI.StatusBarHeight))
		{
			PrintMessage("The drawing will go out of the drawing area");
			break;
		}*/
		pWind->DrawPolygon(hX, hY, 6, style);
	}
}
void GUI::setFillcolor(color c) {
	
	UI.FillColor = c;

}
COLORSITEM GUI::getcolor() {


	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		
		int ix, iy;
		ix=
		iy = UI.ToolBarHeight * 2 - 32;
		if (y >= iy && y < iy + UI.ToolBarHeight);
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_red: return RED1;
			case ITM_green: return GREEN2;
			case ITM_yellow: return YELLOW3;
			case ITM_blue: return BLUE5;
			case ITM_defaultclr: return defaultcolor;
			
		


			default: return EMPTYY;	//A click on empty place in desgin toolbar
			}
		}


	}


}





//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{

	delete pWind;
}

