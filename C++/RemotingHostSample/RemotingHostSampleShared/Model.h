#pragma once

#include <pch.h>

namespace Library
{
	class Game;
	class Mesh;
	class ModelMaterial;

	class Model
	{
	public:
		Model(Game& game, const std::string& filename, bool flipUVs = false);

		~Model();

		Game& GetGame();
		bool HasMeshes() const;
		bool HasMaterials() const;

		const std::vector<Mesh*>& Meshes() const;
		const std::vector<ModelMaterial*>& Materials() const;

	private:
		Model(const Model& rhs);
		Model& operator=(const Model& rhs);

		Game& mGame;
		std::vector<Mesh*> mMeshes;
		std::vector<ModelMaterial*> mMaterials;
	};

}