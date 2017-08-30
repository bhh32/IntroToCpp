#pragma once
#ifndef CREATEMAP_H
#define CREATEMAP_H

class Map
{
public:
	char mapArray[400][400]; // 20 Rows, 10 Columns
	void DrawMap(int mapX, int mapY, int playerX, bool shot, int shotx, int shoty);


};



#endif CREATEMAP_H