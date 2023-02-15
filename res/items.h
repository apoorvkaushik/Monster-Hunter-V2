#include <raylib.h>
#include <string.h>

class BGDraw
{
private:
    Texture2D background;

    void drawBackgroud()
    {
        Vector2 pos = {0, 0};
        DrawTextureEx(background, pos, 0, 0.5, WHITE);
    }

public:
    void MainScreen(int le_vel)
    {

    }
};

class Monster
{
private:
    int number;
    int health;
    int height;
    Texture2D texture;
    int screenwidth;
    int screenheight;

    void monsterLoader()
    {
        long unsigned int len_enemy_num = strlen(TextFormat("%d", number));

        char res_path[] = "res/enemies/enemy01.png";

        if (len_enemy_num == 2)
        {
            res_path[17] = TextFormat("%d", number)[0];
            res_path[18] = TextFormat("%d", number)[1];
        }
        else
        {
            res_path[18] = TextFormat("%d", number)[0];
        }

        texture = LoadTexture(res_path);
    }

    void drawingTexture(int screenwidth, int screenheight)
    {
        DrawTexture(texture, (screenwidth / 2) - (texture.width / 2), (screenheight / 2) - (texture.height / 2), WHITE);
    }

public:
    void screendimension(int screen_width, int screen_height)
    {
        screenwidth = screen_width;
        screenheight = screen_height;
    }

    void createMonster(int num_ber, int hea_lth)
    {
        number = num_ber;
        health = hea_lth;
        monsterLoader();
    }

    void drawRes()
    {
        drawingTexture(screenwidth, screenheight);
    }

    int monsterNumber()
    {
        return number;
    }

    int monsterHealth()
    {
        return health;
    }

    int monsterHealthchanger(int he_lth)
    {
        health = he_lth;
    }

    Texture2D monsterTexture()
    {
        return texture;
    }
};

class Weapon
{
private:
    int damage;
    Sound boom;

    void playSound()
    {
    }

public:
    void createWeapon(int dam_age, Sound bo_om)
    {
        damage = dam_age;
        boom = bo_om;

        playSound();
    }
};

// Code
/*
Texture2D weaponLoader(int weapon_num)
{
    long unsigned int len_weapon_num = strlen(TextFormat("%d", weapon_num));

    char res_path[] = "resrc/weapons/gun01.png";

    if (len_weapon_num == 2)
    {
        res_path[17] = TextFormat("%d", weapon_num)[0];
        res_path[18] = TextFormat("%d", weapon_num)[1];
    }
    else
    {
        res_path[18] = TextFormat("%d", weapon_num)[0];
    }

    Texture2D res = LoadTexture(res_path);

    return res;
}

Texture2D backgroundLoader()
{
    char res_path[] = "resrc/bg/bg.png";

    Texture2D res = LoadTexture(res_path);

    return res;
}
*/