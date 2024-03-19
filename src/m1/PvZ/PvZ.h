#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class PvZ : public gfxc::SimpleScene
    {
    public:
        PvZ();
        ~PvZ();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;

        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;

    protected:
        struct hexagon {
            std::string culoare, color;
            float x, y, del;
            int linie;
            int hp;
        };

        struct stea {
            float x, y;
            bool collected;
            bool dead = { 0 };
            std::string culoare;
        };

        struct romb {
            std::string culoare;
            int linie, coloana;
            stea* stele = new stea[1000];
            int nr_stele;
            bool trage;
            int nr_stele_moarte = 0;
        };

        float cx, cy;
        glm::mat3 modelMatrix;
        float translateX, translateY;
        float scaleX, scaleY;
        float angularStep;
        float del[4][4] = { 0 };
        float timeUntilSpawnH = rand() % 8;     // spawn time hexagon
        float timeUntilSpawnS = rand() % 5;     // spawn time stea
        float width; // width dreptunghi
        float dim_stea = 10;
        float spawn = 1.5f;

        hexagon hexx[100];
        stea stele[100];
        stea stele_tun[5][1000];
        romb romburi[4][4];

        std::string romb, romb2, patrat = "";
        int x, y, squares[4][4] = { 0 }, nr = 0, hp, nr_stele = 8, stele_generate = 0, nr_stele_tun[4][4] = { 0 }, nr_romburi = 0, pos;
        bool click = 0, ok = 1;
    };
}
