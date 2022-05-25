
#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "CommonFunction.h"
#include "BaseObj.h"

#define MAX_TILES 20

class TileMap : public BaseObj
{
public:
     TileMap() {;}
     ~TileMap() {;}
};

class GameMap
{
public:
    GameMap() {;}
    ~GameMap() {;}

    void LoadMap(char* name);
    void LoadTiles(SDL_Renderer* screen);
    void DrawMap(SDL_Renderer* screen);
    Map getMap() const {return game_map_;};
    void SetMap(Map& map_data) {game_map_ = map_data;};  // xử lí map di chuyển theo nhân vật

private:
    Map game_map_;
    TileMap tile_map[MAX_TILES];
};

#endif // GAME_MAP_H
