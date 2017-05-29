#pragma once

#include "Common.h"

struct aiNode;

namespace MatMeshModLibrary
{
  
    class Mesh;
    class ModelMaterial;

    class Model
    {
		friend class Mesh;

    public:
        Model( const std::string& filename, bool flipUVs = false);
		Model(const void* pBuffer, size_t pLength, bool flipUVs );

        ~Model();

     
        bool HasMeshes() const;
        bool HasMaterials() const;

        const std::vector<Mesh*>& Meshes() const;
        const std::vector<ModelMaterial*>& Materials() const;

    private:
        Model(const Model& rhs);
        Model& operator=(const Model& rhs);

      
        std::vector<Mesh*> mMeshes;
        std::vector<ModelMaterial*> mMaterials;
    };
}
