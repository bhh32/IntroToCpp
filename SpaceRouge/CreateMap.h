#pragma once
#ifndef CREATEMAP_H
#define CREATEMAP_H

class Map
{
public:
	char mapArray[20][10]; // 20 Rows, 10 Columns
	int mapX;
	int mapY;

	void DrawMap();

};



#endif CREATEMAP_H