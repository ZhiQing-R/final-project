#pragma once
#include <vulkan/vulkan.h>
#include <glm/glm.hpp>
#include <array>
#include "Model.h"

constexpr static unsigned int NUM_BLADES = 1 << 8;
constexpr static float MIN_HEIGHT = 6.3f;
constexpr static float MAX_HEIGHT = 8.5f;
constexpr static float MIN_WIDTH = 0.28f;
constexpr static float MAX_WIDTH = 0.32f;
constexpr static float MIN_BEND = 1.5f;
constexpr static float MAX_BEND = 2.5f;

constexpr static float ClumpGridSize = 10.0f;


struct Blade {
    // Position and direction
    glm::vec4 v0;
    // Bezier point and height
    glm::vec4 v1;
    // Physical model guide and width
    glm::vec4 v2;
    // Up vector and stiffness coefficient
    glm::vec4 up;

    static VkVertexInputBindingDescription getBindingDescription() {
        VkVertexInputBindingDescription bindingDescription = {};
        bindingDescription.binding = 0;
        bindingDescription.stride = sizeof(Blade);
        bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        return bindingDescription;
    }

    static std::array<VkVertexInputAttributeDescription, 4> getAttributeDescriptions() {
        std::array<VkVertexInputAttributeDescription, 4> attributeDescriptions = {};

        // v0
        attributeDescriptions[0].binding = 0;
        attributeDescriptions[0].location = 0;
        attributeDescriptions[0].format = VK_FORMAT_R32G32B32A32_SFLOAT;
        attributeDescriptions[0].offset = offsetof(Blade, v0);

        // v1
        attributeDescriptions[1].binding = 0;
        attributeDescriptions[1].location = 1;
        attributeDescriptions[1].format = VK_FORMAT_R32G32B32A32_SFLOAT;
        attributeDescriptions[1].offset = offsetof(Blade, v1);

        // v2
        attributeDescriptions[2].binding = 0;
        attributeDescriptions[2].location = 2;
        attributeDescriptions[2].format = VK_FORMAT_R32G32B32A32_SFLOAT;
        attributeDescriptions[2].offset = offsetof(Blade, v2);

        // up
        attributeDescriptions[3].binding = 0;
        attributeDescriptions[3].location = 3;
        attributeDescriptions[3].format = VK_FORMAT_R32G32B32A32_SFLOAT;
        attributeDescriptions[3].offset = offsetof(Blade, up);

        return attributeDescriptions;
    }

    static VkBuffer bladeVertexBuffer;
    static VkBuffer bladeIndexBuffer;

    static VkDeviceMemory bladeVertexBufferMemory;
    static VkDeviceMemory bladeIndexBufferMemory;

    static void CreateBladeVertexIndexBuffer(Device* device, VkCommandPool commandPool);
	static void DestroyBladeVertexIndexBuffer(Device* device);
	static VkBuffer GetBladeVertexBuffer() { return bladeVertexBuffer; }
	static VkBuffer GetBladeIndexBuffer() { return bladeIndexBuffer; }
};

//struct BladeDrawIndirect {
//    uint32_t vertexCount;
//    uint32_t instanceCount;
//    uint32_t firstVertex;
//    uint32_t firstInstance;
//};

struct BladeDrawIndirect {
    uint32_t    indexCount;
    uint32_t    instanceCount;
    uint32_t    firstIndex;
    int32_t     vertexOffset;
    uint32_t    firstInstance;
};

class Blades : public Model {
private:
    VkBuffer bladesBuffer;
    VkBuffer culledBladesBuffer;
    VkBuffer numBladesBuffer;

    VkDeviceMemory bladesBufferMemory;
    VkDeviceMemory culledBladesBufferMemory;
    VkDeviceMemory numBladesBufferMemory;

public:
    Blades(Device* device, VkCommandPool commandPool, float planeDim, glm::vec3 offset = glm::vec3(0));
    VkBuffer GetBladesBuffer() const;
    VkBuffer GetCulledBladesBuffer() const;
    VkBuffer GetNumBladesBuffer() const;
    ~Blades();
};