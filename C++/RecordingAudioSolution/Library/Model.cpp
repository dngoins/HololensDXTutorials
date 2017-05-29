#include "Model.h"
#include "Game.h"
#include "GameException.h"
#include "Mesh.h"
#include "ModelMaterial.h"
#include "MatrixHelper.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace MatMeshModLibrary
{
    Model::Model( const std::string& filename, bool flipUVs)
		: mMeshes(), mMaterials()
    {
        Assimp::Importer importer;

		UINT flags = aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType | aiProcess_FlipWindingOrder;
        if (flipUVs)
        {
            flags |= aiProcess_FlipUVs;
        }

        const aiScene* scene = importer.ReadFile(filename, flags);
        if (scene == nullptr)
        {
            throw GameException(importer.GetErrorString());
        }

        if (scene->HasMaterials())
        {
            for (UINT i = 0; i < scene->mNumMaterials; i++)
            {
                mMaterials.push_back(new ModelMaterial(*this, scene->mMaterials[i]));
            }
        }

        if (scene->HasMeshes())
        {
            for (UINT i = 0; i < scene->mNumMeshes; i++)
            {	
				Mesh* mesh = new Mesh(*this, *(scene->mMeshes[i]));
                mMeshes.push_back(mesh);
            }
        }
    }
	
	Model::Model(const void* pBuffer, size_t pLength, bool flipUVs)
		: mMeshes(), mMaterials()
	{
		Assimp::Importer importer;

		UINT flags = aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType | aiProcess_FlipWindingOrder;
		if (flipUVs)
		{
			flags |= aiProcess_FlipUVs;
		}

		const aiScene* scene = importer.ReadFileFromMemory(pBuffer, pLength, 0);

		if (scene == nullptr)
		{
			throw GameException(importer.GetErrorString());
		}

		if (scene->HasMaterials())
		{
			for (UINT i = 0; i < scene->mNumMaterials; i++)
			{
				mMaterials.push_back(new ModelMaterial(*this, scene->mMaterials[i]));
			}
		}

		if (scene->HasMeshes())
		{
			for (UINT i = 0; i < scene->mNumMeshes; i++)
			{
				Mesh* mesh = new Mesh(*this, *(scene->mMeshes[i]));
				mMeshes.push_back(mesh);
			}
		}
	}

    Model::~Model()
    {
        for (Mesh* mesh : mMeshes)
        {
            delete mesh;
        }

        for (ModelMaterial* material : mMaterials)
        {
            delete material;
        }
    }

   

    bool Model::HasMeshes() const
    {
        return (mMeshes.size() > 0);
    }

    bool Model::HasMaterials() const
    {
        return (mMaterials.size() > 0);
    }

    const std::vector<Mesh*>& Model::Meshes() const
    {
        return mMeshes;
    }

    const std::vector<ModelMaterial*>& Model::Materials() const
    {
        return mMaterials;
    }
}
