#include "create.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float width,
    float height,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(width, 0, 0), color),
        VertexFormat(corner + glm::vec3(width, height, 0), color),
        VertexFormat(corner + glm::vec3(0, height, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* object2D::CreateRomb(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float width,                // latime dreptunghi
    float height,               // inaltime dreptunghi
    float length,               // latura romb
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = glm::vec3(0, 0, 1);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0, 0) * length, color),  // fiecare triunghi pleaca din corner
        VertexFormat(corner + glm::vec3(0, 3, 0) * length, color),  // top
        VertexFormat(corner + glm::vec3(-2, 0, 0) * length, color), // left
        VertexFormat(corner + glm::vec3(0, -3, 0) * length, color), // bottom
        VertexFormat(corner + glm::vec3(2, 0, 0) * length, color),  // right

        VertexFormat(corner + glm::vec3(0, -1, 0) * width, color),  // bottom left
        VertexFormat(corner + glm::vec3(4, -1, 0) * width, color),  // bottom right
        VertexFormat(corner + glm::vec3(4, 1, 0) * width, color),  // top right
        VertexFormat(corner + glm::vec3(0, 1, 0) * width, color)   // top left
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 1, 4, // triunghiuri romb

        4, 5, 6,
        4, 6, 7,
        4, 7, 8,
        4, 8, 5 // triunghiuri dreptunghi
    };

    Mesh* romb = new Mesh(name);

    romb->InitFromData(vertices, indices);
    return romb;
}

Mesh* object2D::CreateHexagon(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float big,
    float small,
    glm::vec3 color_big,
    glm::vec3 color_small,
    bool fill)
{
    glm::vec3 corner = glm::vec3(0, 0, 1);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0, 0) * big, color_small),  // fiecare triunghi pleaca din corner

        VertexFormat(corner + glm::vec3(-0.6f, 1, 0) * small, color_small),
        VertexFormat(corner + glm::vec3(-1, 0, 0) * small, color_small),
        VertexFormat(corner + glm::vec3(-0.6f, -1, 0) * small, color_small),
        VertexFormat(corner + glm::vec3(0.6f, -1, 0) * small, color_small),
        VertexFormat(corner + glm::vec3(1, 0, 0) * small, color_small),
        VertexFormat(corner + glm::vec3(0.6f, 1, 0) * small, color_small),

        VertexFormat(corner + glm::vec3(-0.6f, 1, 0) * big, color_big),
        VertexFormat(corner + glm::vec3(-1, 0, 0) * big, color_big),
        VertexFormat(corner + glm::vec3(-0.6f, -1, 0) * big, color_big),
        VertexFormat(corner + glm::vec3(0.6f, -1, 0) * big, color_big),
        VertexFormat(corner + glm::vec3(1, 0, 0) * big, color_big),
        VertexFormat(corner + glm::vec3(0.6f, 1, 0) * big, color_big)
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 6,
        0, 6, 1,// triunghiuri hexagon mic

        0, 7, 8,
        0, 8, 9,
        0, 9, 10,
        0, 10, 11,
        0, 11, 12,
        0, 12, 7// triunghiuri hexagon mare
    };

    Mesh* hexagon = new Mesh(name);

    hexagon->InitFromData(vertices, indices);
    return hexagon;
}

Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float dim,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = glm::vec3(0, 0, 0);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 1, 0) * dim, color),             //A
        VertexFormat(corner + glm::vec3(0, -1.2f, 0) * dim, color),         //F
        VertexFormat(corner + glm::vec3(-1.2f, -2, 0) * dim, color),        //B
        VertexFormat(corner + glm::vec3(1.2f, -2, 0) * dim, color),         //E
        VertexFormat(corner + glm::vec3(1.8f, 0, 0) * dim, color),          //C
        VertexFormat(corner + glm::vec3(-1.8f, 0, 0) * dim, color)          //D
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        0, 1, 3,
        1, 4, 5
    };

    Mesh* star = new Mesh(name);

    star->InitFromData(vertices, indices);
    return star;
}

Mesh* object2D::CreateStarRand(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float dim,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = glm::vec3(0, 0, 1);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 1, 0) * dim, color),             //A
        VertexFormat(corner + glm::vec3(0, -1.2f, 0) * dim, color),         //F
        VertexFormat(corner + glm::vec3(-1.2f, -2, 0) * dim, color),        //B
        VertexFormat(corner + glm::vec3(1.2f, -2, 0) * dim, color),         //E
        VertexFormat(corner + glm::vec3(1.8f, 0, 0) * dim, color),          //C
        VertexFormat(corner + glm::vec3(-1.8f, 0, 0) * dim, color)          //D
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        0, 1, 3,
        1, 4, 5
    };

    Mesh* star = new Mesh(name);

    star->InitFromData(vertices, indices);
    return star;
}