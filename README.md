# CPP-ECS
A simple Entity Component System (ECS) written in C++.

## Preface

This is a collection of libs implementing an Entity Component System (ECS) in C++. The goal is to create a simple, and easy to use ECS for development.

The file structure is as follows:

```mermaid
graph LR;
    PureOrWorld("Pure/World") --> GroupSubModules("Group Sub-Modules");
    GroupSubModules --> IncludeOrSrc("Include/Src");
    IncludeOrSrc --> Chunks("Chunks");
    IncludeOrSrc --> Components("Components");
    IncludeOrSrc --> Entities("Entities");
    IncludeOrSrc --> Systems("Systems");
```

The "pure" ecs is more or less built as follows:

```mermaid
classDiagram
direction LR
    class Chunk {
        -values: list
    }
    class ChunkPool {
        -chunks: list~Chunk~
    }
    class ComponentPool {
        -chunkPoolX: ChunkPool
    }
    class EntityPool {
        -componentPools: list~ComponentPool~
    }
    
    Chunk -->  ChunkPool : contains
    ChunkPool --> ComponentPool : contains
    ComponentPool --> EntityPool : contains
```

- **Chunks**: A chunk is a collection of components of the same type. It is a contiguous block of memory that stores the components.
- **ChunkPool**: A chunk pool is a collection of chunks. This is the pure form of a memory pool.
- **ComponentPool**: A component pool is a collection of chunk pools. It is usually an abstraction of something, like a position, that wil contain 2 chunk pools, in a 2d context.
- **EntityPool**: An entity pool is a collection of component pools. It is the highest level of abstraction and is used to group components together.
- **Entity**: An entity is a collection of references to components. Direct manipulation of entities is discouraged, as it is better to use the component pools.
- **System**: A system is a function executed on entityPools, allowing for changes in entities' components.

Here is how the entity manager handles the pools and their entities:

```mermaid
classDiagram
direction TD
    namespace ECS Pure {
        class AnyPool
        class EntityPtrPool
    }
    AnyPool <|--|> EntityPtrPool : ref to self
```

And here is how the world manager handles the pools and their entities:
_Note that the WorldChunkPool not being a subclass of AnyLocalizedPool, it uses the above reference system._

```mermaid
classDiagram
direction TD
    namespace ECS Pure {
        class EntityPtrPool
    }
    namespace ECS World {
        class AnyLocalizedPool
        class WorldChunkPool
        class EntityLocPool
    }
    AnyLocalizedPool <|--|> EntityPtrPool : ref to self
    EntityPtrPool <|-- EntityLocPool : ref to self
    EntityLocPool <|-- AnyLocalizedPool : ref to self
    EntityLocPool <|.. WorldChunkPool : ref to list head
    WorldChunkPool <|.. EntityLocPool : ref to chunk
```
