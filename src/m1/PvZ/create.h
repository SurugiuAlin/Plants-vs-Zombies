#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);

    // Create rectangle with given bottom left corner, width, height and color
    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, bool fill = false);

    // Create romb + dreptunghi with given bottom left corner, width, height, length and color
    Mesh* CreateRomb(const std::string& name, glm::vec3 leftBottomCorner, float width, float height, float length, glm::vec3 color, bool fill = false);

    // Create hexagon mare + mic with given bottom left corner, big, small and color
    Mesh* CreateHexagon(const std::string& name, glm::vec3 leftBottomCorner, float big, float small, glm::vec3 color_big, glm::vec3 color_small, bool fill = false);

    // Create stea with given bottom left corner, dim and color
    Mesh* CreateStar(const std::string& name, glm::vec3 leftBottomCorner, float dim, glm::vec3 color, bool fill = false);

    // Create stea with given bottom left corner, dim and color
    Mesh* CreateStarRand(const std::string& name, glm::vec3 leftBottomCorner, float dim, glm::vec3 color, bool fill = false);
}
