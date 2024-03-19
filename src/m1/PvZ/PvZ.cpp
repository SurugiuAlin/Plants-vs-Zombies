#include "m1/PvZ/PvZ.h"

#include <vector>
#include <iostream>

#include "m1/PvZ/transform2D.h"
#include "m1/PvZ/create.h"

using namespace std;
using namespace m1;

PvZ::PvZ()
{
}


PvZ::~PvZ()
{
}


void PvZ::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 95;
    width = 50;
    float height = 390;
    float length = 30;

    hp = 3;
    angularStep = 0;

    Mesh* square11 = object2D::CreateSquare("square11", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square11);

    Mesh* square12 = object2D::CreateSquare("square12", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square12);

    Mesh* square13 = object2D::CreateSquare("square13", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square13);

    Mesh* square21 = object2D::CreateSquare("square21", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square21);

    Mesh* square22 = object2D::CreateSquare("square22", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square22);

    Mesh* square23 = object2D::CreateSquare("square23", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square23);

    Mesh* square31 = object2D::CreateSquare("square31", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square31);

    Mesh* square32 = object2D::CreateSquare("square32", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square32);

    Mesh* square33 = object2D::CreateSquare("square33", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square33);

    Mesh* dreptunghi = object2D::CreateRectangle("dreptunghi", corner, width, height, glm::vec3(1, 0, 0), true);
    AddMeshToList(dreptunghi);

    Mesh* chenar1 = object2D::CreateSquare("chenar1", corner, squareSide, glm::vec3(80, 74, 74), false);
    AddMeshToList(chenar1);

    Mesh* chenar2 = object2D::CreateSquare("chenar2", corner, squareSide, glm::vec3(80, 74, 74), false);
    AddMeshToList(chenar2);

    Mesh* chenar3 = object2D::CreateSquare("chenar3", corner, squareSide, glm::vec3(80, 74, 74), false);
    AddMeshToList(chenar3);

    Mesh* chenar4 = object2D::CreateSquare("chenar4", corner, squareSide, glm::vec3(80, 74, 74), false);
    AddMeshToList(chenar4);

    Mesh* rombportocaliu = object2D::CreateRomb("rombportocaliu", corner, 12, 20, 15, glm::vec3(1, 0.5f, 0), true);
    AddMeshToList(rombportocaliu);

    Mesh* rombgalben = object2D::CreateRomb("rombgalben", corner, 12, 20, 15, glm::vec3(1, 1, 0), true);
    AddMeshToList(rombgalben);

    Mesh* rombmov = object2D::CreateRomb("rombmov", corner, 12, 20, 15, glm::vec3(1, 0, 1), true);
    AddMeshToList(rombmov);

    Mesh* rombalbastru = object2D::CreateRomb("rombalbastru", corner, 12, 20, 15, glm::vec3(0, 0, 1), true);
    AddMeshToList(rombalbastru);

    Mesh* hexagonmov = object2D::CreateHexagon("hexagonmov", corner, 35, 30, glm::vec3(1, 0, 1), glm::vec3(0, 0, 1), true);
    AddMeshToList(hexagonmov);

    Mesh* hexagonalbastru = object2D::CreateHexagon("hexagonalbastru", corner, 35, 30, glm::vec3(0, 0, 1), glm::vec3(1, 0, 1), true);
    AddMeshToList(hexagonalbastru);

    Mesh* hexagonportocaliu = object2D::CreateHexagon("hexagonportocaliu", corner, 35, 30, glm::vec3(1, 0.5f, 0), glm::vec3(1, 1, 0), true);
    AddMeshToList(hexagonportocaliu);

    Mesh* hexagongalben = object2D::CreateHexagon("hexagongalben", corner, 35, 30, glm::vec3(1, 1, 0), glm::vec3(1, 0.5f, 0), true);
    AddMeshToList(hexagongalben);

    Mesh* star = object2D::CreateStar("star", corner, dim_stea, glm::vec3(1, 1, 0), true);
    AddMeshToList(star);

    Mesh* star_rand = object2D::CreateStarRand("star_rand", corner, dim_stea, glm::vec3(255, 51, 153), true);
    AddMeshToList(star_rand);

    Mesh* steaportocalie = object2D::CreateStarRand("steaportocalie", corner, dim_stea, glm::vec3(1, 0.5f, 0), true);
    AddMeshToList(steaportocalie);

    Mesh* steagalbena = object2D::CreateStarRand("steagalbena", corner, dim_stea, glm::vec3(1, 1, 0), true);
    AddMeshToList(steagalbena);

    Mesh* steamov = object2D::CreateStarRand("steamov", corner, dim_stea, glm::vec3(1, 0, 1), true);
    AddMeshToList(steamov);

    Mesh* steaalbastra = object2D::CreateStarRand("steaalbastra", corner, dim_stea, glm::vec3(0, 0, 1), true);
    AddMeshToList(steaalbastra);

    Mesh* hp1 = object2D::CreateSquare("hp1", corner, 50, glm::vec3(1, 0, 0), true);
    AddMeshToList(hp1);

    Mesh* hp2 = object2D::CreateSquare("hp2", corner, 50, glm::vec3(1, 0, 0), true);
    AddMeshToList(hp2);

    Mesh* hp3 = object2D::CreateSquare("hp3", corner, 50, glm::vec3(1, 0, 0), true);
    AddMeshToList(hp3);
}


void PvZ::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void PvZ::Update(float deltaTimeSeconds)
{
    if (hp) {
        std::vector<float> positionsX = { 90, 240, 390 };
        std::vector<float> positionsY = { 50, 200, 350 };

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(positionsX[j], positionsY[i]);
                std::string meshKey = "square" + std::to_string(i + 1) + std::to_string(j + 1);
                RenderMesh2D(meshes[meshKey], shaders["VertexColor"], modelMatrix);
            }
        }

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(10, 50);
        RenderMesh2D(meshes["dreptunghi"], shaders["VertexColor"], modelMatrix);

        for (int i = 0; i < 4; i++) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(42.5f + i * 150, 602.5f);
            std::string meshKey = "chenar" + std::to_string(i + 1);
            RenderMesh2D(meshes[meshKey], shaders["VertexColor"], modelMatrix);
        }

        std::vector<std::string> romburic = { "rombportocaliu", "rombgalben", "rombmov", "rombalbastru" };

        for (int i = 0; i < 4; i++) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(80 + i * 150, 650);
            RenderMesh2D(meshes[romburic[i]], shaders["VertexColor"], modelMatrix);
        }

        // RENDER HEXAGOANE RANDOM

        std::vector<std::string> hexagoane = { "hexagonportocaliu", "hexagongalben", "hexagonmov", "hexagonalbastru" };
        std::vector<std::string> culori = { "portocaliu", "galben", "mov", "albastru" };
        std::vector <float> linii = { 100, 250, 400 };

        timeUntilSpawnH -= deltaTimeSeconds;

        if (timeUntilSpawnH <= 0) {
            hexx[nr].x = 1250;
            hexx[nr].y = linii[rand() % 3];
            hexx[nr].hp = 3;
            hexx[nr].del = 1;
            if ((int)hexx[nr].y == 400) {
                hexx[nr].linie = 1;
            }
            else if ((int)hexx[nr].y == 250) {
                hexx[nr].linie = 2;
            }
            else if ((int)hexx[nr].y == 100) {
                hexx[nr].linie = 3;
            }
            int z = rand() % 4;
            hexx[nr].culoare = hexagoane[z];
            hexx[nr].color = culori[z];            // 0 portocaliu; 1 galben; 2 mov; 3 albastru
            nr++;
            timeUntilSpawnH = rand() % 8;
        }

        ok = 1;

        for (int i = 0; i < nr; i++) {

            if (hexx[i].x == 2 * width) {
                hp--;
            }
            if (hexx[i].x > width) {
                if (hexx[i].hp > 0) {
                    modelMatrix = glm::mat3(1);
                    modelMatrix *= transform2D::Translate(hexx[i].x, hexx[i].y);
                    RenderMesh2D(meshes[hexx[i].culoare], shaders["VertexColor"], modelMatrix);
                    hexx[i].x--;
                    ok = 0;
                }
                else {
                    modelMatrix = glm::mat3(1);
                    modelMatrix *= transform2D::Translate(hexx[i].x, hexx[i].y);
                    modelMatrix *= transform2D::Scale(hexx[i].del, hexx[i].del);
                    RenderMesh2D(meshes[hexx[i].culoare], shaders["VertexColor"], modelMatrix);
                    hexx[i].del -= deltaTimeSeconds;
                    if (hexx[i].del <= 0) {
                        hexx[i].del = 0;
                    }
                    hexx[i].linie = 0;
                }
                if (hexx[i].x >= 90 && hexx[i].x <= 185 && squares[hexx[i].linie][1]) {
                    del[hexx[i].linie][1] = 1;
                }
                if (hexx[i].x >= 240 && hexx[i].x <= 335 && squares[hexx[i].linie][2]) {
                    del[hexx[i].linie][2] = 1;
                }
                if (hexx[i].x >= 390 && hexx[i].x <= 485 && squares[hexx[i].linie][3]) {
                    del[hexx[i].linie][3] = 1;
                }
            }
            else {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(hexx[i].x, hexx[i].y);
                modelMatrix *= transform2D::Scale(hexx[i].del, hexx[i].del);
                RenderMesh2D(meshes[hexx[i].culoare], shaders["VertexColor"], modelMatrix);
                hexx[i].del -= deltaTimeSeconds;
                if (hexx[i].del <= 0) {
                    hexx[i].del = 0;
                }
                hexx[i].hp = 0;
                hexx[i].linie = 0;
            }
        }

        // RENDER STELE COST

        int translateStarX = 50;

        for (int i = 0; i < 8; i++) {

            modelMatrix = glm::mat3(1);
            if (i == 1) {
                translateStarX += 100;  // dupa primul romb al carui cost este de o stea trebuie sa ma deplasez mai mult
            }
            if (i == 3 || i == 5) {
                translateStarX += 50;   // pentru urmatoarele doua romburi al caror cost este de doua stele ma deplasez mai putin
            }
            modelMatrix *= transform2D::Translate(translateStarX + 50 * i, 585);
            RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
        }

        // RENDER STELE RANDOM

        timeUntilSpawnS -= deltaTimeSeconds;

        if (timeUntilSpawnS <= 0) {
            stele[stele_generate].x = rand() % 1280;
            stele[stele_generate].y = rand() % 720;

            stele[stele_generate].collected = 0;
            stele_generate++;
            int a = rand() % 5;
            if (a >= 1) {
                timeUntilSpawnS = a;
            }
        }

        for (int i = 0; i < stele_generate; i++) {
            if (stele[i].collected == 0) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(stele[i].x, stele[i].y);
                RenderMesh2D(meshes["star_rand"], shaders["VertexColor"], modelMatrix);
            }
        }

        // RENDER STELE HP

        // 8 stele initiale sub hp
        for (int i = 0; i < nr_stele; i++) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(700 + i * 50, 620);
            RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
        }

        // RENDER HP

        for (int i = 0; i < hp; i++) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(700 + i * 80, 635);
            std::string meshKey = "hp" + std::to_string(i + 1);
            RenderMesh2D(meshes[meshKey], shaders["VertexColor"], modelMatrix);
        }

        if (romb == "rombportocaliu") {
            if (patrat == "") {
                if (click) {
                    modelMatrix = glm::mat3(1);
                    modelMatrix *= transform2D::Translate(x, 720 - y);
                    RenderMesh2D(meshes["rombportocaliu"], shaders["VertexColor"], modelMatrix);
                }
            }
            else if (patrat == "square11" && nr_stele >= 1 && squares[1][1] == 0) {
                del[1][1] = 0;
                squares[1][1] = 1;
                nr_stele--;
                romburi[1][1].culoare = "portocaliu";
                romburi[1][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square12" && nr_stele >= 1 && squares[1][2] == 0) {
                del[1][2] = 0;
                squares[1][2] = 1;
                nr_stele--;
                romburi[1][2].culoare = "portocaliu";
                romburi[1][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square13" && nr_stele >= 1 && squares[1][3] == 0) {
                del[1][3] = 0;
                squares[1][3] = 1;
                nr_stele--;
                romburi[1][3].culoare = "portocaliu";
                romburi[1][3].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square21" && nr_stele >= 1 && squares[2][1] == 0) {
                del[2][1] = 0;
                squares[2][1] = 1;
                nr_stele--;
                romburi[2][1].culoare = "portocaliu";
                romburi[2][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square22" && nr_stele >= 1 && squares[2][2] == 0) {
                del[2][2] = 0;
                squares[2][2] = 1;
                nr_stele--;
                romburi[2][2].culoare = "portocaliu";
                romburi[2][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square23" && nr_stele >= 1 && squares[2][3] == 0) {
                del[2][3] = 0;
                squares[2][3] = 1;
                nr_stele--;
                romburi[2][3].culoare = "portocaliu";
                romburi[2][3].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square31" && nr_stele >= 1 && squares[3][1] == 0) {
                del[3][1] = 0;
                squares[3][1] = 1;
                nr_stele--;
                romburi[3][1].culoare = "portocaliu";
                romburi[3][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square32" && nr_stele >= 1 && squares[3][2] == 0) {
                del[3][2] = 0;
                squares[3][2] = 1;
                nr_stele--;
                romburi[3][2].culoare = "portocaliu";
                romburi[3][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square33" && nr_stele >= 1 && squares[3][3] == 0) {
                del[3][3] = 0;
                squares[3][3] = 1;
                nr_stele--;
                romburi[3][3].culoare = "portocaliu";
                romburi[3][3].nr_stele = 0;
                nr_romburi++;
            }
            patrat = "";
        }
        if (romb == "rombgalben") {
            if (patrat == "") {
                if (click) {
                    modelMatrix = glm::mat3(1);
                    modelMatrix *= transform2D::Translate(x, 720 - y);
                    RenderMesh2D(meshes["rombgalben"], shaders["VertexColor"], modelMatrix);
                }
            }
            else if (patrat == "square11" && nr_stele >= 2 && squares[1][1] == 0) {
                del[1][1] = 0;
                squares[1][1] = 2;
                nr_stele -= 2;
                romburi[1][1].culoare = "galben";
                romburi[1][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square12" && nr_stele >= 2 && squares[1][2] == 0) {
                del[1][2] = 0;
                squares[1][2] = 2;
                nr_stele -= 2;
                romburi[1][2].culoare = "galben";
                romburi[1][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square13" && nr_stele >= 2 && squares[1][3] == 0) {
                del[1][3] = 0;
                squares[1][3] = 2;
                nr_stele -= 2;
                romburi[1][3].culoare = "galben";
                romburi[1][3].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square21" && nr_stele >= 2 && squares[2][1] == 0) {
                del[2][1] = 0;
                squares[2][1] = 2;
                nr_stele -= 2;
                romburi[2][1].culoare = "galben";
                romburi[2][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square22" && nr_stele >= 2 && squares[2][2] == 0) {
                del[2][2] = 0;
                squares[2][2] = 2;
                nr_stele -= 2;
                romburi[2][2].culoare = "galben";
                romburi[2][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square23" && nr_stele >= 2 && squares[2][3] == 0) {
                del[2][3] = 0;
                squares[2][3] = 2;
                nr_stele -= 2;
                romburi[2][3].culoare = "galben";
                romburi[2][3].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square31" && nr_stele >= 2 && squares[3][1] == 0) {
                del[3][1] = 0;
                squares[3][1] = 2;
                nr_stele -= 2;
                romburi[3][1].culoare = "galben";
                romburi[3][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square32" && nr_stele >= 2 && squares[3][2] == 0) {
                del[3][2] = 0;
                squares[3][2] = 2;
                nr_stele -= 2;
                romburi[3][2].culoare = "galben";
                romburi[3][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square33" && nr_stele >= 2 && squares[3][3] == 0) {
                del[3][3] = 0;
                squares[3][3] = 2;
                nr_stele -= 2;
                romburi[3][3].culoare = "galben";
                romburi[3][3].nr_stele = 0;
                nr_romburi++;
            }
            patrat = "";
        }
        if (romb == "rombmov") {
            if (patrat == "") {
                if (click) {
                    modelMatrix = glm::mat3(1);
                    modelMatrix *= transform2D::Translate(x, 720 - y);
                    RenderMesh2D(meshes["rombmov"], shaders["VertexColor"], modelMatrix);
                }
            }
            else if (patrat == "square11" && nr_stele >= 2 && squares[1][1] == 0) {
                del[1][1] = 0;
                squares[1][1] = 3;
                nr_stele -= 2;
                romburi[1][1].culoare = "mov";
                romburi[1][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square12" && nr_stele >= 2 && squares[1][2] == 0) {
                del[1][2] = 0;
                squares[1][2] = 3;
                nr_stele -= 2;
                romburi[1][2].culoare = "mov";
                romburi[1][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square13" && nr_stele >= 2 && squares[1][3] == 0) {
                del[1][3] = 0;
                squares[1][3] = 3;
                nr_stele -= 2;
                romburi[1][3].culoare = "mov";
                romburi[1][3].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square21" && nr_stele >= 2 && squares[2][1] == 0) {
                del[2][1] = 0;
                squares[2][1] = 3;
                nr_stele -= 2;
                romburi[2][1].culoare = "mov";
                romburi[2][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square22" && nr_stele >= 2 && squares[2][2] == 0) {
                del[2][2] = 0;
                squares[2][2] = 3;
                nr_stele -= 2;
                romburi[2][2].culoare = "mov";
                romburi[2][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square23" && nr_stele >= 2 && squares[2][3] == 0) {
                del[2][3] = 0;
                squares[2][3] = 3;
                nr_stele -= 2;
                romburi[2][3].culoare = "mov";
                romburi[2][3].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square31" && nr_stele >= 2 && squares[3][1] == 0) {
                del[3][1] = 0;
                squares[3][1] = 3;
                nr_stele -= 2;
                romburi[3][1].culoare = "mov";
                romburi[3][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square32" && nr_stele >= 2 && squares[3][2] == 0) {
                del[3][2] = 0;
                squares[3][2] = 3;
                nr_stele -= 2;
                romburi[3][2].culoare = "mov";
                romburi[3][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square33" && nr_stele >= 2 && squares[3][3] == 0) {
                del[3][3] = 0;
                squares[3][3] = 3;
                nr_stele -= 2;
                romburi[3][3].culoare = "mov";
                romburi[3][3].nr_stele = 0;
                nr_romburi++;
            }
            patrat = "";
        }
        if (romb == "rombalbastru") {
            if (patrat == "") {
                if (click) {
                    modelMatrix = glm::mat3(1);
                    modelMatrix *= transform2D::Translate(x, 720 - y);
                    RenderMesh2D(meshes["rombalbastru"], shaders["VertexColor"], modelMatrix);
                }
            }
            else if (patrat == "square11" && nr_stele >= 3 && squares[1][1] == 0) {
                del[1][1] = 0;
                squares[1][1] = 4;
                nr_stele -= 3;
                romburi[1][1].culoare = "albastru";
                romburi[1][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square12" && nr_stele >= 3 && squares[1][2] == 0) {
                del[1][2] = 0;
                squares[1][2] = 4;
                nr_stele -= 3;
                romburi[1][2].culoare = "albastru";
                romburi[1][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square13" && nr_stele >= 3 && squares[1][3] == 0) {
                del[1][3] = 0;
                squares[1][3] = 4;
                nr_stele -= 3;
                romburi[1][3].culoare = "albastru";
                romburi[1][3].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square21" && nr_stele >= 3 && squares[2][1] == 0) {
                del[2][1] = 0;
                squares[2][1] = 4;
                nr_stele -= 3;
                romburi[2][1].culoare = "albastru";
                romburi[2][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square22" && nr_stele >= 3 && squares[2][2] == 0) {
                del[2][2] = 0;
                squares[2][2] = 4;
                nr_stele -= 3;
                romburi[2][2].culoare = "albastru";
                romburi[2][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square23" && nr_stele >= 3 && squares[2][3] == 0) {
                del[2][3] = 0;
                squares[2][3] = 4;
                nr_stele -= 3;
                romburi[2][3].culoare = "albastru";
                romburi[2][3].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square31" && nr_stele >= 3 && squares[3][1] == 0) {
                del[3][1] = 0;
                squares[3][1] = 4;
                nr_stele -= 3;
                romburi[3][1].culoare = "albastru";
                romburi[3][1].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square32" && nr_stele >= 3 && squares[3][2] == 0) {
                del[3][2] = 0;
                squares[3][2] = 4;
                nr_stele -= 3;
                romburi[3][2].culoare = "albastru";
                romburi[3][2].nr_stele = 0;
                nr_romburi++;
            }
            else if (patrat == "square33" && nr_stele >= 3 && squares[3][3] == 0) {
                del[3][3] = 0;
                squares[3][3] = 4;
                nr_stele -= 3;
                romburi[3][3].culoare = "albastru";
                romburi[3][3].nr_stele = 0;
                nr_romburi++;
            }
            patrat = "";
        }

        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                if (squares[i][j] == 1) {
                    if (click) {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(x, 720 - y);
                        RenderMesh2D(meshes["rombportocaliu"], shaders["VertexColor"], modelMatrix);
                    }
                    if (del[i][j]) {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(130.5f + (j - 1) * 150, 397.5f - (i - 1) * 150);
                        modelMatrix *= transform2D::Scale(del[i][j], del[i][j]);
                        RenderMesh2D(meshes["rombportocaliu"], shaders["VertexColor"], modelMatrix);
                        del[i][j] -= deltaTimeSeconds;
                        if (del[i][j] <= 0) {
                            squares[i][j] = 0;
                            romburi[i][j].culoare = "";
                            romburi[i][j].nr_stele = 0;
                            romburi[i][j].trage = 0;
                            romburi[i][j].nr_stele_moarte = 0;
                            for (int k = 0; k < 100; k++) {
                                romburi[i][j].stele[k].dead = 0;
                            }
                        }
                    }
                    else {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(130.5f + (j - 1) * 150, 397.5f - (i - 1) * 150);
                        RenderMesh2D(meshes["rombportocaliu"], shaders["VertexColor"], modelMatrix); 
                    }
                }
                else if (squares[i][j] == 2) {
                    if (click) {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(x, 720 - y);
                        RenderMesh2D(meshes["rombgalben"], shaders["VertexColor"], modelMatrix);
                    }
                    if (del[i][j]) {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(130.5f + (j - 1) * 150, 397.5f - (i - 1) * 150);
                        modelMatrix *= transform2D::Scale(del[i][j], del[i][j]);
                        RenderMesh2D(meshes["rombgalben"], shaders["VertexColor"], modelMatrix);
                        del[i][j] -= deltaTimeSeconds;
                        if (del[i][j] <= 0) {
                            squares[i][j] = 0;
                            romburi[i][j].culoare = "";
                            romburi[i][j].nr_stele = 0;
                            romburi[i][j].trage = 0;
                            romburi[i][j].nr_stele_moarte = 0;
                            for (int k = 0; k < 100; k++) {
                                romburi[i][j].stele[k].dead = 0;
                            }
                        }
                    }
                    else {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(130.5f + (j - 1) * 150, 397.5f - (i - 1) * 150);
                        RenderMesh2D(meshes["rombgalben"], shaders["VertexColor"], modelMatrix);
                    }
                }
                else if (squares[i][j] == 3) {
                    if (click) {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(x, 720 - y);
                        RenderMesh2D(meshes["rombmov"], shaders["VertexColor"], modelMatrix);
                    }
                    if (del[i][j]) {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(130.5f + (j - 1) * 150, 397.5f - (i - 1) * 150);
                        modelMatrix *= transform2D::Scale(del[i][j], del[i][j]);
                        RenderMesh2D(meshes["rombmov"], shaders["VertexColor"], modelMatrix);
                        del[i][j] -= deltaTimeSeconds;
                        if (del[i][j] <= 0) {
                            squares[i][j] = 0;
                            romburi[i][j].culoare = "";
                            romburi[i][j].nr_stele = 0;
                            romburi[i][j].trage = 0;
                            romburi[i][j].nr_stele_moarte = 0;
                            for (int k = 0; k < 100; k++) {
                                romburi[i][j].stele[k].dead = 0;
                            }
                        }
                    }
                    else {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(130.5f + (j - 1) * 150, 397.5f - (i - 1) * 150);
                        RenderMesh2D(meshes["rombmov"], shaders["VertexColor"], modelMatrix);
                    }
                }
                else if (squares[i][j] == 4) {
                    if (click) {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(x, 720 - y);
                        RenderMesh2D(meshes["rombalbastru"], shaders["VertexColor"], modelMatrix);
                    }
                    if (del[i][j]) {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(130.5f + (j - 1) * 150, 397.5f - (i - 1) * 150);
                        modelMatrix *= transform2D::Scale(del[i][j], del[i][j]);
                        RenderMesh2D(meshes["rombalbastru"], shaders["VertexColor"], modelMatrix);
                        del[i][j] -= deltaTimeSeconds;
                        if (del[i][j] <= 0) {
                            squares[i][j] = 0;
                            romburi[i][j].culoare = "";
                            romburi[i][j].nr_stele = 0;
                            romburi[i][j].trage = 0;
                            romburi[i][j].nr_stele_moarte = 0;
                            for (int k = 0; k < 100; k++) {
                                romburi[i][j].stele[k].dead = 0;
                            }
                        }
                    }
                    else {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(130.5f + (j - 1) * 150, 397.5f - (i - 1) * 150);
                        RenderMesh2D(meshes["rombalbastru"], shaders["VertexColor"], modelMatrix);
                    }
                }
            }
        }
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 0; k < nr; k++) {  
                    if (i == hexx[k].linie && romburi[i][j].culoare == hexx[k].color) {
                        romburi[i][j].trage = 1;
                        if (romburi[i][j].trage == 1) {
                            // generare stele
                            spawn += deltaTimeSeconds;
                            if (spawn >= 1) {
                                romburi[i][j].stele[romburi[i][j].nr_stele].x = 180.5f + (j - 1) * 150;
                                romburi[i][j].stele[romburi[i][j].nr_stele].y = 397.5f - (i - 1) * 150;
                                romburi[i][j].stele[romburi[i][j].nr_stele].culoare = romburi[i][j].culoare;
                                romburi[i][j].nr_stele++;
                                spawn = 0;
                            }
                            // translatie stele
                            for (int t = romburi[i][j].nr_stele_moarte; t < romburi[i][j].nr_stele; t++) {
                                cout << t << " " << romburi[i][j].stele[t].dead << endl;
                                modelMatrix = glm::mat3(1);
                                modelMatrix *= transform2D::Translate(romburi[i][j].stele[t].x, romburi[i][j].stele[t].y);
                                modelMatrix *= transform2D::Rotate(angularStep);
                                if (romburi[i][j].culoare == "portocaliu") {
                                    RenderMesh2D(meshes["steaportocalie"], shaders["VertexColor"], modelMatrix);
                                }
                                else if (romburi[i][j].culoare == "galben") {
                                    RenderMesh2D(meshes["steagalbena"], shaders["VertexColor"], modelMatrix);
                                }
                                else if (romburi[i][j].culoare == "mov") {
                                    RenderMesh2D(meshes["steamov"], shaders["VertexColor"], modelMatrix);
                                }
                                else if (romburi[i][j].culoare == "albastru") {
                                    RenderMesh2D(meshes["steaalbastra"], shaders["VertexColor"], modelMatrix);
                                }
                                romburi[i][j].stele[t].x++;

                                if (romburi[i][j].stele[t].x >= hexx[k].x - dim_stea && romburi[i][j].stele[t].dead == 0) {
                                    romburi[i][j].stele[t].dead = 1;
                                    romburi[i][j].nr_stele_moarte++;
                                    hexx[k].hp--;
                                }
                            }
                            cout << endl;
                        } 
                    }
                    else if (hexx[k].hp <= 0) {
                        for (int t = romburi[i][j].nr_stele_moarte; t < romburi[i][j].nr_stele; t++) {
                            cout << t << " " << romburi[i][j].stele[t].dead << endl;
                            modelMatrix = glm::mat3(1);
                            modelMatrix *= transform2D::Translate(romburi[i][j].stele[t].x, romburi[i][j].stele[t].y);
                            modelMatrix *= transform2D::Rotate(angularStep);
                            
                            if (romburi[i][j].culoare == "portocaliu") {
                                RenderMesh2D(meshes["steaportocalie"], shaders["VertexColor"], modelMatrix);
                            }
                            else if (romburi[i][j].culoare == "galben") {
                                RenderMesh2D(meshes["steagalbena"], shaders["VertexColor"], modelMatrix);
                            }
                            else if (romburi[i][j].culoare == "mov") {
                                RenderMesh2D(meshes["steamov"], shaders["VertexColor"], modelMatrix);
                            }
                            else if (romburi[i][j].culoare == "albastru") {
                                RenderMesh2D(meshes["steaalbastra"], shaders["VertexColor"], modelMatrix);
                            }
                            romburi[i][j].stele[t].x++;
                            if (romburi[i][j].stele[t].x >= 1280 && romburi[i][j].stele[t].dead == 0) {
                                romburi[i][j].stele[t].dead = 1;
                                romburi[i][j].nr_stele_moarte++;
                            }
                        }
                    }
                }
            }
        }
        if (ok == 1) {
            angularStep = 0;
        }
        else {
            angularStep += deltaTimeSeconds;
        }
    }
}

void PvZ::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    x = mouseX;
    y = mouseY;
}


void PvZ::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    if (button == 1) {
        if (mouseX >= 42.5f && mouseX <= 137.5f && mouseY >= 22.5f && mouseY <= 117.5f) {
            romb = "rombportocaliu";
            click = 1;
        }
        else if (mouseX >= 192.5f && mouseX <= 287.5f && mouseY >= 22.5f && mouseY <= 117.5f) {
            romb = "rombgalben";
            click = 1;
        }
        else if (mouseX >= 342.5f && mouseX <= 437.5f && mouseY >= 22.5f && mouseY <= 117.5f) {
            romb = "rombmov";
            click = 1;
        }
        else if (mouseX >= 492.5f && mouseX <= 587.5f && mouseY >= 22.5f && mouseY <= 117.5f) {
            romb = "rombalbastru";
            click = 1;
        }
        else {
            romb = "";
            click = 0;
        }
        for (int i = 0; i < stele_generate; i++) {
            if (mouseX >= stele[i].x - dim_stea && mouseX <= stele[i].x + dim_stea && mouseY >= 720 - stele[i].y - dim_stea && mouseY <= 720 - stele[i].y + dim_stea && stele[i].collected == 0) {
                stele[i].collected = 1;
                nr_stele++;
            }
        }
    }
    else {
        if (mouseX >= 90 && mouseX <= 185 && mouseY >= 575 && mouseY <= 670) {
            // sterge tun 11
            del[3][1] = 1;
        }
        if (mouseX >= 240 && mouseX <= 335 && mouseY >= 575 && mouseY <= 670) {
            // sterge tun 12
            del[3][2] = 1;
        }
        if (mouseX >= 390 && mouseX <= 485 && mouseY >= 575 && mouseY <= 670) {
            // sterge tun 13
            del[3][3] = 1;
        }
        if (mouseX >= 90 && mouseX <= 185 && mouseY >= 425 && mouseY <= 520) {
            // sterge tun 21
            del[2][1] = 1;
        }
        if (mouseX >= 240 && mouseX <= 335 && mouseY >= 425 && mouseY <= 520) {
            // sterge tun 22
            del[2][2] = 1;
        }
        if (mouseX >= 390 && mouseX <= 485 && mouseY >= 425 && mouseY <= 520) {
            // sterge tun 23
            del[2][3] = 1;
        }
        if (mouseX >= 90 && mouseX <= 185 && mouseY >= 275 && mouseY <= 370) {
            // sterge tun 31
            del[1][1] = 1;
        }
        if (mouseX >= 240 && mouseX <= 335 && mouseY >= 275 && mouseY <= 370) {
            // sterge tun 32
            del[1][2] = 1;
        }
        if (mouseX >= 390 && mouseX <= 485 && mouseY >= 275 && mouseY <= 370) {
            // sterge tun 33
            del[1][3] = 1;
        }
    }
}


void PvZ::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    if (click) {
        if (mouseX >= 90 && mouseX <= 185 && mouseY >= 575 && mouseY <= 670) {
            patrat = "square31";
        }
        if (mouseX >= 240 && mouseX <= 335 && mouseY >= 575 && mouseY <= 670) {
            patrat = "square32";
        }
        if (mouseX >= 390 && mouseX <= 485 && mouseY >= 575 && mouseY <= 670) {
            patrat = "square33";
        }
        if (mouseX >= 90 && mouseX <= 185 && mouseY >= 425 && mouseY <= 520) {
            patrat = "square21";
        }
        if (mouseX >= 240 && mouseX <= 335 && mouseY >= 425 && mouseY <= 520) {
            patrat = "square22";
        }
        if (mouseX >= 390 && mouseX <= 485 && mouseY >= 425 && mouseY <= 520) {
            patrat = "square23";
        }
        if (mouseX >= 90 && mouseX <= 185 && mouseY >= 275 && mouseY <= 370) {
            patrat = "square11";
        }
        if (mouseX >= 240 && mouseX <= 335 && mouseY >= 275 && mouseY <= 370) {
            patrat = "square12";
        }
        if (mouseX >= 390 && mouseX <= 485 && mouseY >= 275 && mouseY <= 370) {
            patrat = "square13";
        }
    }
    click = 0;
}
