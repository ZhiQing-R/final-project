# Design Doc

## Vulkan Procedural Grass

### Introduction

Grass system is a important part in many games. Lush, realistic grass helps bring the environment to life. When the grass moves in response to weather or characters, it can draw players further into the world.

The open-world action game **Ghost of Tsushima** has an amazing grass and foliage system. Combined with its weather system, waving grass really builds up the solace atmosphere.

In this project, I plan to reimplement the procedural grass system in **Ghost of Tsushima** using a Vulkan grass template.

### Reference

![ref](./img/ref.jpg)
![ref](./img/ref2.jpg)

[Reference Video](https://www.youtube.com/watch?v=Ibe1JBF5i5Y)

### Goals and Features

The general goal is to recreate the grass system as much as possible. My project expects to have the following features:

- Procedural wind field
- Bezier curve based grass
- Procedural grass normal and glossiness
- Procedural grass clump
- Procedural environment lighting and sky
- Waving reed
- Procedural Terrain

(Optional, depending on time)

- Screen space shadow
- Grass LOD
- Add custom objects to the scene

### Techniques

I plan to use Vulkan as the graphics API and use compute shader to do culling and wind interaction.

Using compute shader and indirect instanced draw for better performance. 

The grass physics is basically from the paper [Responsive Real-Time Grass Rendering for General 3D Scenes](https://www.cg.tuwien.ac.at/research/publications/2017/JAHRMANN-2017-RRTG/JAHRMANN-2017-RRTG-draft.pdf)

### Timeline

| Milestones | Task |
| --- | --- |
| **Milestone 1 (Nov. 13)** | Procedural wind Bezier curve based grass, Procedural Terrain |
| **Milestone 2 (Nov. 25)** | Procedural grass normal and glossiness, Procedural grass clump, Procedural environment lighting and sky  |
| **Final Submission (Dec. 2)** | Waving reed and final tuning | 
